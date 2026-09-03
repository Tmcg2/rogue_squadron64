#include "common.h"
#include "common_types.h"
#include "dat.h"
#include "levels.h"
#include "cinematic_overlay/1381D0.h"
#include "main/192E0.h"
#include "main/42AF0.h"
#include "main/66FB0.h"

struct cutsceneIdMapEntry {
    u16 unk0;
    u16 unk2;
};

/* Data Variable, uncomment when Data matching is possible
struct cutsceneIdMapEntry gCutsceneIdMappingTable[] = {...};
*/

// Interim `extern` definitions for Data variable. Remove these when Data is matchable

extern struct cutsceneIdMapEntry gCutsceneIdMappingTable[];

/* BSS Variables, uncomment when BSS matching is possible

struct cuts_file_constant *D_cinematic_overlay_800B1904;
Vec3f *D_cinematic_overlay_800B1A08;
*/

// Interim `extern` definitions for BSS variables. Remove these when BSS matching is possible.
extern struct cuts_file_constant *D_cinematic_overlay_800B1904;
extern Vec3f *D_cinematic_overlay_800B1A08;

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A5130);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeSpecial);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeExtro);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCutsceneTypeIntro);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicLoopBody);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", load_cutscene);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", strCinPlCraftsVwing);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A518C);

INCLUDE_RODATA("asm/nonmatchings/cinematic_overlay/1381D0", D_cinematic_overlay_800A519C);

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

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", dispatchCinematicFromMainLoop);

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

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", tickCutsceneNpcSlots);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", despawnCutsceneNpcSlot);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", initCutsceneSlotTable);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", insertCutsceneSlot);

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

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", destroyAllNpcsInSlotChain);

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

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicComputeDt);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicInitializer);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", isCinematicActive);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicStageAdvancer);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicDeactivator);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", getCinematicStateSubObject);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", cinematicInterpRatio);

INCLUDE_ASM("asm/nonmatchings/cinematic_overlay/1381D0", fake_func_800AF6A8);
