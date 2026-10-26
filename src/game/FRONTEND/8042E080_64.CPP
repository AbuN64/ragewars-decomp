#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_64.H"

/* Fills entry i of the 12-byte records at offset 0x2DF8 of the object D_800E54A4 points to with
   two values and marks it set. */





void Frontend_SetPlayerProfileLink(s32 first, s32 second, s32 index) {
    D_800E54A4->links[index].player = first;
    D_800E54A4->links[index].entry = second;
    D_800E54A4->links[index].state = 1;
}
