#ifndef BS2_GROUND_OUT_H
#define BS2_GROUND_OUT_H

#include "fly_out.h"

typedef struct {
    BS2FlyOut field;
    uint8_t provisional_tick, throw_tick;
    uint16_t query_count;
    uint32_t query_offset;
} BS2GroundPlay;

typedef struct {
    unsigned next_query, pickup_tick, received_tick, runner_ticks;
    BS2Point3 runner_position;
} BS2GroundDefense;

/* Integer stadium coordinates at the reach check in CCLRunnerAIMain::IsArrive. */
typedef struct {
    BS2Point3 position, destination, base;
} BS2RunnerArrival;

void bs2_move_runner_to_first(BS2Point3 *position, const BS2Point3 *destination, int32_t speed);
int bs2_runner_at_base(const BS2RunnerArrival *runner);
int bs2_find_ground_play(const uint8_t *data, size_t size, int group, unsigned order,
                        int batter, unsigned outs, BS2GroundPlay *result);
int bs2_step_ground_play(BS2AtBat *ab, BS2GroundDefense *defense, const BS2GroundPlay *ground,
                        const uint8_t *data, size_t size, unsigned tick);
#endif
