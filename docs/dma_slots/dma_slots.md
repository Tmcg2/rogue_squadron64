# DMA Slots

I don't actually think the word "slot" is the best word to be using, but my vocabulary is failing me so I'll be using it for now.

The game appears to have 8 possible DMA slots it can use, so that it can do 8 DMA's in "parallel".
I say in "parallel" but the N64 can only do one DMA at a time so these 8 slots aren't really acting in a parallel fashion.
Its more of a "round robin" thing.
Although even that is overstating it because I don't think the game ever actually leverages this ability, so it ends up feeling a little over-designed.

The game doesn't DMA a block (be it data, code, or whatever) in a single go.
Rather it DMA's it in smaller chunks (0x4000 bytes at the biggest) and in theory, after any given chunk is DMA'd a different DMA slot could jump in and do its own DMA'ing.
Again, this never happens in practice but the ability is there.

[func_800045E8.c](/docs/dma_slots/func_800045E8.c) seems to be where all DMA related variables get initialized.

[func_80003824.c](/docs/dma_slots/func_80003824.c), [func_80003638.c](/docs/dma_slots/func_80003638.c), and [func_80003480.c](/docs/dma_slots/func_80003480.c) all appear to be "do a DMA" functions.
Presumably they all do things in slightly different fashion, although the details are entirely lost on me.

[func_80005938.c](/docs/dma_slots/func_80005938.c) can be used to set the value of `D_80111254`, although that never happens in practice.

```cpp
s32 D_80111254; // Maximum DMA amount, hard-coded to 0x4000 in func_800045E8
OSMesg      D_801107A0[8]; // PI Manager message buffer
OSMesgQueue D_801107C0; // PI Mangaer queue
OSIoMesg    D_801107E0[8];
OSMesg      D_801108A0[8]; // message """buffer""" for each message queue (only 1 message long though)
OSMesgQueue D_801108C0[8]; // message queue for that slot
OSMesg      D_80110980;
OSMesgQueue D_80110990;
s32 D_801109A8; // is the index of the next open slot, I think?
s32 D_801109AC; // seems like it tracks how many DMA "slots" are open, but nothing ever references it so what's the point?
u8 *D_801109B0[8]; // destination addresses (treated as unsigned bytes for pointer arithmetic reasons)
s32 D_801109D0[8]; // "total amount to be DMA'd", set but never referenced
u8 *D_801109F0[8]; // source addresses (treated as unsigned bytes for pointer arithmetic reasons)
s32 D_80110A10[8]; // "amount DMA'd so far"
s32 D_80110A30[8]; // "amount left to DMA"
s32 D_80110A50[8]; // "amount DMA'd this step"
u8  D_80110A70; // Almost looks like a mutex around the actual OS DMA calls
OSMesgueue D_80110BC0[16];
```
