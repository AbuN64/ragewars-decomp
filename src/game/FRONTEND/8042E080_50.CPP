#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_47.H"
#include "FRONTEND/8042E080_50.H"

/* Takes a free slot from PAKInterface_FindEmptyPlayerLink and fills it with two values, marking it set, as
   func_8043599C_de does for an index; returns one, or zero when no slot is free. */






s32 func_804352C8_de(s32 first, s32 second) {
    s32 result = 0;
    s32 index = PAKInterface_FindEmptyPlayerLink();
    s32 taken;

    if (index >= 0) {
        taken = 1;
        result = taken;
        D_800E54A4->links[index].player = first;
        D_800E54A4->links[index].entry = second;
        D_800E54A4->links[index].state = result;
    }
    taken = result;
    return taken;
}
