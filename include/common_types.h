#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include "PR/ultratypes.h"
#include "crafts.h"

/*
This is something of a dumping ground for types that are used in a variety of places.
Hopefully it doesn't become too much of a type landfill.
*/

//////////////////////////////////////////////////////////////
// TYPEDEFS
//////////////////////////////////////////////////////////////

typedef f32 Vec3f[3];
typedef f32 Vec4f[4];
typedef f32 Mat4x3[4][3];

//////////////////////////////////////////////////////////////
// ENUMS
//////////////////////////////////////////////////////////////

enum MEDAL_TYPE {
    /* 0x00 */ NO_MEDAL,
    /* 0x01 */ BRONZE,
    /* 0x02 */ SILVER,
    /* 0x03 */ GOLD,
};

enum PLAYER_RANK {
    /* 0x00 */ TRAINEE,
    /* 0x01 */ CADET,
    /* 0x02 */ ENSIGN,
    /* 0x03 */ OFFICER,
    /* 0x04 */ LIEUTENANT,
    /* 0x05 */ FLIGHT_LEADER,
    /* 0x06 */ CAPTAIN,
    /* 0x07 */ SQUAD_LEADER,
    /* 0x08 */ GOLD_LEADER,
    /* 0x09 */ MAJOR,
    /* 0x0A */ COMMANDER,
    /* 0x0B */ COLONEL,
    /* 0x0C */ GENERAL,
    /* 0x0D */ LINE_ADMIRAL,
    /* 0x0E */ FLEET_ADMIRAL,
    /* 0x0F */ SUPREME_ALLIED_COMMANDER,
};

//////////////////////////////////////////////////////////////
// STRUCTS
//////////////////////////////////////////////////////////////

struct GameSettings {
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
    /* 0x0C */ u32 unlockAndSettingsFlags[2];
    /* 0x0C u8  unk0C; */
    /*
    |             7             |                 6                 |                    5                    |                   4                   |
    |            ???            | 1/0, Hoth Extra Level en/disabled | 1/0, Death Star Extra Level en/disabled | 1/0, Tatooine Extra Level en/disabled |
    |             3             |                 2                 |                    1                    |                   0                   |
    | 1/0, all craft  available |  1/0, TIE interceptor available   |    1/0, millennium falcon available     |         1/0, advanced shields         |
    */
    /* 0x0D u8  unk0D; */
    /*
    |          7          |               6              |            5           |               4               |
    | 1/0, advanced bombs | 1/0, seeker cluster missiles |  1/0, seeker torpedos  | 1/0, advanced proton torpedos |
    |          3          |               2              |            1           |               0               |
    | 1/0, seeker missles |     1/0, advanced missles    | 1/0, advanced blasters |              ???              |
    */
    /* 0x0E u8  unk0E; */
    /*
    |                  7                 |  6   |            5            |            4           |
    |       1/0, crosshair on/off        | ???  | 1/0, free camera off/on |   1/0 cockpit on/off   |
    |                  3                 |  2   |            1            |            0           |
    | 1/0 displays (hud elements) on/off | ???  |  1/0, auto roll on/off  | 1/0, auto level on/off |
    */
    /* 0x0F u8  displaySettings; */
    /* 0x10 u8  unk10; */
    /* 0x11 u8  unk11; */
    /* 0x12 u8  unk12; */
    /*
    |          7           |         6         |            5             |              4              |
    |    1/0 mono/stereo   |        ???        |    0/1 demo in/active    |     1/0 subtitles off/on    |
    |          3           |         2         |            1             |              0              |
    | 0/1 speech un/muted  | 0/1 sfx un/muted  |    0/1 music un/muted    |  1/0 resolution high/normal |
    */
    /* 0x13 u8  soundResolutionSettings; */
    /* 0x14 */ u8  demoId;
    /* 0x15 */ u8  unk15;
    /* 0x16 */ u8  unk16;
    /* 0x17 */ u8  unk17;
    /* 0x18 */ u32 cheatCodeFlags[2]; // probably 2 words big for insurance, incase they added more cheats. In practice this is oversized
    /* 0x20 */ u8  musicVolume;
    /* 0x21 */ u8  soundFxVolume;
    /* 0x22 */ u8  speechVolume;
    /* 0x23 */ u8  unk23;
    /* 0x24 */ u8  unk24;
    /* 0x24 */ u8  unk25;
    /* 0x24 */ u8  unk26;
    /* 0x24 */ u8  unk27;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u32 unk2C;
}; // size 0x30

