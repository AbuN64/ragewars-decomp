#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* Calls func_8029973C_de, sets the hub words unk216 and unk220 at +0x0D8 and +0x0DC of the menu block
   D_800E3590 points to to 5 and 4, and returns zero. */

extern void func_8029973C_de();

s32 func_8041DE5C_de(void) {
    func_8029973C_de();
    D_800E3590->unk216 = 5;
    D_800E3590->unk220 = 4;
    return 0;
}
