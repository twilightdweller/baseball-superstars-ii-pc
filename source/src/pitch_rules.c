#include "pitch_rules.h"

/* Original loads sign-extend the count bytes, regardless of host char signedness. */
static int signed_byte(uint8_t value) { return value < 128 ? value : (int)value - 256; }
static int32_t signed_word(const uint8_t *p) {
    uint32_t value = (uint32_t)p[0] | (uint32_t)p[1] << 8 |
                     (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
    return value <= INT32_MAX ? (int32_t)value : (int32_t)((int64_t)value - 4294967296LL);
}

/* CBBGRuleEngine::PitchJudge, ELF 0xbe219. */
int bs2_pitch_judge(const uint8_t *p, uint8_t argument) {
    if (p[0x12]) return 4;
    if (!argument && !p[0x10]) return signed_byte(p[5]) < 3 ? 2 : 3;
    return signed_byte(p[4]) > 1 ? 5 : 1;
}

/* CBBGPlayData::IsFoul, ELF 0xd7f7d. Preserve the raw returned flag byte. */
int bs2_play_is_foul(const uint8_t *p) {
    if (p[0x19] && signed_byte(p[4]) > 1) return 0;
    if (p[0x1f]) return 0;
    return p[0x1c];
}

/* CBBGRuleEngine::BoundJudge, ELF 0xbe35d. */
int bs2_bound_judge(const uint8_t *p) {
    if (p[0x1f]) return 13;
    if (p[0x19]) return 0;
    if (bs2_play_is_foul(p)) return signed_byte(p[4]) < 2 || !p[0x13] ? 7 : 11;
    if (signed_word(p + 0x154) < 1) {
        if (signed_word(p + 0x20) < 1) return 6;
        if (!p[0x1e]) return 8;
    } else if (!p[0x1e] || signed_word(p + 0x20) == -1) {
        return 12;
    }
    return 10;
}

/* CBBGPlayData::ResetSB, ELF 0xd7ed5. Includes original per-pitch flags. */
void bs2_reset_sb(uint8_t *p) {
    p[0x164] = 0; p[4] = 0; p[5] = 0; p[0x165] = 0; p[0x166] = 0;
    p[0x14] = 0; p[0x15] = 0; p[0x16] = 0; p[0x17] = 0; p[0x167] = 0;
}

/* CBBGPlayData::ResetSBO, ELF 0xd7f01. */
void bs2_reset_sbo(uint8_t *p) { bs2_reset_sb(p); p[6] = 0; }

/* CBBGPlayData::InccStrikeTo2S, ELF 0xd8221. */
void bs2_increment_strike_to_two(uint8_t *p) {
    if (signed_byte(p[4]) <= 1) p[4] = (uint8_t)(p[4] + 1);
}
