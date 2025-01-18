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

`D_80109CB0` is a `char*` array that contains the paths to the `ov_*` assets for each of the playable crafts.

```cpp
enum SecondaryWeapon {
    /* 0x00 */ UNUSED, // not sure what's up with this...
    /* 0x01 */ ION_CANNON,
    /* 0x02 */ MISSLES,
    /* 0x03 */ SEEKER_MISSILES,
    /* 0x04 */ BOMBS,
    /* 0x05 */ PROTON_TORPEDOS,
    /* 0x06 */ TOW_CABLE,
    /* 0x07 */ CLUSTER_MISSILES,
    /* 0x08 */ SEEKER_TORPEDOS,
    /* 0x09 */ SEEKER_CLUSTER_MISSILES,
    /* 0xFF */ NONE = 0xFF,
};

enum SecondaryWeaponType {
    /* 0x0 */ MISSLE_TYPE,
    /* 0x1 */ CLUSTER_MISSLE_TYPE,
    /* 0x2 */ TORPEDO_TYPE,
    /* 0x3 */ BOMB_TYPE,
};

enum SecondaryWeaponLevel {
    /* 0x0 */ NORMAL_LEVEL,
    /* 0x1 */ ADVANCED_LEVEL,
    /* 0x2 */ SEEKER_LEVEL,
};
```

There's no specific value for the `Advanced` versions of the secondary weapons in `enum SecondaryWeapon`.
Instead, there are bits found in the `struct D_80130B40_type` that are set when the advanced type is available and `func_800AE530` uses those bits to decide whether or not to add the word `Advanced` to the displayed string.
`func_800AE530` is responible for creating the string displayed in the craft selection screen that indicates the craft's secondary weapon.
`D_800CC6E8` is a byte used as an index into `D_800CD540`, which is an array of `0x30` sized strings.
I don't know why `D_800CD540` is big enough to hold 4 such strings.

`func_800C6728` is used to find out which secondary weapon is to be used based on player craft, current level, and some bits found in `struct D_80130B40_type`.
`D_800A5840` is (likely) function specific data that maps `enum SecondaryWeapon` types to their display text ids.
Its an array of `u16`s.

`func_8006F43C` returns the maximum amount of secondary weapon each craft has.
`0xFF (-1)` is used to indicate a maximum of "initify" (used for the Ion Cannon).

`D_80109CD4` is a list of `char*` used to select from the different overlay images used for secondary weapons.
Look for the `ov_2_*` assets.

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
// This could be an array, not sure
struct D_80130B10_type {
    /* 0x0 */ u8 playerCraft;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 secondaryWeapon;
    /* 0x3 */ u8 secondaryWeaponMax;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 unk7;
}; // size 0x8

struct D_80130B40_type {
    /* 0x00 */ u8  currentLevel; // Should really be an `enum Level` but enums types are bigger than 1 byte
    /* 0x01 */ u8  vehicleId; // Should really be an `enum PlayerCraft` but enums types are bigger than 1 byte
    /* 0x02 */ u8  unk02;
    /* 0x03 */ u8  secondaryWeapon; // Should really be an `enum SecondaryWeapon` but enum types are bigger than 1 byte
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
