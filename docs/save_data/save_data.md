# Save Data stuff

There's some parts of this I don't fully understand yet, but I have a good grasp of the general shape.
Like most (all?) N64 games, Rogue Squadron uses a 256 byte blob for its save data.
The save file makes use of the `adler32` function from the `zlib` library for all its checksums.

```cpp
struct account_data {
    /* 0x00 */ char name[4]; // has a null-terminator (I think?)
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8  accountNumber;
    /* 0x11 */ u8  padding[3];
}; // size 0x14

struct EliteRogueData {
    char name[3]; // really just 3 characters, no null terminator
    u8 current_level; // should be an enum Level but enum entires are sized too big
    // Don't know if its a bit field, or if its just a u16 that they pick apart by hand
    union {
        u16 as_short;
        struct {
            u16 pad     : 1;
            u16 golds   : 5;
            u16 silvers : 5;
            u16 bronzes : 5;
        } as_bit_field;
    };
    u16 accountNumber; // I think?
}; // size 0x8

struct D_8013A5C0_type {
    /* 0x00 */ u32 unk00; // struct D_80130B40_type.unk10
    /* 0x04 */ u32 unk04; // struct D_80130B40_type.unk0C & 0x8B
    /* 0x08 */ u32 cheatCodeFlags[2];
    /* 0x10 */ u8  musicVolume;
    /* 0x11 */ u8  soundFxVolume;
    /* 0x12 */ u8  speechVolume;
    /* 0x13 */ u8  controllerSetting;
    /* 0x14 */ struct account_data accounts[3];
    /* 0x50 */ u8 unk50; // has a value, unsure of purpose
    /* 0x51 */ u8 unk51;
    // This stuff is aligned super weirdly, so being a proper struct may not work, only time will tell
    /* 0x52 */ struct EliteRogueData highscores[10];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u32 unkA4;
    /* 0xA8 */ u8  languageSelect;
    /* 0xA9 */ u8  padding[3]; // maybe?
    /* 0xAC */ u32 unkAC;
}; // size 0xB0

struct save_data_body {
    /* 0x00 */ u32 D_8013A5C0_checksum;
    /* 0x04 */ u32 unknown_checksum; // checksum of the unk08 section
    // This looks like a series of pointers(?) but I can't be certain
    /* 0x08 */ u32 unk08[4];
    /* 0x18 */ struct D_8013A5C0_type body;
}; // size 0xC8

struct save_file_header {
    /* 0x000 */ u32 part1_checksum;
    /* 0x004 */ u32 part1[3];
    /* 0x010 */ u32 part2_checksum;
    /* 0x014 */ u32 part2[3];
}; // size 0x20

struct save_data {
    /* 0x000 */ struct save_file_header header;
    /* 0x020 */ struct save_data_body data[2];
    /* 0x1B0 */ u32 zeros[0x50]; // The game doesn't use all 256 bytes of the EEPROM, so there's a bunch of unused space at the bottom
}; // size 0x200
```

I don't know if the save data can really be represented as a single monolithic struct in the decompilation proper, but for documentation purposes it will do.

The `part1` and `part2` are used as part to sanity check the save file, and as such are expected to have really specific values.

## Sanity Check and the `gamesave` asset

```cpp
struct gamesave_asset {
    /* 0x00 */ u32 game_code;
    /* 0x04 */ u32 save_file_size;
    /* 0x08 */ u32 save_data_size;
    /* 0x0C */ u16 company_code;
    /* 0x0E */ u16 data_copy_count;
    /* 0x10 */ char game_name[16]; // Not ASCII, its some other N64 specific encoding. Translated its "RS64"
}; // size 0x20

struct gamesave_asset D_801126C0;
```

[func_80006338.c](/docs/unsorted_thoughts/func_func_80006338.c) appears to be a save data sanity check.
It load the top 32 bytes of the save data (its "header") and compares it to the `gamesave` asset from the [Data Blob](/docs/data_blob/data_blob.md).
Or, sort of, its not a direct comparison, but close enough.
If the comparison turns up a difference, the entirety of the EEPROM is zero'd out thereby destroying all the save data.

Several variables are initialized here too.

- `D_801126C0` is where the `gamesave` asset gets copied to after being DMA'd.
- `D_80112728` is the size of save data body, or more specifically, its the size of `struct gamesave_asset.save_data_size` (`0xB0`) plus the size of a header-like section (`0x18`) totalling `0xC8` bytes.
- `D_80112724` is a pointer to malloc'd memroy. The size of this memory block is oddly (`0x1C8`) large, I can't explain it.

[func_80006798.c](/docs/unsorted_thoughts/func_80006798.c) makes use of the `adler32` function from the `zlib` library to checksums for 2 blocks of data.
Then, those checksums and their respecitve data is written to the EEPROM.

[func_8006DD50.c](/docs/unsorted_thoughts/func_8006DD50.c) is a function involved with both the highscores and the save data.
It looks like it has a bubble sort implemented in it, so maybe its involved in adding/updating the scores and thus has to keep them sorted?

## Elite Rogue Screen

[func_800BEA00.c](/docs/unsorted_thoughts/func_800BEA00.c) appears to be the primary handler for the "Elite Rogues" menu screen (basically the high score list).
The named ranks (e.g Tainee, Cadet, Surpeme Alliance Commander) are decided by the "point" score.
Gold medals are worth 4 points, silvers are worth 2, and bronzes are worth 1 point.
Every 4 points increases the rank.

You can see the data used for this screen starting at ROM address `0x8013A5C0`.
In reality, this is a part of the save data that has been extracted (see `struct D_8013A5C0_type`).

Speculatively, [func_8006DCCC.c](/docs/unsorted_thoughts/func_8006DCCC.c) loads the 10 default high scores.
This would indicate that the names of the default scores start at ROM address `0x8003CB10`.
Really, the names would be a list of `char*`s.
You can even find those pointers starting at ROM address `0x800A0A64`.

```cpp
char *defaultNames[] = {
    "FLO", "ABC", "ETC",...
}
```

## Mempak stuff

- func_80005960 Initializing the memory pack
- func_80005B9C Appears to write `struct save_data_body` to the EEPROM.
- func_80005F18 Appears to be where `D_8013A5C0` gets written
- func_80006198 Appears to copy `struct save_data_body.unk08` stuff to somewhere else in memory. Not sure where or to what end.