#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Releases the object D_800E59E0 holds through func_802547E4_de, clears D_800E59E0, calls
   func_802A2360_de and func_802A23C4_de with 2, and returns zero. */
extern void *D_800E59E0;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();


s32 func_8043BB70_de(void) {
    func_802547E4_de(D_800E59E0);
    D_800E59E0 = 0;
    func_802A2360_de();
    func_802A23C4_de(2);
    return 0;
}
