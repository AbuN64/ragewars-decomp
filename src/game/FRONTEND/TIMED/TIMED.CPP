#include "COMMON/SCREEN.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "SYSTEM_2/8025E280.H"

/* Handles the menu message Smos_GetFocusedElementId reports after MarkMenuEventHandled: 0x3D5 waits 1 through
   SmXlate_SwitchScreen; 0x3D3 plays cue 0x34 through func_8025E2D4_de when func_8025E2C4_de reports sound on,
   resets through Tsmos_DeactivateControllerState, sets the timer at 0x1C of screen D_800E5554 by setting
   D_801462D5 through jtbl_800DDEF0 (10, 15 or 10, and 20 for any other setting) and shows the
   screen through Frontend_StartMenuImageTransition. Returns zero. */
extern MenuRules *D_800E5554;
extern void SmXlate_SwitchScreen(s32);

extern void Tsmos_DeactivateControllerState(void);
extern void Frontend_StartMenuImageTransition(MenuRules *);

#if defined(VERSION_DE)
enum { MENU_80436224_979 = 973, MENU_80436224_981 = 975 };
#elif defined(VERSION_EU_X)
enum { MENU_80436224_979 = 983, MENU_80436224_981 = 985 };
#else
enum { MENU_80436224_979 = 979, MENU_80436224_981 = 981 };
#endif

s32 Frontend_UpdateTimedScreen(void) {
    MarkMenuEventHandled();
    switch (Smos_GetFocusedElementId()) {
    case MENU_80436224_981:
        SmXlate_SwitchScreen(1);
        return 0;
    case MENU_80436224_979:
        if (func_8025E2C4_de() != 0) {
            func_8025E2D4_de(0x34);
        }
        Tsmos_DeactivateControllerState();
        switch (D_801462C8.controllerMode) {
        case 1:
            D_800E5554->locked = 10;
            break;
        case 2:
            D_800E5554->locked = 15;
            break;
        case 3:
        case 4:
            D_800E5554->locked = 10;
            break;
        case 0:
        default:
            D_800E5554->locked = 20;
            break;
        }
        Frontend_StartMenuImageTransition(D_800E5554);
        return 0;
    }
    return 0;
}

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E9744[3] = {
    0x00000015, 0x00000001, 0x00000004,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE584[3] = {
    0x01785822, 0x19600002, 0x01735822,
};
#endif
