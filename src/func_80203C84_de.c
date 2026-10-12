#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"



extern s32 func_80285F58_de(void *arg0, void *arg1);
extern void func_80203C40_de(void *arg0, void *arg1, s32 arg2);
extern void func_80214178_de(void *arg0, void *arg1, s32 arg2);




void func_80203C84_de(void *arg0, WeaponFireState *arg1, s32 arg2) {
    if ((func_80285F58_de(&D_8011FE88, arg0) == 0) &&
        (arg1->variant == 0)) {
        func_80203C40_de(arg0, arg1, arg2);
        func_80214178_de(arg0, arg1, 1);
    }
}
