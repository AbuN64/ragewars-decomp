#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "COMMON/GLOBALS.H"

/* Tears down the match display: calls func_80245B28_de, stops the objects at D_80145088 and 0x48 bytes
   before it through Items_ResetActorPools and func_804499B0_de, releases resource 0x24 of D_8011FE88 through
   Scene_LoadLevelResources, calls func_8025476C_de with one when func_8025477C_de reports nothing, then calls
   func_80245A10_de, func_80245A20_de with zero and func_80245A30_de. */
extern void Cinema_ReleaseSequenceContext();
extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de();
extern void Cinema_ClearResponse();

extern void func_80245A30_de();

void Menu_ReleaseOptionsScene(void) {
    char *object;

    Cinema_ReleaseSequenceContext();
    object = &D_80145088;
    Items_ResetActorPools(object, 0);
    func_804499B0_de(object - 0x48, 0, 0);
    Scene_LoadLevelResources(&g_world, 0x24, 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    Cinema_ClearResponse();
    func_80245A20_de(0);
    func_80245A30_de();
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
 selection = func_804030E0_de(key);
 if (!func_8025477C_de()) func_8025476C_de(1);
 OvlScene_SetSelection(&g_world, ~selection, 0);
 g->width = width; width = height; g->height = width;
}

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DC2C4[1] = {
    0x3FAAAAA8,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_unresolved_800E8E54[1] = {
    0x3FAAAAA8,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800EDC94[1] = {
    0x3FAAAAA8,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_unresolved_800DD614[1] = {
    0x3FAAAAA8,
};
#endif
