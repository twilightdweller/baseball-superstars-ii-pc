#ifndef BS2_FORCE_PLAY_H
#define BS2_FORCE_PLAY_H

#include "ground_out.h"

typedef struct {
    BS2FlyOut field;
    uint8_t throw_tick, second_tick, relay_tick, clear_first_tick, provisional_tick, lead_batter;
    uint16_t query_count;
    uint32_t query_offset;
} BS2ForcePlay;

typedef struct {
    unsigned tick, next_query, possessions, outs_made, invalid;
    BS2Point3 lead, batter;
} BS2ForceDefense;

int bs2_find_force_play(const uint8_t *data, size_t size, int group, unsigned order,
                        int batter, int lead_batter, const BS2AtBat *ab, BS2ForcePlay *result);
int bs2_step_force_play(BS2AtBat *ab, BS2ForceDefense *defense, const BS2ForcePlay *play,
                        const uint8_t *data, size_t size, unsigned until);
#endif
