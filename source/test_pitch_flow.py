"""Original ARM comparisons: flow decisions, game-over predicate and batting timing.
Statistics and mission calls are explicit test doubles; their effects are not ported.
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

from unicorn import UC_HOOK_CODE
n = ctypes.CDLL(sys.argv[2])
assert struct.unpack('<6i',u.mem_read(0x1c468c,24)) == (700,1100,1500,1900,2300,99999)
CALLBACK = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_int)
n.bs2_next_pitch_state.argtypes = [ctypes.c_void_p, CALLBACK, ctypes.c_void_p]
n.bs2_play_game_over.argtypes = [ctypes.c_void_p]
n.bs2_batting_timing.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
n.bs2_batting_timing.restype = ctypes.c_uint8
native_events = []
arm_events = []
active_native = None
mutate = False
@CALLBACK
def effect(context, kind):
    native_events.append(kind)
    if mutate:
        active_native[16 + 0x60] = (active_native[16 + 0x60] + kind) & 255

def hook(u, address, size, data):
    if address in (0xc6888, 0xce07c):
        kind = 1 if address == 0xc6888 else 2
        assert u.reg_read(UC_ARM_REG_R0) == (0x820000 if kind == 1 else 0x820100)
        arm_events.append(kind)
        if mutate:
            old = u.mem_read(0x800060, 1)[0]
            u.mem_write(0x800060, bytes([(old + kind) & 255]))
        u.reg_write(UC_ARM_REG_PC, u.reg_read(UC_ARM_REG_LR))
u.hook_add(UC_HOOK_CODE, hook)

def invoke(symbol, arg0, arg1=0):
    for reg, val in [(UC_ARM_REG_R0,arg0),(UC_ARM_REG_R1,arg1),(UC_ARM_REG_SP,0x900000),(UC_ARM_REG_LR,0xa00001)]:
        u.reg_write(reg,val)
    u.emu_start(symbols[symbol],0xa00000,count=10000)
    assert u.reg_read(UC_ARM_REG_PC)==0xa00000
    return u.reg_read(UC_ARM_REG_R0)

flow_count = game_count = 0
states = set()
def compare(play, flow):
    global active_native, flow_count, game_count
    raw=b'\xa5'*16+bytes(play)+b'\x5a'*16
    active_native=(ctypes.c_uint8*len(raw)).from_buffer_copy(raw)
    ptr=ctypes.cast(ctypes.byref(active_native,16),ctypes.c_void_p)
    u.mem_write(0x7ffff0,raw)
    manager=bytearray(0x1a0)
    struct.pack_into('<I',manager,0x174,0x800000)
    struct.pack_into('<I',manager,0x178,0x820000)
    struct.pack_into('<I',manager,0x184,0x820100)
    u.mem_write(0x810000,bytes(manager))
    native_events.clear();arm_events.clear()
    if flow:
        actual=n.bs2_next_pitch_state(ptr,effect,None)
        expected=invoke('_ZN11CBBGFlowMgr21NextStateAtPitchJudgeEv',0x810000)
        assert actual==expected,(actual,expected,play.hex())
        states.add(actual);flow_count+=1
    else:
        actual=n.bs2_play_game_over(ptr)
        expected=invoke('_ZN12CBBGPlayData10IsGameOverEv',0x800000)
        assert actual==expected,(actual,expected,play.hex())
        game_count+=1
    original_bytes=bytes(u.mem_read(0x7ffff0,len(raw)))
    assert bytes(active_native)==original_bytes, (flow_count,play.hex(),[(hex(i-16),a,b) for i,(a,b) in enumerate(zip(bytes(active_native),original_bytes)) if a!=b])
    assert bytes(active_native[:16])==raw[:16] and bytes(active_native[-16:])==raw[-16:]
    assert bytes(u.mem_read(0x810000,len(manager)))==bytes(manager)
    assert native_events==arm_events,(native_events,arm_events)
    if not flow: assert bytes(active_native)==raw

# Decision branches and original signed counts, modes and result bytes.
for mode, result, outs in itertools.product((0,1,5,6,8,127,128,255),(0,1,2,3,4,5,7,13,255),(0,2,3,127,128,255)):
    play=bytearray(0x180);play[1]=mode;play[0xb]=result;play[6]=outs
    play[0x12d]=9
    compare(play,True)
# Mode 7: all recovered threshold entries, boundary scores and stateful flags.
for index, remaining, flag_a, flag_b in itertools.product(range(6),(0,1,2,255),(0,1),(0,1)):
    for score in (-32768,0,699,700,1100,1500,1900,2300,32767):
        play=bytearray(0x180);play[1]=7;play[0x12d]=9
        play[0x27]=remaining;play[0x38]=index;play[0x33]=255
        play[0x39]=9;play[0x3a]=flag_a;play[0x3b]=2
        play[0x3d]=flag_a;play[0x3e]=flag_b
        struct.pack_into('<h',play,0x34,score)
        compare(play,True)
# Predicate branch combinations and every value in each signed-byte field.
for field in (0x142,0x143,0x12f,0x12d,9,6):
    for value in range(256):
        play=bytearray(0x180);play[0x12d]=9;play[0x12f]=9
        play[0x142]=2;play[0x143]=3;play[9]=1;play[6]=3;play[field]=value
        compare(play,False)
rng=random.Random(20261118)
mutate=True
for _ in range(512):
    play=bytearray(rng.randbytes(0x180));play[0x38]=rng.randrange(6)
    compare(play,False);compare(play,True)
assert states=={14,16,24,25,26},states
# Rejected threshold indices leave object and callbacks untouched.
for index in (6,127,255):
    play=(ctypes.c_uint8*0x180)();play[1]=7;play[0x12d]=9;play[0x27]=2;play[0x38]=index
    before=bytes(play);native_events.clear()
    assert n.bs2_next_pitch_state(play,effect,None)==-1
    assert bytes(play)==before and not native_events

# Original GetBattingTiming accesses the pitch singleton and run field 0x2c4.
got=0x163e68+struct.unpack('<I',u.mem_read(0x163e90,4))[0]
slot=struct.unpack('<I',u.mem_read(got+0x298,4))[0]
u.mem_write(slot,struct.pack('<I',0x830000))
boundaries=(0,1,2,0x7fffffff,0x80000000,0xfffffffe,0xffffffff)
pairs=list(itertools.product(boundaries,boundaries))
for _ in range(512):
    swing=rng.randrange(2**32)
    for delta in (-2,-1,0,1,2): pairs.append(((swing+delta)&0xffffffff,swing))
for current,swing in pairs:
    u.mem_write(0x830090,struct.pack('<I',current));u.mem_write(0x8402c4,struct.pack('<I',swing))
    actual=n.bs2_batting_timing(current,swing)
    expected=invoke('_ZN11CBBGGameRun16GetBattingTimingEv',0x840000)
    assert actual==expected,(current,swing,actual,expected)
print(f'PASS: {flow_count} next-state comparisons: all five returned states, mode-7 writes, callback order and guards match.')
print(f'PASS: {game_count} game-over comparisons match; no predicate calls replaced.')
print(f'PASS: {len(pairs)} batting-timing comparisons match, including wrapping frame differences.')
print('Scope: statistics/mission callees are test doubles; complete match progression is not established.')
