#ifndef BSS_80139020_H
#define BSS_80139020_H

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
extern u16 D_main_bss_80139560[0x20];
extern struct object_entry *D_main_bss_801395E0[0xF];
extern u16 D_main_bss_80139738;

#endif
