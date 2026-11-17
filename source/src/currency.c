#include <stdint.h>
#include <stdbool.h>
#define LIMIT 999999u
#define MASK 0x1fad5349u
/* Reconstructed from CBBGOption and CGsChecksum in the supplied binary. */
uint32_t bs2_checksum(uint32_t encoded) {
    uint16_t state=0xc5e2;
    uint32_t sum=0;
    for(unsigned n=0;n<4;n++) {
        uint32_t v=((encoded>>(8*n))&255u)^(state>>8);
        state=(uint16_t)((v+state)*0xb2acu+0x8e93u);
        sum+=v;
    }
    return sum;
}
uint32_t bs2_set(uint32_t input) {
    uint32_t value=(input&0x80000000u)?0:input;
    return (value>LIMIT?LIMIT:value)^MASK;
}
uint32_t bs2_get(uint32_t encoded) { return encoded^MASK; }
uint32_t bs2_add(uint32_t encoded,int32_t delta) {
    return bs2_set(bs2_get(encoded)+(uint32_t)delta);
}
/* Proposed PC-only UI action, disabled by caller unless explicitly enabled. */
uint32_t bs2_cheat_grant(uint32_t encoded,bool enabled,uint32_t amount) {
    if(!enabled)return encoded;
    uint64_t total=(uint64_t)bs2_get(encoded)+amount;
    return bs2_set(total>LIMIT?LIMIT:(uint32_t)total);
}
