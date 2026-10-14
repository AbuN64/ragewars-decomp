#include "span_1000/code_8020AF9C.h"
/** Return an indexed record from the table referenced by the input. */
void *func_8020C994_de(void *table, int index) {
    char *base = *(char **)table;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}
