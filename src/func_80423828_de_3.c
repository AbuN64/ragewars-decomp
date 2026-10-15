#include "span_16E000/code_80423280.h"
#include "types.h"

/* Releases the object D_800E4510 holds through func_802547E4_de, clears D_800E4510 and returns zero. */
extern void *D_800E4510;
extern void func_802547E4_de(void *);

s32 func_80423B30_eu(void) {
    func_802547E4_de(D_800E4510);
    D_800E4510 = 0;
    return 0;
}
