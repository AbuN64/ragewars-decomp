#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 func_8041AF70_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}
