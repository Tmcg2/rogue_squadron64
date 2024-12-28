struct _m2c_stack_func_800B85B4 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ ? sp10;                              /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ ? sp30;                              /* inferred */
    /* 0x30 */ char pad30[0x18];
    /* 0x48 */ u8 sp48;                             /* inferred */
    /* 0x49 */ char pad49[0x2F];
};                                                  /* size = 0x78 */

u8 func_8006E8AC();                                 /* extern */
s8 func_8006E8BC();                                 /* extern */
? func_8006EB48(struct account_data *, ? *);        /* extern */
? sprintf(? *, ? *, u8);                            /* extern */
? func_800B438C(s32, s32, s32);                     /* static */
? func_800B8F50(f32);                               /* static */
? func_800B9198(? *);                               /* static */
? func_800C56C4(s32, ? *);                          /* static */
extern ? D_800A6654;
extern ? D_800A6678;
extern f32 D_800A68A8;
extern ? D_800CF09C;
static ? D_800A689C;                                /* unable to generate initializer: unknown type; const */
static f32 D_800A68A4[2] = { 1.0f, 3.0f };          /* const */

void func_800B85B4(void) {
    ? sp10;
    ? sp30;
    u8 sp48;
    ? *temp_fp;
    ? *var_a0;
    ? *var_s3;
    s32 temp_a2;
    s32 var_s4;
    s32 var_s5;
    s8 temp_v0;
    struct account_data *temp_v0_2;
    struct account_data *temp_v0_3;
    u32 var_s2;
    u8 *temp_s0;
    u8 var_a2;
    void *var_s1;

    // Get the "active accounts" byte from 8013A5C0
    sp48 = func_8006E8AC();
    // Not sure what this is getting
    temp_v0 = func_8006E8BC();
    var_s2 = 0;
    // struct D_800CF180_type pointer
    var_s1 = &D_800CF09C + 0xE4;
    var_s5 = 0;
    var_s4 = 0;
    // address of a struct account_data.name
    temp_fp = var_s1 + 0x10;
    // struct account_data pointer
    var_s3 = temp_fp;
    // Don't know what this is about...
    *(&D_800CF09C + 0xC6) = temp_v0;
    *(&D_800CF09C + 0xC5) = (3 - temp_v0) % 3;
    // for each of the 3 accounts...
    do {
        // ...If a given account is active...
        if (((s32) sp48 >> var_s2) & 1) {
            // Get struct account_data pointer from the save data stored at 8013A5C0
            temp_v0_2 = func_8006EE5C(var_s2 & 0xFF);
            var_s1->unkC = temp_v0_2;
            // Get the account's current level
            var_a2 = temp_v0_2->unk5;
            if (var_a2 >= 0x10U) {
                var_a2 = 0x0F;
            }
            // Use that value with the format string "level%d" to set the level name
            sprintf(&sp10, &D_800A689C, var_a2);
            // address of 
            temp_s0 = var_s4 + temp_fp;
            rs_strcpy(temp_s0, (u8 *) var_s1->unkC);
            if (strlen((s8 *) temp_s0) != 3) {
                *temp_s0 = (unaligned s32) D_800A6654;
            }
            temp_v0_3 = var_s1->unkC;
            // Copy byte 4 from struct account to byte 0x14 of struct D_800CF180_type
            var_s1->unk14 = (u8) temp_v0_3->unk4;
            // taking the medals out of the account and putting them into a more sensible array format
            func_8006EB48(temp_v0_3, &sp30);
            var_a0 = &sp30;
        } else {
            // ...Otherwise, account is inactive...
            // Unused account, so 0 out the struct account_data pointer
            var_s1->unkC = NULL;
            var_s1->unk14 = 0U;
            // For unused accounts, set the display name to "---" (0x2d2d2d)
            *var_s3 = (unaligned s32) D_800A6654;
            // Set level name to "empty"
            sprintf(&sp10, &D_800A6678);
            // NULL out the medal array, since unused accounts have no medals to speak of
            var_a0 = NULL;
        }
        var_s4 += 0x48;
        // Doing something with the medal array
        func_800B9198(var_a0);
        temp_a2 = var_s5 & 0xFFFF;
        var_s5 += 0x14;
        var_s3 += 0x48;
        // struct D_800CF180_type.somepointer, ???, account number
        func_800B438C(var_s1->unk0, *(&D_800CF09C + 0x70), temp_a2);
        // account number and level name
        func_800C56C4(var_s2 & 0xFF, &sp10);
        var_s2 += 1;
        // Set struct D_800CF180_type.some_alpha_scale0 to 0
        var_s1->unk18 = 0;
        // Set struct D_800CF180_type.some_alpha_scale1 to 1.0f
        var_s1->unk1C = (f32) *D_800A68A4;
        var_s1 += 0x48;
    } while (var_s2 < 3U);
    func_800B8F50((f32) *(&D_800CF09C + 0xC5) / D_800A68A8);
}
