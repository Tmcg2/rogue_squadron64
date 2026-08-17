#ifndef MAIN_04080_H
#define MAIN_04080_H

#include "PR/ultratypes.h"

#include "zlib/zlib_types.h"

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
        u32 size;                    /* 0x20 */
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
        u32 size;                    /* 0x20 */
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
        u32 size;                    /* 0x20 */
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

#endif
