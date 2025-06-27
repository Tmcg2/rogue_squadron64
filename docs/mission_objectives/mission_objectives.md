# Mission Objectives

```cpp
struct simpleCheckHandle {
    /* 0x00 */ void (*handle)(void);
    union {
        struct {
            /* 0x04 */ u8  objectiveBooleanIndex;
            /* 0x05 */ u8  objectiveBooleanValue;
            /* 0x06 */ u8  objectiveCountIndex;
            /* 0x07 */ u8  unk07;
        };
        /* 0x04 */ f32 timer;
    }
    /* 0x08 */ u32 objectiveCountValue;
    /* 0x0C */ u8  checkType; // 0 = objective check, 1 = timer check
    /* 0x0D */ u8  unk0D;
    /* 0x0E */ u8  active;
    /* 0x0F */ u8  unk0F; // might be padding?
}; // size = 0x10

struct simpleCheckHandle simpleCheckHandles[0x30];

u8  gObjectiveBooleans[0x80];
u32 gObjectiveCounts[0x80];
f32 gObjectiveTimers[8];

struct D_8010A450_type {
    /* 0x0 */ s32 (*initializeObjectiveTracking)(void);
    /* 0x4 */ s32 (*unk4)(void);
    /* 0x8 */ s32 (*calculateFriendliesSaved)(void);
    /* 0xC */ s32 (*checkComplexObjectives)(void);
}; // size = 0x10

struct D_8010A450_type D_8010A450[0x15] = {
    { func_80101090, func_80101954, func_8010195C, func_8010119C },
    { func_801019A0, func_80101BE4, func_80101BEC, func_80101C48 },
    { func_80101CD0, func_80102A64, func_80102A6C, func_80101EF4 },
    { func_80102AA0, func_80103528, func_80103530, func_80102D08 },
    { func_80103580, func_80103CBC, func_80103CC4, func_80103720 },
    { func_80103D10, func_80104110, func_80104118, func_8010415C },
    { func_8010439C, func_8010443C, func_80104444, func_80104210 },
    { func_80104A0C, func_80104A58, func_80104A60, func_801044E0 },
    { func_80104D8C, func_80104E64, func_80104E9C, func_80104AA0 },
    { func_80104F80, func_80105B00, func_80105B08, func_801051CC },
    { func_80105B60, func_80106100, func_80106108, func_80106134 },
    { func_801061A0, func_80106B98, func_80106BA0, func_801062E4 },
    { func_80106BF0, func_801071E8, func_801071F0, func_80106D3C },
    { func_80107220, func_80107290, func_80107298, func_801072A0 },
    { func_80107370, func_80107E58, func_80107E60, func_80107578 },
    { func_80107EB0, func_80108494, func_8010849C, func_8010802C },
    { func_80108B34, func_80108B7C, func_80108B84, func_801084E0 },
    { func_80108B90, func_80108E68, func_80108E70, func_80108EB0 },
    { func_80109114, func_801091F8, func_80109200, func_80108F60 },
    { func_80109620, func_80109628, func_80109630, func_80109638 },
    { func_80109590, func_801095CC, func_801095D4, func_80109430 },
};
```

In-mission events are tracked in 3 main ways.

1) Booleans
2) Counts
3) Timers

There are a couple other things that are checked (like distance between the player and an object) but they aren't tracked in any special way.

## Booleans

There are a maximum of 128 booleans that can be tracked.
When something happens (usually something getting destroyed) a boolean gets set in the `gObjectiveBooleans` array.

## Counts

When something happens (pretty well always something getting destroyed) some count in `gObjectiveCounts` is incremented (or, on occasion, set).

## Timers

There are 8 timers in total, found in `gObjectiveTimers`.
They all seem to count up from when the level starts, although there are several instances of the timers being (re)set.

## Simple Checks

What I'm dubbing "simple" checks are checks that check exactly one boolean, count, or timer.
These checks are handled by `struct simpleCheckHandles`.
When the given condition is met (a boolean gets set, a count reaches a value, a timer runs out), the `handle` function pointer is invoked.
Its interesting, these check types don't reference the `gObjectiveTimers`, instead they have their own count down timers.

These checks are setup in a per-level function stored in the `D_8010A450` array.

NPCs are part of the [DAT file](../dat_files/dat_file.md), and they (optionally) have booleans and counts associated with them.
When an NPC dies it calls `datItemSetObjectiveBooleanCount`, adjusting those associated checks.
An interesting thing to note is that NPCs will only ever have 1 boolean associated with them, but can have up to 2 counts.
For example, the probe droids in the 1st level (Ambust at Mos Eisley) modify 2 counts.
One for "droids in group destroyed" and the other for "total droids destroyed".

## Complex Checks

So called "complex" checks are checks that

- Check more than one boolean/count/timer
- Check NPC health
- Check distance to player
- Other non-simple checks
- Some combination thereof

Its pretty common for these checks to be accompanied by auxiallary booleans (`u32`s instead of `u8`s) which are in effect "I've already been triggered" trackers.
That way voicelines and other side effects don't happen multiple times.

These checks are handled in a per-level function stored in the `D_8010A450` array.

## Friendlies Saved

Calculation of friendlies saved is also hadled by a function in the `D_8010A450` array.
The usual method used is to take the total number of friendlies in the level (a hard coded value) and subtract the number of friendlies destoryed (stored in `gObjectiveCounts`).
If there's multiple types of friendlies that can be destroyed (say, buildings and wingmen), they are usually tracked in different counts.
