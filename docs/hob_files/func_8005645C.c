struct _m2c_stack_func_8005645C {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ u8 sp18;                             /* inferred */
    /* 0x19 */ char pad19[0x4F];                    /* maybe part of sp18[0x50]? */
    /* 0x68 */ u8 *sp68;                            /* inferred */
    /* 0x6C */ u8 *sp6C;                            /* inferred */
    /* 0x70 */ u8 *sp70;                            /* inferred */
    /* 0x74 */ s16 *sp74;                           /* inferred */
    /* 0x78 */ s32 sp78;                            /* inferred */
    /* 0x7C */ s32 sp7C;                            /* inferred */
    /* 0x80 */ u8 *sp80;                            /* inferred */
    /* 0x84 */ u8 *sp84;                            /* inferred */
    /* 0x88 */ char pad88[7];                       /* maybe part of sp84[2]? */
    /* 0x8F */ u8 sp8F;                             /* inferred */
    /* 0x90 */ s32 sp90;                            /* inferred */
    /* 0x94 */ char pad94[0x2C];
};                                                  /* size = 0xC0 */

s32 func_80004AAC(s32, ?, s32, u8 *, s32);          /* extern */
? func_80004C70(s32, s32);                          /* extern */
s32 func_80004D5C(s32, u8 *);                       /* extern */
? func_80004E70(s32, ?, s32, ?, s32, u8 *);         /* extern */
s32 func_80005080(s32, u8 *);                       /* extern */
? func_80014DE0(? *, ?, ?);                         /* extern */
? decrypt_ns_hmt(u8 *, s32, s32);                    /* extern */
? func_8007A260(u8 *);                              /* extern */
? sprintf(u8 *, ? *, u8 *);                         /* extern */
? func_800587F0(u8 *, u8 *, u8 *, s16 *, u8 *);     /* static */
? func_80058948(u8 *, u8 *, u8 *, s16 *, u8 *);     /* static */
? func_80058B40(u8 *, s32);                         /* static */
? func_800596C4(u8 *, s32);                         /* static */
? func_800599C0(u8 *, s32, ?);                      /* static */
? func_800599EC(u8 *, s32, ?);                      /* static */
? func_80059A80(s32, u8 *);                         /* static */
extern s32 D_80130B68;
extern s32 D_80137CFC;
extern s16 D_8013805C;
extern s32 D_8013889C;
extern s32 D_80138920;
extern ? D_80139020;
extern u16 D_801394A0;
extern ? D_801394B0;

