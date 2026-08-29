#ifndef PLAYER_H
#define PLAYER_H

#include "PR/ultratypes.h"

#include "crafts.h"

struct meshdef1 {
    struct meshdef1 *next_meshdef1_pointer; /* 0x00 */
    struct meshdef1 *prev_meshdef1_pointer; /* 0x04 */
    u32 unk08;                              /* 0x08 */
    u32 unk0C;                              /* 0x0C */
    u32 unk10;                              /* 0x10 */
    u32 vertex_counts[2];                   /* 0x14 */
    f32 some_float;                         /* 0x1C */
    void *facegroup_pointer;                /* 0x20 */
    void *vertext_pointers[2];              /* 0x24 */
    f32 unk2C[12];                          /* 0x2C */
}; // size 0x5C

struct meshdef0 {
    struct meshdef0 *next_meshdef0_pointer;     /* 0x00 */
    struct meshdef0 *prev_meshdef0_pointer;     /* 0x04 */
    struct meshdef0 *unknown_meshdef0_pointer0; /* 0x08 */
    struct meshdef0 *unknown_meshdef0_pointer1; /* 0x0C */
    struct meshdef1 *meshdef1_pointer;          /* 0x10 */
    u32 unk14;                                  /* 0x14 */
    u32 unk18;                                  /* 0x18 */
    f32 big_block_o_floats[9];                  /* 0x1C */
    f32 pos[3];                                 /* 0x40 */
}; // size 0x4C

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

struct inner_player_struct {
    struct object_entry *object; /* 0x000 */
    f32 posX;                    /* 0x004 */
    f32 posY;                    /* 0x008 */
    f32 posZ;                    /* 0x00C */
    f32 unk010;                  /* 0x010 */
    f32 unk014;                  /* 0x014 */
    f32 unk018;                  /* 0x018 */
    f32 unk01C;                  /* 0x01C */
    f32 unk020;                  /* 0x020 */
    f32 unk024;                  /* 0x024 */
    f32 unk028;                  /* 0x028 */
    f32 unk02C;                  /* 0x02C */
    f32 unk030;                  /* 0x030 */
    u16 unk034[0x40];            /* 0x034 */
    u16 unk0B4;                  /* 0x0B4 */
    u16 unk0B6;                  /* 0x0B6 */
    s32 unk0B8;                  /* 0x0B8 */
    void *unk0BC;                /* 0x0BC */
    f32 currentHealth;           /* 0x0C0 */
    f32 maxHealth;               /* 0x0C4 */
    f32 advancedShieldTimer;     /* 0x0C8 */
    f32 unk0CC[0x23];            /* 0x0CC */
    u16 blaster_to_fire;         /* 0x158 */
    u16 pad15A;                  /* 0x15A */
    u32 fire_mode;               /* 0x15C */
    f32 unk160[0x03];            /* 0x160 */
    f32 blasterDamageMultiplier; /* 0x16C */
    f32 unk170[0x02];            /* 0x170 */
    u32 unk178[0x35];            /* 0x178 */
    f32 unk24C[0x10];            /* 0x24C */
    u16 unk28C;                  /* 0x28C */
    u16 unk28A;                  /* 0x28A */
    enum PlayerCraft vehicleId;  /* 0x290 */
    u32 unk294;                  /* 0x294 */
    u32 unk298;                  /* 0x298 */
}; // size 0x29C

struct player_struct {
    u8 unk000;                        /* 0x000 */
    u8 unk001;                        /* 0x001 */
    u16 unk002;                       /* 0x002 */
    struct inner_player_struct inner; /* 0x004 */
}; // size 0x2A0

extern struct player_struct gPlayers[]; // 0x80137DB8

#endif
