#ifndef BSS_80139010_H
#define BSS_80139010_H

#include "PR/ultratypes.h"
#include "common_types.h"
#include "hob.h"

struct D_main_bss_801394E8_type {
    struct object_entry *object_entry; /* 0x00 */
    UNIDENTIFIED_TYPE *unk04;          /* 0x04 */
    u16 unk08;                         /* 0x08 */
    u8  unk0A;                         /* 0x0A */
    u8  unk0B;                         /* 0x0B */
    struct meshdef0_inner meshdef0[1]; /* 0x0C */
    struct meshdef1 meshdef1[1];       /* 0x58 */
}; // size = 0xB4

extern struct D_main_bss_801394E8_type *D_main_bss_801394E8;
extern u16 D_main_bss_80139560[];
extern u32 gPreviousButtonsPressed[];
extern u32 gNewButtonsPressed[];

#endif
