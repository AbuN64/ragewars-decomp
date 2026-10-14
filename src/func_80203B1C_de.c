#include "span_1000/code_802022E0.h"
#include "types.h"

extern s32 func_802034A4_de(void *arg0);
extern s32 func_80214178_de(void *, void *, s32);

void func_80203B1C_de(void *arg0, void *arg1) {
    if (func_802034A4_de(arg0) == 0) {
        func_80214178_de(arg0, arg1, 0x3E);
    }
}
