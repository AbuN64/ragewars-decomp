#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"

int func_8028FEB8_de(int *arg0) {
    return arg0[0] * arg0[1] + 8;
}

void func_8028FED0_de(void *arg0, void **arg1, s32 *arg2) {
    *arg1 = arg0;
    *arg2 = ((((struct Shape_typemap_13 *) ((s8 *) arg0))->field_0) * (((struct Shape_typemap_13 *) ((s8 *) arg0))->field_4)) + 8;
}
