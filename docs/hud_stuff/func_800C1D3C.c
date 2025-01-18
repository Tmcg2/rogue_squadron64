struct _m2c_stack_func_800C1D3C {
    /* 0x00 */ char pad0[0x38];
};                                                  /* size = 0x38 */

? func_8000A85C(struct _anonymous *);               /* extern */
? func_8001CAC4(f32 *, ?, ?, ?);                    /* extern */
? func_80067108(s32, ?, ?, ?);                      /* extern */
s32 func_800679D0(?);                               /* extern */
? func_8006E1BC(?, ?);                              /* extern */
? func_8006E468(struct D_80130B40_type *, s16);     /* extern */
? func_80087EE8(?, ?, ?);                           /* extern */
? func_800880D8(?, ?, ?);                           /* extern */
? func_8008E0B0(?, ?, ?);                           /* extern */
s32 func_800C1B64(u32, ?);                          /* static */
extern f32 D_800A65DC;
extern f32 D_800A65E0;
extern f32 D_800A65E4;
extern f32 D_800A65E8;
extern f32 D_800A65EC;
extern f32 D_800A65F0;
extern f32 D_800A65F4;
extern f32 D_800A65F8;
extern f32 D_800A65FC;
extern f32 D_800A6600;
extern f32 D_800A6604;
extern f32 D_800A6608;
extern f32 D_800A660C;
extern f32 D_800A6610;
extern f32 D_800A6614;
extern f32 D_800A6618;
extern f32 D_800A661C;
extern u32 D_800A6624;
extern f32 D_800A6628;
extern u32 D_800A662C;
extern f32 D_800A6630;
extern ? D_80109D80;
extern u16 D_8010BFA8;
extern s32 D_8010C9E0;
extern u8 D_8010C9F1;
extern s32 D_8010CA1C;
extern s32 D_8010CA20;
extern s8 D_80130B14;
extern s32 D_80130B50;
extern u8 D_80130B60;
extern u8 D_80130B61;
extern u8 D_80130B62;
extern u8 D_80138838;
extern s32 D_80138898;
extern u8 D_80138926;
extern s32 D_80138928;
extern f32 func_800A6620;

