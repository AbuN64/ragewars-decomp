#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Stops sound for a menu: calls func_8025E214_de with -1 and func_8025E29C_de with zero, calls
   func_8025E360_de when D_800E63B4 is set, passes D_800E63B0 to func_8025E2D4_de, calls func_80264A0C_de and
   returns what func_80442384_de gives for the three arguments. */
extern s32 D_800E63B4;
extern s32 D_800E63B0;

extern void func_8025E29C_de(s32);
extern void func_8025E360_de();

extern void func_80264A0C_de();
extern s32 func_80442384_de(void *, void *, void *);

s32 func_80444F98_de(void *first, void *second, void *third) {
    func_8025E214_de(-1);
    func_8025E29C_de(0);
    if (D_800E63B4 != 0) {
        func_8025E360_de();
    }
    func_8025E2D4_de(D_800E63B0);
    func_80264A0C_de();
    return func_80442384_de(first, second, third);
}

/* Replaces the option byte D_801462E2 with what func_804423BC_de returns for the second argument, that byte, 8, 0, 0xFF and 0, turning 0xF7 into 0xF8, and returns zero. */

extern u8 D_801462E2;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80445020_de(void *first, void *second) {
    u8 *option = &D_801462E2;
    s32 value = *option;

    value = func_804423BC_de(second, value, 8, 0, 0xFF, 0);
    if (value == 0xF7) {
        value = 0xF8;
    }
    *option = value;
    return 0;
}
