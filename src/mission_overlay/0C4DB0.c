#include "common.h"

#include "main/6C310.h"
#include "mission_overlay/0C4DB0.h"

// Interim BSS externs
extern struct Radar *gRadar;
extern u16 D_mission_overlay_8010BFF0[];
extern s16 D_mission_overlay_8010C080; //
// nonmatching gRadar, 0x10
// nonmatching D_mission_overlay_8010BFF0, 0x10
// nonmatching D_mission_overlay_8010C000, 0x80
// nonmatching D_mission_overlay_8010C080, 0x10 (last bss variable, has padding after it)

// Interim Data externs
extern f32 D_mission_overlay_80109FE0;
extern u8 D_mission_overlay_80109FE4[];
extern u8 gRadarPaletteNormal[0x30];
extern u8 gRadarPaletteInverted[0x30];
extern u8 gRadarPaletteAtSt[0x30];

/*
f32 D_mission_overlay_80109FE0 = 0.25f
u8 D_mission_overlay_80109FE4[][2] { 
    {0x19, 0x0C},
    {0x17, 0x0C},
    {0x12, 0x0D},
    {0x13, 0x0C},
    {0x14, 0x0D},
    {0x16, 0x0D},
    {0x18, 0x0D},
    {0x15, 0x0E},
    {0xFF, 0x00},
    {0x00, 0x00},
};
u8 gRadarPaletteNormal[0x30] = {...};
u8 gRadarPaletteInverted[0x30] = {...};
u8 gRadarPaletteAtSt[0x30] = {...};
u32 data_junk_0C4DB0 D_mission_overlay_8010A088[] = {
    0x08042880,
    0x00000000,
};
*/

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", plotRadarBlipColumn);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", plotRadarBlipRow);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", initializeRadar);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", updateCraftSelectAnimState);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", placeRadarDots);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", findClosestRadarContactAndSetSweep);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", renderRadarSweep);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", renderRadarMinimap);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", lookupCraftValueByLevelKey);

void resetCraftSelectionCounter(void) {
    D_mission_overlay_8010C080 = 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", registerObjectAndResolveDatItem);

#if 0
// Matches as written, but the return type for `getCraftRecordByIdx` is known to be wrong
// So until that gets sorted, leave this as unmatched
void getAvailableShipsForLevel(void) {
    f32 *temp_v0;
    s32 var_s0;
    struct Radar *temp_s1;

    temp_s1 = gRadar;
    temp_v0 = getCraftRecordByIdx(0);
    temp_s1->unk85C = temp_v0[0] * 0.5f;
    temp_s1->unk85E = temp_v0[2] * 0.5f;
    for (var_s0 = -0x10; var_s0 < 0x10; var_s0++) {
        plotRadarBlipColumn(temp_s1, temp_s1->unk85C + var_s0);
    }
    temp_s1->numRadarDots = 0;
    findMatchingTextureRecursive(temp_s1->textureId1, &temp_s1->material, &temp_s1->texture, 0);
    temp_s1->unkDC8 = -1U;
    temp_s1->unkDCC = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", getAvailableShipsForLevel);
#endif

void accumulateClampedFloatField(struct Radar *arg0, f32 arg1) {
    if (arg0->unkDCC < 1.0f) {
        arg0->unkDCC += arg1;
    }
}

u8 getDisplayItemStateByte(struct Radar *arg0) {
    return arg0->unkDD0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C4DB0", fake_func_800C64A4);

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodat_junk_0C4DB0[] = {
    0x93C30004,
    0x3C01801D,
    0x00220821,
};
