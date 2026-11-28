"""Compare ordinary taken pitches with the original ARM judge and event handlers."""
import ctypes as C
import itertools
import json
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB, UC_HOOK_CODE, UC_PROT_NONE
from unicorn.arm_const import (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
                               UC_ARM_REG_SP, UC_ARM_REG_PC, UC_ARM_REG_LR)

u = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
u.mem_map(0, 0x1000000)
with open(sys.argv[1], 'rb') as f:
    e = ELFFile(f)
    for segment in e.iter_segments():
        if segment['p_type'] == 'PT_LOAD':
            u.mem_write(segment['p_vaddr'], segment.data())
    symbols = {s.name: s['st_value'] for s in e.get_section_by_name('.dynsym').iter_symbols()}
    for section in e.iter_sections():
        if section['sh_type'] != 'SHT_REL':
            continue
        table = e.get_section(section['sh_link'])
        for relocation in section.iter_relocations():
            kind, address = relocation['r_info_type'], relocation['r_offset']
            symbol = table.get_symbol(relocation['r_info_sym'])
            if symbol['st_shndx'] == 'SHN_UNDEF':
                continue
            if kind in (21, 22):
                u.mem_write(address, struct.pack('<I', symbol['st_value']))
            elif kind == 2:
                old = struct.unpack('<I', u.mem_read(address, 4))[0]
                u.mem_write(address, struct.pack('<I', (old + symbol['st_value']) & 0xffffffff))

u.mem_protect(0, 4096, UC_PROT_NONE)
RUN, PLAY, ENGINE, FLOW = 0x500000, 0x510000, 0x520000, 0x530000
BATTER, ENTRY, STATS, DEFENSE = 0x540000, 0x550000, 0x560000, 0x570000
PITCH, FIGURE, SCREEN, SAMPLE = 0x580000, 0x590000, 0x600000, 0x610000
MISC, RECORD, STOP = 0x620000, 0x630000, 0xa00000
REGS = (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)
presentation = {0x8842c, 0x88690, 0x12d48c, 0x17db48, 0x1b1324, 0x1b12f4}
arm_effects, native_effects, delivered = [], [], []
observed_rect = []
heap = 0x700000
allocations = set()

def word(a):
    return struct.unpack('<I', u.mem_read(a, 4))[0]

def put(a, v):
    u.mem_write(a, struct.pack('<I', v & 0xffffffff))

def hook(uc, pc, size, data):
    global heap
    if pc == 0xb127c:
        x, y, w, h = struct.unpack('<4i', uc.mem_read(uc.reg_read(REGS[0]), 16))
        observed_rect[:] = [x, y, x+w, y+h]
    if pc == 0x172fd0:
        delivered.append(tuple(uc.reg_read(r) for r in REGS[:3]))
    if pc in (0x77850, 0x7764c):
        dest, src, length = (uc.reg_read(r) for r in REGS[:3])
        assert length <= 4096
        uc.mem_write(dest, bytes([src & 255]) * length if pc == 0x77850 else bytes(uc.mem_read(src, length)))
    elif pc in (0x18d2a4, 0x189b18):
        length = uc.reg_read(REGS[0])
        assert 0 < length <= 4096
        addr = heap
        heap += (length+7) & ~7
        assert heap < 0x710000
        allocations.add(addr)
        uc.mem_write(addr, bytes([0 if pc == 0x189b18 else 0xcc]) * length)
        uc.reg_write(REGS[0], addr)
        uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
        return
    elif pc in (0x18d294, 0x189af8):
        allocations.remove(uc.reg_read(REGS[0]))
    elif pc in (0xc6394, 0xc6888):
        assert uc.reg_read(REGS[0]) == STATS
        if pc == 0xc6888:
            arm_effects.append(1)
    elif pc not in presentation:
        return
    uc.reg_write(UC_ARM_REG_R0, MISC if pc == 0x17db48 else 0)
    uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

u.hook_add(UC_HOOK_CODE, hook)

