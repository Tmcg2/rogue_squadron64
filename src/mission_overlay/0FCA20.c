#include "common.h"

#include "crafts.h"
#include "game_settings.h"
#include "hud.h"
#include "mission_state.h"
#include "secondary_weapons.h"

#include "main/1EE30.h"
#include "main/3F160.h"
#include "main/55AF0.h"
#include "main/6C310.h"
#include "main/832A0.h"
#include "main/98960.h"
#include "mission_overlay/0B4EC0.h"
#include "mission_overlay/0FAE50.h"
#include "mission_overlay/0FCA20.h"

static struct hud_struct D_mission_overlay_8010CA30[2];

// Interim Data externs
extern char *D_mission_overlay_8010B424[];

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90B0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90C0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90D0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90DC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90E8);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90F4);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9100);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A910C);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9118);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9124);

#if 0
// https://decomp.me/scratch/60pp0
u8 configurePlayerSecondaryWeaponHud(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    u32 var_s1;
    struct hud_struct *temp_s0;
    struct ui_element *temp_a1;

    temp_s0 = &D_mission_overlay_8010CA30[arg0];
    temp_s0->secondaryWeapon = arg1;
    temp_s0->secondaryWeaponCount = arg2;
    temp_s0->secondaryWeaponReset = arg2;
    temp_s0->secondaryWeaponIsAdvanced = arg3;
    temp_s0->crosshairOnOff = (gGameSettings.unlockAndSettingsFlags[0] >> 7) & 1;
    temp_s0->unknown006 = (D_mission_overlay_8010CA1C >> 0xA) & 1;

    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        temp_s0->texture_ids[var_s1] = loadAndRelocateAsset(D_mission_overlay_8010B424[var_s1], 0, 0x2000);
    }

    temp_s0->outerCrosshairRingElement.texture_count = 1;
    temp_s0->outerCrosshairRingElement.unknown0A = 1;
    temp_s0->outerCrosshairRingElement.flags = 3;
    temp_s0->outerCrosshairRingElement.zero = 0.0f;
    temp_s0->outerCrosshairRingElement.texture_id_pointer = &temp_s0->texture_ids[0];

    temp_s0->innerCrosshairRingElement = temp_s0->outerCrosshairRingElement;
    temp_s0->innerCrosshairRingElement.texture_id_pointer = &temp_s0->texture_ids[1];

    temp_s0->seekerCrosshairRing1Element = temp_s0->outerCrosshairRingElement;
    temp_s0->seekerCrosshairRing1Element.texture_id_pointer = &temp_s0->texture_ids[8];
    temp_s0->seekerCrosshairRing1Element.rgba.r = 0xFF;
    temp_s0->seekerCrosshairRing1Element.rgba.g = 0xD2;
    temp_s0->seekerCrosshairRing1Element.rgba.b = 0;

    temp_s0->seekerCrosshairRing2Element = temp_s0->seekerCrosshairRing1Element;
    temp_s0->seekerCrosshairRing2Element.texture_id_pointer = &temp_s0->texture_ids[9];

    temp_s0->bombCrosshairRingElement.texture_count = 1;
    temp_s0->bombCrosshairRingElement.unknown0A = 1;
    temp_s0->bombCrosshairRingElement.flags = 3;
    temp_s0->bombCrosshairRingElement.zero = 0.0f;
    temp_s0->bombCrosshairRingElement.rgba.r = 0xFF;
    temp_s0->bombCrosshairRingElement.rgba.g = 0xD2;
    temp_s0->bombCrosshairRingElement.rgba.b = 0;
    temp_s0->bombCrosshairRingElement.texture_id_pointer = &temp_s0->texture_ids[2];

    // There's a mismatch around the accessing of `hud_elements` here.
    // What currently written is functionally equivalent, but the exact offsets
    // chosen by the compiler for various pointer accesses are different.
    for (var_s1 = 0; var_s1 < 5; var_s1++) {
        temp_a1 = &temp_s0->hud_elements[var_s1];
        temp_a1->texture_count = 1;
        temp_a1->unknown0A = 1;
        temp_a1->zero = 0.0f;
        temp_a1->flags = 3;
        temp_a1->rgba.r = 0xFF;
        temp_a1->rgba.g = 0;
        temp_a1->rgba.b = 0;
        temp_a1->rgba.a = 0xBE;
        temp_a1->texture_id_pointer = &temp_s0->texture_ids[3 + var_s1];
    }

    switch (temp_s0->secondaryWeapon) {
        case SECONDARY_WEAPON_SEEKER_MISSILES:
        case SECONDARY_WEAPON_SEEKER_TORPEDOS:
            temp_s0->secondaryWeaponState = 0;
            temp_s0->unk210 = 0;
            temp_s0->unk211 = 0;
            break;
        case SECONDARY_WEAPON_ION_CANNON:
        case SECONDARY_WEAPON_MISSLES:
        case SECONDARY_WEAPON_BOMBS:
        case SECONDARY_WEAPON_PROTON_TORPEDOS:
            temp_s0->secondaryWeaponState = 0;
            break;
    }

    if ((getPlayerVehicleId(0) == CRAFT_XWING) && !(isWeaponSlotReady(0))) {
        temp_s0->alpha_scaling = 0.0f;
    } else {
        temp_s0->alpha_scaling = 1.0f;
    }

    for (var_s1 = 0; var_s1 < 2; var_s1++) {
        D_mission_overlay_8010CA30[var_s1].unk274 = 0;
    }

    return temp_s0->secondaryWeapon;
}
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", configurePlayerSecondaryWeaponHud);
#endif

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", resetHudInstancesAndUnbindNpcs);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", findNearestTargetableNpcInRange);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", projectForwardTerrainImpactPoint);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", tickHudInstanceTargetingAndSpawns);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", updatePlayerHudFrame);

