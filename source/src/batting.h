#ifndef BS2_BATTING_H
#define BS2_BATTING_H
#include "projection.h"
#include <stddef.h>
#include <stdint.h>

/* Normal human swing, empty bases, fixed ability inputs and no passive bonuses. */
enum {
    BS2_INVALID_SWING = -2, BS2_SWING_MISS = -1,
    BS2_FLY_OUT = 0, BS2_GROUND_OUT = 3, BS2_FOUL = 9,
    BS2_SINGLE = 15, BS2_DOUBLE = 18, BS2_HOME_RUN = 21
};
/* On contact, returns the original batting pattern ID, including its direction. */
int bs2_swing_pattern(int ace, int judge_frame, int swing_frame, BS2Point2 offset, uint32_t *seed);
int bs2_swing_art_frame(int ace, unsigned ticks);
int bs2_batting_offset(const unsigned char *figure, size_t size, const BS2Projection *camera,
                       const BS2Point3 *target, BS2Point2 *offset);
#endif
