struct _m2c_stack_func_800BD274 {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ s32 sp18[];                          /* inferred */
    /* 0x18 */ char pad18[0x68];
};                                                  /* size = 0x80 */

? func_80061C74(?, s32, ?);                         /* extern */
? func_80061F34(?, s32, ?);                         /* extern */
void *func_80063C3C(?, s32);                        /* extern */
? func_80063CFC(?, s8 *, s32, s16, s32);            /* extern */
? func_80063E2C(?, ?, ?);                           /* extern */
? func_80063E54(?, s32, ? *);                       /* extern */
extern f32 D_800A6C80;
extern ? D_800CC874;
extern ? D_800CD71C;
extern ? func_800CC9B8;

void func_800BD274(s8 *arg0, s32 arg1) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv1;
    s16 temp_v1_2;
    s16 var_s4;
    s32 *temp_s2;
    s32 *var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s2_2;
    s32 temp_s4;
    s32 temp_s7;
    s32 var_s0;
    s32 var_s3;
    s32 var_v1_3;
    s8 *temp_a1_2;
    s8 *temp_s1;
    s8 *temp_s6;
    s8 *var_a0;
    s8 *var_s2;
    u16 *var_s5;
    u16 temp_t0;
    u16 var_v1_2;
    u32 var_a2;
    u32 var_a2_2;
    u32 var_s1;
    u32 var_s1_2;
    u32 var_s1_3;
    void *temp_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *var_a1;

    var_a0 = arg0;
    temp_s6 = var_a0;
    var_s1 = 0;
    var_v1 = &sp18[0];
    temp_s7 = *(((arg1 & 0xFF) * 4) + (&func_800CC9B8 + 0x20));
    do {
        *var_v1 = 0;
        *var_a0 = 0;
        var_a0 += 0x1B8;
        var_s1 += 1;
        var_v1 += 4;
    } while (var_s1 < 0xEU);
    func_80063E2C(1, 0, 0);
    var_s5 = &func_800CC9B8 + 0x30;
loop_3:
    temp_t0 = *var_s5;
    temp_a0 = temp_t0 & 0xFFFF;
    var_s5 += 2;
    if (temp_a0 != 0xFFFF) {
        var_v1_2 = 0xFFFF;
        var_a2 = 0;
        var_a1 = &func_800CC9B8 + 0x78;
loop_5:
        var_a2 += 1;
        if (var_a1->unk4 != *((temp_a0 * 2) + temp_s7)) {
            var_a1 += 8;
            if (var_a2 >= 0xEU) {
                var_s3 = temp_t0 & 0xFFFF;
            } else {
                goto loop_5;
            }
        } else {
            var_v1_2 = var_a1->unk2;
            var_s3 = temp_t0 & 0xFFFF;
        }
        temp_a1 = var_v1_2 & 0xFFFF;
        temp_s2 = &(&sp18[0])[temp_a1];
        temp_s4 = 1 << var_s3;
        if (!(temp_s4 & *temp_s2)) {
            temp_s1 = temp_s6 + (temp_a1 * 0x1B8);
            var_s0 = strlen(temp_s1);
            if (var_s0 != 0) {
                temp_s1[var_s0] = 0x2F;
                var_s0 += 1;
            }
            rs_strcpy((u8 *) &temp_s1[var_s0], getGameOrFrontText((s32) *((var_s3 * 2) + (&func_800CC9B8 + 0x54))));
            temp_a0_2 = *temp_s2 | temp_s4;
            *temp_s2 = temp_a0_2;
            if ((0xE00 >> var_s3) & 1) {
                *temp_s2 = temp_a0_2 | 0xE00;
            }
        }
        goto loop_3;
    }
    var_s1_2 = 0;
    temp_fs0 = D_800A6C80;
    var_s2 = temp_s6;
    do {
        temp_a1_2 = var_s2;
        temp_s0 = var_s1_2 & 0xFFFF;
        temp_a2 = temp_s0;
        temp_fv1 = var_s2->unk30;
        temp_fv0 = var_s2->unk34 + temp_fs0;
        var_s2 += 0x1B8;
        var_s1_2 += 1;
        func_80063CFC(8, temp_a1_2, temp_a2, (s16) (s32) temp_fv1, (s32) (s16) (s32) temp_fv0);
        func_80063E54(8, temp_s0, &D_800CC874);
        func_80061C74(8, temp_s0, 0);
        func_80061F34(8, temp_s0, 0x3F800000);
    } while (var_s1_2 < 0xEU);
    var_s4 = 0;
    temp_s3 = func_80063C3C(8, 0);
    var_s1_3 = 0;
    temp_v0 = &D_800CD71C + 0x1414;
    do {
        temp_v0_2 = func_80063C3C(8, var_s1_3 & 0xFFFF);
        temp_s2_2 = var_s4 & 0xFFFF;
        zmemcpy((temp_s2_2 * 2) + (&D_800CD71C + 0x1214), temp_v0_2->unkC, temp_v0_2->unk8 * 2);
        zmemcpy((temp_s2_2 * 4) + temp_v0, temp_v0_2->unk10, temp_v0_2->unk8 * 4);
        if (var_s1_3 != 0) {
            var_a2_2 = 0;
            if (temp_v0_2->unk8 != 0) {
                var_v1_3 = temp_s2_2;
                do {
                    temp_v1 = (var_v1_3 * 4) + temp_v0;
                    temp_v1->unk0 = (s16) (s32) ((f32) temp_v1->unk0 + (temp_v0_2->unk18 - temp_s3->unk18));
                    temp_v1->unk2 = (s16) (s32) ((f32) temp_v1->unk2 + (temp_v0_2->unk1C - temp_s3->unk1C));
                    var_a2_2 += 1;
                    var_v1_3 = temp_s2_2 + var_a2_2;
                } while (var_a2_2 < (u16) temp_v0_2->unk8);
            }
        }
        var_s1_3 += 1;
        temp_v1_2 = var_s4 + temp_v0_2->unk8;
        var_s4 = temp_v1_2;
    } while (var_s1_3 < 0xEU);
    temp_s3->unkC = (void *) (&D_800CD71C + 0x1214);
    temp_s3->unk10 = (void *) (&D_800CD71C + 0x1414);
    temp_s3->unk8 = temp_v1_2;
    func_80063E2C(2, 0x200, 0);
}
