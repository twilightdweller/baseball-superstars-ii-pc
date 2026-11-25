#include "batted_flight.h"
#include <stdint.h>
#include <string.h>

static uint32_t word(const unsigned char *p) {
    uint32_t value;
    memcpy(&value, p, sizeof(value));
    return value; /* Windows and the original resource are little-endian. */
}

static int fits(size_t size, uint32_t offset, uint32_t count, unsigned stride) {
    return offset <= size && count <= (size - offset) / stride;
}

int bs2_open_flight(const unsigned char *data, size_t size, int pattern,
                    unsigned *order, BS2Flight *flight) {
    if (!data || !order || !flight || size < 24*8 || pattern < 0 || pattern >= 24) return -1;
    const unsigned char *group = data + 8*pattern;
    unsigned variants = word(group), table = word(group+4);
    if (!variants || *order >= variants || !fits(size, table, variants, 16)) return -1;
    const unsigned char *variant = data + table + 16 * *order;
    unsigned count = word(variant), offset = word(variant+4);
    if (!count || count > 150 || !fits(size, offset, count, 12)) return -1;
    unsigned foul = word(variant+12);
    if (foul > 1) return -1;
    *flight = (BS2Flight){data+offset, count, foul};
    /* CCLBattingPatternMgr::increaseIndex, ELF 0x9554c. */
    *order = *order+1 == variants ? 0 : *order+1;
    return 0;
}

int bs2_flight_position(const BS2Flight *flight, unsigned tick, BS2Point3 *point) {
    if (!flight || !point || !flight->samples || !flight->count) return -1;
    if (tick >= flight->count) tick = flight->count-1;
    memcpy(point, flight->samples+12*tick, 12);
    return 0;
}
