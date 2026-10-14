#include "span_1000/code_802636D0.h"
#include "types.h"

extern s32 func_802BB2A0_de(s32 arg0, s32 arg1, s32 arg2);
extern u32 func_802BAD80_de(void *object);
extern s32 D_8010FBC0;
extern s32 D_800CBC1C;

s32 func_802644FC_de(s32 arg0) {
    s32 result;

    result = func_802BB2A0_de((s32)&D_8010FBC0, 0, arg0) == 0;
    if (result != 0) {
        D_800CBC1C = func_802BAD80_de(0);
    }
    return result;
}
