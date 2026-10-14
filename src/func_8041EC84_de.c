#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Releases the object D_800E39C0 holds through func_802547E4_de, clears D_800E39C0 and returns zero. */
extern void *D_800E39C0;
extern void func_802547E4_de(void *);

s32 func_8041EC84_de(void) {
    func_802547E4_de(D_800E39C0);
    D_800E39C0 = 0;
    return 0;
}
