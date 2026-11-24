#ifndef PLAYER_H
#define PLAYER_H

#include "PR/ultratypes.h"

#include "crafts.h"
#include "factor5_list.h"
#include "hob.h"

struct inner_player_struct {
    struct object_entry *object;      /* 0x000 */
    f32 posX;                         /* 0x004 */
    f32 posY;                         /* 0x008 */
    f32 posZ;                         /* 0x00C */
    f32 unk010;                       /* 0x010 */
    f32 unk014;                       /* 0x014 */
    f32 unk018;                       /* 0x018 */
    f32 unk01C;                       /* 0x01C */
    f32 unk020;                       /* 0x020 */
    f32 unk024;                       /* 0x024 */
    f32 unk028;                       /* 0x028 */
    f32 unk02C;                       /* 0x02C */
    f32 unk030;                       /* 0x030 */
    u16 unk034[0x40];                 /* 0x034 */
    u16 unk0B4;                       /* 0x0B4 */
    u16 unk0B6;                       /* 0x0B6 */
    s32 unk0B8;                       /* 0x0B8 */
    void *unk0BC;                     /* 0x0BC */
    f32 currentHealth;                /* 0x0C0 */
    f32 maxHealth;                    /* 0x0C4 */
    f32 advancedShieldTimer;          /* 0x0C8 */
    f32 unk0CC[0x23];                 /* 0x0CC */
    u16 blaster_to_fire;              /* 0x158 */
    u16 pad15A;                       /* 0x15A */
    u32 fire_mode;                    /* 0x15C */
    f32 unk160[0x03];                 /* 0x160 */
    f32 blasterDamageMultiplier;      /* 0x16C */
    f32 unk170[0x02];                 /* 0x170 */
    u32 unk178[0x12];                 /* 0x178 */
    s32 unk1C0;                       /* 0x1C0 */
    s32 unk1C4;                       /* 0x1C4 */
    s32 unk1C8;                       /* 0x1C8 */
    u16 unk1CC;                       /* 0x1CC */
    u16 unk1CE;                       /* 0x1CE */
    u32 unk1D0[(0x208 - 0x1D0) / 4];  /* 0x1D0 */
    struct factor5_list_node unk208;  /* 0x208 */
    u32 unk248;                       /* 0x248 */
    u8  unk24C;                       /* 0x24C */
    u8  unk24D;                       /* 0x24D */
    u8  unk24E;                       /* 0x24E */
    u8  unk24F;                       /* 0x24F */
    f32 unk250[(0x28C - 0x250) / 4];  /* 0x24C */
    u16 unk28C;                       /* 0x28C */
    u16 unk28A;                       /* 0x28A */
    enum PlayerCraft vehicleId;       /* 0x290 */
    u32 unk294;                       /* 0x294 */
    u32 unk298;                       /* 0x298 */
}; // size 0x29C

struct player_struct {
    u8 unk000;                        /* 0x000 */
    u8 unk001;                        /* 0x001 */
    u16 unk002;                       /* 0x002 */
    struct inner_player_struct inner; /* 0x004 */
}; // size 0x2A0

extern struct player_struct gPlayers[]; // 0x80137DB8

#endif
