struct _m2c_stack_func_800587F0 {};                 /* size 0x0 */

// meshdef1 pointer, hob_file_pointer, hob_file_pointer, 
void func_800587F0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 *var_v1;
    s32 temp_v0;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 var_t3;
    u32 var_t2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v1;
    void *var_a0;
    void *var_t0;
    void *var_t1;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            var_t3 = arg2;
            if (*arg4 != 0) {
                var_v1 = arg4;
loop_4:
                var_v1 += 0xC;
                if (var_a0 == *var_v1) {
                    var_t3 = arg1;
                } else if (*var_v1 != 0) {
                    goto loop_4;
                }
            }
            // face_group_end_offset -> pointer
            var_a0->unk-4 = (s32) (var_a0->unk-4 - (var_a0 - arg1));
            // flags getting set???
            var_a0->unkC = (s32) (var_a0->unkC | 0x100008);
            // unk0 is some sort of offset, this is converting it to a pointer
            temp_v1 = var_a0->unk0;
            if (temp_v1 != NULL) {
                var_a0->unk0 = (void *) (temp_v1 + arg1);
            }
            // unk4 is some sort of offset, this is converting it to a pointer
            temp_v0 = var_a0->unk4;
            if (temp_v0 != 0) {
                var_a0->unk4 = (s32) (temp_v0 + arg1);
            }
            // face group offset -> pointer
            temp_v0_2 = var_a0->unk20;
            temp_v0_3 = temp_v0_2 + var_t3;
            if (temp_v0_2 != NULL) {
                // `var_t1` is a facegroup pointer
                var_t1 = temp_v0_3;
                var_a0->unk20 = temp_v0_3;
                if (var_t1 != NULL) {
                    do {
                        // facegroup unk0 offset(?) -> pointer
                        // seemingly some sort of link to the "next" facegroup...
                        temp_v0_4 = var_t1->unk0;
                        if (temp_v0_4 != NULL) {
                            var_t1->unk0 = (void *) (temp_v0_4 + var_t3);
                        }
                        // facegroup unk4 offset(?) -> pointer
                        temp_v0_5 = var_t1->unk4;
                        if (temp_v0_5 != 0) {
                            var_t1->unk4 = (s32) (temp_v0_5 + var_t3);
                        }
                        // face list offset -> pointer
                        temp_v0_6 = var_t1->unk8;
                        if ((temp_v0_6 != NULL) && (arg3 != 0)) {
                            // `var_t0` is a face pointer
                            var_t0 = temp_v0_6 + var_t3;
                            var_t2 = 0;
                            var_t1->unk8 = var_t0;
                            // iterating over each face
                            if (var_t1->unkC != 0) {
                                do {
                                    var_t2 += 1;
                                    // converting the material index to a... pointer? I think?
                                    var_t0->unk8 = (s32) (*((var_t0->unk8 * 2) + arg3) << 0x10);
                                    // Read the top byte of the "unknown" part of the face group to get this face's size and jump to the next face
                                    var_t0 += (u32) (var_t0->unk4 & 0x3F000000) >> 0x16;
                                } while (var_t2 < (u32) var_t1->unkC);
                            }
                        }
                        var_t1 = var_t1->unk0;
                    } while (var_t1 != NULL);
                }
            }
            // vertex offset1 -> pointer
            temp_v0_7 = var_a0->unk24;
            if (temp_v0_7 != 0) {
                var_a0->unk24 = (s32) (temp_v0_7 + var_t3);
            }
            // vertex offset2 -> pointer
            temp_v0_8 = var_a0->unk28;
            if (temp_v0_8 != 0) {
                var_a0->unk28 = (s32) (temp_v0_8 + var_t3);
            }
            var_a0 = var_a0->unk0;
        } while (var_a0 != NULL);
    }
}
