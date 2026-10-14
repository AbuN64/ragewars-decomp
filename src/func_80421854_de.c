#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Releases the object D_800E4400 holds through func_802547E4_de, clears D_800E4400 and returns zero. */
extern void *D_800E4400;
extern void func_802547E4_de(void *);

s32 func_80421854_de(void) {
    func_802547E4_de(D_800E4400);
    D_800E4400 = 0;
    return 0;
}
