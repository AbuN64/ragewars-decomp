#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Releases the object D_800E5430 holds through func_802547E4_de, clears D_800E5430 and returns zero. */
extern void *D_800E5430;
extern void func_802547E4_de(void *);

s32 func_8042DAC8_de(void) {
    func_802547E4_de(D_800E5430);
    D_800E5430 = 0;
    return 0;
}
