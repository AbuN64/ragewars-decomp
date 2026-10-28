#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"

#if defined(VERSION_US)
/* Releases the object D_800E42D0 holds through Cache_FreeMemory, clears D_800E42D0, calls
   Tsmos_ActivateControllerState and Tsmos_SetModeOneFlag with 2, and returns zero. */
extern void *D_800E42D0;
extern void Tsmos_ActivateControllerState();


s32 Selection_DestroyUsCharacterSelectionMenu(void) {
    Cache_FreeMemory(D_800E42D0);
    D_800E42D0 = 0;
    Tsmos_ActivateControllerState();
    Tsmos_SetModeOneFlag(2);
    return 0;
}

/* Calls Tsmos_SetModeOneFlag with 1 and SoundElement_PlayFlatSound with 0xE78, and returns zero. */


s32 Selection_ActivateCharacterSelectionMode(void) {
    Tsmos_SetModeOneFlag(1);
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#endif
