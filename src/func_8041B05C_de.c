#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"

/* When the fourth argument is one, moves a menu's selection at offset 0x110 to the previous of its
   0x114 entries, wrapping to the last, points word 0x38 of its owner at 0x44 to the selected 20-byte
   entry at 0x48 and plays sound 0xE81. Returns zero. */






extern void func_8025DF34_de(s32);

s32 func_8041B05C_de(struct MenuRecAt114 *menu, void *second, void *third, s32 active) {
    struct OwnerRecAt38 *owner;

    if (active == 1) {
        owner = menu->owner;
        if (--menu->index < 0) {
            menu->index = menu->count - 1;
        }
        owner->selected = &menu->entries[menu->index];
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}
