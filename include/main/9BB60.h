#ifndef MAIN_9BB60_H
#define MAIN_9BB60_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct some_voice_playback_thing {
    u8  pad0000[0x1200 - 0x0000]; /* 0x0000 */
    u8  unk1200;                  /* 0x1200 */
    u8  unk1201;                  /* 0x1201 */
    u8  unk1202;                  /* 0x1202 */
    u8  unk1203;                  /* 0x1203 */
    u8  pad1204[0x1214 - 0x1204]; /* 0x1204 */
    u32 pad1214;                  /* 0x1214 */
    u32 pad1218[0x1228 - 0x1218]; /* 0x1218 */
}; // size 0x1228

f32 getVoicePlaybackProgressByKey(s32, f32*);

#endif
