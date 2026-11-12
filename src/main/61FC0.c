#include "common.h"

#include "PR/os.h"

#include "font.h"
#include "main/02420.h"
#include "main/08120.h"
#include "main/1EE30.h"
#include "main/61FC0.h"
#include "main/64EA0.h"

s8  D_main_bss_80139960;
u8  bss_pad0_61FC0;
s16 D_main_bss_80139962;
s16 D_main_bss_80139964;
u16 bss_pad1_61FC0;
s16 (*D_main_bss_80139968)(s16);
u16 D_main_bss_80139970[6];
u16 D_main_bss_80139980[6];

INCLUDE_ASM("asm/nonmatchings/main/61FC0", loadCharTextureSet);

#if 0
// Needs the rest of the RODATA in this file to fully match
// But the .text section matches
extern char *D_main_8009ED70[];
void loadFontAsset(u8 arg0) {
    char sp10[0x40];
    struct material_entry sp50 = {
        .material_type = 1,
        .texture_index = 0,
        .misc_float    = 1.0f,
        .one           = 1.0f,
        .zero          = 0,
        .alwaysa       = 0,
        .pad           = {0, 0, 0},
        .material_name = "___"
    };
    struct texture_entry sp78;
    u16 temp_v0_2;
    u32 var_s2;
    struct partial_image_header *temp_v0;

    rs_memset(&sp78, 0U, 0x34U);
    sp78.texture_name_offset = "___";
    sp78.one = 1;
    for (var_s2 = 0; var_s2 < 6; var_s2++) {
        sprintf(sp10, "fonts/%s", D_main_8009ED70[var_s2]);
        temp_v0 = load_asset(&sp10);
        sp78.transparency_color.r = temp_v0->transparency_color.r;
        sp78.transparency_color.g = temp_v0->transparency_color.g;
        sp78.transparency_color.b = temp_v0->transparency_color.b;
        sp78.width = temp_v0->image_pixel_width;
        sp78.height = temp_v0->image_pixel_height;
        sp78.texture_name_offset[0] = 'X';
        sp78.texture_name_offset[1] = '0' + var_s2;
        sp50.material_name[0] = 'X';
        sp50.material_name[1] = '0' + var_s2;
        sp50.material_name[2] = 'A';
        sp78.pixel_offsets[0] = (u32)temp_v0 + sizeof(struct partial_image_header);
        sp78.texture_name_offset[2] = 'A';
        sp78.flags_type = 0x8002;
        D_main_bss_80139980[var_s2] = registerHmtTextureInTable(&sp50, &sp78, 0U);
        if (arg0 == 0) {
            sp50.material_name[2] = 'S';
            sp78.texture_name_offset[2] = 'S';
            sp78.flags_type = 0x4002;
            D_main_bss_80139970[var_s2] = registerHmtTextureInTable(&sp50, &sp78, 0U);
        } else {
            D_main_bss_80139970[var_s2] = D_main_bss_80139980[var_s2];
        }
        rs_free(temp_v0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/61FC0", loadFontAsset);
#endif

void activateAnimationKeyframe(u16 arg0, u16 arg1, u8 arg2) {
    u32 temp_s0;
    u32 var_a0;
    u32 var_t2;
    struct ui_element_mk2 *temp_a1;
    struct someFontThing *temp_s1;

    temp_s1 = D_main_8009FC10[arg0];
    if (temp_s1->unk030 & (1 << arg1)) {
        if ((arg2 == 0xFF) && (temp_s1->unk01F == 0)) {
            arg2 = 0xFE;
        }
        temp_a1 = getPlayerSlotFieldAt34(arg0, arg1);
        if (arg2 == 0xFF) {
            if (temp_s1->unk084[arg1] == 0) {
                for (var_t2 = 0; var_t2 < temp_a1->texture_count; var_t2++) {
                    for (var_a0 = 0; var_a0 < temp_s1->symbolCount; var_a0++) {
                        if (temp_a1->texture_id_pointer[var_t2] == temp_s1->unk024[var_a0]) {
                            temp_a1->texture_id_pointer[var_t2] = temp_s1->unk028[var_a0];
                            break;
                        }
                    }
                    for (var_a0 = 0; var_a0 < 6; var_a0++) {
                        if (temp_a1->texture_id_pointer[var_t2] == D_main_bss_80139980[var_a0]) {
                            temp_a1->texture_id_pointer[var_t2] = D_main_bss_80139970[var_a0];
                            break;
                        }
                    }
                }
                temp_s1->unk084[arg1] = 1;
            }
            temp_a1->flags &= ~1;
        } else {
            if (temp_s1->unk084[arg1] != 0) {
                for (var_t2 = 0; var_t2 < temp_a1->texture_count; var_t2++) {
                    for (var_a0 = 0; var_a0 < temp_s1->symbolCount; var_a0++) {
                        if (temp_a1->texture_id_pointer[var_t2] == temp_s1->unk028[var_a0]) {
                            temp_a1->texture_id_pointer[var_t2] = temp_s1->unk024[var_a0];
                            break;
                        }
                    }
                    for (var_a0 = 0; var_a0 < 6; var_a0++) {
                        if (temp_a1->texture_id_pointer[var_t2] == D_main_bss_80139970[var_a0]) {
                            temp_a1->texture_id_pointer[var_t2] = D_main_bss_80139980[var_a0];
                            break;
                        }
                    }
                }
                temp_s1->unk084[arg1] = 0;
            }
            temp_a1->flags |= 1;
        }
        temp_a1->rgba.a = arg2;
        if (temp_s1->unk0F4 != NULL) {
            temp_s0 = 0;
            if (temp_a1->rgba.a) {
                temp_s0 = temp_a1->texture_count > 0;
            }
            setLookupEntryField5ByKey(temp_s1->unk0F4, temp_a1, temp_s0);
        }
    }
}

#if 0
// Decently close, bunch of instruction ordering issue down near the floating point math at the bottom.
void samplePlayerAnimChannel(u16 arg0, u16 arg1, f32 arg2) {
    s16 temp_a0;
    s16 var_s2;
    s16 var_s3;
    s16 var_s4;
    f32 midx;
    f32 midy;
    f32 temp_ft1;
    struct someFontThing *temp_s6;
    struct ui_element_mk2 *temp_s1;

    var_s4 = 0x2710;
    temp_s6 = D_main_8009FC10[arg0];
    var_s3 = -0x2710;
    temp_s1 = temp_s6->unk034[arg1];
    for (var_s2 = 0; var_s2 < temp_s1->texture_count; var_s2++) {
        temp_a0 = temp_s1->xy_offset_pointer[var_s2].x + resolvePlayerAnimChannelKeyValue(arg0, temp_s1->texture_id_pointer[var_s2]);
        if (var_s3 < temp_a0) {
            var_s3 = temp_a0;
        }
        if (temp_s1->xy_offset_pointer[var_s2].x < var_s4) {
            var_s4 = temp_s1->xy_offset_pointer[var_s2].x;
        }
    }
    temp_ft1 = 1.0f - arg2;
    temp_s1->width_scale = arg2;
    temp_s1->height_scale = arg2;
    midx = (var_s3 - var_s4) * 0.5f;
    midy = temp_ft1 * (((temp_s1->xy_offset_pointer[temp_s1->texture_count - 1].y + temp_s6->unk006) - temp_s1->xy_offset_pointer[0].y) * 0.5f);
    temp_s1->xpos = temp_s6->unk098[arg1].x + (temp_ft1 * (midx + var_s4));
    temp_s1->ypos = temp_s6->unk098[arg1].y + midy;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/61FC0", samplePlayerAnimChannel);
#endif

INCLUDE_ASM("asm/nonmatchings/main/61FC0", measurePlayerSlotTextLayout);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelExt);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannel);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", advancePlayerAnimationPhase);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", initPlayerSlotAnimationChannelFull);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelFlagged);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelLooping);

