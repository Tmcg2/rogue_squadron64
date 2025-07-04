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
    /* 0x000 */ struct object_entry *object;
    /* 0x004 */ f32 posX;
    /* 0x008 */ f32 posY;
    /* 0x00C */ f32 posZ;
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
    /* 0x0C8 */ f32 unk0C8[0x24];
    /* 0x158 */ u16 blaster_to_fire;
    /* 0x15A */ u16 pad15A;
    /* 0x15C */ u32 fire_mode;
    /* 0x160 */ f32 unk160[0x06];
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

I don't know that "context" is really the best word to use here, but its the best I can come up with.

At ROM address `0x80130B40` there is a large struct that seems to track several game state related variables.
Things like the current level, chosen player craft, controller setting choice, language choice, volume levels, cheat code flags, and who knows what else.

```cpp
struct D_80130B10_type {
    /* 0x00 */ u8  numLives;
    /* 0x01 */ u8  playerRank;
    /* 0x02 */ u8  secondaryWeapon;
    /* 0x03 */ u8  secondaryWeaponMax;
    /* 0x04 */ u8  unk4;
    /* 0x05 */ u8  completedObjectiveFlags; // If a flag is 1, the objective is complete and will be colored green
    /* 0x06 */ u8  hiddenObjectiveFlags; // If a flag is 1, the objective IS NOT displayed
    /* 0x07 */ u8  numMissionObjectives;
    // I think these are copied from D_80130B40 on level start and then compared against them again afterwards to deduce if a new
    // unlocked was gained during the level
    /* 0x08 */ u32 activeUnlockFlags;
    /* 0x0C */ u8  medalPerLevel[0x13]; // really ought to be enum MEDAL_TYPE, but enums are sized too big
    /* 0x1F */ u8  maxUnlockedLevel; // really ought to be enum Level, but enums are sized too big
    /* 0x20 */ u8  unk20;
    /* 0x21 */ u8  unk21;
    /* 0x22 */ u8  unk22;
    /* 0x23 */ u8  unk23;
    /* 0x24 */ u8  accountNumber;
    /* 0x25 */ u8  anyExtraLevelsUnlocked;
    /* 0x26 */ u8  unk26;
    /* 0x27 */ u8  unk27;
}; // size 0x28

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
    |             7             |                 6                 |                    5                    |                   4                   |
    |            ???            | 1/0, Hoth Extra Level en/disabled | 1/0, Death Star Extra Level en/disabled | 1/0, Tatooine Extra Level en/disabled |
    |             3             |                 2                 |                    1                    |                   0                   |
    | 1/0, all craft  available |  1/0, TIE interceptor available   |    1/0, millennium falcon available     |         1/0, advanced shields         |
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
    /* 0x2C */ u32 unk2C;
}; // size 0x30
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
See this StackOverflow question for more information: <https://stackoverflow.com/questions/20680218/why-are-bgezal-bltzal-basic-instructions-and-not-pseudo-instructions-in-mips>

The functions with such contructs HAVE to be hand-written.
That by itself isn't super weird, there's bound to be hand-written in a game like this.
But it become way more interesting when comparing other parts of that file to the code found here: <https://github.com/jombo23/N64-Tools/blob/1e19f4d9fc8265c00abb39b34f15d37aaa3a6a6d/N64SoundListToolUpdated/N64SoundLibrary/MORTDecoder.cpp#L2529>

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

I also found this repo: <https://github.com/AxioDL/amuse>
Don't know if it works or not, just wanted to note it down.

## Level Selection Screen

`func_800C63C0` returns a word whose bits indicate which ships are available for use in a given level.
`func_800B19EC` is responsible for printing the weapon/shield text on the level select screen.
`D_80130B2F` is something like "number of unlocked levels".

## Craft Selection Screen

```cpp
struct D_800CDA5C_type {
    /* 0x000 */ u32 unk000[0x9E];
}; // size = 0x278

