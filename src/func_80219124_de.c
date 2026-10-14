#include "span_1000/code_80217388.h"
#include "shared/func_80219124_de_closed.h"

void func_80219124_de(Shared_MenuItemList *list) {
    s32 i;
    f32 scale = D_800C22C4_de;
    f32 value = D_800C917C;

    list->selection = -1;
    for (i = 0; i < 4; i++) {
        list->records[i].index = i;
        list->records[i].enabled = 1;
        list->records[i].image = 0;
        list->records[i].value = value;
        list->records[i].angle = i * scale;
    }
}
