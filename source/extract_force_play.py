"""Recover the pitcher-to-second-to-first play with Ara running and Medica batting."""
from pathlib import Path
import struct
import sys
import zipfile

from extract_batted_flight import DEFENSE, FIGURE, PATTERNS, PLAY
from extract_fly_outs import ATT_ENTRY, RUNNERS, RUNNER_MGR, advance_batter_on_first, begin_play, minimap, seed_for
from extract_ground_outs import QUERY, observe_contacts

RECORD = struct.Struct('<8BI6BHI')


def force_play(archive, flights, outs, slot=0, previous=(4, 0), count=(0, 0), prior_call=0):
    group, order = previous
    arm, ball = begin_play(archive, group, order, 1, outs, seed_for(flights, group, order), slot, (0, 0))
    for _ in range(200):
        if arm.call(0xad5b4, DEFENSE):
            break
    else:
        raise ValueError('First plate appearance did not end')
    lead, batting_slot = advance_batter_on_first(arm)
    assert arm.cpu.mem_read(ATT_ENTRY+0xe+batting_slot, 1)[0] == 0
    arm.cpu.mem_write(PLAY+4, bytes(count))
    arm.cpu.mem_write(PLAY+11, bytes([prior_call]))
    arm.call(0xd7f64, PLAY)  # ResetMotion resets the pitch session before the next delivery.
    arm.cpu.mem_write(PLAY+0x11, b'\1')
    # Use the group's first shuffled variant. Earlier singles use a different group.
    index = arm.call(0x95510, PATTERNS, 3)
    arm.call(0x163c0c, 3, index)
    arm.put(0x2fd35c, seed_for(flights, 3, 0))
    arm.call(0xad114, DEFENSE)
    assert arm.call(0xc8528, RUNNER_MGR, 1, 1) == lead
    frame = minimap(arm)
    attempts, contacts = observe_contacts(arm, ball, lambda: tick)
    holds, throws, judges, strides, states = [], [], [], {}, []
    maps = bytearray()

    def hold(cpu, pc, size, context):
        who = arm.word(cpu.reg_read(arm.regs[0])+0x14)
        holds.append((tick, who, contacts[tick, who]))

    def release(cpu, pc, size, context):
        if cpu.reg_read(arm.regs[0]) == ball:
            throws.append(tick)

    def judge(cpu, pc, size, context):
        ai, runner_ai = (cpu.reg_read(r) for r in arm.regs[:2])
        mover = arm.word(runner_ai+4)
        judges.append((tick, arm.word(ai+0x14), mover, arm.word(mover+0x7c)))

    def move(cpu, pc, size, context):
        mover = cpu.reg_read(arm.regs[0])
        if mover not in (arm.word(RUNNERS), arm.word(RUNNERS+4)):
            return
        setup = bytes(cpu.mem_read(mover+0x20, 24))
        speed = arm.word(mover+0x3c)
        flat = all(arm.word(mover+i) == 0 for i in (0x18, 0x24, 0x30, 0x40, 0x44))
        strides.setdefault(mover, []).append((tick, setup, speed, flat))

    for pc, hook in ((0xa5ab0, hold), (0xb9408, release), (0xae10c, judge), (0xcf264, move)):
        arm.hook(pc, hook)
    for tick in range(1, 201):
        ended = arm.call(0xad5b4, DEFENSE)
        score = tuple(arm.cpu.mem_read(PLAY+i, 1)[0] for i in (4, 5, 6, 11, 0x1e, 0x1f))
        first = arm.call(0xc8528, RUNNER_MGR, 1, 1)
        assert first in (0, lead)
        second = arm.call(0xc8528, RUNNER_MGR, 2, 1)
        assert second in (0, lead)
        states.append((score, bool(first), bool(second)))
        maps.extend(frame())
        if ended:
            break
    else:
        raise ValueError('Occupied-base defense did not end')
    relay = outs < 2
    assert [f for _, f, _ in holds] == ([0, 3, 2] if relay else [0, 2])
    assert len(throws) == len(judges) == 1+int(relay)
    pickup, batter_out = holds[0][0], holds[-1][0]
    lead_out = holds[1][0] if relay else 0
    if relay:
        assert judges[0] == (lead_out, 3, lead, 2)
        assert throws[0] < lead_out < throws[1]
    batter = judges[-1][2]
    assert batter != lead and judges[-1] == (batter_out, 2, batter, 1)
    assert pickup < throws[0] <= throws[-1] < batter_out <= tick
    total_outs = outs+len(judges)
    assert states[-1][0][:4] == (*count, total_outs, 13)
    assert arm.call(0xc8614, RUNNER_MGR) == int(not relay) and not states[-1][1]
    assert states[-1][2] == (not relay)
    assert arm.word(DEFENSE+0x18) == (25 if total_outs == 3 else 14)
    assert bytes(arm.cpu.mem_read(ATT_ENTRY+0x295, 3))[::2] == bytes((1, (batting_slot+1)%9))
    assert bytes(arm.cpu.mem_read(PLAY+0x142, 2)) == bytes(2)

    clear_first = next(i for i, (_, first, _) in enumerate(states, 1) if not first)
    runs, paths = bytearray(), []
    for runner, force_tick, point in ((lead, lead_out or clear_first+1, 11), (batter, batter_out, 10)):
        arm.call(0x95c7c, 0x5ee000, FIGURE, point)
        base = bytes(arm.cpu.mem_read(0x5ee000, 12))
        before = [s for s in strides[runner] if s[0] < force_tick]
        assert [s[0] for s in before] == list(range(1, force_tick))
        initial, speed = before[0][1:3]
        assert all(s[1][12:] == base and s[2] == speed and s[3] for s in before)
        runs.extend(initial + base + struct.pack('<i', speed))
        # MoveNext inputs at ticks 2 through the force frame are the positions
        # after ticks 1 through force_tick-1, before the defender's call.
        paths.append([s[1][:12] for s in strides[runner] if 2 <= s[0] <= force_tick])
        if runner == lead and not relay:
            # The terminal stride hits the bag. No further MoveNext call follows.
            assert states[clear_first-1][2] and len(paths[-1]) == clear_first-1
            paths[-1].append(base)
        assert len(paths[-1]) == force_tick-1
    queries = bytearray()
    for when, who, site, disabled, args in attempts:
        for stage, ((until, actor, catch_site), since) in enumerate(zip(holds, [0, *throws])):
            if since < when <= until and (who, site) == (actor, catch_site):
                queries.extend(QUERY.pack(when, stage, disabled, *args))
                break
    provisional = next(i for i, (score, _, _) in enumerate(states, 1) if score[3] == 6)
    fields = (3, 0, 0, outs, 0, pickup, batter_out, tick)
    timing = (throws[0], lead_out, throws[1] if relay else 0, clear_first, provisional, 1)
    return fields, timing, bytes(queries), bytes(runs), bytes(maps), states, paths


def extract(apk, flights, path):
    with zipfile.ZipFile(apk) as archive:
        plays = [force_play(archive, flights, outs) for outs in range(3)]
    payload = bytearray()
    table = bytearray()
    start = 8+len(plays)*RECORD.size
    for fields, timing, queries, runs, maps, _, _ in plays:
        offset = start+len(payload)
        payload.extend(queries+runs)
        table.extend(RECORD.pack(*fields, start+len(payload), *timing, len(queries)//QUERY.size, offset))
        payload.extend(maps)
    tmp = path.with_suffix('.tmp')
    tmp.write_bytes(struct.pack('<4sI', b'DPL1', len(plays))+table+payload)
    tmp.replace(path)
    print(f'{len(plays)} verified force-play branches with a runner on first.')


if __name__ == '__main__':
    extract(sys.argv[1], Path(sys.argv[2]).read_bytes(), Path(sys.argv[3]))
