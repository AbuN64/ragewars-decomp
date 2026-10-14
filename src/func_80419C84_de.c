#include "types.h"
#include "span_16E000/code_804196C0.h"
#include "stddef.h"
s32 func_802744D4_de(void);
/* Initializes a flicker effect and randomizes each element's intensity. */
void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_v1;
    s32 offset;
    int temp;
    arg0->unk44 = 0;
    arg0->unk74 = 0;
    if (arg1 > 0) {
        arg0->unk48 = arg1;
    } else {
        arg0->unk48 = (s32) (func_802744D4_de() % 5 + 1);
    }
    for (var_s1 = 0; var_s1 < arg0->unk48; var_s1++) {
        arg0->unk60[var_s1] = (s32) (func_802744D4_de() % 3 + 1);
        var_v1 = (offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) < 0 ? 0 : ((offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = func_802744D4_de() % 40 + 30, arg0->unk80 - offset));
        arg0->unk4C[var_s1] = var_v1;
    }
}
