#include "common.h"

#include "PR/os.h"

#include "main/03290.h"
#include "main/080E0.h"

u8 rsViModeType;

u32 D_main_80037620 = 0;
u32 data_pad_03290[] = {
    0x156AFFF5,
    0x3C020001,
    0x10C00030,
};

u32 computeElapsedMillis(void) {
    u32 temp_s0_2;
    u32 temp_s0;
    u32 temp_v1;
    u64 temp_ret;

    temp_s0 = D_main_80037620;
    temp_v1 = osGetTime();
    temp_s0_2 = temp_v1 - temp_s0;
    D_main_80037620 = temp_v1;
    temp_ret = u64DivU64((u64)temp_s0_2 * 1000000000, osClockRate);
    return u64DivU64(temp_ret, 1000);
}

f32 getViModePeriod(void) {
    f32 var_fv0;

    if (rsViModeType == 1) {
        var_fv0 = 20.0f;
    } else {
        var_fv0 = 16.666666f;
    }
    return var_fv0;
}

// DO NOT DELETE ME I'M REQUIRED FOR MATCHING
const u32 rodata_pad_03290[] = {
    0x800032D4,
    0x800032F8,
};

u8 getViModeType(void) {
    return rsViModeType;
}

void setViModeType(void) {
    u32 var_v0;

    switch (osTvType) {
        case OS_TV_PAL:
            rsViModeType = 1;
            break;
        case OS_TV_NTSC:
            rsViModeType = 0;
            break;
        case OS_TV_MPAL:
            rsViModeType = 2;
            break;
        default:
            return;
    }
}

u8 getOsResetType(void) {
    return osResetType;
}

INCLUDE_ASM("asm/nonmatchings/main/03290", fake_func_800027B8);
