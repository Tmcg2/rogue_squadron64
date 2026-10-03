#include "common.h"
#include "common_types.h"

#include "PR/os.h"

#include "hud.h"
#include "textures.h"

#include "main/02420.h"
#include "main/08120.h"
#include "main/1EE30.h"
#include "main/55AF0.h"
#include "main/64EA0.h"
#include "menu_overlay/115E00.h"
#include "menu_overlay/12CA40.h"

// Interim BSS externs
extern struct ui_element bridgeShipBlueprints[9];
extern u16 bridgeShipBlueprintTextureIds[8]; // This would make it undersized by 1, what gives?
extern struct xy_offset D_menu_overlay_800CDF80[9];

struct rgba bridgeYellowColor = {
    0xE1, 0xAF, 0x00, 0xFF
};
struct rgba bridgeWhiteColor = {
    0xD7, 0xD8, 0xD7, 0xFF
};
struct rgba bridgeGreenColor = {
    0x91, 0xFF, 0x91, 0x00
};
struct rgba bridgeRedColor = {
    0xFF, 0x6E, 0x6E, 0x00
};

s32 D_menu_overlay_800CC700 = -1;

f32 bridgeShipBlueprintWidthScales[9] = {
    1.0f, 1.0f, 0.9f,
    1.1f, 0.9f, 1.1f,
    0.9f, 1.0f, 1.0f,
};
f32 bridgeShipBlueprintHeightScales[9] = {
    1.0f, 1.0f, 0.9f,
    0.9f, 0.9f, 1.1f,
    0.7f, 0.9f, 1.0f,
};

struct xy_offset bridgeShipBlueprintScreenPositions[8][8] = {
    {{   0, -16}, {  0,   0}, {   0,   0}, {   0,   0}, {   0,  0}, {  0,  0}, {  0,  0}, {  0,  0}},
    {{   0, -64}, {  0,  64}, {   0,   0}, {   0,   0}, {   0,  0}, {  0,  0}, {  0,  0}, {  0,  0}},
    {{   0, -64}, {-64,  64}, {  64,  64}, {   0,   0}, {   0,  0}, {  0,  0}, {  0,  0}, {  0,  0}},
    {{ -64, -64}, { 64, -64}, { -64,  64}, {  64,  64}, {   0,  0}, {  0,  0}, {  0,  0}, {  0,  0}},
    {{ -64, -64}, { 64, -64}, {-128,  64}, {   0,  64}, { 128, 64}, {  0,  0}, {  0,  0}, {  0,  0}},
    {{-128, -64}, {  0, -64}, { 128, -64}, {-128,  64}, {   0, 64}, {128, 64}, {  0,  0}, {  0,  0}},
    {{-128, -64}, {  0, -64}, { 128, -64}, {-192,  64}, { -64, 64}, { 64, 64}, {192, 64}, {  0,  0}},
    {{-192, -64}, {-64, -64}, {  64, -64}, { 192, -64}, {-192, 64}, {-64, 64}, { 64, 64}, {192, 64}},
};

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_pad_115E00 = 0x27C30020;

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", initCraftSelectScreen);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58BC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58C4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58C8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58CC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58D0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58D4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58D8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58DC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58E0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58E4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58E8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58EC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58F0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58F4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A58F8);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", tickCraftSelectScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", handleCraftSelectInput);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A5994);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", bridgeOuterBlueLightPositions);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A59C4);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", spawnOrientedEffectWithEasedSpin);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", handleLevelSelectStartConfirm);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", tickMenuTransitionState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", runScriptedCraftCinematicEvent);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", initMenuWidgetArray);

