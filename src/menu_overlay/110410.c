#include "common.h"

#include "PR/ultratypes.h"
#include "game_settings.h"
#include "secondary_weapons.h"
#include "textures.h"

#include "main/1EE30.h"
#include "main/55AF0.h"
#include "main/562A0.h"
#include "main/64EA0.h"
#include "main/6C310.h"
#include "menu_overlay/110410.h"
#include "menu_overlay/12CA40.h"

// Interim Data externs
extern u8 hangarActiveSecondaryWeaponString;

// Interim BSS externs
extern char hangarSecondaryWeaponStrings[4][0x30];
extern u8  D_menu_overlay_800CD520[0x20];
extern u8  D_menu_overlay_800CD6D0;

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", loadCutsceneAssetsByIndex);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A5130);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEDread);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A514C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECalamari);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEBacta);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEVolcano);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEChandrila);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEResearch);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuETaloraan);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKessel);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKile);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECon);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEJade);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKasan);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECorellia);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEChorax);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEBarkesh);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuETatooine);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarInitialize);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", runHangarSelectionFrame);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", composeNpcOrientationMatrix);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", updateHangarBayScene);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarTickCameraOrbit);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A5804);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarInitializeShipShadowHob);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", craftSelectionVoiceLineHelper);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", tickEasedCameraKeyframeBlend);

#if 0

/*
This function may prove to be a problem child.
The last format string in this function, "%s%s", is right before the bogus file padding.
While there is a way to get that bogus padding into the rodata section itself, there's 2 major problems.

1) For reasons I cannot comprehend, there's an extra 16 bytes of padding being added by the compiler.
2) Moving the string out of the function creates an unwinnable situation concerning bridgeSecondaryWeaponTextIds
2a) If the string and bridgeSecondaryWeaponTextIds are in the function, they will be appropriately ordered in the rodata section.
BUT the compiler will also add extraneous padding between them.
2b) If you pull the strings and bridgeSecondaryWeaponTextIds out of the function, the compiler will place them next to each other
as desired.
BUT, you then can't lose the memcpy like assignemt to bridgeSecondaryWeaponTextIds in the function body.

Because of this, this function may not be truly matchable.
If there was ever an indicator that I was using the wrong compiler for this project, this would be it.

Note that as currently writte the .text section for this matches 100%, its just the rodata handling that is screwy.
*/

// const u8 blah0[8] = {
//     "%s%s%s"
// };

// const u8 blah1[20] = {
//     "%s%s\x00\x04\x18\x80\x00\x62\x18\x21\x00\x03\x21\x00\x00\x82\x20\x21"
// };

char *hangarGenerateSecondaryWeaponString(enum Level level, enum PlayerCraft craft) {
    u16 bridgeSecondaryWeaponTextIds[10] = {
        0x0000, 0x004E, 0x0050, 0x0051, 0x0052, 0x0053, 0x004F, 0x0054, 0x0055, 0x0056
    };
    u8 isAdvanced;
    char *temp_s3;
    char *var_s1_2;
    u8 temp_s0;
    u8 temp_s2;
    u8 why;

    isAdvanced = 0;
    temp_s2 = hangarActiveSecondaryWeaponString;
    temp_s0 = getSecondaryWeaponForLevelAndCraft(level, craft, D_menu_overlay_800CD6D0);
    if (temp_s0 != SECONDARY_WEAPON_NONE) {
        why = temp_s0 - 2;
        if ((why < 2U) && (ADVANCED_MISSILES_UNLOCKED)) isAdvanced = 1;
        if ((temp_s0 == SECONDARY_WEAPON_BOMBS) && (ADVANCED_BOMBS_UNLOCKED)) isAdvanced = 1;
        if ((temp_s0 == SECONDARY_WEAPON_PROTON_TORPEDOS) && (ADVANCED_TORPEDOS_UNLOCKED)) isAdvanced = 1;
        temp_s0 = bridgeSecondaryWeaponTextIds[temp_s0];
        temp_s3 = getGameOrFrontText(0x49);
        if (isAdvanced) {
            var_s1_2 = getGameOrFrontText(0x4B);
        } else {
            var_s1_2 = "";
        }
        sprintf(hangarSecondaryWeaponStrings[temp_s2], "%s%s%s", temp_s3, var_s1_2, getGameOrFrontText(temp_s0));
    } else {
        sprintf(hangarSecondaryWeaponStrings[temp_s2], "%s%s", getGameOrFrontText(0x49), getGameOrFrontText(0x57));
    }
    hangarActiveSecondaryWeaponString++;
    hangarActiveSecondaryWeaponString &= 3; // the really ought to be %= 4, but that leads to a ton of intruction reordering
    return hangarSecondaryWeaponStrings[temp_s2];
}
#else

const u16 bridgeSecondaryWeaponTextIds[] = {
    0x0000, 0x004E, 0x0050, 0x0051, 0x0052, 0x0053, 0x004F, 0x0054, 0x0055, 0x0056
};

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarGenerateSecondaryWeaponString);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", gracefulMenuShutdown);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", extractTextBeforeFmtChar);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", composeInterpolatedNodeMatrices);

#if 0
/*
`D_menu_overlay_800A5804` is "pl_crafts/shadows_TM", but its placement in the file is a little odd.
I suspect this is tied to the oddities surrounding `hangarGenerateSecondaryWeaponString`.

I'm beginning to suspect that this file isn't match-able until the rodata weirdness is resolved

As currently written, the .text section of this function is 100% matching
*/
void hangarLoadShadows(void) {
    struct material_entry sp10;
    struct full_image_header *temp_s4;
    struct full_image_header *var_s1;
    s32 var_s2;
    s32 var_v1;

    temp_s4 = load_asset("pl_crafts/shadows_TM");
    for (var_s2 = 0; var_s2 < 14; var_s2++) {
        var_s1 = temp_s4;
        // I really, really do not like this loop. Its the wrong way to solve the problem
        for (var_v1 = 0; var_v1 < var_s2; var_v1++) {
            var_s1 = (struct full_image_header*)(((u32)var_s1 + var_s1->image_size + 7) & ~3);
        }
        full_header_image_offset_convert(&var_s1->ent, (u32)&var_s1->ent);
        var_s1->ent.flags_type |= 0x2000;
        sp10.material_type = 1;
        D_main_bss_8013A528[var_s2] = registerHmtTextureInTable(&sp10, &var_s1->ent, 1U);
    }
    rs_free(temp_s4);
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarLoadShadows);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", setByteAcrossEntryList);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", initCraftSelectVectors);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarSetSecondaryWeaponDisplay);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarUpdateSecWeaponIfChanged);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", fake_func_800AEC54);
