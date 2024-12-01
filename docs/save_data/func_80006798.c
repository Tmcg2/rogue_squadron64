struct _m2c_stack_func_80006798 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

s32 adler32(s32, u8 *, s32);                        /* extern */
? memcpy(u8 *, s32, s32);                           /* extern */
? func_80003284();                                  /* static */
? func_800032E0();                                  /* static */
s32 func_80005B9C(u32, s32, s32, s32);              /* static */
extern s32 D_801126C8;
extern OSMesgQueue *D_801126E0;
extern s32 D_80112720;
extern u8 *D_80112724;
extern u32 D_80112728;

s32 func_80006798(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_s0;
    s32 var_s1;
    u8 *temp_s0;
    u8 *temp_s1;
    u8 *temp_s2;

    var_s1 = saved_reg_s1;
    var_s0 = arg0;
    if (var_s0 == 0) {
        var_s0 = D_80112720;
    }
    func_80003284();
    switch (var_s0) {                               /* irregular */
    case 1:
        temp_s0 = D_80112724;
        rs_memset(temp_s0, 0U, D_80112728);
        temp_s2 = temp_s0 + 0x18;
        memcpy(temp_s2, arg4, arg5);
        temp_s1 = temp_s0 + 8;
        memcpy(temp_s1, arg3, 0x00000010);
        // checksum for some other stuff, purpose unknown
        temp_s0->unk4 = adler32(adler32(0, NULL, 0), temp_s1, 0x00000010);
        var_s1 = 0;
        // checksum for the options, cheat codes, accounts, and high score stuff
        temp_s0->unk0 = adler32(adler32(0, NULL, 0), temp_s2, D_801126C8);
        osEepromLongWrite(D_801126E0, ((u32) ((arg2 * D_80112728) + 0x20) >> 3) & 0xFF, D_80112724, (s32) D_80112728);
    default:
block_11:
        func_800032E0();
        return var_s1;
    case 2:
        if (arg1 < 4U) {
            var_s1 = func_80005B9C(arg1, arg2, arg3, arg4);
            goto block_11;
        }
        return 0xA;
    }
}
