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
    // Technically, this type is in fact known (see hob_files.md), but its exact contents
    // are variable based on flags in the type itself.
    // I think that counts as the type being runtime polymorphic, kind of sort of?
    UNIDENTIFIED_TYPE *facegroup_pointer;   /* 0x20 */
    struct vertex *vertext_pointers[2];     /* 0x24 */
    f32 unk2C[12];                          /* 0x2C */
}; // size 0x5C

struct object_entry {
    char object_name[16];            /* 0x00 */
    struct meshdef0 *meshdef0;       /* 0x10 */
    u32 meshdef0_prelude_offset;     /* 0x14 */
    u32 meshdef1_prelude_offsets[4]; /* 0x18 */
    u32 unknown_offsets[3];          /* 0x28 */
    f32 afloat;                      /* 0x34 */
    u16 ashort;                      /* 0x38 */
    u16 bshort;                      /* 0x3A */
    f32 afloat_list[7];              /* 0x3C */
    u32 header_end_offset;           /* 0x58 */
    f32 bfloat_list[6];              /* 0x5C */
}; // size 0x74

#endif
