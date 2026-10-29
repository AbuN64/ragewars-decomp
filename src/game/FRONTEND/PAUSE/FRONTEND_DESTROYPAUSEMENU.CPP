#include "COMMON/RESERVED_SHARED_DECLARATIONS.H"
#include "TYPES.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Releases the object g_pauseMenuState holds through Cache_FreeMemory, clears g_pauseMenuState, calls
   Tsmos_SetModeOneFlag with 2 and func_8026495C_de, and returns zero. */
extern void *g_pauseMenuState;

extern void Control_RestoreControllerSetup(void);

s32 Frontend_DestroyPauseMenu(void) {
    Cache_FreeMemory(g_pauseMenuState);
    g_pauseMenuState = 0;
    Tsmos_SetModeOneFlag(2);
    Control_RestoreControllerSetup();
    return 0;
}