void func_8005645C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp90;
    u8 sp8F;
    u8 *sp84;
    u8 *sp80;
    s32 sp7C;
    s32 sp78;
    s16 *sp74;
    u8 *sp70;
    u8 *sp6C;
    u8 *sp68;
    u8 sp18;
    ? *temp_a0_3;
    ? *temp_a0_5;
    ? *var_s0_3;
    s16 *temp_v0_9;
    s16 *var_s2_2;
    s32 temp_a0_4;
    s32 temp_s2;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t0_3;
    s32 temp_v0_11;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_fp;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_6;
    s32 var_s1_7;
    s32 var_s2;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s4_3;
    s32 var_s4_4;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s5_3;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    struct texture_entry *var_a1;
    u16 *temp_v0_16;
    u16 *temp_v1_4;
    u16 *var_s2_4;
    u16 temp_s1;
    u16 temp_v0_8;
    u16 var_a1_2;
    u8 *temp_a0;
    u8 *temp_a0_2;
    u8 *temp_s0;
    u8 *temp_s3;
    u8 *temp_s7;
    u8 *temp_v0;
    u8 *temp_v0_10;
    u8 *temp_v0_12;
    u8 *temp_v0_13;
    u8 *temp_v0_14;
    u8 *temp_v0_15;
    u8 *temp_v0_4;
    u8 *temp_v0_5;
    u8 *temp_v0_6;
    u8 *temp_v0_7;
    u8 *temp_v1;
    u8 *temp_v1_2;
    u8 *temp_v1_3;
    u8 *var_s0;
    u8 *var_s1;
    u8 *var_s1_5;
    u8 *var_s2_3;
    u8 *var_s3;
    u8 *var_s6;
    u8 *var_s6_2;
    u8 *var_v1;
    u8 *var_v1_2;
    u8 *var_v1_3;
    u8 temp_v0_17;
    void *temp_a1;
    void *var_s0_2;
    void *var_s0_4;

    var_s6 = NULL;
    sp8F = arg2 & 1;
    sp7C = (s32) D_8013805C;
    /*********************/
    /* HMT HANDLING HERE */
    /*********************/
    sprintf(&sp18, "%s_HMT", arg0);
    if (sp7C > 0) {
        sp78 = 0;
        sp70 = &sp18;
        if (sp18 != 0) {
            do {
                if ((&sp18)[sp78] == 0x2F) {
                    sp70 = &(&sp18)[sp78].unk1;
                }
                temp_v0 = &(&sp18)[sp78].unk1;
                sp78 += 1;
            } while (*temp_v0 != 0);
        }
        *sp70 = sp7C + 0x30;
        if (func_80005080(D_80137CFC, &sp18) != 1) {
            sprintf(&sp18, "%s_HMT", arg0);
            sp7C = 0;
        }
    }
    temp_v0_2 = func_80004D5C(D_80137CFC, &sp18);
    var_s3 = rs_malloc(temp_v0_2, 4U);
    if (var_s3 == NULL) {
        var_s3 = rs_malloc(temp_v0_2, 0U);
    }
    temp_v0_3 = func_80004AAC(D_80138920, 0, D_80137CFC, &sp18, 0);
    func_80004E70(D_80138920, 0, temp_v0_3, 0, temp_v0_2, var_s3);
    func_80004C70(D_80138920, temp_v0_3);
    if (rs_strcmp(arg0, "pl_crafts/koelsch") == 0) {
        decrypt_ns_hmt(var_s3, temp_v0_2, D_80130B68);
        arg1 = 0;
    }
    // The end-of-material offset/start of texture offset is non-zero
    temp_v0_4 = var_s3->unk4;
    if (temp_v0_4 != NULL) {
        // convert that offset to a pointer
        var_s6 = &var_s3[temp_v0_4];
        var_s3->unk4 = var_s6;
        sp78 = 0;
        // Check if texture count is non-zero
        if (*var_s6 != 0) {
            var_s5 = 4;
            var_s2 = 0;
            var_s1 = var_s6;
            do {
                // convert pallette_offset to pointer
                temp_v0_5 = var_s1->unk24;
                if (temp_v0_5 != NULL) {
                    var_s1->unk24 = &var_s3[temp_v0_5];
                }
                // convert texture_name_offset to pointer
                temp_v0_6 = var_s1->unk28;
                if (temp_v0_6 != NULL) {
                    var_s1->unk28 = &var_s3[temp_v0_6];
                }
                var_s4 = 0;
                var_a0 = var_s2;
loop_20:
                // seems like there's 8 pixel_offsets, convert every non-zero offset to a pointer
                temp_v1 = &var_s6[var_a0];
                temp_v0_7 = temp_v1->unk4;
                var_s4 += 1;
                // If pixel_offset X is non-zero, convert it to a pointer
                if (temp_v0_7 != NULL) {
                    temp_v1->unk4 = &var_s3[temp_v0_7];
                }
                var_a0 += 4;
                if (var_s4 < 8) {
                    goto loop_20;
                }
                if (arg2 & 2) {
                    // `temp_s0` is a texture_entry pointer
                    temp_s0 = &var_s6[var_s5];
                    func_8007A260(temp_s0);
                    if (arg2 & 4) {
                        func_8007A260(temp_s0);
                    }
                }
                var_s5 += 0x34;
                var_s2 += 0x34;
                var_s1 += 0x34;
                temp_t0 = sp78 + 1;
                sp78 = temp_t0;
            } while (temp_t0 < (s32) *var_s6);
        }
    }
    // non-zero material count
    temp_v0_8 = var_s3->unk0;
    if (temp_v0_8 != 0) {
        // malloc a u(s?)16 for each material
        temp_v0_9 = rs_malloc(temp_v0_8 * 2, 4U);
        sp74 = temp_v0_9;
        if (temp_v0_9 == NULL) {
            sp74 = rs_malloc(var_s3->unk0 * 2, 0U);
        }
        sp78 = 0;
        // for each material
        if (var_s3->unk0 != 0) {
            var_s2_2 = sp74;
            var_s1_2 = 8;
            var_s0 = var_s3;
            do {
                // pointer to a material_entry
                temp_a0 = &var_s3[var_s1_2];
                // material type is 1 (or, at least, has the LSB set)
                if (var_s0->unk8 & 1) {
                    // var_a1 is now a pointer to the texture_entry at the index indicated by texture_index
                    var_a1 = var_s6 + ((var_s0->unkA * 0x34) + 4);
                } else {
                    var_a1 = NULL;
                }
                var_s1_2 += 0x24;
                // Don't fully understand this function, but it at least partially translates
                // texture_index's into the D_80128F08_index's used in D_8011A444
                // Presumably, D_8011A444 holds all loaded structures, which will come from a variety of HMT files
                // so we need to remap the texture indexes for later use
                *var_s2_2 = func_80022B90((struct material_entry *) temp_a0, var_a1, 0U);
                var_s2_2 += 2;
                var_s0 += 0x24;
                temp_t0_2 = sp78 + 1;
                sp78 = temp_t0_2;
            } while (temp_t0_2 < (s32) var_s3->unk0);
        }
        rs_free(var_s3);
        /*********************/
        /* HOB HANDLING HERE */
        /*********************/
        sprintf(&sp18, "%s_HOB", arg0);
        if (sp7C > 0) {
            *sp70 = sp7C + 0x30;
        }
        temp_s2 = func_80004D5C(D_80137CFC, &sp18);
        var_a1_2 = 0x0010;
        if (sp8F != 0) {
            var_a1_2 = 4;
        }
        temp_v0_10 = rs_malloc(temp_s2, var_a1_2);
        sp68 = temp_v0_10;
        if (temp_v0_10 == NULL) {
            sp68 = rs_malloc(temp_s2, 0x0010U);
        }
        sp84 = sp68;
        sp80 = sp68;
        temp_v0_11 = func_80004AAC(D_80138920, 0, D_80137CFC, &sp18, 0);
        func_80004E70(D_80138920, 0, temp_v0_11, 0, temp_s2, sp68);
        func_80004C70(D_80138920, temp_v0_11);
        if (sp8F != 0) {
            sp6C = sp68;
            sp84 = sp68;
            temp_v0_12 = rs_malloc(sp68->unk4 + 4, 0x0010U);
            // sp68 and sp80 points to the beginning of the HOB file
            sp68 = temp_v0_12;
            sp80 = temp_v0_12;
            zmemcpy(temp_v0_12, sp6C, sp6C->unk4 + 4);
        }
        sp78 = 0;
        if (sp68->unk0 != 0) {
            sp90 = 0;
            // var_s6_2 points to the beginning of the HOB file
            var_s6_2 = sp68;
            do {
                // var_s6_2 should be treated like an "object_entry" pointer,
                // but understand that its really pointeing to the beginning of the file.
                // So all the offsets seen in this block need to be shifted back by 8 bytes.
                var_s6_2->unk40 = 1U;
                var_s6_2->unk42 = 0;
                var_s6_2->unk44 = (s32) D_8013889C;
                temp_s7 = &sp80[var_s6_2->unk34];
                // unknown_offset[0] to pointer converion
                var_s6_2->unk30 = &sp80[var_s6_2->unk30];
                // unkown_offset[1] to pointer converion
                var_s6_2->unk34 = temp_s7;
                var_v1 = temp_s7;
                // For each entry in unkown_offsets[1], while there's nonzero meshdef1 offsets
                // convert the offsets to pointers
                if (*temp_s7 != 0) {
                    do {
                        *var_v1 = &sp80[*var_v1];
                        var_v1 += 0xC;
                    } while (*var_v1 != 0);
                }
                // unknown_offset[2] to pointer converion
                var_s6_2->unk38 = &sp80[var_s6_2->unk38];
                // header_end_offset to pointer converion
                var_s6_2->unk60 = &sp80[var_s6_2->unk60];
                // meshdef0 offest -> pointer
                temp_v1_2 = var_s6_2->unk18;
                if (temp_v1_2 != NULL) {
                    var_s6_2->unk18 = &sp80[temp_v1_2];
                }
                var_s5_2 = 0;
                // meshdef0 prelude offset -> pointer
                temp_v0_13 = var_s6_2->unk1C;
                if (temp_v0_13 != NULL) {
                    temp_a0_2 = &sp80[temp_v0_13];
                    var_s6_2->unk1C = temp_a0_2;
                    var_s1_3 = 0;
                    // offsets to the actual meshdef0's being converted to pointers
                    if (*temp_a0_2 != 0) {
                        var_v1_2 = temp_a0_2;
                        do {
                            var_s1_3 += 1;
                            var_v1_2->unk8 = &sp80[var_v1_2->unk8];
                            var_v1_2 += 8;
                        } while (var_s1_3 < (s32) *temp_a0_2);
                    }
                    // if the meshed0 and meshdef1 count is not 1/1, we unset the bottom bit of object_entry->ashort
                    var_s5_2 = 0;
                    if ((s32) *temp_a0_2 != 0x00010001) {
                        var_s6_2->unk40 = (u16) (var_s6_2->unk40 & 0xFFFE);
                    }
                }
                // sp90 is, in effect, an index for each object
                var_fp = sp90;
loop_57:
                // potentially 4 of these to go through
                temp_v1_3 = &sp68[var_fp];
                temp_v0_14 = temp_v1_3->unk20;
                if (temp_v0_14 != NULL) {
                    // loop index, counting up to meshdef0 count
                    var_s4_2 = 0;
                    // meshdef1 prelude offset -> pointer
                    temp_s3 = &sp80[temp_v0_14];
                    temp_v1_3->unk20 = temp_s3;
                    var_s1_4 = 0;
                    // non-zero meshdef0 count in the meshdef1 prelude?
                    if (*temp_s3 != 0) {
                        // var_s2_3 is a pointer to a meshdef1 prelude..
                        var_s2_3 = temp_s3;
                        do {
                            // non-zero meshdef1 offset
                            if (var_s2_3->unk4 != 0) {
                                var_s0_2 = (var_s1_4 * 4) + temp_s3;
                                // `var_v0` is now a meshdef1 offset...
                                var_v0 = var_s0_2->unk4;
                                do {
                                    // meshdef1 offset -> pointer
                                    temp_v0_15 = &sp80[var_v0];
                                    var_s0_2->unk4 = temp_v0_15;
                                    // if not the first meshdef1 prelude?
                                    if (var_s5_2 > 0) {
                                        // Set `next_meshdef1_offset` to zero, maybe???
                                        *temp_v0_15 = 0;
                                        // meshdef1 pointer, hob_file_pointer, hob_file_pointer, 
                                        func_800587F0(var_s0_2->unk4, sp80, sp84, sp74, temp_s7);
                                        if (arg1 != 0) {
                                            // meshdef1 pointer, some array of f32's
                                            func_80058B40(var_s0_2->unk4, arg1);
                                        }
                                        if (arg3 != 0) {
                                            // meshdef1 pointer, 
                                            func_800599C0(var_s0_2->unk4, arg3, 0);
                                        }
                                    }
                                    var_s0_2 += 4;
                                    var_s2_3 += 4;
                                    var_v0 = var_s0_2->unk4;
                                    var_s1_4 += 1;
                                } while (var_v0 != 0);
                            }
                            var_s4_2 += 1;
                            var_s2_3 += 4;
                            var_s1_4 += 1;
                        } while (var_s4_2 < (s32) *temp_s3);
                    }
                }
                var_s5_2 += 1;
                var_fp += 4;
                if (var_s5_2 < 4) {
                    goto loop_57;
                }
                // meshdef0_offset, hob_file_pointer, hob_file_pointer, 
                func_80058948(var_s6_2->unk18, sp80, sp84, sp74, temp_s7);
                if (arg3 != 0) {
                    // meshdef0_offset, 
                    func_800599EC(var_s6_2->unk18, arg3, 0);
                }
                if (arg1 != 0) {
                    // meshdef0_offset, 
                    func_800596C4(var_s6_2->unk18, arg1);
                }
                if (var_s6_2->unk24 != 0) {
                    func_800599EC(var_s6_2->unk18, 0x00010000, 0);
                }
                if (sp8F != 0) {
                    // meshdef0 pointer...
                    var_s1_5 = var_s6_2->unk18;
                    if (var_s1_5 != NULL) {
                        do {
                            // meshdef1 pointer...
                            temp_a0_3 = var_s1_5->unk10;
                            if (temp_a0_3 != NULL) {
                                var_s0_3 = temp_a0_3;
                                do {
                                    var_a0_2 = 0;
                                    if (*temp_s7 != 0) {
                                        var_v1_3 = temp_s7;
                                        var_v0_2 = *var_v1_3;
loop_82:
                                        var_v0_3 = var_a0_2 * 2;
                                        if (var_s0_3 != var_v0_2) {
                                            var_v1_3 += 0xC;
                                            var_v0_2 = *var_v1_3;
                                            var_a0_2 += 1;
                                            if (var_v0_2 == 0) {
                                                var_v0_3 = var_a0_2 * 2;
                                            } else {
                                                goto loop_82;
                                            }
                                        }
                                        if (*(((var_v0_3 + var_a0_2) * 4) + temp_s7) == 0) {
                                            goto block_86;
                                        }
                                    } else {
block_86:
                                        // meshdef1 pointer, 
                                        func_80014DE0(var_s0_3, 0, 0);
                                    }
                                    var_s0_3 = *var_s0_3;
                                } while (var_s0_3 != NULL);
                            }
                            temp_a0_4 = var_s1_5->unkC;
                            if (temp_a0_4 != 0) {
                                // meshdef0 pointer/offset, unkown_offsets[1] pointer
                                func_80059A80(temp_a0_4, temp_s7);
                            }
                            var_s1_5 = var_s1_5->unk0;
                        } while (var_s1_5 != NULL);
                    }
                    // This loop appears to be going over meshdef1_prelude_offsets[1-3]
                    var_s5_3 = 1;
                    var_s7 = sp90 + 4;
                    do {
                        // `temp_v0_16` is a meshdef1_prelude pointer...
                        temp_v0_16 = sp68[var_s7].unk20;
                        if (temp_v0_16 != NULL) {
                            var_s4_3 = 0;
                            var_s1_6 = 0;
                            // nonzero meshdef0 count in the meshdef1_prelude?
                            if (*temp_v0_16 != 0) {
                                var_s2_4 = temp_v0_16;
                                do {
                                    if (var_s2_4->unk4 != 0) {
                                        var_s0_4 = (var_s1_6 * 4) + temp_v0_16;
                                        do {
                                            temp_a0_5 = var_s0_4->unk4;
                                            var_s0_4 += 4;
                                            var_s2_4 += 4;
                                            func_80014DE0(temp_a0_5, 0, 0);
                                            var_s1_6 += 1;
                                        } while (var_s0_4->unk4 != 0);
                                    }
                                    var_s4_3 += 1;
                                    var_s2_4 += 4;
                                    var_s1_6 += 1;
                                } while (var_s4_3 < (s32) *temp_v0_16);
                            }
                        }
                        var_s5_3 += 1;
                        var_s7 += 4;
                    } while (var_s5_3 < 4);
                    var_s6_2->unk42 = 1;
                    var_s6_2->unk40 = (u16) (var_s6_2->unk40 | 2);
                }
                // Go through the object name, add all its bytes up?
                var_s4_4 = 0;
                var_s1_7 = 0;
                var_v0_4 = sp90;
loop_102:
                temp_v0_17 = sp68[var_v0_4].unk8;
                var_s1_7 += 1;
                if (temp_v0_17 != 0) {
                    var_s4_4 += temp_v0_17;
                    var_v0_4 = var_s1_7 + sp90;
                    if (var_s1_7 < 0x10) {
                        goto loop_102;
                    }
                }
                temp_s1 = D_801394A0;
                temp_a1 = (temp_s1 * 0xC) + &D_80139020;
                temp_v1_4 = ((var_s4_4 % 25) * 2) + &D_801394B0;
                D_801394A0 = temp_a1->unk0;
                temp_a1->unk0 = (u16) *temp_v1_4;
                *temp_v1_4 = temp_s1;
                temp_a1->unk4 = &sp68[sp90].unk8;
                if (sp78 != 0) {
                    temp_a1->unk8 = NULL;
                } else {
                    temp_a1->unk8 = sp68;
                }
                sp90 += 0x74;
                var_s6_2 += 0x74;
                temp_t0_3 = sp78 + 1;
                sp78 = temp_t0_3;
            } while (temp_t0_3 < (s32) sp68->unk0);
        }
        if (sp8F != 0) {
            rs_free(sp6C);
        }
        rs_free(sp74);
    }
}
