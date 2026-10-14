#include "span_1000/code_802A0AC4.h"
#include "types.h"

typedef s32 (*FuncPtr)(s32, u8 *, s32);
extern FuncPtr D_800CD92C_de;

s32 func_802A0FCC_de(s32 arg0) {
    u8 sp10;
    s32 result;

    if (D_800CD92C_de(arg0, &sp10, 1) != 0) {
        result = sp10;
    } else {
        result = -1;
    }
    return result;
}