#if 0
// The .text section matches just fine
// Probably can't fully match this anyway due to the .rodata struct initialization stuff
struct ui_element_mk2 *buildPlayerCraftAssetTemplate(s16 arg0, s16 arg1) {
    struct material_entry sp10 = {
        .material_type = 1,
        .texture_index = 0,
        .misc_float    = 1.0f,
        .one           = 1.0f,
        .zero          = 0,
        .alwaysa       = 0,
        .pad           = {0, 0, 0},
        .material_name = "___"
    };
    struct texture_entry sp38 = {
        .pixel_offsets       = {NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        .plte_offset         = NULL,
        .texture_name_offset = "ZA_fnt",
        .width               = 0,
        .height              = 0,
        .one                 = 1,
        .bit_depth           = 0,
        .flags_type          = 5,
        .transparency_color  = {0, 0, 0, 0},
    };
    u32 temp_lo;
    struct ui_element_mk2 *temp_v0;

    temp_v0 = rs_malloc(sizeof(struct ui_element_mk2), 0U);
    rs_memset(temp_v0, 0U, sizeof(struct ui_element_mk2));
    sp38.width = arg0;
    sp38.height = arg1;
    sp38.pixel_offsets[0] = rs_malloc(arg0 * arg1, 0U);
    rs_memset(sp38.pixel_offsets[0], 0xFFU, arg0 * arg1);
    temp_v0->unk30 = registerHmtTextureInTable(&sp10, &sp38, 0U);
    rs_free(sp38.pixel_offsets[0]);
    temp_v0->texture_count = temp_v0->unknown0A = 1;
    temp_v0->flags = 3;
    temp_v0->prev = temp_v0->next = NULL;
    temp_v0->xy_offset_pointer = NULL;
    temp_v0->texture_id_pointer = &temp_v0->unk30;
    temp_v0->rgba.r = temp_v0->rgba.g = temp_v0->rgba.b = temp_v0->rgba.a = 0xFF;
    temp_v0->xpos = temp_v0->ypos = 0.0f;
    temp_v0->width_scale = temp_v0->height_scale = 1.0f;
    temp_v0->zero = 0.0f;
    return temp_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/61FC0", buildPlayerCraftAssetTemplate);
#endif

INCLUDE_ASM("asm/nonmatchings/main/61FC0", resolvePlayerAnimChannelKeyValue);

void initAllPlayerSlots(void) {
    u32 var_a0;
    u32 var_a2;
    struct someFontThing *temp_v1;

    for (var_a2 = 0; var_a2 < 0xC; var_a2++) {
        temp_v1 = D_main_8009FC10[var_a2];
        temp_v1->unk020 = NULL;
        temp_v1->unk024 = NULL;
        temp_v1->unk028 = NULL;
        temp_v1->unk02C = 0;
        temp_v1->unk030 = 0;
        for (var_a0 = 0; var_a0 < 0x14; var_a0++) {
            temp_v1->unk034[var_a0] = NULL;
            temp_v1->unk084[var_a0] = 0;
        }
        temp_v1->unk0F8 = var_a2 + 'A';
        temp_v1->unk0EC = NULL;
        temp_v1->unk0F0 = NULL;
        temp_v1->unk0F4 = NULL;
        temp_v1->unk0FC = NULL;
    }
    D_main_bss_80139960 = 1;
    D_main_bss_80139962 = 0x140;
    D_main_bss_80139964 = 0x140;
}

void resetPlayerSlotChannelTransform(u16 arg0) {
    struct someFontThing *temp_v0;

    temp_v0 = D_main_8009FC10[arg0];
    temp_v0->unk028 = NULL;
    temp_v0->unk024 = NULL;
    temp_v0->unk020 = NULL;
    temp_v0->unk030 = 0;
}

char *getPlayerSlotLookupBase(u8 arg0) {
    return D_main_8009FC10[arg0]->unk020;
}

struct ui_element_mk2 *getPlayerSlotFieldAt34(u16 arg0, u16 arg1) {
    return D_main_8009FC10[arg0]->unk034[arg1];
}

void resetPlayerSlotAllChannels(u16 arg0, u8 arg1) {
    u32 var_s0;
    struct someFontThing *temp_s1;

    temp_s1 = D_main_8009FC10[arg0];
    if (temp_s1->unk0F4 == 0) return;
    for (var_s0 = 0; var_s0 < temp_s1->unk02C; var_s0++) {
            insertLookupEntry(temp_s1->unk0F4, temp_s1->unk034[var_s0], arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setPlayerSlotAnimationFlag);

void setMenuOverlayHeaderState(s8 arg0, s16 arg1, s16 arg2) {
    D_main_bss_80139960 = arg0;
    D_main_bss_80139962 = arg1;
    D_main_bss_80139964 = arg2;
}

void setMenuOverlayHeaderCallback(s16 (*arg0)(s16)) {
    D_main_bss_80139968 = arg0;
}

void setPlayerSlotEntryRGB(u16 arg0, u16 arg1, struct rgba *arg2) {
    struct ui_element_mk2 *temp_v1;

    temp_v1 = D_main_8009FC10[arg0]->unk034[arg1];
    temp_v1->rgba.r = arg2->r;
    temp_v1->rgba.g = arg2->g;
    temp_v1->rgba.b = arg2->b;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setPlayerSlotPointerAndFlag);

void clearPlayerSlotPointerAndFlag(u16 arg0) {
    struct someFontThing *temp_v0;

    temp_v0 = D_main_8009FC10[arg0];
    temp_v0->unk0FC = NULL;
    temp_v0->unk100 = 0;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", isAnimInstanceActive);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerAnimChannelEntryByIds);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerAnimChannelEntryReversed);

s32 identityReturnArg(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerSlotAnimChannelCount);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", markStructInitializedOnce);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", isStructUninitialized);

u16 findCharEntryValueByKey(u16 arg0, u8 arg1) {
    s32 var_a2;
    u16 var_v1;
    struct someFontThing *temp_a0;

    temp_a0 = D_main_8009FC10[arg0];
    for (var_v1 = 0; var_v1 < temp_a0->symbolCount; var_v1++) {
        if (temp_a0->symbolList[var_v1] == arg1) return temp_a0->unk028[var_v1];
    }
    return 0xFFFF;
}

u16 findCharEntryAltValueByKey(u16 arg0, u8 arg1) {
    u16 var_v1;
    struct someFontThing *temp_a0;

    temp_a0 = D_main_8009FC10[arg0];
    for (var_v1 = 0; var_v1 < temp_a0->symbolCount; var_v1++) {
        if (temp_a0->symbolList[var_v1] == arg1) return temp_a0->unk024[var_v1];
    }
    for (var_v1 = 0; var_v1 < 6; var_v1++) {
        if (arg1 == (u8)(var_v1 + 1)) return D_main_bss_80139980[var_v1];
    }
    return 0xFFFF;
}

u8 findCharEntryByteByKey(u16 arg0, u8 arg1) {
    s32 var_a2;
    u16 var_v1;
    struct someFontThing *temp_a0;

    temp_a0 = D_main_8009FC10[arg0];
    for (var_v1 = 0; var_v1 < temp_a0->symbolCount; var_v1++) {
        if (temp_a0->symbolList[var_v1] == arg1) return temp_a0->unk018[var_v1];
    }
    return 0;
}

s16 getPlayerSlotEntryBaseShort(u16 arg0) {
    return D_main_8009FC10[arg0]->unk006;
}

s16 samplePlayerSlotChannelScaledShort(u16 arg0, u16 arg1) {
    struct someFontThing *temp_a2;
    struct ui_element_mk2 *temp_a1;
    struct xy_offset *temp_a0;
    s16 temp;

    temp_a2 = D_main_8009FC10[arg0];
    temp_a1 = temp_a2->unk034[arg1];
    temp_a0 = temp_a1->xy_offset_pointer;
    temp = temp_a2->unk006 + (temp_a0[temp_a1->texture_count - 1].y - temp_a0[0].y);
    return temp * temp_a1->height_scale;
}

s16 getPlayerSlotSpanShort(u16 arg0) {
    struct someFontThing *temp_v1;

    temp_v1 = D_main_8009FC10[arg0];
    return temp_v1->unk004 + temp_v1->unk00A;
}

void setPlayerSlotEnabledFlag(u16 arg0, u8 arg1) {
    D_main_8009FC10[arg0]->unk102 = arg1 == 0;
}

s16 invokeMenuOverlayHeaderCallback(s16 arg0) {
    s16 var_v0;

    if (D_main_bss_80139960 & 8) {
        var_v0 = D_main_bss_80139968(arg0);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", fake_func_80064294);
