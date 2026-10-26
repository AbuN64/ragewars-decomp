#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"

extern void *SmpOverlay_GetSlotValue(s32, s32);

/* Advances the selected name character, wrapping past Z to a space. */
void func_80434E34_de(s32 player) {
    u8 value;

    D_800E54A4->selected[player] = 0;
    SmpOverlay_GetSlotValue(D_800E54A4->root, player);
    if (D_800E54A4->players[player].name[D_800E54A4->players[player].nameCursor].available == 0) {
        D_800E54A4->players[player].name[D_800E54A4->players[player].nameCursor].available = 0x41;
    }
    value = D_800E54A4->players[player].name[D_800E54A4->players[player].nameCursor].available;
    value++;
    if (value >= 0x5B) {
        value = 0x20;
    }
    D_800E54A4->players[player].name[D_800E54A4->players[player].nameCursor].available = value;
}
