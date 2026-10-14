#include "span_16E000/code_80444EC0.h"
#include "types.h"
#include "stddef.h"
/* Adjusts the volume in steps of eight and starts a sound preview when no preview is playing. */
extern s32 func_8025E2C4_de(void),func_804423BC_de(void *,s32,s32,s32,s32,s32);

extern u8 D_801462E0[];
s32 func_80445160_de(void *unused, void *arg1) {
    s32 var_a1;
    var_a1 = D_801462E0[0];
    var_a1 = func_804423BC_de(arg1, var_a1, 8, 0, 0xFF, 0);
    if(var_a1==0xF7)var_a1=0xF8;
    D_801462E0[0]=var_a1;
    if (func_8025E2C4_de() <= 0) {
        func_8025E2D4_de(1);
    }
    return 0;
}
