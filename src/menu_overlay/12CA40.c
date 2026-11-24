#include "common.h"
#include "common_variables.h"

#include "cheat_codes.h"
#include "crafts.h"
#include "levels.h"
#include "secondary_weapons.h"
#include "medals.h"
#include "game_settings.h"
#include "mission_state.h"

#include "main/bss_80136FD0.h"

#include "main/08510.h"
#include "main/1D000.h"
#include "menu_overlay/110410.h"
#include "menu_overlay/115E00.h"
#include "menu_overlay/12CA40.h"

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", menuOverlayInit);

s32 drawRadarIcon(struct GameSettings *arg0, s32 arg1) {
    s32 temp_v0;
    u32 var_a2;
    u32 var_a3;

    var_a2 = gMissionState.maxUnlockedLevel;
    if (var_a2 >= 0x10U) {
        var_a2 = 0xF;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_GAMEFLO) {
        var_a2 = 0xF;
    }
    if (BEGGARS_CANYON_UNLOCKED || (gGameSettings.cheatCodeFlags[0] & 0x04000000)) {
        var_a2 = 0x10;
    }
    if (DEATH_STAR_UNLOCKED || (gGameSettings.cheatCodeFlags[0] & 0x08000000)) {
        var_a2 = 0x11;
    }
    if (HOTH_UNLOCKED || (gGameSettings.cheatCodeFlags[0] & 0x10000000)) {
        var_a2 = 0x12;
    }
    if (var_a2 >= arg0->currentLevel) {
        var_a3 = arg0->currentLevel;
    } else {
        var_a3 = var_a2;
    }
    initCraftSelectScreen(arg1, 1 << var_a3, (1 << (var_a2 + 1)) - 1);
    do {
        temp_v0 = tickCraftSelectScreen();
    } while (temp_v0 == 0xFFFFFF);
    drainAudioAndFinalizeSpeechBuffer();
    if (temp_v0 != 0xFFFFFE) {
        arg0->currentLevel = temp_v0;
        arg0->unk02 = 0;
        return 1;
    } else {
        return 0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuALPHA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuBETA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuGAMMA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuDELTA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", D_menu_overlay_800A760C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuINTRO);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuEXTRO);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuSPECIAL);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", D_menu_overlay_800A7644);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", runResultsTextScreenLoop);

s32 getAvailablePlayerCraftFlagsConsiderUnlocks(enum Level levelId) {
    s32 availableCraftFlags;

    availableCraftFlags = CRAFT_FLAG(dDefaultCraftForLevel[levelId]);
    if ((gMissionState.maxUnlockedLevel >= LEVEL_JADEMOON) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_AWING);
    }
    if ((gMissionState.maxUnlockedLevel >= LEVEL_TALORAAN) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_VWING);
    }
    if ((gMissionState.maxUnlockedLevel >= LEVEL_CALAMARI) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_XWING);
    }
    if (ALL_CRAFT_UNLOCKED) {
        availableCraftFlags |= 0x7F;
    }
    if ((gGameSettings.cheatCodeFlags[0] & 4) || MELLINIUM_FALCON_UNLOCKED) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_FALCON);
    }
    if ((gGameSettings.cheatCodeFlags[0] & 8) || TIE_INTERCEPTOR_UNLOCKED) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_TIEINTER);
    }
    if (levelId == LEVEL_TALORAAN) {
        availableCraftFlags &= ~CRAFT_FLAG(CRAFT_VWING);
        availableCraftFlags &= ~CRAFT_FLAG(CRAFT_SNOWSPEEDER);
    }
    if (levelId == LEVEL_TRENCH_RUN) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_XWING);
    }
    if (levelId == LEVEL_KESSEL_RESCUE) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_XWING) | CRAFT_FLAG(CRAFT_YWING);
    }
    if ((levelId == LEVEL_CORELLIA) || (levelId == LEVEL_CONST_YARD) || (levelId == LEVEL_FEST) || (levelId == LEVEL_HOTH)) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_SNOWSPEEDER);
    }
    if (levelId == LEVEL_BEGGARS_CANYON) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_T16);
    }
    return availableCraftFlags;
}

