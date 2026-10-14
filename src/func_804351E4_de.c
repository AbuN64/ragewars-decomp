#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Returns the index of the first of the four 12-byte slots at offset 0x2DF8 of the table D_800E54A4
   points to whose first word is -1, meaning free, or -1 when none is. */




extern struct Table_func_804351E4_de *D_800E54A4;

s32 func_804351E4_de(void) {
    s32 found = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (found != -1) {
            break;
        }
        if (D_800E54A4->slots[i].x == -1) {
            found = i;
        }
    }
    return found;
}
