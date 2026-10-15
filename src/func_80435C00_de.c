#include "span_16E000/code_80435CE4.h"
#include "types.h"

/* Releases the object D_800E5550 holds through func_802547E4_de, clears D_800E5550, calls
   func_802A23C4_de with 2 and func_8026495C_de, and returns zero. */
extern void *D_800E5550;
extern void func_802547E4_de(void *);

extern void func_8026495C_de();

s32 func_80435C00_de(void) {
    func_802547E4_de(D_800E5550);
    D_800E5550 = 0;
    func_802A23C4_de(2);
    func_8026495C_de();
    return 0;
}
