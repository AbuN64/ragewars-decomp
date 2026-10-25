#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"

extern void *func_8041B7FC_de(s32, s32);

/* Steps the selected name character of an entry back by one, wrapping below the printable range to 'Z'. */
void func_80434EF4_de(s32 arg0) {
    u8 value;

    D_800E54A4->selected[arg0] = 0;
    func_8041B7FC_de(D_800E54A4->root, arg0);
    if (D_800E54A4->players[arg0].name[D_800E54A4->players[arg0].nameCursor].available == 0) {
        D_800E54A4->players[arg0].name[D_800E54A4->players[arg0].nameCursor].available = 0x41;
    }
    value = D_800E54A4->players[arg0].name[D_800E54A4->players[arg0].nameCursor].available;
    value--;
    if (value < 0x20) {
        value = 0x5A;
    }
    D_800E54A4->players[arg0].name[D_800E54A4->players[arg0].nameCursor].available = value;
}
