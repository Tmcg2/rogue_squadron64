struct _m2c_stack_load_level_hmp {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ ? sp18;                              /* inferred */
    /* 0x18 */ char pad18[0x28];
    /* 0x40 */ f32 sp40;                            /* inferred */
    /* 0x44 */ f32 sp44;                            /* inferred */
    /* 0x48 */ f32 sp48;                            /* inferred */
    /* 0x4C */ char pad4C[4];
    /* 0x50 */ s32 sp50;                            /* inferred */
    /* 0x54 */ void *sp54;                          /* inferred */
    /* 0x58 */ char pad58[0x30];
};                                                  /* size = 0x88 */

s32 func_80004AAC(s32, ?, s32, ? *, s32);           /* extern */
? func_80004C70(s32, s32);                          /* extern */
s32 get_asset_size_extra(s32, ? *);                        /* extern */
? func_80004E70(s32, ?, s32, ?, s32, void *);       /* extern */
? func_8001CF58(f32 *, u8, void *);                 /* extern */
s32 func_8006B694();                                /* extern */
? sprintf(? *, ? *, ?);                             /* extern */
? func_80041EF0(s32);                               /* static */
? func_80046310(u16);                               /* static */
s32 func_8004B1E4(void *, ?, void *);               /* static */
extern ? D_80130B40;
extern u16 D_80130C4C;
extern ? D_80136DC0;
extern ? D_80136E20;
extern ? D_80136FB0;
extern void *D_80136FC4;
extern s32 D_80137CFC;
extern s32 D_80138920;
extern ? *D_80138D24;

