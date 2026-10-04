#include "common.h"

#include "PR/gu.h"

#include "game_settings.h"
#include "levels.h"
#include "mission_state.h"
#include "player.h"
#include "secondary_weapons.h"

#include "main/bss_80130B10.h"
#include "main/3F160.h"
#include "mission_overlay/0BF800.h"
#include "mission_overlay/0C0390.h"

u16 D_mission_overlay_8010BFD0;
u16 bss_pad0_0C0390;
u32 bss_pad1_0C0390;
struct rgba D_mission_overlay_8010BFD8;
f32 D_mission_overlay_8010BFDC;

// Interim Data externs
// These might actually be one big array, based on the access pattern in `updateHudHealthIndicator`
extern struct healthIndicatorColors advancedShieldColors;
extern struct healthIndicatorColors standardHealthColors[2];
extern struct healthIndicatorColors criticalHealthColors[3];
extern u8 missionObjectiveTextIds[0x14][4];

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A6250);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A6260);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A626C);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A627C);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A628C);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A6298);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62A4);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62B0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62BC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62C8);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62D0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62D8);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A62E0);

void updateHudHealthIndicator(struct func_800C0084_type *arg0, f32 arg1) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fs0;
    f32 permuter;
    f32 magic;
    s32 temp_ft2;
    struct healthIndicatorColors *var_a1;

    temp_fv0 = getPlayerHealthPercentage(arg0->unk234);
    if (temp_fv0 < 0.25f) {
        var_fs0 = (0.25f - temp_fv0) * 4.0f;
        var_a1 = criticalHealthColors;
    } else {
        temp_fv1 = gPlayers[arg0->unk234].inner.advancedShieldTimer;
        if (temp_fv1 > 0.0f) {
            var_a1 = &advancedShieldColors;
            arg0->playerHealthPercentage = temp_fv0;
            var_fs0 = 1.0f - temp_fv1;
        } else {
            var_fs0 = (1.0f - temp_fv0) * 4.0f;
            temp_ft2 = (s32) var_fs0;
            var_a1 = &standardHealthColors[temp_ft2];
            var_fs0 -= (f32) temp_ft2;
        }
    }
    if (temp_fv0 < arg0->playerHealthPercentage) {
        arg0->unk23C = 1.0f;
    }
    arg0->playerHealthPercentage = temp_fv0;
    arg0->upperHealthIndicatorColor.r = var_a1->upper.r + ((var_a1[1].upper.r - var_a1->upper.r) * var_fs0);
    arg0->upperHealthIndicatorColor.g = var_a1->upper.g + ((var_a1[1].upper.g - var_a1->upper.g) * var_fs0);
    arg0->upperHealthIndicatorColor.b = var_a1->upper.b + ((var_a1[1].upper.b - var_a1->upper.b) * var_fs0);
    arg0->upperHealthIndicatorColor.a = 0xB9;
    arg0->lowerHealthIndicatorColor.r = var_a1->lower.r + ((var_a1[1].lower.r - var_a1->lower.r) * var_fs0);
    arg0->lowerHealthIndicatorColor.g = var_a1->lower.g + ((var_a1[1].lower.g - var_a1->lower.g) * var_fs0);
    arg0->lowerHealthIndicatorColor.b = var_a1->lower.b + ((var_a1[1].lower.b - var_a1->lower.b) * var_fs0);
    arg0->lowerHealthIndicatorColor.a = 0x5C;
    if (temp_fv0 < 0.25f) {
        temp_fa0 = (cosf(2.0f * (arg0->unk238 * 3.1415927f)) + 1.0f) * 0.5f;
        arg0->upperHealthIndicatorColor.a *= temp_fa0;
        var_fs0 = (2.0f * var_fs0) * arg1;
        arg0->unk238 += (var_fs0) + arg1;
    }
    if (arg0->unk23C > 0.0f) {
        var_fs0 = (sinf((2.0f * (2.0f * arg0->unk23C * 3.1415927f)) - 1.5707964f) + 1.0f) * 0.5f;
        arg0->upperHealthIndicatorColor.r += (0xFF - arg0->upperHealthIndicatorColor.r) * var_fs0;
        arg0->upperHealthIndicatorColor.g += (0xFF - arg0->upperHealthIndicatorColor.g) * var_fs0;
        arg0->upperHealthIndicatorColor.b += (0xFF - arg0->upperHealthIndicatorColor.b) * var_fs0;
        permuter = (2.0f * arg0->unk23C);
        magic = (cosf(2.0f * (permuter * 3.1415927f)) + 1.0f);
        arg0->upperHealthIndicatorColor.a *= (magic * 0.5f);
        arg0->unk23C -= arg1;
        if (arg0->unk23C < 0.0f) {
            arg0->unk23C = 0.0f;
        }
    }
}

