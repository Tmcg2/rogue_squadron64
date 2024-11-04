struct _m2c_stack_func_80058B40 {};                 /* size 0x0 */

// meshdef1 pointer, some array of f32's
void func_80058B40(void *arg0, void *arg1) {
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    u32 var_t2;
    u8 var_v0;
    u8 var_v0_10;
    u8 var_v0_11;
    u8 var_v0_12;
    u8 var_v0_13;
    u8 var_v0_14;
    u8 var_v0_15;
    u8 var_v0_2;
    u8 var_v0_3;
    u8 var_v0_4;
    u8 var_v0_5;
    u8 var_v0_6;
    u8 var_v0_7;
    u8 var_v0_8;
    u8 var_v0_9;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *var_a0;
    void *var_t0;
    void *var_t1;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            temp_v0 = var_a0->unk20;
            if (temp_v0 != NULL) {
                // We have a facegroup pointer
                var_t1 = temp_v0;
                do {
                    temp_v0_2 = var_t1->unk8;
                    if (temp_v0_2 != NULL) {
                        // We have faces
                        var_t0 = temp_v0_2;
                        var_t2 = 0;
                        // For each face... (as long as face_count is non-zero)
                        if (var_t1->unkC != 0) {
                            do {
                                // From the unknown word, collect a number that appears to turn into an offset to the vertex colors
                                temp_a2 = var_t0 + (((u32) var_t0->unk4 >> 0xA) & 0xFC);
                                // We have vertex colors
                                if (var_t0->unk0 & 0x10) {
                                    temp_fv0 = (f32) temp_a2->unk0 * arg1->unk0;
                                    var_v0 = 0;
                                    if (!(temp_fv0 < 0.0f) && (var_v0 = 0xFF, !(temp_fv0 >= 256.0f))) {
                                        if (temp_fv0 >= 2.1474836e9f) {
                                            var_v0 = (s32) (temp_fv0 - 2.1474836e9f) | 0x80000000;
                                            goto block_14;
                                        }
                                        temp_a2->unk0 = (u8) (s32) temp_fv0;
                                    } else {
block_14:
                                        temp_a2->unk0 = var_v0;
                                    }
                                    temp_fv0_2 = (f32) temp_a2->unk1 * arg1->unk4;
                                    var_v0_2 = 0;
                                    if (!(temp_fv0_2 < 0.0f) && (var_v0_2 = 0xFF, !(temp_fv0_2 >= 256.0f))) {
                                        if (temp_fv0_2 >= 2.1474836e9f) {
                                            var_v0_2 = (s32) (temp_fv0_2 - 2.1474836e9f) | 0x80000000;
                                            goto block_22;
                                        }
                                        temp_a2->unk1 = (u8) (s32) temp_fv0_2;
                                    } else {
block_22:
                                        temp_a2->unk1 = var_v0_2;
                                    }
                                    temp_fv0_3 = (f32) temp_a2->unk2 * arg1->unk8;
                                    var_v0_3 = 0;
                                    if (!(temp_fv0_3 < 0.0f) && (var_v0_3 = 0xFF, !(temp_fv0_3 >= 256.0f))) {
                                        if (temp_fv0_3 >= 2.1474836e9f) {
                                            var_v0_3 = (s32) (temp_fv0_3 - 2.1474836e9f) | 0x80000000;
                                            goto block_30;
                                        }
                                        temp_a2->unk2 = (u8) (s32) temp_fv0_3;
                                    } else {
block_30:
                                        temp_a2->unk2 = var_v0_3;
                                    }
                                    temp_fv0_4 = (f32) temp_a2->unk4 * arg1->unk0;
                                    var_v0_4 = 0;
                                    if (!(temp_fv0_4 < 0.0f) && (var_v0_4 = 0xFF, !(temp_fv0_4 >= 256.0f))) {
                                        if (temp_fv0_4 >= 2.1474836e9f) {
                                            var_v0_4 = (s32) (temp_fv0_4 - 2.1474836e9f) | 0x80000000;
                                            goto block_38;
                                        }
                                        temp_a2->unk4 = (u8) (s32) temp_fv0_4;
                                    } else {
block_38:
                                        temp_a2->unk4 = var_v0_4;
                                    }
                                    temp_fv0_5 = (f32) temp_a2->unk5 * arg1->unk4;
                                    var_v0_5 = 0;
                                    if (!(temp_fv0_5 < 0.0f) && (var_v0_5 = 0xFF, !(temp_fv0_5 >= 256.0f))) {
                                        if (temp_fv0_5 >= 2.1474836e9f) {
                                            var_v0_5 = (s32) (temp_fv0_5 - 2.1474836e9f) | 0x80000000;
                                            goto block_46;
                                        }
                                        temp_a2->unk5 = (u8) (s32) temp_fv0_5;
                                    } else {
block_46:
                                        temp_a2->unk5 = var_v0_5;
                                    }
                                    temp_fv0_6 = (f32) temp_a2->unk6 * arg1->unk8;
                                    var_v0_6 = 0;
                                    if (!(temp_fv0_6 < 0.0f) && (var_v0_6 = 0xFF, !(temp_fv0_6 >= 256.0f))) {
                                        if (temp_fv0_6 >= 2.1474836e9f) {
                                            var_v0_6 = (s32) (temp_fv0_6 - 2.1474836e9f) | 0x80000000;
                                            goto block_54;
                                        }
                                        temp_a2->unk6 = (u8) (s32) temp_fv0_6;
                                    } else {
block_54:
                                        temp_a2->unk6 = var_v0_6;
                                    }
                                    temp_fv0_7 = (f32) temp_a2->unk8 * arg1->unk0;
                                    var_v0_7 = 0;
                                    if (!(temp_fv0_7 < 0.0f) && (var_v0_7 = 0xFF, !(temp_fv0_7 >= 256.0f))) {
                                        if (temp_fv0_7 >= 2.1474836e9f) {
                                            var_v0_7 = (s32) (temp_fv0_7 - 2.1474836e9f) | 0x80000000;
                                            goto block_62;
                                        }
                                        temp_a2->unk8 = (u8) (s32) temp_fv0_7;
                                    } else {
block_62:
                                        temp_a2->unk8 = var_v0_7;
                                    }
                                    temp_fv0_8 = (f32) temp_a2->unk9 * arg1->unk4;
                                    var_v0_8 = 0;
                                    if (!(temp_fv0_8 < 0.0f) && (var_v0_8 = 0xFF, !(temp_fv0_8 >= 256.0f))) {
                                        if (temp_fv0_8 >= 2.1474836e9f) {
                                            var_v0_8 = (s32) (temp_fv0_8 - 2.1474836e9f) | 0x80000000;
                                            goto block_70;
                                        }
                                        temp_a2->unk9 = (u8) (s32) temp_fv0_8;
                                    } else {
block_70:
                                        temp_a2->unk9 = var_v0_8;
                                    }
                                    temp_fv0_9 = (f32) temp_a2->unkA * arg1->unk8;
                                    var_v0_9 = 0;
                                    if (!(temp_fv0_9 < 0.0f) && (var_v0_9 = 0xFF, !(temp_fv0_9 >= 256.0f))) {
                                        if (temp_fv0_9 >= 2.1474836e9f) {
                                            var_v0_9 = (s32) (temp_fv0_9 - 2.1474836e9f) | 0x80000000;
                                            goto block_78;
                                        }
                                        temp_a2->unkA = (u8) (s32) temp_fv0_9;
                                    } else {
block_78:
                                        temp_a2->unkA = var_v0_9;
                                    }
                                    // if the face is a quad...
                                    if (var_t0->unk0 & 8) {
                                        temp_fv0_10 = (f32) temp_a2->unkC * arg1->unk0;
                                        var_v0_10 = 0;
                                        if (!(temp_fv0_10 < 0.0f) && (var_v0_10 = 0xFF, !(temp_fv0_10 >= 256.0f))) {
                                            if (temp_fv0_10 >= 2.1474836e9f) {
                                                var_v0_10 = (s32) (temp_fv0_10 - 2.1474836e9f) | 0x80000000;
                                                goto block_87;
                                            }
                                            temp_a2->unkC = (u8) (s32) temp_fv0_10;
                                        } else {
block_87:
                                            temp_a2->unkC = var_v0_10;
                                        }
                                        temp_fv0_11 = (f32) temp_a2->unkD * arg1->unk4;
                                        var_v0_11 = 0;
                                        if (!(temp_fv0_11 < 0.0f) && (var_v0_11 = 0xFF, !(temp_fv0_11 >= 256.0f))) {
                                            if (temp_fv0_11 >= 2.1474836e9f) {
                                                var_v0_11 = (s32) (temp_fv0_11 - 2.1474836e9f) | 0x80000000;
                                                goto block_95;
                                            }
                                            temp_a2->unkD = (u8) (s32) temp_fv0_11;
                                        } else {
block_95:
                                            temp_a2->unkD = var_v0_11;
                                        }
                                        temp_fv0_12 = (f32) temp_a2->unkE * arg1->unk8;
                                        var_v0_12 = 0;
                                        if (!(temp_fv0_12 < 0.0f) && (var_v0_12 = 0xFF, !(temp_fv0_12 >= 256.0f))) {
                                            if (temp_fv0_12 >= 2.1474836e9f) {
                                                var_v0_12 = (s32) (temp_fv0_12 - 2.1474836e9f) | 0x80000000;
                                                goto block_103;
                                            }
                                            temp_a2->unkE = (u8) (s32) temp_fv0_12;
                                        } else {
block_103:
                                            temp_a2->unkE = var_v0_12;
                                        }
                                    }
                                } else {
                                    // No vertex colors, so just a face color?
                                    temp_fv0_13 = (f32) temp_a2->unk0 * arg1->unk0;
                                    var_v0_13 = 0;
                                    if (!(temp_fv0_13 < 0.0f) && (var_v0_13 = 0xFF, !(temp_fv0_13 >= 256.0f))) {
                                        if (temp_fv0_13 >= 2.1474836e9f) {
                                            var_v0_13 = (s32) (temp_fv0_13 - 2.1474836e9f) | 0x80000000;
                                            goto block_111;
                                        }
                                        temp_a2->unk0 = (u8) (s32) temp_fv0_13;
                                    } else {
block_111:
                                        temp_a2->unk0 = var_v0_13;
                                    }
                                    temp_fv0_14 = (f32) temp_a2->unk1 * arg1->unk4;
                                    var_v0_14 = 0;
                                    if (!(temp_fv0_14 < 0.0f) && (var_v0_14 = 0xFF, !(temp_fv0_14 >= 256.0f))) {
                                        if (temp_fv0_14 >= 2.1474836e9f) {
                                            var_v0_14 = (s32) (temp_fv0_14 - 2.1474836e9f) | 0x80000000;
                                            goto block_119;
                                        }
                                        temp_a2->unk1 = (u8) (s32) temp_fv0_14;
                                    } else {
block_119:
                                        temp_a2->unk1 = var_v0_14;
                                    }
                                    temp_fv0_15 = (f32) temp_a2->unk2 * arg1->unk8;
                                    var_v0_15 = 0;
                                    if (!(temp_fv0_15 < 0.0f) && (var_v0_15 = 0xFF, !(temp_fv0_15 >= 256.0f))) {
                                        if (temp_fv0_15 >= 2.1474836e9f) {
                                            var_v0_15 = (s32) (temp_fv0_15 - 2.1474836e9f) | 0x80000000;
                                            goto block_127;
                                        }
                                        temp_a2->unk2 = (u8) (s32) temp_fv0_15;
                                    } else {
block_127:
                                        temp_a2->unk2 = var_v0_15;
                                    }
                                }
                                var_t2 += 1;
                                // Read the top byte of the "unknown" part of the face group to get this face's size and jump to the next face
                                var_t0 += ((u32) var_t0->unk4 >> 0x16) & 0xFC;
                            } while (var_t2 < (u32) var_t1->unkC);
                        }
                    }
                    // Go to the next(?) facegroup
                    var_t1 = var_t1->unk0;
                } while (var_t1 != NULL);
            }
            // Got to the next(?) meshdef1
            var_a0 = var_a0->unk0;
        } while (var_a0 != NULL);
    }
}
