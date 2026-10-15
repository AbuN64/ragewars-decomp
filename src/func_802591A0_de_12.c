#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802591C0.h"





void func_80259AF0_de(void **arg0, void *arg1) {
    *(void **)arg1 = *arg0;
    ((Field_void_4 *)(arg1))->value = arg0;
    ((Field_void_4 *)((*arg0)))->value = arg1;
    *arg0 = arg1;
}
