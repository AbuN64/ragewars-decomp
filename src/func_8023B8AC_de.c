#include "span_1000/code_8023A284.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

void *func_8023B8AC_de(struct IntegerState8A4 *arg0) {
    void *temp_s0;

    temp_s0 = arg0->unk_8A0.head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&arg0->unk_8A0, temp_s0);
        func_80255D14_de(&arg0->unk_8B4, temp_s0);
    }
    return temp_s0;
}
