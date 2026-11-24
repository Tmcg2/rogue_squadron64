#include "common.h"
#include "common_types.h"

#include "PR/os.h"

#include "game_settings.h"
#include "hud.h"
#include "textures.h"

#include "main/02420.h"
#include "main/08120.h"
#include "main/1EE30.h"
#include "main/55AF0.h"
#include "main/562A0.h"
#include "main/61FC0.h"
#include "main/64EA0.h"
#include "main/67690.h"
#include "main/84830.h"
#include "menu_overlay/115E00.h"
#include "menu_overlay/1197D0.h"
#include "menu_overlay/12CA40.h"

// Interim BSS externs
extern u8 D_menu_overlay_800CDC80[0x5C]; // This is really a struct of some kind, until I actually need its internal for match I'm going to leave it as an array
extern struct ui_element bridgeShipBlueprints[9];
extern u16 bridgeShipBlueprintTextureIds[8]; // This would make it undersized by 1, what gives?
extern struct xy_offset D_menu_overlay_800CDF80[9];
extern struct some_ui_list_root *D_menu_overlay_800CDCDC;
extern struct bridge_mini_hob bridgeBlueLightHobs[7];

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

void initMenuWidgetArray(void) {
    u32 var_a1;
    u32 var_s1;
    Vec3f *temp_v0;
    struct bridge_mini_hob *var_s0;

    for (var_s1 = 0; var_s1 < 7; var_s1++) {
        var_s0 = &bridgeBlueLightHobs[var_s1];
        var_s0->mini_meshdef1.unk0C = 0x09000009;
        var_s0->mini_meshdef0.next_meshdef0_pointer = \
        var_s0->mini_meshdef0.prev_meshdef0_pointer = \
        var_s0->mini_meshdef0.unknown_meshdef0_pointer0 = \
        var_s0->mini_meshdef0.unknown_meshdef0_pointer1 = NULL;
        var_s0->mini_meshdef0.meshdef1_pointer = &var_s0->mini_meshdef1;
        var_s0->mini_meshdef1.vertex_counts[0] = 3;
        var_s0->mini_meshdef0.two_floats[0] = 0.0f;
        var_s0->mini_meshdef1.prev_meshdef1_pointer = NULL;
        var_s0->mini_meshdef1.next_meshdef1_pointer = NULL;
        var_s0->mini_meshdef1.facegroup_pointer = &var_s0->facegroup;
        var_s0->mini_meshdef1.unk08 = 0;
        var_s0->mini_meshdef1.some_float = 0.0f;
        var_s0->mini_meshdef1.unk10 = 0;
        var_s0->mini_meshdef1.vertex_counts[1] = 0;
        var_s0->mini_meshdef1.vertex_pointers[0] = var_s0->vertices;
        var_s0->mini_meshdef1.vertex_pointers[1] = NULL;
        clearStructPair2C30(&var_s0->mini_meshdef1);
        var_s0->facegroup.face_offset = (struct face *) &var_s0->face;
        var_s0->face.flags = 0x10;
        var_s0->facegroup.prev_facegroup = NULL;
        var_s0->facegroup.next_facegroup = NULL;
        var_s0->facegroup.face_count = 1;
        var_s0->face.stuffed_data = 0x080C5000;
        var_s0->face.material_index = 0;
        var_s0->face.flags |= 0x82;
        var_s0->face.material_index = 0;
        for (var_a1 = 0; var_a1 < 3; var_a1++) {
            var_s0->face.vertex_indices[var_a1] = var_a1;
        }
        if (var_s1 == 0) {
            var_s0->face.vertex_colors[0].r = 0xB4;
            var_s0->face.vertex_colors[0].g = 0xB4;
            var_s0->face.vertex_colors[0].b = 0xF5;
            var_s0->face.vertex_colors[0].a = 0;
            var_s0->face.vertex_colors[1].r = 0xB4;
            var_s0->face.vertex_colors[1].g = 0xB4;
            var_s0->face.vertex_colors[1].b = 0xF5;
            var_s0->face.vertex_colors[1].a = 0;
            var_s0->face.vertex_colors[2].r = 0;
            var_s0->face.vertex_colors[2].g = 0;
            var_s0->face.vertex_colors[2].b = 0xA0;
            var_s0->face.vertex_colors[2].a = 0;
        } else {
            if (var_s1 < 4U) {
                var_s0->face.vertex_colors[0].r = 0xFF;
                var_s0->face.vertex_colors[0].g = 0xFF;
                var_s0->face.vertex_colors[0].b = 0xFF;
                var_s0->face.vertex_colors[0].a = 0;
                var_s0->face.vertex_colors[1].r = 0xFF;
                var_s0->face.vertex_colors[1].g = 0xFF;
                var_s0->face.vertex_colors[1].b = 0xFF;
                var_s0->face.vertex_colors[1].a = 0;
                var_s0->face.vertex_colors[2].r = 0x50;
                var_s0->face.vertex_colors[2].g = 0x50;
                var_s0->face.vertex_colors[2].b = 0xFF;
                var_s0->face.vertex_colors[2].a = 0xC8;
            } else {
                var_s0->face.vertex_colors[0].r = 0;
                var_s0->face.vertex_colors[0].g = 0;
                var_s0->face.vertex_colors[0].b = 0x37;
                var_s0->face.vertex_colors[0].a = 0;
                var_s0->face.vertex_colors[1].r = 0;
                var_s0->face.vertex_colors[1].g = 0;
                var_s0->face.vertex_colors[1].b = 0x37;
                var_s0->face.vertex_colors[1].a = 0;
                var_s0->face.vertex_colors[2].r = 0x1E;
                var_s0->face.vertex_colors[2].g = 0x1E;
                var_s0->face.vertex_colors[2].b = 0xE1;
                var_s0->face.vertex_colors[2].a = 0x9B;
            }
        }
        temp_v0 = var_s0->mini_meshdef1.vertex_pointers[0];
        temp_v0[0][0] = 1.0f;
        temp_v0[0][1] = -2.0f;
        temp_v0[0][2] = 0;
        temp_v0[1][0] = -1.0f;
        temp_v0[1][1] = -2.0f;
        temp_v0[1][2] = 0;
        temp_v0[2][0] = 0;
        temp_v0[2][1] = 0;
        temp_v0[2][2] = 0;
    }
}

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

