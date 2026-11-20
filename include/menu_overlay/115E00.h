#ifndef MENU_115E00_H
#define MENU_115E00_H

#include "PR/ultratypes.h"

#include "common_types.h"
#include "hob.h"
#include "hud.h"

struct bridge_mini_hob {
    struct meshdef0_inner mini_meshdef0; /* 0x00 */
    struct meshdef1 mini_meshdef1;       /* 0x4C */
    struct facegroup facegroup;          /* 0xA8 */
    struct {
        u32 flags;                       /* 0xB8 */
        u32 stuffed_data;                /* 0xBC */
        u32 material_index;              /* 0xC0 */
        u16 vertex_indices[4];           /* 0xCC */
        struct rgba vertex_colors[3];    /* 0xD0 */
    } face;                              /* 0xB8 */
    Vec3f vertices[3];                   /* 0xD8 */
}; // size = 0xFC

void initMenuWidgetArray(void);
void bridgeLoadShipBlueprints(struct some_ui_list_root*);
void printLevelSelectWeaponText(u8);
void setupPlayerCraftDisplayAnim(void);
void layoutMenuTextRow(struct some_ui_list_root*, u8);

#endif