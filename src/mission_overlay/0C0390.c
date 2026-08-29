#include "common.h"

#include "game_settings.h"
#include "mission_state.h"
#include "player.h"
#include "secondary_weapons.h"
#include "hud.h"

#include "mission_overlay/0C0390.h"

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

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800BF790);

void func_mission_overlay_800BFDC4(struct func_800C0084_type *arg0) {
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

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800BFEA0);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", handleHUD);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C1B64);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C1D3C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C298C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C3F70);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C3FEC);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C401C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C4060);

f32 getPlayerHealthPercentage(s32 arg0) {
    if ((gPlayers[arg0].inner.currentHealth <= 0.0f)) {
        return 0.0f;
    } else {
        return gPlayers[arg0].inner.currentHealth / gPlayers[arg0].inner.maxHealth;
    } 
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", func_mission_overlay_800C40F8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C0390", fake_func_800C41AC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0C0390", D_mission_overlay_800A6724);
