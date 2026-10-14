#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Returns the halfword at offset 0xC of the object held in entry i of the pointer array at
   offset 0x4C of an object. */




s16 func_8041B810_de(struct SlotsRecAt4C *object, s32 index) {
    return object->entries[index]->unkC;
}
