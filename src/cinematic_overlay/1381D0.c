#include "include_asm.h"

#include "common_types.h"
#include "cinematic_overlay/1381D0.h"
#include "main/42AF0.h"
#include "main/66FB0.h"

/* BSS Variables, uncomment when BSS matching is possible

Vec3f *D_cinematic_overlay_800B1A08;
*/

// Interim `extern` definitions for BSS variables. Remove these when BSS matching is possible.
extern Vec3f *D_cinematic_overlay_800B1A08;

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A5D80);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", load_cutscene);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A6904);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", setupCutsceneLevel);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCinematicDispatchSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A70E4);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A71B8);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cutscenePopulateSlotsFromLevelLists);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A76B8);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A7C4C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cutsceneDispatchSlotsByFlag);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A89B0);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A959C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A98AC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A9ABC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800A9D70);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AA1BC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AA4F4);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", tickCutsceneActionSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AA850);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AAC88);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800ABD0C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AC574);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AC75C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", processCutsceneActions);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", computeCutsceneScreenScale);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AD690);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800ADBF8);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800ADF74);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AE518);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AE878);

u8 shouldShowCutsceneForLevelStage(u8 arg0, u8 arg1) {
    u8 ret;

    ret = (arg1 == 0);
    if (arg1 == 1) {
        ret = 1;
    }
    if (arg0 >= 0x10U) {
        ret = 0;
    }
    if (arg0 == 3) {
        if (arg1 == 2) {
            ret = 1;
        }
    }
    if ((arg0 == 0x13) && ((arg1 & 0xFF) == 2)) {
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AE98C);

Vec3f *func_cinematic_overlay_800AEA18(void) {
    return D_cinematic_overlay_800B1A08;
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cuts_0058_bubble_sort);

void func_cinematic_overlay_800AEB30(void) {
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", freeCutsceneResources);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", resetCutsceneActionSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AEBD0);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AEC48);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", tickCutsceneNpcSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AEF30);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCutsceneSlotTable);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", insertCutsceneSlot);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", lookupCutsceneIdMapping);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", destroyAllNpcsInSlotChain);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF0EC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF164);

void cinematicShutdownAudioAndAssets(void) {
    finalizeCurrentSpeechBuffer();
    teardownAnimatedMapGridLayer(); 
}

s32 bytesDiffer(u8 *arg0, u8 *arg1, u32 arg2) {
    u16 var_a3;

    for (var_a3 = 0; var_a3 < arg2; ++var_a3) {
        if (arg0[var_a3] != arg1[var_a3]) return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF2C8);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF360);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF408);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF540);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF550);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF60C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF65C);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", func_cinematic_overlay_800AF668);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", fake_func_800AF6A8);
