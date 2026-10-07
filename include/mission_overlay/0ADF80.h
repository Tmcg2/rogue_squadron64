#ifndef MISSION_0ADF80_H
#define MISSION_0ADF80_H

#include "PR/ultratypes.h"
#include "common_types.h"

#include "main/bss_80139010.h"

struct D_mission_overlay_8010B6E0_type {
    Vec3f  unk00; /* 0x00 */
    f32    unk0C; /* 0x0C */
    Mat4x3 unk10; /* 0x10 */
    struct D_main_bss_801394E8_type unk40; /* 0x40 */
    u8     unkF4; /* 0xF4 */
    u8     unkF5; /* 0xF5 */
    u8     unkF6; /* 0xF6 */
    u8     unkF7; /* 0xF7 */
}; // size 0xF8

struct D_mission_overlay_8010B6E8_type {
    u8     unk00; /* 0x00 */
    u8     unk01; /* 0x01 */
    u8     unk02; /* 0x02 */
    u8     unk03; /* 0x03 */
    Mat4x3 unk04; /* 0x04 */
    Vec3f  unk34; /* 0x34 */
    Vec3f  unk44; /* 0x44 */
    u32    unk50; /* 0x50 */
}; // size 0x54(?)

void computeTrackedObjectWorldAnchor(struct D_mission_overlay_8010B6E8_type*);
void resetEffectSequenceState(void);
void freeEffectModelInstancePool(void);
void requestCameraSnapToTrackedAnchor(void);
void beginCameraTrackedTransition(void);
s32  isCameraTransitionIdle(void);

#endif
