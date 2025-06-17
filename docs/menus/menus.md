# Menus

## Main Menu Stuff

There's a struct at `0x800CE730` that is `0xF8` bytes big.
It appears to be related to the text shown on the menu screens.
I don't currently know what all the entries in it are, but I have a good idea about a lot of them

```cpp
enum Menu {
    /* 0x0 */ MAIN_MENU,
    /* 0x1 */ ACCOUNT_SELECTION,
    /* 0x2 */ OPTIONS,
    /* 0x3 */ GAME_SETTINGS,
    /* 0x4 */ ELITE_ROGUES,
    /* 0x5 */ CONTROLLER_SETTINGS,
    /* 0x6 */ SOUND_SETTINGS,
    /* 0x7 */ CHEAT_MENU,
    /* 0x8 */ BIOGRAPHIES,
    /* 0x9 */ LANGUAGE_SELECT,
    /* 0xA */ SHOWROOM,
    /* 0xB */ CONCERT_HALL,
    /* 0xC */ AT_THE_MOVIES,
    /* 0xD */ NUM_MENUS,
};

struct D_800CE730_type {
    /* 0x00 */ char *screen_title;
    /* 0x04 */ u8 current_menu; // Should really be an `enum Menu` but enums are sized too big
    /* 0x05 */ u8 back_menu; // that is, the menu you'll go back to when selecting the "Back" option
    /* 0x06 */ u16 unk06;
    /* 0x08 */ char *menu_entries[8];
    /*
    based on a switch/case found in func_800B47C4 these might be a sub-type for each menu entry
    not all valid entries are handled in that switch/case
    sub-type 00: empty (but active) entry?
    sub-type 01: go to a sub-menu?
    sub-type 02: implied to exist in `func_800C30C8`, use unknown
    sub-type 03: name/rank for highlighted account
    sub-type 05: on/off styled setting
    sub-type 06: biography back
    sub-type 07: biography left arrows
    sub-type 08: biography right arrows
    sub-type 09: erase game
    sub-type 11:
    sub-type 12:
    sub-type 14: game settings restore defaults
    sub-type 15: sound settings restore defaults
    sub-type 16:
    sub-type 17:
    sub-type 18: passcode "enter code"
    sub-type 19: passcode back
    sub-type 20: passcode text (not the wheel, the text above it)
    sub-type 21: music volume
    sub-type 22: sfx volume
    sub-type 23: speech volume
    sub-type 24: language menu entries
    sub-type 25: "nomral" back
    sub-type 26: 
    sub-type 27: concert hall left arrows
    sub-type 28: concert hall right arrows
    sub-type 29: concert hall song name
    */
    /* 0x28 */ u8 unk28[8];
    /* 0x30 */ s16 entry_xy_offsets[8][2]; // could maybe be struct, but an array works just as well
    /* 0x50 */ s16 title_xy_offset[2];
    /* 0x54 */ f32 entry_size_scaler[8];
    /*
    numbers found here have different meanings, dependent on the "sub-type" found in unk28
    e.g. a 01 entry in unk28 would indicate the value found here is the `enum Menu` value of the sub-menu you'll go to
    */
    /* 0x74 */ u32 unk74[8];
    /* 0x94 */ u8 current_menu_entry;
    /* 0x95 */ u8 num_menu_entries; // This doesn't alway match the visible menu entries, so there's likely a nuance I'm missing
    /* 0x96 */ s16 overall_y_offset;
    /*
    Each bit is used to indicate whether a given menu entry is "active" (has actual text) or "inactive"
    u16 entry15 : 1;
    u16 entry14 : 1;
    ...
    u16 entry1  : 1;
    u16 entry0  : 1;
    */
    /* 0x98 */ u16 active_entries;
    /* 0x9A */ u16 unk9A;
    /* 0x9C */ f32 unk9C; // Changes whenever you move to a new menu entry, some type of timer
    /* 0xA0 */ f32 highlight_timer;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0[8];
    /* 0xD0 */ f32 unkD0[8];
    /* 0xF0 */ f32 unkF0[2];
}; // size = 0xF8

struct D_800CE730_type D_800CE730;
```

