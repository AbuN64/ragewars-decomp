#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "ACHIEVE/80437C30_2.H"

/* Calls InitFrontendMenus and Tsmos_DeactivateControllerState, then SmXlate_SwitchScreen with 0x12. */
#if defined(VERSION_EU)
extern void Tsmos_InitializeEuropeanFrontend();
#elif defined(VERSION_EU_X)
extern void func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
extern void InitFrontendMenus();
#else
extern void func_802A2224_de();
#endif

extern void Tsmos_DeactivateControllerState();

void func_804389C4_de(void) {
    
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
InitFrontendMenus
#else
func_802A2224_de
#endif
();
    Tsmos_DeactivateControllerState();
    SmXlate_SwitchScreen(0x12);
}

void func_804389F0_de(void) {
    s32 next;
    CGameStatus *layout = &D_801462C8.counters;
    layout->m_bCTFOn = 0;
    layout->m_bFragTagOn = 0;
    if (layout->humanWon == 1 && D_8015402C >= 35) {
        switch (D_801462C8.controllerMode) {
        case 4:
            next = 3;
            break;
        default:
            next = 3;
            break;
        case 1:
            next = 7;
            break;
        case 3:
            next = 3;
            break;
        }
    } else {
        next = 10;
    }
    SmXlate_SwitchScreen(next);
}
