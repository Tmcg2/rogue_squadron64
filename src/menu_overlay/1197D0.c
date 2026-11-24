#include "common.h"

#include "compiler/gcc/string.h"

#include "game_config.h"

#include "main/02420.h"
#include "main/07800.h"
#include "main/08120.h"
#include "main/1A410.h"
#include "main/1EE30.h"
#include "main/64EA0.h"
#include "main/66660.h"
#include "menu_overlay/1197D0.h"

/*
BSS, for when matching it is possible
char D_menu_overlay_800CE6B0[0x40];
nonmatching D_menu_overlay_800CE6F0, 0x2
nonmatching D_menu_overlay_800CE6F2, 0x2
nonmatching D_menu_overlay_800CE6F4, 0xC
*/

// Interim BSS externs
extern char D_menu_overlay_800CE6B0[0x40];
extern u16 D_menu_overlay_800CE6F0;
extern u16 D_menu_overlay_800CE6F2;
extern f32 D_menu_overlay_800CE6F4;

u8  D_menu_overlay_800CC850 = 0;
u32 D_menu_overlay_800CC854 = 0x00000001;
OSId D_menu_overlay_800CC858 = 0xFFFFFFFF;
struct some_texture_context *D_menu_overlay_800CC85C = NULL;
u8  D_menu_overlay_800CC860 = 0;
struct some_texture_context *D_menu_overlay_800CC864 = NULL;
u32 data_junk_1197D0[] = {
    0x8FC200B4,
    0x27C30080,
};

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C20);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C2C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C34);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildFormatMessageGlyphBuffer);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C40);

struct some_texture_context *allocFormatTextElement(struct some_texture_context *arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5) {
    u16 temp_s2;
    u16 temp_s3;
    u16 temp_s4;
    struct ui_element *temp_s0;
    struct some_texture_context *why;
    struct some_texture_context *temp_v0;
    struct partial_image_header *temp_a0_2;

    temp_s2 = arg0->unk10->flags_type.as_u16;
    temp_s3 = arg0->width;
    temp_s4 = arg0->height;
    temp_v0 = rs_malloc(sizeof(struct some_texture_context), 0U);
    rs_memset(temp_v0, 0U, sizeof(struct some_texture_context));
    temp_v0->unk10 = rs_malloc(0x10U, 0U);
    rs_memset(temp_v0->unk10, 0U, 0x10U);
    temp_v0->unk10->flags_type.as_u16 = temp_s2;
    temp_v0->unk18 = D_menu_overlay_800CC850++;
    temp_v0->unk1C = arg3;
    temp_v0->width = temp_s3;
    temp_v0->height = temp_s4;
    D_menu_overlay_800CC850--;
    why = temp_v0;
    why->unk18 = arg0->unk18;
    why->unk10->image_pixel_width = arg1;
    why->unk10->image_pixel_height = arg2;
    why->unk34 = arg4;
    why->unk36 = arg5;
    switch (why->unk10->flags_type.as_u16) {
        case 2:
            why->unk04 = 4;
            break;
        case 3:
            why->unk04 = 8;
            break;
        case 4:
            why->unk04 = 1;
            break;
        case 5:
            why->unk04 = 2;
            break;
        
    }
    temp_a0_2 = why->unk10;
    why->unk08 = (((temp_a0_2->image_pixel_width + why->width) - 1) / why->width) * (((temp_a0_2->image_pixel_height + why->height) - 1) / why->height);
    why->unk14 = rs_malloc(why->unk08 * 2, 0U);
    why->unk0C = rs_malloc(sizeof(struct ui_element), 0U);
    rs_memset(why->unk0C, 0U, sizeof(struct ui_element));
    temp_s0 = why->unk0C;
    temp_s0->texture_id_pointer = rs_malloc(why->unk08 * 2, 0U);
    temp_s0->texture_count = arg1 / why->width;
    temp_s0->unknown0A = arg2 / why->height;
    temp_s0->width_scale = 1.0f;
    temp_s0->height_scale = 1.0f;
    temp_s0->rgba.r = 0xFF;
    temp_s0->rgba.g = 0xFF;
    temp_s0->rgba.b = 0xFF;
    temp_s0->rgba.a = 0xFF;
    return why;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", loadNamedTextureDescriptor);

#if 0
// .text matches, rodata shenanigans are putting damper on a proper match
struct some_texture_context *allocTextRenderTarget(s16 arg0, s16 arg1) {
    struct material_entry sp10 = {
        .material_type = 1,
        .texture_index = 0,
        .misc_float    = 1.0f,
        .one           = 1.0f,
        .zero          = 0.0f,
        .alwaysa       = 0,
        .pad           = {0},
        .material_name = "P____",
    };
    struct texture_entry sp38 = {
        .pixel_offsets       = {NULL},
        .plte_offset         = NULL,
        .texture_name_offset = "P____",
        .width               = 0,
        .height              = 0,
        .one                 = 1,
        .bit_depth           = 0,
        .flags_type          = 4,
        .transparency_color  = {0, 0, 0, 0},
    };
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s0;
    u16 temp_v0_4;
    u32 var_a1;
    struct ui_element_mk2 *why;
    struct some_texture_context *temp_v0;

