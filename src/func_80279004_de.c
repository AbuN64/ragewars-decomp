#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "types.h"

extern void func_8028D90C_de(void);
extern void func_80402FB4_de(s32, s32);


void func_80279004_de(s32 arg0) {
    if (D_8011FE88.mode == 4) {
        func_8028D90C_de();
        func_80402FB4_de(0, arg0);
    }
}
