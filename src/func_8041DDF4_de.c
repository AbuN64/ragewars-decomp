#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* On event 3 with value 0, calls func_8029973C_de, hands func_8041DB30_de the cursor word the hub
   names unk268 at +0x10C of the menu block D_800E3590 points to, calls func_8041DA5C_de with 0x6E,
   func_8041D6A8_de and func_8041D960_de, and clears the hub's focus word at +0x0EC. Returns zero. */

extern void func_8029973C_de();
extern void func_8041DA5C_de(s32);



s32 func_8041DDF4_de(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3 && value == 0) {
        func_8029973C_de();
        func_8041DB30_de(&D_800E3590->unk268);
        func_8041DA5C_de(0x6E);
        func_8041D6A8_de();
        func_8041D960_de();
        D_800E3590->focus = 0;
    }
    return 0;
}
