#include "span_1000/code_80299DB4.h"
#include "types.h"
s32 func_8025305C_de(s32);
s32 func_802A0748_de(s32, s32, s32);
extern s32 D_8014D0B0;
void func_8029AA78_de(void) {
    s32 temp_v0;
    temp_v0 = func_8025305C_de(0xC44);
    D_8014D0B0 = temp_v0;
    func_802A0748_de(temp_v0, 0, 0xC44);
}
