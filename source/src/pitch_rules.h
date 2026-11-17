#ifndef BS2_PITCH_RULES_H
#define BS2_PITCH_RULES_H
#include <stdint.h>
/* ARM CBBGPlayData byte layout, not a native-pointer C++ object.
 * Callers supply at least 0x168 bytes. Result numbers retain the original ABI;
 * these helpers do not implement the match event handler or advance an at-bat. */
int bs2_pitch_judge(const uint8_t *play, uint8_t argument);
int bs2_play_is_foul(const uint8_t *play);
int bs2_bound_judge(const uint8_t *play);
void bs2_reset_sb(uint8_t *play);
void bs2_reset_sbo(uint8_t *play);
void bs2_increment_strike_to_two(uint8_t *play);
#endif
