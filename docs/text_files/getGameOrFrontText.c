struct _m2c_stack_getGameOrFrontText {};            /* size 0x0 */

extern u16 D_80138E7C;
static s32 D_8009ECA0 = 0;                          /* const */

s8 *getGameOrFrontText(s32 textId) {
    if ((textId >= 0) && (textId < (s32) D_80138E7C)) {
        return D_8009ECA0 + *((textId * 2) + D_8009ECA0);
    }
    return NULL;
}
