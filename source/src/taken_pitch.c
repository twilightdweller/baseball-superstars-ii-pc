#include "taken_pitch.h"
#include "pitch_rules.h"
#include "pitch_scene.h"

static int32_t pixel(int32_t fixed) {
    /* ARM adds half a Q18 unit with 32-bit wrap, then shifts arithmetically. */
    uint32_t shifted = ((uint32_t)fixed + 131072u) >> 18;
    return shifted < 8192u ? (int32_t)shifted : (int32_t)shifted - 16384;
}

BS2Point2 bs2_pitch_screen_pixel(const BS2Point3 *point, const BS2Projection *camera) {
    BS2Point2 projected;
    bs2_project_point(&projected, point, camera);
    return (BS2Point2){pixel(projected.x), pixel(projected.y)};
}

/* xToVirtual and IntersectStrikeZone on the two supplied decoded figures. */
int bs2_strike_zone(const unsigned char *figure, size_t size,
                    const BS2Projection *camera, BS2StrikeZone *zone) {
    BS2Point3 first, second;
    if (!camera || !zone || bs2_zone_corners(figure, size, &first, &second)) return -1;
    zone->first = bs2_pitch_screen_pixel(&first, camera);
    zone->second = bs2_pitch_screen_pixel(&second, camera);
    return 0;
}

static int between(int32_t v, int32_t a, int32_t b) {
    return a <= b ? a <= v && v <= b : b <= v && v <= a;
}

int bs2_pitch_in_zone(const BS2Point3 *sample, const BS2Projection *camera,
                      const BS2StrikeZone *zone) {
    BS2Point2 p = bs2_pitch_screen_pixel(sample, camera);
    return between(p.x, zone->first.x, zone->second.x) &&
           between(p.y, zone->first.y, zone->second.y);
}

int bs2_take_curve(BS2AtBat *ab, const BS2Point3 *path, size_t samples,
                   const BS2Projection *camera, const BS2StrikeZone *zone) {
    if (!ab || !path || !camera || !zone || samples < 5 || samples > 4099 || ab->batter_reserved ||
        ab->batting_slot >= 9) return -1;
    uint8_t *p = ab->play;
    if (p[1] || p[0x24] || p[4] > 2 || p[5] > 3 || p[6] > 2 ||
        bs2_play_game_over(p)) return -1;

    int in_zone = bs2_pitch_in_zone(&path[samples - 4], camera, zone);
    p[0x10] = 0; p[0x12] = 0; p[0x18] = (uint8_t)in_zone;
    p[0x19] = 0; p[0x1a] = 0;
    int result = bs2_pitch_judge(p, (uint8_t)in_zone);
    if (result == 1) ++p[4];
    if (result == 2 || result == 3) ++p[5];
    if (result == 3 || result == 5) {
        ab->batter_reserved = 1;
        ab->reserved_slot = (uint8_t)((ab->batting_slot + 1) % 9);
        if (result == 5) ++p[6];
        else ab->defense_action = p[0x26] = 2;
    }
    p[0x0c] = (uint8_t)result; /* INIT_HANDLER_GSTATE_PITCH_JUDGE */
    p[0x0b] = (uint8_t)result; /* DoEvent(0xbba), ordinary judge state */
    return result;
}

int bs2_taken_pitch_next_state(BS2AtBat *ab, unsigned ticks, BS2FlowEffect effect, void *context) {
    if (!ab || !effect || ab->play[1]) return -1;
    int result = ab->play[0xb];
    if (result != 1 && result != 2 && result != 3 && result != 5) return -1;
    unsigned delay = result == 3 || result == 5 ? 31u : 15u;
    if (ticks < delay) return 0;
    return bs2_next_pitch_state(ab->play, effect, context);
}
