struct _m2c_stack_func_800BFDC4 {};                 /* size 0x0 */

extern u8 D_80130B12;
extern u32 D_80130B4C;

void func_800BFDC4(struct func_800C0084_type *arg0) {
    u8 var_v0;
    u8 var_v1;

    switch (D_80130B12) {
    case 2:
        var_v1 = 0;
        var_v0 = ((u32) D_80130B4C >> 0xA) & 1;
        break;
    case 3:
        var_v1 = 0;
        var_v0 = 2;
        break;
    case 7:
        var_v1 = 1;
        var_v0 = ((u32) D_80130B4C >> 0xE) & 1;
        break;
    case 9:
        var_v1 = 1;
        var_v0 = 2;
        break;
    case 5:
        var_v1 = 2;
        if (!(D_80130B4C & 0x1000)) {
            var_v0 = ((D_80130B4C & 0x2000) != 0) * 2;
        } else {
            var_v0 = 1;
        }
        break;
    case 8:
        var_v1 = 2;
        var_v0 = 2;
        break;
    case 4:
        var_v1 = 3;
        var_v0 = ((u32) D_80130B4C >> 0xF) & 1;
        break;
    default:
        var_v1 = 0;
        var_v0 = 0;
        break;
    }
    arg0->secondaryWeaponType = var_v1;
    arg0->secondaryWeaponLevel = var_v0;
}
