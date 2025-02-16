struct _m2c_stack_load_level_dat {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ ? sp10;                              /* inferred */
    /* 0x10 */ char pad10[0x28];
    /* 0x38 */ f32 sp38;                            /* inferred */
    /* 0x3C */ f32 sp3C;                            /* inferred */
    /* 0x40 */ f32 sp40;                            /* inferred */
    /* 0x44 */ char pad44[4];
    /* 0x48 */ f32 sp48;                            /* inferred */
    /* 0x4C */ f32 sp4C;                            /* inferred */
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x34];
};                                                  /* size = 0x88 */

f32 func_8001E20C(f32, f32);                        /* extern */
? load_hmt_and_hob(? *, ? *, ?, ?);                    /* extern */
void **func_80056EB0(? *);                          /* extern */
? func_8005779C(void **);                           /* extern */
void *func_8006488C(? *);                           /* extern */
? load_dat_file_assets();                                  /* extern */
? func_800653B4(void *);                            /* extern */
s32 func_80065790(void *, s32);                     /* extern */
? func_800AA870(void **, u32);                      /* extern */
s32 func_800AE98C(s32);                             /* extern */
? sprintf(? *, ? *, s32);                           /* extern */
? func_80043AEC(f32, f32, f32, f32);                /* static */
? func_80043C30(f32, f32, f32, f32);                /* static */
? func_80046620(void *, void *);                    /* static */
extern u8 D_80130B39;
extern u8 D_80130B3A;
extern ? D_80130B40;
extern u8 D_80130B63;
extern s32 D_80130B70;
extern u8 D_80130BA0;
extern ? D_80136DC0;
extern ? D_80136FB0;
extern void *D_801375D0;
extern s32 D_801375D4;
extern ? D_801375D8;
extern s32 D_80137CE4;

