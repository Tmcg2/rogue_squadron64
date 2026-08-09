#ifndef MISSION_0FCA20_H
#define MISSION_0FCA20_H

#include "PR/ultratypes.h"

struct rgba {
    u8 red;   /* 0x00 */
    u8 green; /* 0x01 */
    u8 blue;  /* 0x02 */
    u8 alpha; /* 0x03 */
}; // size 0x4

struct xy_offset {
    u16 x; /* 0x0 */
    u16 y; /* 0x2 */
}; // size = 0x4

struct ui_element {
    struct ui_element *prev;             /* 0x00 */
    struct ui_element *next;             /* 0x04 */
    // These seem to control whether the UI element is visible or not, somehow
    u16 texture_count;                   /* 0x08 */
    u16 unknown0A;                       /* 0x0A */
    u16 *texture_id_pointer;             /* 0x0C */
    struct xy_offset *xy_offset_pointer; /* 0x10 */
    u32 flags;                           /* 0x14 */
    f32 xpos;                            /* 0x18 */
    f32 ypos;                            /* 0x1C */
    f32 zero;                            /* 0x20 zpos?, maybe padding */
    f32 width_scale;                     /* 0x24 */
    f32 height_scale;                    /* 0x28 */
    struct rgba rgba;                    /* 0x2C */
}; // size = 0x30

struct hud_struct {
    u8 secondaryWeapon;                            /* 0x000 */
    u8 secondaryWeaponState;                       /* 0x001 Involved in the firing of secondary weapons in one way or another */
    u8 secondaryWeaponCount;                       /* 0x002 */
    u8 secondaryWeaponReset;                       /* 0x003 Or maybe, secondaryWeaponMax? */
    u8 secondaryWeaponIsAdvanced;                  /* 0x004 */
    u8 crosshairOnOff;                             /* 0x005 */
    u8 unknown006;                                 /* 0x006 */
    u8 unknown007;                                 /* 0x007 */
    u16 unknown008;                                /* 0x008 */
    // I think these are indices into D_8011A444;
    u16 texture_ids[10];                           /* 0x00A */
    // u16 compiler_padding;                       /* 0x01E */
    u32 unknown020;                                /* 0x020 could be padding? */
    f32 alpha_scaling;                             /* 0x024 */
    struct ui_element outerCrosshairRingElement;   /* 0x028 */
    struct ui_element innerCrosshairRingElement;   /* 0x058 */
    struct ui_element bombCrosshairRingElement;    /* 0x088 */
    struct ui_element hud_elements[5];             /* 0x0B8 */
    struct ui_element seekerCrosshairRing1Element; /* 0x088 */
    struct ui_element seekerCrosshairRing2Element; /* 0x088 */
    u32 unknown_words208[0x1C];                    /* 0x208 */
}; // size 0x278

void resetSecondaryWeaponCount(void);
s32  func_mission_overlay_800FEECC(void);
u8   getHudSecondaryWeponCount(void);

#endif