#include "common.h"

#include "main/02490.h"
#include "main/64EA0.h"

void insertLookupEntry(struct some_ui_list_root *arg0, struct ui_element *arg1, u8 arg2) {
    u8 var_t0;
    u8 var_t1;

    for (var_t0 = 0; var_t0 < arg0->size; var_t0++) {
        if (arg0->list[var_t0].elem == arg1) return;
    }

    for (var_t0 = 0; var_t0 < arg0->size; var_t0++) {
        if (arg0->list[var_t0].priority >= arg2) break;
    }

    for (var_t1 = arg0->size; var_t1 > var_t0 ; var_t1--) {
        arg0->list[var_t1].elem     = arg0->list[var_t1 - 1].elem;
        arg0->list[var_t1].priority = arg0->list[var_t1 - 1].priority;
        arg0->list[var_t1].active   = arg0->list[var_t1 - 1].active;
    }

    arg0->list[var_t0].elem     = arg1;
    arg0->list[var_t0].priority = arg2;
    arg0->list[var_t0].active   = 0;
    arg0->size++;
}

void removeLookupTableEntry(struct some_ui_list_root *arg0, struct ui_element *arg1) {
    u8 var_a2;
    u8 var_a3;

    if (arg0->size != 0) {
        for (var_a2 = 0; var_a2 < arg0->size; var_a2++) {
            if (arg0->list[var_a2].elem == arg1) break;
        }

        if (var_a2 != arg0->size) {
            for (var_a3 = var_a2; var_a3 < arg0->size - 1; var_a3++) {
                arg0->list[var_a3].elem     = arg0->list[var_a3 + 1].elem;
                arg0->list[var_a3].priority = arg0->list[var_a3 + 1].priority;
                arg0->list[var_a3].active   = arg0->list[var_a3 + 1].active;
            }
        }
        arg0->size--;
    }
}

struct ui_element *rebuildActiveDisplayObjectList(struct some_ui_list_root *arg0) {
    u8 var_a1;
    u8 var_a2;
    struct ui_element *temp_s0;
    struct ui_element *temp_s1;
    struct ui_element **temp_v0;

    temp_v0 = rs_malloc(0x100 * sizeof(struct ui_element*), 0U);
    temp_v0[0] = NULL;
    var_a1 = 0;
    for (var_a2 = 0; var_a2 < arg0->size; var_a2++) {
        if (arg0->list[var_a2].active == 0) continue;
        temp_s0 = arg0->list[var_a2].elem;
        if (((temp_s0->flags & 1) != 0) && (temp_s0->rgba.a == 0)) continue;
        if (temp_s0->texture_count == 0) continue;
        if (temp_s0->unknown0A == 0) continue;
        temp_v0[var_a1++] = temp_s0;
    }

    for (var_a2 = 0; var_a2 < var_a1; var_a2++) {
        temp_s1 = temp_v0[var_a2];
        if (var_a2 != 0) {
            temp_s1->next = temp_v0[var_a2 - 1];
        } else {
            temp_s1->next = NULL;
        }
        temp_s1 = temp_v0[var_a2];
        if (var_a2 != (var_a1 - 1)) {
            temp_s1->prev = temp_v0[var_a2 + 1];
        } else {
            temp_s1->prev = NULL;
        }
    }

    temp_s0 = temp_v0[0];
    rs_free(temp_v0);
    return temp_s0;
}


struct some_ui_list_root *allocateSlotTable(u16 arg0) {
    struct some_ui_list_root *temp_s1;

    temp_s1 = rs_malloc(sizeof(struct some_ui_list_root), 0U);
    temp_s1->list = rs_malloc(arg0 * sizeof(struct some_ui_list_entry), 0U);
    temp_s1->size = 0;
    temp_s1->capacity = arg0;
    return temp_s1;
}

void destroyLookupTable(struct some_ui_list_root *arg0) {
    rs_free(arg0->list);
    rs_free(arg0);
}

u32 getLookupEntryField5(struct some_ui_list_root *arg0, struct ui_element *arg1) {
    u8 var_a2;

    for (var_a2 = 0; var_a2 < arg0->size; var_a2++) {
        if (arg0->list[var_a2].elem == arg1) return arg0->list[var_a2].active;
    }
    return 0;
}

void setLookupEntryField5ByKey(struct some_ui_list_root *arg0, struct ui_element *arg1, u8 arg2) {
    u8 var_a2;

    for (var_a2 = 0; var_a2 < arg0->size; var_a2++) {
        if (arg0->list[var_a2].elem == arg1) {
            arg0->list[var_a2].active = arg2;
            return;
        }
    }
}

void relocateLookupEntryToNewKey(struct some_ui_list_root *arg0, struct ui_element *arg1, u8 arg2) {
    u8 var_a0;
    u8 temp_s1;

    for (var_a0 = 0; var_a0 < arg0->size; var_a0++) {
        if (arg0->list[var_a0].elem == arg1) {
            temp_s1 = arg0->list[var_a0].active;
            removeLookupTableEntry(arg0, arg1);
            insertLookupEntry(arg0, arg1, arg2);
            for (var_a0 = 0; var_a0 < arg0->size; var_a0++) {
                if (arg0->list[var_a0].elem == arg1) {
                    arg0->list[var_a0].active = temp_s1;
                    break;
                }
            }
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main/64EA0", load_asset_with_malloc_flags);

INCLUDE_ASM("asm/nonmatchings/main/64EA0", load_asset);

INCLUDE_ASM("asm/nonmatchings/main/64EA0", fake_func_80064934);
