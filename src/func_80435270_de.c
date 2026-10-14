#include "span_16E000/code_80434F4C.h"
/* Releases the first of the four twelve-byte slots at 0x2DF8 of D_800E54A4 whose id and value match
   the arguments, marking its id -1 and its state 2, and returns whether one was found. */



extern struct Table_func_804351E4_de *D_800E54A4;

int func_80435270_de(int id, int value) {
    int found;
    int i;

    found = 0;
    for (i = 0; i < 4 && found == 0; i++) {
        if (D_800E54A4->slots[i].x == id && D_800E54A4->slots[i].y == value) {
            found = 1;
            D_800E54A4->slots[i].x = -1;
            D_800E54A4->slots[i].z = 2;
        }
    }
    return found;
}
