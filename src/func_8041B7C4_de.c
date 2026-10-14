#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Counts the non-zero words among the first n of the array at offset 0x5C of an object, n being
   its count at 0x48. */


s32 func_8041B7C4_de(struct SlotsRecAt5CV2 *object) {
    s32 used = 0;
    s32 i;

    for (i = 0; i < object->count; i++) {
        if (object->values[i] != 0) {
            used++;
        }
    }
    return used;
}
