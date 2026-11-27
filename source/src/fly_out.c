#include "fly_out.h"
#include "pitch_rules.h"
#include <string.h>

_Static_assert(sizeof(BS2FlyOut) == 12, "fly-out resource layout");

_Static_assert(sizeof(BS2MapDraw) == 12, "minimap drawing layout");

int bs2_fly_map_frame(const uint8_t *data, size_t size, const BS2FlyOut *fly,
                      unsigned tick, const uint8_t **commands) {
    if (!data || !commands || !fly || !tick || !fly->end_tick) return -1;
    if (tick > fly->end_tick) tick = fly->end_tick;
    size_t offset = fly->map_offset;
    for (unsigned frame = 1; frame <= tick; ++frame) {
        uint16_t count;
        if (offset > size || size-offset < sizeof(count)) return -1;
        memcpy(&count, data+offset, sizeof(count));
        offset += sizeof(count);
        if (!count || count > (size-offset)/sizeof(BS2MapDraw)) return -1;
        if (frame == tick) {
            *commands = data+offset;
            return count;
        }
        offset += count*sizeof(BS2MapDraw);
    }
    return -1;
}

int bs2_find_fly_out(const uint8_t *data, size_t size, int group, unsigned order,
                     int batter, unsigned outs, BS2FlyOut *result) {
    uint32_t count;
    if (!data || !result || size < sizeof(count)) return -1;
    memcpy(&count, data, sizeof(count));
    if (count > (size-sizeof(count))/sizeof(*result)) return -1;
    size_t end = sizeof(count)+count*sizeof(*result);
    for (size_t offset = sizeof(count); offset < end; offset += sizeof(*result)) {
        BS2FlyOut fly;
        memcpy(&fly, data+offset, sizeof(fly));
        if (fly.group != group || fly.order != order ||
            fly.batter != batter || fly.starting_outs != outs) continue;
        if (fly.fielder >= 9 || !fly.catch_tick || fly.catch_tick > fly.out_tick ||
            fly.out_tick > fly.end_tick || fly.map_offset < end || fly.map_offset >= size || outs >= 3) return -1;
        *result = fly;
        return 1;
    }
    return 0;
}

int bs2_step_fly_out(BS2AtBat *ab, const BS2FlyOut *fly, unsigned tick) {
    if (!ab || !fly || ab->batting_slot >= 9 || fly->starting_outs >= 3) return -1;
    uint8_t *p = ab->play;
    if (!p[0x11] || p[0x1c] || (p[0x1f] && p[0xb] != 13) ||
        p[6] != fly->starting_outs + (p[0x1f] != 0)) return -1;
    if (tick < fly->out_tick) return 0;
    if (!p[0x1f]) {
        p[0x1e] = p[0x1f] = 1; /* CCLDefenseEnv::JudgeFlyOut(false), 0xae1dc. */
        p[0xb] = 13;
        ++p[6]; /* CCLDefenseMain::JudgeProcess, ordinary out. */
    }
    if (tick < fly->end_tick) return 0;
    return bs2_finish_field_out(ab);
}

int bs2_finish_field_out(BS2AtBat *ab) {
    if (!ab || ab->batting_slot >= 9 || ab->play[6] > 3) return -1;
    if (!ab->batter_reserved) {
        ab->batter_reserved = 1; /* EndOfDefense -> RsvNextBatter(0), 0x16cb52. */
        ab->reserved_slot = (ab->batting_slot + 1) % 9;
    }
    return ab->play[6] == 3 ? 25 : 14; /* NextStateAtDefenseEnd, empty bases. */
}

int bs2_begin_next_batter(BS2AtBat *ab) {
    if (!ab || !ab->batter_reserved || ab->reserved_slot >= 9 || ab->play[6] >= 3)
        return -1;
    bs2_reset_sb(ab->play);
    ab->batting_slot = ab->reserved_slot;
    ab->batter_reserved = ab->defense_action = 0;
    ab->play[0x0b] = ab->play[0x0c] = 0;
    ab->play[0x10] = ab->play[0x11] = ab->play[0x1c] = ab->play[0x1e] = ab->play[0x1f] = 0;
    return 0;
}
