#include "COMMON/WORLD.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"

/* 804221A0_8.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_80422228_de_padding_188228[8] = { 0x8F, 0xBF, 0x00, 0x18, 0x00, 0x00, 0x10, 0x21 };
#endif

/* 804221A0_2.CPP */
/* Sets up the match display: calls Menu_ConfigureOptionsCamera, starts the objects at D_80145088 and 0x48 bytes
   before it through Items_ResetActorPools and Ovlgame_InitializePlayerPool, loads the resource Track_RequestTrackByKey names for
   0x27D into D_8011FE88 through func_8044D528_de, and calls Cache_SetResourceActivityState with one when func_8025477C_de
   reports nothing. */

extern void Items_ResetActorPools(void *, s32);
extern void Ovlgame_InitializePlayerPool(void *, s32, s32);
extern s32 Track_RequestTrackByKey(s32);
extern void OvlScene_SetSelection(void *, s32, s32);
extern s32 func_8025477C_de();
extern void Cache_SetResourceActivityState(s32);

void Menu_InitializeOptionsScene(void) {
    char *object;

    Menu_ConfigureOptionsCamera();
    object = &D_80145088;
    Items_ResetActorPools(object, 1);
    Ovlgame_InitializePlayerPool(object - 0x48, 1, 0);
    OvlScene_SetSelection(&g_world, ~Track_RequestTrackByKey(0x27D), 0);
    if (func_8025477C_de() == 0) {
        Cache_SetResourceActivityState(1);
    }
}

/* Calls Cinema_SetLoopMode with 1, func_80245A00_de with the pooled constant D_800E1648 and
   Cinema_SetViewport with 0x43, 0x4F, 0x12 and 0x80. */

void Menu_ConfigureOptionsCamera(void) {
    Cinema_SetLoopMode(1);
    Cinema_SetResponse((45.0f));
    Cinema_SetViewport(0x43, 0x4F, 0x12, 0x80);
}
