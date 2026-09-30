#ifndef TEXTURES_H
#define TEXTURES_H

#include "PR/ultratypes.h"

struct material_entry {
    u16 material_type;      /* 0x00 1 = has texture, 2 = no texture */
    u16 texture_index;      /* 0x02 */
    f32 misc_float;         /* 0x04 Pupose unknown */
    f32 one;                /* 0x08 Always(?) 1.0f */
    u32 zero;               /* 0x0C Always(?) 0 */
    u32 alwaysa;            /* 0x10 Always(?) 0x0a000000, purpose unknown */
    char material_name[16]; /* 0x14 */
}; // size 0x24

struct texture_entry {
    u32 pixel_offsets[8];    /* 0x00 */
    u32 plte_offset;         /* 0x20 */
    u32 texture_name_offset; /* 0x24 */
    u16 width;               /* 0x28 */
    u16 height;              /* 0x2A */
    u8  one;                 /* 0x2C Always(?) 0x01, purpose unknown */
    u8  bit_depth;           /* 0x2D */
    u16 flags_type;          /* 0x2E */
    u32 transparency_color;  /* 0x30 */
}; // size 0x34

struct full_image_header {
    u32 image_size;
    struct texture_entry ent;
};

#endif
