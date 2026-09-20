#ifndef SNG_H
#define SNG_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct SNG_unk00_type {
    u32 unk0; /* 0x0 */
    u8  unk4; /* 0x4 */
    u8  unk5; /* 0x5 */
    u16 pad6; /* 0x6 */
    s16 unk8; /* 0x8 might be u16? */
    u8  unkA; /* 0xA */
    u8  unkB; /* 0xB */
}; // size 0xC

struct SNG_unk04_unkC_type {
    u32 unk0; /* 0x0 */
    u16 unk4; /* 0x4 */
    u8  unk6; /* 0x6 */
    u8  unk7; /* 0x7 */
}; // size 0x8;

struct SNG_unk04_type {
    u32 unk0;                            /* 0x0 */
    UNIDENTIFIED_TYPE *unk4;             /* 0x4 */
    UNIDENTIFIED_TYPE *unk8;             /* 0x8 */
    // The array size here is artificial
    // In reality there is an unpredictable/unknowable(?) amount of entries
    // The array ends when there's an entry with both unk6 and unk7 set to 0xFF
    struct SNG_unk04_unkC_type *unkC[1]; /* 0xC */
}; // size variable

struct SNG_unk0C_type {
    u32 unk0; /* 0x0 */
    u32 unk4; /* 0x4 */
}; // size 0x8

struct D_main_80149A00_unk128_type {
    struct SNG_unk00_type *unk00; /* 0x00 */
    struct SNG_unk00_type *unk04; /* 0x04 */
    u32 unk08;                    /* 0x08 */
    u32 unk0C;                    /* 0x0C */
}; // size 0x10

struct D_main_bss_801511C0_type {
    struct D_main_bss_801511C0_type *unk00; /* 0x00 */
    struct D_main_bss_801511C0_type *unk04; /* 0x04 */
    s32 unk08;                              /* 0x08 */
    s32 unk0C;                              /* 0x0C */
    s32 unk10;                              /* 0x10 */
    s32 unk14;                              /* 0x14 */
}; // size 0x18

struct D_main_80149A00_unk568_type {
    u32 unk00;                         /* 0x00 0x568 */
    u32 unk04;                         /* 0x04 0x56C */
    struct SNG_unk04_unkC_type *unk08; /* 0x08 0x570 */
    UNIDENTIFIED_TYPE *unk0C;          /* 0x0C 0x574 same type as struct SNG_unk04_type unk4 */
    UNIDENTIFIED_TYPE *unk10;          /* 0x10 0x578 same type as struct SNG_unk04_type unk8 */
    u16 unk14;                         /* 0x14 0x57C */
    u16 unk16;                         /* 0x16 0x57E */
    u32 unk18;                         /* 0x18 0x580 */
    u32 unk1C;                         /* 0x1C 0x584 */
    u8  unk20;                         /* 0x20 0x588 */
    u8  unk21;                         /* 0x21 0x589 */
    u8  unk22;                         /* 0x22 0x58A */
    u8  unk23;                         /* 0x23 0x58B */
}; // size 0x24

struct SNG_file_header {
    struct SNG_unk00_type **unk00; /* 0x00 */
    struct SNG_unk04_type **unk04; /* 0x04 */
    u8 *unk08;                     /* 0x08 */
    struct SNG_unk0C_type *unk0C;  /* 0x0C */
    u32 unk10;                     /* 0x10 */
    u32 unk14;                     /* 0x14 */
};

struct D_main_bss_80149A00_type {
    u32 unk000;                                      /* 0x000 */
    u32 unk004[0x042];                               /* 0x004 */
    struct SNG_file_header *SNG_file;                /* 0x10C */
    s32 unk110[0x006];                               /* 0x110 */
    struct D_main_80149A00_unk128_type unk128[0x40]; /* 0x128 */
    u8  unk528[0x040];                               /* 0x528 */
    struct D_main_80149A00_unk568_type unk568[0x40]; /* 0x568 */
    struct SNG_unk0C_type *unkE68;                   /* 0xE68 */
    struct SNG_unk0C_type *unkE6C;                   /* 0xE6C */
    u32 unkE70;                                      /* 0xE70 */
    u32 unkE74;                                      /* 0xE74 */
    struct D_main_bss_801511C0_type *unkE78[0x10];   /* 0xE78 */
    UNIDENTIFIED_TYPE *unkEB8;                       /* 0xEB8 */
    UNIDENTIFIED_TYPE *unkEBC;                       /* 0xEBC */
    u8  unkEC0;                                      /* 0xEC0 */
    u8  unkEC1;                                      /* 0xEC2 */
    u8  unkEC2;                                      /* 0xEC2 */
    u8  unkEC3;                                      /* 0xEC3 */
    u8  unkEC4;                                      /* 0xEC4 */
    u8  unkEC5;                                      /* 0xEC5 */
    u16 unkEC6;                                      /* 0xEC6 */
    u32 unkEC8[0x00C];                               /* 0xEC8 */
}; // size 0xEF8

#endif
