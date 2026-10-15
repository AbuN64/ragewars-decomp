#include "span_16E000/code_80435CE4.h"
#include "types.h"

/* On event 3 with value 0xD, clears D_80146894 and calls func_802A230C_de and func_8025E384_de. Returns
   zero. */
extern s32 D_80146894;
extern void func_802A230C_de();
extern void func_8025E384_de();

s32 func_80435C70_de(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3) {
        if (value != 0xD) {
            return 0;
        }
        D_80146894 = 0;
        func_802A230C_de();
        func_8025E384_de();
    }
    return 0;
}
