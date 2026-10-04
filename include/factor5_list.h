#ifndef FACTOR5_LIST_H
#define FACTOR5_LIST_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct factor5_list_node {
    struct factor5_list_node *next; /* 0x00 */
    struct factor5_list_node *prev; /* 0x04 */
    u32   unk08; /* 0x08 */
    Vec3f unk0C; /* 0x0C */
    Vec3f unk18; /* 0x18 */
    f32   unk24; /* 0x24 */
    f32   unk28; /* 0x28 */
    f32   unk2C; /* 0x2C */
    f32   unk30; /* 0x30 */
    s32   unk34; /* 0x34 */
    u32   unk38; /* 0x38 */
    u16   unk3C; /* 0x3C */
    u16   unk3E; /* 0x3E */
}; // size 0x40

#endif
