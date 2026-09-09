#ifndef MAIN_56F50_H
#define MAIN_56F50_H

#include "PR/ultratypes.h"
#include "common_types.h"

#include "hob.h"

struct hobObjectListItem {
    u16 nextIndex;                     /* 0x00 */
    u16 padding;                       /* 0x02 */
    struct object_entry *object_entry; /* 0x04 */
    UNIDENTIFIED_TYPE *hob_file;       /* 0x08 only set for the first object loaded from each HOB file, NULL otherwise */
}; // size = 0xC

struct object_entry *getHobObjectByName(u8*);
void meshdef1_offset_convert(struct meshdef1*, u32, u32, u32, u32);
void meshdef0_offset_convert(struct meshdef0*, u32, u32, u32, u32);
void applyMeshdef1AnimColors(struct meshdef1*, u32);
void recursivelyReleaseMeshTree(struct meshdef0*);
void walkMeshdef0TreeApplyAnimColors(struct meshdef0*, u32);
void walkListAndUpdateFlagsAt0xC(struct meshdef1*, u32, u32);
void applyFlagsToMeshdef1List(struct meshdef0*, u32, u32);

#endif