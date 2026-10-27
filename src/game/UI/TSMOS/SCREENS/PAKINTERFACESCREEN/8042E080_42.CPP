#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_42.H"

/* Stores its argument in D_800E54A0. */


void PAKInterface_SetScreenPhase(s32 value) {
    D_800E54A0 = value;
}
