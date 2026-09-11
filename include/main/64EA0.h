#ifndef MAIN_64EA0_H
#define MAIN_64EA0_H

#include "hud.h"

void  insertLookupEntry(struct some_ui_list_root*, struct ui_element*, u8);
void  removeLookupTableEntry(struct some_ui_list_root*, struct ui_element*);
struct ui_element *rebuildActiveDisplayObjectList(struct some_ui_list_root*);
struct some_ui_list_root *allocateSlotTable(u16);
void  destroyLookupTable(struct some_ui_list_root*);
u32   getLookupEntryField5(struct some_ui_list_root*, struct ui_element*);
void  setLookupEntryField5ByKey(struct some_ui_list_root*, struct ui_element*, u8);
void  relocateLookupEntryToNewKey(struct some_ui_list_root*, struct ui_element*, u8);
void *load_asset(char*);

#endif
