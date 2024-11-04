struct _m2c_stack_func_8001F954 {
    /* 0x00 */ char pad0[0x78];
};                                                  /* size = 0x78 */

? func_8001E36C(s32, u16, u32 *, s32);              /* static */
s16 func_8001EA50(s32);                             /* static */
void *func_8001EB24(void *, s32, u16, u16, s32, struct texture_entry *, ? *); /* static */
extern s32 D_8011A7D0;
extern void *D_8011A7D8;
extern u16 D_80128EF0;
extern s32 D_80128EFC;
extern u16 D_80128F04;

u16 func_8001F954(struct texture_entry *texture, u32 *palte_offset, u16 width, u16 height, u32 *trans_color, s8 *texture_name_offset, u8 arg6, u16 arg7, ? *arg8, u8 *arg9) {
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a3;
    s32 temp_s4;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a1;
    s32 var_s0;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0_2;
    s32 var_v0_3;
    struct D_80128F08_type *temp_a0;
    struct D_80128F08_type *temp_v1;
    struct D_80128F08_type *var_v1;
    u16 temp_v0;
    u16 var_v0;
    u32 *var_a1_2;
    void *var_a0;
    void *var_s0_2;

    if (subroutine_argF == 0xFFFF) {
        temp_v0 = D_80128EF0;
        var_s2_2 = 0;
        if ((s32) temp_v0 > 0) {
            var_s0 = 0;
loop_3:
            if ((*(var_s0 + D_80128F08) == 0) || (var_v0 = var_s2_2 & 0xFFFF, (rs_strncmp(&D_80128F08->texture_name[var_s0], arg9, 0x00000010U) != 0))) {
                var_s2_2 += 1;
                var_s0 += 0x24;
                if (var_s2_2 >= (s32) D_80128EF0) {
                    goto block_7;
                }
                goto loop_3;
            }
            /* Duplicate return node #61. Try simplifying control flow for better match */
            return var_v0;
        }
block_7:
        var_s2 = 0;
        if ((s32) temp_v0 > 0) {
            var_v1 = D_80128F08;
loop_9:
            if (*var_v1 != 0) {
                var_s2 += 1;
                var_v1 += 0x24;
                if (var_s2 < (s32) temp_v0) {
                    goto loop_9;
                }
            }
        }
        var_s0_2 = D_8011A7D8;
        goto block_13;
    }
    var_s2 = (s32) subroutine_argF;
    var_s0_2 = D_80128F08[var_s2].texture_data;
block_13:
    if (var_s2 != D_80128EF0) {
        rs_strncpy(D_80128F08[var_s2].texture_name, arg9, 0x00000010U);
        temp_s4 = (u16) trans_color & 0xFFFF;
        D_80128F08[var_s2].unk02 = subroutine_argD;
        temp_v1 = &D_80128F08[var_s2];
        temp_v1->unk0 = func_8001EA50(temp_s4);
        temp_v1->width = subroutine_arg9;
        temp_v1->texture_data = var_s0_2;
        temp_v1->unk03 = arg6;
        temp_v1->height = subroutine_argB;
        if (arg8 != NULL) {
            D_80128F08[var_s2].unk4 = (unaligned s32) *arg8;
        }
        var_a0 = func_8001EB24(var_s0_2, temp_s4, subroutine_arg9, subroutine_argB, (s32) subroutine_argD, texture, arg8);
        // `var_a1` is being used as a new image sub-type (4 or 5) to setup a second extraction from the image file
        var_a1 = 4;
        if (((u16) trans_color & 0x800) || (var_a1 = 5, (((u16) trans_color & 0x400) != 0))) {
            temp_a3 = arg6 & 0xFF;
            var_a0 = func_8001EB24(var_a0, var_a1, ((s32) subroutine_arg9 >> temp_a3) & 0xFFFF, ((s32) subroutine_argB >> temp_a3) & 0xFFFF, 1, (struct texture_entry *) texture->zeros, NULL);
        }
        var_s0_3 = (s32) (var_a0 + 0xF) & ~0xF;
        temp_v1_2 = (u16) trans_color & 0xF;
        if ((u16) trans_color & 0x20) {
            if (temp_v1_2 != 0) {
                if (temp_v1_2 == 1) {
                    var_s0_3 += 0x200;
                }
            } else {
                var_s0_3 += 0x20;
            }
        }
        temp_a0 = &D_80128F08[var_s2];
        temp_a0->unk0C = var_s0_3 - temp_a0->texture_data;
        temp_v1_3 = (u16) trans_color & 0xF;
        if (subroutine_argF == 0xFFFF) {
            D_8011A7D8 = (void *) var_s0_3;
            var_s0_4 = 0xFFFF;
            if (temp_v1_3 != 0) {
                var_t1 = 0x100;
                if (temp_v1_3 != 1) {
                    var_a1_2 = (u32 *)0x0000FFFF;
                } else {
                    goto block_31;
                }
            } else {
                var_t1 = 0x10;
block_31:
                var_a1_2 = palte_offset;
                if (((s32) palte_offset & 0xFF000000) == 0x80000000) {
                    temp_a0_2 = 0xFFFF & 0xFFFF;
                    if (temp_a0_2 == 0xFFFF) {
                        var_s0_4 = 0;
                        if (D_80128F04 != 0) {
                            var_v0_2 = 0 & 0xFFFF;
loop_35:
                            if (*((var_v0_2 * 4) + D_80128EFC) != 0) {
                                var_s0_4 += 1;
                                var_v0_2 = var_s0_4 & 0xFFFF;
                                if ((u32) (var_s0_4 & 0xFFFF) < (u16) D_80128F04) {
                                    goto loop_35;
                                }
                            }
                        }
                        temp_t0 = var_s0_4 & 0xFFFF;
                        if (temp_t0 == D_80128F04) {
                            var_a1_2 = (u32 *)0x0000FFFF;
                        } else {
                            var_a0_2 = D_8011A7D0 - (var_t1 * 2);
                            D_8011A7D0 = var_a0_2;
                            *((temp_t0 * 4) + D_80128EFC) = var_a0_2;
                            goto block_42;
                        }
                    } else {
                        var_a0_2 = *((temp_a0_2 * 4) + D_80128EFC);
block_42:
                        func_8001E36C(var_a0_2, (u16) trans_color, palte_offset, var_t1);
                        var_a1_2 = (u32 *) var_s0_4;
                    }
                }
            }
            D_80128F08[var_s2].unk0E = (u16) var_a1_2;
            goto block_59;
        }
        if (temp_v1_3 != 0) {
            var_t0 = 0x100;
            if (temp_v1_3 != 1) {
                return var_s2 & 0xFFFF;
            }
            goto block_48;
        }
        var_t0 = 0x10;
block_48:
        var_v0 = var_s2 & 0xFFFF;
        if (((s32) palte_offset & 0xFF000000) == 0x80000000) {
            temp_a0_3 = temp_a0->unk0E & 0xFFFF;
            if (temp_a0_3 == 0xFFFF) {
                var_a0_3 = 0;
                if (D_80128F04 != 0) {
                    var_v0_3 = 0 & 0xFFFF;
loop_52:
                    if (*((var_v0_3 * 4) + D_80128EFC) != 0) {
                        var_a0_3 += 1;
                        var_v0_3 = var_a0_3 & 0xFFFF;
                        if ((u32) (var_a0_3 & 0xFFFF) < (u16) D_80128F04) {
                            goto loop_52;
                        }
                    }
                }
                temp_t1 = var_a0_3 & 0xFFFF;
                if (temp_t1 != D_80128F04) {
                    var_a0_4 = D_8011A7D0 - (var_t0 * 2);
                    D_8011A7D0 = var_a0_4;
                    *((temp_t1 * 4) + D_80128EFC) = var_a0_4;
                    goto block_58;
                }
            } else {
                var_a0_4 = *((temp_a0_3 * 4) + D_80128EFC);
block_58:
                func_8001E36C(var_a0_4, (u16) trans_color, palte_offset, var_t0);
            }
block_59:
            return var_s2 & 0xFFFF;
        }
        /* Duplicate return node #61. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = 0xFFFF;
    return var_v0;
}
