#include "common.h"
#include "common_types.h"

#include "PR/os.h"
#include "compiler/gcc/string.h"

#include "cheat_codes.h"
#include "dat.h"
#include "game_settings.h"
#include "levels.h"

#include "main/bss_80130BD0.h"
#include "main/bss_80139010.h"
#include "main/02420.h"
#include "main/08120.h"
#include "main/08510.h"
#include "main/192E0.h"
#include "main/1D000.h"
#include "main/3F160.h"
#include "main/40F10.h"
#include "main/42AF0.h"
#include "main/48A50.h"
#include "main/66FB0.h"
#include "main/79E80.h"
#include "cinematic_overlay/1381D0.h"

struct cutsceneIdMapEntry {
    u16 unk0;
    u16 unk2;
};

/* Data Variable, uncomment when Data matching is possible
char *cutsceneTypeStrings[] = {
    "intro",
    "extro",
    "special"
};
struct cutsceneIdMapEntry gCutsceneIdMappingTable[] = {...};
UNIDENTIFIED_TYPE *D_cinematic_overlay_800B0934 = NULL;
*/

// Interim `extern` definitions for Data variable. Remove these when Data is matchable
extern char *cutsceneTypeStrings[];
extern struct cutsceneIdMapEntry gCutsceneIdMappingTable[];
extern UNIDENTIFIED_TYPE *D_cinematic_overlay_800B0934;

/* BSS Variables, uncomment when BSS matching is possible

struct D_cinematic_overlay_800B0D00_type D_cinematic_overlay_800B0D00[0x40];
UNIDENTIFIED_TYPE *D_cinematic_overlay_800B1900;
struct cuts_file_constant *D_cinematic_overlay_800B1904;
Vec3f *D_cinematic_overlay_800B1A08;
*/

// Interim `extern` definitions for BSS variables. Remove these when BSS matching is possible.
extern u8  D_cinematic_overlay_800B0B1E;
extern u16 D_cinematic_overlay_800B0B20;
extern struct D_cinematic_overlay_800B0D00_type  D_cinematic_overlay_800B0D00[0x40];
extern struct D_cinematic_overlay_800B1900_type *D_cinematic_overlay_800B1900;
extern struct cuts_file_constant *D_cinematic_overlay_800B1904;
extern Vec3f *D_cinematic_overlay_800B1A08;
extern s32 D_cinematic_overlay_800B1A10[];
extern s32 D_cinematic_overlay_800B1A20[];

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5130);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeSpecial);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeExtro);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeIntro);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicLoopBody);

#if 0
// Due to string re-use in the rodata section, this can't be fully matched until a couple other functions
// are matched too
// As written though, the .text section matches 100%
struct cuts_file_constant *load_cutscene(u8 level_id, u8 cutscene_type) {
    char sp10[0x20];
    u32 var_s1;
    u32 var_s4;
    struct cuts_file_constant *temp_v0;

