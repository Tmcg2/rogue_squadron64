#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include "PR/ultratypes.h"

struct game_config_0x10 {
    u16 unk0; /* 0x0 */
    u16 unk2; /* 0x2 */
    u16 unk4; /* 0x4 */
    u16 unk6; /* 0x6 */
    u16 unk8; /* 0x8 */
    u16 unkA; /* 0xA */
}; // size 0xC

struct game_config_0x1C {
    u32 unk00; /* 0x00 */
    u8  unk04; /* 0x04 */
    u8  unk05; /* 0x05 */
    u16 unk06; /* 0x06 */
    u32 unk08; /* 0x08 */
    u32 unk0C; /* 0x0C */
}; // size 0x10

struct game_config_0x2C {
    u32 unk00; /* 0x00 */
    u32 unk04; /* 0x04 */
    u32 unk08; /* 0x08 */
    u32 unk0C; /* 0x0C */
    u16 unk10; /* 0x10 */
    u16 unk12; /* 0x12 */
    u16 unk14; /* 0x14 */
    u16 unk16; /* 0x16 */
    u32 unk18; /* 0x18 */
}; // size 0x1C

struct game_config  {
    u32 unk00;                     /* 0x00 */
    void (*unk04)(s32*);           /* 0x04 */
    u32 unk08;                     /* 0x08 */
    u32 unk0C;                     /* 0x0C */
    struct game_config_0x10 unk10; /* 0x10 */
    struct game_config_0x1C unk1C; /* 0x1C */
    struct game_config_0x2C unk2C; /* 0x2C */
    u32 unk48;                     /* 0x48 */
    u32 unk4C;                     /* 0x4C */
}; // size 0x50

extern struct game_config gBootConfig;

#endif
