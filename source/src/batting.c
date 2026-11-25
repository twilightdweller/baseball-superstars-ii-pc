#include "batting.h"
#include "taken_pitch.h"
#include "pitch_scene.h"

/* bb_rand(0,limit), ELF 0xd4f6c. Arithmetic wraps before the logical shift. */
static unsigned random_below(uint32_t *seed, unsigned limit) {
    *seed = (*seed * 214013u + 2531011u) >> 1;
    return *seed % limit;
}

/* DoEvent(0x6aa), ELF 0x17315a. The direction roll uses swing tick + 1. */
static int direction(int ace, int delta, uint32_t *seed) {
    int center = 50, left = 25;
    if (delta != 0) {
        int adjacent = delta == -1 || delta == 1;
        int favors_left = (delta < 0) == (ace == 1);
        center = adjacent ? 40 : 30;
        left = favors_left ? (adjacent ? 45 : 70) : (adjacent ? 15 : 0);
    }
    int roll = (int)random_below(seed, 100);
    if (roll < center) return 0;
    return roll < center + left ? 1 : 2;
}

/* BattingProcess, normal swing with fixed matchup inputs. Both axes use the same inclusive bands. */
int bs2_swing_pattern(int ace, int judge_frame, int swing_frame, BS2Point2 offset, uint32_t *seed) {
    if (!seed || (ace != 0 && ace != 1) || judge_frame < 0 || judge_frame >= 4096 ||
        swing_frame < 0 || swing_frame > judge_frame + 1 ||
        offset.x < -40 || offset.x > 40 || offset.y < -40 || offset.y > 40) return BS2_INVALID_SWING;
    int timing = bs2_batting_timing((unsigned)judge_frame, (unsigned)swing_frame);
    int x = offset.x < 0 ? -offset.x : offset.x;
    int y = offset.y < 0 ? -offset.y : offset.y;
    int distance = x > y ? x : y;
    static const int edges[] = {3, 9, 12, 15, 19, 22};
    static const int location[] = {10000, 9500, 9000, 8500, 6000, 3000, 0};
    unsigned band = 0;
    while (band < 6 && distance > edges[band]) ++band;

    /* Base effective abilities from the ace roster rows for this matchup.
       Level data supplies the 80% pitcher weight and the 500 contact coefficient. */
    int batting = ace == 0 ? 750 : 800;
    int ability = batting - 650 * 80 / 100;
    int location_rate = location[band] * (300 - 80) / 200;
    int threshold = (timing * location_rate / 10000) * (1200 + 500 * ability / 1000) / 10;
    threshold += 1000;
    if (threshold > 9990) threshold = 9990;
    random_below(seed, 100); /* BattingProcess consumes this roll before testing normal contact. */
    if ((int)random_below(seed, 10000) >= threshold) return BS2_SWING_MISS;

    /* Integer factors after applying the level and player data for this matchup.
       0xcb17a splits successful contact between hits and foul/fly/ground patterns. */
    static const int hit_penalty[] = {0, 100, 110, 125, 160, 200, 300};
    static const int power_penalty[] = {0, 70, 80, 90, 150, 270, 470};
    int hit = 1000 + (timing - 27) * ((ace ? 928 : 933) - hit_penalty[band]) / 10;
    int power = (timing - 27) * ((ace ? 106 : 186) - power_penalty[band]) / 10;
    int pattern;
    if ((int)random_below(seed, 10000) >= hit) {
        int roll = (int)random_below(seed, 10000);
        if (roll < 3000) pattern = BS2_FOUL;
        else pattern = roll < 6500 ? BS2_FLY_OUT : BS2_GROUND_OUT;
    } else if ((int)random_below(seed, 10000) < power) {
        pattern = BS2_HOME_RUN;
    } else {
        int double_rate = power * 120 / ((10000 - power) / 100);
        pattern = (int)random_below(seed, 10000) < double_rate ? BS2_DOUBLE : BS2_SINGLE;
    }
    return pattern + direction(ace, swing_frame + 1 - judge_frame, seed);
}

/* GetMotion / IncMotin for a normal swing, indexed by ticks since Swing. */
int bs2_swing_art_frame(int ace, unsigned ticks) {
    unsigned last = ace == 0 ? 8u : 9u;
    if (ace != 0 && ace != 1) return -1;
    return (ace == 0 ? 14 : 12) + (int)(ticks > last ? last : ticks);
}

static int clamp_offset(int value) {
    return value < -40 ? -40 : value > 40 ? 40 : value;
}

int bs2_batting_offset(const unsigned char *figure, size_t size, const BS2Projection *camera,
                       const BS2Point3 *target, BS2Point2 *offset) {
    BS2Point3 center;
    if (!target || !offset || !camera || bs2_batting_center(figure, size, &center)) return -1;
    BS2Point2 plate = bs2_pitch_screen_pixel(&center, camera);
    BS2Point2 pitch = bs2_pitch_screen_pixel(target, camera);
    *offset = (BS2Point2){clamp_offset(pitch.x - plate.x), clamp_offset(pitch.y - plate.y)};
    return 0;
}