s32 load_level_hmp(s32 arg0, ? arg1) {
    void *sp54;
    s32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    ? sp18;
    f32 temp_ft0;
    f32 temp_ft1;
    s32 *temp_a0_6;
    s32 temp_v0;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_18;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_8;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s2_5;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_5;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_t0;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t7;
    s32 var_v0;
    s8 temp_a0;
    s8 temp_a0_2;
    s8 temp_a0_3;
    s8 temp_a0_4;
    s8 temp_v0_3;
    s8 temp_v0_5;
    s8 temp_v0_7;
    s8 temp_v0_9;
    u16 *temp_a1;
    u16 temp_a0_5;
    u16 temp_s7;
    u16 temp_v0_10;
    u8 temp_a1_2;
    void *temp_a0_7;
    void *temp_t5;
    void *temp_v0_14;
    void *temp_v0_15;
    void *temp_v0_16;
    void *temp_v0_17;
    void *temp_v0_19;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v0_8;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *var_s1;

    sprintf(&sp18, "%s/hmp", arg1);
    temp_v0 = get_asset_size_extra(D_80137CFC, &sp18);
    D_80136FC4 = rs_malloc(temp_v0, 0U);
    temp_v0_2 = func_80004AAC(D_80138920, 0, D_80137CFC, &sp18, 0);
    func_80004E70(D_80138920, 0, temp_v0_2, 0, temp_v0, D_80136FC4);
    func_80004C70(D_80138920, temp_v0_2);
    // lighting offset -> pointer
    D_80136FC4->unk20 = (s32 *) (D_80136FC4->unk20 + D_80136FC4);
    // tile offset -> pointer
    D_80136FC4->unk1C = (void *) (D_80136FC4->unk1C + D_80136FC4);
    // tile index array start (u16*)
    D_80136DC0.unk0 = (void *) (D_80136FC4 + 0x28);
    D_80136DC0.unk4 = (void *) D_80136FC4->unk1C;
    // tile count
    temp_s7 = D_80136FC4->unk18;
    var_s3 = 0;
    /**
     * Go through the each height in the inner 3x3 of the 5x5 height array and compare it to its orthoganal neighbors
     *  X 
     * X.X
     *  X 
     * For each neighbor, get the absolute difference of the heights and add it to a running total
     * If the total difference is less than 20, a flag is set in byte 2 of this tile 
     **/
    if (temp_s7 != 0) {
        var_t7 = 0;
        do {
            var_s2 = 0;
            var_s4 = 1;
            var_t4 = 0xA;
            var_t3 = 0;
            var_t2 = 6;
            var_t1 = 4;
            var_t0 = 5;
            // temp_t5 is now a tile pointer
            temp_t5 = var_t7 + D_80136DC0.unk4;
loop_3:
            var_a1 = 1;
            var_a2 = var_t0 + 1;
loop_4:
            temp_a0 = (temp_t5 + var_a2)->unk5;
            temp_v0_3 = (temp_t5 + (var_a1 + var_t1))->unk5;
            temp_v1 = temp_a0 - temp_v0_3;
            if (temp_v1 >= 0) {
                var_s2_2 = var_s2 + temp_v1;
            } else {
                var_s2_2 = var_s2 + (temp_v0_3 - temp_a0);
            }
            temp_v0_4 = var_t7 + D_80136DC0.unk4;
            temp_a0_2 = (temp_v0_4 + var_a2)->unk5;
            temp_v0_5 = (temp_v0_4 + (var_a1 + var_t2))->unk5;
            temp_v1_2 = temp_a0_2 - temp_v0_5;
            if (temp_v1_2 >= 0) {
                var_s2_3 = var_s2_2 + temp_v1_2;
            } else {
                var_s2_3 = var_s2_2 + (temp_v0_5 - temp_a0_2);
            }
            temp_v0_6 = var_t7 + D_80136DC0.unk4;
            temp_a0_3 = (temp_v0_6 + var_a2)->unk5;
            temp_v0_7 = (temp_v0_6 + (var_a1 + var_t3))->unk5;
            temp_v1_3 = temp_a0_3 - temp_v0_7;
            if (temp_v1_3 >= 0) {
                var_s2_4 = var_s2_3 + temp_v1_3;
            } else {
                var_s2_4 = var_s2_3 + (temp_v0_7 - temp_a0_3);
            }
            temp_v0_8 = var_t7 + D_80136DC0.unk4;
            temp_a0_4 = (temp_v0_8 + var_a2)->unk5;
            temp_v0_9 = (temp_v0_8 + (var_a1 + var_t4))->unk5;
            temp_v1_4 = temp_a0_4 - temp_v0_9;
            if (temp_v1_4 >= 0) {
                var_s2 = var_s2_4 + temp_v1_4;
            } else {
                var_s2 = var_s2_4 + (temp_v0_9 - temp_a0_4);
            }
            var_a1 += 1;
            var_a2 += 1;
            if (var_a1 < 4) {
                goto loop_4;
            }
            var_t4 += 5;
            var_t3 += 5;
            var_t2 += 5;
            var_t1 += 5;
            var_s4 += 1;
            var_t0 += 5;
            if (var_s4 < 4) {
                goto loop_3;
            }
            var_s3 += 1;
            if (var_s2 < 0x14) {
                temp_v1_5 = var_t7 + D_80136DC0.unk4;
                temp_v1_5->unk2 = (u8) (temp_v1_5->unk2 | 1);
            }
            var_t7 += 0x1E;
        } while (var_s3 < (s32) temp_s7);
    }
    temp_ft1 = D_80136FC4->unk0;
    D_80136DC0.unk20 = temp_ft1;
    D_80136DC0.unk24 = (f32) (temp_ft1 + (2.0f * (f32) D_80136FC4->unk24));
    temp_ft0 = D_80136FC4->unk8;
    D_80136DC0.unk2C = temp_ft0;
    D_80136DC0.unk30 = (f32) (temp_ft0 + (2.0f * (f32) D_80136FC4->unk26));
    D_80136DC0.unk28 = (f32) (2.0f * (f32) D_80136FC4->unk24);
    D_80136DC0.unk34 = (f32) (2.0f * (f32) D_80136FC4->unk26);
    D_80136DC0.unk38 = (u16) D_80136FC4->unk24;
    temp_v0_10 = D_80136FC4->unk26;
    D_80136DC0.unk3A = temp_v0_10;
    D_80136DC0.unk14 = temp_ft1;
    D_80136DC0.unk10 = (f32) (D_80136FC4->unk10 * 256.0f);
    D_80136DC0.unk1C = temp_ft0;
    D_80136DC0.unk18 = (f32) D_80136FC4->unk4;
    var_s3_2 = 0;
    D_80136DC0.unk8 = rs_malloc(D_80136DC0.unk38 * (temp_v0_10 & 0xFFFF) * 2, 0U);
    if ((D_80136DC0.unk38 * D_80136DC0.unk3A) > 0) {
        do {
            *((var_s3_2 * 2) + D_80136DC0.unk8) = 0xFFFF;
            var_s3_2 += 1;
        } while (var_s3_2 < (D_80136DC0.unk38 * D_80136DC0.unk3A));
    }
    // For each tile, if the height difference flag was set, set another flag in the tile index entry?
    var_s3_3 = 0;
    if ((D_80136DC0.unk38 * D_80136DC0.unk3A) > 0) {
        do {
            temp_a1 = (var_s3_3 * 2) + D_80136DC0.unk0;
            temp_a0_5 = *temp_a1;
            if ((((temp_a0_5 & 0x1FFF) * 0x1E) + D_80136DC0.unk4)->unk2 & 1) {
                *temp_a1 = temp_a0_5 | 0x8000;
            }
            var_s3_3 += 1;
        } while (var_s3_3 < (D_80136DC0.unk38 * D_80136DC0.unk3A));
    }
    sprintf(&sp18, "%s_TEX", arg1);
    temp_v0_11 = get_asset_size_extra(D_80137CFC, &sp18);
    D_80136DC0.unkC = rs_malloc(temp_v0_11, 0U);
    temp_v0_12 = func_80004AAC(D_80138920, 0, D_80137CFC, &sp18, 0);
    func_80004E70(D_80138920, 0, temp_v0_12, 0, temp_v0_11, D_80136DC0.unkC);
    func_80004C70(D_80138920, temp_v0_12);
    var_s3_4 = 0;
    if (D_80136FC4->unk1A != 0) {
        var_v0 = 0 * 4;
        do {
            *((var_v0 | 2) + D_80136DC0.unkC) = 0xFFFF;
            var_s3_4 += 1;
            var_v0 = var_s3_4 * 4;
        } while (var_s3_4 < (s32) D_80136FC4->unk1A);
    }
    var_s5 = 0;
    var_s4_2 = 0;
    sp50 = 0;
    func_80046310(D_80136FC4->unk1A);
loop_33:
    var_s3_5 = 0;
    if (*D_80136FC4->unk20 > 0) {
        var_s2_5 = 0xC;
        var_s0 = 0;
        sp54 = (var_s4_2 * 4) + &D_80136DC0;
        temp_v0_13 = var_s4_2 * 0x58;
        var_s1 = temp_v0_13 + &D_80136E20;
        var_s6 = temp_v0_13;
        var_s7 = var_s6 - 0x58;
        do {
            temp_a0_6 = D_80136FC4->unk20;
            temp_v1_6 = temp_a0_6 + var_s0;
            temp_a1_2 = temp_v1_6->unk18;
            if (temp_a1_2 == 0) {
                if (((temp_v1_6->unk1B == 0) || (D_80130B40.unk23 != 0)) && (var_s4_2 <= 0) && (var_s5 == 0)) {
                    func_8001CF58(temp_a0_6 + var_s2_5 + 0x10, temp_a1_2, D_80136FC4);
                    temp_v1_7 = D_80136FC4->unk20 + var_s0;
                    if (temp_v1_7->unk19 != 0) {
                        temp_v1_7->unkC = (f32) -temp_v1_7->unkC;
                        temp_v0_14 = D_80136FC4->unk20 + var_s0;
                        temp_v0_14->unk10 = (f32) -temp_v0_14->unk10;
                        temp_v0_15 = D_80136FC4->unk20 + var_s0;
                        temp_v0_15->unk14 = (f32) -temp_v0_15->unk14;
                    }
                    if (arg0 == 0) {
                        var_s1->unk0 = 0;
                        if (var_s4_2 == 0) {
                            D_80136E20.unk4 = 0;
                        } else {
                            var_s1->unk4 = (void *) (var_s6 + (&D_80136E20 - 0x58));
                            *(var_s7 + &D_80136E20) = var_s1;
                        }
                        var_s1->unk8 = 1;
                        var_s1->unk18 = (f32) (D_80136FC4->unk20 + var_s0)->unk1C;
                        var_s1->unk1C = (f32) (D_80136FC4->unk20 + var_s0)->unk20;
                        var_s1->unk20 = (f32) (D_80136FC4->unk20 + var_s0)->unk24;
                        sp40 = (D_80136FC4->unk20 + var_s0)->unkC / 255.0f;
                        sp44 = (D_80136FC4->unk20 + var_s0)->unk10 / 255.0f;
                        sp48 = (D_80136FC4->unk20 + var_s0)->unk14 / 255.0f;
                        func_8001CF58(&sp40);
                        var_s1->unk24 = sp40;
                        var_s1->unk28 = sp44;
                        var_s1->unk2C = sp48;
                    }
                    var_s1 += 0x58;
                    var_s6 += 0x58;
                    var_s7 += 0x58;
                    var_s4_2 += 1;
                    sp54->unk48 = (void *) (D_80136FC4->unk20 + var_s2_5);
                    sp54 += 4;
                }
            } else if (temp_a1_2 == 1) {
                if ((temp_v1_6->unk19 != 0) && (var_s5 == temp_a1_2)) {
                    temp_v1_6->unkC = (f32) -temp_v1_6->unkC;
                    temp_v0_16 = D_80136FC4->unk20 + var_s0;
                    temp_v0_16->unk10 = (f32) -temp_v0_16->unk10;
                    temp_v0_17 = D_80136FC4->unk20 + var_s0;
                    temp_v0_17->unk14 = (f32) -temp_v0_17->unk14;
                }
                if (var_s5 == 0) {
                    sp50 += func_8004B1E4(D_80136FC4->unk20 + var_s2_5, 0, D_80136FC4);
                } else {
                    func_8004B1E4(D_80136FC4->unk20 + var_s2_5, 1, D_80136FC4);
                }
            }
            var_s2_5 += 0x20;
            var_s3_5 += 1;
            var_s0 += 0x20;
        } while (var_s3_5 < *D_80136FC4->unk20);
    }
    if ((var_s5 != 0) || (func_80041EF0(sp50 + D_80130C4C + func_8006B694()), var_a1_2 = var_s4_2 < 4, (sp50 != 0))) {
        var_s5 += 1;
        var_a1_2 = var_s4_2 < 4;
        if (var_s5 < 2) {
            goto loop_33;
        }
    }
    if (var_a1_2 != 0) {
        ((var_s4_2 * 4) + &D_80136DC0)->unk48 = 0;
    }
    D_80136DC0.unk3C = (f32) D_80136FC4->unk20->unk4;
    D_80136DC0.unk40 = (f32) D_80136FC4->unk20->unk5;
    D_80136DC0.unk44 = (f32) D_80136FC4->unk20->unk6;
    D_80136FB0.unk0 = (f32) ((f32) D_80136FC4->unk20->unk8 / 255.0f);
    D_80136FB0.unk4 = (f32) ((f32) D_80136FC4->unk20->unk9 / 255.0f);
    D_80136FB0.unk8 = (f32) ((f32) D_80136FC4->unk20->unkA / 255.0f);
    if (arg0 == 0) {
        if (var_a1_2 != 0) {
            temp_v1_8 = var_s4_2 * 0x58;
            temp_a0_7 = temp_v1_8 + &D_80136E20;
            temp_a0_7->unk0 = 0;
            if (var_s4_2 == 0) {
                D_80136E20.unk4 = 0;
            } else {
                temp_a0_7->unk4 = (void *) (temp_v1_8 + (&D_80136E20 - 0x58));
                *(((var_s4_2 - 1) * 0x58) + &D_80136E20) = temp_a0_7;
            }
            temp_v0_18 = var_s4_2 * 0xB;
            var_s4_2 += 1;
            temp_v0_19 = (temp_v0_18 * 8) + &D_80136E20;
            temp_v0_19->unk8 = 0;
            temp_v0_19->unk24 = 0.5f;
            temp_v0_19->unk28 = 0.5f;
            temp_v0_19->unk2C = 0.5f;
        }
        if (var_s4_2 > 0) {
            D_80138D24 = &D_80136E20;
        }
    }
    return 1;
}