    temp_v0 = rs_malloc(sizeof(struct some_texture_context), 0U);
    rs_memset(temp_v0, 0U, sizeof(struct some_texture_context));
    temp_v0->width = 0x40U;
    temp_v0->height = 0x10U;
    temp_lo = arg0 / temp_v0->width;
    temp_v0->unk08 = temp_lo;
    temp_lo_2 = temp_lo * (arg1 / temp_v0->height);
    temp_v0->unk08 = temp_lo_2;
    temp_v0->unk04 = 1U;
    temp_v0->unk14 = rs_malloc(temp_lo_2 * sizeof(u16), 0U);
    why = rs_malloc(sizeof(struct ui_element), 0U);
    temp_v0->unk0C = why;
    rs_memset(why, 0U, sizeof(struct ui_element));
    why->texture_id_pointer = rs_malloc(temp_v0->unk08 * sizeof(u16), 0U);
    temp_s0 = (temp_v0->width * temp_v0->height * temp_v0->unk04) / 2;
    sp38.width = temp_v0->width;
    sp38.height = temp_v0->height;
    sp38.one = 1;
    sp38.bit_depth = 0;
    sp38.pixel_offsets[0] = rs_malloc(temp_s0, 0U);
    rs_memset(sp38.pixel_offsets[0], 0xFF, temp_s0);
    sp38.texture_name_offset[1] = D_menu_overlay_800CC850 + 'A';
    sp10.material_name[1] = D_menu_overlay_800CC850 + 'A';
    why->texture_id_pointer[0] = temp_v0->unk14[0] = registerHmtTextureInTable(&sp10, &sp38, 1U);
    rs_free(sp38.pixel_offsets[0]);
    why->texture_count = arg0 / temp_v0->width;
    why->unknown0A = arg1 / temp_v0->height;
    why->height_scale = 1.0f;
    why->width_scale = 1.0f;
    for (var_a1 = 1; var_a1 < temp_v0->unk08; var_a1++) {
        why->texture_id_pointer[var_a1] = why->texture_id_pointer[0];
        temp_v0->unk14[var_a1] = 0xFFFF;
    }
    temp_v0->unk18 = D_menu_overlay_800CC850++;
    return temp_v0;
}
#else
INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuAlpha);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C58);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", strMenuP);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5C7C);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", allocTextRenderTarget);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", tickFormatMessageWorker);

