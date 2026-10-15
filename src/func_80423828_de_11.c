#include "span_16E000/code_80423280.h"
#include "types.h"

/* Releases the object D_800E4600 holds through func_802547E4_de, clears D_800E4600 and returns zero. */
extern void *D_800E4600;
extern void func_802547E4_de(void *);

s32 func_8042418C_de(void) {
    func_802547E4_de(D_800E4600);
    D_800E4600 = 0;
    return 0;
}
