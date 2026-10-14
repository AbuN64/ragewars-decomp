#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Selects entry i of the 20-byte records at offset 0x48 of an object: records the index at 0x110
   and points word 0x38 of the object at 0x44 to that record. func_8041AD04_de returns the index. */






void func_8041AD10_de(struct Menu_func_8041AD10_de *menu, s32 index) {
    menu->index = index;
    menu->owner->selected = &menu->entries[index];
}
