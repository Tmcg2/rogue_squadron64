# Unsorted Thoughts

This folder is for various, unsorted thoughts.
Basically a holding pen for topics that I didn't feel necessitated their own separate folders.
This also unfortunately means that a lot of topics mentioned here will be anemic compared to all the other documentation.

[notes.txt](/docs/unsorted_thoughts/notes.txt) is a file I used as a dumping ground for ideas and thoughts I had while looking at decomped code and/or the emulator's debugger.
It is where most of "unsorted thoughts" reside.
Its very stream-of-conciousness in nature, which means it might not make sense to anyone else (some parts of it confuse me in the here and now).
Its also very possible that there is outdated/incorrect information in it, so be vigilant when reading it.

## Levels

```cpp
enum Level {
    /* 0x00 */ MOSEISLEY_LEVEL,
    /* 0x01 */ BARKHESH_LEVEL,
    /* 0x02 */ NONNAH_LEVEL,
    /* 0x03 */ CORELLIA_LEVEL,
    /* 0x04 */ GERRARDV_LEVEL,
    /* 0x05 */ JADEMOON_LEVEL,
    /* 0x06 */ CONST_YARD_LEVEL,
    /* 0x07 */ KILEII_LEVEL,
    /* 0x08 */ KESSEL_RESCUE_LEVEL,
    /* 0x09 */ KESSEL_PRISON_LEVEL,
    /* 0x0A */ TALORAAN_LEVEL,
    /* 0x0B */ FEST_LEVEL,
    /* 0x0C */ CHANDRILA_LEVEL,
    /* 0x0D */ SULLUST_LEVEL,
    /* 0x0E */ THYFERRA_LEVEL,
    /* 0x0F */ CALAMARI_LEVEL,
    /* 0x10 */ BEGGARS_CANYON_LEVEL,
    /* 0x11 */ TRENCH_RUN_LEVEL,
    /* 0x12 */ HOTH_LEVEL,
    /* 0x13 */ NUM_LEVELS,
    /* 0x13 */ LOGO_LEVEL = 0x13,
    /* 0x14 */ ATST_LEVEL,
};

// These are the same thing, gCurrentLevel is found at ROM address 0x80130B70
enum Level D_80130B70;
enum Level gCurrentLevel;

// These are the same thing, although I don't have an entry for `dLevelByDemoId` in symbol_addrs.txt
// Really enum Level, but that will be sized too large
// Levels used for the demos
u8 D_800CD404[6];
u8 dLevelByDemoId[6];
```

You can fiddle with the byte at ROM address `0x80130B40` to change this in memory.
I don't know when this value gets read though, so you'll have to mess around to find out if/how it can be manipulated to do anything weird.

## Player Crafts

```cpp
enum PlayerCraft {
    /* 0x0 */ XWING_CRAFT,
    /* 0x1 */ YWING_CRAFT,
    /* 0x2 */ AWING_CRAFT,
    /* 0x3 */ VWING_CRAFT,
    /* 0x4 */ SNOWSPEEDER_CRAFT,
    /* 0x5 */ FALCON_CRAFT,
    /* 0x6 */ TIEINTER_CRAFT,
    /* 0x7 */ T16_CRAFT,
    /* 0x8 */ KOELSCH_CRAFT,
};

// Default/demo craft per level
// Data found at ROM address 0x8009EC50
enum PlayerCraft dDefaultCraftForLevel[NUM_LEVELS];
```

You can fiddle with the byte at ROM address `0x80130B41` to change this in memory.
I don't know where all this value gets read though, so you'll have to mess around to get it to have any noticeable effect.
I know at some point I used it to get the wrong craft loaded for one of the demo scenes, which was pretty funny to watch.

[func_800FB6C0.c](/docs/unsorted_thoughts/func_800FB6C0.c) is pretty invovled with the DMA'ing of the HOB/HMT files for the chosen player craft.

## Player Struct

I've identified a block in memory that has lots of player information in it.
I don't know of its the primary player information block, and I doubt its the only place with player information.

