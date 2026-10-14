#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Releases the object D_800E5950 holds through func_802547E4_de, clears D_800E5950 and returns zero. */
extern void *D_800E5950;
extern void func_802547E4_de(void *);

s32 func_804395F8_de(void) {
    func_802547E4_de(D_800E5950);
    D_800E5950 = 0;
    return 0;
}
