#include "RSP/8026E1F8_5.H"
#include "COMMON/MENU_UI_PROVIDERS.H"
#include "COMMON/WORLD.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"
#include "SYSTEM_2/8025E280.H"
#include "FRONTEND/8043A0B0_12.H"
#include "FRONTEND/SCREEN.H"

/* Event callback for the match setup screen D_800E4518: on event 1 with the screen in state 1 it
   advances it, and once it reaches state 2 either goes back (choice 0: resets the mode, shows the
   item and queues sound 0x259 past D_8015402C) or starts the match (choice 1: picks the arena,
   clears the pause word, then either sets the mode from the settings and active human players or
   stops the match objects and calls Frontend_StartConfiguredMatch). Returns zero. */






extern struct ScreenMenuFinishTabOptionsTransition *D_800E4518;

extern struct LevelActor *D_800E2830;





extern s32 Frontend_GetMenuImageState(struct ScreenMenuFinishTabOptionsTransition *);
extern void Frontend_DrawMenuImage(struct ScreenMenuFinishTabOptionsTransition *);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void Menu_RequestTrackByKey(s32);
extern void MarkMenuEventHandled(void);

extern void Tsmos_RequestFrontendShutdown(void);
extern void Items_ResetActorPools(void *, s32);
extern void Ovlgame_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern void Frontend_StartConfiguredMatch(void);




s32 Menu_FinishTabOptionsTransition(void *item, s32 unused1, s32 event) {
    s32 state;
    s32 humans;
    s32 i;
    Shared_Game *settings;
    u8 *player;
    s32 *pause;

    if (event == 1) {
        state = Frontend_GetMenuImageState(D_800E4518);
        if (state != event) {
            return 0;
        }
        Frontend_DrawMenuImage(D_800E4518);
        Frontend_AdvanceMenuImageTransition(D_800E4518);
        if (Frontend_GetMenuImageState(D_800E4518) != 2) {
            return 0;
        }
        if (D_800E4518->choice != 0 && D_800E4518->choice != state) {
            return 0;
        }
        if (D_800E4518->choice == 0) {
            Frontend_RequestScreenMode(0);
            Frontend_SetWidgetFlag08(item, 1);
            Menu_RequestTrackByKey(D_8015402C + 0x259);
            D_800E2830->resourceHandle = -1;
            D_800E2830->motionIndex = state;
        } else {
            MarkMenuEventHandled();
            if (D_800E4518->arena == 0 && func_8025E2C4_de() != 0) {
                func_8025E2D4_de(GraphU64_NextRandom() % 4 + 0x38);
            } else {
                func_8025E2D4_de(D_800E4518->arena);
            }
            pause = &D_80145088.status[7];
            *pause = 0;
            if (D_800E4518->mode == -1) {
                humans = 0;
                i = 0;
                player = (u8 *)pause - 0x5CC;
                do {
                    if (((Shared_Game *)player)->playerSettings[i].locked == 0 && ((Shared_Game *)player)->playerSettings[i].enabled == 1) {
                        humans++;
                    }
                    i++;
                } while (i < 4);
                settings = &D_801462C8;
                if (settings->reserved580 == 2 && humans >= 2) {
                    Frontend_RequestScreenMode(1);
                } else {
                    Frontend_RequestScreenMode(settings->reserved580);
                }
                Tsmos_RequestFrontendShutdown();
                return 0;
            }
            Items_ResetActorPools((u8 *)pause - 0x180C, 0);
            Ovlgame_InitializePlayerPool((u8 *)pause - 0x1854, 0, 0);
            Scene_LoadLevelResources(&g_world, 0, 0);
            Frontend_StartConfiguredMatch();
        }
    }
    return 0;
}
