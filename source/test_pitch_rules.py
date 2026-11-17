"""Compare recovered result/count helpers with the supplied ARM library.

No gameplay calls, arithmetic, or allocations are substituted. BoundJudge calls
the original IsFoul. Controlled object bytes are not a captured running match.
"""
import ctypes
import itertools
import random
import struct
import sys
from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC

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

n = ctypes.CDLL(sys.argv[2])
functions = {
    'bs2_pitch_judge': ('_ZN14CBBGRuleEngine10PitchJudgeEh', True, True),
    'bs2_bound_judge': ('_ZN14CBBGRuleEngine10BoundJudgeEv', True, True),
    'bs2_play_is_foul': ('_ZN12CBBGPlayData6IsFoulEv', False, True),
    'bs2_reset_sb': ('_ZN12CBBGPlayData7ResetSBEv', False, False),
    'bs2_reset_sbo': ('_ZN12CBBGPlayData8ResetSBOEv', False, False),
    'bs2_increment_strike_to_two': ('_ZN12CBBGPlayData14InccStrikeTo2SEv', False, False),
}
for name, (_, _, has_return) in functions.items():
    getattr(n, name).argtypes = [ctypes.c_void_p] + ([ctypes.c_uint8] if name == 'bs2_pitch_judge' else [])
    getattr(n, name).restype = ctypes.c_int if has_return else None

counts = dict.fromkeys(functions, 0)
results_seen = {name: set() for name in ('bs2_pitch_judge', 'bs2_bound_judge')}


def compare(name, play, argument=0):
    symbol, engine, has_return = functions[name]
    guarded = b'\xa5' * 16 + bytes(play) + b'\x5a' * 16
    native = (ctypes.c_uint8 * len(guarded)).from_buffer_copy(guarded)
    native_play = ctypes.cast(ctypes.byref(native, 16), ctypes.c_void_p)
    native_args = [native_play] + ([argument] if name == 'bs2_pitch_judge' else [])
    actual = getattr(n, name)(*native_args)
    u.mem_write(0x800000 - 16, guarded)
    engine_before = b'\xc3' * 8 + struct.pack('<I', 0x800000) + b'\xc3' * 20
    u.mem_write(0x810000, engine_before)
    for register, value in [(UC_ARM_REG_R0, 0x810000 if engine else 0x800000),
                            (UC_ARM_REG_R1, argument), (UC_ARM_REG_SP, 0x900000),
                            (UC_ARM_REG_LR, 0xa00001)]:
        u.reg_write(register, value)
    u.emu_start(symbols[symbol], 0xa00000, count=10000)
    assert u.reg_read(UC_ARM_REG_PC) == 0xa00000, (name, 'original did not return')
    expected_bytes = bytes(u.mem_read(0x800000 - 16, len(guarded)))
    assert bytes(native) == expected_bytes, (name, counts[name], 'object or guard mismatch')
    assert expected_bytes[:16] == guarded[:16] and expected_bytes[-16:] == guarded[-16:]
    assert bytes(u.mem_read(0x810000, len(engine_before))) == engine_before
    if has_return:
        expected = u.reg_read(UC_ARM_REG_R0)
        assert actual == expected, (name, counts[name], actual, expected, bytes(play).hex())
        assert expected_bytes == guarded, (name, 'unexpected input mutation')
        if name in results_seen:
            results_seen[name].add(expected)
    counts[name] += 1


rng = random.Random(20261117)
# Every byte count, including signed boundaries, and non-Boolean flags.
for count in range(256):
    play = bytearray(rng.randbytes(0x180))
    play[4] = play[5] = count
    for argument in (0, 1, 255):
        play[0x12] = 0
        play[0x10] = argument
        compare('bs2_pitch_judge', play, argument)
    for name in ('bs2_play_is_foul', 'bs2_reset_sb', 'bs2_reset_sbo', 'bs2_increment_strike_to_two'):
        compare(name, play)

# Explicit pitch decision branches, including the priority flag.
for strike, ball, argument, flag, priority in itertools.product((0, 1, 2), (0, 2, 3, 4), (0, 1), (0, 1), (0, 1)):
    play = bytearray(0x180)
    play[4], play[5], play[0x10], play[0x12] = strike, ball, flag, priority
    compare('bs2_pitch_judge', play, argument)

# BoundJudge branch coverage and signed integer boundaries with original IsFoul.
for strike, foul, bunt, flag19, flag31, flag1e, word20, word154 in itertools.product(
        (0, 2), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (-1, 0, 1), (-1, 0, 1)):
    play = bytearray(0x180)
    play[4], play[0x1c], play[0x13] = strike, foul, bunt
    play[0x19], play[0x1f], play[0x1e] = flag19, flag31, flag1e
    struct.pack_into('<i', play, 0x20, word20)
    struct.pack_into('<i', play, 0x154, word154)
    compare('bs2_bound_judge', play)
    compare('bs2_play_is_foul', play)

for _ in range(256):
    play = bytearray(rng.randbytes(0x180))
    for offset in (0x10, 0x12, 0x13, 0x19, 0x1c, 0x1e, 0x1f):
        play[offset] = rng.choice((0, 1, 2, 127, 128, 255))
    for offset in (0x20, 0x154):
        struct.pack_into('<i', play, offset, rng.choice((-2147483648, -1, 0, 1, 2147483647)))
    for name in functions:
        compare(name, play, rng.randrange(256))

assert results_seen['bs2_pitch_judge'] == {1, 2, 3, 4, 5}
assert results_seen['bs2_bound_judge'] == {0, 6, 7, 8, 10, 11, 12, 13}
for name, count in counts.items():
    print(f'PASS: {name}: {count} original ARM comparisons; object bytes, guards and defined returns match.')
print('PASS: all PitchJudge and BoundJudge result branches covered; no original gameplay calls replaced.')
