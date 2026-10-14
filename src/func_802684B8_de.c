#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80268160.h"
#include "types.h"




void func_802684B8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 temp = *(u8 *)arg0;
    if (temp == 1) {
        s32 *p = &arg3;
        ((Field_s32_2E0 *)(arg0))->value = ((Field_s32_2E0 *)(arg0))->value | (temp << p[3]);
    }
}
