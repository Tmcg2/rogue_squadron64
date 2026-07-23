#include "common.h"

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateReset);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateEnd);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateInit2_);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateInit_);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflate);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateSetDictionary);

INCLUDE_ASM("asm/nonmatchings/zlib/inflate", inflateSync);

INCLUDE_RODATA("asm/nonmatchings/zlib/inflate", junk_80000AA8);