void func_800C1D3C(struct func_800C0084_type *arg0, f32 arg1) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 var_fs0;
    f32 var_fv0;
    f32 var_fv0_2;
    s16 temp_a1_2;
    s16 temp_v1_4;
    s16 temp_v1_6;
    s16 temp_v1_7;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_4;
    s32 var_condition_bit;
    s32 var_s0_2;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1_3;
    s32 var_v1_4;
    struct D_80109DD4_type *var_a0_3;
    struct D_80109DD4_type *var_a0_5;
    struct D_80109DD4_type *var_s0;
    struct D_80109DD4_type *var_s2;
    struct _anonymous *temp_s0;
    struct func_800C0084_type *var_a1;
    struct func_800C0084_type *var_v1_2;
    u16 *var_a1_2;
    u16 *var_v1;
    u16 temp_v0;
    u16 temp_v0_7;
    u16 temp_v0_8;
    u16 temp_v1_3;
    u16 temp_v1_5;
    u8 *temp_a2;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v1;
    u8 var_v0_3;
    void *temp_a0_2;

    if (arg0->unk258 == 0) {
        if (D_8010CA20 == 5) {
            temp_s0 = &arg0->mini_hob.mini_meshdef1;
            arg0->unk258 = 1U;
            arg0->current_entry = 0;
            arg0->current_menu = 0;
            arg0->unkD6B = 1;
            arg0->unkD6C = 0U;
            arg0->mini_hob.mini_meshdef0.unknown_meshdef0_pointer1 = NULL;
            arg0->mini_hob.mini_meshdef0.unknown_meshdef0_pointer0 = NULL;
            arg0->mini_hob.mini_meshdef0.prev_meshdef0_pointer = NULL;
            arg0->mini_hob.mini_meshdef0.next_meshdef0_pointer = NULL;
            arg0->mini_hob.mini_meshdef0.meshdef1_pointer = temp_s0;
            arg0->mini_hob.mini_meshdef0.unk14 = 0;
            arg0->rest01[0xD] = 0;
            arg0->rest01[0xE] = 0;
            arg0->text_highlight_timer = 0.0f;
            arg0->medal_timer = 0.0f;
            arg0->unkD78 = 0;
            arg0->unkD7C = 0;
            func_8001CAC4(arg0->mini_hob.mini_meshdef0.big_block_o_floats, 0, 0, 0x3F800000);
            arg0->mini_hob.mini_meshdef1.unk0C = 0x02560000;
            arg0->mini_hob.mini_meshdef1.vertex_counts[0] = 4;
            arg0->mini_hob.mini_meshdef1.facegroup_pointer = &arg0->mini_hob.facegroup;
            arg0->mini_hob.mini_meshdef1.prev_meshdef1_pointer = NULL;
            arg0->mini_hob.mini_meshdef1.next_meshdef1_pointer = NULL;
            arg0->mini_hob.mini_meshdef1.unk08 = 0;
            arg0->mini_hob.mini_meshdef1.some_float = 0.0f;
            arg0->mini_hob.mini_meshdef1.unk10 = 0;
            arg0->mini_hob.mini_meshdef1.vertex_counts[1] = 0;
            arg0->mini_hob.mini_meshdef1.vertext_pointers[0] = arg0->mini_hob.vertices;
            arg0->mini_hob.mini_meshdef1.vertext_pointers[1] = NULL;
            func_8000A85C(temp_s0);
            arg0->mini_hob.facegroup.face_offset = &arg0->mini_hob.face;
            arg0->mini_hob.facegroup.face_count = 1;
            arg0->mini_hob.face.flags = 8;
            arg0->mini_hob.face.vertex_indices[2] = 1;
            arg0->mini_hob.face.vertex_indices[0] = 3;
            arg0->mini_hob.face.vertex_indices[1] = 2;
            arg0->mini_hob.vertices[3].x = -0x0100U;
            arg0->mini_hob.vertices[1].y = -0x0100U;
            arg0->mini_hob.vertices[0].y = -0x0100U;
            arg0->mini_hob.vertices[0].x = -0x0100U;
            arg0->mini_hob.facegroup.prev_facegroup = NULL;
            arg0->mini_hob.facegroup.next_facegroup = NULL;
            arg0->mini_hob.face.stuffed_data = 0x060C5140;
            arg0->mini_hob.face.material_index = 0;
            arg0->mini_hob.face.vertex_indices[3] = 0;
            arg0->mini_hob.face.vertex_colors.red = 0;
            arg0->mini_hob.face.vertex_colors.green = 0;
            arg0->mini_hob.face.vertex_colors.blue = 0;
            arg0->mini_hob.face.vertex_colors.alpha = 0;
            arg0->mini_hob.vertices[3].y = 0x0100;
            arg0->mini_hob.vertices[2].y = 0x0100;
            arg0->mini_hob.vertices[2].x = 0x0100;
            arg0->mini_hob.vertices[1].x = 0x0100;
            arg0->mini_hob.vertices[3].z = 0;
            arg0->mini_hob.vertices[2].z = 0;
            arg0->mini_hob.vertices[1].z = 0;
            arg0->mini_hob.vertices[0].z = 0;
            arg0->mini_hob.face.flags |= 2;
            func_800880D8(0x18, 0xA, 0x060C5140);
            func_800880D8(0x17, 0xA);
            func_8008E0B0(0x7F, 0, 0xA);
            var_a0 = 0;
            var_v1 = &D_8010BFA8;
            var_a1 = arg0;
            arg0->rest02[8] = 0;
            arg0->objective_highlight_countdown = D_800A65DC;
            do {
                var_a0 += 1;
                var_a1->unk7BC = (u16) *var_v1;
                *var_v1 = 0;
                var_v1 += 2;
                var_a1 += 2;
            } while (var_a0 < 4);
            if (!(D_80130B50 & 1)) {
                D_80138898 = (D_80138898 & ~0x11) | 4;
                D_80138928 = (D_80138928 | 0x11) & ~4;
            } else {
                D_80138898 |= 0xC;
                D_80138928 |= ~0xC;
            }
            goto block_7;
        }
    } else {
block_7:
        temp_v1 = arg0->unk258;
        arg0->rest01[0xE] = (bitwise u32) ((bitwise f32) arg0->rest01[0xE] + (arg1 * D_800A65E0 * D_800A65E4));
        switch (temp_v1) {                          /* irregular */
        case 1:
            temp_fv0 = (bitwise f32) arg0->rest01[0xD] + arg1;
            arg0->rest01[0xD] = (bitwise u32) temp_fv0;
            if (D_800A65E8 <= temp_fv0) {
                arg0->unk258 = 3U;
                arg0->rest01[0xD] = (bitwise u32) D_800A65E8;
                return;
            }
            return;
        case 2:
            temp_fv0_2 = (bitwise f32) arg0->rest01[0xD] - arg1;
            arg0->rest01[0xD] = (bitwise u32) temp_fv0_2;
            if (temp_fv0_2 <= 0.0f) {
                arg0->unk258 = 0U;
                D_8010C9E0 |= 0x20;
                func_800880D8(0x18, 0xFE);
                func_800880D8(0x17, 0xFE);
                var_a0_2 = 0;
                var_a1_2 = &D_8010BFA8;
                var_v1_2 = arg0;
                do {
                    temp_v0 = var_v1_2->unk7BC;
                    var_v1_2 += 2;
                    var_a0_2 += 1;
                    *var_a1_2 = temp_v0;
                    var_a1_2 += 2;
                } while (var_a0_2 < 4);
                if (!(D_80130B50 & 1)) {
                    var_v0 = D_80138898 & ~0x15;
                    var_v1_3 = D_80138928 | 0x15;
                } else {
                    var_v0 = D_80138898 & ~0xC;
                    var_v1_3 = D_80138928 | 0xC;
                }
                D_80138898 = var_v0;
                D_80138928 = var_v1_3;
            }
            if ((D_8010C9F1 != 0) && (D_8010CA1C & 0x100) && ((bitwise f32) arg0->rest01[0xD] < D_800A65EC)) {
                D_8010CA1C &= ~0x100;
                return;
            }
            break;
        case 3:
            temp_v0_2 = arg0->current_menu;
            switch (temp_v0_2) {                    /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                var_s2 = D_80109DD4;
                break;
            case 1:                                 /* switch 1 */
                var_s2 = D_80109E24;
                break;
            case 2:                                 /* switch 1 */
                var_s2 = D_80109E68;
                break;
            default:                                /* switch 1 */
                var_s2 = D_80109EEC;
                break;
            }
            if (arg0->current_menu == 0) {
                temp_v0_3 = arg0->unkD6C;
                temp_v0_4 = temp_v0_3 - 1;
                if (temp_v0_3 != 0) {
                    arg0->unkD6C = temp_v0_4;
                    if (!(temp_v0_4 & 0xFF)) {
                        func_8006E1BC(2, 1);
                    }
                }
            }
            var_s3 = 0;
            if (var_s2->flags != 0xFFFF) {
                var_a0_3 = var_s2;
                do {
                    if (var_a0_3->flags & 1) {
                        var_s3 += 1;
                        if (var_s3 == (s16) arg0->current_entry) {
                            var_s2 = var_a0_3;
                        }
                    }
                    var_a0_3 += 6;
                } while (var_a0_3->flags != 0xFFFF);
            }
            if (!(D_80130B50 & 8) && (arg0->current_menu == 0) && (func_800679D0(0) < 0)) {
                temp_fv0_3 = arg0->objective_highlight_countdown - arg1;
                arg0->objective_highlight_countdown = temp_fv0_3;
                if (temp_fv0_3 <= 0.0f) {
                    temp_a0 = arg0->rest02[8];
                    temp_a2 = temp_a0 + (gCurrentLevel * 4) + &D_80109D80;
                    if ((*temp_a2 != 0xFF) && !(((s32) D_80130B10.unk6 >> temp_a0) & 1)) {
                        var_v1_4 = temp_a0 + 1;
                        if (!(((s32) D_80130B10.unk5 >> temp_a0) & 1)) {
                            func_80067108(*temp_a2 + 0x2C0, 0x73, 0, 0x80);
                            temp_a1 = arg0->rest02[8];
                            temp_v1_2 = temp_a1 + 1;
                            var_a0_4 = temp_v1_2;
                            arg0->rest02[9] = arg0->rest02[8];
                            if (temp_v1_2 < 0) {
                                var_a0_4 = temp_a1 + 4;
                            }
                            temp_v0_5 = temp_v1_2 - (var_a0_4 & 0x1FC);
                            arg0->rest02[8] = temp_v0_5;
                            if (temp_v0_5 & 0xFF) {
                                arg0->objective_highlight_countdown = D_800A65F0;
                            } else {
                                arg0->objective_highlight_countdown = D_800A65F4;
                            }
                        } else {
                            goto block_58;
                        }
                    } else {
                        var_v1_4 = temp_a0 + 1;
block_58:
                        var_v0_2 = var_v1_4;
                        if (var_v1_4 < 0) {
                            var_v0_2 = temp_a0 + 4;
                        }
                        temp_v0_6 = var_v1_4 - (var_v0_2 & 0x1FC);
                        arg0->rest02[8] = temp_v0_6;
                        var_fv0 = D_800A65F8;
                        if (!(temp_v0_6 & 0xFF)) {
                            var_fv0 = D_800A65FC;
                        }
                        arg0->objective_highlight_countdown = var_fv0;
                        goto block_64;
                    }
                } else {
block_64:
                    arg0->rest02[9] = 0xFF;
                }
            }
            arg0->text_highlight_timer += arg1;
            arg0->unkD78 = (bitwise u32) ((bitwise f32) arg0->unkD78 - arg1);
            arg0->unkD7C = (bitwise u32) ((bitwise f32) arg0->unkD7C - arg1);
            arg0->medal_timer += arg1 * D_800A6600;
            if (D_80138838 != 0) {
                D_80138898 &= ~0x1D;
                D_80138928 |= 0x1D;
                if (D_80138926 != 0) {
                    D_8010CA1C &= ~1;
                    return;
                }
                D_8010CA1C |= 1;
                return;
            }
            if ((func_800C1B64(arg0->rest01[3], 4) & 0xFF) && (arg0->current_menu != 0) && (arg0->unkD6B == 0)) {
                var_s3 = 1;
                arg0->unkD6B = 1;
                arg0->current_menu = 0;
                arg0->current_entry = 0;
                arg0->rest02[8] = 0;
                arg0->objective_highlight_countdown = D_800A6604;
            } else if (!(func_800C1B64(arg0->rest01[3], 6) & 0xFF)) {
                if (!(func_800C1B64(arg0->rest01[3], 5) & 0xFF)) {
                    arg0->unkD6B = 0;
                } else {
                    goto block_77;
                }
            } else {
block_77:
                if (arg0->unkD6B == 0) {
                    arg0->unkD6B = 1;
                    temp_v1_3 = var_s2->flags;
                    if (temp_v1_3 & 0x20) {
                        temp_v1_4 = (s16) var_s2->unk4;
                        switch (temp_v1_4) {        /* switch 2; irregular */
                        case 2:                     /* switch 2 */
                            var_s0 = D_80109E68;
                            break;
                        default:                    /* switch 2 */
                            var_s0 = D_80109EEC;
                            break;
                        case 1:                     /* switch 2 */
                            var_s0 = D_80109E24;
                            break;
                        case 0:                     /* switch 2 */
                            var_s0 = D_80109DD4;
                            break;
                        }
                        var_s3 = 0;
                        if (var_s0->flags != 0xFFFF) {
                            var_a0_5 = var_s0;
loop_88:
                            temp_v1_5 = var_a0_5->flags;
                            if (!(temp_v1_5 & 1) || (var_s3 += 1, ((temp_v1_5 & 0x20) == 0)) || ((s16) var_a0_5->unk4 != arg0->current_menu)) {
                                var_a0_5 += 6;
                                if (var_a0_5->flags != 0xFFFF) {
                                    goto loop_88;
                                }
                            }
                        }
                        arg0->current_entry = var_s3 - 1;
                        arg0->rest02[8] = 0;
                        arg0->current_menu = var_s2->unk5;
                        arg0->objective_highlight_countdown = D_800A6608;
                    } else if (temp_v1_3 & 0x80) {
                        D_80130B14 = 0;
                        D_8010C9E0 |= 1;
                    } else {
                        if (temp_v1_3 & 4) {
                            temp_a0_2 = (arg0->rest01[3] * 4) + &D_80130B40;
                            temp_a0_2->unkC = (s32) (temp_a0_2->unkC ^ (1 << (s16) var_s2->unk4));
                            goto block_102;
                        }
                        if (temp_v1_3 & 8) {
                            temp_a1_2 = (s16) var_s2->unk4;
                            D_80130B40.unk10 = (s32) (D_80130B40.unk10 ^ (1 << temp_a1_2));
                            arg0->unkD6C = 3U;
                            if ((s16) var_s2->unk4 == 7) {
                                func_8006E468((struct D_80130B40_type *)0x00000018, temp_a1_2);
                            }
                        } else if (temp_v1_3 & 2) {
                            D_8010CA1C ^= 1 << (s16) var_s2->unk4;
block_102:
                            arg0->unkD6C = 3U;
                        } else if (temp_v1_3 & 0x40) {
                            arg0->unk258 = 2U;
                        }
                    }
                    func_80087EE8(0x18, 0x5F, 0x40);
                }
            }
            if (var_s2->flags & 0x200) {
                temp_v1_6 = (s16) var_s2->unk4;
                var_s0_2 = 0;
                if (temp_v1_6 == 0) {
                    var_v0_3 = D_80130B60;
                } else if (temp_v1_6 == 1) {
                    var_v0_3 = D_80130B61;
                } else {
                    var_v0_3 = D_80130B62;
                }
                var_fs0 = (f32) var_v0_3;
                if (func_800C1B64(arg0->rest01[3], 2) & 0xFF) {
                    var_fs0 -= arg1 * D_800A660C;
                    var_fv0_2 = 0.0f;
                    var_condition_bit = var_fs0 < 0.0f;
                    goto block_117;
                }
                if (func_800C1B64(arg0->rest01[3], 3) & 0xFF) {
                    var_fs0 += arg1 * D_800A6610;
                    var_fv0_2 = D_800A6614;
                    var_condition_bit = var_fv0_2 < var_fs0;
block_117:
                    if (var_condition_bit) {
                        var_fs0 = var_fv0_2;
                    }
                    var_s0_2 = 1;
                }
                if (var_s0_2 != 0) {
                    temp_v1_7 = (s16) var_s2->unk4;
                    if (temp_v1_7 == 0) {
                        if (!(D_800A6618 <= var_fs0)) {
                            D_80130B40.musicVolume = (u8) (s32) var_fs0;
                        } else {
                            D_80130B40.musicVolume = (s32) (var_fs0 - D_800A6618) | 0x80000000;
                        }
                    } else if (temp_v1_7 == 1) {
                        if (!(D_800A661C <= var_fs0)) {
                            D_80130B40.soundFxVolume = (u8) (s32) var_fs0;
                        } else {
                            D_80130B40.soundFxVolume = (s32) (var_fs0 - D_800A661C) | 0x80000000;
                        }
                    } else if (!(func_800A6620 <= var_fs0)) {
                        D_80130B40.speechVolume = (u8) (s32) var_fs0;
                    } else {
                        D_80130B40.speechVolume = (s32) (var_fs0 - func_800A6620) | 0x80000000;
                    }
                    arg0->unkD6C = 3U;
                    func_8006E468(&D_80130B40);
                }
            }
            if ((func_800C1B64(arg0->rest01[3], 0) & 0xFF) || (((s16) var_s2->unk2 == 0x0032) && (func_800C1B64(arg0->rest01[3], 2) & 0xFF))) {
                if ((bitwise f32) arg0->unkD78 <= 0.0f) {
                    temp_v0_7 = arg0->current_entry - 1;
                    arg0->current_entry = temp_v0_7;
                    arg0->unkD78 = D_800A6624;
                    arg0->text_highlight_timer = D_800A6628;
                    if (temp_v0_7 & 0x8000) {
                        arg0->current_entry = var_s3 - 1;
                    }
                    goto block_149;
                }
            } else if (!(func_800C1B64(arg0->rest01[3], 1) & 0xFF)) {
                if ((s16) var_s2->unk2 != 0x0031) {
                    arg0->unkD78 = 0;
                } else if (!(func_800C1B64(arg0->rest01[3], 3) & 0xFF)) {
                    arg0->unkD78 = 0;
                } else {
                    goto block_146;
                }
            } else {
block_146:
                if ((bitwise f32) arg0->unkD78 <= 0.0f) {
                    temp_v0_8 = arg0->current_entry + 1;
                    arg0->current_entry = temp_v0_8;
                    arg0->unkD78 = D_800A662C;
                    arg0->text_highlight_timer = D_800A6630;
                    if ((s16) temp_v0_8 >= var_s3) {
                        arg0->current_entry = 0;
                    }
block_149:
                    func_80087EE8(0x17, 0x5F, 0x40);
                }
            }
            if (((arg0->rest01[3] * 4) + &D_80130B40)->unkC & 8) {
                D_8010CA1C &= ~0x80;
            } else {
                D_8010CA1C |= 0x80;
            }
            if (D_8010CA20 != 5) {
                arg0->unk258 = 2U;
            }
            break;
        }
    }
}
