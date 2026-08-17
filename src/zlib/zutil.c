#include "common.h"

#include "main/04080.h"
#include "zlib/zutil.h"

void *zcalloc(void *opaque, u32 arg1, u32 arg2) {
    return rs_zcalloc(arg1, arg2);
}

void zcfree(void *arg0, void *arg1) {
    rs_zcfree(arg1);
}

INCLUDE_ASM("asm/nonmatchings/zlib/zutil", fake_func_80029D14);
