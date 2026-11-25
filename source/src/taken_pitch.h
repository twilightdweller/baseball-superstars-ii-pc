#ifndef BS2_TAKEN_PITCH_H
#define BS2_TAKEN_PITCH_H
#include "pitch_flow.h"
#include "projection.h"
#include <stddef.h>

/* Decoded version-7 figure and active camera, as used by IntersectStrikeZone. */
typedef struct { BS2Point2 first, second; } BS2StrikeZone;
int bs2_strike_zone(const unsigned char *figure, size_t size,
                    const BS2Projection *camera, BS2StrikeZone *zone);
BS2Point2 bs2_pitch_screen_pixel(const BS2Point3 *point, const BS2Projection *camera);
int bs2_pitch_in_zone(const BS2Point3 *sample, const BS2Projection *camera,
                      const BS2StrikeZone *zone);

/* Ordinary takes and swinging misses, normal mode, no steal, HBP, wild pitch or mission.
 * play preserves the original byte layout. Counts are kept through the result.
 * A reserved batter ends this appearance. No roster change is applied here. */
typedef struct {
    uint8_t play[0x180];
    uint8_t batting_slot, batter_reserved, reserved_slot, defense_action;
} BS2AtBat;
/* A generated UpdatePitch path has three extrapolated samples after the judge frame. */
int bs2_judge_unhit_curve(BS2AtBat *at_bat, int swung, const BS2Point3 *path, size_t samples,
                          const BS2Projection *camera, const BS2StrikeZone *zone);
int bs2_take_curve(BS2AtBat *at_bat, const BS2Point3 *path, size_t samples,
                   const BS2Projection *camera, const BS2StrikeZone *zone);
/* Returns zero before the original wait expires, then the reserved state ID.
 * Stop ticking the judge once a state has been reserved. */
int bs2_taken_pitch_next_state(BS2AtBat *at_bat, unsigned ticks,
                               BS2FlowEffect effect, void *context);
#endif
