#include "common.h"

#include "main/1D000.h"
#include "mission_overlay/0F09E0.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", func_mission_overlay_800EFDE0);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", isPendingChildNpcActive);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", validateActorTargetLOS);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", computeActorAnchorDeltaAfterLOS);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", evaluateTargetTrackingVisibility);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", tickObjectAnimSubstruct);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", resolveNpcAttachmentPos);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", quicksortFloatKeysWithValues);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", gatherAndSortNearbyNpcViewPoints);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", acquireNpcTargetsInAimCone);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", tickProgressChannel);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", raycastTerrainAndNpcs);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", initActorRenderDescriptorIfUninit);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", initActorRenderDescriptorWithNpcVelocity);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setNpcHealth);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getNpcCurrentHealth);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", dealDamageToNpc);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getNpcMissingHealth);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getNpcHealthPercentage);

s32 isVectorWithinConeAndRange(Mat4x3 arg0, f32 arg1, f32 arg2, Vec3f arg3) {
    Vec3f sp10;
    f32 temp_fs1_2;
    f32 temp_fs2;
    s32 var_v0;

    sp10[0] = arg3[0] - arg0[0][0];
    sp10[1] = arg3[1] - arg0[0][1];
    sp10[2] = arg3[2] - arg0[0][2];
    temp_fs2 = ((sp10[0] * sp10[0]) + (sp10[2] * sp10[2]));
    if ((arg1 * arg1) < temp_fs2) {
        return 0;
    }
    temp_fs1_2 = vec3Dot(arg0[1], sp10) / (vec3Length(arg0[1]) * vec3Length(sp10));
    // I hate that this matches :(
    if (!(temp_fs2 < 1.0f) || (var_v0 = 1, !(temp_fs1_2 >= 0.0f))) {
        if (!(temp_fs1_2 < arg2)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
    }
    return var_v0;
}

s32 isVectorInConeWriteDistance(Mat4x3 arg0, f32 arg1, f32 arg2, Vec3f arg3, f32 *arg4) {
    Vec3f sp10;

    sp10[0] = arg3[0] - arg0[0][0];
    sp10[1] = arg3[1] - arg0[0][1];
    sp10[2] = arg3[2] - arg0[0][2];
    if (!((arg1 * arg1) < ((sp10[0] * sp10[0]) + (sp10[2] * sp10[2])))) {
        if (!((vec3Dot(arg0[1], sp10) / (vec3Length(arg0[1]) * vec3Length(sp10))) < arg2)) {
            *arg4 = vec3Length(sp10);
            return 1;
        }
    }
    return 0;
}

s32 computeTurnAxisTowardTarget(Mat4x3 arg0, f32 arg1, f32 arg2, Vec3f arg3, UNIDENTIFIED_TYPE *arg4, struct Struct3f *arg5) {
    Vec3f sp10;
    struct Struct3f sp20;
    f32 *temp_s1;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_ft0;
    f32 temp_fv0;

    sp10[0] = arg3[0] - arg0[0][0];
    sp10[1] = arg3[1] - arg0[0][1];
    sp10[2] = arg3[2] - arg0[0][2];
    if (((arg1 * arg1) < ((sp10[0] * sp10[0]) + (sp10[2] * sp10[2])))) return 0;

    normalize_vector(sp10);
    temp_fa0 = vec3Dot(arg0[1], sp10) / (vec3Length(arg0[1]) * vec3Length(sp10));
    if (temp_fa0 < arg2) return 0;

    constMinusSinfApprox(temp_fa0);
    vec3Cross(&sp20, arg0[1], sp10);
    if (vec3Length(&sp20) != 0.0f) {
        normalize_vector(&sp20);
    }
    *arg5 = sp20;
    return 1;
}

#if 0
// The register allocation surrounding the struct copy is a little incorrect, which is annoying because
// that works just fine in `computeTurnAxisTowardTarget`
f32 computeTurnVectorTowardTarget(Mat4x3 arg0, Vec3f arg1, struct Struct3f *arg2, f32 *arg3) {
    Vec3f sp10;
    struct Struct3f sp20;
    f32 temp_fs0;

    sp10[0] = arg1[0] - arg0[0][0];
    sp10[1] = arg1[1] - arg0[0][1];
    sp10[2] = arg1[2] - arg0[0][2];
    temp_fs0 = constMinusSinfApprox(vec3Dot(arg0[1], sp10) / (vec3Length(arg0[1]) * vec3Length(sp10))) * 57.29578f;
    vec3Cross(&sp20, arg0[1], sp10);
    if (vec3Length(&sp20) != 0.0f) {
        normalize_vector(&sp20);
    }
    *arg2 = sp20;
    return temp_fs0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", computeTurnVectorTowardTarget);
#endif

#if 0
// The register allocation surrounding the struct copy is a little incorrect, which is annoying because
// that works just fine in `computeTurnAxisTowardTarget`
// https://decomp.me/scratch/D6Lx1
f32 computeTurnVectorAndDistanceToTarget(Mat4x3 arg0, Vec3f arg1, struct Struct3f *arg2, f32 *arg3) {
    Vec3f sp10;
    struct Struct3f sp20;
    f32 temp_fs0;

    sp10[0] = arg1[0] - arg0[0][0];
    sp10[1] = arg1[1] - arg0[0][1];
    sp10[2] = arg1[2] - arg0[0][2];
    *arg3 = vec3Length(sp10);
    temp_fs0 = constMinusSinfApprox(vec3Dot(arg0[1], sp10) / (vec3Length(arg0[1]) * vec3Length(sp10))) * 57.29578f;
    vec3Cross(&sp20, arg0[1], sp10);
    if (vec3Length(&sp20) != 0.0f) {
        normalize_vector(&sp20);
    }
    *arg2 = sp20;
    return temp_fs0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", computeTurnVectorAndDistanceToTarget);
#endif

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", isPointInsideTriggerVolume);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getNpcDetailLevelByIndex);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setObjectDetailLevel);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getObjectDetailLevel);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", initActorMotionParams);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getObjectMeshTransformOrLocal);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getObjectNpcTypeId);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", clearPendingChildNpc);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setObjectFlagBit4);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", clearObjectFlagBit4);

void computeAnchorRelativePositionByDistanceRatio(Vec3f arg0, Mat4x3 arg1, f32 arg2, Vec3f arg3) {
    Vec3f sp10;
    f32 temp_fv0;
    f32 var_ft0;

    sp10[0] = arg1[0][0] - arg0[0];
    sp10[1] = arg1[0][1] - arg0[1];
    sp10[2] = arg1[0][2] - arg0[2];
    temp_fv0 = vec3Length(sp10);
    if (arg2 > 0.0f) {
        var_ft0 = temp_fv0 / arg2;
    } else {
        var_ft0 = 0.0f;
    }
    arg3[0] = (f32) (arg1[0][0] + (arg1[3][0] * var_ft0));
    arg3[1] = (f32) (arg1[0][1] + (arg1[3][1] * var_ft0));
    arg3[2] = (f32) (arg1[0][2] + (arg1[3][2] * var_ft0));
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", initObjectAnimSubstruct);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", initAnimSubstructFromParams);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", applyToObjectSubstructByFlag);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setObjectSubstructF10IfReady);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setAnimSubstructValueIfActive);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", generatePerpEmitDirectionWithJitter);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", stepAndTickProgressChannel);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", getEffectIntensity);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", setEffectIntensity);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", triggerCueWithSlotEffect);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", copyPipeDelimitedField);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", copyRandomPipeDelimitedField);

s32 returnZero_800F3258(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0F09E0", tallyMidDetailObject);
