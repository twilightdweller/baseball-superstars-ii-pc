#ifndef BS2_BALL_MOTION_H
#define BS2_BALL_MOTION_H

#include "batted_flight.h"

typedef struct {
    const BS2Flight *flight;
    unsigned cursor, stopped, collision_disabled;
    BS2Point3 position;
} BS2MovingBall;

/* BallMoveProcess exposes the current sample, then advances the cursor for the
   next physics query. The final update clamps the cursor and stops the ball. */
int bs2_start_ball(BS2MovingBall *ball, const BS2Flight *flight);
void bs2_move_ball(BS2MovingBall *ball);
int bs2_ball_speed(const BS2MovingBall *ball);

/* Corners are ordered in X/Z and reversed in Y, as in the original stadium. */
int bs2_ball_collision(const BS2MovingBall *ball, const BS2Point3 bounds[2],
                       int radius, int steps, int max_speed, BS2Point3 *contact);

#endif