void bridgeLoadShipBlueprints(struct some_ui_list_root *arg0) {
    char sp10[0x20];
    char *bridgeShipBlueprintNames[9] = {
        "xwing",
        "ywing",
        "awing",
        "vwing",
        "speeder",
        "falcon",
        "interceptor",
        "t16",
        "xwing",
    };
    struct material_entry sp58;
    u32 var_s4;
    struct full_image_header *temp_v0;
    struct texture_entry *temp_s0;

    for (var_s4 = 0; var_s4 < 9; var_s4++) {
        sprintf(sp10, "blueprints/%s", bridgeShipBlueprintNames[var_s4]);
        temp_v0 = load_asset(sp10);
        temp_s0 = &temp_v0->ent;
        full_header_image_offset_convert(temp_s0, (u32)temp_s0);
        sp58.material_type = 1;
        rs_strcpy(sp58.material_name, (u8 *) temp_s0->texture_name_offset);
        temp_s0->flags_type = 0x2004;
        bridgeShipBlueprintTextureIds[var_s4] = registerHmtTextureInTable(&sp58, temp_s0, 1U);
        rs_memset(&bridgeShipBlueprints[var_s4], 0U, 0x30U);
        bridgeShipBlueprints[var_s4].texture_id_pointer = &bridgeShipBlueprintTextureIds[var_s4];
        bridgeShipBlueprints[var_s4].unknown0A = 1;
        bridgeShipBlueprints[var_s4].texture_count = 1;
        bridgeShipBlueprints[var_s4].width_scale = bridgeShipBlueprintWidthScales[var_s4];
        bridgeShipBlueprints[var_s4].height_scale = bridgeShipBlueprintHeightScales[var_s4];
        bridgeShipBlueprints[var_s4].flags = 3;
        bridgeShipBlueprints[var_s4].rgba.r = 0;
        bridgeShipBlueprints[var_s4].rgba.g = 0;
        bridgeShipBlueprints[var_s4].rgba.b = 0;
        bridgeShipBlueprints[var_s4].rgba.a = 0xFF;
        insertLookupEntry(arg0, &bridgeShipBlueprints[var_s4], 0xAU);
        rs_free(temp_v0);
    }
}

#if 0
// Really close, permuter hasn't turned anything up yet
// Functionally identical though, which is a good sign
// https://decomp.me/scratch/mkgBu
void layoutMenuTextRow(struct some_ui_list_root *arg0, u8 arg1) {
    f32 temp_fv0;
    s32 temp_s4;
    s32 temp_s6;
    s32 var_v1;
    u32 var_s0;

    temp_s6 = getAvailablePlayerCraftFlagsConsiderUnlocks(arg1);
    temp_s4 = getAvailablePlayerCraftFlagsIgnoreUnlocks(arg1);
    var_v1 = 0;
    for (var_s0 = 0; var_s0 < 9; var_s0++) {
        if (temp_s4 & (1 << var_s0)) var_v1++;
    }
    for (var_s0 = 0; var_s0 < 9; var_s0++) {
        if (temp_s4 & (1 << var_s0)) {
            temp_fv0 = (((bridgeShipBlueprintScreenPositions[var_v1 - 1][var_s0].x / 1.5f) - 32.0f) * 512.0f) / 512.0f;
            bridgeShipBlueprints[var_s0].xpos = temp_fv0;
            D_menu_overlay_800CDF80[var_s0].x = temp_fv0;
            temp_fv0 = (((bridgeShipBlueprintScreenPositions[var_v1 - 1][var_s0].y / 1.1f) - 75.0f) * 340.0f) / 340.0f;
            bridgeShipBlueprints[var_s0].ypos = temp_fv0;
            D_menu_overlay_800CDF80[var_s0].y = temp_fv0;
        }
        if (temp_s6 & (1 << var_s0)) {
            bridgeShipBlueprints[var_s0].rgba = bridgeGreenColor;
        } else {
            bridgeShipBlueprints[var_s0].rgba = bridgeRedColor;
        }
        setLookupEntryField5ByKey(arg0, &bridgeShipBlueprints[var_s0], (temp_s4 & (1 << var_s0)) != 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", layoutMenuTextRow);
#endif

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A5BA4);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", printLevelSelectWeaponText);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", startSlotLoopAnimWithVoiceSync);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", setupPlayerCraftDisplayAnim);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", applyPlayerSlotAnimChannelKeyframe);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", drainAudioAndFinalizeSpeechBuffer);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", tickTimedScreenFadeFloat);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", playExitSoundAndToggleScreenMeshes);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", fake_func_800B2628);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A5C18);
