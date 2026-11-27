"""Original next-batter and pitch judge on the same machine as the completed ground play."""
import ctypes as C
import struct

from unicorn.arm_const import UC_ARM_REG_PC, UC_ARM_REG_LR
from extract_batted_flight import DEFENSE, GAME, PATTERNS, PLAY, SCREEN
from extract_fly_outs import ATT_ENTRY, ATT_TEAM, DEF_TEAM, RUNNERS, RUNNER_MGR, STATS


def original_first_pitch(arm, safe, *, outside, result, next_ground_seed=None):
    if not safe:
        return
    cpu = arm.cpu
    runner = arm.word(RUNNERS)
    def first():
        return arm.call(0xc8528, RUNNER_MGR, 1, 1)

    assert first() == runner
    slot = cpu.mem_read(ATT_ENTRY+0x32, 1)[0]
    expected_slot = cpu.mem_read(ATT_ENTRY+0x297, 1)[0]
    # UpdatePlayer checks the batting team's own pitcher as well as the
    # incoming batter. Supply a real pitcher record and the imported stack guard.
    arm.put(ATT_TEAM+0xc, 1)
    cpu.mem_write(ATT_TEAM+0x14, bytes(cpu.mem_read(DEF_TEAM+0x14, 0x44)))
    arm.put(0x1eb8e8, 0x614000)
    arm.call(0xcc67c, ATT_ENTRY, 1)
    assert cpu.mem_read(ATT_ENTRY+0x32, 1)[0] == expected_slot == (slot+1) % 9
    assert cpu.mem_read(ATT_ENTRY+0x295, 1)[0] == 0 and first() == runner
    arm.call(0xd7ed4, PLAY)
    assert bytes(cpu.mem_read(PLAY+4, 2)) == bytes(2)

    pitch, engine, batter, misc = 0x610000, 0x611000, 0x612000, 0x613000
    for address, value in (
        (GAME+0x1f0, engine), (engine+8, PLAY), (GAME+0x28c, batter), (GAME+0x214, STATS),
        (STATS+8, PLAY), (STATS+12, misc+0x900), (STATS+16, misc+0xc00),
        (GAME+0x9e0, misc), (GAME+0xa28, misc), (0x1fbad8, pitch), (pitch+0x88, misc+0x800),
        (pitch+0xd0, SCREEN+4), (GAME+0x10, 19), (GAME+0xc, 19), (GAME+0x208, misc+0x900),
        (0x1fbadc, misc), (misc+0x60, PLAY), (misc+0x1c, misc+0x400), (0x1ed470, misc), (0x1fc8ec, misc)):
        arm.put(address, value)
    cpu.mem_write(batter+0xd, b'\1')  # Ordinary pitch, no HBP.
    cpu.mem_write(misc+0x9f, b'\1')
    cpu.mem_write(PLAY+0x11, b'\0')
    def presentation(cpu, pc, size, context):
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
    for pc in (0x8842c, 0x17db48, 0x1b1324, 0x1b12f4):
        arm.hook(pc, presentation)
    preset = 1 if cpu.mem_read(ATT_ENTRY+0xe+expected_slot, 1)[0] else 2
    arm.call(0x95998, SCREEN, preset)
    sample = struct.pack('<3i', (40 if outside else 0)*262144, -11*262144, -990*262144)
    cpu.mem_write(misc+0x800, sample)
    arm.call(0x169f2c, GAME)
    assert first() == runner and arm.call(0xc8614, RUNNER_MGR) == 1
    result.update(preset=preset, sample=sample, call=cpu.mem_read(PLAY+0xb, 1)[0],
                  counts=bytes(cpu.mem_read(PLAY+4, 3)), slot=expected_slot)
    if next_ground_seed is not None:
        trace_next_grounder(arm, runner, next_ground_seed)


def trace_next_grounder(arm, lead_runner, seed):
    """Original acceptance case for future occupied-base defense after Ara's single."""
    index = arm.call(0x95510, PATTERNS, 3)
    arm.call(0x163c0c, 3, index)
    arm.put(0x2fd35c, seed)
    arm.cpu.mem_write(PLAY+0x11, bytes([1]))  # Next swing made fair contact.
    arm.call(0xad114, DEFENSE)
    holds, outs = [], []
    def catch(cpu, pc, size, context):
        holds.append((tick, arm.word(cpu.reg_read(arm.regs[0])+0x14)))
    def judge(cpu, pc, size, context):
        fielder, ai = (cpu.reg_read(r) for r in arm.regs[:2])
        runner = arm.word(ai+4)
        outs.append((tick, arm.word(fielder+0x14), runner, arm.word(runner+0x7c)))
    arm.hook(0xa5ab0, catch)
    arm.hook(0xae10c, judge)
    for tick in range(1, 100):
        if arm.call(0xad5b4, DEFENSE):
            break
    assert tick == 45 and holds == [(11, 0), (21, 3), (31, 2)]
    assert len(outs) == 2 and outs[0] == (21, 3, lead_runner, 2)
    assert outs[1][:2] == (31, 2) and outs[1][2] != lead_runner and outs[1][3] == 1
    assert arm.cpu.mem_read(PLAY+6, 1)[0] == 2 and arm.cpu.mem_read(PLAY+11, 1)[0] == 13
    assert arm.call(0xc8614, RUNNER_MGR) == 0 and arm.word(DEFENSE+0x18) == 14


def compare_first_pitch(dll, ab, scene, reference):
    camera, zone = (C.c_int32*20)(), (C.c_int32*4)()
    dll.bs2_camera_from_figure.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_void_p]
    dll.bs2_strike_zone.argtypes = [C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p]
    dll.bs2_take_curve.argtypes = [C.c_void_p, C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p]
    assert dll.bs2_camera_from_figure(scene, len(scene), reference['preset'], camera) == 0
    assert dll.bs2_strike_zone(scene, len(scene), camera, zone) == 0
    # PitchJudge examines the fourth-from-last sample. The Windows input test
    # also exercises the full pitch generator and real delivery.
    path = reference['sample']*5
    code = dll.bs2_take_curve(C.byref(ab), path, 5, camera, zone)
    assert code == reference['call'] and bytes(ab.play[4:7]) == reference['counts']
    assert ab.slot == reference['slot'] and not ab.reserved
    return code
