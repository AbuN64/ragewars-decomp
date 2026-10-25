#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "stddef.h"
#include "TYPES.H"

/* Acts on the mode of the menu held first in the block g_optionsPage points to: in mode 4 it calls
   MarkMenuEventHandled and then either func_80298368_de with the block's word at 0x20, when that is not -1,
   or func_802998A8_de. Returns zero. */




extern struct State_func_804232AC_de *g_optionsPage;

extern s32 func_8041A470_de(void *);

extern void MarkMenuEventHandled();

extern void func_80298368_de(s32);

extern void func_802998A8_de();

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
enum { SHORTCUT_RESET = 0x50, SHORTCUT_SIX = 0x57, SHORTCUT_FIVE = 0x58 };
#elif defined(VERSION_EU_X)
enum { SHORTCUT_RESET = 0x5C, SHORTCUT_SIX = 0x52, SHORTCUT_FIVE = 0x55 };
#endif

/* Handles the menu shortcut codes by selecting an entry and refreshing the screen. */


extern void MarkMenuEventHandled(void),func_80422FC0_de(void),func_8041A430_de(void *,s32);

extern s32 func_80299A08_de(void);

s32 func_804232AC_de(void) {
    switch (func_8041A470_de(g_optionsPage->menu)) {
    case 3:
        break;
    case 4:
        MarkMenuEventHandled();
        if (g_optionsPage->value != -1) {
            func_80298368_de(g_optionsPage->value);
        } else {
            func_802998A8_de();
        }
        break;
    }
    return 0;
}

s32 func_80423328_de(void) {
    s32 temp_v0;
    s32 var_s0;
    MarkMenuEventHandled();
    var_s0 = 1;
    temp_v0 = func_80299A08_de();
    switch(temp_v0) {
    case SHORTCUT_RESET:g_optionsPage->value=-1;break;
    case SHORTCUT_SIX:g_optionsPage->value=6;break;
    case SHORTCUT_FIVE:g_optionsPage->value=5;break;
    default:var_s0=0;break;
    }
    if (var_s0 == 1) {
        func_80422FC0_de();
        func_8041A430_de(g_optionsPage->menu, 2);
    }
    return 0;
}
