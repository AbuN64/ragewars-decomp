#include "COMMON/S1_6.H"
#include "COMMON/LONE/D_800E5558.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E5558 holds through Cache_FreeMemory, clears D_800E5558, calls Tsmos_SetModeOneFlag with 2
   and returns zero. */


s32 Frontend_FreePage67Screen(void) {
    Cache_FreeMemory(D_800E5558);
    D_800E5558 = 0;
    Tsmos_SetModeOneFlag(2);
    return 0;
}