void buildLevelSelectTextTextures(f32 arg0) {
    // u8 sp10[0x40][8];
    u8 sp10[0x200];
    u8 sp210[0x40][8];
    u8 sp410[8][0x40];
    struct material_entry sp610 = {
        .material_type = 1,
        .texture_index = 0,
        .misc_float    = 1.0f,
        .one           = 1.0f,
        .zero          = 0.0f,
        .alwaysa       = 0,
        .pad           = {0},
        .material_name = "GRAD1",
    };
    struct material_entry sp638 = {
        .material_type = 1,
        .texture_index = 0,
        .misc_float    = 1.0f,
        .one           = 1.0f,
        .zero          = 0.0f,
        .alwaysa       = 0,
        .pad           = {0},
        .material_name = "GRAD2",
    };
    struct texture_entry sp660 = {
        .pixel_offsets       = {NULL},
        .plte_offset         = NULL,
        .texture_name_offset = "GRAD1A",
        .width               = 0x40,
        .height              = 0x8,
        .one                 = 1,
        .bit_depth           = 0,
        .flags_type          = 0x0405,
        .transparency_color  = {0, 0, 0, 0},
    };
    struct texture_entry sp698 = {
        .pixel_offsets       = {NULL},
        .plte_offset         = NULL,
        .texture_name_offset = "GRAD2A",
        .width               = 0x8,
        .height              = 0x40,
        .one                 = 1,
        .bit_depth           = 0,
        .flags_type          = 0x0405,
        .transparency_color  = {0, 0, 0, 0},
    };
    f32 var_fv1;
    u32 var_s1;
    u32 var_s2;

    for (var_s1 = 0; var_s1 < 0x40; var_s1++) {
        for (var_s2 = 0; var_s2 < 8; var_s2++) {
            // sp10[var_s1][var_s2] = 0xFF;
            sp10[(var_s1*8) + var_s2] = 0xFF; // But why???
            var_fv1 = quadraticEaseInOut(var_s1 / 64.0f) * 1746.0f;
            if (arg0 < var_fv1) {
                var_fv1 = arg0;
            }
            sp210[var_s1][var_s2] = var_fv1;
            sp410[var_s2][var_s1] = var_fv1;
        }
    }
    sp698.pixel_offsets[0] = sp10;
    sp698.pixel_offsets[1] = sp210;
    sp660.pixel_offsets[0] = sp10;
    sp660.pixel_offsets[1] = sp410;
    D_menu_overlay_800CE6F0 = registerHmtTextureInTable(&sp610, &sp660, 1U);
    D_menu_overlay_800CE6F2 = registerHmtTextureInTable(&sp638, &sp698, 1U);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildScaledFormatTextElement);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", processAndDisposeFormatMessage);

void decrementTextTextureRefcount(void) {
    D_menu_overlay_800CC850--;
}

void setChildPosFromI16Pair(struct some_texture_context *arg0, s16 arg1, s16 arg2) {
    arg0->unk0C->xpos = arg1;
    arg0->unk0C->ypos = arg2;
}

struct ui_element *getStructField0xC(struct some_texture_context *arg0) {
    return arg0->unk0C;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", rasterizeFormatMessageGlyphs);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", disposeFormatMsgQueueMember);

void initFormatMessageWorker(u8 arg0) {
    u32 temp_v0;

    D_menu_overlay_800CC854 = 1;
    D_menu_overlay_800CC858 = registerServiceWorker(8, 0x800, arg0, tickFormatMessageWorker);
    startServiceWorker(D_menu_overlay_800CC858);
}

void shutdownFormatMessageWorker(void) {
    unregisterServiceWorker(D_menu_overlay_800CC858);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", enqueueFormatMessage);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", pollServiceMessageByte);