`func_800B47C4` is menu related in some capcity, at the very least it handles controller input for the menus.
`func_800BA0F0` and `func_800BB394` are deeply involved with the menus.
`func_800BA0F0` sets up `D_800CE730` based on whichever menu you're in.
`func_800BB394` appears to handle the second-to-second details of a menu (text highliting for example).

```cpp
struct D_800CC89C_type {
    /* 0x00 */ u16 name_text_id;
    /* 0x02 */ u16 unk02; // padding, maybe?
    /* 0x04 */ char *image_asset_name;
    /* 0x08 */ u16 image_width;
    /* 0x0A */ u16 image_height;
    /* 0x0C */ u16 image_x_offset;
    /* 0x0E */ u16 image_y_offset;
    /* 0x10 */ s16 name_x_offset;
    /* 0x12 */ u16 biography_text_id;
    /* 0x14 */ u16 unk14; // x-offset of the indent in the text. Modifying this can have weird side-effects
    /* 0x16 */ u16 unk16; // y-offset of where the biography text stops taking the picture into account
    /* 0x18 */ u16 unk18[6]; // maximum of 5 real entries with the 6th being `0xFFFF` as an end-of-list entry
}; // size = 0x24

struct D_800CC89C_type D_800CC89C[6];
```

`800CC89C` 0x24 sized struct, something related to the text displayed on the Biographies menu
`800CF150` and `800CF151` are related to the Biographies menu, tracking which biography we're on right now and which menu entry we were on prior to swapping to a new biography.

```cpp
struct D_800CC974_type {
    /* 0x0 */ u16 option1_text_id;
    /* 0x2 */ u16 option2_text_id;
    /* 0x4 */ u8  D_80130B40_unk0C_byte;
    /* 0x5 */ u8  unk5; // padding?
    /* 0x6 */ u16 D_80130B40_unk0C_bit;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
}; // size = 0xC

struct D_800CC974_type D_800CC974[7];
```

`D_800CC974` 7 0xC sized structs related to the menu items seen on the Game Settings menu (see `func_800BB234`)

```cpp
struct D_800CCE1C_type {
    /* 0x0 */ char *song_name;
    /* 0x4 */ u32 song_id; // name is speculative
}; // size = 0x8

// 0x3D real entries, plus one entry with a null song_name
struct D_800CCE1C_type D_800CCE1C[0x3E];

u8 D_800CFE3D; // index of displayed song
u8 D_800CFE3E; // index of playing song
```

`D_800CCE1C` is something related to the songs shown in the `Concert Hall` menu.
The pointer part is pretty clear, its just a `char*`.
The `song_id` is speculative on my part though, I haven't figured out what that number actually is.

`D_800CFE3D` is the index of the song being displayed, while `D_800CFE3E` is the index of the song being played.

## Pause Menu Stuff

```cpp
struct PauseMenuStuff {
    /* 0x0 */ u16 flags;
    union {
        /* 0x2 */ u16 textId;
        /* 0x2 */ u16 objectiveNumber;
    };
    union
    {
        /* 0x4 */ u16 nextMenu;
        /* 0x4 */ u16 settingBit;
    };
}; // size = 0x6

struct PauseMenuStuff pauseMenuMissionObjectives[];
struct PauseMenuStuff pauseMenuGameSettings[];
struct PauseMenuStuff pauseMenuAudioSettings[];
struct PauseMenuStuff pauseMenuAbortLevel[];
```

Its hard to pin down the exact member names for things in `struct PauseMenuStuff`.
The `flags` part is pretty straightforward, its the other 2 members that are messy.
What represent appears to be highly context dependent.
For the sub-menu options on the main pause menu screen (the Mission Objectives), the last member is an indicator of which menu the option will take you to.
But when in the Game or Audio Settings menus they can represent the bit a particular setting modifies in `D_80130B40`.
