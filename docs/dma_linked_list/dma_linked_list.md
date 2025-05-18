# DMA Linked List

`D_801128D0` acts as the head of a linked list of DMA related structs.
I don't get why this exists alongside [DMA slots](../dma_slots/dma_slots.md), I suspect the difference has to do with their intended purpose.
Based on the usage of the linked list (see `07800.s` in general), it seems like this is used to DMA specific assets?

```cpp
struct D_801128D0_type {
    /* 0x000 */ u32  theadId;
    /* 0x004 */ u8   threadPrio;
    /* 0x005 */ u8   unk005;
    /* 0x006 */ u16  mesgCount;
    /* 0x008 */ u32 *threadStackPointer;
    /* 0x00C */ u32 *threadStackEnd;
    /* 0x010 */ u32  threadStackSize;
    /* 0x014 */ void (*entry)(void*);
    /* 0x018 */ struct D_801128D0_type *next;
    /* 0x01C */ OSMesg *mesg;
    /* 0x020 */ OSThread t;
    /* 0x1D0 */ OSMesgQueue mq;
    /* 0x1E8 */ OSMesg mesg2[2]; // not too sure about this, I doubt there's anything meaningful at 0x1EC
}; // size = 0x1F0

struct D_801128D0_type *D_801128D0;
u32 D_801128D4; // Monotonically increasing value, used to give each list item a unique thread ID
u16 D_801128D8; // No idea what this is meant to be, its set but never read
```

`func_80006C28` is responsible for creating new entries for the linked list.
An interesting tidbit is that there appears to be a bit of stack/memory poisoning going on.
The last 2 words of the stack are filled with the value `0xCDCDCDCD`.

`func_80004E70` and `func_80004C70` appear to be the primary users of the linked list.
They respecitvely look like setup and teardown for DMAs related to asset loading.
Although the internals of all that is unclear to me.
Namely I don't understand `D_80111100`, which where the actual messages related to the DMA's are housed.
