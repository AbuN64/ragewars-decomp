#include "COMMON/SCREEN.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "FRONTEND/MENUIMAGE.H"
#include "FRONTEND/SCREEN.H"

/* Event callback for screen D_800E5554: on event 1 while Frontend_GetMenuImageState reports the screen in state 1 it advances the screen through Frontend_DrawMenuImage and Frontend_AdvanceMenuImageTransition, and when that leaves it in state 2 it calls func_8040C428_de(0) and MarkMenuEventHandled, clears the pause word D_80146894 (0x180C past the match objects at D_80145088), stops those objects and the ones 0x48 bytes before them, releases resource 0x24 of D_8011FE88, restarts Cache_SetResourceActivityState when Cache_GetResourceActivityState reports it idle, stores 8 at 0x17F0 past the match objects, passes the screen's word at 0x1C to SmXlate_SwitchScreen and calls SoundElement_DisableMusicGainOverride, returning zero. Adapted from Frontend_UpdatePage67Exit with the screen D_800E5558 changed to D_800E5554, a func_8040C428_de(0) call added, and the trailing Stage_StartConfiguredMatch call replaced by the store of 8 and the SmXlate_SwitchScreen call before SoundElement_DisableMusicGainOverride. */

extern MenuRules *D_800E5554;


extern s32 Frontend_GetMenuImageState(void *);
extern void Frontend_DrawMenuImage(void *);
extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 Cache_GetResourceActivityState(void);
extern void Cache_SetResourceActivityState(unsigned int);
extern void SmXlate_SwitchScreen(void *);
extern void SoundElement_DisableMusicGainOverride(void);

s32 Timed_FinishPauseConfirmationTransition(s32 unused0, s32 unused1, s32 event) {
    s32 *pause;
    if (event == 1) {
        if (Frontend_GetMenuImageState(D_800E5554) != 1) {
            return 0;
        }
        Frontend_DrawMenuImage(D_800E5554);
        Frontend_AdvanceMenuImageTransition(D_800E5554);
        if (Frontend_GetMenuImageState(D_800E5554) != 2) {
            return 0;
        }
        Frontend_RequestScreenMode(0);
        MarkMenuEventHandled();
        pause = &D_80145088.status[7];
        *pause = 0;
        Pools_ResetActorPools((char *)pause - 0x180C, 0);
        Player_InitializePlayerPool((char *)pause - 0x1854, 0, 0);
        Scene_LoadLevelResources(&g_world, 0x24, 0);
        if (Cache_GetResourceActivityState() == 0) {
            Cache_SetResourceActivityState(1);
        }
        pause[-7] = 8;
        SmXlate_SwitchScreen((void *)D_800E5554->locked);
        SoundElement_DisableMusicGainOverride();
    }
    return 0;
}
