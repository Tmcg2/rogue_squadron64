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

struct rgba {
    u8 r; /* 0x0 */
    u8 g; /* 0x1 */
    u8 b; /* 0x2 */
    u8 a; /* 0x3 */
}; // size = 0x4

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
    u32 data_offset;       /* 0x00 */
    u32 decompressed_size; /* 0x04 */
    u32 compressed_size;   /* 0x08 0xFFFFFFFF (or -1 if signed) indicates that the entry is not compressed */
    /*
    bit 7: is directory (0x80)
    bits 1-6: never set, checked in several places though
    bit 0: set a lot (but not alwasy). Purpose unknown
    */
    u8 flags; /* 0x0C */
    u8 unk0D; /* 0x0D */
    /*
    This is a number multiplied by 0x20 (<< 5)
    It is the size in bytes that the directory takes up in the manifest
    So, (directory content entries + 1(the directory entry itself)) * 0x20
    For non-directory entries, this number should be zero 
    */
    u16 directory_size; /* 0x0E */
    u8 name[16];        /* 0x10 */
}; // size 0x20

#endif