```cpp
struct inner_player_struct {
    /* 0x000 */ void *unk000;
    /* 0x004 */ f32 posX;
    /* 0x008 */ f32 posY;
    /* 0x00C */ f32 posZ;
    // I wouldn't be surprised if things like speed, acceleration, and facing angle/vector are somewhere in here
    /* 0x010 */ f32 unk010;
    /* 0x014 */ f32 unk014;
    /* 0x018 */ f32 unk018;
    /* 0x01C */ f32 unk01C;
    /* 0x020 */ f32 unk020;
    /* 0x024 */ f32 unk024;
    /* 0x028 */ f32 unk028;
    /* 0x02C */ f32 unk02C;
    /* 0x030 */ f32 unk030;
    /* 0x034 */ u16 unk034[0x40];
    /* 0x0B4 */ u16 unk0B4;
    /* 0x0B6 */ u16 unk0B6;
    /* 0x0B8 */ s32 unk0B8;
    /* 0x0BC */ void *unk0BC;
    /* 0x0C0 */ f32 currentHealth;
    /* 0x0C4 */ f32 maxHealth;
    /* 0x0C8 */ f32 unk0C8[0x2C];
    /* 0x178 */ u32 unk178[0x35];
    /* 0x24C */ f32 unk24C[0x10];
    /* 0x28C */ u16 unk28C;
    /* 0x28A */ u16 unk28A;
    /* 0x290 */ enum PlayerCraft vehicleId;
    /* 0x294 */ u32 unk294;
    /* 0x298 */ u32 unk298;
}; // size 0x29C

struct player_struct {
    /* 0x000 */ u8 unk000;
    /* 0x001 */ u8 unk001; // compiler padding?
    /* 0x002 */ u16 unk002;
    /* 0x004 */ struct inner_player_struct inner;
}; // size 0x2A0

// This array is only 1 entry long. I assume its an array as a leftover from when they were planning on having a multiplayer mode
// References to things inside this struct
// D_80137DBC -> 0x004
// D_8013800C -> 0x254
// D_8013803C -> 0x284
struct player_struct D_80137DB8[];
```

## Game Context

I don't know "context" is really the best word to use here, but its the best I can come up with.

At ROM address `0x80130B40` there is a large struct that seems to track several game state related variables.
Things like the current level, chosen player craft, controller setting choice, language choice, volume levels, cheat code flags, and who knows what else.

```cpp
struct D_80130B40_type {
    /* 0x00 */ u8  currentLevel; // Should really be an `enum Level` but enums types are bigger than 1 byte
    /* 0x01 */ u8  vehicleId; // Should really an `enum PlayerCraft` but enums types are bigger than 1 byte
    /* 0x02 */ u8  unk02;
    /* 0x03 */ u8  unk03;
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  controllerSetting; // Should really an `enum ControllerSetting` but enums types are bigger than 1 byte
    /* 0x06 */ u8  languageSelect; // Should really an `enum Language` but enums types are bigger than 1 byte
    /* 0x07 */ char name[3]; // no null terminator
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
    // I suspect these next 4 bytes are really part of a single word
    // It might be a huge bit field?
    /* 0x0C */ u8  unk0C;
    /*
    |             7             |                6               |                 5                |           4           |
    |            ???            |               ???              |                ???               |          ???          |
    |             3             |                2               |                 1                |           0           |
    | 1/0, all craft  available | 1/0, TIE interceptor available | 1/0, millennium falcon available | 1/0, advanced shields |
    */
    /* 0x0D */ u8  unk0D;
    /*
    |          7          |               6              |            5           |               4               |
    | 1/0, advanced bombs | 1/0, seeker cluster missiles |  1/0, seeker torpedos  | 1/0, advanced proton torpedos |
    |          3          |               2              |            1           |               0               |
    | 1/0, seeker missles |     1/0, advanced missles    | 1/0, advanced blasters |              ???              |
    */
    /* 0x0E */ u8  unk0E;
    /*
    |                  7                 |  6   |            5            |            4           |
    |       1/0, crosshair on/off        | ???  | 1/0, free camera off/on |   1/0 cockpit on/off   |
    |                  3                 |  2   |            1            |            0           |
    | 1/0 displays (hud elements) on/off | ???  |  1/0, auto roll on/off  | 1/0, auto level on/off |
    */
    /* 0x0F */ u8  displaySettings;
    // I suspect these next 4 bytes are really part of a single word
    // It might be a huge bit field?
    /* 0x10 */ u8  unk10;
    /* 0x11 */ u8  unk11;
    /* 0x12 */ u8  unk12;
    /*
    |          7           |         6         |            5             |              4              |
    |    1/0 mono/stereo   |        ???        |    0/1 demo in/active    |     1/0 subtitles off/on    |
    |          3           |         2         |            1             |              0              |
    | 0/1 speech un/muted  | 0/1 sfx un/muted  |    0/1 music un/muted    |  1/0 resolution high/normal |
    */
    /* 0x13 */ u8  soundResolutionSettings;
    /* 0x14 */ u8  demoId;
    /* 0x15 */ u8  unk15;
    /* 0x16 */ u8  unk16;
    /* 0x17 */ u8  unk17;
    /* 0x18 */ u32 cheatCodeFlags[2]; // probably 2 words big for insurance, incase they added more cheats. In practice this is oversized
    /* 0x20 */ u8  musicVolume;
    /* 0x21 */ u8  soundFxVolume;
    /* 0x22 */ u8  speechVolume;
    /* 0x23 */ u8  unk23;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
}; // size 0x2C
```

