#include "common.h"
#include "PR/ultratypes.h"

static u32 rngSeed = 0;

static u32 padding_junk[] = {
    0x24C63560,
    0x3C02801A,
    0x2442F240
};

// These functions have `nop`s filling the delay slot after the `jr ra` instruction
// I saw this a lot with GCC 2.7.2SN, but not with GCC 2.8.1SN
// Given that the .data in this file (the rngSeed variable) is awkardly placed directly
//   after the .text section, I wonder if  this was some statically linked library?

#if 0
u32 rand(void) {
    rngSeed *= 0xA8351D63;
    return (rngSeed >> 6) % 32768;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04030", rand);
#endif

#if 0
void setRngSeed(u32 seed) {
    rngSeed = seed;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04030", setRngSeed);
#endif
