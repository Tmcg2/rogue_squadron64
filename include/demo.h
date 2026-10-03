#ifndef DEMO_H
#define DEMO_H

#include "PR/ultratypes.h"

struct demoInput {
    /*
    * I suspect this is duration of the input, but I can't be sure...
    * its nomrally 1/30th or 1/20th, which would sort of fit for a 1-per-frame setup
    * But increasing these values to things like 1 or 5 don't increase the input's duration (or, at least, not in any perceptible way)
    */
    f32 unk0;    /* 0x0 */ 
    u16 button;  /* 0x4 */ 
    s8  stick_x; /* 0x6 */ 
    s8  stick_y; /* 0x7 */ 
}; // size 0x8

#endif
