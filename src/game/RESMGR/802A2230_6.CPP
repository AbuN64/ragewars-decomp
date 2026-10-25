#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "RESMGR/802A2230.H"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "FRONTEND/8040B45C_36.H"
#include "FRONTEND/8042E080_23.H"
#include "RESMGR/802A2230_6.H"
#include "RESMGR/802A2230_8.H"
#include "RESMGR/802A2230_9.H"
#include "RESMGR/802A23A4_10.H"
#include "RESMGR/802A23A4_7.H"
#include "MATH/80299ECC.H"

extern s32 D_800D2C90;
extern s8 D_8010BBB8;
extern void Frontend_SetupRandomTeams(void);
void func_802A2090_de(void) {
    s32 mode;
    s32 value;
    s32 active;
    s32 state;
    if (D_800D2C98 == 1) {
        func_802A17C4_de();
        mode = GetMenuScreenOwner();
        func_802995D4_de(mode, 0xE08, 0, 0, 0);
        func_80298FE8_de();
        func_80410448_de();
        func_802A1944_de();
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
            Frontend_SetupRandomTeams();
            func_8042DEA0_de();
            func_802A2400_de(0.0f);
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
            func_802A2434_de();
        }
    }
}
#if defined(VERSION_DE)
s32 func_802A2224_de();
#elif defined(VERSION_EU)
s32 func_802A2344_eu();
#elif defined(VERSION_EU_X)
s32 func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
s32 InitFrontendMenus();
#endif
s32 func_8041EA70_de();
void Resmgr_InitFrontendOnce(void) {
    if (D_800D2C98 == 0) {
        func_8041EA70_de();
#if defined(VERSION_DE)
        func_802A2224_de();
#elif defined(VERSION_EU)
        func_802A2344_eu();
#elif defined(VERSION_EU_X)
        func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
        InitFrontendMenus();
#endif
    }
}
