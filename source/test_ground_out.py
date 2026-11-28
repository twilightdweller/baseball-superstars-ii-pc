"""Compare the native ground play, collision timing and lineup with the APK's full defense."""
import ctypes as C
from pathlib import Path
import struct
from functools import partial
from first_base_pitch_reference import compare_first_pitch, original_first_pitch
import sys
import zipfile

from extract_ground_outs import ORDERS, QUERY, ground_play, seed_for


class AtBat(C.Structure):
    _fields_ = [('play', C.c_uint8*0x180), ('slot', C.c_uint8), ('reserved', C.c_uint8),
                ('next_slot', C.c_uint8), ('action', C.c_uint8), ('first_base_slot', C.c_uint8), ('second_base_slot', C.c_uint8)]


class Field(C.Structure):
    _fields_ = [(name, C.c_uint8) for name in
                ('group', 'order', 'batter', 'outs', 'fielder', 'pickup', 'out', 'end')]
    _fields_.append(('offset', C.c_uint32))


class Ground(C.Structure):
    _fields_ = [('field', Field), ('provisional', C.c_uint8), ('thrown', C.c_uint8),
                ('query_count', C.c_uint16), ('query_offset', C.c_uint32)]


class Defense(C.Structure):
    _fields_ = [('next_query', C.c_uint), ('pickup', C.c_uint), ('received', C.c_uint),
                ('runner_ticks', C.c_uint), ('runner_position', C.c_int32*3)]


def batter_at_plate(outs, slot=8):
    ab = AtBat()
    ab.slot = slot
    ab.play[4:7] = (1, 2, outs)
    ab.play[0x11] = 1
    ab.play[0x12d] = 9
    return ab


build = Path(sys.argv[3])
data = (build/'ground-outs.bin').read_bytes()
flights = (build/'batted-flight.bin').read_bytes()
dll = C.CDLL(sys.argv[2])
lookup = dll.bs2_find_ground_play
lookup.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.c_uint, C.c_int, C.c_uint, C.POINTER(Ground)]
step = dll.bs2_step_ground_play
step.argtypes = [C.POINTER(AtBat), C.POINTER(Defense), C.POINTER(Ground), C.c_void_p, C.c_size_t, C.c_uint]
frame = dll.bs2_fly_map_frame
frame.argtypes = [C.c_void_p, C.c_size_t, C.POINTER(Field), C.c_uint, C.POINTER(C.c_void_p)]
advance = dll.bs2_begin_next_batter
advance.argtypes = [C.POINTER(AtBat)]
arrival = dll.bs2_runner_at_base
arrival.argtypes = [C.c_void_p]
arrivals = [0, 0]
runner_steps = 0
move = dll.bs2_move_runner_to_first
move.argtypes = [C.c_void_p, C.c_void_p, C.c_int32]
move.restype = None


def check_arrival(arm, ball):
    from extract_batted_flight import FIGURE
    first = 0x5ef000
    arm.call(0x95c7c, first, FIGURE, 10)
    base = bytes(arm.cpu.mem_read(first, 12))
    pending = None

    def enter(cpu, pc, size, context):
        nonlocal pending
        runner = arm.word(cpu.reg_read(arm.regs[0])+4)
        pending = None
        if arm.word(runner+0x7c) == 1:
            pending = arrival(bytes(cpu.mem_read(runner+0x20, 24))+base)

    def returned(cpu, pc, size, context):
        if pending is not None:
            assert pending == cpu.reg_read(arm.regs[0])
            arrivals[pending] += 1

    # MoveNext also drives defenders. Check each actual flat stride by the
    # batter-runner toward first, including plays where he beats the throw.
    from extract_fly_outs import RUNNERS
    runner = arm.word(RUNNERS)
    next_position = None
    def moving(cpu, pc, size, context):
        nonlocal next_position
        next_position = None
        if cpu.reg_read(arm.regs[0]) != runner or bytes(cpu.mem_read(runner+0x2c, 12)) != base:
            return
        assert all(arm.word(runner+i) == 0 for i in (0x18, 0x24, 0x30, 0x40, 0x44))
        pos = C.create_string_buffer(bytes(cpu.mem_read(runner+0x20, 12)))
        move(pos, base, arm.word(runner+0x3c))
        next_position = pos.raw[:12]

    def moved(cpu, pc, size, context):
        global runner_steps
        if next_position is not None:
            assert next_position == cpu.mem_read(runner+0x20, 12)
            runner_steps += 1

    arm.hook(0xcf264, moving)
    arm.hook(0xcf2be, moved)
    arm.hook(0x98bc4, enter)
    arm.hook(0x98bdc, returned)


