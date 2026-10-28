#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Releases the object D_800E5554 holds through Cache_FreeMemory, clears D_800E5554, calls Tsmos_SetModeOneFlag with 2
   and returns zero. */
extern void *D_800E5554;


s32 Timed_DestroyPauseConfirmation(void) {
    Cache_FreeMemory(D_800E5554);
    D_800E5554 = 0;
    Tsmos_SetModeOneFlag(2);
    return 0;
}
