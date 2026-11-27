"""Compare native flight playback with the original movable object, including its last frame."""
import ctypes as C
from pathlib import Path
import struct
import sys
import zipfile
from extract_batted_flight import BALL, FIELD_BALL, NORMAL_GROUPS, PATTERNS, PLAY, launch_field, setup_field, stadium

class Flight(C.Structure):
    _fields_ = [('samples', C.c_void_p), ('count', C.c_uint), ('untouched_foul', C.c_uint)]

class MovingBall(C.Structure):
    _fields_ = [('flight', C.POINTER(Flight)), ('cursor', C.c_uint), ('stopped', C.c_uint),
                ('disabled', C.c_uint), ('position', C.c_int32*3)]

native = C.CDLL(sys.argv[2])
native.bs2_open_flight.argtypes = [C.c_void_p, C.c_size_t, C.c_int, C.POINTER(C.c_uint), C.POINTER(Flight)]
native.bs2_flight_position.argtypes = [C.POINTER(Flight), C.c_uint, C.c_void_p]
native.bs2_start_ball.argtypes = [C.POINTER(MovingBall), C.POINTER(Flight)]
native.bs2_move_ball.argtypes = [C.POINTER(MovingBall)]
native.bs2_move_ball.restype = None
data = Path(sys.argv[3]).read_bytes()
with zipfile.ZipFile(sys.argv[1]) as archive:
    arm = stadium(archive)
setup_field(arm)
point = (C.c_int32*3)()
paths = ticks = fouls = 0
for group in NORMAL_GROUPS:
    order = C.c_uint()
    flight = Flight()
    count = arm.word(PATTERNS+4+28*group)
    for variant in range(count):
        index = arm.call(0x95510, PATTERNS, group)
        assert native.bs2_open_flight(data, len(data), group, C.byref(order), C.byref(flight)) == 0
        # Batting and field views launch different trajectories from the same pattern.
        _, table = struct.unpack_from('<II', data, 8*group)
        seed, = struct.unpack_from('<I', data, table+16*variant+8)
        arm.put(0x2fd35c, seed)
        arm.call(0xaa910, group, index)
        assert flight.count == arm.word(BALL+0x9b0)
        ball = MovingBall()
        assert native.bs2_start_ball(C.byref(ball), C.byref(flight)) == 0
        for tick in range(flight.count+2):
            arm.call(0xb8dd0, BALL)
            assert native.bs2_flight_position(C.byref(flight), tick, point) == 0
            expected = struct.unpack('<3i', arm.cpu.mem_read(BALL+0x9c0, 12))
            assert tuple(point) == expected, (group, variant, index, tick, tuple(point), expected)
            native.bs2_move_ball(C.byref(ball))
            assert tuple(ball.position) == expected and ball.cursor == arm.word(BALL+0x9ac)
            assert ball.stopped == arm.cpu.mem_read(BALL+0x9b4, 1)[0]
            ticks += 1
        field_ticks = launch_field(arm, group, index)
        for _ in range(field_ticks):
            arm.call(0xb8dd0, FIELD_BALL)
            arm.call(0xae97c)
        original_foul = arm.cpu.mem_read(PLAY+0x1c, 1)[0]
        assert original_foul == flight.untouched_foul, (group, variant, original_foul)
        fouls += original_foul
        paths += 1
        arm.call(0x9554c, PATTERNS, group)
    assert order.value == 0
for size, group in ((191, 0), (len(data), 6), (len(data), -1), (len(data), 24)):
    assert native.bs2_open_flight(data, size, group, C.byref(order), C.byref(flight)) == -1
assert 0 < fouls < paths
print(f'PASS: {fouls} untouched fouls matched the original defense judge after stepping every field trajectory.')
print(f'PASS: {paths} original batted-ball paths, {ticks} movement ticks, all 18 groups and every variant cursor wrap.')
