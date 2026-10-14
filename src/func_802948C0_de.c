#include "span_1000/code_802944E8.h"
#include "types.h"

extern void func_80293A20_de(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_800CD780;
extern s32 D_8010B194_de;
extern s32 D_80142898;



void func_802948C0_de(s32 arg0) {
    s32 *p;

    if (D_800CD780 != 0) {
        func_80293A20_de(arg0, 1, 1);
        return;
    }
    p = &D_8010B194_de;
    if ((*p & 0x1000) && (D_80142898 == 0)) {
        D_80142898 = 1;
        *p = 0;
        D_80142CB4 = D_800C54DC_de;
    }
}
