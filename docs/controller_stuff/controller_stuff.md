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
enum ControllerSetting {
    /* 0x0 */ CONTROLLER_SETTING_LUKE,
    /* 0x1 */ CONTROLLER_SETTING_WEDGE,
    /* 0x2 */ CONTROLLER_SETTING_JANSON,
    /* 0x3 */ CONTROLLER_SETTING_HOBBIE,
    /* 0x4 */ NUM_CONTROLLER_SETTINGS,
};
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
