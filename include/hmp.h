#ifndef HMP_H
#define HMP_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct hmp_tile {
    u16 texmap_idx;       /* 0x00 */
    u8 flags;             /* 0x02 */
    s8 min_height;        /* 0x03 */
    s8 max_height;        /* 0x04 */
    s8 height_values[25]; /* 0x05 */
}; // size 0x1E

struct global_terrain_light_object {
    f32 rgb_intensity[3];   /* 0x00 */
    u8 active;              /* 0x0C */
    u8 mode;                /* 0x0D */
    u8 intesity_boost;      /* 0x0E */
    u8 unk0F;               /* 0x0F */
    f32 light_direction[3]; /* 0x10 */
    f32 unk24;              /* 0x1C */
}; // size 0x20

struct light_object {
    f32 rgb_intensity[3]; /* 0x00 */
    u8 active;            /* 0x0C */
    u8 mode;              /* 0x0D */
    u8 intesity_boost;    /* 0x0E */
    u8 unk0F;             /* 0x0F */
    f32 location[3];      /* 0x10 */
    f32 size_scale;       /* 0x1C */
}; // size = 0x20

struct lighting_data {
    u32  light_object_count;                /* 0x00 This is the number of `light_object`s + the `global_terrain_light_object` */
    struct rgba terrain_shadow_color;              /* 0x04 */
    struct rgba world_light_color;                 /* 0x08 */
    struct global_terrain_light_object glo; /* 0x0C */
    struct light_object lights[];           /* 0x2C */
};

struct hmp_header {
    Vec3f floats;                     /* 0x00 */
    Vec3f scales;                     /* 0x0C */
    u16   tile_count;                 /* 0x18 */
    u16   texture_count;              /* 0x1A */
    struct hmp_tile *tiles;           /* 0x1C */
    struct lighting_data *light_data; /* 0x20 */
    u16   width;                      /* 0x24 */
    u16   height;                     /* 0x26 */
    u16   tile_indices[];             /* 0x28 */
}; // size = 0x28

struct hmp_context {
    u16  *tile_indices;             /* 0x00 */
    struct hmp_tile *tiles;         /* 0x04 */
    u16  *unk08;                    /* 0x08 */
    UNIDENTIFIED_TYPE *tex_pointer; /* 0x0C */
    f32   unk10;                    /* 0x10 */
    Vec3f unk14;                    /* 0x14 */
    Vec3f unk20;                    /* 0x20 */
    Vec3f unk2C;                    /* 0x2C */
    u16   width;                    /* 0x38 */
    u16   height;                   /* 0x3A */
    Vec3f rgb;                      /* 0x3C */
    struct light_object *lights[4]; /* 0x48 */
}; // size 0x58

#endif
