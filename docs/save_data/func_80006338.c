struct _m2c_stack_func_80006338 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s32 sp1C;                            /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ s32 sp2C;                            /* inferred */
    /* 0x30 */ char pad30[0x18];
};                                                  /* size = 0x48 */

s32 adler32(s32, s32 *, u32, ?);                    /* extern */
s32 bcmp(s32 *, u8 *, ?);                           /* extern */
? memcpy(struct gamesave_asset *, s32, ?);          /* extern */
? func_80003284(s32);                               /* static */
? func_800032E0();                                  /* static */
extern s32 D_801126C4;
extern OSMesgQueue *D_801126E0;
extern ? *D_801126E4;
extern OSContStatus *D_801126E8;
extern u8 D_801126EC;
extern s8 D_801126ED;
extern s32 (*D_801126F0)(?);
extern u8 D_80112700;
extern s32 D_80112720;
extern void *D_80112724;
extern s32 D_80112728;
extern s8 D_8011272C;
extern ? gControllerBits;
extern OSMesgQueue gSIEventMesgQueue;

s32 func_80006338(s32 arg0, s32 (*arg1)(?)) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    ? *temp_s0_2;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 var_a0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    u8 *temp_v0;

    D_801126F0 = arg1;
    memcpy(&D_801126C0, arg0, 0x20);
    D_8011272C = 1;
    D_801126E0 = &gSIEventMesgQueue;
    D_801126E4 = &gControllerBits;
    D_801126E8 = gControllerStatuses;
    D_80112728 = D_801126C0.save_data_size + 0x18;
    // I don't quite understand the size of this malloc, in practice is 0x1C8 big
    // The 0xC8 part I get, its the size of a save data body + its header, but the extra 0x100 is a mystery to me
    D_80112724 = rs_malloc(D_801126C0.save_data_size + 0x118, 0x0081U);
    var_a0 = 2;
    if (D_801126C0.save_file_size != 0) {
        var_a0 = 1;
    }
    D_80112720 = var_a0;
    func_80003284(var_a0);
    D_801126EC = osEepromProbe(D_801126E0) != 0;
    func_800032E0();
    if (D_801126C0.save_file_size != 0) {
        if (D_801126EC == 0) {
            if (D_801126F0 == NULL) {
                return 0;
            }
            D_801126F0(8);
            return 0;
        }
        if (D_801126EC == 1) {
            sp14 = 0xF5F5F5F5; // probably just Factor 5 being cute
            sp24 = 0x47414D45; // "GAME"
            sp18 = 0x47535953; // "GSYS"
            sp1C = 0xAAAAAAAA; // ???
            sp2C = 0x55555555; // ???
            // I bet this is a type-cast, something like `(u16) D_801126C0.save_data_size << 0x10`
            sp28 = (D_801126C0.unkA << 0x10) | D_801126C0.data_copy_count;
            sp10 = adler32(adler32(0, NULL, 0U), &sp14, 0x0000000CU);
            sp20 = adler32(adler32(0, NULL, 0U), &sp24, 0x0000000CU);
loop_10:
            func_80003284();
            temp_s0 = osEepromLongRead(D_801126E0, 0U, &D_80112700, 0x00000020);
            func_800032E0();
            if (temp_s0 != 0) {
                var_v1 = 0;
                if (D_801126F0 != NULL) {
                    var_v1 = D_801126F0(9);
                }
                if (var_v1 != 1) {
                    D_801126EC = 0;
                    D_80112720 = 2;
                    return 0;
                }
                goto loop_10;
            }
            // Compare the top 0x20 bytes from the EEPROM to the calculated version in sp10
            // I suppose there could be a `save_file_header` struct they're using...
            // If there's a difference, zero out the entire save file
            if (bcmp(&sp10, &D_80112700, 0x20) != 0) {
                var_v1_2 = 0;
                if (D_801126F0 != NULL) {
                    var_v1_2 = D_801126F0(8);
                }
                if (var_v1_2 != 1) {
                    var_v0 = 0;
                    if (var_v1_2 == 2) {
                        if ((u32) D_801126C0.save_file_size < (u32) ((D_801126C0.data_copy_count * D_80112728) + 0x20)) {
                            if (D_801126F0 == NULL) {
                                return 0;
                            }
                            D_801126F0(2);
                            return 0;
                        }
                        // Create a new save file, all zero'd out
                        temp_v0 = rs_malloc((s32) D_801126C0.save_file_size, 8U);
                        rs_memset(temp_v0, 0U, D_801126C0.save_file_size);
                        var_s1 = 0;
                        // Calculate checksums for the all-zero body sections
                        if (D_801126C0.data_copy_count != 0) {
                            do {
                                temp_s0_2 = &temp_v0[var_s1 * (D_801126C0.save_data_size + 0x18)].unk20;
                                temp_s0_2->unk4 = adler32(adler32(0, NULL, 0U), temp_s0_2 + 8, 0x00000010U);
                                temp_s0_2->unk0 = adler32(adler32(0, NULL, 0U), temp_s0_2 + 0x18, D_801126C0.save_data_size);
                                var_s1 += 1;
                            } while (var_s1 < (s32) D_801126C0.data_copy_count);
                        }
loop_28:
                        func_80003284();
                        // Write out save file
                        if (osEepromLongWrite(D_801126E0, 0U, temp_v0, D_801126C4) != 0) {
                            func_800032E0();
                            var_v1_3 = 0;
                            if (D_801126F0 == NULL) {

                            } else {
                                goto block_33;
                            }
                            goto block_35;
                        }
                        // Write correct, hard coded header to the file
                        temp_s0_3 = osEepromLongWrite(D_801126E0, 0U, (u8 *) &sp10, 0x00000020);
                        func_800032E0();
                        if (temp_s0_3 != 0) {
                            var_v1_3 = 0;
                            if (D_801126F0 != NULL) {
block_33:
                                var_v1_3 = D_801126F0(9);
                            }
block_35:
                            if (var_v1_3 != 1) {
                                D_801126EC = 0;
                                D_80112720 = 2;
                                rs_free(temp_v0);
                                return 0;
                            }
                            goto loop_28;
                        }
                        rs_free(temp_v0);
                        goto loop_10;
                    }
                    /* Duplicate return node #40. Try simplifying control flow for better match */
                    return var_v0;
                }
                goto loop_10;
            }
            goto block_39;
        }
        goto block_39;
    }
block_39:
    D_801126ED = 0;
    var_v0 = 1;
    return var_v0;
}