void teardownHudInstancesAndUnbindNpcs(void) {
    struct factor5_list_node *var_s1_2;
    struct hud_struct *var_s0;
    struct hud_struct *var_s0_2;
    u16 temp_a0;
    u32 var_s1;
    u8 temp_v0;

    for (var_s1 = 0; var_s1 < 10;  var_s1++) {
        releaseTextureLutEntry(D_mission_overlay_8010CA30[0].texture_ids[var_s1]);
    }
    for (var_s1 = 0; var_s1 < 2;  var_s1++) {
        if (((D_mission_overlay_8010CA30[var_s1].secondaryWeapon == SECONDARY_WEAPON_SEEKER_MISSILES)
            || (D_mission_overlay_8010CA30[var_s1].secondaryWeapon == SECONDARY_WEAPON_SEEKER_TORPEDOS))
            && (D_mission_overlay_8010CA30[var_s1].unk210 != 0)) {
            destroyNpcSlotChain(D_mission_overlay_8010CA30[var_s1].unk212);
        }
        if (D_mission_overlay_8010CA30[var_s1].unk274 != 0) {
            factor5RemoveListNode(&D_mission_overlay_8010CA30[var_s1].node);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", dispatchHudInstanceWeaponEffect);

u8 refreshPlayerSecondaryWeaponHud(u8 arg0) {
    s32 isAdvanced;

    if (arg0 == SECONDARY_WEAPON_UNUSED) {
        switch (gMissionState.secondaryWeapon) {
            case SECONDARY_WEAPON_MISSLES:
            case SECONDARY_WEAPON_SEEKER_MISSILES:
                isAdvanced = (gGameSettings.unlockAndSettingsFlags[0] >> 0xA) & 1;
                break;
            case SECONDARY_WEAPON_PROTON_TORPEDOS:
            case SECONDARY_WEAPON_SEEKER_TORPEDOS:
                isAdvanced = (gGameSettings.unlockAndSettingsFlags[0] >> 0xC) & 1;
                break;
            case SECONDARY_WEAPON_BOMBS:
                isAdvanced = (gGameSettings.unlockAndSettingsFlags[0] >> 0xF) & 1;
                break;
            default:
                isAdvanced = 0;
                break;
        }
    } else {
        isAdvanced = 0;
    }
    return configurePlayerSecondaryWeaponHud(arg0, gMissionState.secondaryWeapon, gMissionState.secondaryWeaponMax, isAdvanced);
}

void resetTransientPlayerStateFlags(void) {
    u8 var_s1;
    struct hud_struct *temp_s0;

    for (var_s1 = 0; var_s1 < 2;  var_s1++) {
        temp_s0 = &D_mission_overlay_8010CA30[var_s1];
        switch (temp_s0->secondaryWeapon) {
        case SECONDARY_WEAPON_SEEKER_MISSILES:
        case SECONDARY_WEAPON_SEEKER_TORPEDOS:
            temp_s0->secondaryWeaponState = 0;
            temp_s0->unk210 = 0;
            temp_s0->unk211 = 0;
            break;
        case SECONDARY_WEAPON_ION_CANNON:
        case SECONDARY_WEAPON_MISSLES:
        case SECONDARY_WEAPON_BOMBS:
        case SECONDARY_WEAPON_PROTON_TORPEDOS:
            temp_s0->secondaryWeaponState = 0;
            break;
        }
        if (getPlayerVehicleId(0) != CRAFT_XWING) {
            temp_s0->alpha_scaling = 1.0f;
        } else if (!isWeaponSlotReady(0U)) {
            temp_s0->alpha_scaling = 0.0f;
        } else {
            temp_s0->alpha_scaling = 1.0f;
        }
    }
}

void resetSecondaryWeaponCount(void) {
    u8 var_a0;

    for (var_a0 = 0; var_a0 < 2; var_a0++) {
        D_mission_overlay_8010CA30[var_a0].secondaryWeaponCount = D_mission_overlay_8010CA30[var_a0].secondaryWeaponReset;
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", getActiveHudInstanceTargetPosition);

s32 isHudSecondaryWeaponActive(void) {
    s32 var_a0;

    var_a0 = 0;
    if (D_mission_overlay_8010CA30[0].secondaryWeapon == SECONDARY_WEAPON_BOMBS) {
        var_a0 = D_mission_overlay_8010CA30[0].secondaryWeaponState > 0U;
    }
    return var_a0;
}

u8 getHudSecondaryWeponCount(void) {
    return D_mission_overlay_8010CA30[0].secondaryWeaponCount;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", fake_func_800FEF04);

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_0FCA20[] = {
    0x00000000,
    0x8FC20024,
};
