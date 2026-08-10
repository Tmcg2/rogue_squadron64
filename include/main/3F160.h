#ifndef MAIN_3F160_H
#define MAIN_3F160_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct D_80130BB8_type;

typedef s32 (*npc_update)(struct D_80130BB8_type *self, u16 arg1, void *arg2);

struct D_80130BB8_type {
    npc_update update_func; /* 0x00 */
    void *unk04;            /* 0x04 */
    void *unk08;            /* 0x08 */
    u32 unk0C;              /* 0x0C */
    u32 unk10;              /* 0x10 */
    u16 unk14;              /* 0x14 */
    u16 unk16;              /* 0x16 */
    u8 unk18;               /* 0x18 */
    u8 unk19;               /* 0x19 */
    u8 unk1A;               /* 0x1A */
    u8 unk1B;               /* 0x1B */
    u16 unk1C[16];          /* 0x1C */
}; // size = 0x3C

struct D_80130BB0_type {
    struct D_80130BB8_type *unk00; /* 0x00 */
    u16 next_idx;                  /* 0x04 */
    u16 prev_idx;                  /* 0x06 */
}; // size = 0x8

void initNpcSlotList(void);
s32  allocateNpcSlot(struct D_80130BB8_type*);
u16  popNpcSlotFromTail(u16, struct D_80130BB8_type*);
void unregisterAndFreeNpcSlot(u16, struct D_80130BB8_type*);
s32  slotDispatcherIter(u16, s32, void*);
void slotDispatcherInner(struct D_80130BB8_type*);
void reinsertNpcIntoSortedFreeList(struct D_80130BB8_type*);
void destroyNpcSlotByIndex(u16);
void destroyNpcSlotChain(u16);
void freeNpcSlotArray(void);
void allocNpcContextArrays(void);
u16  spawnNpcWithSubtype(npc_update, void*, u32, u8);
u16  spawnNpcOfType(npc_update, void*arg1, u32, u8);
struct D_80130BB8_type *getNpcContextByIndex(u16);
u16  findFreeNpcSlotByKey(struct D_80130BB8_type*, u16);
u16  getNextSlotNpcTypeId(u16);
u16  getNpcNextSlotIndex(u16);
void destroyTransientNpcSlots(void);

#endif
