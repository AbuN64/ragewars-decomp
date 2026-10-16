#include "span_16E000/code_80434F4C.h"
/* Returns 1 when all four twelve-byte slots at offset 0x2DF0 of the object D_800E54A4 hold -1 in
   their id word, stopping at the first that does not. */



extern Base *D_800E54A4;

int func_80435340_de(void) {
    int result;
    int i;

    result = 1;
    for (i = 0; i < 4 && result == 1; i++) {
        if (D_800E54A4->slots[i].z != -1) {
            result = 0;
        }
    }
    return result;
}
