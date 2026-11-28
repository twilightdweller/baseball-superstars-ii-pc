"""Extract empty-base ground plays that the original defense resolves at first."""
import struct
import sys
import zipfile
from pathlib import Path

from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_SP
from extract_batted_flight import FIGURE
from extract_fly_outs import (ATT_ENTRY, DEFENSE, ORDERS, PLAY, RUNNERS, RUNNER_MGR, begin_play,
                              minimap, seed_for)

# Common field record, map offset, provisional call, throw release, query count, query offset.
RECORD = struct.Struct('<8BIBBHI')
# Tick, pickup/reception, collision-disabled flag, then the CollisionDetect inputs.
QUERY = struct.Struct('<3Bx18i')


def observe_contacts(arm, ball, clock):
    attempts, contacts = [], {}
    actor = caller = 0

    def defender(cpu, pc, size, context):
        nonlocal actor, caller
        actor = arm.word(cpu.reg_read(arm.regs[0])+0x14)
        caller = cpu.reg_read(UC_ARM_REG_LR)

    def query(cpu, pc, size, context):
        obj, bounds, radius, steps = (cpu.reg_read(r) for r in arm.regs)
        assert obj == ball and steps == 5
        sp = cpu.reg_read(UC_ARM_REG_SP)
        cursor, length = arm.word(ball+0x9ac), arm.word(ball+0x750)
        assert 0 <= cursor < length <= 150
        indices = (max(0, cursor-1), cursor, min(length-1, cursor+1))
        samples = b''.join(arm.cpu.mem_read(ball+0x48+12*i, 12) for i in indices)
        coords = struct.unpack('<15i', samples + arm.cpu.mem_read(bounds, 24))
        disabled = arm.cpu.mem_read(ball+0x9cc, 1)[0]
        attempts.append((clock(), actor, caller, disabled, (*coords, radius, steps, arm.word(sp))))

    def collision_return(cpu, pc, size, context):
        if cpu.reg_read(arm.regs[0]) != 0xffffffff:
            contacts[(clock(), actor)] = caller

    for pc, hook in ((0xa1b38, defender), (0xb8024, query), (0xa1c1a, collision_return)):
        arm.hook(pc, hook)
    return attempts, contacts


