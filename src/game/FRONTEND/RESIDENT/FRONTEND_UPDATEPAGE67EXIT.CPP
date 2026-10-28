#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "COMMON/SCREEN.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/LONE/D_800E5558.H"
#include "COMMON/WORLD.H"
#include "FRONTEND/MENUIMAGE.H"

/* 8042E080_89.CPP */
/* Calls Tsmos_SetModeOneFlag with 2 and returns zero. */

s32 Frontend_ClearPage67ModeFlag(void) {
    Tsmos_SetModeOneFlag(2);
    return 0;
}

/* 8042E080_90.CPP */
/* Event callback for screen D_800E5558: on event 1 while Frontend_GetMenuImageState reports the screen in state
   1 it advances the screen through Frontend_DrawMenuImage and Frontend_AdvanceMenuImageTransition, and when that leaves it in
   state 2 it calls MarkMenuEventHandled, clears the pause word D_80146894 (0x180C past the match objects
   at D_80145088), stops those objects and the ones 0x48 bytes before them, releases resource 0x24
   of D_8011FE88, restarts Cache_SetResourceActivityState when Cache_GetResourceActivityState reports it idle, and calls
   SoundElement_DisableMusicGainOverride and Stage_StartConfiguredMatch. Returns zero. */

extern s32 Frontend_GetMenuImageState(void *);
extern void Frontend_DrawMenuImage(void *);
extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 Cache_GetResourceActivityState(void);
extern void Cache_SetResourceActivityState(unsigned int);
extern void SoundElement_DisableMusicGainOverride(void);
extern void Stage_StartConfiguredMatch(void);

s32 Frontend_UpdatePage67Exit(s32 unused0, s32 unused1, s32 event) {
    s32 *pause;
    if (event == 1) {
        if (Frontend_GetMenuImageState(D_800E5558) != 1) {
            return 0;
        }
        Frontend_DrawMenuImage(D_800E5558);
        Frontend_AdvanceMenuImageTransition(D_800E5558);
        if (Frontend_GetMenuImageState(D_800E5558) != 2) {
            return 0;
        }
        MarkMenuEventHandled();
        pause = &D_80145088.status[7];
        *pause = 0;
        Pools_ResetActorPools((char *)pause - 0x180C, 0);
        Player_InitializePlayerPool((char *)pause - 0x1854, 0, 0);
        Scene_LoadLevelResources(&g_world, 0x24, 0);
        if (Cache_GetResourceActivityState() == 0) {
            Cache_SetResourceActivityState(1);
        }
        SoundElement_DisableMusicGainOverride();
        Stage_StartConfiguredMatch();
    }
    return 0;
}
