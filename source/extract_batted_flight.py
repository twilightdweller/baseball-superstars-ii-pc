"""Materialize the original batting-view trajectory buffers for the fixed stadium."""
import io
from pathlib import Path
import struct
import sys
import zipfile
from arm_reference import ArmReference
from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC
from extract_figure import decode

FIGURE, POINTS, FENCE, PATTERNS, GAME, SOURCE, SCREEN = range(0x400000, 0x470000, 0x10000)
BALL = GAME + 0xe8
FIELD_ENV, PLAY, DEFENSE, FIELD_BALL = range(0x480000, 0x4c0000, 0x10000)
NORMAL_GROUPS = tuple(p+d for p in (0, 3, 9, 15, 18, 21) for d in range(3))


def stadium(archive):
    arm = ArmReference(io.BytesIO(archive.read('lib/armeabi/libgameDSO.so')))
    figure, fence = decode(archive.read('assets/data/bb2011_480x320.fig'))
    arm.cpu.mem_write(FIGURE+4, figure)
    arm.put(FIGURE+0x154, POINTS)
    arm.cpu.mem_write(POINTS, fence)
    arm.put(0x1f9cf4, FIGURE)
    arm.put(0x1f9cf8, SCREEN)
    arm.put(SCREEN+0x168, -1)
    arm.call(0x95998, SCREEN, 1)
    arm.put(0x1f9d10, FENCE)
    arm.call(0xbc5fc, FENCE)
    arm.call(0xbcb70, FENCE)
    data = archive.read('assets/data/bb2011.bpd')
    header, = struct.unpack_from('<I', data)
    if header >> 24 != 2 or header & 0xffffff != len(data)-4:
        raise ValueError('Unexpected batting pattern archive version or size')
    arm.cpu.mem_write(SOURCE, data)
    arm.put(0x1f9cf0, PATTERNS)
    arm.put(0x1fbad8, GAME)
    arm.call(0x950a8, PATTERNS+4, SOURCE+4)
    arm.call(0xb9728, BALL)
    arm.call(0x955b4, PATTERNS)  # Original ShufflePatternIndx.
    return arm


def trajectory(arm, group, index):
    arm.call(0xaa910, group, index)
    count = arm.word(BALL+0x9b0)
    if not 0 < count <= 150 or count != arm.word(BALL+0x750):
        raise ValueError(f'Pattern {group}/{index} has invalid sample count {count}')
    return bytes(arm.cpu.mem_read(BALL+0x48, 12*count))


def setup_field(arm):
    arm.put(0x1f9d44, FIELD_ENV)
    arm.put(0x1fc8fc, PLAY)
    arm.put(FIELD_ENV+4, FIELD_BALL)
    arm.put(DEFENSE+4, FIELD_BALL)
    arm.call(0xb9728, FIELD_BALL)

    # No players are fielding this ball. The event queue and visual judge effects
    # are consumers. JudgeDefenseFoul itself decides and writes the verdict.
    def ignore_notification(cpu, pc, size, context):
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
    arm.hook(0xaa3e0, ignore_notification)
    arm.hook(0xae0b8, ignore_notification)


def launch_field(arm, group, index):
    arm.cpu.mem_write(FIELD_ENV+0x54, bytes(0x100))
    arm.cpu.mem_write(PLAY, bytes(0x180))
    arm.call(0x163c0c, group, index)  # CCLDefenseEnv::SetBattingPattern
    arm.call(0xacf40, DEFENSE)        # CCLDefenseMain::BattingBall
    count = arm.word(FIELD_BALL+0x9b0)
    if not 0 < count <= 150:
        raise ValueError(f'Invalid defense flight length {group}/{index}: {count}')
    return count


def untouched_foul(arm, group, index):
    count = launch_field(arm, group, index)
    # JudgeDefenseFoul compares the trajectory cursor to its first bounce or
    # fence collision. At rest the movable clamps this cursor to count-1.
    arm.put(FIELD_BALL+0x9ac, count-1)
    arm.call(0xae97c)
    return arm.cpu.mem_read(PLAY+0x1c, 1)[0]


def extract(apk, destination):
    with zipfile.ZipFile(apk) as archive:
        arm = stadium(archive)
    setup_field(arm)
    # Group descriptors -> array of variant descriptors -> aligned Q18 XYZ samples.
    output = bytearray(24*8)
    paths = samples = 0
    for group in NORMAL_GROUPS:
        count = arm.word(PATTERNS+4+28*group)
        table = len(output)
        struct.pack_into('<II', output, 8*group, count, table)
        output.extend(bytes(16*count))
        indices = set()
        for order in range(count):
            index = arm.call(0x95510, PATTERNS, group)
            if not 0 <= index < count or index in indices:
                raise ValueError(f'Invalid original pattern order {group}/{order}/{index}')
            indices.add(index)
            launch_seed = arm.word(0x2fd35c)
            data = trajectory(arm, group, index)
            foul = untouched_foul(arm, group, index)
            struct.pack_into('<IIII', output, table+16*order, len(data)//12, len(output), launch_seed, foul)
            output.extend(data)
            arm.call(0x9554c, PATTERNS, group)
            paths += 1
            samples += len(data)//12
        assert arm.word(PATTERNS+(0xc2+group)*4) == 0
    temp = destination.with_suffix('.tmp')
    temp.write_bytes(output)
    temp.replace(destination)
    print(f'{paths} original stadium trajectories, {samples} Q18 XYZ samples, {len(NORMAL_GROUPS)} pattern groups.')


if __name__ == '__main__':
    extract(sys.argv[1], Path(sys.argv[2]))
