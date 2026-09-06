#include "common.h"

#include "PR/os.h"
#include "main/02490.h"

struct D_main_bss_8010FF08_type {
    u32 dataAddress; /* 0x0 */
    u32 dataSize;    /* 0x4 */
}; // size 0x8

struct heapBlockHeader {
    u16 unk00;  /* 0x00 */
    u16 flags;  /* 0x02 */
    u32 size;   /* 0x04 */
    u32 pad[2]; /* 0x08 */
}; // size 0x10;

OSMesgQueue D_main_8010FEE0;
OSMesg D_main_bss_8010FEF8;
struct heapBlockHeader *D_main_bss_8010FEFC;
struct heapBlockHeader *D_main_bss_8010FF00;
u32 bss_pad_02490;
struct D_main_bss_8010FF08_type *D_main_bss_8010FF08;
u32 D_main_bss_8010FF0C;
struct heapBlockHeader *D_main_bss_8010FF10;
struct heapBlockHeader *D_main_bss_8010FF14;
struct heapBlockHeader *D_main_bss_8010FF18;

INCLUDE_ASM("asm/nonmatchings/main/02490", ensureHeapInitialized);

u32 getTotalFreeHeapSize(void) {
    u32 var_a1;
    struct heapBlockHeader *var_a0;
    u32 var_a2;

    var_a0 = D_main_bss_8010FF18;
    var_a1 = 0;
    var_a2 = 0;
    while ((var_a2 < 2) & (var_a0 != NULL)) {
        while (!(var_a0->unk00 & 8)) {
            if (var_a0->unk00 & 1) var_a1 += var_a0->size;
            var_a0 = (struct heapBlockHeader*)((u32)var_a0 + var_a0->size + sizeof(struct heapBlockHeader));
        }
        var_a0 = D_main_bss_8010FF00;
        var_a2++;
    }
    return var_a1;
}

u32 findLargestFreeHeapChunk(void) {
    s32 var_a1;
    struct heapBlockHeader *var_a0;
    u32 var_a2;

    var_a0 = D_main_bss_8010FF18;
    var_a1 = 0;
    var_a2 = 0;
    while ((var_a2 < 2) & (var_a0 != NULL)) {
        while (!(var_a0->unk00 & 8)) {
            if ((var_a0->unk00 & 1) && (var_a1 < var_a0->size)) var_a1 = var_a0->size;
            var_a0 = (struct heapBlockHeader*)((u32)var_a0 + var_a0->size + sizeof(struct heapBlockHeader));
        }
        var_a0 = D_main_bss_8010FF00;
        var_a2++;
    }
    return var_a1;
}

void *rs_malloc(u32 size, u16 flags) {
    struct heapBlockHeader *sp10[2];
    struct heapBlockHeader *var_a0;
    struct heapBlockHeader *var_a1;
    struct heapBlockHeader *var_s2;
    u32 blockSize;
    u32 var_a2;
    u32 var_t0;
    struct heapBlockHeader *temp_a0;

    var_s2 = NULL;
    if (size != 0) {
        osRecvMesg(&D_main_8010FEE0, NULL, 1);
        blockSize = (size + 0xF) & ~0xF;
        if (flags & 4) {
            ensureHeapInitialized();
            var_t0 = 1;
            if (D_main_bss_8010FEFC == NULL) goto why;
            sp10[0] = D_main_bss_8010FEFC;
        } else {
            if (D_main_bss_8010FF00 != NULL) {
                if (flags & 0x10) {
                    sp10[0] = D_main_bss_8010FF00;
                    sp10[1] = D_main_bss_8010FF18;
                } else {
                    sp10[0] = D_main_bss_8010FF18;
                    sp10[1] = D_main_bss_8010FF00;
                }
                var_t0 = 2;
            } else {
                var_t0 = 1;
                sp10[0] = D_main_bss_8010FF18;
            }
        }
        var_a1 = NULL;
        for (var_a2 = 0; var_a2 < var_t0; var_a2++) {
            var_a0 = sp10[var_a2];
            while(!(var_a0->unk00 & 8)) {
                // I hate this, but I can't get it to match any other way...
                if ((var_a0->unk00 & 1) && (var_a0->size >= blockSize) && (var_a1 = var_a0, ((flags & 0x88) != 8))) break;
                var_a0 = (u32)var_a0 + var_a0->size + sizeof(struct heapBlockHeader);
            }
            if (var_a1 == NULL) continue;
            var_s2 = var_a1 + 1;
            var_a1->unk00 = 2;
            var_a1->flags = flags;
            if (blockSize != var_a1->size) {
                temp_a0 = (u32)var_s2 + blockSize;
                if ((u32) (var_a1->size - blockSize) >= 0x20U) {
                    temp_a0->unk00 = 1;
                    temp_a0->size = (s32) ((var_a1->size - blockSize) - 0x10);
                    var_a1->size = blockSize;
                }
            }
            break;
        }
why:
        osSendMesg(&D_main_8010FEE0, NULL, 0);
    }
    return var_s2;
}

