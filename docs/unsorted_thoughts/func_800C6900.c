struct _m2c_stack_func_800C6900 {};                 /* size 0x0 */

// return a number used to identify which "planet*" asset to use for the pan-down after the text crawl before some levels
// Since there's only 4 text crawls, the levels without them return 0xFF (-1)
s32 func_800C6900(enum Level arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    if (temp_a0 != 5) {
        if (temp_a0 < 6) {
            if (temp_a0 != 0) {
                return 0x000000FF;
            }
            return 0;
        }
        switch (temp_a0) {                          /* irregular */
        case 10:
            return 2;
        case 15:
            return 3;
        default:
            return 0x000000FF;
        }
    } else {
        return 1;
    }
}
