"""Compare native fielding playback and plate-appearance transitions with APK execution."""
import ctypes as C
from pathlib import Path
import struct
import sys
import zipfile

from extract_fly_outs import ORDERS, play, seed_for


class AtBat(C.Structure):
    _fields_ = [('play', C.c_uint8*0x180), ('slot', C.c_uint8), ('reserved', C.c_uint8),
                ('next_slot', C.c_uint8), ('action', C.c_uint8)]


class Fly(C.Structure):
    _fields_ = [(name, C.c_uint8) for name in
                ('group', 'order', 'batter', 'outs', 'fielder', 'caught', 'out', 'end')]
    _fields_.append(('offset', C.c_uint32))


build = Path(sys.argv[3])
data = (build/'fly-outs.bin').read_bytes()
flights = (build/'batted-flight.bin').read_bytes()
dll = C.CDLL(sys.argv[2])
lookup = dll.bs2_find_fly_out
lookup.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_uint, C.c_int, C.c_uint, C.POINTER(Fly)]
step = dll.bs2_step_fly_out
step.argtypes = [C.POINTER(AtBat), C.POINTER(Fly), C.c_uint]
advance = dll.bs2_begin_next_batter
advance.argtypes = [C.POINTER(AtBat)]
frame = dll.bs2_fly_map_frame
frame.argtypes = [C.c_void_p, C.c_size_t, C.POINTER(Fly), C.c_uint, C.POINTER(C.c_void_p)]

cases = ticks = missed = 0
with zipfile.ZipFile(sys.argv[1]) as archive:
    for group in range(3):
        for order in ORDERS:
            seed = seed_for(flights, group, order)
            for batter in (0, 1):
                for outs in range(3):
                    # Exercise a mixed count and wrap the last lineup slot. Extraction starts at 0-0 in slot zero.
                    original = play(archive, group, order, batter, outs, seed, slot=8, capture=True, count=(1, 2))
                    fly = Fly()
                    found = lookup(data, len(data), group, order, batter, outs, C.byref(fly))
                    assert found == int(original is not None), (group, order, batter, outs, found)
                    if not found:
                        missed += 1
                        continue
                    record, map_bytes = original
                    assert bytes(fly)[:8] == bytes(record)
                    ab = AtBat()
                    ab.slot = 8
                    ab.play[4:7] = (1, 2, outs)
                    ab.play[0x11] = 1
                    ab.play[0x12d] = 9
                    head = 0
                    for tick in range(1, fly.end+1):
                        calls, = struct.unpack_from('<H', map_bytes, head)
                        commands = C.c_void_p()
                        assert frame(data, len(data), C.byref(fly), tick, C.byref(commands)) == calls
                        assert C.string_at(commands, calls*12) == map_bytes[head+2:head+2+calls*12]
                        head += 2 + calls*12
                        state = step(C.byref(ab), C.byref(fly), tick)
                        assert ab.play[6] == outs + (tick >= fly.out)
                        assert ab.play[0xb] == (13 if tick >= fly.out else 0)
                        assert ab.play[4:6] == [1, 2] and ab.reserved == (tick == fly.end)
                        assert state == ((25 if outs == 2 else 14) if tick == fly.end else 0)
                        ticks += 1
                    assert len(map_bytes) == head
                    assert frame(data, fly.offset+1, C.byref(fly), 1, C.byref(commands)) == -1
                    assert step(C.byref(ab), C.byref(fly), fly.end+3) == state and ab.play[6] == outs+1
                    assert ab.next_slot == 0 and ab.play[0x142:0x144] == [0, 0]
                    if outs == 2:
                        assert advance(C.byref(ab)) == -1 and ab.play[6] == 3
                    else:
                        assert advance(C.byref(ab)) == 0
                        assert ab.slot == 0 and not ab.reserved and ab.play[4:7] == [0, 0, outs+1]
                    cases += 1

assert cases == struct.unpack_from('<I', data)[0] and cases and missed
assert lookup(data, 3, 0, 0, 0, 0, C.byref(fly)) == -1
assert lookup(data, len(data), 0, 99, 0, 0, C.byref(fly)) == 0
print(f'PASS: {cases} confirmed fly outs, {ticks} native map frames and out-count checks, '
      f'{missed} cases without an ordinary fly out. Both batters, lineup wrap and third outs matched.')
