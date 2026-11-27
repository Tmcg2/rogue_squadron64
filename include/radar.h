#ifndef RADAR_H
#define RADAR_H

#include "PR/ultratypes.h"

#include "hob.h"
#include "textures.h"

struct RadarPixelBackup {
    u16 tlPixelIndex;    /* 0x00 */
    u8 tlOrigColorIndex; /* 0x02 */
    u8 trOrigColorIndex; /* 0x03 */
    u8 blOrigColorIndex; /* 0x04 */
    u8 brOrigColorIndex; /* 0x05 */
}; // size = 0x6

// The radar is a more set-in-stone entity than other models/meshes with faces, so we'll use a more definite struct for its faces to make usage easier
struct radar_face {
    u32 flags;                    /* 0x00 */
    // struct {
    //     u32 unused                    : 2;
    //     u32 face_size                 : 6; // multiply by 4 to get the actual size
    //     u32 vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
    //     u32 vertex_color_offset       : 6; // multiply by 4 to get the actual offset
    //     u32 vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
    //     u32 texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
    // } stuffed_data;
    u32 stuffed_data;             /* 0x04 */
    u32 unk08;                    /* 0x08 */
    u16 vertex_indices[3];        /* 0x0C */
    u16 pad12;                    /* 0x12 */
    u32 texture_coordinates[3];   /* 0x14 */
    struct rgba vertex_colors;    /* 0x20 */
}; // size 0x24

struct Radar {
    // The Radar dispalyed in the HUD is a CI4 image projected onto a plane on-screen
    u8 colorIndexes[0x800];                   /* 0x000 */
    struct material_entry material;           /* 0x800 */
    struct texture_entry texture;             /* 0x824 */
    u16 textureId1;                           /* 0x858 */
    u16 textureId2;                           /* 0x85A */
    s16 unk85C;                               /* 0x85C */
    s16 unk85E;                               /* 0x85E */
    Mat4x3 matrix1;                           /* 0x860 */
    struct meshdef0_inner radarmeshdef0;      /* 0x890 */
    struct meshdef1 radarmeshdef1;            /* 0x8DC */
    struct facegroup facegroup;               /* 0x938 */
    struct vertex hudOctagonCorners[8];       /* 0x948 */
    struct vertex hudObjectiveSlice[3];       /* 0x988 */
    struct vertex cockpitOctagonCorners[8];   /* 0x9A0 */
    struct vertex cockpitObjectiveSlice[3];   /* 0x9E0 */
    struct radar_face faces[16];              /* 0x9F8 */
    struct RadarPixelBackup dotBackups[0x40]; /* 0xC38 */
    u16 numRadarDots;                         /* 0xDB8 */
    u16 padDBA;                               /* 0xDBA */
    f32 unkDBC;                               /* 0xDBC */
    f32 unkDC0;                               /* 0xDC0 */
    f32 unkDC4;                               /* 0xDC4 */
    s16 unkDC8;                               /* 0xDC8 */
    s16 padDCA;                               /* 0xDCA */
    f32 unkDCC;                               /* 0xDCC */
    u8  unkDD0;                               /* 0xDD0 */
    // Probably 3 bytes of padding
}; // size = 0xDD4

#endif
