#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_59.H"

/* Copies the block's chosen 400-byte record for the place at slot arg0 into D_80102B00[arg0]: when
   the place is claimed (id != -1), copies the owning player's chosen slot into the record and marks
   the record's owned-slot byte, then always stamps the record's place-id byte. */







extern struct PlayerSlotTable *D_800E54A4;
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
        ((struct RecordRecAtD *)record)->slot = (s8) owner;
    }
    ((struct RecordRecAtD *)record)->place = (s8) place;
}