def ground_play(archive, group, order, batter, outs, seed, slot=0, count=(0, 0), observe=None, after_defense=None):
    arm, ball = begin_play(archive, group, order, batter, outs, seed, slot, count)
    # IsArrive maps the batter-runner's target index 1 to stadium point 10.
    base_buffer = 0x5ee000
    arm.call(0x95c7c, base_buffer, FIGURE, 10)
    first_base = bytes(arm.cpu.mem_read(base_buffer, 12))
    runs = []
    positions = []
    occupants = []
    races = {}
    frame = minimap(arm)
    holds, releases, judgments, states = [], [], [], []
    maps = bytearray()
    attempts, contacts = observe_contacts(arm, ball, lambda: tick)

    def hold(cpu, pc, size, context):
        who = arm.word(cpu.reg_read(arm.regs[0])+0x14)
        holds.append((tick, who, contacts.get((tick, who))))
        if who == 2:
            runner = arm.word(RUNNERS)
            if arm.word(runner+0x7c) == 1:
                races[tick] = bytes(cpu.mem_read(runner+0x20, 24)) + first_base

    def move_runner(cpu, pc, size, context):
        runner = cpu.reg_read(arm.regs[0])
        if runner == arm.word(RUNNERS):
            setup = bytes(cpu.mem_read(runner+0x20, 24))
            speed = arm.word(runner+0x3c)
            # Level run to first. Vertical motion on other routes is outside this table.
            flat = all(arm.word(runner+i) == 0 for i in (0x18, 0x24, 0x30, 0x40, 0x44))
            runs.append((tick, setup, speed, flat))

    def release(cpu, pc, size, context):
        if cpu.reg_read(arm.regs[0]) == ball:
            releases.append(tick)

    def judge(cpu, pc, size, context):
        ai, runner, base = (cpu.reg_read(r) for r in arm.regs[:3])
        judgments.append((tick, arm.word(ai+0x14), arm.word(runner+4), base,
                          cpu.reg_read(UC_ARM_REG_LR)))

    for pc, hook in ((0xa5ab0, hold),
                     (0xb9408, release), (0xae10c, judge), (0xcf264, move_runner)):
        arm.hook(pc, hook)
    if observe:
        observe(arm, ball)
    for tick in range(1, 201):
        ended = arm.call(0xad5b4, DEFENSE)
        occupying_runner = arm.call(0xc8528, RUNNER_MGR, 1, 1)
        assert occupying_runner in (0, arm.word(RUNNERS))
        occupants.append(bool(occupying_runner))
        positions.append(bytes(arm.cpu.mem_read(arm.word(RUNNERS)+0x20, 12)))
        states.append(tuple(arm.cpu.mem_read(PLAY+i, 1)[0] for i in (6, 11, 0x1e, 0x1f)))
        maps.extend(frame())
        if ended:
            break
    else:
        raise RuntimeError(f'Defense did not end: group {group}, order {order}, batter {batter}, outs {outs}')

    # Require the batter-runner, first baseman, and original force-out call site.
    if len(holds) != 2 or len(releases) != 1 or len(judgments) > 1:
        return None, states
    (pickup, fielder, pickup_site), (received, receiver, receive_site) = holds
    if not pickup_site or not receive_site or received not in races:
        return None, states
    if receiver != 2 or (judgments and judgments[0] != (received, receiver, arm.word(RUNNERS), 2, 0xa111b)):
        return None, states
    provisional = next(i for i, state in enumerate(states, 1) if state[1] == 6)
    thrown, = releases
    assert 0 < pickup < thrown < received <= tick
    safe = not judgments
    final_call = 6 if safe else 13
    assert states[-1] == (outs+int(not safe), final_call, 1, 0)
    assert arm.call(0xc8614, RUNNER_MGR) == int(safe)
    assert arm.call(0xc8528, RUNNER_MGR, 1, 1) == (arm.word(RUNNERS) if safe else 0)
    assert arm.call(0xc87fc, RUNNER_MGR, 2) == arm.call(0xc87fc, RUNNER_MGR, 3) == 0
    assert bytes(arm.cpu.mem_read(ATT_ENTRY+0x295, 3))[::2] == bytes((1, (slot+1) % 9))
    assert arm.word(DEFENSE+0x18) == (25 if outs == 2 and not safe else 14)
    assert bytes(arm.cpu.mem_read(PLAY+0x142, 2)) == bytes(2)
    queries = bytearray()
    for when, who, site, disabled, args in attempts:
        if when <= pickup and who == fielder and site == pickup_site:
            stage = 0
        elif thrown < when <= received and who == receiver and site == receive_site:
            stage = 1
        else:
            continue
        queries.extend(QUERY.pack(when, stage, disabled, *args))
    initial, speed = runs[0][1:3]
    before_receipt = [r for r in runs if r[0] < received]
    # Once safe, the ARM runner stops requesting strides. The native stride
    # clamps to its destination for the remaining ticks before the throw.
    assert [r[0] for r in before_receipt] == list(range(1, len(before_receipt)+1))
    if safe:
        assert positions[received-2] == first_base
    else:
        assert len(before_receipt) == received-1
    assert all(r[1][12:] == first_base and r[2] == speed and r[3] for r in before_receipt)
    assert positions[received-2] == races[received][:12]
    run = struct.pack('<I', final_call) + initial + first_base + struct.pack('<I', speed)
    fields = (group, order, batter, outs, fielder, pickup, received, tick)
    if after_defense:
        after_defense(arm, safe)
    return (fields, provisional, thrown, bytes(queries), run, bytes(maps), positions[:received-1], occupants), states


def extract(apk, flights, path):
    records = []
    payload = bytearray()
    with zipfile.ZipFile(apk) as archive:
        for group in (3, 4, 5):
            for order in ORDERS:
                seed = seed_for(flights, group, order)
                for batter in (0, 1):
                    for outs in range(3):
                        play, _ = ground_play(archive, group, order, batter, outs, seed)
                        if play is None:
                            continue
                        fields, provisional, thrown, queries, run, maps, _, _ = play
                        qoff = len(payload)
                        payload.extend(queries)
                        payload.extend(run)
                        moff = len(payload)
                        payload.extend(maps)
                        records.append((fields, moff, provisional, thrown, len(queries)//QUERY.size, qoff))
    if not records:
        raise ValueError('No ground plays at first observed')
    start = 8 + len(records)*RECORD.size
    table = b''.join(RECORD.pack(*fields, start+m, p, t, n, start+q) for fields, m, p, t, n, q in records)
    temp = path.with_suffix('.tmp')
    temp.write_bytes(struct.pack('<4sI', b'GRP4', len(records)) + table + payload)
    temp.replace(path)
    print(f'{len(records)} empty-base ground plays through original reception and defense end.')


if __name__ == '__main__':
    extract(sys.argv[1], Path(sys.argv[2]).read_bytes(), Path(sys.argv[3]))
