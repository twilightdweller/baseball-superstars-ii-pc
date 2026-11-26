#ifndef BS2_FLY_OUT_H
#define BS2_FLY_OUT_H

#include "taken_pitch.h"

/* Field updates are numbered from one. Only recorded empty-base matchups have a result. */
typedef struct {
    uint8_t group, order, batter, starting_outs;
    uint8_t fielder, catch_tick, out_tick, end_tick;
    uint32_t map_offset;
} BS2FlyOut;

typedef struct {
    uint8_t shape, reserved;
    int16_t x, y, width, height;
    uint16_t rgb565;
} BS2MapDraw;

int bs2_fly_map_frame(const uint8_t *data, size_t size, const BS2FlyOut *fly,
                      unsigned tick, const uint8_t **commands);
int bs2_find_fly_out(const uint8_t *data, size_t size, int group, unsigned order,
                     int batter, unsigned outs, BS2FlyOut *result);
int bs2_step_fly_out(BS2AtBat *at_bat, const BS2FlyOut *fly, unsigned tick);
int bs2_begin_next_batter(BS2AtBat *at_bat);

#endif
