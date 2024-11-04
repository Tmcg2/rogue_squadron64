struct _m2c_stack_func_80003480 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

? osPiStartDma(OSIoMesg *, ?, ?, u8 *, u8 *, s32, OSMesgQueue *); /* extern */
s32 func_800058C0(?);                               /* static */
? func_800072AC(s32);                               /* static */
extern s32 D_80110D54;

s32 func_80003480(u8 *source, u8 *dest, u32 size) {
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v0;

    osRecvMesg(&D_80110990, NULL, 1);
    temp_s2 = D_801109A8;
    temp_v1 = temp_s2 + 1;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_s2 + 8;
    }
    D_801109A8 = temp_v1 - ((var_v0 >> 3) * 8);
    D_801109B0[temp_s2] = dest;
    D_801109D0[temp_s2] = (s32) size;
    D_801109F0[temp_s2] = source;
    D_80110A30[temp_s2] = (s32) size;
    D_80110A10[temp_s2] = 0;
    var_s1 = D_80111254;
    if ((u32) var_s1 >= size) {
        var_s1 = (s32) size;
    }
    D_80110A50[temp_s2] = var_s1;
loop_5:
    if ((func_800058C0(0) & 0xFF) == 1) {
        func_800072AC(D_80110D54);
        goto loop_5;
    }
    D_80110A70 = 0;
    osWritebackDCache(dest, var_s1);
    osPiStartDma(&D_801107E0[temp_s2], 0, 0, source, dest, var_s1, &D_801108C0[temp_s2]);
    D_80110A70 = 1;
    D_801109AC -= 1;
    osSendMesg(&D_80110990, (void *)1, 1);
    return temp_s2;
}
