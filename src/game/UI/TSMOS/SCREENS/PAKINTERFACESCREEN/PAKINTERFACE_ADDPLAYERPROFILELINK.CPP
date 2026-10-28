#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_FINDEMPTYPLAYERLINK.H"
#include "FRONTEND/PAKINTERFACE_ADDPLAYERPROFILELINK.H"

/* Takes a free slot from PAKInterface_FindEmptyPlayerLink and fills it with two values, marking it set, as
   Frontend_SetPlayerProfileLink does for an index; returns one, or zero when no slot is free. */






s32 PAKInterface_AddPlayerProfileLink(s32 first, s32 second) {
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
