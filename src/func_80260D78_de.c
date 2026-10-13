#include "span_1000/code_802609CC.h"

/** Initialize a packed array and its decoding range. */
void func_80260D78_de(void *arg0, int arg1, Func802608ECResult t, int arg5) {
    DecodeArray *array = arg0;
    array->base = arg1;
    array->range = t;
    array->count = arg5;
}
