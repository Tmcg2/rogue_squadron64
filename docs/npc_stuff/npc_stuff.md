# NPC Stuff

This file is a little bare as I haven't looked into this stuff too much yet.

`func_800653B4` is an interesting function, it appers to be where a a lot (but not all) of [DAT file entries](../dat_files/dat_file.md) get some amount of setup done.
The part that has my interest is all the function pointers being referenced.
Note: there are referecnes to `D_` variables in the function but those are really function pointers.
`func_800653B4` is in the main code segment but the function pointers are for functions in the mission_overlay.
Presumably this is caused by some kind of configuration issue on my end concerning splat.

The functions referenced in that function appear to be some sort update functions for various NPC/prop items in levels.

```cpp
typedef s32 (*npc_update)(struct D_80130BB8_type *self, s32 arg1, void *arg2);

// I guess you could call this "NPC context" or something like that
// The update function takes the entry itself as its first argument, which is interesting
struct D_80130BB8_type {
    /* 0x00 */ npc_update update_func;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ u32   unk0C;
    /* 0x10 */ u32   unk10;
    /* 0x14 */ u16   unk14;
    /* 0x16 */ u16   unk16;
    /* 0x18 */ u8    unk18;
    /* 0x19 */ u8    unk19;
    /* 0x1A */ u8    unk1A;
    /* 0x1B */ u8    unk1B;
    /* 0x1C */ u16   unk1C[16];
}; // size = 0x3C

struct D_80130BB0_type {
    /* 0x00 */ struct D_80130BB8_type *unk00;
    /* 0x04 */ s16 unk04; // next D_80130BB0 entry index?
    /* 0x06 */ s16 unk06; // prev D_80130BB0 entry index?
}; // size = 0x8

struct D_80130BB0_type *D_80130BB0; // malloc'd to sizeof(struct D_80130BB0_type) * 0x800
s16 D_80130BB4;
// These are initialized in `func_8003FD54`
struct D_80130BB8_type  *D_80130BB8; // malloc'd to sizeof(struct D_80130BB8_type)  * 0xC0
struct D_80130BB8_type **D_80130BBC; // malloc'd to sizeof(struct D_80130BB8_type*) * 0xC0
// These are malloc'd in `func_8003EA4C`, but their type/size is unknown
// They're linked-list like though, unk44 and unk48 are links to other members in the list
u32 D_80130BC0;
u32 D_80130BC4;
// Count of entries open in D_80130BB8/C (or, I guess, next open slot)
// I don't think this list gets curated, so is it being treated like a stack?
u32 D_80130BC8;
```

Don't quite know what to make of `D_80130BB0`.
Seems simlar to a linked-list, although I'm not 100% certain of that.
`D_80130BB4` is something like the list tail, I think.
