#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E54A4 holds through Cache_FreeMemory, clears D_800E54A4, calls
   Tsmos_ActivateControllerState and Tsmos_SetTimerState with 1, and returns zero. */
extern void Tsmos_ActivateControllerState();
extern void Tsmos_SetTimerState(s32);

s32 Frontend_DestroyPakProfileScreen(void) {
    Cache_FreeMemory(D_800E54A4);
    D_800E54A4 = 0;
    Tsmos_ActivateControllerState();
    Tsmos_SetTimerState(1);
    return 0;
}