void initTextTextureTarget(void) {
    D_menu_overlay_800CC864 = allocTextRenderTarget(0x40, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", updateTextOverlayLookupEntry);

// arg1 is unused, so its exact type is honestly immaterial
// Based on the usage of this fuction arg1 a `???`
s32 accumulateShipThrottleCharge(struct some_ui_list_root *arg0, UNIDENTIFIED_TYPE *arg1, f32 arg2) {
    f32 temp_fv1;
    struct ui_element *why;
    struct ui_element *temp_v1;

    if (D_menu_overlay_800CC85C != NULL) {
        temp_v1 = D_menu_overlay_800CC85C->unk0C;
        temp_fv1 = (D_menu_overlay_800CE6F4 * arg2) + temp_v1->rgba.a;
        if (temp_fv1 > 255.0f) {
            temp_v1->rgba.a = 0xFF;
            D_menu_overlay_800CC860++;
            if (D_menu_overlay_800CC860 >= 7) {
                return 1;
            }
        } else {
            why = temp_v1;
            why->rgba.a = temp_fv1;
        }
    }
    return 0;
}

f32 computeThrottleChargeFraction(void) {
    f32 var_ft0;

    var_ft0 = 1.0f;
    if (D_menu_overlay_800CC85C != NULL) {
        var_ft0 = 1.0f - (D_menu_overlay_800CC85C->unk0C->rgba.a / 255.0f);
    }
    return var_ft0;
}

s32 isPlayerShipActive(void) {
    return D_menu_overlay_800CC85C != NULL;
}

void destroyPlayerShipRecord(struct some_ui_list_root *arg0, UNIDENTIFIED_TYPE *arg1) {
    if (D_menu_overlay_800CC85C != NULL) {
        removeLookupTableEntry(arg0, D_menu_overlay_800CC85C->unk0C);
        D_menu_overlay_800CC85C = NULL;
        D_menu_overlay_800CC850 -= 1;
        if (!(gBootConfig.unk2C.unk18 & 0x80)) {
            requestViFeatureChange(8);
        }
    }
}

struct some_texture_context *spawnProjectileObject(u16 arg0, u16 arg1, u16 arg2, u32 arg3) {
    struct some_texture_context *temp_v0;

    temp_v0 = rs_malloc(sizeof(struct some_texture_context), 0U);
    rs_memset(temp_v0, 0U, sizeof(struct some_texture_context));
    temp_v0->unk10 = rs_malloc(0x10U, 0U);
    rs_memset(temp_v0->unk10, 0U, 0x10U);
    temp_v0->unk10->flags_type.as_u16 = arg0;
    temp_v0->unk1C = arg3;
    temp_v0->width = arg1;
    temp_v0->height = arg2;
    temp_v0->unk18 = D_menu_overlay_800CC850++;
    return temp_v0;
}

void copyMorphTargetVertices(struct some_texture_context *arg0, struct some_texture_context *arg1, u16 arg2) {
    u32 var_a3;

    for (var_a3 = 0; var_a3 < arg0->unk08; var_a3++) {
        arg0->unk0C->texture_id_pointer[var_a3] = \
        arg0->unk14[var_a3] = arg1->unk14[var_a3 + arg2];
    }
}

#if 0
// Text matching, have not check if rodata works yet
// Appends "alplha" to the end of arg0, placing the combined result in D_menu_overlay_800CE6B0
char *buildPrefixedAssetName(char *arg0) {
    s32 temp_s3;
    char *temp_v0;
    u32 var_s1;

    temp_v0 = "alpha";
    rs_strcpy(D_menu_overlay_800CE6B0, arg0);
    temp_s3 = strlen(D_menu_overlay_800CE6B0);
    for (var_s1 = 0; var_s1 < strlen(temp_v0) + 1; var_s1++) {
        D_menu_overlay_800CE6B0[temp_s3 + var_s1] = temp_v0[var_s1];
    }
    return D_menu_overlay_800CE6B0;
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", buildPrefixedAssetName);
#endif

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", spawnHudReticleAtMeshBounds);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", positionHudSpriteOffset);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", createHudSpritePair);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", layoutHudSpriteScreenRect);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1197D0", fake_func_800B47C4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/1197D0", D_menu_overlay_800A5DC0);
