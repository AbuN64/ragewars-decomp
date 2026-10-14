#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023B9A0.h"





void func_8023CB60_de(void *arg0, void *arg1) {
    void *temp_v0;

    *(void **)arg1 = 0;
    ((Field_void_4 *)(arg1))->value = ((Field_void_4 *)(arg0))->value;
    temp_v0 = ((Field_void_4 *)(arg0))->value;
    if (temp_v0 != 0) {
        *(void **)temp_v0 = arg1;
    }
    ((Field_void_4 *)(arg0))->value = arg1;
    if (*(void **)arg0 == 0) {
        *(void **)arg0 = arg1;
    }
}
