#include "common.h"
#include "common_types.h"

#include "main/7CEA0.h"

Vec3f D_main_800A0D90 = {0.0f, 0.0f, 1.0f};

struct D_main_800A0D9C_type {
    char *unk00[3];
    f32 block_o_floats[12];
};

struct D_main_800A0D9C_type D_main_800A0D9C[] = {
    {{"top_tran", "barrel_t", "rohr_tra"},
     {0.064567f, 7.99805f, -0.1937f,
      1.0f, 1.0f, 1.0f,
      10.0f, -181.0f, 181.0f,
      0.0f, 60.0f, -2.0f}},
    {{"top_tran", "barrel_t", "rohr_tra"},
     {1.74563f, 6.63377f, 0.0f,
      1.0f, 1.0f, 1.0f,
      10.0f, -181.0f, 181.0f,
      -10.0f, 181.0f, -2.0f}},
    {{"top_tran", "barrel_t", "rohr_tra"},
     {0.0f, 0.0f, 0.802509f,
      1.0f, 1.0f, 1.0f,
      10.0f, -25.0f, 25.0f,
      -7.0f, 7.0f, -2.0f}},
    {{"top_tran", "barrel_t", "rohr_tra"}, 
     {-3.30829f, 13.6873f, 0.0f,
      1.0f, 1.0f, 1.0f,
      10.0f, -181.0f, 181.0f,
      -20.0f, 70.0f, -2.0f}},
    {{"top_tran", "larm_tra", "rarm_tra"},
     {-3.27379f, 5.40009f, 0.0f,
      1.0f, 1.0f, 1.0f,
      5.0f, -181.0f, 181.0f,
      0.0f, 70.0f, 0.0f}},
};

u32 data_pad_7CEA0[] = {
    0x00000000,
    0x24020271,
};

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", initNpcTexturedEffectFromTemplate);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D69C);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcTexturedEffectUpdate);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcTexturedEffectUpdateVariant);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcTexturedEffectUpdateConditional);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcTexturedEffectUpdateConditionalAlt);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcTexturedEffectUpdateWithSlotChain);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", aimOrientNpcTowardTarget);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", spawnDatDrivenAudioVisualEmitters);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", spawnNamedTexturedEmitterNpc);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D708);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcQuatOrientedMultiPhaseUpdate);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", emitPresetSparkBurst);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", updateWalkerLegStrideAndDust);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcWalkerUpdate);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D7C0);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", submitOrientedEffectMesh);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", twoPointPositionedNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", spawnWorldDevastatorVacuumDebris);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcWordDevastatorUpdate);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D8C0);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", jtbl_main_8003D8C8);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D904);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D908);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D90C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D910);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", jtbl_main_8003D918);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D92C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D930);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D934);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D938);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D93C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D940);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D944);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D948);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D94C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D950);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D954);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D958);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D95C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D960);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D964);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D968);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D96C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D970);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D974);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D978);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D97C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D980);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D984);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D988);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D98C);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D990);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D994);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D998);

INCLUDE_RODATA("asm/nonmatchings/main/7CEA0", D_main_8003D99C);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", attachedAudioVisualEmitterNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcShieldGeneratorUpdate);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcVortexUpdate);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", clearObjectPoolStateFlag);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcSpawnInitTimedEffect);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", npcSpawnInitMarkActive);

INCLUDE_ASM("asm/nonmatchings/main/7CEA0", fake_func_80082268);
