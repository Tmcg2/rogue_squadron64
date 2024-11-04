struct _m2c_stack_func_800BCE2C {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ f32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ f32 sp20;                            /* inferred */
    /* 0x24 */ f32 sp24;                            /* inferred */
    /* 0x28 */ f32 sp28;                            /* inferred */
    /* 0x2C */ char pad2C[4];
    /* 0x30 */ f32 sp30;                            /* inferred */
    /* 0x34 */ f32 sp34;                            /* inferred */
    /* 0x38 */ f32 sp38;                            /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ f32 sp40;                            /* inferred */
    /* 0x44 */ f32 sp44;                            /* inferred */
    /* 0x48 */ s32 sp48;                            /* inferred */
    /* 0x4C */ char pad4C[4];
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ f32 sp54;                            /* inferred */
    /* 0x58 */ s32 sp58;                            /* inferred */
    /* 0x5C */ char pad5C[0x5C];
};                                                  /* size = 0xB8 */

? func_80019548(f32 *, f32 *, f32 *);               /* extern */
? func_8001CA50(u8 *);                              /* extern */
? func_8001CA90(u8 *, ?, ?, ?);                     /* extern */
? func_8001CB64(u8 *, ?, f32, f32);                 /* extern */
? func_8001CF58(f32, f32 *);                        /* extern */
extern f32 D_800A6C50;
extern f32 D_800A6C54;
extern f32 D_800A6C58;
extern f32 D_800A6C5C;
extern f32 D_800A6C60;
extern f32 D_800A6C64;
extern f32 D_800A6C68;
extern f32 D_800A6C6C;
extern f32 D_800A6C70;
extern f32 D_800A6C74;
extern f32 D_800A6C78;
extern f32 D_800A6C7C;
extern ? D_800CC874;
extern ? func_800CC9B8;

