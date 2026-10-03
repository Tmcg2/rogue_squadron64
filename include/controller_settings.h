#ifndef CONTROLLER_SETTINGS_H
#define CONTROLLER_SETTINGS_H

#include "PR/ultratypes.h"

enum ControllerSettingType {
    CONTROLLER_SETTING_LUKE,   /* 0x0 */
    CONTROLLER_SETTING_WEDGE,  /* 0x1 */
    CONTROLLER_SETTING_JANSON, /* 0x2 */
    CONTROLLER_SETTING_HOBBIE, /* 0x3 */
    CONTROLLER_SETTING_NUM,    /* 0x4 */
};

enum ControllerInput {
    CONTROLLER_INPUT_PAUSE,              /* 0x00 */
    CONTROLLER_INPUT_SWITCH_VIEW,        /* 0x01 */
    CONTROLLER_INPUT_DROP_CAMERA,        /* 0x02 */
    CONTROLLER_INPUT_LOOK_AROUND,        /* 0x03 */
    CONTROLLER_INPUT_COCKPIT_VIEW,       /* 0x04 */
    CONTROLLER_INPUT_CLOSE_VIEW,         /* 0x05 */
    CONTROLLER_INPUT_STANDARD_VIEW,      /* 0x06 */
    CONTROLLER_INPUT_UNKOWN_OPEARION_07, /* 0x07 */
    CONTROLLER_INPUT_UNKOWN_OPEARION_08, /* 0x08 */
    CONTROLLER_INPUT_BRAKES1,            /* 0x09 */
    CONTROLLER_INPUT_BRAKES2,            /* 0x0A */
    CONTROLLER_INPUT_BRAKES3,            /* 0x0B */
    CONTROLLER_INPUT_THRUST,             /* 0x0C */
    CONTROLLER_INPUT_FIRE_BLASTERS,      /* 0x0D */
    CONTROLLER_INPUT_FIRE_SECONDARY,     /* 0x0E */
    CONTROLLER_INPUT_FIRE_MODE,          /* 0x0F */
    CONTROLLER_INPUT_ROLL,               /* 0x10 */
    CONTROLLER_INPUT_SPECIAL,            /* 0x11 */
    CONTROLLER_INPUT_NUM,                /* 0x12 */
};

union ControllerSettings {
    struct {
        u16 pause;            /* 0x00 */
        u16 switch_view;      /* 0x02 */
        u16 drop_camera;      /* 0x04 */
        u16 look_around;      /* 0x06 */
        u16 cockpit_view;     /* 0x08 */
        u16 close_view;       /* 0x0A */
        u16 standard_view;    /* 0x0C */
        u16 unknown_input_07; /* 0x0E */
        u16 unknown_input_08; /* 0x10 */
        u16 brakes1;          /* 0x12 */
        u16 brakes2;          /* 0x14 */
        u16 brakes3;          /* 0x16 */
        u16 thrust;           /* 0x18 */
        u16 fire_blasters;    /* 0x1A */
        u16 fire_secondary;   /* 0x1C */
        u16 fire_mode;        /* 0x1E */
        u16 roll;             /* 0x20 */
        u16 special;          /* 0x22 */
    } asStruct;
    u16 asArray[CONTROLLER_INPUT_NUM];
}; // size = 0x24

extern union ControllerSettings *D_800CC9D8[CONTROLLER_SETTING_NUM];
extern union ControllerSettings  D_8010BE18[];

#endif
