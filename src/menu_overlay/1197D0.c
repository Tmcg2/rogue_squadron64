#include "common.h"

#include "compiler/gcc/string.h"

#include "main/08120.h"
#include "menu_overlay/1197D0.h"

/*
BSS, for when matching it is possible
char D_menu_overlay_800CE6B0[0x40];
nonmatching D_menu_overlay_800CE6F0, 0x2
nonmatching D_menu_overlay_800CE6F2, 0x2
nonmatching D_menu_overlay_800CE6F4, 0xC
*/

// Interim BSS externs
extern char D_menu_overlay_800CE6B0[0x40];

/* Data Variables, uncomment when Data matching is possible
u8  D_menu_overlay_800CC850 = 0;
s32 D_menu_overlay_800CC85C = 0;
*/

// Interim `extern` definitions for Data variables. Remove these when Data matching is possible.
extern u8  D_menu_overlay_800CC850;
extern s32 D_menu_overlay_800CC85C;

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C20);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C2C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C34);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildFormatMessageGlyphBuffer);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C40);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", allocFormatTextElement);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", loadNamedTextureDescriptor);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuAlpha);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C58);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuP);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C7C);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", allocTextRenderTarget);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", tickFormatMessageWorker);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5CB4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuGRAD1);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5CD8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuGRAD2);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuGRAD1A);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5D04);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuGRAD2A);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5D40);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildLevelSelectTextTextures);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildScaledFormatTextElement);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", processAndDisposeFormatMessage);

void decrementTextTextureRefcount(void) {
    D_menu_overlay_800CC850--;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", setChildPosFromI16Pair);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", getStructField0xC);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", rasterizeFormatMessageGlyphs);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", disposeFormatMsgQueueMember);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", initFormatMessageWorker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", shutdownFormatMessageWorker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", enqueueFormatMessage);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", pollServiceMessageByte);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", initTextTextureTarget);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", updateTextOverlayLookupEntry);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", accumulateShipThrottleCharge);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", computeThrottleChargeFraction);

s32 isPlayerShipActive(void) {
    return D_menu_overlay_800CC85C != 0;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", destroyPlayerShipRecord);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", spawnProjectileObject);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", copyMorphTargetVertices);

#if 0
// Text matching, have not check if rodata works yet
// Appends "alplha" to the end of arg0, placing the combined result in D_menu_overlay_800CE6B0
char *buildPrefixedAssetName(char *arg0) {
    s32 temp_s3;
    char *temp_v0;
    u32 var_s1;

    temp_v0 = "alpha";
    rs_strcpy(D_menu_overlay_800CE6B0, arg0);
    temp_s3 = strlen(D_menu_overlay_800CE6B0);
    for (var_s1 = 0; var_s1 < strlen(temp_v0) + 1; var_s1++) {
        D_menu_overlay_800CE6B0[temp_s3 + var_s1] = temp_v0[var_s1];
    }
    return D_menu_overlay_800CE6B0;
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildPrefixedAssetName);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", spawnHudReticleAtMeshBounds);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", positionHudSpriteOffset);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", createHudSpritePair);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", layoutHudSpriteScreenRect);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", fake_func_800B47C4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5DC0);
