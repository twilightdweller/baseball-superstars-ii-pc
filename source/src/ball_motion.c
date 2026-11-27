#include "ball_motion.h"
#include <stdint.h>

#define Q18 262144

int bs2_start_ball(BS2MovingBall *ball, const BS2Flight *flight) {
    if (!ball || !flight || !flight->samples || !flight->count || flight->count > 150)
        return -1;
    *ball = (BS2MovingBall){0};
    ball->flight = flight;
    return bs2_flight_position(flight, 0, &ball->position);
}

void bs2_move_ball(BS2MovingBall *ball) {
    if (!ball || !ball->flight || ball->stopped) return;
    bs2_flight_position(ball->flight, ball->cursor, &ball->position);
    if (ball->cursor + 1 < ball->flight->count) ++ball->cursor;
    else ball->stopped = 1;
}

/* ARM shifts the difference by nine before squaring. It discards the low
   nine product bits, narrows to 32 bits, then shifts by nine again. */
static uint32_t squared_component(int32_t start, int32_t end) {
    int32_t delta = (int32_t)((uint32_t)end - (uint32_t)start) >> 9;
    int64_t square = (int64_t)delta * delta;
    return (uint32_t)((int32_t)(uint32_t)(square >> 9) >> 9);
}

static int32_t distance_q18(BS2Point3 a, BS2Point3 b) {
    uint32_t square = squared_component(a.x,b.x) + squared_component(a.y,b.y)
                    + squared_component(a.z,b.z);
    /* CLMath::Sqrt starts at 65535, uses unsigned division and returns
       the final Newton iterate minus one, even for an exact square. */
    uint32_t root = 65535;
    while (2u*root) {
        uint32_t correction = (root*root - square) / (2*root);
        if (!correction) break;
        root -= correction;
    }
    return (int32_t)((root-1u) << 18);
}

int bs2_ball_speed(const BS2MovingBall *ball) {
    if (!ball || !ball->flight || !ball->flight->samples || ball->cursor >= ball->flight->count) return -1;
    BS2Point3 current, next;
    bs2_flight_position(ball->flight, ball->cursor, &current);
    bs2_flight_position(ball->flight, ball->cursor+1, &next);
    int32_t length = distance_q18(current, next);
    return (int32_t)((uint32_t)length + Q18/2) >> 18;
}

static int32_t interpolate(int32_t a, int32_t b, int32_t fraction) {
    int32_t delta = (int32_t)((uint32_t)b-(uint32_t)a);
    int64_t amount = ((int64_t)delta*fraction + Q18/2) >> 18;
    return (int32_t)((uint32_t)a+(uint32_t)amount);
}

int bs2_ball_collision(const BS2MovingBall *ball, const BS2Point3 bounds[2],
                       int radius, int steps, int max_speed, BS2Point3 *contact) {
    /* CCLBallMovable::CollisionDetect, ELF 0xb8024. Interpolate across the
       previous and next sample, including both endpoints for a five-step test. */
    if (!ball || !ball->flight || !ball->flight->samples || !bounds || ball->collision_disabled || steps <= 0 ||
        ball->cursor >= ball->flight->count || bs2_ball_speed(ball) > max_speed) return -1;
    BS2Point3 prev, next;
    bs2_flight_position(ball->flight, ball->cursor ? ball->cursor-1 : 0, &prev);
    bs2_flight_position(ball->flight, ball->cursor+1, &next);
    BS2Point3 center = {interpolate(bounds[0].x,bounds[1].x,Q18/2), 0,
                        interpolate(bounds[0].z,bounds[1].z,Q18/2)};
    for (int i=0; i<steps; ++i) {
        int32_t fraction = steps == 1 ? 0 : (int32_t)(((int64_t)i*Q18)/(steps-1));
        BS2Point3 p = {interpolate(prev.x,next.x,fraction), interpolate(prev.y,next.y,fraction),
                       interpolate(prev.z,next.z,fraction)};
        if (p.x < bounds[0].x || p.x > bounds[1].x || p.z < bounds[0].z ||
            p.z > bounds[1].z || p.y < bounds[1].y || p.y > bounds[0].y) continue;
        if (distance_q18(p,center) <= (int32_t)((uint32_t)radius << 18)) {
            if (contact) *contact = p;
            return (int)ball->cursor;
        }
    }
    return -1;
}
