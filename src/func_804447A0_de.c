#include "span_16E000/code_80444030.h"
#include "types.h"

/* Replaces the option byte D_801462E7 with what func_804423BC_de returns for the second argument, that
   byte, 1, 0, 1 and 1, and returns zero. */
extern u8 D_801462E7;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_804447A0_de(void *first, void *second) {
    u8 *option = &D_801462E7;

    *option = func_804423BC_de(second, *option, 1, 0, 1, 1);
    return 0;
}
