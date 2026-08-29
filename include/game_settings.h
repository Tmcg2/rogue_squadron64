#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "PR/ultratypes.h"

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
    /* 0x28 */ u32 nabooStarfighterCheatHash;
    /* 0x2C */ u32 unk2C;
}; // size 0x30

extern struct GameSettings gGameSettings; // 0x80130B40

enum UnlockSettingBits {
    GAME_SETTINGS_AUTO_LEVEL = 0,
    GAME_SETTINGS_AUTO_ROLL,
    // GAME_SETTINGS_BIT_2,
    GAME_SETTINGS_HUD = 3,
    GAME_SETTINGS_COCKPIT,
    GAME_SETTINGS_FREE_CAMERA,
    // GAME_SETTINGS_BIT6,
    GAME_SETTINGS_CROSSHAIR = 7,
    // GAME_SETTINGS_BIT_8,
    GAME_SETTINGS_ADVANCED_BLASTERS = 9,
    GAME_SETTINGS_ADVANCED_MISSILES,
    GAME_SETTINGS_SEEKER_MISSILES,
    GAME_SETTINGS_ADVANCED_TORPEDOS,
    GAME_SETTINGS_SEEKER_TORPEDOS,
    GAME_SETTINGS_SEEKER_CLUSTER_MISSILES,
    GAME_SETTINGS_ADVANCED_BOMBS,
    GAME_SETTINGS_ADVANCED_SHIELD,
    GAME_SETTINGS_MELLINIUM_FALCON,
    GAME_SETTINGS_TIE_INTERCEPTOR,
    GAME_SETTINGS_ALL_CRAFT,
    GAME_SETTINGS_BEGGARS_CANYON,
    GAME_SETTINGS_DEATH_STAR,
    GAME_SETTINGS_HOTH,
    GAME_SETTINGS_HIGH_RESOLUTION= 0,
    GAME_SETTINGS_MUTE_MUSIC,
    GAME_SETTINGS_MUTE_SFX,
    GAME_SETTINGS_MUTE_SPEECH,
    GAME_SETTINGS_DISABLE_SUBTITLES,
    GAME_SETTINGS_DEMO_ACTIVE,
    // GAME_SETTINGS_UNLOCK_BIT_6,
    GAME_SETTINGS_MONO_STEREO = 7,
};

#define GAME_SETTING_MASK(bit) (1 << (bit))
#define GAME_SETTING_IS_SET(byte, bit) (gGameSettings.unlockAndSettingsFlags[(byte)] & GAME_SETTING_MASK((bit)))

#define AUTO_LEVEL_ENABLED               (GAME_SETTING_IS_SET(0, GAME_SETTINGS_AUTO_LEVEL))
#define AUTO_ROLL_ENABLED                (GAME_SETTING_IS_SET(0, GAME_SETTINGS_AUTO_ROLL))
#define HUD_ENABLED                      (GAME_SETTING_IS_SET(0, GAME_SETTINGS_HUD))
#define COCKPIT_ENABLED                  (GAME_SETTING_IS_SET(0, GAME_SETTINGS_COCKPIT))
#define FREE_CAMERA_ENABLED              (GAME_SETTING_IS_SET(0, GAME_SETTINGS_FREE_CAMERA))
#define CROSSHAIR_ENABLED                (GAME_SETTING_IS_SET(0, GAME_SETTINGS_CROSSHAIR))
#define ADVANCED_BLASTERS_UNLOCKED       (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ADVANCED_BLASTERS))
#define ADVANCED_MISSILES_UNLOCKED       (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ADVANCED_MISSILES))
#define SEEKER_MISSILES_UNLOCKED         (GAME_SETTING_IS_SET(0, GAME_SETTINGS_SEEKER_MISSILES))
#define ADVANCED_TORPEDOS_UNLOCKED       (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ADVANCED_TORPEDOS))
#define SEEKER_TORPEDOS_UNLOCKED         (GAME_SETTING_IS_SET(0, GAME_SETTINGS_SEEKER_TORPEDOS))
#define SEEKER_CLUSTER_MISSILES_UNLOCKED (GAME_SETTING_IS_SET(0, GAME_SETTINGS_SEEKER_CLUSTER_MISSILES))
#define ADVANCED_BOMBS_UNLOCKED          (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ADVANCED_BOMBS))
#define ADVANCED_SHIELD_UNLOCKED         (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ADVANCED_SHIELD))
#define MELLINIUM_FALCON_UNLOCKED        (GAME_SETTING_IS_SET(0, GAME_SETTINGS_MELLINIUM_FALCON))
#define TIE_INTERCEPTOR_UNLOCKED         (GAME_SETTING_IS_SET(0, GAME_SETTINGS_TIE_INTERCEPTOR))
#define ALL_CRAFT_UNLOCKED               (GAME_SETTING_IS_SET(0, GAME_SETTINGS_ALL_CRAFT))
#define BEGGARS_CANYON_UNLOCKED          (GAME_SETTING_IS_SET(0, GAME_SETTINGS_BEGGARS_CANYON))
#define DEATH_STAR_UNLOCKED              (GAME_SETTING_IS_SET(0, GAME_SETTINGS_DEATH_STAR))
#define HOTH_UNLOCKED                    (GAME_SETTING_IS_SET(0, GAME_SETTINGS_HOTH))
#define MUSIC_MUTED                      (GAME_SETTING_IS_SET(1, GAME_SETTINGS_MUTE_MUSIC))
#define SFX_MUTED                        (GAME_SETTING_IS_SET(1, GAME_SETTINGS_MUTE_SFX))
#define SPEECH_MUTED                     (GAME_SETTING_IS_SET(1, GAME_SETTINGS_MUTE_SPEECH))
#define SUBTITLES_DISABLED               (GAME_SETTING_IS_SET(1, GAME_SETTINGS_DISABLE_SUBTITLES))
#define DEMO_ACTIVE                      (GAME_SETTING_IS_SET(1, GAME_SETTINGS_DEMO_ACTIVE))
#define MONO_AUDIO                       (GAME_SETTING_IS_SET(1, GAME_SETTINGS_MONO_STEREO))
#define STEREO_AUDIO                     (~GAME_SETTING_IS_SET(1, GAME_SETTINGS_MONO_STEREO))

#define GAME_SETTING_SET(byte, bit)   (gGameSettings.unlockAndSettingsFlags[(byte)] |= GAME_SETTING_MASK((bit)))
#define GAME_SETTING_UNSET(byte, bit) (gGameSettings.unlockAndSettingsFlags[(byte)] &= ~GAME_SETTING_MASK((bit)))

#endif
