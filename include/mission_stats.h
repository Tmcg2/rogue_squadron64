#ifndef MISSION_STATS_H
#define MISSION_STATS_H

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

extern struct mission_stats missionStats; // 0x80130B78

#endif
