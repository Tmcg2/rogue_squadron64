#ifndef MAIN_1D000_H
#define MAIN_1D000_H

#include "PR/ultratypes.h"
#include "main/08510.h"

struct MaterialPoolEntry {
    struct MaterialPoolEntry *next;    /* 0x00 */
    struct MaterialPoolEntry *prev;    /* 0x04 */
    u16   unk08;                       /* 0x08 */
    u16   unk0A;                       /* 0x0A */
    u8    unk0C;                       /* 0x0C */
    u8    unk0D;                       /* 0x0D */
    u8    unk0E;                       /* 0x0E */
    u8    unk0F;                       /* 0x0F */
    u32   unk10;                       /* 0x10 */
    struct DisplayListBuffer *unk14;   /* 0x14 */
}; // size 0x18

struct D_main_bss_80128F08 {
    u8    unk00;            /* 0x00 */
    u8    unk01;            /* 0x01 */
    u8    unk02;            /* 0x02 */
    u8    unk03;            /* 0x03 */
    u32   unk04;            /* 0x04 */
    u16   width;            /* 0x08 */
    u16   height;           /* 0x0A */
    u16   texture_size;     /* 0x0C */
    u16   unk0E;            /* 0x0E */
    void *texture_data;     /* 0x10 */
    u8    texture_name[16]; /* 0x14 */
}; // size 0x24

u16   decodeRdpFormatFlags(u16);
u16   decodeRdpSizeFlags(u16);
void  resetMaterialPool(void);
u8    buildMaterialFreeList(void);
s32   createMaterialPool(void);
u16   getTextureLUTFieldAt8(u16);
u16   getTextureLUTFieldAtA(u16);
s32   getTextureDimsBySlot(u16, u16*, u16*);
s32   unlinkTextureMaterialList(u16);
void  tickTextureMaterialExpiry(void);
void *findAndUnlinkSmallestEntry(void);
struct MaterialPoolEntry *popMaterialNodeIntoBucket(u16);
void *getTextureDataByMaterialId(u16);
s32   returnOne_80023334(void);
s32   returnOne_8002335C(void);
u16   getTextureAttrBySlot(u16);
s32   unpackTlutToRgbaBytes(u16, u8*, u8, u8, u8);
s32   shiftTlutEntryWithinChunk(u16, u8, u8, s8);

#endif