    sprintf(sp10, "cuts/id%d_%s", level_id, cutsceneTypeStrings[cutscene_type]);
    temp_v0 = load_asset_with_malloc_flags(sp10, 0x10U);
    processCutsceneActions(temp_v0, gGameSettings.vehicleId);
    D_cinematic_overlay_800B0B20 = 0;
    if (level_id == LEVEL_LOGO) {
        if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_KOELSCH) {
            // These memcpy's get compiled out entirely, the loop inside them
            // gets unrolled too. I was not expecting that.
            memcpy(temp_v0->unk13D8[0x20].unk00, "pl_crafts/vwing", 0x10);
            memcpy(temp_v0->unk13D8[0x23].unk00, "pl_crafts/vwing", 0x10);
        }
    }
    D_cinematic_overlay_800B1900 = rs_malloc(temp_v0->unk13D8_active_count * sizeof(struct D_cinematic_overlay_800B1900_type), 0x10U);
    rs_memset(D_cinematic_overlay_800B1900, 0U, temp_v0->unk13D8_active_count * sizeof(struct D_cinematic_overlay_800B1900_type));
    for (var_s4 = 0; var_s4 < temp_v0->unk13D8_active_count; var_s4++) {
        D_cinematic_overlay_800B1900[var_s4].unk000 = 0;
        D_cinematic_overlay_800B1900[var_s4].unk068 = 5.0f;
        D_cinematic_overlay_800B1900[var_s4].unk0B8 = 0xFFFF;
        clearVec4QuadStruct(D_cinematic_overlay_800B1900[var_s4].unk088);
        var_s1 = strlen(temp_v0->unk13D8[var_s4].unk00) - 1;
        D_cinematic_overlay_800B1900[var_s4].unk001 = var_s1;
        if (rs_strcmp(temp_v0->unk13D8[var_s4].unk00, "pl_crafts/t16") == 0) continue;
        if (!((temp_v0->unk13D8[var_s4].unk00[var_s1] - '0') < 0xAU)) continue;

        while (((temp_v0->unk13D8[var_s4].unk00[var_s1] - '0') < 0xAU) || (temp_v0->unk13D8[var_s4].unk00[var_s1] == '_')) {
            var_s1--;
        }
        D_cinematic_overlay_800B1900[var_s4].unk001 = var_s1;
    }
    cuts_0058_bubble_sort(temp_v0);
    spawnCutsceneObjectsFromList(temp_v0, level_id, 0U);
    initWaterSprayEffectAndSfx();
    spawnCutsceneObjectsFromList(temp_v0, level_id, 1U);
    if (level_id != LEVEL_TALORAAN) {
        loadLevelTextureCache(0x5DC0);
    }
    initCutsceneAudioChannels(temp_v0);
    for (var_s4 = 0; var_s4 < 4; var_s4++) {
        D_cinematic_overlay_800B1A10[var_s4] = -1;
        D_cinematic_overlay_800B1A20[var_s4] = -1;
    }
    return temp_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", load_cutscene);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCinPlCraftsVwing);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A518C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A519C);
#endif

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicSlotUpdate);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", setupCutsceneLevel);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCinematicDispatchSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicSlotBatchDispatch);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", slotEffectHandlerDispatch);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cutscenePopulateSlotsFromLevelLists);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A52B4);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicSlotDispatcher);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", spawnCutsceneObjectsFromList);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cutsceneDispatchSlotsByFlag);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A52F0);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A52FC);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_800A5300);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCinRedbox1);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_800A5308);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_800A530C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5310);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5320);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", spawnCutsceneEffectsAndCues);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCutsceneAudioChannels);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCutsceneScene);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initSceneForMission);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", emit3DSoundsForActiveNpcs);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", updatePositionalAudioSource);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A54A8);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A54B4);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", applyCutsceneSlotMaterialOverrides);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", tickCutsceneActionSlots);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A54CC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", applyNamedEffectParameterDefault);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A54F4);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5500);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A550C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5518);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5524);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5530);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A553C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5548);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5554);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5560);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A556C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5570);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5574);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5578);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5594);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", spawnCutsceneDebrisField);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", npcIncomingMissileUpdate);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", buildCutsceneGradientBuffers);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5820);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A582C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5830);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", jtbl_cinematic_overlay_800A5838);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5850);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5854);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5858);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A585C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5860);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5864);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5868);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A586C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5870);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5874);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5878);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A587C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5880);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5884);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5888);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A588C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5890);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5894);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5898);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A589C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58A0);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58A4);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58A8);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58AC);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58B0);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58B4);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58B8);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A58BC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", spawnNpcBurstAlongSegment);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", processCutsceneActions);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", computeCutsceneScreenScale);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", tickCutsceneCameraFromTimeline);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", transformAndNormalizeDirectionByMatrix);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", loadBackdropAsset);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5B6C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5B74);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5B7C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5B84);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5B88);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_800A5B9C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5BAC);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCinematicSceneAssets);