cases = safe = ticks = attempts = 0
first_pitches = set()
scene = (Path(__file__).parent/'figure-assets'/'bb2011_480x320.bin').read_bytes()
with zipfile.ZipFile(sys.argv[1]) as archive:
    for group in (3, 4, 5):
        for order in ORDERS:
            for batter in (0, 1):
                for outs in range(3):
                    seed = seed_for(flights, group, order)
                    double_play = (group, order, batter, outs) == (4, 0, 1, 0)
                    slot = 0 if outs == 1 or double_play else 8
                    followup = {}
                    original, states = ground_play(archive, group, order, batter, outs, seed, slot=slot, count=(1, 2),
                        observe=check_arrival, after_defense=partial(original_first_pitch, outside=outs == 1, result=followup,
                            next_ground_seed=seed_for(flights, 3, 0) if double_play else None))
                    g = Ground()
                    found = lookup(data, len(data), group, order, batter, outs, C.byref(g))
                    assert found == int(original is not None), (group, order, batter, outs, found)
                    assert found == 1
                    was_safe = bool(followup)
                    safe += was_safe
                    fields, provisional, thrown, queries, run, maps, positions, occupants = original
                    f = g.field
                    assert bytes(f)[:8] == bytes(fields) and (g.provisional, g.thrown) == (provisional, thrown)
                    assert g.query_count*QUERY.size == len(queries)
                    assert data[g.query_offset:g.query_offset+len(queries)] == queries
                    assert data[f.offset-len(run):f.offset] == run
                    defense, ab = Defense(), batter_at_plate(outs, slot)
                    head = 0
                    for tick, expected in enumerate(states, 1):
                        state = step(C.byref(ab), C.byref(defense), C.byref(g), data, len(data), tick)
                        actual = tuple(ab.play[i] for i in (6, 11, 0x1e, 0x1f))
                        assert actual == expected, (group, order, batter, outs, tick, actual, expected)
                        assert bytes(defense.runner_position) == positions[min(tick, f.out-1)-1]
                        assert ab.first_base_slot == ((slot+1) if occupants[tick-1] else 0)
                        assert defense.pickup == (f.pickup if tick >= f.pickup else 0)
                        assert defense.received == (f.out if tick >= f.out else 0)
                        assert state == ((25 if outs == 2 and not was_safe else 14) if tick == f.end else 0)
                        assert ab.play[4:6] == [1, 2] and ab.reserved == (tick == f.end)
                        ops = C.c_void_p()
                        n, = struct.unpack_from('<H', maps, head)
                        assert frame(data, len(data), C.byref(f), tick, C.byref(ops)) == n
                        assert C.string_at(ops, 12*n) == maps[head+2:head+2+12*n]
                        head += 2+12*n
                    assert head == len(maps) and ab.next_slot == (slot+1)%9 and ab.play[0x142:0x144] == [0, 0]
                    assert step(C.byref(ab), C.byref(defense), C.byref(g), data, len(data), f.end+1) == state
                    final_outs = outs+int(not was_safe)
                    assert ab.play[6] == final_outs
                    assert advance(C.byref(ab)) == (-1 if final_outs == 3 else 0)
                    if final_outs < 3:
                        assert ab.slot == (slot+1)%9 and ab.play[4:7] == [0, 0, final_outs] and ab.play[0x1e] == 0
                    if was_safe:
                        assert ab.first_base_slot == slot+1
                        first_pitches.add(compare_first_pitch(dll, ab, scene, followup))
                        assert ab.first_base_slot == slot+1
                        # An empty-base field record cannot be started while that runner is on.
                        ab.play[0x11] = 1
                        assert step(C.byref(ab), C.byref(Defense()), C.byref(g), data, len(data), 1) == -1
                    # A delayed paint can jump over the pickup and throw. The same queries must run.
                    skipped, fresh = Defense(), batter_at_plate(outs)
                    assert step(C.byref(fresh), C.byref(skipped), C.byref(g), data, len(data), f.end) == state
                    # Remove the first baseman's reach. A recorded out tick alone must never add an out.
                    broken = bytearray(data)
                    for j in range(g.query_count):
                        pos = g.query_offset+j*QUERY.size
                        if broken[pos+1] == 1:
                            broken[pos+2] = 1
                    missed, fresh = Defense(), batter_at_plate(outs)
                    assert step(C.byref(fresh), C.byref(missed), C.byref(g), bytes(broken), len(broken), f.end) == -1
                    assert missed.pickup == f.pickup and not missed.received and fresh.play[6] == outs
                    # Reverse the race while leaving the reference ending and minimap unchanged.
                    beaten = bytearray(data)
                    struct.pack_into('<i', beaten, f.offset-4, 1 if was_safe else 500)
                    arrived, fresh = Defense(), batter_at_plate(outs)
                    assert step(C.byref(fresh), C.byref(arrived), C.byref(g), bytes(beaten), len(beaten), f.end) == -1
                    assert arrived.received == f.out and fresh.play[6] == outs
                    attempts += g.query_count
                    cases += 1
                    ticks += len(states)

assert first_pitches == {1, 2}, first_pitches
assert runner_steps and all(arrivals), arrivals
assert cases == struct.unpack_from('<I', data, 4)[0] and cases and safe
assert lookup(data, 5, 3, 0, 1, 0, C.byref(g)) == -1
assert lookup(data, len(data), 3, 99, 1, 0, C.byref(g)) == 0
print(f'PASS: {cases-safe} ground outs and {safe} safe at first, {attempts} native fielder queries, '
      f'{ticks} original scoreboard, base occupancy and minimap frames. '
      f'All {safe} safe plays retained the runner through the next batter and first pitch. '
      f'{runner_steps} strides and {sum(arrivals)} arrival checks matched ({arrivals[1]} at first).')
