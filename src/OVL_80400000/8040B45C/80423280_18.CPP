#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "stddef.h"
#include "TYPES.H"

/* Acts on the mode of the menu held first in the block D_800E4510 points to: in mode 4 it calls
   func_8029973C_de and then either func_80298368_de with the block's word at 0x20, when that is not -1,
   or func_802998A8_de. Returns zero. */




extern s32 func_8041A470_de(void *);

extern void func_8029973C_de();

extern void func_80298368_de(s32);

extern void func_802998A8_de();

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
enum { SHORTCUT_RESET = 0x50, SHORTCUT_SIX = 0x57, SHORTCUT_FIVE = 0x58 };
#elif defined(VERSION_EU_X)
enum { SHORTCUT_RESET = 0x5C, SHORTCUT_SIX = 0x52, SHORTCUT_FIVE = 0x55 };
#endif

/* Handles the menu shortcut codes by selecting an entry and refreshing the screen. */


extern void func_8029973C_de(void),func_80422FC0_de(void),func_8041A430_de(s32,s32);

extern s32 func_80299A08_de(void);

s32 func_804232AC_de(void) {
    extern struct State_func_804232AC_de *D_800E4510;
    switch (func_8041A470_de(D_800E4510->menu)) {
    case 3:
        break;
    case 4:
        func_8029973C_de();
        if (D_800E4510->value != -1) {
            func_80298368_de(D_800E4510->value);
        } else {
            func_802998A8_de();
        }
        break;
    }
    return 0;
}

s32 func_80423328_de(void) {
    extern State_func_80423328_de *D_800E4510;
    s32 temp_v0;
    s32 var_s0;
    func_8029973C_de();
    var_s0 = 1;
    temp_v0 = func_80299A08_de();
    switch(temp_v0) {
    case SHORTCUT_RESET:D_800E4510->unk20=-1;break;
    case SHORTCUT_SIX:D_800E4510->unk20=6;break;
    case SHORTCUT_FIVE:D_800E4510->unk20=5;break;
    default:var_s0=0;break;
    }
    if (var_s0 == 1) {
        func_80422FC0_de();
        func_8041A430_de(D_800E4510->unk0, 2);
    }
    return 0;
}
