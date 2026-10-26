#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/LONE/D_800E5558.H"
#include "COMMON/WORLD.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Event callback for screen D_800E5558: on event 1 while Frontend_GetMenuImageState reports the screen in state
   1 it advances the screen through Frontend_DrawMenuImage and Frontend_AdvanceMenuImageTransition, and when that leaves it in
   state 2 it calls MarkMenuEventHandled, clears the pause word D_80146894 (0x180C past the match objects
   at D_80145088), stops those objects and the ones 0x48 bytes before them, releases resource 0x24
   of D_8011FE88, restarts func_8025476C_de when func_8025477C_de reports it idle, and calls
   func_8025E384_de and Frontend_StartConfiguredMatch. Returns zero. */



extern s32 Frontend_GetMenuImageState(void *);
extern void Frontend_DrawMenuImage(void *);
extern void Frontend_AdvanceMenuImageTransition(void *);
extern void MarkMenuEventHandled(void);
extern void Items_ResetActorPools(void *, s32);
extern void Ovlgame_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_8025E384_de(void);
extern void Frontend_StartConfiguredMatch(void);




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
        Items_ResetActorPools((char *)pause - 0x180C, 0);
        Ovlgame_InitializePlayerPool((char *)pause - 0x1854, 0, 0);
        Scene_LoadLevelResources(&g_world, 0x24, 0);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1);
        }
        func_8025E384_de();
        Frontend_StartConfiguredMatch();
    }
    return 0;
}