def call(addr, *args):
    for r, v in zip(REGS, args):
        u.reg_write(r, v)
    u.reg_write(UC_ARM_REG_SP, 0x900000)
    u.reg_write(UC_ARM_REG_LR, STOP+1)
    try:
        u.emu_start(addr, STOP, count=200000)
    except Exception as exc:
        raise RuntimeError(f'ARM {addr:#x} failed at PC {u.reg_read(UC_ARM_REG_PC):#x}, '
                           f'LR {u.reg_read(UC_ARM_REG_LR):#x}') from exc
    assert u.reg_read(UC_ARM_REG_PC) == STOP, (hex(addr), hex(u.reg_read(UC_ARM_REG_PC)))
    return u.reg_read(UC_ARM_REG_R0)

class AtBat(C.Structure):
    _fields_ = [('play', C.c_uint8 * 0x180), ('slot', C.c_uint8),
                ('reserved', C.c_uint8), ('next_slot', C.c_uint8), ('defense', C.c_uint8), ('first_base_slot', C.c_uint8), ('second_base_slot', C.c_uint8)]

Camera, Zone, Point = C.c_int32 * 20, C.c_int32 * 4, C.c_int32 * 3
Callback = C.CFUNCTYPE(None, C.c_void_p, C.c_int)

@Callback
def effect(context, kind):
    native_effects.append(kind)

n = C.CDLL(sys.argv[2])
n.bs2_take_curve.argtypes = [C.POINTER(AtBat), C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p]
n.bs2_judge_unhit_curve.argtypes = [C.POINTER(AtBat), C.c_int, C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p]
n.bs2_batting_offset.argtypes = [C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p, C.c_void_p]
n.bs2_taken_pitch_next_state.argtypes = [C.POINTER(AtBat), C.c_uint, Callback, C.c_void_p]
n.bs2_pitch_in_zone.argtypes = [C.c_void_p, C.c_void_p, C.c_void_p]
n.bs2_strike_zone.argtypes = [C.c_void_p, C.c_size_t, C.c_void_p, C.c_void_p]
n.bs2_camera_from_figure.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_void_p]

def camera_setup(asset, preset):
    scene = asset.read_bytes()
    u.mem_write(FIGURE, bytes(1024))
    u.mem_write(FIGURE+4, scene)
    put(0x1f9cf4, FIGURE)
    put(0x1f9cf8, SCREEN)
    u.mem_write(SCREEN, bytes(0x200))
    put(SCREEN+0x168, -1)
    call(0x95999, SCREEN, preset)
    camera, zone = Camera(), Zone()
    assert n.bs2_camera_from_figure(scene, len(scene), preset, camera) == 0
    assert n.bs2_strike_zone(scene, len(scene), camera, zone) == 0
    call(0x96dd1, FIGURE, SAMPLE)
    assert list(zone) == observed_rect, (asset, preset, list(zone), observed_rect)
    return camera, zone


class Spec(C.Structure):
    _fields_ = [(key, C.c_int32) for key in ('count', 'frames', 'style', 'mirror', 'format', 'kind', 'mode', 'phase')] + [('release', Point), ('target', Point)]

n.bs2_pitch_release.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_int, C.c_void_p]
n.bs2_pitch_path.argtypes = [C.POINTER(Spec), C.c_void_p, C.c_void_p, C.c_void_p]

def generate_curve(scene, record, offset, raised):
    global heap
    points = (Point * len(record['points']))(*(Point(*p) for p in record['points']))
    count, frames = len(points), record['base_frames']
    target = Point(*record['points'][-1])
    target[0] += offset * 262144
    release = Point()
    assert n.bs2_pitch_release(scene, len(scene), record['style'], raised, release) == 0
    spec = Spec(count, frames, record['style'], 0, 1, record['spline_kind'], 0, 0, release, target)
    controls, native_path = (Point * count)(), (Point * (frames+3))()
    assert n.bs2_pitch_path(C.byref(spec), points, controls, native_path) == 0
    # Independent ARM inputs. UpdatePitch computes release from the original figure.
    obj = PITCH + 4
    u.mem_write(obj, bytes(256))
    u.mem_write(FIGURE+0x334, bytes([raised]))
    put(obj, spec.style)
    heap = 0x700000
    call(0xb4239, obj, frames)  # SetTotalFrameCount allocates the path and selects the judge frame
    sample_buffer, sample_count, judge_frame = (word(obj+p) for p in (0x84, 0x88, 0x8c))
    assert sample_count == len(native_path) and judge_frame == sample_count-4
    for pos, val in {0x7c: 0x640000, 0x80: count, 0x9c: count, 0xa0: 0x650000,
                     0xa4: 0x660000, 0xa8: 0x670000}.items():
        put(obj+pos, val)
    u.mem_write(obj+0xc0, bytes(target))
    u.mem_write(obj+0xd4, bytes([1, spec.kind]))
    u.mem_write(0x640000, bytes(points))
    call(0xb43e9, obj, 0)
    assert allocations == {sample_buffer}
    arm_path = bytes(u.mem_read(sample_buffer, sample_count * 12))
    call(0x189af9, sample_buffer)
    assert not allocations
    assert bytes(native_path) == arm_path
    return native_path, arm_path, judge_frame

