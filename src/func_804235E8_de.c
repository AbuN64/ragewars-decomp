#include "span_16E000/code_80423280.h"
#include "types.h"

/* Releases the object D_800E4514 holds through func_802547E4_de, calls func_802A2360_de, clears
   D_800E4514 and returns zero. */
extern void *D_800E4514;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();

s32 func_804235E8_de(void) {
    func_802547E4_de(D_800E4514);
    func_802A2360_de();
    D_800E4514 = 0;
    return 0;
}
