#ifndef CRAFTS_H
#define CRAFTS_H

enum PlayerCraft {
    /* 0x0 */ CRAFT_XWING,
    /* 0x1 */ CRAFT_YWING,
    /* 0x2 */ CRAFT_AWING,
    /* 0x3 */ CRAFT_VWING,
    /* 0x4 */ CRAFT_SNOWSPEEDER,
    /* 0x5 */ CRAFT_FALCON,
    /* 0x6 */ CRAFT_TIEINTER,
    /* 0x7 */ CRAFT_T16,
    /* 0x8 */ CRAFT_KOELSCH,
};

#define CRAFT_FLAG(craftId) (1 << (craftId))

#endif
