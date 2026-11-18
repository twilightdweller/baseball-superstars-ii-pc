#include "pitch_flow.h"
static int sb(uint8_t x) { return x < 128 ? x : (int)x - 256; }

/* CBBGPlayData::IsGameOver, ELF 0xd7f99. Original byte fields are signed. */
int bs2_play_game_over(const uint8_t *p) {
    int away = sb(p[0x142]), home = sb(p[0x143]);
    if (sb(p[0x12f]) < sb(p[0x12d])) return 0;
    if (sb(p[9]) == 1) {
        if (away != home && sb(p[6]) > 2) return 1;
        return away < home;
    }
    return away < home && sb(p[6]) > 2;
}

/* CBBGGameRun::GetBattingTiming, ELF 0x163e61; retain 32-bit wrap. */
uint8_t bs2_batting_timing(uint32_t current, uint32_t swing) {
    uint32_t delta = current - swing;
    return delta == 0 ? 100 : (delta == 1 || delta == UINT32_MAX ? 75 : 0);
}

/* CBBGFlowMgr::NextStateAtPitchJudge, ELF 0xcbfe9.
 * Six mode-7 thresholds are original words at ELF 0x1c468c. */
int bs2_next_pitch_state(uint8_t *p, BS2FlowEffect effect, void *context) {
    static const int thresholds[6] = {700,1100,1500,1900,2300,99999};
    int state, mode, game_over;
    if (!p || !effect) return -1;
    mode = sb(p[1]); game_over = bs2_play_game_over(p);
    if (!game_over && mode == 7 && p[0x27] > 1 && p[0x38] >= 6) return -1;
    if (game_over) {
        effect(context, BS2_FLOW_PROC_JUDGE); state = 25;
    } else if (mode == 7) {
        unsigned remaining = p[0x27];
        if (p[0x3a]) p[0x39] = 0;
        p[0x3a] = p[0x3b]; p[0x3b] = 0;
        if (remaining > 1) {
            unsigned score_raw = (unsigned)p[0x34] | (unsigned)p[0x35] << 8;
            int score = score_raw < 32768 ? (int)score_raw : (int)score_raw - 65536;
            p[0x27]--; p[0x33]++;
            if (thresholds[p[0x38]] > score) state = 16;
            else { p[0x38]++; state = 14; }
        } else if (p[0x3d] && !p[0x3e]) {
            p[0x3a] = 0; p[0x39] = 0; p[0x3e] = 1;
            p[0x27] = p[0x3d]; p[0x33]++; state = 14;
        } else state = 26;
    } else if (sb(p[6]) > 2) {
        effect(context, BS2_FLOW_PROC_JUDGE); state = 25;
    } else if (sb(p[0xb]) == 5 || sb(p[0xb]) == 13) {
        effect(context, BS2_FLOW_PROC_JUDGE); state = 14;
    } else if (sb(p[0xb]) == 3 || sb(p[0xb]) == 4) state = 24;
    else state = 16;
    if (mode == 5 || mode == 6) effect(context, BS2_FLOW_CHECK_MISSION);
    return state;
}
