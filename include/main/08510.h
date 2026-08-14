#ifndef MAIN_08510_H
#define MAIN_08510_H

#include "PR/ultratypes.h"
#include "PR/gbi.h"

struct DisplayListBuffer {
    struct DisplayListBuffer *next; /* 0x000 */
    struct DisplayListBuffer *prev; /* 0x004 */
    Gfx displayList[0x40];          /* 0x008 */
}; // size 0x108

struct D_main_bss_8011A444 {
    /* 0x0 */ u16 material_type;
    /* 0x2 */ u16 D_80128F08_index;
}; // size 0x4

extern struct D_main_bss_8011A444 *D_main_bss_8011A444;

void heapFreeListInsert(struct DisplayListBuffer*);
void registerSiCallback(void (*)(void));

#endif
