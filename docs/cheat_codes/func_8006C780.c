struct _m2c_stack_func_8006C780 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

s32 func_80004AAC(s32, ?, s32, ? *, s32);           /* extern */
? func_80004C70(s32, s32);                          /* extern */
s32 func_80004D5C(s32, ? *);                        /* extern */
? func_80004E70(s32, ?, s32, ?, s32, void *);       /* extern */
? decrypt_ns_hmt(void *, s32, s32);                  /* static */
extern s32 D_80137CFC;
extern s32 D_80138920;
static ? D_8003C9B0;                                /* unable to generate initializer: unknown type; const */

/*
This function decrypts the Naboo Starfighter HMT file and then does sanity checking to ensure it was decoded with the right key
Sanity checking consists of reading values from the decoded file and:
    Confirming the offset is non-zero (var != 0 )
    Confirming the offset is a multiple of 4 (!(var & 3))
    Confirming the offset wouldn't push us past the end of the file (var < hmt_file_size)
The texture_offset, texture_count, pixel_offset and texture_name_offset all are checked in this manner
(texture_offset is NOT checked for !=0)
(texture_count is further checked to be lower than 0x29)
These checks are very, very unlikely to all be correct if the file was decoded with the incorrect key
If properly validated, the decryption key is returned. Otherwise, 0 is returned
*/
s32 func_8006C780(s32 arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    u16 temp_t0;
    u32 temp_a3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_a1;
    void *temp_s2;
    void *temp_v0_3;

    temp_v0 = func_80004D5C(D_80137CFC, &D_8003C9B0);
    temp_s2 = rs_malloc(temp_v0, 0U);
    temp_v0_2 = func_80004AAC(D_80138920, 0, D_80137CFC, &D_8003C9B0, 0);
    func_80004E70(D_80138920, 0, temp_v0_2, 0, temp_v0, temp_s2);
    func_80004C70(D_80138920, temp_v0_2);
    decrypt_ns_hmt(temp_s2, temp_v0, arg0);
    // temp_s2 is a pointer to the top of the HTM file
    // so var_a1 is the offset to the texture offset 
    var_a1 = temp_s2->unk4;
    var_s0 = 0;
    // temp_v0 is the size (in bytes) of the HMT file
    // as long as we haven't stepped outside of the file, and as long as var_a1 is divisible by 4 (why?)
    // OH. If the decryption key was wrong, it would be EXTEREMLY likely that the texture_offset would be some non-multiple of 4
    if (((u32) temp_v0 >= var_a1) && !(var_a1 & 3)) {
        // temp_t0 and temp_a3 are the texture_count
        temp_t0 = *(temp_s2 + var_a1);
        temp_a3 = temp_t0 & 0xFFFF;
        if (temp_a3 < 0x29U) {
            // loop variable, counting up for each texture we walk over
            var_a2 = 0;
            if (temp_a3 > 0U) {
loop_4:
                // temp_v0_3 is a pointer to the texture_count, but its being used to access the texture_entry right below it
                // so as var_a1 is walked forwrad, this in effect points to subsequent texture_entries
                temp_v0_3 = var_a1 + temp_s2;
                // temp_v1 is the pixel_offset
                // If the decryption key was wrong, it would be EXTEREMLY likely that the pixel_offset would be some non-multiple of 4
                if ((var_a1 < (u32) temp_v0) && (temp_v1 = temp_v0_3->unk4, (temp_v1 != 0)) && !(temp_v1 & 3)) {
                    var_v0 = var_a2 & 0xFFFF;
                    // Check if we overstepped
                    if ((u32) temp_v0 >= temp_v1) {
                        // temp_v1_2 is the texture_name_offset
                        temp_v1_2 = (temp_v0_3 + 4)->unk24;
                        // Non null, decripted to a valid value
                        if ((temp_v1_2 != 0) && !(temp_v1_2 & 3)) {
                            var_v0 = var_a2 & 0xFFFF;
                            // Check if we overstepped
                            if ((u32) temp_v0 >= temp_v1_2) {
                                var_a2 += 1;
                                var_a1 += 0x34;
                                if ((u32) (var_a2 & 0xFFFF) >= temp_a3) {
                                    goto block_12;
                                }
                                goto loop_4;
                            }
                        } else {
                            goto block_12;
                        }
                    }
                } else {
                    goto block_12;
                }
            } else {
block_12:
                var_v0 = var_a2 & 0xFFFF;
            }
            if (var_v0 == temp_t0) {
                var_s0 = arg0;
            }
        }
    }
    rs_free(temp_s2);
    return var_s0;
}
