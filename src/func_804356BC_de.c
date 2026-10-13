#include "span_16E000/code_80434F4C.h"
#include "types.h"
/* Copies the block's chosen 400-byte record for the place at slot arg0 into D_80102B00[arg0]: when
   the place is claimed (id != -1), copies the owning player's chosen slot into the record and marks
   the record's owned-slot byte, then always stamps the record's place-id byte. */







extern struct Block_func_804356BC_de *D_800E54A4;
extern char D_80102B00[];
extern void func_802A0724_de(void *, void *, s32);




void func_804356BC_de(s32 arg0) {
    char *record;
    s32 place;
    s32 owner;

    place = D_800E54A4->places[arg0].x;
    owner = D_800E54A4->places[arg0].y;
    record = &D_80102B00[arg0 * 400];
    if (place != -1) {
        func_802A0724_de(record, D_800E54A4->players[place].slots[owner], 400);
        ((struct Record_func_804358C0_de *)record)->slot = (s8) owner;
    }
    ((struct Record_func_804358C0_de *)record)->place = (s8) place;
}
