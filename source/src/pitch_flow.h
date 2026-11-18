#ifndef BS2_PITCH_FLOW_H
#define BS2_PITCH_FLOW_H
#include <stdint.h>
enum { BS2_FLOW_PROC_JUDGE = 1, BS2_FLOW_CHECK_MISSION = 2 };
typedef void (*BS2FlowEffect)(void *context, int effect);
/* Play data uses the original byte layout, at least 0x168 bytes.
 * Effects are invoked in original order. They must be supplied by the caller.
 * Returns original state ID, or -1 without writes for missing callback or an
 * out-of-range mode-7 threshold index on a path that accesses that table. */
int bs2_next_pitch_state(uint8_t *play, BS2FlowEffect effect, void *context);
int bs2_play_game_over(const uint8_t *play);
uint8_t bs2_batting_timing(uint32_t current_frame, uint32_t swing_frame);
#endif
