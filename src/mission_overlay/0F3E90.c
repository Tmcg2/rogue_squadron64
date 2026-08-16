#include "common.h"

#include "level_objectives.h"
#include "mission_overlay/0F3E90.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F3290);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F34DC);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F3CB0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0F3E90", D_mission_overlay_800A8BB8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F410C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F4E74);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F538C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F5A30);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F5D34);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F6954);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F7130);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F7C74);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F8398);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9474);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F947C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9674);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F97B4);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F97F4);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F981C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F98CC);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9918);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F99C8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9A14);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9AB8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9AF4);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9B0C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9B34);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9BEC);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9C30);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", func_mission_overlay_800F9D68);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", load_model_animation);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", reset_model_animations);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", reset_and_free_model_animations);

#if 0
// The major mismatch with this is that the original code accesses a bunch of information
// via negative offsets from the unk0D element. This is strange, I don't think you can tickle
// GCC into doing this through "normal" code.
s32 checkObjectiveHandles(f32 arg0) {
    s32 var_s2;
    s32 temp_a0;
    s32 temp_a1;
    struct simpleCheckHandle *var_s1;

    for (var_s2 = 0; var_s2 < 0x30; var_s2++) {
        var_s1 = &simpleCheckHandles[var_s2];
        if (var_s1->active != 1) continue;

        switch (var_s1->checkType) {
            case 0:
                temp_a0 = var_s1->checks.boolcount.objectiveBooleanIndex;
                if ((temp_a0 != 0) && (gObjectiveBooleans[temp_a0 - 1] != var_s1->checks.boolcount.objectiveBooleanValue)) continue;

                temp_a0 = var_s1->checks.boolcount.objectiveCountIndex;
                if (temp_a0 == 0) break;
                temp_a1 = var_s1->checks.boolcount.unk07;
                if ((temp_a1 == 0) && (gObjectiveCounts[temp_a0 - 1] < var_s1->objectiveCountValue)) continue;

                if (var_s1->checks.boolcount.unk07 != 1) break;
                if (gObjectiveCounts[var_s1->checks.boolcount.unk07 - 1] >= var_s1->objectiveCountValue) continue;
                break;
            case 1:
                var_s1->checks.timer.timer -= arg0;
                if (var_s1->checks.timer.timer > 0.0f) continue;
                break;
            default:
                continue;
        }
        var_s1->active = 0;
        if (var_s1->unk0D == 0) {
            var_s1->handle();
        }
    }
    return 1;

//         if (simpleCheckHandles[var_s2].checkType != 0) {
//             if (simpleCheckHandles[var_s2].checkType != 1) continue;
//             simpleCheckHandles[var_s2].checks.timer.timer -= arg0;
//             if (simpleCheckHandles[var_s2].checks.timer.timer <= 0.0f) {
//                 simpleCheckHandles[var_s2].active = 0;
//                 if (simpleCheckHandles[var_s2].unk0D == 0) {
//                     simpleCheckHandles[var_s2].handle();
//                 }
//             }
//         } else {
//             temp_a0 = simpleCheckHandles[var_s2].checks.boolcount.objectiveBooleanIndex;
//             if ((temp_a0 == 0) ||
//                 (gObjectiveBooleans[temp_a0 - 1] == simpleCheckHandles[var_s2].checks.boolcount.objectiveBooleanValue)) {
//                     temp_a0 = simpleCheckHandles[var_s2].checks.boolcount.objectiveCountIndex;
//                     if (temp_a0 == 0) {
//                         temp_a1 = simpleCheckHandles[var_s2].checks.boolcount.unk07;
//                         if((temp_a1 != 0) || (gObjectiveCounts[temp_a0 - 1] >= simpleCheckHandles[var_s2].objectiveCountValue)) {
//                             if (temp_a1 == 1)
//                         }
//                     } else {
//                         simpleCheckHandles[var_s2].active = 0;
//                         if (simpleCheckHandles[var_s2].unk0D == 0) {
//                             simpleCheckHandles[var_s2].handle();
//                         }
//                     }
//                 }
//         }
//     }
//     return 1;
//     var_s2 = 0;
//     var_s1 = simpleCheckHandles;
//     var_s0 = &simpleCheckHandles->unk0D;
//     do {
//         temp_a1 = var_s0->unk1;
//         if (temp_a1 == 1) {
//             temp_v0 = var_s0->unk-1;
//             if (temp_v0 != 0) {
//                 if (temp_v0 != temp_a1) {
//                     var_s2 += 1;
//                 } else {
//                     temp_fv0 = var_s0->unk-9 - arg0;
//                     var_s0->unk-9 = temp_fv0;
//                     if (!(temp_fv0 > 0.0f)) {
//                         goto block_14;
//                     }
//                     goto block_16;
//                 }
//             } else {
//                 temp_v0_2 = (bitwise u8) var_s0->unk-9;
//                 if ((temp_v0_2 == 0) || (gObjectiveBooleans[temp_v0_2].unk-1 == var_s0->unk-8)) {
//                     temp_v0_3 = var_s0->unk-7;
//                     if (temp_v0_3 != 0) {
//                         temp_a0 = var_s0->unk-6;
//                         if ((temp_a0 != 0) || ((s32) gObjectiveCounts[temp_v0_3 - 1] >= var_s0->unk-5)) {
//                             if (temp_a0 == temp_a1) {
//                                 if ((s32) gObjectiveCounts[var_s0->unk-7 - 1] < var_s0->unk-5) {
//                                     goto block_14;
//                                 }
//                             } else {
//                                 goto block_14;
//                             }
//                         }
//                     } else {
// block_14:
//                         var_s0->unk1 = 0U;
//                         if (var_s0->unk0 == 0) {
//                             var_s1->handle();
//                         }
//                     }
//                 }
//                 goto block_16;
//             }
//         } else {
// block_16:
//             var_s2 += 1;
//         }
//         var_s0 += 0x10;
//         var_s1 += 0x10;
//     } while (var_s2 < 0x30);
//     return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", checkObjectiveHandles);
#endif

s32 initializeObjectiveHandles(void) {
    s32 var_v1;

    for (var_v1 = 0x2F; var_v1 >= 0; var_v1--) {
        simpleCheckHandles[var_v1].active = 0;
    }
    return 1;
}

s32 addBooleanCountHandle(void (*handle)(), u8 booleanIndex, u8 booleanValue, u8 checkIndex, u32 checkCount, u8 arg5) {
    s32 var_v1;

    for (var_v1 = 0; var_v1 < 0x30; var_v1++) {
        if (simpleCheckHandles[var_v1].active == 0) break;
    }

    if (var_v1 == 0x30) {
        return 0;
    } else { 
        simpleCheckHandles[var_v1].active = 1;
        simpleCheckHandles[var_v1].unk0D = 0;
        simpleCheckHandles[var_v1].checkType = 0;
        simpleCheckHandles[var_v1].handle = handle;
        simpleCheckHandles[var_v1].checks.boolcount.objectiveBooleanIndex = booleanIndex;
        simpleCheckHandles[var_v1].checks.boolcount.objectiveBooleanValue = booleanValue;
        simpleCheckHandles[var_v1].checks.boolcount.objectiveCountIndex = checkIndex;
        simpleCheckHandles[var_v1].objectiveCountValue = checkCount;
        simpleCheckHandles[var_v1].checks.boolcount.unk07 = arg5;
        return 1;
    }
}

s32 addTimerHandle(void (*handle)(), f32 timerValue) {
    s32 var_v1;

    for (var_v1 = 0; var_v1 < 0x30; var_v1++) {
        if (simpleCheckHandles[var_v1].active == 0) break;
    }

    if (var_v1 == 0x30) {
        return 0;
    } else {
        simpleCheckHandles[var_v1].active = 1;
        simpleCheckHandles[var_v1].unk0D = 0;
        simpleCheckHandles[var_v1].checkType = 1;
        simpleCheckHandles[var_v1].handle = handle;
        simpleCheckHandles[var_v1].checks.timer.timer = timerValue;
        return 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F3E90", fake_func_800FA248);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0F3E90", D_mission_overlay_800A8F64);
