struct _m2c_stack_func_800C6728 {};                 /* size 0x0 */

enum SecondaryWeapon func_800C6728(enum Level arg0, enum PlayerCraft arg1, s32 arg2) {
    enum SecondaryWeapon var_a3;
    u32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    var_a3 = NONE;
    switch (temp_v1) {
    case 0:
        var_a3 = PROTON_TORPEDOS;
        break;
    case 1:
        var_a3 = BOMBS;
        break;
    case 2:
        var_a3 = MISSLES;
        break;
    case 3:
        var_a3 = CLUSTER_MISSILES;
        break;
    case 4:
        var_a3 = TOW_CABLE;
        break;
    case 6:
    case 7:
        var_a3 = NONE;
        break;
    case 5:
    case 8:
        var_a3 = SEEKER_TORPEDOS;
        break;
    }
    if ((arg0 & 0xFF) == 8) {
        if (!(arg1 & 0xFF)) {
            var_a3 = ION_CANNON;
        }
    }
    if (var_a3 == MISSLES) {
        if ((((arg2 & 0xFF) * 4) + &D_80130B40)->unkC & 0x800) {
            var_a3 = SEEKER_MISSILES;
        }
    }
    if (var_a3 == PROTON_TORPEDOS) {
        if ((((arg2 & 0xFF) * 4) + &D_80130B40)->unkC & 0x2000) {
            var_a3 = SEEKER_TORPEDOS;
        }
    }
    if ((var_a3 == CLUSTER_MISSILES) && ((((arg2 & 0xFF) * 4) + &D_80130B40)->unkC & 0x4000)) {
        var_a3 = SEEKER_CLUSTER_MISSILES;
    }
    return var_a3;
}
