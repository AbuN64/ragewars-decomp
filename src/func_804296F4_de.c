#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Releases the object D_800E4EF0 holds through func_802547E4_de, clears D_800E4EF0 and returns zero. */
extern void *D_800E4EF0;
extern void func_802547E4_de(void *);

s32 func_804296F4_de(void) {
    func_802547E4_de(D_800E4EF0);
    D_800E4EF0 = 0;
    return 0;
}