// Initializing a big series of 14 structs, 0x1B8 bytes big each, for the controller settings screen
// Controls the location and color of the boxes lines and (presumably) text on the screen
// Exact details are unclear
/*
struct controller_setting_thing {
    char setting_name[32];
    f32 some_floats_0[6];
    
};
*/
u8 *func_800BCE2C(void) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp40;
    f32 sp44;
    s32 sp48;
    f32 sp50;
    f32 sp54;
    s32 sp58;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    s16 temp_a0;
    s16 var_a3;
    s16 var_t0;
    s16 var_t1;
    s32 var_a2;
    u32 var_a1;
    u32 var_s4;
    u8 *temp_s1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *var_s2;
    void *var_s3;

    temp_v0 = rs_malloc(0x00001810, 0U);
    rs_memset(temp_v0, 0U, 0x00001810U);
    var_s4 = 0;
    var_s2 = temp_v0;
    var_s3 = &func_800CC9B8 + 0xE8;
    temp_fs5 = D_800A6C50;
    temp_fs4 = D_800A6C54;
    temp_fs3 = D_800A6C58;
    temp_fs1 = D_800A6C5C;
    temp_fs0 = D_800A6C60;
    do {
        temp_s1 = var_s2 + 0x54;
        func_8001CA50(temp_s1);
        var_s2->unk48 = (u8 *) (var_s2 + 0x84);
        var_s2->unkA4 = (u8 *) (var_s2 + 0xE0);
        var_s2->unk98 = 8;
        var_s2->unkE8 = (u8 *) (var_s2 + 0xF0);
        var_s2->unkA8 = (u8 *) (var_s2 + 0x158);
        var_s2->unk90 = 0x00060009;
        var_s2->unkEC = 2;
        var_s2->unk30 = (f32) var_s3->unk0;
        var_s2->unk34 = (f32) ((var_s3->unk4 - D_800A6C64) + D_800A6C68);
        var_s2->unk28 = (f32) var_s3->unk8;
        var_s2->unk2C = (f32) var_s3->unkC;
        var_s2->unk20 = (f32) var_s3->unk10;
        temp_ft2 = var_s2->unk20;
        var_s2->unk24 = (f32) var_s3->unk14;
        sp40 = temp_ft2;
        temp_ft1 = var_s2->unk24;
        sp48 = 0;
        sp44 = temp_ft1;
        temp_fv1 = (var_s2->unk30 * D_800A6C6C) + var_s2->unk28;
        sp50 = temp_fv1;
        temp_fv1_2 = temp_fv1 - temp_ft2;
        temp_ft0 = (var_s2->unk34 * D_800A6C70) + var_s2->unk2C;
        temp_ft1_2 = temp_ft0 - temp_ft1;
        sp58 = 0;
        sp20 = temp_fv1_2;
        sp54 = temp_ft0;
        sp24 = temp_ft1_2;
        sp28 = 0.0f;
        sp20 = temp_fv1_2 * D_800A6C74;
        sp24 = temp_ft1_2 * temp_fs5;
        func_8001CF58(D_800A6C74, &sp20);
        sp30 = 0.0f;
        sp34 = 0.0f;
        sp38 = temp_fs4;
        func_80019548(&sp10, &sp20, &sp30);
        temp_ft2_2 = sp10 * temp_fs3;
        temp_ft0_2 = sp14 * temp_fs3;
        temp_fv1_3 = temp_ft2_2 * D_800A6C78;
        sp10 = temp_ft2_2;
        sp14 = temp_ft0_2;
        sp18 *= temp_fs3;
        sp10 = temp_fv1_3;
        sp14 = temp_ft0_2 * D_800A6C7C;
        var_s2->unk188 = (f32) (sp40 - temp_fv1_3);
        var_s2[0x188].unk4 = (f32) (sp44 - sp14);
        var_s2[0x188].unkC = (f32) (sp40 + temp_fv1_3);
        var_s2[0x188].unk10 = (f32) (sp44 + sp14);
        var_s2[0x188].unk18 = (f32) (sp50 - temp_fv1_3);
        var_s2[0x188].unk1C = (f32) (sp54 - sp14);
        var_s2[0x188].unk24 = (f32) (sp50 + temp_fv1_3);
        var_s2[0x188].unk28 = (f32) (sp54 + sp14);
        var_s2->unk158 = (f32) (var_s2->unk20 - temp_fs1);
        var_s2[0x158].unk4 = (f32) (var_s2->unk24 - temp_fs0);
        var_s2[0x158].unkC = (f32) (var_s2->unk20 + temp_fs1);
        var_s2[0x158].unk10 = (f32) (var_s2->unk24 - temp_fs0);
        var_s2[0x158].unk18 = (f32) (var_s2->unk20 - temp_fs1);
        var_s2[0x158].unk1C = (f32) (var_s2->unk24 + temp_fs0);
        var_s2[0x158].unk24 = (f32) (var_s2->unk20 + temp_fs1);
        var_s2[0x158].unk28 = (f32) (var_s2->unk24 + temp_fs0);
        func_8001CB64(temp_s1, 0x3EB69985, temp_fs5, temp_fs4);
        func_8001CA90(temp_s1, 0, 0x3DAAAAAB, 0x401A826B);
        var_a1 = 0;
        var_t1 = 2;
        var_t0 = 3;
        var_a3 = 1;
        var_a2 = 0xF0;
loop_2:
        temp_v0_2 = &var_s2[var_a2];
        temp_v0_2->unk12 = var_t1;
        var_t1 += 4;
        temp_v0_2->unk10 = var_t0;
        var_t0 += 4;
        temp_v0_2->unkE = var_a3;
        var_a3 += 4;
        temp_a0 = var_a1 * 4;
        temp_v0_2->unk0 = 0x0000009E;
        var_a1 += 1;
        temp_v0_2->unk4 = 0x0D0C9005;
        temp_v0_2->unk8 = 0;
        temp_v0_2->unk8 = 0;
        temp_v0_2->unkC = temp_a0;
        temp_v0_2->unk0 = (s32) (0x9E & ~0x14);
        temp_v0_2->unk30 = (unaligned s32) D_800CC874;
        temp_v0_2->unk2C = (unaligned s32) temp_v0_2->unk30;
        temp_v0_2->unk28 = (unaligned s32) temp_v0_2->unk2C;
        temp_v0_2->unk24 = (unaligned s32) temp_v0_2->unk28;
        var_a2 += 0x34;
        if (var_a1 < 2U) {
            goto loop_2;
        }
        var_s2 += 0x1B8;
        var_s4 += 1;
        var_s3 += 0x18;
    } while (var_s4 < 0xEU);
    return temp_v0;
}
