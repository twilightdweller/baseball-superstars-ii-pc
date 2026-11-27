"""Compare live native ball state and defender collision queries with the supplied APK."""
import ctypes as C
import sys
import zipfile
from pathlib import Path

from unicorn.arm_const import UC_ARM_REG_SP

from extract_ground_outs import ground_play
from extract_fly_outs import ORDERS, play, seed_for
from extract_batted_flight import FIELD_BALL, launch_field, setup_field, stadium


class Point(C.Structure):
    _fields_ = [(name, C.c_int32) for name in ('x', 'y', 'z')]


class Flight(C.Structure):
    _fields_ = [('samples', C.c_void_p), ('count', C.c_uint), ('foul', C.c_uint)]


class Ball(C.Structure):
    _fields_ = [('flight', C.POINTER(Flight)), ('cursor', C.c_uint), ('stopped', C.c_uint),
                ('collision_disabled', C.c_uint), ('position', Point)]


dll = C.CDLL(sys.argv[2])
dll.bs2_start_ball.argtypes = [C.POINTER(Ball), C.POINTER(Flight)]
dll.bs2_move_ball.argtypes = [C.POINTER(Ball)]
dll.bs2_move_ball.restype = None
dll.bs2_ball_speed.argtypes = [C.POINTER(Ball)]
dll.bs2_ball_collision.argtypes = [C.POINTER(Ball), C.POINTER(Point), C.c_int, C.c_int,
                                   C.c_int, C.POINTER(Point)]
flights = Path(sys.argv[3]).read_bytes()
stats = dict(queries=0, hits=0, rejected=0, ticks=0)


def snapshot(arm, address):
    count = arm.word(address+0x750)
    assert count == arm.word(address+0x9b0) and 0 < count <= 150
    samples = C.create_string_buffer(bytes(arm.cpu.mem_read(address+0x48, 12*count)))
    # ctypes keeps the sample buffer alive through the Flight's pointer.
    return Flight(C.cast(samples, C.c_void_p), count, 0)


def observe(arm, address):
    pending = {}
    def enter(cpu, pc, size, context):
        obj, box, radius, steps = (cpu.reg_read(r) for r in arm.regs)
        assert obj == address
        sp = cpu.reg_read(UC_ARM_REG_SP)
        max_speed, dest = arm.word(sp), arm.word(sp+4)
        flight = snapshot(arm, obj)
        cursor = arm.word(obj+0x9ac)
        stopped = arm.cpu.mem_read(obj+0x9b4, 1)[0]
        native = Ball(C.pointer(flight), cursor, stopped, arm.cpu.mem_read(obj+0x9cc, 1)[0], Point())
        bounds = (Point*2).from_buffer_copy(arm.cpu.mem_read(box, 24))
        before = bytes(arm.cpu.mem_read(dest, 12))
        point = Point.from_buffer_copy(before)
        result = dll.bs2_ball_collision(C.byref(native), bounds, radius, steps, max_speed, C.byref(point))
        pending.update(result=result, point=bytes(point), dest=dest, cursor=cursor)
    def returned(cpu, pc, size, context):
        expected = C.c_int32(cpu.reg_read(arm.regs[0])).value
        assert pending['result'] == expected, (pending, expected)
        assert pending['point'] == arm.cpu.mem_read(pending['dest'], 12)
        stats['queries'] += 1
        stats['hits' if expected >= 0 else 'rejected'] += 1
    arm.hook(0xb8024, enter)
    arm.hook(0xa1c1a, returned)


with zipfile.ZipFile(sys.argv[1]) as archive:
    arm = stadium(archive)
    setup_field(arm)
    for group in (0, 1, 2, 3, 4, 5, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23):
        count = launch_field(arm, group, 0)
        flight = snapshot(arm, FIELD_BALL)
        ball = Ball()
        assert dll.bs2_start_ball(C.byref(ball), C.byref(flight)) == 0
        for tick in range(count+3):
            assert dll.bs2_ball_speed(C.byref(ball)) == C.c_int32(arm.call(0xb7fcc, FIELD_BALL, ball.cursor)).value
            arm.call(0xb8dd0, FIELD_BALL)
            dll.bs2_move_ball(C.byref(ball))
            assert bytes(ball.position) == arm.cpu.mem_read(FIELD_BALL+0x9c0, 12)
            assert ball.cursor == arm.word(FIELD_BALL+0x9ac)
            assert ball.stopped == arm.cpu.mem_read(FIELD_BALL+0x9b4, 1)[0]
            stats['ticks'] += 1
    for group in range(3):
        for order in ORDERS:
            play(archive, group, order, 1, 0, seed_for(flights, group, order), observe=observe)

    for group in (3, 4, 5):
        for order in ORDERS:
            ground_play(archive, group, order, 1, 0, seed_for(flights, group, order), observe=observe)

assert stats['hits'] and stats['rejected']
print(f"PASS: {stats['ticks']} live field-ball ticks and speed queries. "
      f"{stats['queries']} original defender collision queries matched, "
      f"including {stats['hits']} contacts with identical Q18 interception points.")
