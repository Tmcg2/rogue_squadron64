#ifndef TEXTURES_H
#define TEXTURES_H

#include "PR/ultratypes.h"

struct texture_entry {
    /* 0x00 */ u32 pixel_offsets[8];
    /* 0x20 */ u32 plte_offset;
    /* 0x24 */ u32 texture_name_offset;
    /* 0x28 */ u16 width;
    /* 0x2A */ u16 height;
    /* 0x2C */ u8 one; // Always(?) 0x01, purpose unknown
    /* 0x2D */ u8 bit_depth;
    /* 0x2E */ u8 unused;
    /* 0x2F */ u8 type;
    /* 0x30 */ u32 trans_color;
}; // size 0x34

#endif
