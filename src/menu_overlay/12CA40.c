#include "common.h"
#include "common_types.h"
#include "common_variables.h"

#include "menu_overlay/12CA40.h"

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C58A0);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C5D9C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuALPHA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuBETA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuGAMMA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuDELTA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", D_menu_overlay_800A760C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuINTRO);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuEXTRO);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", strMenuSPECIAL);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", D_menu_overlay_800A7644);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C5EF8);

s32 getAvailablePlayerCraftFlagsConsiderUnlocks(enum Level levelId) {
    s32 availableCraftFlags;

    availableCraftFlags = CRAFT_FLAG(dDefaultCraftForLevel[levelId]);
    if ((gMissionState.maxUnlockedLevel >= JADEMOON_LEVEL) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(AWING_CRAFT);
    }
    if ((gMissionState.maxUnlockedLevel >= TALORAAN_LEVEL) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(VWING_CRAFT);
    }
    if ((gMissionState.maxUnlockedLevel >= CALAMARI_LEVEL) && (levelId < gMissionState.maxUnlockedLevel) && (availableCraftFlags & 0xD)) {
        availableCraftFlags |= CRAFT_FLAG(XWING_CRAFT);
    }
    if (gGameSettings.unlockAndSettingsFlags[0] & 0x80000) {
        availableCraftFlags |= 0x7F;
    }
    if ((gGameSettings.cheatCodeFlags[0] & 4) || (gGameSettings.unlockAndSettingsFlags[0] & 0x20000)) {
        availableCraftFlags |= CRAFT_FLAG(FALCON_CRAFT);
    }
    if ((gGameSettings.cheatCodeFlags[0] & 8) || (gGameSettings.unlockAndSettingsFlags[0] & 0x40000)) {
        availableCraftFlags |= CRAFT_FLAG(TIEINTER_CRAFT);
    }
    if (levelId == TALORAAN_LEVEL) {
        availableCraftFlags &= ~CRAFT_FLAG(VWING_CRAFT);
        availableCraftFlags &= ~CRAFT_FLAG(SNOWSPEEDER_CRAFT);
    }
    if (levelId == TRENCH_RUN_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(XWING_CRAFT);
    }
    if (levelId == KESSEL_RESCUE_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(XWING_CRAFT) | CRAFT_FLAG(YWING_CRAFT);
    }
    if ((levelId == CORELLIA_LEVEL) || (levelId == CONST_YARD_LEVEL) || (levelId == FEST_LEVEL) || (levelId == HOTH_LEVEL)) {
        availableCraftFlags &= CRAFT_FLAG(SNOWSPEEDER_CRAFT);
    }
    if (levelId == BEGGARS_CANYON_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(T16_CRAFT);
    }
    return availableCraftFlags;
}

