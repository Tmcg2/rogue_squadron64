#ifndef FONT_H
#define FONT_H

#include "hud.h"

struct someFontThing {
    u16 symbolCount;                 /* 0x000 */
    s16 unk002;                      /* 0x002 */
    s16 unk004;                      /* 0x004 */
    s16 unk006;                      /* 0x006 */
    s16 unk008;                      /* 0x008 */
    s16 unk00A;                      /* 0x00A */
    char *symbolList;                /* 0x00C */
    char *fontName;                  /* 0x010 */
    void *unk014;                    /* 0x014 */
    u8 *unk018;                      /* 0x018 */
    u8 unk01C;                       /* 0x01C */
    u8 unk01D;                       /* 0x01D */
    u8 unk01E;                       /* 0x01E */
    u8 unk01F;                       /* 0x01F */
    void *unk020;                    /* 0x020 */
    u16 *unk024;                     /* 0x024 */
    u16 *unk028;                     /* 0x028 */
    u32 unk02C;                      /* 0x02C */
    u32 unk030;                      /* 0x030 */
    struct ui_element *unk034[0x14]; /* 0x034 */
    u8 unk084[0x14];                 /* 0x084 */
    u16 unk098[0x14][2];             /* 0x098 */
    u32 unk0E8;                      /* 0x0E8 */
    void *unk0EC;                    /* 0x0EC */
    void *unk0F0;                    /* 0x0F0 */
    u32 unk0F4;                      /* 0x0F4 */
    u32 unk0F8;                      /* 0x0F8 */
    void *unk0FC;                    /* 0x0FC */
    u16 unk100;                      /* 0x100 */
    u8 unk102;                       /* 0x102 */
    u8 unk103;                       /* 0x103 */
}; // size = 0x104

extern struct someFontThing *D_main_8009FC10[0xC];

#endif