def setup(slot, outs):
    for addr in (RUN, PLAY, ENGINE, FLOW, BATTER, ENTRY, STATS, DEFENSE, PITCH, MISC, RECORD):
        u.mem_write(addr, bytes(0x2000))
    for addr, val in {
        0x1fc8fc: PLAY, 0x1fbad8: PITCH, 0x1f9d44: DEFENSE,
        0x1fbadc: MISC, 0x1ed470: MISC, 0x1fc8ec: MISC, 0x1f9d48: MISC,
        RUN+0x60: symbols['_ZTV11CBBGGameRun'] + 68, RUN+0x1f0: ENGINE,
        RUN+0x1f8: FLOW, RUN+0x204: ENTRY, RUN+0x208: RECORD,
        RUN+0x214: STATS, RUN+0x28c: BATTER, RUN+0x9e0: MISC, RUN+0xa28: MISC,
        MISC+0x60: PLAY, MISC+0x1c: MISC+0x400, FLOW: symbols['_ZTV11CBBGFlowMgr'] + 8,
        FLOW+0x174: PLAY, FLOW+0x178: STATS, ENGINE+8: PLAY,
        STATS+8: PLAY, STATS+12: RECORD, PITCH+0x88: SAMPLE,
        PITCH+0xd0: SCREEN+4, RUN+0xc: 19,
    }.items():
        put(addr, val)
    u.mem_write(MISC+0x9f, bytes([1]))  # disable auto simulation
    u.mem_write(BATTER+0xd, bytes([1]))  # original IsHitByPitcher early-out
    u.mem_write(ENTRY+0x32, bytes([slot]))
    ab = AtBat()
    ab.slot, ab.play[6], ab.play[0x12d] = slot, outs, 9
    u.mem_write(PLAY, bytes(ab.play))
    return ab

def compare(ab, paths, camera, zone, swung=False):
    native_path, arm_path, judge_frame = paths
    u.mem_write(SAMPLE, arm_path)
    put(PITCH+0x90, judge_frame)
    native_effects.clear()
    arm_effects.clear()
    delivered.clear()
    put(RUN+0x10, 19)
    u.mem_write(RUN+0x20, bytes(1))
    u.mem_write(BATTER+0xe, bytes([swung]))
    call(0x169f2d, RUN)
    if swung:
        result = n.bs2_judge_unhit_curve(C.byref(ab), 1, native_path, len(native_path), camera, zone)
    else:
        result = n.bs2_take_curve(C.byref(ab), native_path, len(native_path), camera, zone)
    assert result == ab.play[0xb] and result > 0
    assert delivered == [(RUN, 0xbba, ab.play[0xb])], delivered
    assert word(RUN+0x330) == ab.play[0xc]
    assert bytes(ab.play) == bytes(u.mem_read(PLAY, 0x180)), [
        (hex(i), a, b) for i, (a, b) in enumerate(zip(ab.play, u.mem_read(PLAY, 0x180))) if a != b]
    assert (ab.reserved, ab.next_slot) == (u.mem_read(ENTRY+0x295, 1)[0], u.mem_read(ENTRY+0x297, 1)[0])
    assert ab.defense == word(DEFENSE+0xc0)
    delay = 31 if ab.play[0xb] in (3, 5) else 15
    assert n.bs2_taken_pitch_next_state(C.byref(ab), delay-1, effect, None) == 0
    assert not native_effects
    put(RUN+0x1c, delay-1)
    call(0x169135, RUN)
    assert word(RUN+0x10) == 19 and u.mem_read(RUN+0x20, 1)[0] == 0
    put(RUN+0x1c, delay)
    call(0x169135, RUN)
    state = n.bs2_taken_pitch_next_state(C.byref(ab), delay, effect, None)
    assert state == word(RUN+0xb18) == word(RUN+0x10)
    assert u.mem_read(RUN+0x20, 1)[0] == 1 and native_effects == arm_effects
    return state

