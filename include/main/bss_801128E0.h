#ifndef BSS_801128E0_H
#define BSS_801128E0_H

#include "PR/os.h"
#include "PR/ultratypes.h"

// Commented out variables are fake

extern u8 D_main_bss_801143B0[0x2000]; // video thread stack
extern OSMesgQueue D_main_8011A420;
extern u8  *D_main_bss_8011A7D0;
extern u8  *D_main_bss_8011A7D8;
extern OSMesgQueue D_main_bss_8011A800;
extern OSMesgQueue D_main_bss_8011A818;
extern u32 D_main_bss_8011A838;
extern u32 D_main_bss_8011A83C;
extern s16 D_main_bss_8011A848;
extern u8  *D_main_bss_8011A850;
extern u8  *D_main_bss_8011A854;
extern u8  D_main_bss_8011A860[];
extern void (*D_main_bss_8011A8A4[4])(void);
// nonmatching D_main_bss_8011A8B0, 0x4
extern u16 D_main_bss_8011A8B4;
extern s32 D_main_bss_80128E90;
extern s32 D_main_bss_80128E94;
extern OSViMode D_main_bss_80128D50[];
extern OSMesgQueue D_main_bss_80128D10;
extern OSViMode D_main_bss_80128C90;
// nonmatching D_main_bss_80128CC0, 0x2
// nonmatching D_main_bss_80128CC2, 0x12
// nonmatching D_main_bss_80128CD4, 0x2
// nonmatching D_main_bss_80128CD6, 0xA
extern OSMesgQueue D_main_bss_80128CF0;
extern u8  D_main_bss_80128D2C;
extern u32 D_main_bss_80128D34;
extern s32 D_main_bss_80128EB4;
extern s32 D_main_bss_80128EB8;
extern s32 D_main_bss_80128EBC;

#endif