s32 getAvailablePlayerCraftFlagsIgnoreUnlocks(enum Level levelId) {
    s32 availableCraftFlags;

    availableCraftFlags = CRAFT_FLAG(dDefaultCraftForLevel[levelId]);
    if (availableCraftFlags & 0xD) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_XWING) | CRAFT_FLAG(CRAFT_AWING) | CRAFT_FLAG(CRAFT_VWING);
    }
    if (ALL_CRAFT_UNLOCKED) {
        availableCraftFlags |= 0x7F;
    }
    if ((gGameSettings.cheatCodeFlags[0] & 4) || MELLINIUM_FALCON_UNLOCKED) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_FALCON);
    }
    if ((gGameSettings.cheatCodeFlags[0] & 8) || TIE_INTERCEPTOR_UNLOCKED) {
        availableCraftFlags |= CRAFT_FLAG(CRAFT_TIEINTER);
    }
    if (levelId == LEVEL_TALORAAN) {
        availableCraftFlags &= ~CRAFT_FLAG(CRAFT_VWING);
        availableCraftFlags &= ~CRAFT_FLAG(CRAFT_SNOWSPEEDER);
    }
    if (levelId == LEVEL_TRENCH_RUN) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_XWING);
    }
    if (levelId == LEVEL_KESSEL_RESCUE) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_XWING) | CRAFT_FLAG(CRAFT_YWING);
    }
    if ((levelId == LEVEL_CORELLIA) || (levelId == LEVEL_CONST_YARD) || (levelId == LEVEL_FEST) || (levelId == LEVEL_HOTH)) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_SNOWSPEEDER);
    }
    if (levelId == LEVEL_BEGGARS_CANYON) {
        availableCraftFlags &= CRAFT_FLAG(CRAFT_T16);
    }
    return availableCraftFlags;
}

void unlockLevelsAndCraftsBasedOnMedalsEarned(u8 *medalsPerLevel) {
    u8 var_a1;
    u8 normalAllBronze;
    u8 unlockableAllBronze;
    u8 normalAllSilver;
    u8 unlockableAllSilver;
    u8 normalAllGold;
    u8 unlockableAllGold;
    u8 anyLevelsUnlocked;
    u8 temp_v1;
    u8 temp_v1_2;

    anyLevelsUnlocked = 0;
    normalAllBronze = 1;
    normalAllSilver = 1;
    normalAllGold   = 1;
    // Check the medals for all "normal" levels
    for (var_a1 = 0; var_a1 < LEVEL_BEGGARS_CANYON; var_a1++) {
        temp_v1 = medalsPerLevel[var_a1];
        if (temp_v1 < MEDAL_GOLD) {
            normalAllGold = 0;
        }
        if (temp_v1 < MEDAL_SILVER) {
            normalAllSilver = 0;
        }
        if (temp_v1 < MEDAL_BRONZE) {
            normalAllBronze = 0;
        }
    }
    if (normalAllBronze == 1) {
        if (!BEGGARS_CANYON_UNLOCKED) {
            anyLevelsUnlocked = 1;
        }
        GAME_SETTING_SET(0, GAME_SETTINGS_BEGGARS_CANYON);
    }
    if (normalAllSilver == 1) {
        if (!DEATH_STAR_UNLOCKED) {
            anyLevelsUnlocked = 1;
        }
        GAME_SETTING_SET(0, GAME_SETTINGS_DEATH_STAR);
    }
    if (normalAllGold == 1) {
        if (!HOTH_UNLOCKED) {
            anyLevelsUnlocked = 1;
        }
        GAME_SETTING_SET(0, GAME_SETTINGS_HOTH);
    }
    gMissionState.anyExtraLevelsUnlocked = anyLevelsUnlocked;
    unlockableAllBronze = 1;
    unlockableAllSilver = 1;
    unlockableAllGold   = 1;
    // Check the medals for all unlockable levels
    for (var_a1 = LEVEL_BEGGARS_CANYON; var_a1 < NUM_LEVELS; var_a1++) {
        temp_v1 = medalsPerLevel[var_a1];
        if (temp_v1 < MEDAL_GOLD) {
            unlockableAllGold = 0;
        }
        if (temp_v1 < MEDAL_SILVER) {
            unlockableAllSilver = 0;
        }
        if (temp_v1 < MEDAL_BRONZE) {
            unlockableAllBronze = 0;
        }
    }
    if (unlockableAllBronze == 1) {
        GAME_SETTING_SET(0, GAME_SETTINGS_MELLINIUM_FALCON);
    }
    if (unlockableAllSilver == 1) {
        GAME_SETTING_SET(0, GAME_SETTINGS_TIE_INTERCEPTOR);
    }
    if (unlockableAllGold == 1) {
        GAME_SETTING_SET(0, GAME_SETTINGS_ALL_CRAFT);
    }
}

