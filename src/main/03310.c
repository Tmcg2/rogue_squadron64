#include "common.h"

#include "PR/os.h"

#include "main/03310.h"

u8 rsViModeType;

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
static const u32 rodata_padding[] = {
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

INCLUDE_ASM("asm/nonmatchings/main/03310", fake_func_800027B8);
