#include "common.h"

#include "controller_settings.h"
#include "game_settings.h"
#include "levels.h"

#include "main/033C0.h"
#include "main/3F160.h"
#include "main/98960.h"
#include "mission_overlay/0AEFF0.h"
#include "mission_overlay/0BF800.h"

// Interim BSS externs
extern u32 D_mission_overlay_8010B740[];
extern u8  D_mission_overlay_8010B780[];
extern f32 D_mission_overlay_8010B7A0;

u32 D_mission_overlay_80109680[] = {
    0x0000010F,
    0x00000110,
    0x00000111,
    0x00000113,
    0x00000114,
    0x00000115,
};

u32 D_mission_overlay_80109698[] = {
    0x000001E4,
    0x000001F7,
    0x000001E8,
    0x00000221,
    0x000001EE,
    0x00000222,
};

f32 D_mission_overlay_801096B0 = 0.0f;

u32 D_mission_overlay_801096B4 = 0xFFFFFFFF;

u8  D_mission_overlay_801096B8 = 0x01;

u8  D_mission_overlay_801096B9 = 0x00;

u16 D_mission_overlay_801096BC[] = {
    0x00FA,
    0x00C8,
    0x012C,
    0x0190,
    0x0064,
    0x00FA,
    0x00FA,
    0x00FA,
    0x03E8,
    0x00FA,
    0x00FA,
    0x0FA0,
    0x07D0,
    0x0000,
};

u16 D_mission_overlay_801096D8[] = {
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0014,
    0x0000,
};

u16 D_mission_overlay_801096F4[] = {
    0x001E,
    0x000A,
    0x0014,
    0x001E,
    0x000A,
    0x0014,
    0x001E,
    0x0014,
    0x003C,
    0x0014,
    0x001E,
    0x012C,
    0x0028,
    0x0000,
};

u16 D_mission_overlay_80109710[] = {
    0x0014,
    0x0028,
    0x001E,
    0x0014,
    0x0028,
    0x001E,
    0x0014,
    0x0028,
    0x000A,
    0x0014,
    0x0014,
    0x012C,
    0x0014,
    // DO NOT DELETE US WE ARE REQUIRED FOR MATCHING
    0x96A8,
    0x4602,
    0x0002,
};

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", initPlayerCraftTrailBuffers);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", computeCraftSelectTurnFromInput);

void populateCutsceneSubtitleTextIds(void) {
    s32 var_v1;
    s32 why;
    u32 temp;

    for (var_v1 = 0xD; var_v1 >= 0; var_v1--) {
        do {why = var_v1;} while(0); // Permuter magic
        D_mission_overlay_8010B780[why] = 0;
    }
    D_mission_overlay_8010B740[0]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x104 : 0x28C;
    D_mission_overlay_8010B740[1]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x272 : 0x28C;
    D_mission_overlay_8010B740[2]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x134 : 0x28C;
    D_mission_overlay_8010B740[3]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x122 : 0x206;
    D_mission_overlay_8010B740[4]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x123 : 0x207;
    D_mission_overlay_8010B740[5]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x124 : 0x208;
    D_mission_overlay_8010B740[6]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x12B : 0x20F;
    D_mission_overlay_8010B740[7]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x12E : 0x212;
    D_mission_overlay_8010B740[8]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x12F : 0x213;
    D_mission_overlay_8010B740[9]  = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x12D : 0x211;
    D_mission_overlay_8010B740[10] = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x130 : 0x214;
    D_mission_overlay_8010B740[11] = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x131 : 0x28C;
    D_mission_overlay_8010B740[12] = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x132 : 0x28C;
    D_mission_overlay_8010B740[13] = gGameSettings.currentLevel != LEVEL_CALAMARI ? 0x133 : 0x28C;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", playRandomCutsceneVoiceLine);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", integrateCraftVelocityAndCollide);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", playCutsceneObjectImpactSound);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", tickCutsceneObject);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", findNearestSceneObjectToPoint);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", loadPlayerStartPosition);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0AEFF0", D_mission_overlay_800A55C0);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", spawnSceneDebrisAndEffectCluster);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", spawnNpcDestructionDebris);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", updateSplineCraftTransform);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", computeOrientedTransformFromQuat);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", tickCinematicObjectStateMachine);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", updatePlayerCraftPhysics);

void applyCraftCapabilityFlags(struct inner_player_struct *arg0) {
    D_mission_overlay_8010BFA8[arg0->unk0B8] |= D_mission_overlay_8010BE18[arg0->unk0B8].asStruct.pause;
    D_mission_overlay_8010BFA8[arg0->unk0B8] |= D_mission_overlay_8010BE18[arg0->unk0B8].asStruct.drop_camera;
    D_mission_overlay_8010BFA8[arg0->unk0B8] |= D_mission_overlay_8010BE18[arg0->unk0B8].asStruct.switch_view;
    D_mission_overlay_8010BFA8[arg0->unk0B8] |= D_mission_overlay_8010BE18[arg0->unk0B8].asStruct.fire_mode;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", initPlayerCraftMovementMode);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", tryPlaySpatialSoundWithGates);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", scheduleSceneFormatMessageTimed);

void cancelSceneQueueHandle(struct inner_player_struct *arg0) {
    if (arg0->unk1C0 != -1) {
        stopRumbleEffect(arg0->unk1C0);
        arg0->unk1C0 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", playSpeechClipOncePerChange);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", playSpeechClipOncePerLevel);

void resetSpeechOncePerLevelFlag(s32 arg0) {
    s32 var_v1;

    if (arg0 != 0x28C) {
        for (var_v1 = 0; var_v1 < 0xE; var_v1++) {
            if (D_mission_overlay_8010B740[var_v1] == arg0) {
                D_mission_overlay_8010B780[var_v1] = var_v1 = 0; // Permuter magic
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", setPlayerSlotPositionVec3);

void destroySceneNpcsAndUnlink(struct inner_player_struct *arg0) {
    u16 temp_a0;

    if (arg0->unk1CC != 0xFFFF) {
        while ((temp_a0 = getNextSlotNpcTypeId(arg0->unk1CC)) != 0xFFFF) {
            destroyNpcSlotByIndex(temp_a0);
        }
        destroyNpcSlotChain(arg0->unk1CC);
        arg0->unk1CC = 0xFFFFU;
    }
    if (arg0->unk24C != 0) {
        arg0->unk24C = 0U;
        factor5RemoveListNode(&arg0->unk208);
    }
}

// This function appears to be unused, so the type of `arg0` is immaterial
// If I had to guess based on other functions in this file, its probably `struct inner_player_struct`
void decayWeaponCooldownTimer(void *arg0, f32 arg1) {
    if (D_mission_overlay_801096B0 > 0.0f) {
        D_mission_overlay_801096B0 -= arg1;
    }
}

f32 getWeaponChargeLevel(void) {
    return D_mission_overlay_8010B7A0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", advancePitchTowardTarget);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AEFF0", fake_func_800B42BC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0AEFF0", D_mission_overlay_800A5810);
