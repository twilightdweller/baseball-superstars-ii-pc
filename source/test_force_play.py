"""Compare a native two-runner force play tick by tick with the APK."""
import ctypes as C
from pathlib import Path
import struct
import sys
import zipfile

from extract_force_play import QUERY, force_play


class AtBat(C.Structure):
    _fields_ = [('play', C.c_uint8*0x180), ('slot', C.c_uint8), ('reserved', C.c_uint8),
                ('next_slot', C.c_uint8), ('action', C.c_uint8), ('first', C.c_uint8), ('second', C.c_uint8)]


class Field(C.Structure):
    _fields_ = [(name, C.c_uint8) for name in
                ('group', 'order', 'batter', 'outs', 'fielder', 'pickup', 'out', 'end')]
    _fields_.append(('offset', C.c_uint32))


class Force(C.Structure):
    _fields_ = [('field', Field), *[(name, C.c_uint8) for name in
                ('throw', 'second', 'relay', 'clear', 'provisional', 'lead_batter')],
                ('query_count', C.c_uint16), ('query_offset', C.c_uint32)]


class Defense(C.Structure):
    _fields_ = [(name, C.c_uint) for name in ('tick', 'next_query', 'holds', 'outs_made', 'invalid')]
    _fields_.extend([('lead', C.c_int32*3), ('batter', C.c_int32*3)])


build = Path(sys.argv[3])
dll = C.CDLL(sys.argv[2])
data = (build/'double-plays.bin').read_bytes()
flights = (build/'batted-flight.bin').read_bytes()
lookup = dll.bs2_find_force_play
lookup.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_uint, C.c_int, C.c_int, C.POINTER(AtBat), C.POINTER(Force)]
step = dll.bs2_step_force_play
step.argtypes = [C.POINTER(AtBat), C.POINTER(Defense), C.POINTER(Force), C.c_void_p, C.c_size_t, C.c_uint]
advance = dll.bs2_begin_next_batter
advance.argtypes = [C.POINTER(AtBat)]
frame = dll.bs2_fly_map_frame
frame.argtypes = [C.c_void_p, C.c_size_t, C.POINTER(Field), C.c_uint, C.POINTER(C.c_void_p)]


def appearance(slot, outs, count):
    ab = AtBat()
    ab.first, ab.slot = slot+1, (slot+1)%9
    ab.play[4:7] = (*count, outs)
    ab.play[0x11] = 1
    return ab


cases = ticks = 0
with zipfile.ZipFile(sys.argv[1]) as archive:
    for outs in range(3):
        for slot, previous, count, prev_call in ((0, (4, 0), (0, 0), 0), (6, (4, 2), (2, 3), 2)):
            fields, timing, queries, runs, maps, states, paths = force_play(archive, flights, outs, slot,
                                                                           previous, count, prev_call)
            relay = outs < 2
            ab, defense, p = appearance(slot, outs, count), Defense(), Force()
            assert lookup(data, len(data), 3, 0, 0, 1, C.byref(ab), C.byref(p)) == 1
            f = p.field
            assert bytes(f)[:8] == bytes(fields) and bytes(p)[12:18] == bytes(timing)
            assert data[p.query_offset:f.offset] == queries+runs
            head = 0
            for t, (score, first, second) in enumerate(states, 1):
                state = step(C.byref(ab), C.byref(defense), C.byref(p), data, len(data), t)
                assert state == ((25 if outs else 14) if t == f.end else 0), (outs, t, state)
                assert tuple(ab.play[i] for i in (4, 5, 6, 11, 0x1e, 0x1f)) == score
                assert ab.first == (slot+1 if first else 0) and ab.reserved == (t == f.end)
                assert ab.second == (slot+1 if second else 0)
                assert bytes(defense.lead) == paths[0][min(t,len(paths[0]))-1]
                assert bytes(defense.batter) == paths[1][min(t,f.out-1)-1]
                assert defense.holds == sum(t >= k for k in (f.pickup, p.second, f.out) if k)
                n, = struct.unpack_from('<H', maps, head)
                drawing = C.c_void_p()
                assert frame(data, len(data), C.byref(f), t, C.byref(drawing)) == n
                assert C.string_at(drawing, n*12) == maps[head+2:head+2+n*12]
                head += 2+n*12
            assert head == len(maps) and not ab.first and ab.play[0x142:0x144] == [0,0]
            assert step(C.byref(ab), C.byref(defense), C.byref(p), data, len(data), 999) == state
            assert ab.play[6] == min(3,outs+2) and ab.next_slot == (slot+2)%9
            assert advance(C.byref(ab)) == (-1 if outs else 0)
            if not outs:
                assert ab.slot == (slot+2)%9 and list(ab.play[4:7]) == [0,0,2]
            ab, d = appearance(slot, outs, count), Defense()
            assert step(C.byref(ab), C.byref(d), C.byref(p), data, len(data), 999) == state
            for stage in range(3 if relay else 2):
                # Suppress the chosen fielder's collision. Only earlier outs may stand.
                altered = bytearray(data)
                for j in range(p.query_count):
                    pos = p.query_offset+j*QUERY.size
                    if altered[pos+1] == stage:
                        altered[pos+2] = 1
                ab, d = appearance(slot, outs, count), Defense()
                assert step(C.byref(ab), C.byref(d), C.byref(p), bytes(altered), len(altered), f.end) == -1
                assert ab.play[6] == outs + int(stage == 2)
            for which in (0, 1):
                altered = bytearray(data)
                struct.pack_into('<i', altered, f.offset-80+40*which+36, 500)
                ab, d = appearance(slot, outs, count), Defense()
                assert step(C.byref(ab), C.byref(d), C.byref(p), bytes(altered), len(altered), f.end) == -1
                assert ab.play[6] == outs+(which if relay else 0)
                assert step(C.byref(ab), C.byref(d), C.byref(p), bytes(altered), len(altered), f.end+1) == -1
            cases += 1
            ticks += len(states)

ab = appearance(0, 0, (0,0))
for group, order, batter, lead, outs, first in ((3,0,0,1,3,1),(3,0,1,0,0,1),(3,1,0,1,0,1),
                                                (4,0,0,1,0,1),(3,0,0,1,0,0),(3,0,0,1,0,5)):
    ab.play[6], ab.first = outs, first
    assert lookup(data, len(data), group, order, batter, lead, C.byref(ab), C.byref(p)) == 0
print(f'PASS: {cases} original occupied-base grounders and {ticks} native frames. Both runner paths, possessions, '
      'force decisions, base clearance, minimap, lineup reservation and third-out transition matched.')
