struct _m2c_stack_func_800BEA00 {
    /* 0x000 */ char pad0[0x18];
    /* 0x018 */ s8 sp18;                            /* inferred */
    /* 0x019 */ char pad19[0x7F];                   /* maybe part of sp18[0x80]? */
    /* 0x098 */ s8 sp98;                            /* inferred */
    /* 0x099 */ char pad99[0x2F];                   /* maybe part of sp98[0x30]? */
    /* 0x0C8 */ s8 spC8;                            /* inferred */
    /* 0x0C9 */ char padC9[0x2F];                   /* maybe part of spC8[0x30]? */
    /* 0x0F8 */ s8 spF8;                            /* inferred */
    /* 0x0F9 */ char padF9[0x2F];                   /* maybe part of spF8[0x30]? */
    /* 0x128 */ u16 sp128;                          /* inferred */
    /* 0x12A */ char pad12A[2];
    /* 0x12C */ ? sp12C;                            /* inferred */
    /* 0x12C */ char pad12C[4];
    /* 0x130 */ ? sp130;                            /* inferred */
    /* 0x130 */ char pad130[8];
    /* 0x138 */ u16 sp138[];                        /* inferred */
    /* 0x138 */ char pad138[4];
    /* 0x13C */ ? sp13C;                            /* inferred */
    /* 0x13C */ char pad13C[4];
    /* 0x140 */ s8 sp140;                           /* inferred */
    /* 0x141 */ s8 sp141;                           /* inferred */
    /* 0x142 */ s8 sp142;                           /* inferred */
    /* 0x143 */ char pad143[5];                     /* maybe part of sp142[6]? */
    /* 0x148 */ u8 sp148;                           /* inferred */
    /* 0x149 */ u8 sp149;                           /* inferred */
    /* 0x14A */ u8 sp14A;                           /* inferred */
    /* 0x14B */ s8 sp14B;                           /* inferred */
    /* 0x14C */ char pad14C[0x54];
};                                                  /* size = 0x1A0 */

? func_80061C74(?, s32, ?);                         /* extern */
? func_80061F34(?, s32, ?);                         /* extern */
void *func_80063C3C(?, s32);                        /* extern */
? func_80063CFC(?, u8 *, s32, s16, s32);            /* extern */
? func_80063E2C(?, ?, ?);                           /* extern */
? func_80063E54(?, s32, s8 *);                      /* extern */
? func_80063E98(?, u16 *, ?);                       /* extern */
? func_80063EC0(?);                                 /* extern */
? func_800646AC(s32, void *, s32);                  /* extern */
? func_800646F8(s32, void *, ?);                    /* extern */
f32 func_800662E0(f32);                             /* extern */
s32 func_80079F50(s32);                             /* extern */
? func_80087EE8(?, ?, ?);                           /* extern */
f32 sinf(f32, f32 *);                               /* extern */
? sprintf(s8 *, ? *, s8 *, s8 *);                   /* extern */
void *func_800B3D08(s32);                           /* static */
extern ? D_800A6DC0;
extern ? D_800A6DCC;
extern ? D_800A6DD4;
extern ? D_800A6DE4;
extern ? D_800A6DE8;
extern ? D_800A6DF0;
extern u8 D_800A6DF8;
extern f32 D_800A6E24;
extern f32 D_800A6E28;
extern f32 D_800A6E2C;
extern f32 D_800A6E30;
extern f32 D_800A6E34;
extern f32 D_800A6E38;
extern f32 D_800A6E3C;
extern f32 D_800A6E40;
extern f32 D_800A6E44;
extern f32 D_800A6E48;
extern f32 D_800A6E4C;
extern f32 D_800A6E50;
extern f32 D_800A6E54;
extern f32 D_800A6E58;
extern f32 D_800A6E5C;
extern f32 D_800A6E60;
extern f32 D_800A6E64;
extern f32 D_800A6E68;
extern f32 D_800A6E6C;
extern f32 D_800A6E70;
extern f32 D_800A6E74;
extern f32 D_800A6E78;
extern f32 D_800A6E7C;
extern f32 D_800A6E80;
extern f32 D_800A6E84;
extern f32 D_800A6E88;
extern f32 D_800A6E8C;
extern f32 D_800A6E90;
extern f32 D_800A6E94;
extern f32 D_800A6E98;
extern f32 D_800A6E9C;
extern s8 D_800CC874;
extern s8 D_800CC87C;
extern f32 D_800CF074;
extern s32 D_800CF078;
extern s32 D_800CF080;
extern ? D_800CF09C;
extern ? func_800CC2AC;
extern ? func_800CF20C;