assets = [p for p in sorted(Path(__file__).with_name('figure-assets').glob('*.bin')) if 'fence' not in p.name]
records = json.loads(Path(__file__).with_name('pitch-records.json').read_text())
cases = [next(r for r in records if r['spline_kind'] == k) for k in (0, 1)]
# Every possible ball/strike history that ends on the third strike or fourth ball.
sequences = [''.join(prefix) + last
             for length in range(3, 7) for prefix in itertools.product('BS', repeat=length-1)
             for last in 'BS' if prefix.count('B') < 4 and prefix.count('S') < 3
             and (prefix.count(last) == (3 if last == 'B' else 2))]
assert len(sequences) == 35
appearances = pitches = boundary_cases = 0
for asset, preset in itertools.product(assets, range(3)):
    camera, zone = camera_setup(asset, preset)
    scene = asset.read_bytes()
    for x, y in itertools.product((-50, -11, 0, 10, 50), repeat=2):
        u.mem_write(RUN+0x348, struct.pack('<iii', x, y, -990))
        point = Point(x * 262144, y * 262144, -990 * 262144)
        offset = (C.c_int32 * 2)()
        assert n.bs2_batting_offset(scene, len(scene), camera, point, offset) == 0
        expected = [C.c_int32(call(addr, RUN)).value for addr in (0x16f1b9, 0x16f16d)]
        assert list(offset) == expected, (asset, preset, x, y, list(offset), expected)
    strike = Point(0, -11 * 262144, -990 * 262144)
    ball = Point(40 * 262144, strike[1], strike[2])
    assert n.bs2_pitch_in_zone(strike, camera, zone) == 1
    assert n.bs2_pitch_in_zone(ball, camera, zone) == 0
    # Compare original pixel rounding and inclusion near each world-space edge.
    put(PITCH+0x88, SAMPLE)
    put(PITCH+0xd0, SCREEN+4)
    for x, y in itertools.product((-16, -15, -14, -1, 0, 1, 14, 15, 16), repeat=2):
        point = Point(x * 131072, strike[1] + y * 131072, strike[2])
        u.mem_write(SAMPLE, bytes(point))
        call(0xb409d, MISC+0x800, PITCH+4, 0)
        expected = call(0x96dd1, FIGURE, MISC+0x800)
        assert n.bs2_pitch_in_zone(point, camera, zone) == expected
        boundary_cases += 1
    curves = {(i, c): generate_curve(asset.read_bytes(), r, offset, int(preset == 0))
              for i, r in enumerate(cases) for c, offset in (('S', 0), ('B', 40))}
    for location, outs in itertools.product('SB', (0, 2)):
        ab = setup(8, outs)
        for i in range(3):
            state = compare(ab, curves[i % 2, location], camera, zone, swung=True)
            assert ab.play[0xb] == (1 if i < 2 else 5)
        assert ab.reserved and ab.next_slot == 0 and state == (25 if outs == 2 else 14)
    for seq, outs, slot in itertools.product(sequences, (0, 2), (0, 8)):
        ab = setup(slot, outs)
        for i, c in enumerate(seq):
            paths = curves[i % 2, c]
            state = compare(ab, paths, camera, zone)
            assert ab.play[0x18] == (c == 'S')
            pitches += 1
        assert ab.reserved and ab.next_slot == (slot+1) % 9
        assert state == (24 if seq.endswith('B') else (25 if outs == 2 else 14))
        before = bytes(ab)
        curve = paths[0]
        assert n.bs2_take_curve(C.byref(ab), curve, len(curve), camera, zone) == -1 and bytes(ab) == before
        appearances += 1
print('PASS: 150 batting offsets and 24 swinging strikeouts across both figures and all three cameras match ARM.')
print(f'PASS: {boundary_cases} projected samples near zone boundaries and all six pixel rectangles match ARM.')
print(f'PASS: {appearances} taken-pitch appearances, {pitches} pitches; ARM events, play bytes, batter reservation and next states match.')
