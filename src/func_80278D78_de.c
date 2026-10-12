#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80277444.h"
#include "types.h"

extern s32 func_80279204_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);
extern s32 func_8028C26C_de(s8 *arg0, void *arg1, s32 *arg2, s32 *arg3);





void func_80278D78_de(struct Shared_Actor *arg0, s32 arg1, void *arg2) {
    s32 sp20;
    s32 sp24;

    if (!(arg0->weaponFlags & 0x80000)) {
        func_8028C26C_de(&D_8011FE88, arg0, &sp20, &sp24);
        if (sp24 != 0) {
            func_80279204_de(sp20, sp24, 0, arg1 & 0x3FC1FF, arg1 & 0x400000, 0x400000, arg2);
        }
    }
}
