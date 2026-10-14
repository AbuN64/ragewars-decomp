#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023B9A0.h"







void func_8023CB90_de(void *arg0, void *arg1) {
    void *temp_v0;

    ((Field_void_4 *)(arg1))->value = 0;
    *(void **)arg1 = *(void **)arg0;
    temp_v0 = *(void **)arg0;
    if (temp_v0 != 0) {
        ((Field_void_4 *)(temp_v0))->value = arg1;
    }
    *(void **)arg0 = arg1;
    if (((Field_void_4 *)(arg0))->value == 0) {
        ((Field_void_4 *)(arg0))->value = arg1;
    }
}
