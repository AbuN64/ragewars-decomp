#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"

#if !(defined(VERSION_US))
/* Releases the object g_characterSelectionMenu holds through Cache_FreeMemory, clears g_characterSelectionMenu, calls
   Tsmos_ActivateControllerState and Tsmos_SetModeOneFlag with 2, and returns zero. */
extern void *g_characterSelectionMenu;
extern void Tsmos_ActivateControllerState(void);


s32 Selection_DestroyCharacterSelectionMenu(void) {
    Cache_FreeMemory(g_characterSelectionMenu);
    g_characterSelectionMenu = 0;
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
