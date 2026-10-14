#include "span_1000/code_80299DB4.h"
#include "types.h"





extern Callback *D_8014D0B0;
extern s32 func_80299958_de(void);
extern void func_802995D4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80299E80_de(Event_func_8029A558_de *arg0);
extern void func_8029A324_de(Event_func_8029A558_de *arg0);

void func_8029A558_de(Event_func_8029A558_de *arg0) {
    s32 temp_s0;

    if (D_8014D0B0->callback != 0 && D_8014D0B0->callback() == 1) {
        return;
    }

    switch (arg0->f4) {
    case 0:
        temp_s0 = ((u16)arg0->f0 << 16) | (u16)arg0->f2;
        func_802995D4_de(func_80299958_de(), 0x11, temp_s0, arg0->fC, arg0->f6);
        break;
    case 1:
        if (arg0->f0 == 4) {
            arg0->f0 = 3;
            func_80299E80_de(arg0);
        }
        break;
    case 2:
    case 3:
    case 4:
        if (arg0->f0 == 4) {
            arg0->f0 = 3;
            func_8029A324_de(arg0);
        }
        break;
    }
}
