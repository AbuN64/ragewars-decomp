#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "FRONTEND/8042E080_45.H"

/* Returns the index of the first of a player's four 400-byte entries in the game D_800E54A4 whose
   state byte at 0x7D is -1, or -1 when all are in use. */





int PAKInterface_FindEmptyProfileSlot(int player) {
    int result;
    int i;

    result = -1;
    for (i = 0; i < 4 && result == -1; i++) {
        if (D_800E54A4->players[player].records[i].player == -1) {
            result = i;
        }
    }
    return result;
}
