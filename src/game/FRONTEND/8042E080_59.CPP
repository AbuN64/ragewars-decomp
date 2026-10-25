#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_59.H"

/* Copies the block's chosen 400-byte record for the place at slot arg0 into D_80102B00[arg0]: when
   the place is claimed (id != -1), copies the owning player's chosen slot into the record and marks
   the record's owned-slot byte, then always stamps the record's place-id byte. */







extern char D_80102B00[];




void func_804356BC_de(s32 linkIndex) {
    char *record;
    s32 place;
    s32 owner;

    place = D_800E54A4->links[linkIndex].player;
    owner = D_800E54A4->links[linkIndex].entry;
    record = &D_80102B00[linkIndex * 400];
    if (place != -1) {
        Resmgr_CopyBytes(record, D_800E54A4->players[place].slots[owner], 400);
        ((struct RecordRecAtD *)record)->slot = (s8) owner;
    }
    ((struct RecordRecAtD *)record)->place = (s8) place;
}
