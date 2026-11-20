#ifndef TEXTURES_H
#define TEXTURES_H

#include "PR/ultratypes.h"

#include "common_types.h"
#include "hud.h"

struct material_entry {
    u16 material_type;      /* 0x00 1 = has texture, 2 = no texture */
    u16 texture_index;      /* 0x02 */
    f32 misc_float;         /* 0x04 Pupose unknown */
    f32 one;                /* 0x08 Always(?) 1.0f */
    u32 zero;               /* 0x0C Always(?) 0 */
    u8  alwaysa;            /* 0x10 Always(?) 0x0a000000, purpose unknown */
    u8  pad[3];             /* 0x11 I don't trust to compiler to put this here on its own */
    char material_name[16]; /* 0x14 */
}; // size 0x24

struct texture_entry {
    void *pixel_offsets[8];         /* 0x00 */
    void *plte_offset;              /* 0x20 */
    char *texture_name_offset;      /* 0x24 */
    u16 width;                      /* 0x28 */
    u16 height;                     /* 0x2A */
    u8  one;                        /* 0x2C Always(?) 0x01, purpose unknown */
    u8  bit_depth;                  /* 0x2D */
    u16 flags_type;                 /* 0x2E */
    struct rgba transparency_color; /* 0x30 */
}; // size 0x34

struct full_image_header {
    u32 image_size;
    struct texture_entry ent;
};

struct partial_image_header {
    union {
        struct {
            u8 flags;
            u8 type;
        } as_u8;
        u16 as_u16;
    } flags_type;
    // u16 flags_type;                 /* 0x0 */ 
    u8  always_0;                   /* 0x2 */
    u8  bit_depth;                  /* 0x3 */
    u16 image_pixel_width;          /* 0x4 */
    u16 image_pixel_height;         /* 0x6 */
    struct rgba transparency_color; /* 0x8 */
}; // size 0xC

struct some_texture_context {
    u16 width;                          /* 0x00 */
    u16 height;                         /* 0x02 */
    u16 unk04;                          /* 0x04 */
    u16 unk06;                          /* 0x06 */
    u32 unk08;                          /* 0x08 */
    struct ui_element *unk0C;           /* 0x0C */
    struct partial_image_header *unk10; /* 0x10 Some functions indicate that this should point to something 0x10 bytes big, but a partial header is only 0xC bytes big */
    u16 *unk14;                         /* 0x14 */
    u8 unk18;                           /* 0x18 */
    u8 pad19[0x1C - 0x19];              /* 0x19 I don't trust the compiler to put this here */
    u32 unk1C;                          /* 0x1C */
    u8 pad20[0x34 - 0x20];              /* 0x20 */
    s16 unk34;                          /* 0x34 */
    s16 unk36;                          /* 0x36 */
}; // size 0x38

#endif
