#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"
#include "SYSTEM_2/8025E280.H"
extern s32 Pak_AdjustValue(void *,s32,s32,s32,s32,s32);

#if !(defined(VERSION_US))
/* Adjusts the volume in steps of eight and starts a sound preview when no preview is playing. */

s32 func_80445160_de(void *unused, void *arg1) {
    s32 var_a1;
    var_a1 = D_801462E0[0];
    var_a1 = Pak_AdjustValue(arg1, var_a1, 8, 0, 0xFF, 0);
    if(var_a1==0xF7)var_a1=0xF8;
    D_801462E0[0]=var_a1;
    if (func_8025E2C4_de() <= 0) {
        func_8025E2D4_de(1);
    }
    return 0;
}
#endif