INCLUDE_ASM("asm/nonmatchings/main/02490", rs_free);

INCLUDE_ASM("asm/nonmatchings/main/02490", buildHeapFreeList);

#if 0
void initMainHeap(u32 arg0, struct D_main_bss_8010FF08_type *arg1, struct heapBlockHeader *arg2, struct heapBlockHeader *arg3) {
    s32 temp_v1;
    s32 var_t1;
    struct heapBlockHeader *temp_t0;
    struct D_main_bss_8010FF08_type *var_a1;
    struct heapBlockHeader *var_a2;
    struct heapBlockHeader *temp_a0;
    u32 temp_a2;
    u32 var_t2;
    struct heapBlockHeader *temp_a3;
    struct heapBlockHeader *temp_v1_2;

    D_main_bss_8010FF08 = arg1;
    D_main_bss_8010FF0C = arg0;
    D_main_bss_8010FF10 = arg2;
    D_main_bss_8010FF14 = arg3;
    osCreateMesgQueue(&D_main_8010FEE0, &D_main_bss_8010FEF8, 1);
    osSendMesg(&D_main_8010FEE0, NULL, 0);
    D_main_bss_8010FF18 = arg2;
    arg2->unk00 = 1;
    arg2->flags = 0;
    arg2->size = ((u32)arg3 - (u32)arg2) - 0x20;
    do { } while (0); // ???
    (arg3 - 1)->unk00 = 8;
    (arg3 - 1)->flags = 0;
    (arg3 - 1)->size = 0;
    for (var_t2 = 0; var_t2 < arg0; var_t2++) {
        var_a1 = &arg1[var_t2];
        var_a2 = D_main_bss_8010FF18;
        var_t1 = (var_a1->dataSize + 0xF) & ~0xF;
        temp_a0 = (struct heapBlockHeader *)(var_a1->dataAddress - 0x10);
        while (!(var_a2->unk00 & 8)) {
            temp_a3 = (u32)var_a2 + var_a2->size;
            temp_t0 = (u32)temp_a3 + 0x10;
            if ((temp_a0 >= (u32) var_a2) & (temp_a0 < (u32) temp_t0)) {
                temp_a0->unk00 = 6;
                temp_a0->flags= 0;
                if (temp_a0 != var_a2) {
                    var_a2->size = ((u32)temp_a0 - (u32)var_a2) - 0x10;
                }
                temp_v1 = ((u32)temp_t0 - (u32)temp_a0) - 0x10;
                temp_a2 = (u32)temp_v1 - var_t1;
                if (temp_v1 != var_t1) {
                    if (temp_a2 >= 0x21U) {
                        temp_v1_2 = (u32)temp_a0 + var_t1;
                        (temp_v1_2 + 1)->unk00 = 1;
                        (temp_v1_2 + 1)->flags = 0;
                        (temp_v1_2 + 1)->size = (s32) (temp_a2 - 0x10);
                    } else {
                        var_t1 = temp_v1;
                    }
                }
                temp_a0->size= var_t1;
                break;
            } else {
                var_a2 = temp_t0;
            }
        }
    }
    D_main_bss_8010FF00 = NULL;
    D_main_bss_8010FEFC = NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/02490", initMainHeap);
#endif

INCLUDE_ASM("asm/nonmatchings/main/02490", coalesceFreeHeapBlocks);
