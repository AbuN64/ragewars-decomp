#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "COMMON/GLOBALS.H"

/* Tears down the match display: calls Cinema_ReleaseSequenceContext_FrontendHandletaboptionsshortcut, stops the objects at g_frontendScreenStatus and 0x48 bytes
   before it through Pools_ResetActorPools and Player_InitializePlayerPool, releases resource 0x24 of g_world_AchieveUpdateresultsscreen through
   Scene_LoadLevelResources, calls Cache_SetResourceActivityState with one when Cache_GetResourceActivityState reports nothing, then calls
   Cinema_ClearResponse_Optionscene, Cinema_SetLoopMode with zero and Cinema_ResetViewport. */

void Menu_ReleaseOptionsScene(void) {
    char *object;

    Cinema_ReleaseSequenceContext();
    object = &g_frontendScreenStatus;
    Pools_ResetActorPools(object, 0);
    Player_InitializePlayerPool(object - (u32)&((Shared_MenuData *)0)->object, 0, 0);
    Scene_LoadLevelResources(&g_world, 36, 0);
    if (Cache_GetResourceActivityState() == 0) {
        Cache_SetResourceActivityState(1);
    }
    Cinema_ClearResponse();
    Cinema_SetLoopMode(0);
    Cinema_ResetViewport();
}

void Menu_SetOptionsSceneSelection(int key) {
 GlobalsMenuSetOptionsSceneSelection *g = &g_gameplayCameraList;
 GameplayCamera *o = g->camera;
 float width = 45.0f;
 float height = g_cameraAspectRatios[1];
 StateMenuSetOptionsSceneSelection *state = g_cinemaSequenceState;
 int selection;
 o->fovY = width; o->aspect = height;
 o->viewWidth = state->a; o->viewHeight = state->b; o->viewLeft = state->c; o->viewTop = state->d;
 selection = Track_RequestTrackByKey(key);
 if (!Cache_GetResourceActivityState()) Cache_SetResourceActivityState(1);
 Scene_SetSelection(&g_world, ~selection, 0);
 g->width = width; width = height; g->height = width;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int k_OptionsceneEncodedWords[1] = {
    0x3FAAAAA8,
};
#endif
