#include "COMMON/S1_5.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/S1_6.H"

#if defined(VERSION_EU_X)
enum { START_MATCH = 0x43, RETURN_MENU = 0x3E, WAIT_SHORT = 0x42, WAIT_LONG = 0x40 };
#else
enum { START_MATCH = 0x40, RETURN_MENU = 0x3C, WAIT_SHORT = 0x41, WAIT_LONG = 0x3E };
#endif
#include "TYPES.H"
#include "MENU_2/804221A0_13.H"

/* Handles the menu message func_80299A08_de reports after MarkMenuEventHandled: 0x40 clears D_80146894 and
   calls Tsmos_RequestFrontendShutdown and func_8025E384_de; 0x3C clears D_80146894 and calls Menu_RequestOptionsScreen22; 0x41 and
   0x3E wait 0x1F and 0x20 through func_80298368_de. Returns zero. */
extern void MarkMenuEventHandled(void);
extern s32 func_80299A08_de(void);
extern void Tsmos_RequestFrontendShutdown(void);
extern void func_8025E384_de(void);

extern void func_80298368_de(s32);

s32 Frontend_ActivatePauseMenuAction(void) {
    s32 time;

    MarkMenuEventHandled();
    switch (func_80299A08_de()) {
    case START_MATCH:
        D_8011FAC0.clockPaused = 0;
        Tsmos_RequestFrontendShutdown();
        func_8025E384_de();
        return 0;
    case RETURN_MENU:
        D_8011FAC0.clockPaused = 0;
        Menu_RequestOptionsScreen22();
        return 0;
    case WAIT_SHORT:
        time = 0x1F;
        goto wait;
    case WAIT_LONG:
        time = 0x20;
    wait:
        func_80298368_de(time);
        return 0;
    }
    return 0;
}
