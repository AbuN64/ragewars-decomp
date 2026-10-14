#include "span_1000/code_802BE0D0.h"
#include "span_1000/code_802B369C.h"
#include "types.h"

typedef s32 (*FuncPtr)(void *);

extern void func_802B53E0_de(void *arg0, void *a, void *b, s32 c);
extern s32 func_802B0340_de(s32, s32, void *, s32, s32);

extern char D_002BE0D0;
extern char D_002BEAA4;




void func_802B43A4_de(void *arg0, FuncPtr arg1, s32 arg2) {
    func_802B53E0_de(arg0, &D_002BE0D0, &D_002BEAA4, 0);
    ((ALLoadFilter48_2 *)arg0)->state = func_802B0340_de(0, 0, arg2, 1, 0x20);
    ((ALLoadFilter48_2 *)arg0)->lstate = func_802B0340_de(0, 0, arg2, 1, 0x20);
    ((ALLoadFilter48_2 *)arg0)->dma = arg1(&((ALLoadFilter48_2 *)arg0)->dmaState);
    ((ALLoadFilter48_2 *)arg0)->lastsam = 0;
    ((ALLoadFilter48_2 *)arg0)->first = 1;
    ((ALLoadFilter48_2 *)arg0)->memin = 0;
}