struct D_800CDA5C_type *D_800CDA5C;
```

`func_800A9364` is responsible for `rs_malloc`'ing `D_800CDA5C`.
`D_800CDA5C` is 0x38 (56) entries long.

`func_800C6234` also returns a word whose bits indicate which ships are available for use in a given level.
Its very similar to `func_800C63C0`, although they do differ in some small ways.
`D_800CD6D8` stores those bits.

`func_800A9364` is involved with Craft Selection, for example it's where the on screen text is decided.
It does a ton of other stuff though, not sure what all is going on in that function.

`D_800CC3F0` is an array of `enum PlayerCraft`s (as `u8`s).
NOTE: the first entry is `0`, but that is NOT the same as being an X-Wing.
For reasons unknown `D_800CC404` does not contain a `0` entry.

`D_800CC404` is an intermediate map of some kind.
Its indexed by bay number and its contents are indexes into `D_800CC3F0`.
It also appears to contain indexes into `D_800CDA5C`, so this map might be a bay-to-ui-element-index map.

`D_800CC40C` is an array of `enum PlayerCraft`s (as `u8`s).
Indicates which craft is in which bay in the hangar.

`D_800CC4F8` is an array of `u16` pointers.
These point to `0xFFFF` terminated lists of `u16` that acts as voice line (or just general audio?) ids.
Values in `D_800CC404`, chosen by `D_800CD6E8`, decide which pointer to access.
`func_800AE264` is involved in this somehow.

`func_800CBF60` is responsible for `rs_malloc`ing a struct that is related to those voice lines, although most of the details about that struct are lost on me.

`D_800CD6CD` is a byte, indicates if the Mellinium Falcon is available or not.
`D_800CD6CE` is a byte, indicates if the TIE Interceptor is available or not.
`D_800CD6CF` is a byte, indicates if the Naboo Starfighter is available or not.

`D_800CD6D0` is a word whose bits indicate if a given craft is available for use in the currently selected level.

`D_800CD6E4` is a byte, its the value you get if you access `D_800CC404` at `D_800CD6E8`

`D_800CD6E8` is a byte, indicates the current bay being looked at in the hanger

## I don't remember what these are for...

I think these are in-mission related, something to do with the `DAT` files in the [Data Blob](/docs/data_blob/data_blob.md).

```cpp
struct D_80130BB8_type {
    /* 0x00 */ u32 unk00[15];
}; // size = 0x3C

struct D_80130BB8_type *D_80130BB8;
u32 *D_80130BBC; // not entirely what type this should be, but its only 4 bytes big so u32 will do for now
```

`func_8003FD54` is responsible for `rs_malloc`'ing `D_80130BB8` and `D_80130BBC`
`D_80130BB8` and `D_80130BBC` are both 0xC0 (192) entries long.

## Overlay Speculation

I think `func_80000B20` is the high level entry point for getting an overlay loaded.
I speculate (but can not confirm) that there are 3 overlays:

0) In-mission
1) Memory Pak message and menus
2) "Cinematic" scenes (logo screens, pre/post mission cutscenes, demos)

If there are more overlays, I don't know where they are or how to find them.

The main thing `func_80000B20` does is initialize a struct that I guess could be called "overlay dma information".
`D_800375B0` appears to be something like "currently loaded overlay"

```cpp
struct overlay_dma {
    /* 0x00 */ u32 src_addrs[8];
    /* 0x20 */ u32 dest_addrs[8];
    /* 0x40 */ u32 dma_size[8];
    /* 0x60 */ u32 transaction_count;
    /* 0x64 */ u32 bss_addr;
    /* 0x68 */ u32 bss_size;
}; // size = 0x6C

struct overlay_dma overlay0 = {
    { 0xB00A5D30, 0, 0, 0, 0, 0, 0, 0 },
    { 0x800A5130, 0, 0, 0, 0, 0, 0, 0 },
    { 0x665A0, 0, 0, 0, 0, 0, 0, 0 },
    1,
    0x8010B6D0,
    0x1B30
};

struct overlay_dma overlay1 = {
    { 0xB010C2D0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x800A5130, 0, 0, 0, 0, 0, 0, 0 },
    { 0x283F0, 0, 0, 0, 0, 0, 0, 0 },
    1,
    0x800CD520,
    0x2EC0,
};

struct overlay_dma overlay2 = {
    { 0xB0137580, 0, 0, 0, 0, 0, 0, 0 },
    { 0x800A5130, 0, 0, 0, 0, 0, 0, 0 },
    { 0xB810, 0, 0, 0, 0, 0, 0, 0 },
    1,
    0x800B0940,
    0x15B0,
};
```

Note that these structs aren't real data.
A single struct of this type exists as a function local variable and has its entries set in a switch-case.

The `bss_*` members are a bit speculative, I don't actually know with certainty that they are for BSS initialization.
What I do know is that `bss_size` bytes are zero-filled starting at `bss_addr` after the DMA is done.
Which, to me, looks a lot like BSS initialization.

`func_800033A0` does the actual handling of the struct, which in turn goes 2 or 3 functions deep before the DMA proper occurs
