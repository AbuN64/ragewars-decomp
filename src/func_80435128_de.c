#include "span_16E000/code_80434F4C.h"
/* Returns the index of the first of a player's four 400-byte entries in the game D_800E54A4 whose
   state byte at 0x7D is -1, or -1 when all are in use. */





extern Game_func_80435128_de *D_800E54A4;
int func_80435128_de(int player) {
    int result;
    int i;

    result = -1;
    for (i = 0; i < 4 && result == -1; i++) {
        if (D_800E54A4->players[player].entries[i].state == -1) {
            result = i;
        }
    }
    return result;
}
