#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "COMMON/GLOBALS.H"

/* Tears down the match display: calls func_80245B28_de, stops the objects at D_80145088 and 0x48 bytes
   before it through Items_ResetActorPools and Ovlgame_InitializePlayerPool, releases resource 0x24 of D_8011FE88 through
   Scene_LoadLevelResources, calls Cache_SetResourceActivityState with one when func_8025477C_de reports nothing, then calls
   func_80245A10_de, Cinema_SetLoopMode with zero and Cinema_ResetViewport. */

void Menu_ReleaseOptionsScene(void) {
    char *object;

    Cinema_ReleaseSequenceContext();
    object = &D_80145088;
    Items_ResetActorPools(object, 0);
    Ovlgame_InitializePlayerPool(object - 0x48, 0, 0);
    Scene_LoadLevelResources(&g_world, 0x24, 0);
    if (func_8025477C_de() == 0) {
        Cache_SetResourceActivityState(1);
    }
    Cinema_ClearResponse();
    Cinema_SetLoopMode(0);
    Cinema_ResetViewport();
}

void Menu_SetOptionsSceneSelection(int key) {
 GlobalsMenuSetOptionsSceneSelection *g = &D_80140FE8_de;
 GameplayCamera *o = g->camera;
 float width = 45.0f;
 float height = D_800DD610[1];
 StateMenuSetOptionsSceneSelection *state = D_800E2830;
 int selection;
 o->fovY = width; o->aspect = height;
 o->viewWidth = state->a; o->viewHeight = state->b; o->viewLeft = state->c; o->viewTop = state->d;
 selection = Track_RequestTrackByKey(key);
 if (!func_8025477C_de()) Cache_SetResourceActivityState(1);
 OvlScene_SetSelection(&g_world, ~selection, 0);
 g->width = width; width = height; g->height = width;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int rodata_unresolved_800DC2C4[1] = {
    0x3FAAAAA8,
};
#endif
