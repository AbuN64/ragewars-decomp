#include "span_1000/code_80268160.h"
#include "common/types_1dc8418c21db.h"
#include "TYPES.H"

extern s32 func_80255CB8_de(void *, s32);

s32 func_80255CB8_de(void *, s32);

void *func_80268C1C_de(void *arg0, void *arg1) {
    extern void func_80255ED8_de(void *, s32);
    void *temp_s0;

    temp_s0 = ((IntrusiveList *)arg0)[1].head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&((IntrusiveList *)arg0)[1], (s32)temp_s0);
        func_80255CB8_de(arg0, (s32)temp_s0);
        ((RangeNode *)temp_s0)->radius = arg1;
        ((RangeNode *)temp_s0)->active = 0;
    }
    return temp_s0;
}

void func_80268C7C_de(void *a, s32 b) {
    s32 func_80255ED8_de();
    (((struct Limit *) ((s8 *) b))->limit) = 0;
    func_80255ED8_de();
    func_80255CB8_de(a + 0x14, b);
}
