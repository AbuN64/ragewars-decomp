#include "span_164000/code_80405DB4.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"

/* Releases the object D_800E42D0 holds through func_802547E4_de, clears D_800E42D0, calls
   func_802A2360_de and func_802A23C4_de with 2, and returns zero. */
extern void *D_800E42D0;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();


s32 func_80420B80_us(void) {
    func_802547E4_de(D_800E42D0);
    D_800E42D0 = 0;
    func_802A2360_de();
    func_802A23C4_de(2);
    return 0;
}

/* Calls func_802A23C4_de with 1 and func_8025DF34_de with 0xE78, and returns zero. */

extern void func_8025DF34_de(s32);

s32 func_80420B50_de(void) {
    func_802A23C4_de(1);
    func_8025DF34_de(0xE78);
    return 0;
}