## Audio Stuff

Factor 5 was apparently dissatisfied with Nintendo's audio microcode, and manage to convince Nintendo that they could be trusted to write their own.
So in all of their N64 games there's some super special audio code laying around.
I don't know where this is in Rogue Squadron, but I have an idea of where to start looking.

In the [splat yaml file](/roguesquadron.yaml) there's an assembly section at ROM address `0x9E3CC`.
Once you've split the ROM, you will find an assembly filed at the following file path: `repo_root/asm/9ECC.s`.
In that file there is some interesting code using the `bltzal` instruction (you can also see this in `repo/root/asm/9E744.s`).

```
/* 9E4EC 8009D8EC 04100022 */  bltzal     $zero, .L8009D978
```

But its written weird, its effectively saying "if 0 is less than 0, branch-and-link to label .L8009D978".
But 0 isn't less than 0, so the branch can't ever occur.

As best as I understand it this is a roundabout way of getting program counter (instruction pointer) loaded into the `ra` register.
See this StackOverflow question for more information: https://stackoverflow.com/questions/20680218/why-are-bgezal-bltzal-basic-instructions-and-not-pseudo-instructions-in-mips

The functions with such contructs HAVE to be hand-written.
That by itself isn't super weird, there's bound to be hand-written in a game like this.
But it become way more interesting when comparing other parts of that file to the code found here: https://github.com/jombo23/N64-Tools/blob/1e19f4d9fc8265c00abb39b34f15d37aaa3a6a6d/N64SoundListToolUpdated/N64SoundLibrary/MORTDecoder.cpp#L2529

I assume that that code can be attributed to Github user `jombo23` (given that its their repo), but I haven't confirmed that myself.
I see that that file has been modified by another user named `SubDrag`, which is a name I saw a pop up a lot when googling Factor 5 audio stuff.

The data table found at lines 2529, 3317, and 4321 is very interesting though.
There are 6 entries in that table, which I will combine into pairs

```
0x0CCD2CCD
0x53337FFF
0x0852A000
```

Starting at ROM address `0x9E578` you'll find the exact same set of numbers.

```
.L8009D978:
/* 9E578 8009D978 0CCD2CCD */  jal        func_8334B334
/* 9E57C 8009D97C 53337FFF */   beql      $t9, $s3, . + 4 + (0x7FFF << 2)
.L8009D980:
/* 9E580 8009D980 852A0000 */   lh        $t2, 0x0($t1)
```

In fact, I think the `MORTDecoder` code accidentally includes program data in the table.
`0x0852A000` is really `lh $t2, 0x0($t1)` when converted into MIPS mnemonics, and its clearly the top of some loop in the code.
Which is cool!
It gives good confidence that the `MORTDecoder` code is likely correct and that the code in `9E3CC.s` really is audio related.