void printLevelSelectWeaponText(u8 arg0) {
    char sp20[0x100];
    u16 var_v1_2;
    s32 temp_a0;
    s32 var_s1;
    u8 var_v1;
    char *temp_s3;
    char *temp_s4;
    char *temp_s5;
    char *var_s0;
    char *var_s2;

    var_s1 = 0;
    temp_a0 = getAvailablePlayerCraftFlagsIgnoreUnlocks(arg0);
    for (var_v1 = 0; var_v1 < 9; var_v1++) {
        if (temp_a0 & (1 << var_v1)) {
            var_s1 += 1;
        }
    }
    temp_s5 = getGameOrFrontText(0x48);
    if (ADVANCED_BLASTERS_UNLOCKED) {
        var_s2 = getGameOrFrontText(0x4B);
    } else {
        var_s2 = "";
    }
    temp_s4 = getGameOrFrontText(0x4D);
    temp_s3 = getGameOrFrontText(0x4A);
    if (ADVANCED_SHIELD_UNLOCKED) {
        var_s0 = getGameOrFrontText(0x4B);
    } else {
        var_s0 = "";
    }
    sprintf(sp20, "%s%s%s\n%s%s%s", temp_s5, var_s2, temp_s4, temp_s3, var_s0, getGameOrFrontText(0x4C));
    if (var_s1 == 1) {
        var_v1_2 = -3;
    } else {
        var_v1_2 = -0x30;
    }
    setPlayerSlotAnimationFlag(2U, sp20, 1U, -0x100, var_v1_2);
    setPlayerSlotEntryRGB(2U, 1U, &bridgeWhiteColor);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", startSlotLoopAnimWithVoiceSync);

void setupPlayerCraftDisplayAnim(void) {
    u8 var_s2;

    setPlayerSlotAnimationFlag(0U, "XX", 6U, -0x100, 0x72);
    setPlayerSlotAnimationFlag(0U, "XX", 9U, -0x100, 0x72);
    samplePlayerAnimChannel(0U, 6U, 1.0f);
    samplePlayerAnimChannel(0U, 9U, 1.0f);
    relocateLookupEntryToNewKey(D_menu_overlay_800CDCDC, getPlayerSlotFieldAt34(0U, 6U), 0x19U);
    relocateLookupEntryToNewKey(D_menu_overlay_800CDCDC, getPlayerSlotFieldAt34(0U, 9U), 0x19U);
    setPlayerSlotAnimationFlag(0U, "{", 4U, -0x100, 0x76);
    setPlayerSlotAnimationFlag(0U, "{", 7U, -0x100, 0x76);
    setPlayerSlotAnimationFlag(0U, "}", 5U, -0x100, 0x76);
    setPlayerSlotAnimationFlag(0U, "}", 8U, -0x100, 0x76);
    for (var_s2 = 4; var_s2 < 0xA; var_s2++) {
        activateAnimationKeyframe(0U, var_s2, 0U);
        setPlayerSlotEntryRGB(0U, var_s2, &bridgeWhiteColor);
        samplePlayerAnimChannel(0U, var_s2, 1.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", applyPlayerSlotAnimChannelKeyframe);

void drainAudioAndFinalizeSpeechBuffer(void) {
    tickMusyXIfActive();
    do {

    } while (!(anyAudioSlotActive()));
    bufferArbiterProducerScanWait();
    destroyPlayerShipRecord(D_menu_overlay_800CDCDC, &D_menu_overlay_800CDC80);
    shutdownFormatMessageWorker();
    finalizeCurrentSpeechBuffer();
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", tickTimedScreenFadeFloat);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", playExitSoundAndToggleScreenMeshes);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/115E00", fake_func_800B2628);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/115E00", D_menu_overlay_800A5C18);
