#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"
/* Updates the menu item visibility and text for the current configuration. */

s32 func_802934F8_de();                                /* extern */
extern char D_800D35E4;
extern char D_800D35E8;
extern u8 D_801462E5;
extern u8 D_801462E7;

s32 func_804447F0_de(StateRecAt14 *arg0) {
    s32 var_v0;

    if ((func_802934F8_de() != 0) && (D_801462E5 == 0)) {
        arg0->unk8 = arg0->unk8 & 0xFEFFFFFF;
    } else {
        arg0->unk8 = arg0->unk8 | 0x01000000;
    }
    switch (D_801462E7) {                           /* irregular */
    case 0:
        arg0->unk14 = &D_800D35E4;
        break;
    case 1:
        arg0->unk14 = &D_800D35E8;
        break;
    }
    return 0;
}
