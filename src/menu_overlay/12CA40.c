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

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", getAvailablePlayerCraftFlagsConsiderUnlocks);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", getAvailablePlayerCraftFlagsIgnoreUnlocks);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", unlockLevelsAndCraftsBasedOnMedalsEarned);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", func_menu_overlay_800C6660);

s32 getLevelHardwiredDifficulty(u8 levelId) {
    return 0;
}

#if 0
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
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/12CA40", getSecondaryWeaponForLevelAndCraft);
#endif

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
