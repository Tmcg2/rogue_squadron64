# Controller Stuff

This document is loose assortment of controller related information.
There's not going to be much structure to this document, which I apologize for.

[func_8007A068.c](/docs/controller_stuff/func_8007A068.c) and [func_8007A0A8.c](/docs/controller_stuff/func_8007A0A8.c) appear to convert a controller's stick position into a percent-of-max value.
That is, they read `stick_x` and `stick_y` (respectively) and divide it by 128.

[func_80079D54.c](/docs/controller_stuff/func_80079D54.c) returns a set of bit flags representing the controllers button and stick states. It references `func_8007A068` and `func_8007A0A8`, the return values decide what the stick bit flags should be.
In both the `x` and `y` directions, `-0.53` to `0.53` is considered the deadzone.

| Stick Position                  | Flag     |
| ------------------------------- | -------- |
| Left  (`func_8007A068` < -0.53) | 0x800000 |
| Right (`func_8007A068` >  0.53) | 0x400000 |
| Down  (`func_8007A0A8` < -0.53) | 0x100000 |
| Up    (`func_8007A0A8` >  0.53) | 0x200000 |

Button flags are the same as those used by `OSContPad.button`.

[func_80079CE0.c](/docs/controller_stuff/func_80079CE0.c) sets the values of `D_8013A950` and `D_8013A960` calling [func_80079F20.c](/docs/controller_stuff/func_80079F20.c) which in turn calls `func_80079D54`.
`D_8013A950` and `D_8013A960` are arrays, one word per controller (so, something like `u32 D_8013A950[4]`).
I don't know what to call each of those arrays, but based on how they're set in `func_80079CE0` I have some speculations.
`D_8013A960` looks to me to be like "new stick/button state", while `D_8013A950` would be "previous stick/button state".

[func_80079EB0.c](/docs/controller_stuff/func_80079EB0.c) zero-initializes `D_8013A950` and `D_8013A960`.

[func_80079F50.c](/docs/controller_stuff/func_80079F50.c) is a function to get values out of `D_8013A960`.
Don't know why they made an entire function for that, but whatever.

[func_80079FD8.c](/docs/controller_stuff/func_80079FD8.c) is a function that unsets flags in `D_8013A960`.

## Controller Settings

There are 4 different controller setting sets, named after Star Wars characters.

```cpp
enum ControllerSettingType {
    /* 0x0 */ CONTROLLER_SETTING_LUKE,
    /* 0x1 */ CONTROLLER_SETTING_WEDGE,
    /* 0x2 */ CONTROLLER_SETTING_JANSON,
    /* 0x3 */ CONTROLLER_SETTING_HOBBIE,
    /* 0x4 */ NUM_CONTROLLER_SETTINGS,
};

enum ControllerInput {
    /* 0x00 */ PAUSE,
    /* 0x01 */ SWITCH_VIEW,
    /* 0x02 */ DROP_CAMERA,
    /* 0x03 */ LOOK_AROUND,
    /* 0x04 */ COCKPIT_VIEW,
    /* 0x05 */ CLOSE_VIEW,
    /* 0x06 */ STANDARD_VIEW,
    /* 0x07 */ UNKOWN_OPEARION_07,
    /* 0x08 */ UNKOWN_OPEARION_08,
    /* 0x09 */ BRAKES1,
    /* 0x0A */ BRAKES2,
    /* 0x0B */ BRAKES3,
    /* 0x0C */ THRUST,
    /* 0x0D */ FIRE_BLASTERS,
    /* 0x0E */ FIRE_SECONDARY,
    /* 0x0F */ FIRE_MODE,
    /* 0x10 */ ROLL,
    /* 0x11 */ SPECIAL,
    /* 0x12 */ NUM_INPUTS,
};

union ControllerSettings {
    struct {
        /* 0x00 */ u16 pause;
        /* 0x02 */ u16 switch_view;
        /* 0x04 */ u16 drop_camera;
        /* 0x06 */ u16 look_around;
        /* 0x08 */ u16 cockpit_view;
        /* 0x0A */ u16 close_view;
        /* 0x0C */ u16 standard_view;
        /* 0x0E */ u16 unknown_input_07;
        /* 0x10 */ u16 unknown_input_08;
        /* 0x12 */ u16 brakes1;
        /* 0x14 */ u16 brakes2;
        /* 0x16 */ u16 brakes3;
        /* 0x18 */ u16 thrust;
        /* 0x1A */ u16 fire_blasters;
        /* 0x1C */ u16 fire_secondary;
        /* 0x1E */ u16 fire_mode;
        /* 0x20 */ u16 roll;
        /* 0x22 */ u16 special;
    } asStruct;
    u16 asArray[NUM_INPUTS];
}; // size = 0x24

union ControllerSettings *D_800CC9D8[NUM_CONTROLLER_SETTINGS];
union ControllerSettings *D_80109AD0[NUM_CONTROLLER_SETTINGS];
union ControllerSettings  D_8010BE18[];
```

You can fiddle with the byte at ROM address `0x80130B45` to set this value directly in memory.
I don't know if you'd need to do anything special to make the change "stick".
See [unsorted thoughts](/docs/unsorted_thoughts/unsorted_thoughts.md) for more details.

[func_800BD274.c](/docs/controller_stuff/func_800BD274.c) is a function at least partially related to the `Controller Settings` screen.
That function also implies that there is a series of structs that are in some capacity responsible for the displaying of the text on that screen.
The structs are `0x1B8` bytes in size, the only thing I can with any certainty is that the first member would be a 16 (or maybe 32?) character string.
More investigation is required to get more details.
[func_800BCE2C.c](/docs/controller_stuff/func_800BCE2C.c) is the function responsible for malloc'ing and initializing the structs, so that's a good starting point.

[func_800B47C4.c](/docs/controller_stuff/func_800B47C4.c) is a very big function, likely responsible for WAY more than just controller stuff.
It references `func_80079F50` and `func_800BD274` in a way that, too my eyes, looks like it handling the pressing of stick left/right on the `Controller Settings` menu screen.

[getControllerSettingsTitle.c](/docs/controller_stuff/getControllerSettingsTitle.c) (ROM address `0x800C49BC`) is exactly what it sounds like.
It generated the title of the `Controller Settings` menu screen, which requires a tiny bit of extra work in the event that the display language is French.
