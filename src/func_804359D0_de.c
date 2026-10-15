#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Releases the object D_800E54A4 holds through func_802547E4_de, clears D_800E54A4, calls
   func_802A2360_de and func_802A2418_de with 1, and returns zero. */
extern void *D_800E54A4;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();
extern void func_802A2418_de(s32);

s32 func_804359D0_de(void) {
    func_802547E4_de(D_800E54A4);
    D_800E54A4 = 0;
    func_802A2360_de();
    func_802A2418_de(1);
    return 0;
}
