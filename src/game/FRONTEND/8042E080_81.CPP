#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E5554 holds through Cache_FreeMemory, clears D_800E5554, calls func_802A23C4_de with 2
   and returns zero. */
extern void *D_800E5554;


s32 func_80435EBC_de(void) {
    Cache_FreeMemory(D_800E5554);
    D_800E5554 = 0;
    func_802A23C4_de(2);
    return 0;
}
