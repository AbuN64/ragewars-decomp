#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Releases the object D_800E5830 holds through func_802547E4_de, clears D_800E5830 and returns zero. */
extern void *D_800E5830;
extern void func_802547E4_de(void *);

s32 func_80438AA4_de(void) {
    func_802547E4_de(D_800E5830);
    D_800E5830 = 0;
    return 0;
}
