"""Compare native normal swings with the APK's ARM code at the contact decision."""
import ctypes as C
import itertools
import struct
import sys
import zipfile
import zlib

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_HOOK_CODE, UC_MODE_THUMB, UC_PROT_NONE
from unicorn.arm_const import (UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_R1,
                               UC_ARM_REG_R2, UC_ARM_REG_R3, UC_ARM_REG_R4,
                               UC_ARM_REG_R5, UC_ARM_REG_R6, UC_ARM_REG_SP)


class Offset(C.Structure):
    _fields_ = [('x', C.c_int32), ('y', C.c_int32)]


def roster(apk, role, index):
    data = zlib.decompress(apk.read(f'assets/data/XlsACE_{role}_DATA.zt1')[8:])
    assert data[:4] == b'GXL\x01'
    stride, columns, rows = struct.unpack_from('<HHH', data, 4)
    assert index < rows
    return struct.unpack_from('<4H', data, 10 + columns + stride * index + 12)


u = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
u.mem_map(0, 0x1000000)
with open(sys.argv[1], 'rb') as elf:
    for segment in ELFFile(elf).iter_segments():
        if segment['p_type'] == 'PT_LOAD':
            u.mem_write(segment['p_vaddr'], segment.data())
u.mem_protect(0, 4096, UC_PROT_NONE)

with zipfile.ZipFile(sys.argv[2]) as apk:
    level = apk.read('assets/data/d_level.dat')
    batters = [roster(apk, 'BAT', ace) for ace in (0, 1)]
    pitcher = roster(apk, 'PIT', 2)
assert len(level) == 516
native = C.CDLL(sys.argv[3])
native.bs2_swing_pattern.argtypes = [C.c_int, C.c_int, C.c_int, Offset, C.POINTER(C.c_uint32)]
native.bs2_swing_art_frame.argtypes = [C.c_int, C.c_uint]

REGS = [UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3]
LEVEL, PLAY, BATTER, PITCHER, ENTRY, TEAM, RESULT = range(0x510000, 0x580000, 0x10000)
STACK, STOP, SEED = 0x900000, 0xa00000, 0x2fd35c


def put(address, value):
    u.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(address):
    return struct.unpack('<I', u.mem_read(address, 4))[0]


def call(address, *args):
    for reg, value in zip(REGS, args):
        u.reg_write(reg, value)
    u.reg_write(UC_ARM_REG_SP, STACK)
    u.reg_write(UC_ARM_REG_LR, STOP+1)
    u.emu_start(address | 1, STOP, count=40000)
    assert u.reg_read(UC_ARM_REG_PC) == STOP, hex(u.reg_read(UC_ARM_REG_PC))
    return u.reg_read(REGS[0])


# Supply only the roster, team and passive-skill inputs. The original routine reads
# d_level, computes both odds and executes the original RNG and result writes.
def fixture(cpu, pc, size, data):
    if pc == 0xd6a78:
        player = cpu.reg_read(REGS[2])
        assert player in (BATTER, PITCHER)
        value = (batters[ace] if player == BATTER else pitcher)[cpu.reg_read(REGS[1])]
    else:
        value = {0xcc2d0: BATTER, 0xcc514: PITCHER, 0xd8ea0: TEAM}.get(pc, 0)
    cpu.reg_write(REGS[0], value)
    cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))


for pc in (0xd6a78, 0xcc2d0, 0xcc514, 0xd8ea0, 0xc9710, 0xc9b00, 0xe0f2c, 0xe0f1c, 0xd7958):
    u.hook_add(UC_HOOK_CODE, fixture, begin=pc, end=pc)
decision = []
def observe(cpu, *args):
    decision.append((cpu.reg_read(UC_ARM_REG_R4), cpu.reg_read(REGS[0])))
u.hook_add(UC_HOOK_CODE, observe, begin=0xcb164, end=0xcb164)

u.mem_write(LEVEL+4, level)
put(0x1f9d48, LEVEL)
put(0x1fc8fc, PLAY)
for offset in (9, 0x31):
    u.mem_write(PLAY+offset, bytes([0, 1]))