struct MissionState {
    /* 0x00 */ u8  numLives[1];
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

struct account_data {
    /* 0x00 */ char name[4]; // has a null-terminator (I think?)
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  unk05;
    /* 0x06 */ u8  unk06;
    /* 0x07 */ u8  unk07;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8  accountNumber;
    /* 0x11 */ u8  padding[3];
}; // size 0x14

struct EliteRogueData {
    /* 0x0 */ char name[3]; // really just 3 characters, no null terminator
    /* 0x3 */ u8 current_level; // should be an enum Level but enum entires are sized too big
    // Don't know if its a bit field, or if its just a u16 that they pick apart by hand
    /* 0x4 */ union {
        u16 as_short;
        struct {
            u16 pad     : 1;
            u16 golds   : 5;
            u16 silvers : 5;
            u16 bronzes : 5;
        } as_bit_field;
    } medals;
    /* 0x6 */ u8 accountNumber; // I think?
    /* 0x7 */ u8 padding;
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
    /* 0xA2 */ u8  unkA2;
    /* 0xA3 */ u8  unkA0[8];
    /* 0xAB */ u8  languageSelect;
    /* 0xAC */ u8  unkAC;
}; // size 0xB0

struct asset_medal_info {
    /* 0x00 */ f32 completion_time;
    /* 0x04 */ u16 enemies_destroyed;
    /* 0x06 */ u16 accuracy;
    /* 0x08 */ u16 friendlies_saved;
    /* 0x0A */ u16 bonus_collected;
}; // size = 0x0C;

struct game_medal_info {
    /* 0x00 */ u32 completion_time;
    /* 0x04 */ u16 enemies_destroyed;
    /* 0x06 */ u8  accuracy;
    /* 0x07 */ u8  friendlies_saved;
    /* 0x08 */ u8  bonus_collected;
    // 3 bytes of padding
}; // size = 0x0C;

struct mission_stats {
    /* 0x00 */ u32 completion_time;
    /* 0x04 */ u32 shots_fired;
    /* 0x08 */ u32 shots_landed;
    /* 0x0C */ u16 enemies_destroyed;
    /* 0x0E */ u8  friendlies_saved;
    /* 0x0F */ u8  bonus_collected;
}; // size = 0x10;

struct manifest_entry {
    /* 0x00 */ u32 data_offset;
    /* 0x04 */ u32 decompressed_size;
    /* 0x08 */ u32 compressed_size; // 0xFFFFFFFF (or -1 if signed) indicates that the entry is not compressed
    /*
    bit 7: is directory (0x80)
    bits 1-6: never set, checked in several places though
    bit 0: set a lot (but not alwasy). Purpose unknown
    */
    /* 0x0C */ u8 flags;
    /* 0x0D */ u8 unk0D;
    /*
    This is a number multiplied by 0x20 (<< 5)
    It is the size in bytes that the directory takes up in the manifest
    So, (directory content entries + 1(the directory entry itself)) * 0x20
    For non-directory entries, this number should be zero 
    */
    /* 0x0E */ u16 directory_size;
    /* 0x10 */ u8 name[16];
}; // size 0x20

struct D_80110A80_entry {
    u8 unk00[0x20];                  /* 0x00 */
    u8 unk20[0x20];                  /* 0x00 */
    struct manifest_entry *manifest; /* 0x40 */
    u8 *data;                        /* 0x44 pointer to the data block that the manifest refers to. Is a ROM pointer as well, weirdly */
    u32 entry_count;                 /* 0x48 number of entries in the manifest/number of files in the data block (same thing really) */
    u16 unk4C;                       /* 0x4C */
    u8  one;                         /* 0x4E */
    // u8 compiler_padding?; /* 0x4F */
}; // size 0x50

struct meshdef1 {
    struct meshdef1 *next_meshdef1_pointer; /* 0x00 */
    struct meshdef1 *prev_meshdef1_pointer; /* 0x04 */
    u32 unk08;                              /* 0x08 */
    u32 unk0C;                              /* 0x0C */
    u32 unk10;                              /* 0x10 */
    u32 vertex_counts[2];                   /* 0x14 */
    f32 some_float;                         /* 0x1C */
    void *facegroup_pointer;                /* 0x20 */
    void *vertext_pointers[2];              /* 0x24 */
    f32 unk2C[12];                          /* 0x2C */
}; // size 0x5C

struct meshdef0 {
    struct meshdef0 *next_meshdef0_pointer;     /* 0x00 */
    struct meshdef0 *prev_meshdef0_pointer;     /* 0x04 */
    struct meshdef0 *unknown_meshdef0_pointer0; /* 0x08 */
    struct meshdef0 *unknown_meshdef0_pointer1; /* 0x0C */
    struct meshdef1 *meshdef1_pointer;          /* 0x10 */
    u32 unk14;                                  /* 0x14 */
    u32 unk18;                                  /* 0x18 */
    f32 big_block_o_floats[9];                  /* 0x1C */
    f32 pos[3];                                 /* 0x40 */
}; // size 0x4C

struct object_entry {
    char object_name[16];            /* 0x00 */
    struct meshdef0 *meshdef0;       /* 0x10 */
    u32 meshdef0_prelude_offset;     /* 0x14 */
    u32 meshdef1_prelude_offsets[4]; /* 0x18 */
    u32 unknown_offsets[3];          /* 0x28 */
    f32 afloat;                      /* 0x34 */
    u16 ashort;                      /* 0x38 */
    u16 bshort;                      /* 0x3A */
    f32 afloat_list[7];              /* 0x3C */
    u32 header_end_offset;           /* 0x58 */
    f32 bfloat_list[6];              /* 0x5C */
}; // size 0x74

struct inner_player_struct {
    struct object_entry *object; /* 0x000 */
    f32 posX;                    /* 0x004 */
    f32 posY;                    /* 0x008 */
    f32 posZ;                    /* 0x00C */
    f32 unk010;                  /* 0x010 */
    f32 unk014;                  /* 0x014 */
    f32 unk018;                  /* 0x018 */
    f32 unk01C;                  /* 0x01C */
    f32 unk020;                  /* 0x020 */
    f32 unk024;                  /* 0x024 */
    f32 unk028;                  /* 0x028 */
    f32 unk02C;                  /* 0x02C */
    f32 unk030;                  /* 0x030 */
    u16 unk034[0x40];            /* 0x034 */
    u16 unk0B4;                  /* 0x0B4 */
    u16 unk0B6;                  /* 0x0B6 */
    s32 unk0B8;                  /* 0x0B8 */
    void *unk0BC;                /* 0x0BC */
    f32 currentHealth;           /* 0x0C0 */
    f32 maxHealth;               /* 0x0C4 */
    f32 advancedShieldTimer;     /* 0x0C8 */
    f32 unk0CC[0x23];            /* 0x0CC */
    u16 blaster_to_fire;         /* 0x158 */
    u16 pad15A;                  /* 0x15A */
    u32 fire_mode;               /* 0x15C */
    f32 unk160[0x03];            /* 0x160 */
    f32 blasterDamageMultiplier; /* 0x16C */
    f32 unk170[0x02];            /* 0x170 */
    u32 unk178[0x35];            /* 0x178 */
    f32 unk24C[0x10];            /* 0x24C */
    u16 unk28C;                  /* 0x28C */
    u16 unk28A;                  /* 0x28A */
    enum PlayerCraft vehicleId;  /* 0x290 */
    u32 unk294;                  /* 0x294 */
    u32 unk298;                  /* 0x298 */
}; // size 0x29C

struct player_struct {
    u8 unk000;                        /* 0x000 */
    u8 unk001;                        /* 0x001 */
    u16 unk002;                       /* 0x002 */
    struct inner_player_struct inner; /* 0x004 */
}; // size 0x2A0

struct rgba {
    u8 r; /* 0x0 */
    u8 g; /* 0x1 */
    u8 b; /* 0x2 */
    u8 a; /* 0x3 */
}; // size = 0x4

struct xy_offset {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
}; // size = 0x4

struct ui_element {
    /* 0x00 */ struct ui_element *prev;
    /* 0x04 */ struct ui_element *next;
    // These seem to control whether the UI element is visible or not, somehow
    /* 0x08 */ u16 texture_count;
    /* 0x0A */ u16 unknown0A;
    /* 0x0C */ u16 *texture_id_pointer;
    /* 0x10 */ struct xy_offset *xy_offset_pointer;
    /* 0x14 */ u32 flags;
    /* 0x18 */ f32 xpos;
    /* 0x1C */ f32 ypos;
    /* 0x20 */ f32 zero; // zpos?, maybe padding
    /* 0x24 */ f32 width_scale;
    /* 0x28 */ f32 height_scale;
    /* 0x2C */ struct rgba rgba;
}; // size = 0x30

struct func_800C0084_d84_type {
    /* 0x00 */ u32 unk00[8];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u16 unk34;
    /* 0x36 */ u16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u32 unk44;
}; // size = 0x48

struct func_800C0084_type {
    /* 0x000 */ u16 hud_texture_ids[0x1E];
    /* 0x03C */ struct ui_element hud_element_0;
    /* 0x06C */ struct ui_element livesCountElement;
    /* 0x09C */ struct ui_element upperHealthIndicatorElement;
    /* 0x0CC */ struct ui_element lowerHealthIndicatorElement;
    /* 0x0FC */ struct ui_element secondaryWeaponCountElement;
    /* 0x12C */ struct ui_element secondaryWeaponSymbolElement;
    /* 0x15C */ struct ui_element secondaryWeaponRingElement;
    /* 0x18C */ struct ui_element radarOutlineElement;
    /* 0x1BC */ struct ui_element playerIdElement;
    /* 0x1EC */ u16 hud_xy_offsets[6][2]; // Not sure why there's only 6 of these but 9 hud elements
    /* 0x204 */ struct rgba hud_element_color_0;
    /* 0x208 */ struct rgba livesCountColor;
    /* 0x20C */ struct rgba upperHealthIndicatorColor;
    /* 0x210 */ struct rgba lowerHealthIndicatorColor;
    /* 0x214 */ struct rgba secondaryWeaponCountColor;
    /* 0x218 */ struct rgba secondaryWeaponSymobolColor;
    /* 0x21C */ struct rgba secondaryWeaponRingColor;
    /* 0x220 */ struct rgba radarOutlineColor;
    /* 0x224 */ struct rgba playerIdColor; // name based on code, but I don't think anything is actually displayed
    /* 0x228 */ u16 livesCountTimer;
    /* 0x22A */ u16 unk22A;
    /* 0x22C */ void *unk22C;
    /* 0x230 */ void *unk230;
    /* 0x234 */ u32 unk234;
    /* 0x238 */ f32 unk238;
    /* 0x23C */ f32 unk23C;
    /* 0x240 */ f32 playerHealthPercentage;
    /* 0x244 */ u32 rest01[8];
    /* 0x264 */ struct ui_element menu_elements[16];
    /* 0x564 */ u16 menu_texture_ids[0x12C];
    /* 0x7BC */ u8  rest02[10];
    // The alignment of this is pretty bizarre
    /* 0x7C6 */ u16 menu_element_xy_offsets[0x12C][2];
    /* 0xC76 */ u8  rest03[2]; // padding, most likely
    /*
    Starting here it looks like there's something like a mini-hob. Its related to the dimming effect on the pause screen.
    The `big_block_o_floats` from the meshdef0 definition is a little small in this case though, only 14 floats instead of 28
    The meshdef1 is also interesting, in the middle of its `big_block_o_floats` there's a pointer of some kind, so that's probably undersized too
    */
    /* 0xC78  u32 mini_hob[0x3C];*/
    struct {
        struct {
            /* 0xC78 */ void *next_meshdef0_pointer;
            /* 0xC7C */ void *prev_meshdef0_pointer;
            /* 0xC80 */ void *unknown_meshdef0_pointer0;
            /* 0xC84 */ void *unknown_meshdef0_pointer1;
            /* 0xC88 */ void *meshdef1_pointer;
            /* 0xC8C */ u32 unk14;
            /* 0xC90 */ u32 unk18;
            /* 0xC94 */ float big_block_o_floats[9];
            /* 0xCB8 */ float pos[3];
        } mini_meshdef0;
        // struct meshdef0 mini_meshdef0
        struct {
            /* 0xCC4 */ void *next_meshdef1_pointer;
            /* 0xCC8 */ void *prev_meshdef1_pointer;
            /* 0xCCC */ u32 unk08;
            /* 0xCD0 */ u32 unk0C;
            /* 0xCD4 */ u32 unk10;
            /* 0xCD8 */ u32 vertex_counts[2];
            /* 0xCE0 */ float some_float;
            /* 0xCE4 */ void *facegroup_pointer;
            /* 0xCE8 */ void *vertext_pointers[2];
            /* 0xCF0 */ u32 unk2C[12];
        } mini_meshdef1;
        // struct meshdef1 mini_meshdef1
        struct {
            /* 0xD20 */ void *next_facegroup;
            /* 0xD24 */ void *prev_facegroup;
            /* 0xD28 */ void *face_offset;
            /* 0xD2C */ u32 face_count;
        } facegroup;
        struct {
            /* 0xD30 */ u32 flags;
            /* struct {
                u32 extra                     : 2;
                u32 face_size                 : 6; // multiply by 4 to get the actual size
                u32 vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
                u32 vertex_color_offset       : 6; // multiply by 4 to get the actual offset
                u32 vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
                u32 texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
            } stuffed_data; */
            /* 0xD34 */ u32 stuffed_data;
            /* 0xD38 */ u32 material_index;
            /* 0xD3C */ u16 vertex_indices[4];
            /* 0xD44 */ struct rgba vertex_colors;
        } face;
        /* 0xD58 */ struct {
            u16 x;
            u16 y;
            u16 z;
            u16 padding;
        } vertices[4];
    } mini_hob;
    /* 0xD68 */ u16 current_entry;
    /* 0xD6A */ u8  current_menu;
    /* 0xD6B */ u8  unkD6B;
    /* 0xD6C */ u32 unkD6C;
    /* 0xD70 */ f32 text_highlight_timer;
    /* 0xD74 */ f32 medal_timer; // a timer related to the medal's back-and-forth rotation
    /* 0xD78 */ u32 unkD78;
    /* 0xD7C */ u32 unkD7C;
    /* 0xD80 */ f32 objective_highlight_countdown; // a countdown to when the objectives should be highlighted, the hilighting uses the same time as the menu selection
    /* 0xD84 */ struct func_800C0084_d84_type unkD84[7];
    /* 0xF7C */ u8 unkF7C;
    /* 0xF7D */ u8 secondaryWeaponType;
    /* 0xF7E */ u8 secondaryWeaponLevel;
    /* 0xF7F */ u8 unkF7F;
}; // size = 0xF80

#endif