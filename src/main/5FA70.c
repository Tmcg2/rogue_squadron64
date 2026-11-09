#include "common.h"

#include "main/5FA70.h"

// THIS IS WRONG, THESE ARE STRUCTS OF SIZE 0x44!!
// But I want to match the BSS of this file some an array of bytes will do for now
u8 D_main_bss_80139750[4][0x44];
s8 D_main_bss_80139860;
s8 bss_pad_5FA70[3];
s8 D_main_bss_80139864[4];

INCLUDE_ASM("asm/nonmatchings/main/5FA70", steerOrientationTowardTarget);

INCLUDE_RODATA("asm/nonmatchings/main/5FA70", D_main_8003B224);

INCLUDE_ASM("asm/nonmatchings/main/5FA70", levelOrientationToReferenceAxis);

INCLUDE_RODATA("asm/nonmatchings/main/5FA70", D_main_8003B248);

INCLUDE_ASM("asm/nonmatchings/main/5FA70", emitTrailPuffAndCue);

INCLUDE_ASM("asm/nonmatchings/main/5FA70", guidedEffectNpcHandler);

void initWeaponSlotIndexTable(void) {
    s32 var_v1;
    s8 *why;

    var_v1 = 3;
    why = &D_main_bss_80139864[var_v1];
    for (; var_v1 >= 0; var_v1--) {
        *why-- = var_v1;
    }
    D_main_bss_80139860 = 4;
}

INCLUDE_RODATA("asm/nonmatchings/main/5FA70", D_main_8003B2F4);
