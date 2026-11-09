#ifndef TEXTURES_H
#define TEXTURES_H

#include "PR/ultratypes.h"

#include "common_types.h"

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
    u8  flags;                      /* 0x0 */ 
    u8  type;                       /* 0x1 */
    u8  always_0;                   /* 0x2 */
    u8  bit_depth;                  /* 0x3 */
    u16 image_pixel_width;          /* 0x4 */
    u16 image_pixel_height;         /* 0x6 */
    struct rgba transparency_color; /* 0x8 */
}; // size 0xC

#endif
