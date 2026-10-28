#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "FRONTEND/8042E080_49.H"

/* Releases the first of the four twelve-byte slots at 0x2DF8 of D_800E54A4 whose id and value match
   the arguments, marking its id -1 and its state 2, and returns whether one was found. */




int PAKInterface_RemovePlayerProfileLink(int id, int value) {
    int found;
    int i;

    found = 0;
    for (i = 0; i < 4 && found == 0; i++) {
        if (D_800E54A4->links[i].player == id && D_800E54A4->links[i].entry == value) {
            found = 1;
            D_800E54A4->links[i].player = -1;
            D_800E54A4->links[i].state = 2;
        }
    }
    return found;
}
