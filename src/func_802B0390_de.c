#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"





void func_802B0390_de(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    temp_v1 = 0x10 - (arg1 & 0xF);
    if (temp_v1 != 0x10) {
        (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0) = (s32) (arg1 + temp_v1);
    } else {
        (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0) = arg1;
    }
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_8) = arg2;
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_C) = 0;
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_4) = (s32) (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0);
}
