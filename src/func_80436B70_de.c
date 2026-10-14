#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804366C4.h"
#include "types.h"

/* Acts on the mode of the menu held first in the block D_800E5690 points to: in mode 4 it calls
   func_8029973C_de and then either func_80298368_de with the block's word at 0x20, when that is not -1,
   or func_802998A8_de. Returns zero. */


extern struct State_func_804232AC_de *D_800E5690;
extern s32 func_8041A470_de(void *);
extern void func_8029973C_de();
extern void func_80298368_de(s32);
extern void func_802998A8_de();

s32 func_80436B70_de(void) {
    switch (func_8041A470_de(D_800E5690->menu)) {
    case 3:
        break;
    case 4:
        func_8029973C_de();
        if (D_800E5690->value != -1) {
            func_80298368_de(D_800E5690->value);
        } else {
            func_802998A8_de();
        }
        break;
    }
    return 0;
}