void func_800BEA00(s32 arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4) {
    s8 sp18;
    s8 sp98;
    s8 spC8;
    s8 spF8;
    u16 sp128;
    ? sp12C;
    ? sp130;
    ? sp13C;
    s8 sp140;
    s8 sp141;
    s8 sp142;
    u8 sp148;
    u8 sp149;
    u8 sp14A;
    s8 sp14B;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs2;
    f32 temp_ft1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 var_fs0;
    f32 var_fs3;
    f32 var_fv0;
    s16 var_v0;
    s32 temp_a0_3;
    s32 temp_a2;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s1_2;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_a0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *temp_s1;
    s8 temp_a0_4;
    s8 temp_v0;
    s8 temp_v0_11;
    s8 temp_v0_12;
    s8 temp_v0_13;
    s8 temp_v0_14;
    s8 temp_v0_2;
    s8 temp_v0_3;
    s8 temp_v0_4;
    s8 temp_v0_5;
    s8 var_s1_2;
    s8 var_s2;
    s8 var_s2_2;
    s8 var_s2_3;
    s8 var_s2_4;
    s8 var_s2_5;
    s8 var_s2_6;
    s8 var_s3;
    s8 var_s3_2;
    s8 var_s4;
    u16 temp_a0_2;
    u16 temp_v1_3;
    u32 var_s1;
    u8 temp_v1;
    u8 var_v0_2;
    void *temp_a1;
    void *temp_s0;
    void *temp_s0_4;
    void *temp_s0_8;
    void *temp_s3;
    void *temp_v0_10;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_4;

    sp128 = (unaligned s32) D_800A6DC0.unk0;
    sp12C = (unaligned s32) D_800A6DC0.unk4;
    sp130 = (unaligned s32) D_800A6DC0.unk8;
    sp138[0] = (unaligned s32) D_800A6DCC.unk0;
    sp13C = (unaligned s32) D_800A6DCC.unk4;
    var_fs3 = 0.0f;
    // For me, arg1 is ROM address 0x800CEF40. No idea if this will be consistent or not.
    // byte 0 appears to be something like "menu state"
    // byte 1 appears to be the rank index to start at
    // byte 2 is ???
    // byte 3 is ???
    // then there's a float, seems like a counter for when to swap between the 2 rank screens (its a floating point value and it counts up)
    // then there's a bunch more floats, not sure what they're for
    temp_v1 = arg1->unk0;
    if (temp_v1 != 1) {
        if ((s32) temp_v1 < 2) {
            var_s2 = 0;
            if (temp_v1 != 0) {

            } else {
                func_80063E98(0xB, &sp128, 5);
                func_80063E98(5, &sp128, 5);
                func_80063E2C(1, 0, 0);
                temp_a0 = &func_800CF20C + 0x54;
                sp18 = 0;
                *temp_a0 = 0;
                spF8 = 0;
                spC8 = 0;
                sp98 = 0;
                var_s4 = arg1->unk1;
                var_s3 = 0;
                if (1 != 0) {
                    do {
                        temp_s0 = (var_s4 * 8) + arg0;
                        temp_a0_2 = temp_s0->unk4;
                        // Calculate the account's score
                        // Gold medals are 4 points, Silvers are 2, and Bronzes are 1
                        // Divide the score by 4 to get the rank
                        var_s1 = (u32) ((temp_s0->unk5 & 0x1F) + ((temp_a0_2 >> 4) & 0x3E) + ((temp_a0_2 >> 8) & 0x7C)) >> 2;
                        // If somehow we're above max rank, clip the value
                        if (var_s1 >= 0x10U) {
                            var_s1 = 0x0000000F;
                        }
                        temp_s0_2 = &temp_a0[strlen(temp_a0)];
                        // Get the name of the level the account is on
                        temp_s1 = getGameOrFrontText((s32) temp_s0->unk3);
                        sprintf(temp_s0_2, &D_800A6DD4, temp_s1, getGameOrFrontText(var_s1 + 0x92) + 1);
                        temp_a0[strlen(temp_a0)].unk-1 = 0;
                        sprintf(&temp_a0[strlen(temp_a0)], &D_800A6DE4);
                        temp_s0_3 = &(&sp18)[strlen(&sp18)];
                        // choosing between "st", "nd", "rd", and "th"
                        if (var_s4 == 0) {
                            var_a0 = 0x000000BF; // "st"
                        } else if (var_s4 == 1) {
                            var_a0 = 0x000000C0; // "nd"
                        } else {
                            var_a0 = 0x000000C2; // "th"
                            if (var_s4 == 2) {
                                var_a0 = 0x000000C1; // "rd"
                            }
                        }
                        // Ranking as string (so stuff like "1st" or "5th")
                        sprintf(temp_s0_3, &D_800A6DE8, var_s4 + 1, getGameOrFrontText(var_a0));
                        temp_s0_4 = (var_s4 * 8) + arg0;
                        // Get the medal counts
                        // Gold medals
                        sprintf(&(&sp98)[strlen(&sp98)], &D_800A6DF0, (s8 *) (((u16) temp_s0_4->unk4 >> 0xA) & 0x1F));
                        // Silvers
                        sprintf(&(&sp98)[strlen(&spC8)].unk30, &D_800A6DF0, (s8 *) (((u16) temp_s0_4->unk4 >> 5) & 0x1F));
                        // Bronzes
                        sprintf(&(&sp98)[strlen(&spF8)].unk60, &D_800A6DF0, (s8 *) (temp_s0_4->unk4 & 0x1F));
                        temp_v1_2 = var_s3 << 0x18;
                        temp_a2 = (var_s3 + 1) & 0xFFFF;
                        // Getting the name of the account
                        // Character 1
                        sp148 = temp_s0_4->unk0;
                        var_s3 += 1;
                        // Character 2
                        sp149 = temp_s0_4->unk1;
                        sp14B = 0;
                        // Character 3
                        sp14A = temp_s0_4->unk2;
                        func_80063CFC(5, &sp148, temp_a2, -0x00B4, ((temp_v1_2 >> 0x18) * 0x33) - 0x6E);
                        temp_v0 = var_s4 + 1;
                        var_s4 = temp_v0;
                    } while (temp_v0 < (arg1->unk1 + 5));
                }
                func_80063CFC(0xB, &func_800CF20C + 0x54, 1, -0x00DC, -0x0000006E);
                func_80063CFC(0xB, (u8 *) &sp18, 2, -0x00D1, -0x00000066);
                func_80063E2C(2, 0x200, 0);
                var_s2_2 = 0;
                var_a0_2 = 0 << 0x18;
                do {
                    temp_a0_3 = var_a0_2 >> 0x18;
                    temp_v1_3 = (&sp138[0])[temp_a0_3];
                    var_v0 = temp_v1_3 - 0x1C5;
                    if (temp_a0_3 == 2) {
                        var_v0 = temp_v1_3 - 0x1C4;
                    }
                    func_80063CFC(0xB, &sp98 + (temp_a0_3 * 0x30), (temp_a0_3 + 3) & 0xFFFF, var_v0, -0x00000066);
                    temp_v0_2 = var_s2_2 + 1;
                    var_s2_2 = temp_v0_2;
                    var_a0_2 = var_s2_2 << 0x18;
                } while (temp_v0_2 < 3);
                func_80063E2C(1, 0, 0);
                var_s3_2 = 0;
                var_s0 = 0 << 0x18;
                do {
                    func_80061F34(5, ((var_s0 >> 0x18) + 1) & 0xFFFF, 0x3F35C28F);
                    func_80063E54(5, ((var_s0 >> 0x18) + 1) & 0xFFFF, &D_800CC87C);
                    temp_v0_3 = var_s3_2 + 1;
                    var_s3_2 = temp_v0_3;
                    var_s0 = var_s3_2 << 0x18;
                } while (temp_v0_3 < 5);
                var_s2_3 = 1;
                var_s0_2 = 1 << 0x18;
                do {
                    func_80063E54(0xB, (var_s0_2 >> 0x18) & 0xFFFF, &D_800CC874);
                    func_80061F34(0xB, (var_s0_2 >> 0x18) & 0xFFFF, 0x3F800000);
                    temp_v0_4 = var_s2_3 + 1;
                    var_s2_3 = temp_v0_4;
                    var_s0_2 = var_s2_3 << 0x18;
                } while (temp_v0_4 < 6);
                func_80063E98(8, &sp138[0], 7);
                func_80063CFC(8, &D_800A6DF8, 1, -0x00C4, -0x0000005E);
                var_s2_4 = 0;
                func_800646F8(D_800CF078, func_80063C3C(8, 1), 0x19);
                func_80063E54(8, 1, &func_800CC2AC + 0x5CC);
                func_80061F34(8, 1, 0x3F800000);
                func_80063E2C(2, 0x200, 0);
                func_80063EC0(0xB);
                func_80063EC0(8);
                func_80063EC0(5);
                var_s0_3 = 0 << 0x18;
                do {
                    temp_v0_6 = func_80063C3C(0xB, ((var_s0_3 >> 0x18) + 1) & 0xFFFF);
                    temp_s0_5 = var_s0_3 >> 0x18;
                    temp_v1_4 = arg1 + (temp_s0_5 * 4);
                    temp_s1_2 = (temp_s0_5 + 1) & 0xFFFF;
                    temp_v1_4->unk8 = (f32) temp_v0_6->unk18;
                    temp_v1_4->unk58 = (f32) temp_v0_6->unk1C;
                    temp_v0_7 = func_80063C3C(5, temp_s1_2);
                    temp_v0_8 = arg1 + ((temp_s0_5 + 5) * 4);
                    temp_v0_8->unk8 = (f32) temp_v0_7->unk18;
                    temp_v0_8->unk58 = (f32) temp_v0_7->unk1C;
                    if (temp_s0_5 <= 0) {
                        temp_v0_9 = func_80063C3C(8, temp_s1_2);
                        temp_v0_10 = arg1 + ((temp_s0_5 + 0xA) * 4);
                        temp_v0_10->unk8 = (f32) temp_v0_9->unk18;
                        temp_v0_10->unk58 = (f32) temp_v0_9->unk1C;
                    }
                    temp_v0_5 = var_s2_4 + 1;
                    var_s2_4 = temp_v0_5;
                    var_s0_3 = var_s2_4 << 0x18;
                } while (temp_v0_5 < 5);
                arg1->unk0 = 1U;
                goto block_31;
            }
        } else if (temp_v1 != 2) {
            var_s2 = 0;
            if (temp_v1 != 3) {

            } else {
                // I think this stuff is handling the timer for the screen
                temp_fv1 = arg1->unk4 + (arg3 * D_800A6E40);
                arg1->unk4 = temp_fv1;
                if (D_800A6E44 < temp_fv1) {
                    arg1->unk4 = (f32) D_800A6E44;
                }
                temp_fv0 = arg1->unk4;
                var_fs3 = (D_800A6E44 - temp_fv0) * D_800A6E48;
                var_s2 = 0;
                if (temp_fv0 == D_800A6E44) {
                    temp_v0_11 = (u8) arg1->unk1 + (arg1->unk2 * 5);
                    arg1->unk1 = temp_v0_11;
                    if (temp_v0_11 >= 0xA) {
                        arg1->unk1 = 0;
                    }
                    if (arg1->unk1 < 0) {
                        arg1->unk1 = 5;
                    }
                    arg1->unk4 = 0.0f;
                    arg1->unk0 = 0U;
                    goto block_50;
                }
            }
        } else {
            var_s1_2 = 1;
            temp_s0_6 = arg2 & 0xFF;
            var_fs3 = D_800A6E30;
            arg1->unk4 = (f32) (arg1->unk4 + arg3);
            if (func_80079F50(temp_s0_6) & 0xA00A00) {
                var_s1_2 = -1;
                arg1->unk4 = (f32) D_800A6E34;
            }
            if (func_80079F50(temp_s0_6) & 0x500500) {
                arg1->unk4 = (f32) D_800A6E38;
            }
            if (D_800A6E3C <= arg1->unk4) {
                func_80087EE8(0x7B, 0x3C, 0x40);
                var_v0_2 = 3;
                arg1->unk2 = var_s1_2;
                arg1->unk4 = 0.0f;
                goto block_41;
            }
            goto block_50;
        }
    } else {
block_31:
        temp_fv1_2 = arg1->unk4 + (arg3 * D_800A6E24);
        arg1->unk4 = temp_fv1_2;
        if (D_800A6E28 < temp_fv1_2) {
            arg1->unk4 = (f32) D_800A6E28;
        }
        temp_fv1_3 = arg1->unk4;
        var_fs3 = temp_fv1_3 * D_800A6E2C;
        var_v0_2 = 2;
        if (temp_fv1_3 == D_800A6E28) {
            arg1->unk4 = 0.0f;
block_41:
            arg1->unk0 = var_v0_2;
        }
block_50:
        var_s2 = 0;
    }
    var_a1 = 0 << 0x18;
    do {
        func_800646AC(D_800CF080, func_80063C3C(0xB, (var_a1 >> 0x18) & 0xFFFF), 0);
        temp_v0_12 = var_s2 + 1;
        var_s2 = temp_v0_12;
        var_a1 = var_s2 << 0x18;
    } while (temp_v0_12 < 8);
    var_s2_5 = 0;
    temp_fs1 = (var_fs3 * arg4) / D_800A6E4C;
    do {
        var_fs0 = func_800662E0(D_800A6E50 - temp_fs1) * D_800A6E54;
        if (arg1->unk0 == 3) {
            var_fs0 = -var_fs0;
        }
        func_80061C74(0xB, (var_s2_5 + 1) & 0xFFFF, 0xFF);
        temp_a1 = func_80063C3C(0xB, (var_s2_5 + 1) & 0xFFFF);
        temp_fv1_4 = (arg1 + (var_s2_5 * 4))->unk58;
        if (var_s2_5 >= 2) {
            var_fv0 = temp_fv1_4 + var_fs0;
        } else {
            var_fv0 = temp_fv1_4 + -var_fs0;
        }
        temp_a1->unk1C = var_fv0;
        func_80061C74(5, (var_s2_5 + 1) & 0xFFFF, 0xFE);
        func_80063C3C(5, (var_s2_5 + 1) & 0xFFFF)->unk1C = (f32) ((arg1 + ((var_s2_5 + 5) * 4))->unk58 + var_fs0);
        if (var_s2_5 <= 0) {
            temp_s0_7 = (var_s2_5 + 1) & 0xFFFF;
            func_80061C74(8, temp_s0_7, 0xFE);
            func_80063C3C(8, temp_s0_7)->unk1C = (f32) ((arg1 + ((var_s2_5 + 0xA) * 4))->unk58 + var_fs0);
        }
        temp_v0_13 = var_s2_5 + 1;
        var_s2_5 = temp_v0_13;
    } while (temp_v0_13 < 5);
    var_s2_6 = 0;
    temp_s3 = &func_800CC2AC + 0x5D4;
    temp_fs2 = D_800A6E58;
    temp_fs1_2 = D_800A6E5C;
    temp_fs0 = D_800A6E60;
    // Speculatively, this is handling the white->yellow->white highlighting going on with the names
    // It iterates over 5 items (5 entires per screen) and is doing a sine wave for something, which makes sense with how the color shifting occurs
    do {
        temp_fv0_2 = func_800662E0((sinf((D_800CF074 / D_800A6E68) + (((f32) (4 - var_s2_6) * D_800A6E64) / D_800A6E6C), &D_800CF074) * temp_fs2) + temp_fs2);
        temp_ft1 = D_800A6E70 - temp_fv0_2;
        temp_fv0_3 = ((f32) temp_s3->unk0 * temp_fv0_2) + (temp_ft1 * temp_fs1_2);
        if (temp_fs0 <= temp_fv0_3) {
            var_v1 = (s32) (temp_fv0_3 - temp_fs0) | 0x80000000;
        } else {
            var_v1 = (s32) temp_fv0_3;
        }
        temp_fv0_4 = ((f32) temp_s3->unk1 * temp_fv0_2) + (temp_ft1 * temp_fs1_2);
        sp140 = (s8) var_v1;
        if (!(temp_fs0 <= temp_fv0_4)) {
            var_v1_2 = (s32) temp_fv0_4;
        } else {
            var_v1_2 = (s32) (temp_fv0_4 - temp_fs0) | 0x80000000;
        }
        temp_fv0_5 = ((f32) temp_s3->unk2 * temp_fv0_2) + (temp_ft1 * temp_fs1_2);
        sp141 = (s8) var_v1_2;
        if (!(temp_fs0 <= temp_fv0_5)) {
            sp142 = (s8) (s32) temp_fv0_5;
        } else {
            sp142 = (s32) (temp_fv0_5 - temp_fs0) | 0x80000000;
        }
        func_80063E54(5, (var_s2_6 + 1) & 0xFFFF, &sp140);
        temp_v0_14 = var_s2_6 + 1;
        var_s2_6 = temp_v0_14;
    } while (temp_v0_14 < 5);
    if (D_80130B40.unk24 != 0) {
        temp_s0_8 = func_800B3D08(*(&D_800CF09C + 0x78));
        temp_a0_4 = arg1->unk1;
        temp_v1_5 = D_80130B40.unk24 - 1;
        if ((temp_v1_5 >= temp_a0_4) && (temp_v1_5 < (temp_a0_4 + 5))) {
            temp_s0_8->unk14 = (s32) (temp_s0_8->unk14 | 3);
            temp_s0_8->unk2C = (unaligned s32) *(&func_800CC2AC + 0x5EC);
            temp_s0_8->unk24 = (f32) D_800A6E74;
            temp_s0_8->unk28 = (f32) D_800A6E7C;
            temp_s0_8->unk18 = (f32) (D_800A6E74 * D_800A6E78);
            temp_s0_8->unk1C = (f32) (((D_800A6E7C * D_800A6E80) - D_800A6E88) + ((f32) ((D_80130B40.unk24 - arg1->unk1) - 1) * D_800A6E84));
            temp_fv0_6 = ((((sinf(D_800CF074 / D_800A6E8C, (f32 *) temp_a0_4) * D_800A6E90) + D_800A6E94) * var_fs3) / D_800A6E98) * arg4;
            if (D_800A6E9C <= temp_fv0_6) {
                var_a2 = (s32) (temp_fv0_6 - D_800A6E9C) | 0x80000000;
            } else {
                var_a2 = (s32) temp_fv0_6;
            }
            temp_s0_8->unk2F = (s8) var_a2;
            var_a0_3 = D_800CF078;
            var_a2_2 = (var_a2 & 0xFF) != 0;
        } else {
            var_a0_3 = D_800CF078;
            var_a2_2 = 0;
        }
        func_800646AC(var_a0_3, temp_s0_8, var_a2_2);
    }
}
