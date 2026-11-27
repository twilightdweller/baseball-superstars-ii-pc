"""Run empty-base fly balls through the APK's original nine-player defense."""
import struct
import sys
import zipfile
import zlib
from pathlib import Path

from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_SP

from extract_batted_flight import DEFENSE, FIGURE, GAME, PATTERNS, PLAY, SCREEN, stadium

LEVEL = 0x500000
DEFENDERS, ENTRIES, ATT_ENTRY, DEF_ENTRY = 0x510000, 0x511000, 0x512000, 0x512400
DEF_TEAM, ATT_TEAM, MOVABLES = 0x513000, 0x514000, 0x520000
RUNNERS, RUNNER_MGR = 0x570000, 0x580000
FLOW, STATS = 0x5b0000, 0x550000
# Small fixed practice set. Other variants have no fielding result in the viewer.
ORDERS = range(3)
# group, variant order, batter, starting outs, fielder slot, catch, out, defense end (1-based ticks).
RECORD = struct.Struct('<8B')


def roster_rows(archive, name):
    data = zlib.decompress(archive.read(f'assets/data/Xls{name}_DATA.zt1')[8:])
    width, columns, count = struct.unpack_from('<3H', data, 4)
    start = 10 + columns
    if data[:4] != b'GXL\x01' or len(data) < start + count * width:
        raise ValueError(f'Invalid {name} roster')
    return [data[start+i*width:start+(i+1)*width] for i in range(count)]


def defense(archive):
    arm = stadium(archive)

    def external(pc, value=None):
        def callback(cpu, address, size, context):
            if value is not None:
                cpu.reg_write(arm.regs[0], value)
            cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
        arm.hook(pc, callback)

    arm.cpu.mem_write(LEVEL+4, archive.read('assets/data/d_level.dat'))
    arm.put(0x1f9d48, LEVEL)
    arm.put(0x1fc8fc, PLAY)
    arm.call(0xbdec0, 0x560000)  # Original stadium coordinate system.
    arm.put(0x1ed410, 0x5b3000)  # Presentation state cleared on defense exit.
    arm.call(0xacb4c, DEFENSE)
    arm.put(0x1f9d50, DEFENSE)
    env = arm.word(0x1f9d44)
    ball = arm.word(DEFENSE+4)

    # Same roster record widths, team offsets and XOR pass as LoadTeamDataFromRes.
    arm.cpu.mem_write(DEF_TEAM, roster_rows(archive, 'TEAM')[0])
    arm.put(DEF_TEAM+0xc, 8)
    arm.put(DEF_TEAM+0x10, 12)
    arm.cpu.mem_write(DEF_TEAM+0x14, b''.join(roster_rows(archive, 'PITCHER')[:8]))
    arm.cpu.mem_write(DEF_TEAM+0x250, b''.join(roster_rows(archive, 'BATTER')[:12]))
    arm.cpu.mem_write(DEF_TEAM+0x14, roster_rows(archive, 'ACE_PIT')[2])
    arm.put(ATT_TEAM+0x10, 2)
    arm.cpu.mem_write(ATT_TEAM+0x250, b''.join(roster_rows(archive, 'ACE_BAT')[:2]))
    for team in (DEF_TEAM, ATT_TEAM):
        arm.call(0xd61e4, team)

    def get_team(cpu, pc, size, context):
        entry = cpu.reg_read(arm.regs[0])
        cpu.reg_write(arm.regs[0], {ATT_ENTRY: ATT_TEAM, DEF_ENTRY: DEF_TEAM}[entry])
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
    arm.hook(0xd8ea0, get_team)

    # Frontend resources, audio, mission and statistics consumers. The original
    # event queue, catch selection, collision, judge and lineup reservation all run.
    for pc in (0xab6cc, 0xab59c, 0xb02e4, 0x12d48c, 0x88690, 0x880f0,
               0xc6448, 0xc3930, 0xc391c, 0xc44ec, 0xc6888, 0x1660e4,
               0x165154, 0xd2050, 0x165178):
        external(pc)
    external(0x17ee70, 0x5b2000)  # GetOption at the end of defense.
    for offset, value in {4: ball, 0xc: DEFENDERS, 0x10: RUNNERS, 0x14: RUNNER_MGR,
                          0x18: 0x530000, 0x20: 9, 0x24: 4, 0x34: STATS,
                          0x38: FLOW, 0x40: GAME+0x60, 0x44: GAME, 0x48: ENTRIES}.items():
        arm.put(env+offset, value)
    arm.put(GAME+0x60, 0x1ea8d4)  # CBBEvt subobject, CBBGGameRun::DoEvent thunk.
    arm.put(ENTRIES, ATT_ENTRY)
    arm.put(ENTRIES+4, DEF_ENTRY)
    arm.put(FLOW, 0x1e9e08)
    arm.put(FLOW+0x174, PLAY)
    arm.put(FLOW+0x178, STATS)
    for offset, value in {0x1f8: FLOW, 0x204: ATT_ENTRY, 0x254: 0x5b1000,
                          0x290: 0x5a0000, 0x294: 0x5a0100}.items():
        arm.put(GAME+offset, value)
    arm.put(0x5a0110, 1)  # User bats, computer fields.
    arm.cpu.mem_write(PLAY+10, bytes([1]))
    arm.cpu.mem_write(PLAY+0x11, bytes([1]))
    arm.cpu.mem_write(PLAY+0x12d, bytes([9]))
    for i in range(9):
        obj = MOVABLES + 0x200*i
        arm.call(0xc2fd8, obj)
        arm.call(0xc2a14, obj)
        arm.put(DEFENDERS+4*i, obj)
    arm.call(0xc95f4, RUNNER_MGR)
    arm.put(RUNNER_MGR+8, RUNNERS)
    for i in range(4):
        obj = 0x590000 + 0x200*i
        arm.call(0xc1038, obj)
        arm.call(0xc0f58, obj)
        arm.put(RUNNERS+4*i, obj)
    arm.call(0x95998, SCREEN, 0)
    arm.put(FIGURE+0x34c, -1)  # Default defensive alignment.
    return arm, ball


