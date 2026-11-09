#ifndef HOB_H
#define HOB_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct vertex {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
};

struct face {
    u32 flags;                    /* 0x00 */
    // struct {
    //     u32 unused                    : 2;
    //     u32 face_size                 : 6; // multiply by 4 to get the actual size
    //     u32 vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
    //     u32 vertex_color_offset       : 6; // multiply by 4 to get the actual offset
    //     u32 vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
    //     u32 texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
    // } stuffed_data;               /* 0x04 */
    u32 stuffed_data;
    // I hate this, but its required to match `setMaterialFlagByIdInMeshTree`
    union {
        struct {
            u16 material_index;      /* 0x08 */
            u16 unk0A;               /* 0x0A */
        } as_pair;
        u32 as_word;                 /* 0x08 */
    } unk08;                         /* 0x08 */
    u16 vertex_indices[1];        /* 0x?? A tri has 3 vertices, while a quad has 4. There may be 2 sets of vertices */
    struct rgba vertex_colors[1]; /* 0x?? These may not be present at all, there can be 3 or 4 entries, see flags */
    u32 texture_coordinates[1];   /* 0x?? These may not be present at all, there can be 3 or 4 entries, see flags */
}; // size variable

struct facegroup {
    struct facegroup *next_facegroup; /* 0x0 */
    struct facegroup *prev_facegroup; /* 0x4 */
    struct face *face_offset;         /* 0x8 */
    u32 face_count;                   /* 0xC */
}; // size 0x10

struct meshdef0_inner {
    struct meshdef0 *next_meshdef0_pointer;     /* 0x00 */
    struct meshdef0 *prev_meshdef0_pointer;     /* 0x04 */
    struct meshdef0 *unknown_meshdef0_pointer0; /* 0x08 */
    struct meshdef0 *unknown_meshdef0_pointer1; /* 0x0C */
    struct meshdef1 *meshdef1_pointer;          /* 0x10 */
    f32 two_floats[2];                          /* 0x14 */
    Mat4x3 mtx;                                 /* 0x1C */
}; // size = 0x4C

struct meshdef0 {
    struct meshdef0_inner inner; /* 0x00 */
    u32 flags;                   /* 0x4C */
    Vec3f somevector0;           /* 0x50 */
    Vec3f somevector1;           /* 0x5C */
    Vec4f somequat0;             /* 0x68 */
    Vec3f somevector2;           /* 0x78 */
}; // size = 0x84

struct meshdef1 {
    struct meshdef1 *next_meshdef1_pointer; /* 0x00 */
    struct meshdef1 *prev_meshdef1_pointer; /* 0x04 */
    u32 unk08;                              /* 0x08 */
    u32 unk0C;                              /* 0x0C */
    u32 unk10;                              /* 0x10 */
    u32 vertex_counts[2];                   /* 0x14 */
    f32 some_float;                         /* 0x1C */
    struct facegroup *facegroup_pointer;    /* 0x20 */
    struct vertex *vertext_pointers[2];     /* 0x24 */
    f32 unk2C[12];                          /* 0x2C */
}; // size 0x5C

struct meshdef0_prelude_entry {
    u32 flags;                        /* 0x0 */
    struct meshdef0 *meshdef0_offset; /* 0x4 */
}; // size 0x8

struct meshdef0_prelude {
    u16 meshdef0_count;                    /* 0x0 */
    u16 meshdef1_count;                    /* 0x2 */
    struct meshdef0_prelude_entry ents[1]; /* 0x4 In reality this has a variable size, setting it to 1 to satisfy the compiler */
}; // size variable

struct meshdef1_prelude {
    u16 meshdef0_count;             /* 0x0 */
    u16 meshdef1_count;             /* 0x2 */
    u32 meshdef1_offsets_mostly[1]; /* 0x4 In reality this has a variable size, setting it to 1 to satisfy the compiler */
    u32 zero_word;                  /* 0x?? */
}; // size variable

struct object_entry {
    char object_name[16];                                 /* 0x00 */
    struct meshdef0 *meshdef0;                            /* 0x10 */
    struct meshdef0_prelude *meshdef0_prelude_offset;     /* 0x14 */
    struct meshdef1_prelude *meshdef1_prelude_offsets[4]; /* 0x18 */
    u32 unknown_offsets[3];                               /* 0x28 */
    f32 afloat;                                           /* 0x34 */
    u16 ashort;                                           /* 0x38 */
    u16 bshort;                                           /* 0x3A */
    f32 afloat_list[7];                                   /* 0x3C */
    u32 header_end_offset;                                /* 0x58 */
    f32 bfloat_list[6];                                   /* 0x5C */
}; // size 0x74

#endif
