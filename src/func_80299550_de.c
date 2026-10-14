#include "span_1000/code_80297CD0.h"
#include "types.h"
typedef s32 (*FuncPtr)(s32, s32, s32, s32);

extern s32 D_8014D080;

void func_80299550_de(FuncPtr arg0) {
    *(FuncPtr *)D_8014D080 = arg0;
    if (arg0 != 0) {
        arg0(0xE04, 0, 0, 0);
    }
}
