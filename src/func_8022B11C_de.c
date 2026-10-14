#include "span_1000/code_8022AE90.h"
#include "types.h"





void func_8022B11C_de(void *arg0, s32 arg1) {
    u16 temp_v0;
    u16 var_v1;
    temp_v0 = (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) + arg1;
    var_v1 = temp_v0;
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = temp_v0;
    if ((u32) (var_v1 & 0xFFFF) >= 0x65U) {
        var_v1 = 0x64;
    }
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = var_v1;
}
