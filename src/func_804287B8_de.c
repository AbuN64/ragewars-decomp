#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Releases the object D_800E4690 holds through func_802547E4_de, calls func_802A2360_de, clears D_800E4690, calls
   func_80245B28_de and returns zero. */
extern void *D_800E4690;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();
extern void func_80245B28_de();

s32 func_804287B8_de(void) {
    func_802547E4_de(D_800E4690);
    func_802A2360_de();
    D_800E4690 = 0;
    func_80245B28_de();
    return 0;
}
