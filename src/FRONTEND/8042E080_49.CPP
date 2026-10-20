#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/8042E080_49.H"

/* Releases the first of the four twelve-byte slots at 0x2DF8 of D_800E54A4 whose id and value match
   the arguments, marking its id -1 and its state 2, and returns whether one was found. */



extern struct PlayerSlotTable *D_800E54A4;

int func_80435270_de(int id, int value) {
    int found;
    int i;

    found = 0;
    for (i = 0; i < 4 && found == 0; i++) {
        if (D_800E54A4->places[i].x == id && D_800E54A4->places[i].y == value) {
            found = 1;
            D_800E54A4->places[i].x = -1;
            D_800E54A4->places[i].z = 2;
        }
    }
    return found;
}