def minimap(arm):
    """Capture the original map's drawing calls, retaining its coordinates and RGB565 palette."""
    commands = bytearray()
    def draw(cpu, pc, size, context):
        x, y, w = (cpu.reg_read(r) for r in arm.regs[1:])
        sp = cpu.reg_read(UC_ARM_REG_SP)
        values = (x, y, w, arm.word(sp))
        signed = [v if v < 0x80000000 else v-0x100000000 for v in values]
        commands.extend(struct.pack('<BB4hH', kinds[pc], 0, *signed, arm.word(sp+4)))
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
    kinds = {0xbc5bc: 0, 0xbc574: 1, 0xbc434: 2, 0xbc5a8: 3}
    for pc in kinds:
        arm.hook(pc, draw)
    draw_object = 0x5c0000
    arm.cpu.mem_write(draw_object+0x58, bytes([1]))
    def frame():
        commands.clear()
        arm.call(0xb0a10, draw_object, 0, 0)
        return struct.pack('<H', len(commands)//12) + bytes(commands)
    return frame


def begin_play(archive, group, order, batter, outs, seed, slot, count):
    arm, ball = defense(archive)
    for _ in range(order):
        arm.call(0x9554c, PATTERNS, group)
    index = arm.call(0x95510, PATTERNS, group)
    arm.cpu.mem_write(PLAY+4, bytes([*count, outs]))
    arm.cpu.mem_write(ATT_ENTRY+0x32, bytes([slot]))
    # Two-batter practice order. The engine still reserves the next slot modulo nine.
    arm.cpu.mem_write(ATT_ENTRY+0xe, bytes(batter ^ ((i-slot) % 2) for i in range(9)))
    arm.put(0x2fd35c, seed)
    arm.call(0x163c0c, group, index)
    arm.call(0xad114, DEFENSE)
    return arm, ball


def play(archive, group, order, batter, outs, seed, slot=0, capture=False, count=(0, 0), observe=None):
    arm, ball = begin_play(archive, group, order, batter, outs, seed, slot, count)
    events = {}
    tick = 0

    def catch(cpu, pc, size, context):
        ai = cpu.reg_read(arm.regs[0])
        events.setdefault('catch', (tick, arm.word(ai+0x14)))

    def judge(cpu, pc, size, context):
        if cpu.reg_read(arm.regs[0]) == 0:
            holder = arm.word(0x1f9d68)  # CCLDefenderAIMain::s_pBallCatchedDefender
            assert holder and events['catch'][1] == arm.word(holder+0x14)
            events['fly'] = tick

    arm.hook(0xa5ab0, catch)
    arm.hook(0xae1dc, judge)
    if observe:
        observe(arm, ball)
    frame = minimap(arm) if capture else None
    frames = bytearray()
    bounce = arm.word(ball+0x7cc)
    for tick in range(1, 201):
        if 'catch' not in events and arm.word(ball+0x9ac) >= bounce:
            return None
        try:
            ended = arm.call(0xad5b4, DEFENSE)
        except RuntimeError as exc:
            raise RuntimeError(f'group {group} order {order} batter {batter} outs {outs} tick {tick}: {exc}') from exc
        current_outs = arm.cpu.mem_read(PLAY+6, 1)[0]
        if current_outs != outs:
            events.setdefault('out', tick)
        if frame:
            frames.extend(frame())
        if ended:
            if 'fly' not in events:
                return None
            caught, defender = events['catch']
            assert 0 <= defender < 9 and caught <= events['fly'] <= events['out'] <= tick
            assert arm.cpu.mem_read(PLAY+0xb, 1)[0] == 13 and current_outs == outs+1
            assert arm.cpu.mem_read(ATT_ENTRY+0x295, 1)[0] == 1
            assert arm.cpu.mem_read(ATT_ENTRY+0x297, 1)[0] == (slot+1) % 9
            assert arm.word(DEFENSE+0x18) == (25 if outs == 2 else 14)
            assert bytes(arm.cpu.mem_read(PLAY+0x142, 2)) == bytes(2)
            record = (group, order, batter, outs, defender, caught, events['out'], tick)
            return record, bytes(frames)
    raise RuntimeError(f'Defense did not end: group {group}, order {order}, outs {outs}')


def seed_for(flights, group, order):
    count, table = struct.unpack_from('<II', flights, 8*group)
    if order >= count:
        raise ValueError('Missing flight variant')
    return struct.unpack_from('<I', flights, table+16*order+8)[0]


def extract(apk, flights, destination):
    records = []
    maps = bytearray()
    with zipfile.ZipFile(apk) as archive:
        for group in range(3):
            for order in ORDERS:
                seed = seed_for(flights, group, order)
                for batter in (0, 1):
                    for outs in range(3):
                        result = play(archive, group, order, batter, outs, seed, capture=True)
                        if result:
                            record, frames = result
                            records.append((RECORD.pack(*record), len(maps)))
                            maps.extend(frames)
    if not records:
        raise ValueError('No ordinary fly outs observed')
    temp = destination.with_suffix('.tmp')
    start = 4 + 12*len(records)
    table = b''.join(record + struct.pack('<I', start+offset) for record, offset in records)
    temp.write_bytes(struct.pack('<I', len(records)) + table + maps)
    temp.replace(destination)
    print(f'{len(records)} empty-base fly-out cases verified through defense end.')


if __name__ == '__main__':
    extract(sys.argv[1], Path(sys.argv[2]).read_bytes(), Path(sys.argv[3]))
