#include "span_1000/code_802A25C4.h"
#include "types.h"
s32 func_802A5E08_de();
s32 func_802A5EE0_de(s32);
extern s32 D_800CDBE8;
extern s32 D_80146894;
void func_802A5680_de(s32 arg0) {
    D_800CDBE8 = 0;
    if (D_80146894 == 0) {
        func_802A5E08_de();
        func_802A5EE0_de(arg0);
    }
}
