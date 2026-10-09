#ifndef MAIN_08510_H
#define MAIN_08510_H

#include "PR/ultratypes.h"
#include "PR/gbi.h"

#include "hob.h"

struct DisplayListBuffer {
    struct DisplayListBuffer *next; /* 0x000 */
    struct DisplayListBuffer *prev; /* 0x004 */
    Gfx displayList[0x20];          /* 0x008 */
}; // size 0x108

struct D_main_bss_8011A444 {
    /* 0x0 */ u16 material_type;
    /* 0x2 */ u16 D_80128F08_index;
}; // size 0x4

struct timeSnapshotFiller_arg0 {
    u32 unk00; /* 0x00 */
    u32 unk04; /* 0x04 */
    u32 unk08; /* 0x08 */
    f32 unk0C; /* 0x0C */
    f32 unk10; /* 0x10 */
    f32 unk14; /* 0x14 */
    f32 unk18; /* 0x18 */
    f32 unk1C; /* 0x1C */
    f32 unk20; /* 0x20 */
    f32 unk24; /* 0x24 */
}; // size 0x28

extern struct D_main_bss_8011A444 *D_main_bss_8011A444;

void registerSiCallback(void (*)(void));
void heapFreeListInsert(struct DisplayListBuffer*);
s32  countDisplayListChunks(void);
struct DisplayListBuffer *reclaimDisplayListChunk(void);
Gfx *allocateDisplayListBuffer(void);
void enqueueMeshForDeferredRelease(struct meshdef1*);
s32  frameStartReset(void);
s32  waitForPrevFrameDone(void);
s32  drawFrameProfilerBars(void);
void computeFrameDeltaTime(void);
s32  timeSnapshotFiller(struct timeSnapshotFiller_arg0*);
void bufferArbiterProducerScanWait(void);
s32  submitGfxFrame(void);
s32  selectRenderPresetByIndex(u8);
s32  selectSecondaryPresetByIndex(u8);
s32  setMissionLevelInitByte(s8);
s32  resetMaterialPoolWrapper(void);

#endif
