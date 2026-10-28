#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Releases the object D_800E5550 holds through Cache_FreeMemory, clears D_800E5550, calls
   Tsmos_SetModeOneFlag with 2 and func_8026495C_de, and returns zero. */
extern void *D_800E5550;

extern void Control_RestoreControllerSetup(void);

s32 Frontend_DestroyPauseMenu(void) {
    Cache_FreeMemory(D_800E5550);
    D_800E5550 = 0;
    Tsmos_SetModeOneFlag(2);
    Control_RestoreControllerSetup();
    return 0;
}
