struct _m2c_stack_func_800045E8 {
    /* 0x00 */ char pad0[0x28];
};                                                  /* size = 0x28 */

? osCreatePiManager(?, OSMesgQueue *, void **, ?);  /* extern */
? func_80003638(s32);                               /* static */
? func_80004360();                                  /* static */
? func_80005380(void *, s32);                       /* static */
? func_80005850();                                  /* static */
s32 func_80006C28(?, ?, ?, ? (*)());                /* static */
s32 func_80006D9C(s32);                             /* static */
extern ? D_40;
extern void *D_8010FCB0;
extern u32 D_80110D40;
extern ? *D_80110D44;
extern s32 D_80110D48;
extern s32 D_80110D4C;
extern void *D_80110D50;
extern s32 D_80110D54;
extern u8 D_B0144340;
extern ? D_B0144380;

s32 func_800045E8(s32 arg0) {
    OSMesgQueue *var_s1;
    OSMesgQueue *var_v0_2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    struct D_80110A80_entry *var_v0;
    struct data_block_header_entry *temp_v0_2;
    void **var_s2;

    var_s0 = 0;
    D_80111254 = 0x00004000;
    var_s2 = D_801108A0;
    var_s1 = D_801108C0;
    do {
        osCreateMesgQueue(var_s1, var_s2, 1);
        var_s2 += 4;
        var_s0 += 1;
        var_s1 += 0x18;
    } while (var_s0 < 8);
    osCreateMesgQueue(&D_80110990, &D_80110980, 1);
    osSendMesg(&D_80110990, (void *)1, 0);
    osCreatePiManager(0x96, &D_801107C0, D_801107A0, 8);
    var_s0_2 = 3;
    var_v0 = &D_80110A80[3];
    do {
        var_v0->one = 0;
        var_s0_2 -= 1;
        var_v0 -= 0x50;
    } while (var_s0_2 >= 0);
    var_s0_3 = 0xF;
    var_v0_2 = &D_80110BC0[0xF];
    do {
        *var_v0_2 = 0;
        var_s0_3 -= 1;
        var_v0_2 -= 0x18;
    } while (var_s0_3 >= 0);
    if (D_8010FCB0->unk31 != 0) {
        D_80110D4C = arg0;
        D_80110D48 = arg0;
        if (arg0 != 0) {
            D_80110D50 = rs_malloc(arg0, 0x0081U);
        }
    } else {
        D_80110D4C = 0;
        D_80110D48 = 0;
        D_80110D50 = NULL;
    }
    func_80005380(D_80110D50, D_80110D48);
    D_801109A8 = 0;
    D_801109AC = 8;
    D_80110A70 = 0;
    D_80110D40 = (u32) &D_40 >> 5;
    temp_v0_2 = rs_malloc((s32) &D_40, 0x0081U);
    D_80110A74 = temp_v0_2;
    func_80003638(func_80003480(&D_B0144340, temp_v0_2->name, (u32) &D_40));
    D_80110D44 = &D_B0144380;
    func_80005850();
    temp_v0 = func_80006C28(8, 0x2000, 0x20, func_80004360);
    D_80110D54 = temp_v0;
    return func_80006D9C(temp_v0) & 0xFF;
}
