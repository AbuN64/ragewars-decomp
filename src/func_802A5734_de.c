#include "span_1000/code_802A25C4.h"
#include "types.h"

s32 func_80279508_de(s32, s32);
s32 func_80279550_de(void *, s32);
s32 func_802A5734_de(void *arg0, s32 arg1) {
    s32 temp_s0;
    temp_s0 = (((struct IntegerState6A94 *) ((s8 *) arg0))->unk_6A90);
    if (temp_s0 != 0) {
        func_80279550_de(arg0 + 0x6A90, temp_s0);
        func_80279508_de(arg1 + 0x40, temp_s0);
    }
    return temp_s0;
}
