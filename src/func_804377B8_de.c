#include "span_16E000/code_804366C4.h"
#include "types.h"

/* Releases the object D_800E5784 holds through func_802547E4_de, clears D_800E5784 and returns zero. */
extern void *D_800E5784;
extern void func_802547E4_de(void *);

s32 func_804377B8_de(void) {
    func_802547E4_de(D_800E5784);
    D_800E5784 = 0;
    return 0;
}
