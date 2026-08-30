#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include "PR/ultratypes.h"

/*
This is something of a dumping ground for types that are used in a variety of places.
Hopefully it doesn't become too much of a type landfill.
*/

//////////////////////////////////////////////////////////////
// TYPEDEFS
//////////////////////////////////////////////////////////////

typedef f32 Vec3f[3];
typedef f32 Vec4f[4];
typedef f32 Mat4x3[4][3];

//////////////////////////////////////////////////////////////
// ENUMS
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// STRUCTS
//////////////////////////////////////////////////////////////

struct rgba {
    u8 r; /* 0x0 */
    u8 g; /* 0x1 */
    u8 b; /* 0x2 */
    u8 a; /* 0x3 */
}; // size = 0x4

struct manifest_entry {
    u32 data_offset;       /* 0x00 */
    u32 decompressed_size; /* 0x04 */
    u32 compressed_size;   /* 0x08 0xFFFFFFFF (or -1 if signed) indicates that the entry is not compressed */
    /*
    bit 7: is directory (0x80)
    bits 1-6: never set, checked in several places though
    bit 0: set a lot (but not alwasy). Purpose unknown
    */
    u8 flags; /* 0x0C */
    u8 unk0D; /* 0x0D */
    /*
    This is a number multiplied by 0x20 (<< 5)
    It is the size in bytes that the directory takes up in the manifest
    So, (directory content entries + 1(the directory entry itself)) * 0x20
    For non-directory entries, this number should be zero 
    */
    u16 directory_size; /* 0x0E */
    u8 name[16];        /* 0x10 */
}; // size 0x20

#endif