There appears to be a similar set of numbers starting at ROM address `0x9E4BC`, but I don't see those referenced anywhere in the `MORTDecoder` code.
Don't know what to make of that.

I also found this repo: https://github.com/AxioDL/amuse
Don't know if it works or not, just wanted to note it down.

## HUD Stuff

General note about this section: ROM addresses mentioned are likley only valid if you are playing the "Search for the Nonna" mission.
Its possible they could be valid for other levels, but I wouldn't assume that is the case.

There's a struct at ROM address `0x8010CA30` that seems to be related to how the HUD elements get displayed.
Its very very big, but the bulk of its size is comprised an array of a another struct type.

```cpp
struct rgba {
    /* 0x00 */ u8 red;
    /* 0x01 */ u8 green;
    /* 0x02 */ u8 blue;
    /* 0x03 */ u8 alpha;
}; // size 0x4

struct sub_struct {
    // Or is it prev then next?
    /* 0x00 */ struct sub_struct *next;
    /* 0x04 */ struct sub_struct *prev;
    // These seem to control whether the UI element is visible or not, somehow
    /* 0x08 */ u16 unknown08;
    /* 0x0A */ u16 unknown0A;
    /* 0x0C */ u16 *pointer_in_some_indices;
    /* 0x10 */ void *a_pointer; // usually NULL, but occasionally not
        // If not NULL, this is usually a set of u16 x/y pairs that act as extra offsets from the main X/Y position for each sub-element of the main thing-to-display
    /* 0x14 */ u8 unknown14;
    /* 0x15 */ u8 unknown15;
    /* 0x16 */ u8 unknown16;
    /* 0x17 */ u8 unknown17;
    /* 0x18 */ f32 xpos;
    /* 0x1C */ f32 ypos;
    /* 0x20 */ f32 zero; // zpos?, maybe padding
    /* 0x24 */ f32 width_scale;
    /* 0x28 */ f32 height_scale;
    /* 0x2C */ struct rgba rgba;
}; // size 0x30

struct hud_struct {
    /* 0x000 */ u8 unknown000;
    /* 0x001 */ u8 unknown001;
    /* 0x002 */ u8 secondaryWeaponCount;
    /* 0x003 */ u8 secondaryWeaponReset; // Or maybe, secondaryWeaponMax?
    /* 0x004 */ u8 unknown004;
    /* 0x005 */ u8 unknown005;
    /* 0x006 */ u8 unknown006;
    /* 0x007 */ u8 unknown007;
    /* 0x008 */ u16 unknown008;
    // I think these are indices into D_8011A444;
    /* 0x00A */ u16 some_indices[10];
    /* 0x01E */ // u16 compiler_padding;
    /* 0x020 */ u32 unknown020; // could be padding?
    /* 0x024 */ f32 alpha_scaling;
    /* 0x028 */ struct sub_struct hud_elements[10];
    /* 0x208 */ u32 unknown_words208[0x1C];
}; // size 0x278

struct hud_struct D_8010CA30[2];

struct D_80128F08_type {
    /* 0x00 */ u8  unk00;
    /* 0x01 */ u8  unk01;
    /* 0x02 */ u8  unk02;
    /* 0x03 */ u8  unk03;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ u16 texture_size;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ void *texture_data; // u8*?
    /* 0x14 */ u8 texture_name[16];
}; // size 0x24

struct D_8011A444_entry {
    /* 0x0 */ u16 material_type;
    /* 0x2 */ u16 D_80128F08_index;
}; // size 0x4

struct D_80128F08_type *D_80128F08;
struct D_8011A444_entry *D_8011A444;
```

`D_8010CA30` gets referenced alot in the `0xFCA20` code segment, so that would be the best place to start investigating how it works.

I don't fully understand `D_80128F08_type` and `D_8011A444_entry` at this time.
They seem related to how textures from the [HMT files](/docs/hmt_files/hmt_files.md) get mapped on loading.
By that I mean, textures in the HMT file have their own 0 indexed numbers associated with them.
But when multiple HMT files are loaded, there would need to be way to differentiate the multiple "index 0" textures.
And to the best of my knowledge, that's what those 2 types/arrays are involved with.
The details are a fuzzy though, needs a lot more investigation.


