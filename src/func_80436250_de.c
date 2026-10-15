#include "span_16E000/code_80435CE4.h"
#include "types.h"

/* Releases the object D_800E5558 holds through func_802547E4_de, clears D_800E5558, calls func_802A23C4_de with 2
   and returns zero. */
extern void *D_800E5558;
extern void func_802547E4_de(void *);


s32 func_80436250_de(void) {
    func_802547E4_de(D_800E5558);
    D_800E5558 = 0;
    func_802A23C4_de(2);
    return 0;
}
