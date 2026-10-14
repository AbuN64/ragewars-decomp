#include "span_1000/code_80243A80.h"
#include "types.h"

extern int func_80245784_de(void);




extern func_802456FC_S1 *D_800E2830;
extern f32 D_800C37D0_de;

void func_8024570C_de(void) {
    if (func_80245784_de() != 0 && func_80245764_de() != 0 && D_800E2830->unk60 == 0) {
        f32 temp = D_800C37D0_de;
        D_800E2830->unk60 = 1;
        D_800E2830->unk64 = temp;
    }
}
