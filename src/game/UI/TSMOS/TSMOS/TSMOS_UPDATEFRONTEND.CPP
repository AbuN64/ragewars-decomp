#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "RESMGR/STATEPAIR.H"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "FRONTEND/NODE_GETIMAGETEXTURE.H"
#include "FRONTEND/RANDOM_SETUPRANDOMTEAMS.H"
#include "RESMGR/TSMOS_UPDATEFRONTEND.H"
#include "RESMGR/TSMOS_SETIDLETIMER.H"
#include "RESMGR/TSMOS_SHUTDOWNFRONTEND.H"
#include "MATH/N64_ENG.H"
#include "RESMGR/FRAME_HEAP_MARKS.H"
#include "MATH/MENU.H"

extern s32 D_800D2C90;
extern s8 D_8010BBB8;
void Tsmos_UpdateFrontend(void) {
    s32 mode;
    s32 value;
    s32 active;
    s32 state;
    if (D_800D2C98 == 1) {
        ESmem_SwapFrameHeap();
        mode = GetMenuScreenOwner();
        Menu_RouteElementEvent(mode, 0xE08, 0, 0, 0);
        Menu_DrawScreenStack();
        Node_EvictExpiredImages();
        N64Eng_AdvanceFrameCounter();
        mode = GetMenuScreenOwner();
        active = 1;
        value = 0;
        if (mode == 3) {
            goto mode_three;
        }
        if (mode != 0x18) {
            goto mode_inactive;
        }
        value = 20;
        goto mode_done;
mode_three:
        value = 300;
        goto mode_done;
mode_inactive:
        active = 0;
mode_done:
        if ((D_801462C8.counters.transitionActive == 0) && (active == 1) && ((f32)(value * 15) < D_800CDA30_de.value)) {
            Random_SetupRandomTeams();
            Stage_StartConfiguredMatch();
            Tsmos_SetIdleTimer(0.0f);
        }
        D_800CDA30_de.value += D_800D2988;
        state = D_800CDA30_de.state;
        if (state == 1) {
            D_800CBC14--;
            if (D_800CBC14 <= 0) {
                D_800CBC14 = 60;
                D_8010BBB8 = state;
            }
        }
        if (D_800D2C90 == 1) {
            Tsmos_ShutdownFrontend();
        }
    }
}
#if defined(VERSION_EU)
void Tsmos_InitializeEuropeanFrontend(void);
#else
void InitFrontendMenus(void);
#endif
void Join_ResetJoinRequestEntries(void);
void Tsmos_InitFrontendOnce(void) {
    if (D_800D2C98 == 0) {
        Join_ResetJoinRequestEntries();
#if defined(VERSION_EU)
        Tsmos_InitializeEuropeanFrontend();
#else
        InitFrontendMenus();
#endif
    }
}
