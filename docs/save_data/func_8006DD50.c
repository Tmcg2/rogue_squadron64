struct _m2c_stack_func_8006DD50 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ u8 sp10;                             /* inferred */
    /* 0x11 */ u8 sp11;                             /* inferred */
    /* 0x12 */ u8 sp12;                             /* inferred */
    /* 0x13 */ char pad13[5];                       /* maybe part of sp12[6]? */
    /* 0x18 */ ? sp18;                              /* inferred */
    /* 0x18 */ char pad18[4];
    /* 0x1C */ ? sp1C;                              /* inferred */
    /* 0x1C */ char pad1C[0x24];
};                                                  /* size = 0x40 */

? func_8006F39C(s32, s32, s32);                     /* static */
s32 func_8006F3E8(s32);                             /* static */
extern ? D_80130B10;
extern u8 D_80130B34;
extern s8 D_80130B64;
extern ? D_8013A5C0;

void func_8006DD50(s32 arg0) {
    u8 sp10;
    u8 sp11;
    u8 sp12;
    ? sp18;
    ? sp1C;
    ? *var_a1;
    ? *var_s5;
    ? *var_v1;
    ? *var_v1_3;
    s32 temp_s0;
    s32 var_a0;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_5;
    s32 var_v1_2;
    u8 *temp_v1;
    u8 temp_v0;
    void *temp_v0_2;
    void *var_a0_2;
    void *var_s2;

    var_s3 = 0;
    D_80130B64 = 0;
    sp12 = 0;
    sp11 = 0;
    sp10 = 0;
    /*
    sp10 is a three byte array, storing the number of bronze, silver, and gold medals (in that order)
    Starting at offset 0xC in D_80130B10 there is an array of 19 bytes (one per level), containing numbers in the range [0-3]
    0 means the level has not been completed, 1 means bronze, 2 means silver, 3 means gold
    */
    var_v1 = &D_80130B10;
    do {
        temp_v0 = var_v1->unkC;
        var_s3 += 1;
        if (temp_v0 != 0) {
            temp_v1 = &(&sp10)[temp_v0].unk-1;
            *temp_v1 += 1;
        }
        var_v1 = var_s3 + &D_80130B10;
    } while (var_s3 < 0x13);
    // I think this loop is identifying which high scores have a real account associated with them?
    var_a2 = -1;
    var_s3_2 = 0;
    var_a1 = &D_8013A5C0;
loop_5:
    if (var_a1->unk58 == D_80130B34) {
        var_a2 = var_s3_2;
    } else {
        var_s3_2 += 1;
        var_a1 += 8;
        if (var_s3_2 < 0xA) {
            goto loop_5;
        }
    }
    var_a0 = var_a2 & 0xFF;
    if (var_a2 != -1) {
        var_a2_2 = arg0 & 0xFF;
        goto block_21;
    }
    // Not a real account, just a default one
    var_s3_3 = 0;
    // loop until the caculated score from above is greater than some other score
    // OR until we've checked all 10 high scores
loop_13:
    if ((sp10 | (sp11 << 5) | (sp12 << 0xA)) < func_8006F3E8(var_s3_3 & 0xFF)) {
        var_s3_3 += 1;
        if (var_s3_3 >= 0xA) {
            var_s3_4 = 0;
        } else {
            goto loop_13;
        }
    } else {
        var_s1 = 8;
        var_a0 = var_s3_3 & 0xFF;
        if (var_s3_3 <= 8) {
            var_a0_2 = &D_8013A5C0 + 0x40;
            var_v1_2 = 0x48;
            do {
                temp_v0_2 = var_v1_2 + &D_8013A5C0;
                temp_v0_2->unk52 = (unaligned s32) var_a0_2->unk52;
                temp_v0_2->unk56 = (unaligned s32) var_a0_2->unk56;
                var_a0_2 -= 8;
                var_s1 -= 1;
                var_v1_2 -= 8;
            } while (var_s1 >= var_s3_3);
            var_a0 = var_s3_3 & 0xFF;
        }
        var_a2_2 = arg0 & 0xFF;
        // real account or something else...
block_21:
        func_8006F39C(var_a0, (sp10 | (sp11 << 5) | (sp12 << 0xA)) & 0xFFFF, var_a2_2);
        var_s3_4 = 0;
    }
    // Ordering the highscores, if I had to guess
    // Bubble sorting, basically
    var_s5 = &D_8013A5C0;
    do {
        var_s1_2 = var_s3_4 + 1;
        if (var_s1_2 < 0xA) {
            var_s2 = (var_s1_2 * 8) + &D_8013A5C0;
            do {
                temp_s0 = func_8006F3E8(var_s3_4 & 0xFF);
                var_s1_2 += 1;
                if (temp_s0 < func_8006F3E8(var_s1_2 & 0xFF)) {
                    sp18 = (unaligned s32) var_s5->unk52;
                    sp1C = (unaligned s32) var_s5->unk56;
                    var_s5->unk52 = (unaligned s32) var_s2->unk52;
                    var_s5->unk56 = (unaligned s32) var_s2->unk56;
                    var_s2->unk52 = (unaligned s32) sp18;
                    var_s2->unk56 = (unaligned s32) sp1C;
                }
                var_s2 += 8;
            } while (var_s1_2 < 0xA);
        }
        var_s3_4 += 1;
        var_s5 += 8;
    } while (var_s3_4 < 0xA);
    var_s3_5 = 0;
    var_v1_3 = &D_8013A5C0;
    D_80130B64 = 0;
loop_32:
    if (var_v1_3->unk58 == D_80130B34) {
        D_80130B64 = var_s3_5 + 1;
        return;
    }
    var_s3_5 += 1;
    var_v1_3 += 8;
    if (var_s3_5 >= 0xA) {
        return;
    }
    goto loop_32;
}
