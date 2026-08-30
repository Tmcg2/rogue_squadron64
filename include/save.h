#ifndef SAVE_H
#define SAVE_H

#include "PR/ultratypes.h"

struct account_data {
    /* 0x00 */ char name[4]; // has a null-terminator (I think?)
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  unk05;
    /* 0x06 */ u8  unk06;
    /* 0x07 */ u8  unk07;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8  accountNumber;
    /* 0x11 */ u8  padding[3];
}; // size 0x14

struct EliteRogueData {
    /* 0x0 */ char name[3]; // really just 3 characters, no null terminator
    /* 0x3 */ u8 current_level; // should be an enum Level but enum entires are sized too big
    // Don't know if its a bit field, or if its just a u16 that they pick apart by hand
    /* 0x4 */ union {
        u16 as_short;
        struct {
            u16 pad     : 1;
            u16 golds   : 5;
            u16 silvers : 5;
            u16 bronzes : 5;
        } as_bit_field;
    } medals;
    /* 0x6 */ u8 accountNumber; // I think?
    /* 0x7 */ u8 padding;
}; // size 0x8

struct D_8013A5C0_type {
    u32 unk00;                            /* 0x00 struct D_80130B40_type.unk10 */
    u32 unk04;                            /* 0x04 struct D_80130B40_type.unk0C & 0x8B */
    u32 cheatCodeFlags[2];                /* 0x08 */
    u8  musicVolume;                      /* 0x10 */
    u8  soundFxVolume;                    /* 0x11 */
    u8  speechVolume;                     /* 0x12 */
    u8  controllerSetting;                /* 0x13 */
    struct account_data accounts[3];      /* 0x14 */
    u8 unk50;                             /* 0x50 has a value, unsure of purpose */
    u8 unk51;                             /* 0x51 */
    // This stuff is aligned super weirdly, so being a proper struct may not work, only time will tell
    struct EliteRogueData highscores[10]; /* 0x52 */
    u8  unkA2;                            /* 0xA2 */
    u8  unkA3[8];                         /* 0xA3 */
    u8  languageSelect;                   /* 0xAB */
    u8  unkAC;                            /* 0xAC */
}; // size 0xB0

extern struct D_8013A5C0_type gSaveDataBody; // 0x8013A5C0

#endif
