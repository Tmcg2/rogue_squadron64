struct _m2c_stack_func_8006F43C {};                 /* size 0x0 */

s32 func_8006F43C(enum PlayerCraft craftType, enum SecondaryWeapon arg1) {
    s32 var_a2;
    u32 temp_v1;

    temp_v1 = craftType & 0xFF;
    var_a2 = 0;
    switch (temp_v1) {
    case 0:
        var_a2 = 6;
        if ((arg1 & 0xFF) == 1) {
        case 7:
            var_a2 = 0x000000FF;
        }
        break;
    case 1:
        var_a2 = 0x00000014;
        break;
    case 3:
    case 4:
        var_a2 = 6;
        break;
    case 5:
        var_a2 = 0x0000000F;
        break;
    case 2:
    case 6:
        var_a2 = 8;
        break;
    case 8:
        var_a2 = 0x0000000A;
        break;
    }
    return var_a2;
}
