#ifndef HUD_H
#define HUD_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct xy_offset {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
}; // size = 0x4

struct ui_element {
    /* 0x00 */ struct ui_element *prev;
    /* 0x04 */ struct ui_element *next;
    // These seem to control whether the UI element is visible or not, somehow
    /* 0x08 */ u16 texture_count;
    /* 0x0A */ u16 unknown0A;
    /* 0x0C */ u16 *texture_id_pointer;
    /* 0x10 */ struct xy_offset *xy_offset_pointer;
    /* 0x14 */ u32 flags;
    /* 0x18 */ f32 xpos;
    /* 0x1C */ f32 ypos;
    /* 0x20 */ f32 zero; // zpos?, maybe padding
    /* 0x24 */ f32 width_scale;
    /* 0x28 */ f32 height_scale;
    /* 0x2C */ struct rgba rgba;
}; // size = 0x30

struct func_800C0084_d84_type {
    /* 0x00 */ u32 unk00[8];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u16 unk34;
    /* 0x36 */ u16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u32 unk44;
}; // size = 0x48

struct func_800C0084_type {
    /* 0x000 */ u16 hud_texture_ids[0x1E];
    /* 0x03C */ struct ui_element hud_element_0;
    /* 0x06C */ struct ui_element livesCountElement;
    /* 0x09C */ struct ui_element upperHealthIndicatorElement;
    /* 0x0CC */ struct ui_element lowerHealthIndicatorElement;
    /* 0x0FC */ struct ui_element secondaryWeaponCountElement;
    /* 0x12C */ struct ui_element secondaryWeaponSymbolElement;
    /* 0x15C */ struct ui_element secondaryWeaponRingElement;
    /* 0x18C */ struct ui_element radarOutlineElement;
    /* 0x1BC */ struct ui_element playerIdElement;
    /* 0x1EC */ u16 hud_xy_offsets[6][2]; // Not sure why there's only 6 of these but 9 hud elements
    /* 0x204 */ struct rgba hud_element_color_0;
    /* 0x208 */ struct rgba livesCountColor;
    /* 0x20C */ struct rgba upperHealthIndicatorColor;
    /* 0x210 */ struct rgba lowerHealthIndicatorColor;
    /* 0x214 */ struct rgba secondaryWeaponCountColor;
    /* 0x218 */ struct rgba secondaryWeaponSymobolColor;
    /* 0x21C */ struct rgba secondaryWeaponRingColor;
    /* 0x220 */ struct rgba radarOutlineColor;
    /* 0x224 */ struct rgba playerIdColor; // name based on code, but I don't think anything is actually displayed
    /* 0x228 */ u16 livesCountTimer;
    /* 0x22A */ u16 unk22A;
    /* 0x22C */ void *unk22C;
    /* 0x230 */ void *unk230;
    /* 0x234 */ u32 unk234;
    /* 0x238 */ f32 unk238;
    /* 0x23C */ f32 unk23C;
    /* 0x240 */ f32 playerHealthPercentage;
    /* 0x244 */ u32 rest01[8];
    /* 0x264 */ struct ui_element menu_elements[16];
    /* 0x564 */ u16 menu_texture_ids[0x12C];
    /* 0x7BC */ u8  rest02[10];
    // The alignment of this is pretty bizarre
    /* 0x7C6 */ u16 menu_element_xy_offsets[0x12C][2];
    /* 0xC76 */ u8  rest03[2]; // padding, most likely
    /*
    Starting here it looks like there's something like a mini-hob. Its related to the dimming effect on the pause screen.
    The `big_block_o_floats` from the meshdef0 definition is a little small in this case though, only 14 floats instead of 28
    The meshdef1 is also interesting, in the middle of its `big_block_o_floats` there's a pointer of some kind, so that's probably undersized too
    */
    /* 0xC78  u32 mini_hob[0x3C];*/
    struct {
        struct {
            /* 0xC78 */ void *next_meshdef0_pointer;
            /* 0xC7C */ void *prev_meshdef0_pointer;
            /* 0xC80 */ void *unknown_meshdef0_pointer0;
            /* 0xC84 */ void *unknown_meshdef0_pointer1;
            /* 0xC88 */ void *meshdef1_pointer;
            /* 0xC8C */ u32 unk14;
            /* 0xC90 */ u32 unk18;
            /* 0xC94 */ float big_block_o_floats[9];
            /* 0xCB8 */ float pos[3];
        } mini_meshdef0;
        // struct meshdef0 mini_meshdef0
        struct {
            /* 0xCC4 */ void *next_meshdef1_pointer;
            /* 0xCC8 */ void *prev_meshdef1_pointer;
            /* 0xCCC */ u32 unk08;
            /* 0xCD0 */ u32 unk0C;
            /* 0xCD4 */ u32 unk10;
            /* 0xCD8 */ u32 vertex_counts[2];
            /* 0xCE0 */ float some_float;
            /* 0xCE4 */ void *facegroup_pointer;
            /* 0xCE8 */ void *vertext_pointers[2];
            /* 0xCF0 */ u32 unk2C[12];
        } mini_meshdef1;
        // struct meshdef1 mini_meshdef1
        struct {
            /* 0xD20 */ void *next_facegroup;
            /* 0xD24 */ void *prev_facegroup;
            /* 0xD28 */ void *face_offset;
            /* 0xD2C */ u32 face_count;
        } facegroup;
        struct {
            /* 0xD30 */ u32 flags;
            /* struct {
                u32 extra                     : 2;
                u32 face_size                 : 6; // multiply by 4 to get the actual size
                u32 vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
                u32 vertex_color_offset       : 6; // multiply by 4 to get the actual offset
                u32 vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
                u32 texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
            } stuffed_data; */
            /* 0xD34 */ u32 stuffed_data;
            /* 0xD38 */ u32 material_index;
            /* 0xD3C */ u16 vertex_indices[4];
            /* 0xD44 */ struct rgba vertex_colors;
        } face;
        /* 0xD58 */ struct {
            u16 x;
            u16 y;
            u16 z;
            u16 padding;
        } vertices[4];
    } mini_hob;
    /* 0xD68 */ u16 current_entry;
    /* 0xD6A */ u8  current_menu;
    /* 0xD6B */ u8  unkD6B;
    /* 0xD6C */ u32 unkD6C;
    /* 0xD70 */ f32 text_highlight_timer;
    /* 0xD74 */ f32 medal_timer; // a timer related to the medal's back-and-forth rotation
    /* 0xD78 */ u32 unkD78;
    /* 0xD7C */ u32 unkD7C;
    /* 0xD80 */ f32 objective_highlight_countdown; // a countdown to when the objectives should be highlighted, the hilighting uses the same time as the menu selection
    /* 0xD84 */ struct func_800C0084_d84_type unkD84[7];
    /* 0xF7C */ u8 unkF7C;
    /* 0xF7D */ u8 secondaryWeaponType;
    /* 0xF7E */ u8 secondaryWeaponLevel;
    /* 0xF7F */ u8 unkF7F;
}; // size = 0xF80

#endif