RUN, PITCH = 0x600000, 0x610000
put(0x1fbad8, PITCH)
put(PITCH+0x90, 15)
put(RUN+0x204, ENTRY)
patterns = set()


def compare(seed, swing, x, y):
    timing = {15: 100, 14: 75, 16: 75}.get(swing, 0)
    decision.clear()
    put(SEED, seed)
    u.mem_write(RESULT, bytes(32))
    # Normal swing, no bunt or skill, empty bases, 90 pitch speed.
    stack = [TEAM, timing, 0, x, y, 0, 0, 0, 90, 0, 0, 0, TEAM]
    for i, value in enumerate(stack):
        put(STACK+4*i, value)
    call(0xca504, RESULT, ENTRY, TEAM, TEAM+0x1000)
    assert len(decision) == 1
    native_seed = C.c_uint32(seed)
    original = -1
    if u.mem_read(RESULT+6, 1)[0]:
        # Execute the original DoEvent direction selection up to its pattern lookup.
        u.mem_write(RUN+0x2b8, bytes(u.mem_read(RESULT, 12)))
        put(RUN+0x2c4, swing)
        u.mem_write(BATTER+0xb, bytes([0x40 | ace]))
        u.reg_write(UC_ARM_REG_SP, STACK)
        u.reg_write(UC_ARM_REG_R5, (0x172ffa + word(0x1733a0)) & 0xffffffff)
        u.reg_write(UC_ARM_REG_R6, RUN)
        u.reg_write(UC_ARM_REG_R2, 0x1fbad8)  # pitch singleton slot loaded at 0x173130
        u.emu_start(0x173145, 0x173230, count=5000)
        assert u.reg_read(UC_ARM_REG_PC) == 0x173230
        original = word(RUN+0x2c0)
    result = native.bs2_swing_pattern(ace, 15, swing, Offset(x, y), C.byref(native_seed))
    assert (result, native_seed.value) == (original, word(SEED)), (ace, swing, x, y, seed, decision, original, result)
    patterns.add(result)
    return decision[0]


# Find seeds for exact rolls. The observed ARM RNG result is checked below.
seeds = {}
candidate = 0
while len(seeds) < 10000:
    value = candidate
    for _ in range(2):
        value = ((value * 214013 + 2531011) & 0xffffffff) >> 1
    seeds.setdefault(value % 10000, candidate)
    candidate += 1
    assert candidate < 1000000

checks = 0
for ace in (0, 1):
    u.mem_write(BATTER, bytes(128))
    put(BATTER+0x28, ace)
    call(0xceeb4, BATTER)  # Ready
    assert call(0xceee0, BATTER) == 1
    assert call(0xceee0, BATTER) == 0 and u.mem_read(BATTER+0xe, 1)[0] == 1
    for tick in range(32):
        assert call(0xce9dc, BATTER) == native.bs2_swing_art_frame(ace, tick), (ace, tick)
        if tick < 2:
            assert call(0xcedf4, BATTER) == 1-tick
        call(0xcee0c, BATTER)
    for swing, distance in itertools.product((0, 13, 14, 15, 16), (0, 3, 4, 9, 10, 12, 13, 15, 16, 19, 20, 22, 23, 40)):
        for x, y in ((distance, 0), (0, -distance), (-distance, distance)):
            threshold, _ = compare(0xffffffff, swing, x, y)
            for roll in (threshold - 1, threshold):
                assert compare(seeds[roll], swing, x, y) == (threshold, roll)
            checks += 3
    for seed in range(1024):
        u.mem_write(PLAY+4, bytes([seed % 3, (seed // 3) % 4]))
        compare(seed, 12 + seed % 5, 0, 0)
        checks += 1
assert patterns == {-1} | {p+d for p in (0, 3, 9, 15, 18, 21) for d in range(3)}, patterns
print(f'PASS: {checks} ARM/native swings matched the contact decision, final pattern and RNG state.')
print('Covered misses and all 18 normal batted-ball patterns, including both sides of each tested contact threshold.')
print('PASS: Original Swing, IsBattable, Run and GetMotion match both batters across 64 animation ticks.')
