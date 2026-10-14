#include "span_16E000/code_80434F4C.h"
/* Returns the index of the first of the four twelve-byte slots at offset 0x2DF8 of D_800E54A4 whose
   id and value words match the arguments, or -1 when none does. */



extern struct Table_func_804351E4_de *D_800E54A4;

int func_80435224_de(int id, int value) {
    int result;
    int i;

    result = -1;
    for (i = 0; i < 4 && result == -1; i++) {
        if (D_800E54A4->slots[i].x == id && D_800E54A4->slots[i].y == value) {
            result = i;
        }
    }
    return result;
}