void dispatchCinematicFromMainLoop(u8 *arg0, u8 arg1) {
    s32 var_a1;
    u8 allBronze;
    u8 allSilver;
    u8 allGold;
    u8 var_v0;
    u8 temp_v1;

    allBronze = 1;
    allSilver = 1;
    allGold = 1;
    for (var_v0 = 0; var_v0 < 0x10; var_v0++) {
        temp_v1 = arg0[var_v0];
        if (temp_v1 < 3) {
            allGold = 0;
        }
        if (temp_v1 < 2) {
            allSilver = 0;
        }
        if (temp_v1 < 1) {
            allBronze = 0;
        }
    }
    D_cinematic_overlay_800B0B1E = 0;
    if (allBronze) {
        D_cinematic_overlay_800B0B1E = 1;
    }
    if (allSilver) {
        D_cinematic_overlay_800B0B1E = 2;
    }
    if (allGold) {
        D_cinematic_overlay_800B0B1E = 3;
    }
    cinematicLoopBody(3, 2, arg1);
}

u8 shouldShowCutsceneForLevelStage(u8 levelId, u8 arg1) {
    u8 ret;

    ret = (arg1 == 0);
    if (arg1 == 1) {
        ret = 1;
    }
    if (levelId >= LEVEL_BEGGARS_CANYON) {
        ret = 0;
    }
    if (levelId == LEVEL_CORELLIA) {
        if (arg1 == 2) {
            ret = 1;
        }
    }
    if ((levelId == LEVEL_LOGO) && ((arg1 & 0xFF) == 2)) {
        ret = 1;
    }
    return ret;
}

