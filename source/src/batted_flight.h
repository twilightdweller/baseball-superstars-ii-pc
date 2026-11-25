#ifndef BS2_BATTED_FLIGHT_H
#define BS2_BATTED_FLIGHT_H

#include <stddef.h>
#include "projection.h"

typedef struct {
    const unsigned char *samples;
    unsigned count;
    unsigned untouched_foul;
} BS2Flight;

int bs2_open_flight(const unsigned char *data, size_t size, int pattern,
                    unsigned *order, BS2Flight *flight);
int bs2_flight_position(const BS2Flight *flight, unsigned tick, BS2Point3 *point);
#endif