void *load_level_dat(s32 arg0) {
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    ? sp10;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_8;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    s32 *var_a0_4;
    s32 temp_a0_7;
    s32 temp_ft4;
    s32 temp_ft4_2;
    s32 temp_v0_12;
    s32 var_s0_2;
    s32 var_s1_6;
    s32 var_s1_8;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a0_3;
    u16 temp_v0_7;
    u16 temp_v1;
    u32 **temp_v1_6;
    u32 *temp_v0_10;
    u32 *var_a1_2;
    u32 temp_v0_11;
    u32 temp_v1_7;
    u32 var_s1;
    u32 var_s1_10;
    u32 var_s1_11;
    u32 var_s1_2;
    u32 var_s1_3;
    u32 var_s1_4;
    u32 var_s1_5;
    u32 var_s1_7;
    u32 var_s1_9;
    void **temp_a1;
    void **temp_a1_2;
    void **temp_a1_3;
    void **temp_a3;
    void **temp_s3;
    void **temp_v0_13;
    void **var_a0;
    void **var_a0_2;
    void **var_a0_3;
    void **var_a1;
    void **var_s0;
    void **var_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a0_8;
    void *temp_a0_9;
    void *temp_s0;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_14;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    sprintf(&sp10, "%s/dat", arg0);
    temp_s2 = func_8006488C(&sp10);
    sp38 = D_80136DC0.unk20;
    sp40 = D_80136DC0.unk2C;
    sp48 = D_80136DC0.unk24;
    sp50 = D_80136DC0.unk30;
    sp4C = 0.0f;
    sp3C = 0.0f;
    var_s1 = 0;
    // item0 count is non-zero
    if (temp_s2->unk0 != 0) {
        // item0 offset list offset converted to pointer
        temp_a3 = temp_s2 + temp_s2->unk4;
        temp_s2->unk4 = temp_a3;
        if (temp_s2->unk0 != 0) {
            var_a1 = temp_a3;
            do {
                // convert item0 offset to pointer
                temp_a0 = temp_a3 + *var_a1;
                *var_a1 = temp_a0;

                temp_v0 = temp_a0->unkC;
                if (temp_v0 != NULL) {
                    // item0 name offset -> pointer
                    temp_a0->unkC = (void *) (temp_a0 + temp_v0);
                    temp_a0->unk34 = 0xFFFF;
                    temp_a0->unk6 = 0xFFFF;
                    temp_a0->unk54 = 0x80000000;
                }
                if (!(temp_a0->unk4C & 2)) {
                    temp_v0_2 = temp_a0->unk5C;
                    if (temp_v0_2 != NULL) {
                        temp_a0->unk5C = (void *) (temp_a0 + temp_v0_2);
                    }
                }
                if (D_80130B39 != 0) {
                    temp_v1 = temp_a0->unk0;
                    switch (temp_v1) {              /* switch 1 */
                    case 0x0:                       /* switch 1 */
                    case 0xD:                       /* switch 1 */
                    case 0x14:                      /* switch 1 */
                    case 0x21:                      /* switch 1 */
                    case 0x28:                      /* switch 1 */
                    case 0x2A:                      /* switch 1 */
                    case 0x2B:                      /* switch 1 */
                    case 0x2E:                      /* switch 1 */
                    case 0x33:                      /* switch 1 */
                    case 0x41:                      /* switch 1 */
                    case 0x42:                      /* switch 1 */
                    case 0x44:                      /* switch 1 */
                    case 0x4A:                      /* switch 1 */
                    case 0x4B:                      /* switch 1 */
                        break;
                    case 0x32:                      /* switch 1 */
                        if (D_80130BA0 != 0) {
                        default:                    /* switch 1 */
                        case 0x1:                   /* switch 1 */
                        case 0x2:                   /* switch 1 */
                        case 0x3:                   /* switch 1 */
                        case 0x4:                   /* switch 1 */
                        case 0x5:                   /* switch 1 */
                        case 0x6:                   /* switch 1 */
                        case 0x7:                   /* switch 1 */
                        case 0x8:                   /* switch 1 */
                        case 0x9:                   /* switch 1 */
                        case 0xA:                   /* switch 1 */
                        case 0xB:                   /* switch 1 */
                        case 0xC:                   /* switch 1 */
                        case 0xE:                   /* switch 1 */
                        case 0xF:                   /* switch 1 */
                        case 0x10:                  /* switch 1 */
                        case 0x11:                  /* switch 1 */
                        case 0x12:                  /* switch 1 */
                        case 0x13:                  /* switch 1 */
                        case 0x15:                  /* switch 1 */
                        case 0x16:                  /* switch 1 */
                        case 0x17:                  /* switch 1 */
                        case 0x18:                  /* switch 1 */
                        case 0x19:                  /* switch 1 */
                        case 0x1A:                  /* switch 1 */
                        case 0x1B:                  /* switch 1 */
                        case 0x1C:                  /* switch 1 */
                        case 0x1D:                  /* switch 1 */
                        case 0x1E:                  /* switch 1 */
                        case 0x1F:                  /* switch 1 */
                        case 0x20:                  /* switch 1 */
                        case 0x22:                  /* switch 1 */
                        case 0x23:                  /* switch 1 */
                        case 0x24:                  /* switch 1 */
                        case 0x25:                  /* switch 1 */
                        case 0x26:                  /* switch 1 */
                        case 0x27:                  /* switch 1 */
                        case 0x29:                  /* switch 1 */
                        case 0x2C:                  /* switch 1 */
                        case 0x2D:                  /* switch 1 */
                        case 0x2F:                  /* switch 1 */
                        case 0x30:                  /* switch 1 */
                        case 0x31:                  /* switch 1 */
                        case 0x34:                  /* switch 1 */
                        case 0x35:                  /* switch 1 */
                        case 0x36:                  /* switch 1 */
                        case 0x37:                  /* switch 1 */
                        case 0x38:                  /* switch 1 */
                        case 0x39:                  /* switch 1 */
                        case 0x3A:                  /* switch 1 */
                        case 0x3B:                  /* switch 1 */
                        case 0x3C:                  /* switch 1 */
                        case 0x3D:                  /* switch 1 */
                        case 0x3E:                  /* switch 1 */
                        case 0x3F:                  /* switch 1 */
                        case 0x40:                  /* switch 1 */
                        case 0x43:                  /* switch 1 */
                        case 0x45:                  /* switch 1 */
                        case 0x46:                  /* switch 1 */
                        case 0x47:                  /* switch 1 */
                        case 0x48:                  /* switch 1 */
                        case 0x49:                  /* switch 1 */
                            temp_a0->unk0 = 0xFFFFU;
                        }
                        break;
                    }
                } else if ((D_80130B70 == 3) && (D_80130B40.unk23 == 0) && (temp_a0->unk0 == 0x000C)) {
                    temp_a0->unk0 = 0x0013U;
                }
                temp_fv1 = temp_a0->unk10;
                if (temp_fv1 < sp38) {
                    sp38 = temp_fv1;
                } else if (sp48 < temp_fv1) {
                    sp48 = temp_fv1;
                }
                temp_fv1_2 = temp_a0->unk14;
                if (temp_fv1_2 < sp3C) {
                    sp3C = temp_fv1_2;
                } else if (sp4C < temp_fv1_2) {
                    sp4C = temp_fv1_2;
                }
                temp_fv1_3 = temp_a0->unk18;
                if (temp_fv1_3 < sp40) {
                    sp40 = temp_fv1_3;
                } else if (sp50 < temp_fv1_3) {
                    sp50 = temp_fv1_3;
                }
                var_s1 += 1;
                var_a1 += 4;
            } while (var_s1 < (u32) temp_s2->unk0);
        }
    } else {
        temp_s2->unk4 = NULL;
    }
    var_s1_2 = 0;
    // item2 count
    if (temp_s2->unk10 != 0) {
        // item2 offset to pointer conversion
        temp_a1 = temp_s2 + temp_s2->unk14;
        temp_s2->unk14 = temp_a1;
        if (temp_s2->unk10 != 0) {
            var_a0 = temp_a1;
            do {
                temp_v1_2 = temp_a1 + *var_a0;
                *var_a0 = temp_v1_2;
                temp_v0_3 = temp_v1_2->unkC;
                if (temp_v0_3 != NULL) {
                    temp_v1_2->unkC = (void *) (temp_v1_2 + temp_v0_3);
                }
                temp_fv1_4 = temp_v1_2->unk10;
                if (temp_fv1_4 < sp38) {
                    sp38 = temp_fv1_4;
                } else if (sp48 < temp_fv1_4) {
                    sp48 = temp_fv1_4;
                }
                temp_fv1_5 = temp_v1_2->unk14;
                if (temp_fv1_5 < sp3C) {
                    sp3C = temp_fv1_5;
                } else if (sp4C < temp_fv1_5) {
                    sp4C = temp_fv1_5;
                }
                temp_fv1_6 = temp_v1_2->unk18;
                if (temp_fv1_6 < sp40) {
                    sp40 = temp_fv1_6;
                } else if (sp50 < temp_fv1_6) {
                    sp50 = temp_fv1_6;
                }
                var_s1_2 += 1;
                var_a0 += 4;
            } while (var_s1_2 < (u32) temp_s2->unk10);
        }
    } else {
        temp_s2->unk14 = NULL;
    }
    var_s1_3 = 0;
    // item3 count
    if (temp_s2->unk18 != 0) {
        // item3 offset list offset -> pointer
        temp_a1_2 = temp_s2 + temp_s2->unk1C;
        temp_s2->unk1C = temp_a1_2;
        if (temp_s2->unk18 != 0) {
            var_a0_2 = temp_a1_2;
            do {
                // item3 offset -> pointer
                temp_v1_3 = temp_a1_2 + *var_a0_2;
                *var_a0_2 = temp_v1_3;
                // item3 name offset -> pointer
                temp_v0_4 = temp_v1_3->unkC;
                if (temp_v0_4 != NULL) {
                    temp_v1_3->unkC = (void *) (temp_v1_3 + temp_v0_4);
                }
                // UNKNOWN offset -> pointer
                temp_v0_5 = temp_v1_3->unk20;
                if (temp_v0_5 != NULL) {
                    temp_v1_3->unk20 = (void *) (temp_v1_3 + temp_v0_5);
                }
                if (temp_v1_3->unk28 != 0) {
                    temp_v1_3->unk2C = (void *) (temp_v1_3 + temp_v1_3->unk2C);
                }
                var_s1_3 += 1;
                var_a0_2 += 4;
            } while (var_s1_3 < (u32) temp_s2->unk18);
        }
    } else {
        temp_s2->unk1C = NULL;
    }
    var_s1_4 = 0;
    // item6 count
    if (temp_s2->unk30 != 0) {
        // item6 offset list offset -> pointer
        temp_s3 = temp_s2 + temp_s2->unk34;
        temp_s2->unk34 = temp_s3;
        if (temp_s2->unk30 != 0) {
            var_s0 = temp_s3;
loop_67:
            // item6 offset -> pointer
            temp_v1_4 = temp_s3 + *var_s0;
            *var_s0 = temp_v1_4;
            // item6 name offset -> pointer
            temp_v0_6 = temp_v1_4->unkC;
            if (temp_v0_6 != NULL) {
                temp_v1_4->unkC = (void *) (temp_v1_4 + temp_v0_6);
                temp_v1_4->unk6 = 0xFFFF;
            }
            temp_v0_7 = temp_v1_4->unk0;
            if (temp_v0_7 != 4) {
                if (temp_v0_7 != 5) {
                    var_s0 += 4;
                } else {
                    temp_fv1_7 = temp_v1_4->unk18;
                    temp_fa0 = temp_v1_4->unk10;
                    func_80043AEC(temp_fa0, temp_fa0 + temp_v1_4->unk28, temp_fv1_7, temp_fv1_7 + temp_v1_4->unk30);
                    var_s0 += 4;
                }
            } else {
                temp_fv1_8 = temp_v1_4->unk18;
                temp_fa0_2 = temp_v1_4->unk10;
                func_80043C30(temp_fa0_2, temp_fa0_2 + temp_v1_4->unk28, temp_fv1_8, temp_fv1_8 + temp_v1_4->unk30);
                var_s0 += 4;
            }
            var_s1_4 += 1;
            if (var_s1_4 < (u32) temp_s2->unk30) {
                goto loop_67;
            }
        }
    } else {
        temp_s2->unk34 = NULL;
    }
    var_s1_5 = 0;
    // item7 count
    if (temp_s2->unk38 != 0) {
        // item7 offset list offset -> pointer
        temp_a1_3 = temp_s2 + temp_s2->unk3C;
        temp_s2->unk3C = temp_a1_3;
        if (temp_s2->unk38 != 0) {
            var_a0_3 = temp_a1_3;
            do {
                // item7 offset -> pointer
                temp_v1_5 = temp_a1_3 + *var_a0_3;
                *var_a0_3 = temp_v1_5;
                // item7 name offset ->pointer
                temp_v0_8 = temp_v1_5->unkC;
                if (temp_v0_8 != NULL) {
                    temp_v1_5->unkC = (void *) (temp_v1_5 + temp_v0_8);
                    temp_v1_5->unk6 = 0xFFFF;
                }
                var_s1_5 += 1;
                var_a0_3 += 4;
            } while (var_s1_5 < (u32) temp_s2->unk38);
        }
    } else {
        temp_s2->unk3C = NULL;
    }
    // item collection offset list offset ->pointer
    temp_v0_9 = temp_s2->unk44;
    if (temp_v0_9 != NULL) {
        temp_s2->unk44 = (void *) (temp_v0_9 + temp_s2);
        // expecting 256 item collections
        var_s1_6 = 0;
        do {
            temp_a0_2 = temp_s2->unk44;
            temp_v1_6 = (var_s1_6 * 4) + temp_a0_2;
            // if item collection offset is nonzero
            temp_v0_10 = *temp_v1_6;
            if (temp_v0_10 != NULL) {
                // item collection offset -> pointer
                var_a1_2 = temp_v0_10 + temp_a0_2;
                *temp_v1_6 = var_a1_2;
                // item collection's appear to be 2 u32s. The first being a type, the second being an index
                // all F's (-1) indicate the end of the list
                if (*var_a1_2 != -1U) {
                    var_a0_4 = var_a1_2 + 4;
                    do {
                        // switch based on the item collections type
                        temp_v1_7 = *var_a1_2;
                        switch (temp_v1_7) {        /* switch 2 */
                        case 0:                     /* switch 2 */
                            var_v1 = temp_s2->unk4;
                            var_v0 = *var_a0_4 * 4;
block_97:
                            // var_v1 is now the item* offset list pointers from the top of the file
                            // var_v0 is the index of from the item collection
                            // so temp_v0_11 now an item* pointer
                            temp_v0_11 = *(var_v0 + var_v1);
                            // replace the type of item collection with the item* pointer
                            *var_a1_2 = temp_v0_11;
                            // replace the index with the item* name pointer
                            *var_a0_4 = temp_v0_11->unkC;
                            break;
                        case 2:                     /* switch 2 */
                            var_v1 = temp_s2->unk14;
                            var_v0 = *var_a0_4 * 4;
                            goto block_97;
                        case 3:                     /* switch 2 */
                            var_v1 = temp_s2->unk1C;
                            var_v0 = *var_a0_4 * 4;
                            goto block_97;
                        case 6:                     /* switch 2 */
                            var_v1 = temp_s2->unk34;
                            var_v0 = *var_a0_4 * 4;
                            goto block_97;
                        case 7:                     /* switch 2 */
                            var_v1 = temp_s2->unk3C;
                            var_v0 = *var_a0_4 * 4;
                            goto block_97;
                        default:                    /* switch 2 */
                            *var_a1_2 = 0;
                            *var_a0_4 = 0;
                            break;
                        }
                        var_a1_2 += 8;
                        var_a0_4 += 8;
                    } while (*var_a1_2 != -1U);
                }
            }
            var_s1_6 += 1;
        } while (var_s1_6 < 0x100);
    }
    if (D_80130B3A == 1) {
        return temp_s2;
    }
    D_801375D8.unk0 = temp_s2;
    if (sp38 < 0.0f) {
        var_fv0 = func_8001E20C(sp38, 4.0f);
        var_fv1 = sp38 - 4.0f;
    } else {
        var_fv0 = func_8001E20C(sp38, 4.0f);
        var_fv1 = sp38;
    }
    sp38 = var_fv1 - var_fv0;
    if (sp40 < 0.0f) {
        var_fv0_2 = func_8001E20C(sp40, 4.0f);
        var_fv1_2 = sp40 - 4.0f;
    } else {
        var_fv0_2 = func_8001E20C(sp40, 4.0f);
        var_fv1_2 = sp40;
    }
    sp40 = var_fv1_2 - var_fv0_2;
    if (sp48 < 0.0f) {
        var_fv1_3 = sp48 - func_8001E20C(sp48, 4.0f);
    } else {
        var_fv1_3 = (sp48 + 4.0f) - func_8001E20C(sp48, 4.0f);
    }
    sp48 = var_fv1_3;
    if (sp50 < 0.0f) {
        var_fv1_4 = sp50 - func_8001E20C(sp50, 4.0f);
    } else {
        var_fv1_4 = (sp50 + 4.0f) - func_8001E20C(sp50, 4.0f);
    }
    sp50 = var_fv1_4;
    temp_ft4 = (s32) ((sp48 - sp38) * 0.25f);
    D_801375D8.unk14 = temp_ft4;
    if (temp_ft4 <= 0) {
        D_801375D8.unk14 = 1;
    }
    temp_ft4_2 = (s32) ((var_fv1_4 - sp40) * 0.25f);
    D_801375D8.unk18 = temp_ft4_2;
    if (temp_ft4_2 <= 0) {
        D_801375D8.unk18 = 1;
    }
    D_801375D8.unk4 = sp38;
    D_801375D8.unk8 = sp40;
    D_801375D8.unkC = sp48;
    D_801375D8.unk10 = var_fv1_4;
    if (D_80130B39 == 0) {
        func_800AA870(temp_s2->unk3C, temp_s2->unk38);
    }
    load_dat_file_assets();
    if (D_80130B39 != 0) {
        var_s1_7 = 0;
        if (D_801375D8.unk0->unk0 != 0) {
            do {
                temp_s0 = *((var_s1_7 * 4) + D_801375D8.unk0->unk4);
                temp_a0_3 = temp_s0->unk0;
                temp_v0_12 = temp_a0_3 & 0xFFFF;
                if ((temp_v0_12 != 0xFFFF) && (temp_v0_12 != 0x14) && (temp_v0_12 != 0x32) && (temp_v0_12 != 0x4A)) {
                    if (temp_s0->unk5C == 0) {
                        temp_s0->unk5C = func_800AE98C(temp_a0_3 & 0xFF);
                    }
                    temp_s0->unk0 = 0U;
                }
                var_s1_7 += 1;
            } while (var_s1_7 < (u32) D_801375D8.unk0->unk0);
        }
    }
    var_s1_8 = 0;
    D_801375D8.unk1C = rs_malloc(D_801375D8.unk14 * D_801375D8.unk18 * 2, 0U);
    if ((D_801375D8.unk14 * D_801375D8.unk18) > 0) {
        do {
            *((var_s1_8 * 2) + D_801375D8.unk1C) = 0xFFFF;
            var_s1_8 += 1;
        } while (var_s1_8 < (D_801375D8.unk14 * D_801375D8.unk18));
        var_s1_8 = 0;
    }
    D_801375D4 = 0;
    if (temp_s2->unk0 != 0) {
        var_s0_2 = 0;
        do {
            // temp_a0_4 is an item0 pointer
            temp_a0_4 = *(var_s0_2 + temp_s2->unk4);
            if (temp_a0_4->unk4C & 4) {
                var_s0_2 += 4;
            } else {
                var_v0_2 = 1;
                if (D_80130B39 == 0) {
                    var_v0_2 = func_80065790(temp_a0_4, D_80137CE4);
                }
                if (var_v0_2 == 1) {
                    // temp_a0_5 is an item0 pointer
                    temp_a0_5 = *(var_s0_2 + temp_s2->unk4);
                    func_80046620(temp_a0_5, temp_a0_5 + 0x10);
                    var_s0_2 += 4;
                } else {
                    var_s0_2 += 4;
                    if (var_v0_2 == 2) {
                        D_801375D4 += 1;
                    }
                }
            }
            var_s1_8 += 1;
        } while ((u32) var_s1_8 < (u32) temp_s2->unk0);
    }
    if (D_801375D4 != 0) {
        var_s3 = 0;
        var_s1_9 = 0;
        D_801375D0 = rs_malloc(D_801375D4 * 4, 0U);
        if (temp_s2->unk0 != 0) {
            do {
                // temp_a0_6 is an item0 pointer
                temp_a0_6 = temp_s2->unk4[var_s1_9];
                if (!(temp_a0_6->unk4C & 4)) {
                    temp_a0_7 = var_s3 * 4;
                    if (func_80065790(temp_a0_6, D_80137CE4) == 2) {
                        var_s3 += 1;
                        *(temp_a0_7 + D_801375D0) = temp_s2->unk4[var_s1_9];
                    }
                }
                var_s1_9 += 1;
            } while (var_s1_9 < (u32) temp_s2->unk0);
        }
    } else {
        D_801375D0 = NULL;
    }
    if (D_80130B39 == 0) {
        var_s1_10 = 0;
        if (temp_s2->unk38 != 0) {
            do {
                // temp_a0_8 is an item7 pointer
                temp_a0_8 = temp_s2->unk3C[var_s1_10];
                if (!(temp_a0_8->unk20 & 4)) {
                    func_80046620(temp_a0_8, temp_a0_8 + 0x10);
                }
                var_s1_10 += 1;
            } while (var_s1_10 < (u32) temp_s2->unk38);
        }
        var_s1_11 = 0;
        if (temp_s2->unk30 != 0) {
            do {
                // temp_a0_9 is an item6 pointer
                temp_a0_9 = temp_s2->unk34[var_s1_11];
                if (temp_a0_9->unk34 & 0x80) {
                    func_800653B4(temp_a0_9);
                }
                var_s1_11 += 1;
            } while (var_s1_11 < (u32) temp_s2->unk30);
        }
    }
    sprintf(&sp10, "%s/opkg", arg0);
    load_hmt_and_hob(&sp10, &D_80136FB0, 1, 0);
    if (D_80130B63 != 0) {
        sprintf(&sp10, "%s/opkg2", arg0);
        load_hmt_and_hob(&sp10, &D_80136FB0, 1, 0);
    }
    if (D_80130B70 == 0x0000000A) {
        temp_v0_13 = func_80056EB0("b_tsp_hi");
        if (temp_v0_13 != NULL) {
            temp_v0_14 = *temp_v0_13;
            temp_v0_14->unk44 = (f32) (temp_v0_14->unk44 * 1.5f);
            func_8005779C(temp_v0_13);
        }
    }
    return NULL;
}