void setHudSecondaryWeaponInfo(struct func_800C0084_type *arg0) {
    u8 secondaryWeaponLevel;
    u8 secondaryWeaponType;

    switch (gMissionState.secondaryWeapon) {
    case SECONDARY_WEAPON_MISSLES:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_MISSLE;
        secondaryWeaponLevel = (gGameSettings.unlockAndSettingsFlags[0] >> GAME_SETTINGS_ADVANCED_MISSILES) & 1;
        break;
    case SECONDARY_WEAPON_SEEKER_MISSILES:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_MISSLE;
        secondaryWeaponLevel = SECONDARY_WEAPON_LEVEL_SEEKER;
        break;
    case SECONDARY_WEAPON_CLUSTER_MISSILES:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_CLUSTER_MISSLE;
        secondaryWeaponLevel = (gGameSettings.unlockAndSettingsFlags[0] >> GAME_SETTINGS_SEEKER_CLUSTER_MISSILES) & 1;
        break;
    case SECONDARY_WEAPON_SEEKER_CLUSTER_MISSILES:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_CLUSTER_MISSLE;
        secondaryWeaponLevel = SECONDARY_WEAPON_LEVEL_SEEKER;
        break;
    case SECONDARY_WEAPON_PROTON_TORPEDOS:
        secondaryWeaponType = SECONDARY_WEAPON_TYPE_TORPEDO;
        if (!ADVANCED_TORPEDOS_UNLOCKED) {
            secondaryWeaponLevel = ((gGameSettings.unlockAndSettingsFlags[0] & GAME_SETTING_MASK(GAME_SETTINGS_SEEKER_TORPEDOS)) != 0) * 2;
        } else {
            secondaryWeaponLevel = SECONDARY_WEAPON_LEVEL_ADVANCED;
        }
        break;
    case SECONDARY_WEAPON_SEEKER_TORPEDOS:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_TORPEDO;
        secondaryWeaponLevel = SECONDARY_WEAPON_LEVEL_SEEKER;
        break;
    case SECONDARY_WEAPON_BOMBS:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_BOMB;
        secondaryWeaponLevel = (gGameSettings.unlockAndSettingsFlags[0] >> GAME_SETTINGS_ADVANCED_BOMBS) & 1;
        break;
    default:
        secondaryWeaponType  = SECONDARY_WEAPON_TYPE_MISSLE;
        secondaryWeaponLevel = SECONDARY_WEAPON_LEVEL_NORMAL;
        break;
    }
    arg0->secondaryWeaponType  = secondaryWeaponType;
    arg0->secondaryWeaponLevel = secondaryWeaponLevel;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", findHudElementExtremes);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", handleHUD);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", evalPauseMenuInputMode);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", initOrUpdatePauseScreenDim);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", runPauseMenuStateMachine);

void spawnHudNpc(void) {
    s32 var_a0;
    s32 var_v0;
    u32 var_a1;

    var_a1 = 0;
    for (var_a0 = 0; var_a0 < 4; var_a0++) {
        if (missionObjectiveTextIds[gCurrentLevel][var_a0] != 0) var_a1++;
    }
    gMissionState.numMissionObjectives = var_a1;
    D_mission_overlay_8010BFD0 = spawnNpcOfType(handleHUD, NULL, 4U, 0x64U);
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", broadcastSceneShutdownAndCleanup);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", broadcastSceneEventWithPayload);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", setRenderObjectTargetOrClear);

f32 getPlayerHealthPercentage(s32 arg0) {
    if ((gPlayers[arg0].inner.currentHealth <= 0.0f)) {
        return 0.0f;
    } else {
        return gPlayers[arg0].inner.currentHealth / gPlayers[arg0].inner.maxHealth;
    } 
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", probeNumberedAssetFilename);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", fake_func_800C41AC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A6724);