f32 advanceWrappingPhaseAccumulator(void) {
    struct timeSnapshotFiller_arg0 sp10;
    f32 temp_fv0;
    f32 var_fs0;

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
    if (var_fs0 > 0.16666667f) {
        var_fs0 = 0.16666667f;
    }
    return var_fs0;
}

s32 getLevelHardwiredDifficulty(u8 levelId) {
    return 0;
}

u8 getSecondaryWeaponForLevelAndCraft(u8 levelId, u8 craftId, u8 arg2) {
    s32 secondaryWeaponType;

    secondaryWeaponType = SECONDARY_WEAPON_NONE;
    switch (craftId) {
    case CRAFT_XWING:
        secondaryWeaponType = SECONDARY_WEAPON_PROTON_TORPEDOS;
        break;
    case CRAFT_YWING:
        secondaryWeaponType = SECONDARY_WEAPON_BOMBS;
        break;
    case CRAFT_AWING:
        secondaryWeaponType = SECONDARY_WEAPON_MISSLES;
        break;
    case CRAFT_VWING:
        secondaryWeaponType = SECONDARY_WEAPON_CLUSTER_MISSILES;
        break;
    case CRAFT_SNOWSPEEDER:
        secondaryWeaponType = SECONDARY_WEAPON_TOW_CABLE;
        break;
    case CRAFT_TIEINTER:
    case CRAFT_T16:
        secondaryWeaponType = SECONDARY_WEAPON_NONE;
        break;
    case CRAFT_FALCON:
    case CRAFT_KOELSCH:
        secondaryWeaponType = SECONDARY_WEAPON_SEEKER_TORPEDOS;
        break;
    }
    if (levelId == LEVEL_KESSEL_RESCUE) {
        if (craftId == CRAFT_XWING) {
            secondaryWeaponType = SECONDARY_WEAPON_ION_CANNON;
        }
    }
    if ((secondaryWeaponType == SECONDARY_WEAPON_MISSLES) && GAME_SETTING_IS_SET(arg2, GAME_SETTINGS_SEEKER_MISSILES)) {
        secondaryWeaponType = SECONDARY_WEAPON_SEEKER_MISSILES;
    }
    if ((secondaryWeaponType == SECONDARY_WEAPON_PROTON_TORPEDOS) && GAME_SETTING_IS_SET(arg2, GAME_SETTINGS_SEEKER_TORPEDOS)) {
        secondaryWeaponType = SECONDARY_WEAPON_SEEKER_TORPEDOS;
    }
    if ((secondaryWeaponType == SECONDARY_WEAPON_CLUSTER_MISSILES) && GAME_SETTING_IS_SET(arg2, GAME_SETTINGS_SEEKER_CLUSTER_MISSILES)) {
        secondaryWeaponType = SECONDARY_WEAPON_SEEKER_CLUSTER_MISSILES;
    }
    return secondaryWeaponType;
}

s32 hasKasanMoorDefected(u8 levelId) {
    return levelId < LEVEL_JADEMOON ? 4 : 5;
}

u8 runHangarMenuFromOverlay(struct GameSettings *arg0, u8 arg1, s32 arg2) {
    u8 temp;
    s32 temp_v0;

    hangarInitialize(temp = arg1, dDefaultCraftForLevel[arg2], getAvailablePlayerCraftFlagsConsiderUnlocks(arg2), arg2);
    do {
        temp_v0 = runHangarSelectionFrame(arg2);
    } while (temp_v0 == 0xFFFFFF);
    gracefulMenuShutdown();
    if (temp_v0 != 0xFFFFFE) {
        temp = temp_v0;
        arg0->vehicleId = temp;
        return 1;
    }
    return 0;
}

u8 getLevelIntroCrawlId(u8 levelId) {
    switch (levelId) {
        case LEVEL_MOSEISLEY:
            return 0;
            break;
        case LEVEL_JADEMOON:
            return 1;
            break;
        case LEVEL_TALORAAN:
            return 2;
            break;
        case LEVEL_CALAMARI:
            return 3;
            break;
        default:
            return 0xFF;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", fake_func_800C6968);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", junk_800A76D4);