s32 getAvailablePlayerCraftFlagsIgnoreUnlocks(enum Level levelId) {
    s32 availableCraftFlags;

    availableCraftFlags = CRAFT_FLAG(dDefaultCraftForLevel[levelId]);
    if (availableCraftFlags & 0xD) {
        availableCraftFlags |= CRAFT_FLAG(XWING_CRAFT) | CRAFT_FLAG(AWING_CRAFT) | CRAFT_FLAG(VWING_CRAFT);
    }
    if (gGameSettings.unlockAndSettingsFlags[0] & 0x80000) {
        availableCraftFlags |= 0x7F;
    }
    if ((gGameSettings.cheatCodeFlags[0] & 4) || (gGameSettings.unlockAndSettingsFlags[0] & 0x20000)) {
        availableCraftFlags |= CRAFT_FLAG(FALCON_CRAFT);
    }
    if ((gGameSettings.cheatCodeFlags[0] & 8) || (gGameSettings.unlockAndSettingsFlags[0] & 0x40000)) {
        availableCraftFlags |= CRAFT_FLAG(TIEINTER_CRAFT);
    }
    if (levelId == TALORAAN_LEVEL) {
        availableCraftFlags &= ~CRAFT_FLAG(VWING_CRAFT);
        availableCraftFlags &= ~CRAFT_FLAG(SNOWSPEEDER_CRAFT);
    }
    if (levelId == TRENCH_RUN_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(XWING_CRAFT);
    }
    if (levelId == KESSEL_RESCUE_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(XWING_CRAFT) | CRAFT_FLAG(YWING_CRAFT);
    }
    if ((levelId == CORELLIA_LEVEL) || (levelId == CONST_YARD_LEVEL) || (levelId == FEST_LEVEL) || (levelId == HOTH_LEVEL)) {
        availableCraftFlags &= CRAFT_FLAG(SNOWSPEEDER_CRAFT);
    }
    if (levelId == BEGGARS_CANYON_LEVEL) {
        availableCraftFlags &= CRAFT_FLAG(T16_CRAFT);
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
    for (var_a1 = 0; var_a1 < BEGGARS_CANYON_LEVEL; var_a1++) {
        temp_v1 = medalsPerLevel[var_a1];
        if (temp_v1 < GOLD) {
            normalAllGold = 0;
        }
        if (temp_v1 < SILVER) {
            normalAllSilver = 0;
        }
        if (temp_v1 < BRONZE) {
            normalAllBronze = 0;
        }
    }
    if (normalAllBronze == 1) {
        if (!(gGameSettings.unlockAndSettingsFlags[0] & 0x100000)) {
            anyLevelsUnlocked = 1;
        }
        gGameSettings.unlockAndSettingsFlags[0] |= 0x100000;
    }
    if (normalAllSilver == 1) {
        if (!(gGameSettings.unlockAndSettingsFlags[0] & 0x200000)) {
            anyLevelsUnlocked = 1;
        }
        gGameSettings.unlockAndSettingsFlags[0] |= 0x200000;
    }
    if (normalAllGold == 1) {
        if (!(gGameSettings.unlockAndSettingsFlags[0] & 0x400000)) {
            anyLevelsUnlocked = 1;
        }
        gGameSettings.unlockAndSettingsFlags[0] |= 0x400000;
    }
    gMissionState.anyExtraLevelsUnlocked = anyLevelsUnlocked;
    unlockableAllBronze = 1;
    unlockableAllSilver = 1;
    unlockableAllGold   = 1;
    // Check the medals for all unlockable levels
    for (var_a1 = BEGGARS_CANYON_LEVEL; var_a1 < NUM_LEVELS; var_a1++) {
        temp_v1 = medalsPerLevel[var_a1];
        if (temp_v1 < GOLD) {
            unlockableAllGold = 0;
        }
        if (temp_v1 < SILVER) {
            unlockableAllSilver = 0;
        }
        if (temp_v1 < BRONZE) {
            unlockableAllBronze = 0;
        }
    }
    if (unlockableAllBronze == 1) {
        gGameSettings.unlockAndSettingsFlags[0] |= 0x20000;
    }
    if (unlockableAllSilver == 1) {
        gGameSettings.unlockAndSettingsFlags[0] |= 0x40000;
    }
    if (unlockableAllGold == 1) {
        gGameSettings.unlockAndSettingsFlags[0] |= 0x80000;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C6660);

s32 getLevelHardwiredDifficulty(u8 levelId) {
    return 0;
}

u8 getSecondaryWeaponForLevelAndCraft(u8 levelId, u8 craftId, u8 arg2) {
    s32 secondaryWeaponType;

    secondaryWeaponType = NONE;
    switch (craftId) {
    case XWING_CRAFT:
        secondaryWeaponType = PROTON_TORPEDOS;
        break;
    case YWING_CRAFT:
        secondaryWeaponType = BOMBS;
        break;
    case AWING_CRAFT:
        secondaryWeaponType = MISSLES;
        break;
    case VWING_CRAFT:
        secondaryWeaponType = CLUSTER_MISSILES;
        break;
    case SNOWSPEEDER_CRAFT:
        secondaryWeaponType = TOW_CABLE;
        break;
    case TIEINTER_CRAFT:
    case T16_CRAFT:
        secondaryWeaponType = NONE;
        break;
    case FALCON_CRAFT:
    case KOELSCH_CRAFT:
        secondaryWeaponType = SEEKER_TORPEDOS;
        break;
    }
    if (levelId == KESSEL_RESCUE_LEVEL) {
        if (craftId == XWING_CRAFT) {
            secondaryWeaponType = ION_CANNON;
        }
    }
    if ((secondaryWeaponType == MISSLES) && (gGameSettings.unlockAndSettingsFlags[arg2] & 0x800)) {
        secondaryWeaponType = SEEKER_MISSILES;
    }
    if ((secondaryWeaponType == PROTON_TORPEDOS) && (gGameSettings.unlockAndSettingsFlags[arg2] & 0x2000)) {
        secondaryWeaponType = SEEKER_TORPEDOS;
    }
    if ((secondaryWeaponType == CLUSTER_MISSILES) && (gGameSettings.unlockAndSettingsFlags[arg2] & 0x4000)) {
        secondaryWeaponType = SEEKER_CLUSTER_MISSILES;
    }
    return secondaryWeaponType;
}

s32 hasKasanMoorDefected(u8 levelId) {
    return levelId < JADEMOON_LEVEL ? 4 : 5;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C6854);

u8 getLevelIntroCrawlId(u8 levelId) {
    switch (levelId) {
        case MOSEISLEY_LEVEL:
            return 0;
            break;
        case JADEMOON_LEVEL:
            return 1;
            break;
        case TALORAAN_LEVEL:
            return 2;
            break;
        case CALAMARI_LEVEL:
            return 3;
            break;
        default:
            return 0xFF;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", fake_func_800C6968);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/12CA40", junk_800A76D4);
