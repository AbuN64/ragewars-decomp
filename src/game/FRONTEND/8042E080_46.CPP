#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "FRONTEND/8042E080_46.H"

/* Returns 1 when all four of a player's 400-byte entries in the game D_800E54A4 have state byte -1 at
   0x7D, stopping with 0 at the first in use. */





int func_80435184_de(int player) {
    int result;
    int i;

    result = 1;
    for (i = 0; i < 4 && result == 1; i++) {
        if (D_800E54A4->players[player].records[i].player != -1) {
            result = 0;
        }
    }
    return result;
}
