#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"
/* Forwards a position and extent to func_80266810_de with zero flags and priority 0x80, but only when
   the first byte of the given object is 1. Adapted from the matched twin func_80267BC8_de with the object
   type test added and the leading flag changed to 0. */





extern void func_80266810_de(unsigned char *, s32, s32, Triple, struct IntPair, s32, s32, s32);

void func_80267B68_de(unsigned char *arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    if (*arg0 == 1) {
        func_80266810_de(arg0, arg1, arg2, arg3, arg6, 0, 0, 0x80);
    }
}
