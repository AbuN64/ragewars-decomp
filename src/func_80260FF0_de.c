#include "span_1000/code_802609CC.h"
/** Advance a record pointer by an indexed number of strides. */
void func_80260FF0_de(unsigned int *record, int index) {
    record[0] += index * record[1];
}
