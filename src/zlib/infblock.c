#include "common.h"

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", inflate_blocks_reset);

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", inflate_blocks_new);

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", inflate_blocks);

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", inflate_blocks_free);

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", inflate_set_dictionary);

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", fake_func_8002851C);

INCLUDE_RODATA("asm/nonmatchings/zlib/infblock", junk_80000AD8);
