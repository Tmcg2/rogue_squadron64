#include "common.h"
#include "common_variables.h"

#include "main/08120.h"
#include "main/1D000.h"

// Interim BSS externs
extern Mat4x3 D_menu_overlay_800CFFB0;
extern Mat4x3 D_menu_overlay_800D039C;

/* RO/Data, uncomment when ro/data matching is possible
s8 *gPostIntroCrawlCraftObjectNames[4][4] = {
    { "xwing", "xwing", "xwing", NULL },
    { "xwing", "xwing", "xwing", "xwing" },
    { "awing", "awing", "awing", "awing" },
    { "vwing", "vwing", "vwing", "vwing" },
};
s8 *gPostIntroCrawlHobFiles[4][4] = {
    { (s8 *) "pl_crafts/xwing", NULL, NULL, NULL },
    { (s8 *) "pl_crafts/xwing", NULL, NULL, NULL },
    { (s8 *) "pl_crafts/awing", NULL, NULL, NULL },
    { (s8 *) "pl_crafts/vwing", NULL, NULL, NULL },
};
*/

// Interim ro/data externs
extern char *gPostIntroCrawlCraftObjectNames[4][4];
extern char *gPostIntroCrawlHobFiles[4][4];

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78B0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78B8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78C0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78C8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78D8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/intro_crawl_handling", D_menu_overlay_800A78E8);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", runModelViewerLoop);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", initModelViewer);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", buildModelViewerTextPage);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", runModelViewerSoundDemo);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", updateModelViewerAudioSource);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", loadModelViewerModels);

#ifdef NONMATCHING_DATA
// This probably can't be matched until the ro/data for this entire file is figured out.
void selectPostCrawlCraft(u8 arg0) {
    u8 var_s0;
    char *var_a1;
    char *var_s1;

    switch (gGameSettings.vehicleId) {
    case XWING_CRAFT:
        var_s1 = "pl_crafts/xwing";
        var_a1 = "xwing";
        break;
    case YWING_CRAFT:
        var_s1 = "pl_crafts/ywing";
        var_a1 = "ywing";
        break;
    case AWING_CRAFT:
        var_s1 = "pl_crafts/awing";
        var_a1 = "awing";
        break;
    case VWING_CRAFT:
        var_s1 = "pl_crafts/vwing";
        var_a1 = "vwing";
        break;
    case SNOWSPEEDER_CRAFT:
        var_s1 = "pl_crafts/snowspeeder";
        var_a1 = "snowspeeder";
        break;
    case FALCON_CRAFT:
        var_s1 = "pl_crafts/falcon";
        var_a1 = "falcon";
        break;
    case TIEINTER_CRAFT:
        var_s1 = "imp_stuff/tieinter";
        var_a1 = "tie_inter";
        break;
    case T16_CRAFT:
        var_s1 = "pl_crafts/t16";
        var_a1 = "t16";
        break;
    case KOELSCH_CRAFT:
        var_s1 = "pl_crafts/koelsch";
        var_a1 = "koelsch";
        break;
    default:
        return;
    }
    gPostIntroCrawlCraftObjectNames[arg0][0] = var_a1;
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        if (gPostIntroCrawlHobFiles[arg0][var_s0] == NULL) {
            gPostIntroCrawlHobFiles[arg0][var_s0] = var_s1;
            break;
        }
        if (rs_strcmp(gPostIntroCrawlHobFiles[arg0][var_s0], var_s1) == 0) break;
    }
    return;
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", selectPostCrawlCraft);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", shutdownModelViewer);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", releaseMeshLinkedList);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", freeModelViewerMeshChain);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", releaseModelViewerModelAssets);

Mat4x3 *setModelViewerObjectTransform(f32 arg0) {
    initVec4TripletFromArgs(D_menu_overlay_800CFFB0, 0.625f, 0.625f, 1.0f);
    addVec3At0x24(D_menu_overlay_800CFFB0, 0.0f, arg0, 0.0f);
    mat3x3InverseInto(D_menu_overlay_800D039C, D_menu_overlay_800CFFB0);
    return D_menu_overlay_800CFFB0;
}

void runMusyXTaskWrapper(void) {
    runMusyXTaskLocked();
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", appendNodeToListTail);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/intro_crawl_handling", appendNodeToListHead);

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_junk_intro_crawl_handling[] = {
    0x000520C0,
    0x00832021,
};