#if 0
// Due to the strings, this likely isn't match-able until the whole file is matched
char *getAssetNameForNpcType(u8 datSubType) {
    switch (datSubType) {
    case DAT_UNKNOWN_00:
    case DAT_TYPE_0_GENERIC_BUILDING:
    case DAT_TYPE_0_21:
    case DAT_TYPE_0_IMPERIAL_TRAIN_PILLAR:
    case DAT_TYPE_0_IMPERIAL_PLATFORM:
    case DAT_TYPE_0_POWER_GENERATOR:
    case DAT_TYPE_0_4B:
        return NULL;
    case DAT_TYPE_0_TALORAAN_TURRET:
        return "b_ttu_hi";
    case DAT_TYPE_0_RADAR_DISH:
        return "b_lrsp";
    case DAT_TYPE_0_REBEL_TRANSPORT:
        return "reb_transport";
    case DAT_TYPE_0_REBEL_COMBAT:
        return "r_combat";
    case DAT_TYPE_0_MEGA_TURRENT:
        return "megaturret";
    case DAT_TYPE_0_REBEL_TURRET:
        return "r_tur_hi";
    case DAT_TYPE_0_GUN_TURRET:
        return "i_gtu_hi";
    default:
        return NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", getAssetNameForNpcType);
#endif

Vec3f *func_cinematic_overlay_800AEA18(void) {
    return D_cinematic_overlay_800B1A08;
}

void cuts_0058_bubble_sort(struct cuts_file_constant *cutscene) {
    struct cuts_0058_type temp;
    struct cuts_0058_type *temp_s0;
    struct cuts_0058_type *temp_s1;
    u16 var_s2;
    u16 var_s3;

    if (cutscene->unk0058_active_count >= 2U) {
        for (var_s3 = 0; var_s3 < cutscene->unk0058_active_count; var_s3++) {
            for (var_s2 = var_s3 + 1; var_s2 < cutscene->unk0058_active_count; var_s2++) {
                temp_s0 = &cutscene->unk0058[var_s3];
                temp_s1 = &cutscene->unk0058[var_s2];
                if (temp_s0->unk04 > temp_s1->unk04) {
                    zmemcpy(&temp,   temp_s0, sizeof(struct cuts_0058_type));
                    zmemcpy(temp_s0, temp_s1, sizeof(struct cuts_0058_type));
                    zmemcpy(temp_s1, &temp,   sizeof(struct cuts_0058_type));
                }
            }
        }
    }
}

void noopHandler_800AEB30(void) {
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", freeCutsceneResources);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", resetCutsceneActionSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", scheduleCutsceneActionSlot);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", composeInterpolatedNodeMatricesAlt);

void tickCutsceneNpcSlots(struct cuts_file_constant *arg0) {
    Vec3f sp10;
    Vec3f sp20;
    u32 temp_s1;
    u16 temp_s0;
    u32 var_s3;

    for (var_s3 = 0; var_s3 < arg0->unk13D8_active_count; var_s3++) {
        temp_s0 = D_cinematic_overlay_800B1900[var_s3].unk0B8;
        if (temp_s0 == 0xFFFF) continue;
        temp_s1 = getNextSlotNpcTypeId(temp_s0);
        if (temp_s1 != 0xFFFF) {
            sp10[0] =  0.0f;
            sp10[1] = -0.1f;
            sp10[2] = -0.4f;
            transformVec3ByMat34(D_cinematic_overlay_800B1900[var_s3].unk088, sp10, sp20);
            setNpcForwardVectorByIndex(temp_s1, sp20);
        } else {
            destroyNpcSlotChain(temp_s0);
            D_cinematic_overlay_800B1900[var_s3].unk0B8 = temp_s1;
        }
    }
}
#if 0
void despawnCutsceneNpcSlot(u8 arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    u16 temp_s1;

    temp_s1 = D_cinematic_overlay_800B1900[arg0].unk0B8;
    if (temp_s1 != 0xFFFF) {
        temp_a0_2 = getNextSlotNpcTypeId(temp_s1);
        if (temp_a0_2 != 0xFFFF) {
            destroyNpcSlotByIndexU16(temp_a0_2);
        }
        destroyNpcSlotChain(temp_s1);
        D_cinematic_overlay_800B1900[arg0].unk0B8 = 0xFFFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", despawnCutsceneNpcSlot);
#endif

void initCutsceneSlotTable(void) {
    u32 var_a0;

    for (var_a0 = 0; var_a0 < 0x40; var_a0++) {
        D_cinematic_overlay_800B0D00[var_a0].unk00 = 0;
    }
}

void insertCutsceneSlot(struct D_cinematic_overlay_800B0D00_type *arg0) {
    u32 var_v1;

    for (var_v1 = 0; var_v1 < 0x40; var_v1++) {
        if (D_cinematic_overlay_800B0D00[var_v1].unk00 == 0) {
            zmemcpy(&D_cinematic_overlay_800B0D00[var_v1], arg0, sizeof(struct D_cinematic_overlay_800B0D00_type));
            break;
        }
    }
}

u16 lookupCutsceneIdMapping(s32 arg0) {
    u16 var_a1;
    u16 ret = 0xFFFF;

    for (var_a1 = 0; var_a1 < 0x5E; var_a1++) {
        if (gCutsceneIdMappingTable[var_a1].unk0 == arg0) {
            ret = gCutsceneIdMappingTable[var_a1].unk2;
            break;
        }
    }
    return ret;
}

void destroyAllNpcsInSlotChain(s32 arg0) {
    struct findActiveNpcInSlotChain_arg1 sp10;
    u16 temp_a0;

    while ((temp_a0 = findActiveNpcInSlotChain(D_main_bss_80139560[arg0], &sp10)) != 0xFFFF) {
        destroyNpcSlotByIndex(temp_a0);
    }
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", maybeLoadYwingCutscene);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", buildBobbingObjectMatrix);

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

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", matchKeywordWithPriority);

f32 cinematicComputeDt(void) {
    struct timeSnapshotFiller_arg0 sp10;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fv0;

    timeSnapshotFiller(&sp10);
    var_fs0 = sp10.unk20;
    D_main_bss_8013889C += 1;
    temp_fv0 = floatModulo(var_fs0, sp10.unk1C);
    if (temp_fv0 > 0.0f) {
        if ((temp_fv0 / sp10.unk1C) < 0.5f) {
            var_fs0 -= temp_fv0;
        } else {
            var_fs0 = (var_fs0 + sp10.unk1C) - temp_fv0;
        }
    }
    if (var_fs0 <= 0.0f) {
        var_fs0 = 0.016666668f;
    }
    return var_fs0;
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicInitializer);

s32 isCinematicActive(void) {
    return D_cinematic_overlay_800B0934 != 0;
}

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicStageAdvancer);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicDeactivator);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", getCinematicStateSubObject);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicInterpRatio);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", fake_func_800AF6A8);
