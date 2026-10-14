#include "span_1000/code_802636D0.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Ensures the session is initialised once (calling func_80293268_de and func_80263C24_de and, the first
   time, latching D_8014ADA0 when D_8014AD9C is set, clearing D_8014AD94 and setting D_80153784),
   then latches D_80153784 to one when D_800E28C8 is not -1 and both func_802645D0_de and
   func_80406178_de(arg0, D_800E28C8, 0) accept it, returning D_80153784. */
extern s32 D_80146D60;
extern s32 D_8014AD9C;
extern s32 D_8014ADA0;
extern s32 D_8014AD94;
extern s32 D_80153784;
extern s32 D_800E28C8;
extern s32 D_8011FAC0;

extern void func_80293268_de(void *arg0);

extern s32 func_802645D0_de(s32);
extern s32 func_80406178_de(s32, s32, s32);

s32 func_80409E10_de(s32 arg0) {
    if (D_80146D60 == 0) {
        func_80293268_de(&D_8011FAC0);
        func_80263C24_de();
        if (D_80146D60 == 0) {
            if (D_8014AD9C != 0) {
                D_8014ADA0 = 1;
            }
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    if (D_80153784 == 0) {
        if ((D_800E28C8 != -1) && (func_802645D0_de(D_800E28C8) != 0) && (func_80406178_de(arg0, D_800E28C8, 0) != 0)) {
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    return D_80153784;
}
