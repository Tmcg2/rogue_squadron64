#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include "PR/ultratypes.h"

/*
This is something of a dumping ground for types that are used in a variety of places.
Hopefully it doesn't become too much of a type landfill.
*/

//////////////////////////////////////////////////////////////
// TYPEDEFS
//////////////////////////////////////////////////////////////

typedef f32 Vec3f[3];

//////////////////////////////////////////////////////////////
// ENUMS
//////////////////////////////////////////////////////////////

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

#define CRAFT_FLAG(craftId) (1 << (craftId))

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

struct overlay_dma {
    /* 0x00 */ void *src_addrs[8];
    /* 0x20 */ void *dest_addrs[8];
    /* 0x40 */ u32 dma_size[8];
    /* 0x60 */ u32 transaction_count;
    /* 0x64 */ u32 bss_addr;
    /* 0x68 */ u32 bss_size;
}; // size = 0x6C

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

#endif