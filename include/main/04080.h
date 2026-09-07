#ifndef MAIN_04080_H
#define MAIN_04080_H

#include "PR/ultratypes.h"
#include "PR/os.h"

#include "zlib/zlib.h"

struct data_block_header_entry {
    u8 name[16];     /* 0x00 */
    u32 unk10;       /* 0x10 */
    u32 unk14;       /* 0x14 */
    u32 unk18;       /* 0x18 If this is nonzero then this data block's manifest won't get DMA'd. I don't get why that would ever be useful */
    u32 data_offset; /* 0x1C offset after data block header to the data block for this entry */
}; // size 0x20

struct D_80110A80_entry {
    u8 unk00[0x20];                  /* 0x00 */
    u8 unk20[0x20];                  /* 0x20 */
    struct manifest_entry *manifest; /* 0x40 */
    u8 *data;                        /* 0x44 pointer to the data block that the manifest refers to. Is a ROM pointer as well, weirdly */
    u32 entry_count;                 /* 0x48 number of entries in the manifest/number of files in the data block (same thing really) */
    u16 unk4C;                       /* 0x4C */
    u8  one;                         /* 0x4E */
    u8  unk4F;                       /* 0x4F */
}; // size 0x50

struct D_80110BC0_type {
    u8 unk00;                        /* 0x00 */
    struct manifest_entry *manfiest; /* 0x04 */
    u32 unk08;                       /* 0x08 */
    u16 unk0C;                       /* 0x0C */
    u16 pad0E;                       /* 0x0E */
    u32 unk10;                       /* 0x10 */
    u32 unk14;                       /* 0x14 */
}; // size = 0x18

union D_80111100_type {
    struct {
        u8  flags;                   /* 0x00 */
        u8  unk01;                   /* 0x01 */
        u16 unk02;                   /* 0x02 */
        u32 unk04;                   /* 0x04 */
        u32 unk08;                   /* 0x08 */
        u32 unk0C;                   /* 0x0C */
        union D_80111100_type *next; /* 0x10 */
        u16 unk14;                   /* 0x14 */
        u16 unk16;                   /* 0x16 */
        void *source;                /* 0x18 */
        u32 offset;                  /* 0x1C */
        u16 size;                    /* 0x20 */
        u16 pad22;                   /* 0x22 */
        void *destination;           /* 0x24 */
    } flag_8000;
    struct {
        u8  flags;                   /* 0x00 */
        u8  unk01;                   /* 0x01 */
        u16 unk02;                   /* 0x02 */
        u32 unk04;                   /* 0x04 */
        u32 unk08;                   /* 0x08 */
        u32 unk0C;                   /* 0x0C */
        union D_80111100_type *next; /* 0x10 */
        u32 unk14;                   /* 0x14 */
        void *source;                /* 0x18 */
        u32 offset;                  /* 0x1C */
        u16 size;                    /* 0x20 */
        u16 pad22;                   /* 0x22 */
        void *destination;           /* 0x24 */
    } flag_8001;
    struct {
        u8  flags;                   /* 0x00 */
        u8  unk01;                   /* 0x01 */
        u16 unk02;                   /* 0x02 */
        u32 unk04;                   /* 0x04 */
        u32 unk08;                   /* 0x08 */
        u32 unk0C;                   /* 0x0C */
        union D_80111100_type *next; /* 0x10 */
        u32 unk14;                   /* 0x14 */
        void *source;                /* 0x18 */
        u32 offset;                  /* 0x1C */
        u16 size;                    /* 0x20 */
        u16 pad22;                   /* 0x22 */
        void *destination;           /* 0x24 */
    } flag_8002;
}; // size = 0x28

struct D_80110D60_type {
    u8       unk00;     /* 0x00 */
    u8       unk01;     /* 0x01 */
    u16      unk02;     /* 0x02 */
    union D_80111100_type *unk04; /* 0x04 */
    u16      unk08;     /* 0x08 */
    u16      unk0A;     /* 0x0A */
    u32      unk0C;     /* 0x08 */
    z_stream stream;    /* 0x10 */
    u32      unk48[11]; /* 0x48 */
}; // size = 0x74

s32   submitDmaSlot(u8*, u8*, s32);
void  waitDmaSlotComplete(s32);
s32   pollDmaSlotStep(s32);
struct manifest_entry *find_manifest_entry(s32, u8*, u32);
s32   pushEventToRingBuffer(union D_80111100_type*);
s32   subscribeEventHandler(s32*);
s32   freeManifestSegmentAssets(s32);
void  noopHandler_80004FC8(void);
void  noopHandler_80004FD0(void);
s32   setManifestEntryName(s32, u8*);
s32   get_manifest_entry_type(u32, u8*);
s32   zlibReturnZeroStub(void);
void  synchronousDmaTransfer(u8*, u8*, s32);
void *mallocWithFallbackStrategy(s32);
void  rs_zcfree(void*);
void *rs_zcalloc(u32, u32);
s32   returnNegativeOneStub(void);
s32   returnZeroStubZlib(void);
u8   *resolveAssetRamAddress(s32);
u8    getDmaSlotMutex(void);
void  setDmaWorkerPriority(s32);

// We have to extern everything, otherwise GCC does some wacky variable reordering
// In reality, all I want extern'd is `dmaSlotMaxTxStepSize`
extern OSMesg      D_main_801107A0[8];
extern OSMesgQueue D_main_801107C0;
extern u32 bss_pad0_04080;
extern OSIoMesg    D_main_801107E0[8];
extern OSMesg      dmaSlotMesgBuffer[8];
extern OSMesgQueue dmaSlotMesgQueue[8];
extern OSMesg      gDmaSlotLockMesg;
extern u32 bss_pad1_04080;
extern u32 bss_pad2_04080;
extern OSMesgQueue gDmaSlotLockQueue;
extern s32         nextOpenDmaSlot;
extern s32         dmaSlotsAvailable;
extern u8         *dmaSlotDestAddr[8];
extern s32         dmaSlotTotalTxSize[8];
extern u8         *dmaSlotSrcAddr[8];
extern s32         dmaSlotTxSoFar[8];
extern s32         dmaSlotTxRemaning[8];
extern s32         dmaSlotTxThisStep[8];
extern volatile u8 dmaSlotMutex;
extern u8 bss_pad3_04080;
extern u8 bss_pad4_04080;
extern u8 bss_pad5_04080;
extern struct data_block_header_entry *D_main_bss_80110A74;
extern u32 bss_pad6_04080;
extern u32 bss_pad7_04080;
extern struct D_80110A80_entry gManifestTable[4]; // The name of this variable is wonky because otherwise it gets placed in the BSS section incorrectly
extern struct D_80110BC0_type  D_main_80110BC0[16];
extern s32 D_main_bss_80110D40;
extern u8 *D_main_bss_80110D44;
extern s32 D_main_bss_80110D48;
extern s32 D_main_bss_80110D4C;
extern u8 *D_main_bss_80110D50;
extern s32 D_main_bss_80110D54;
extern u32 bss_pad8_04080;
extern u32 bss_pad9_04080;
extern struct D_80110D60_type D_main_bss_80110D60[8];
extern union  D_80111100_type gServiceWorkerMesgBuf[8];
extern u32 D_main_bss_80111240;
extern s32 D_main_bss_80111244;
extern s32 D_main_bss_80111248;
extern s32 D_main_bss_8011124C;
extern s32 D_main_bss_80111250;
extern u32 dmaSlotMaxTxStepSize;

#endif
