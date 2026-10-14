#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Sets the word at offset 0x54 of an object to 2 when the event's upper halfword is 3 and its
   value is 6 or 7, and returns zero. */


s32 func_8041AAF0_de(struct func_8022FD9C_Record *object, void *unused, u32 event, s32 value) {
    if ((event >> 16) == 3 && value < 8 && value >= 6) {
        object->unk54 = 2;
    }
    return 0;
}
