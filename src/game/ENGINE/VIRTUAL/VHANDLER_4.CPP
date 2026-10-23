#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "TYPES.H"
#include "ENGINE/VIRTUAL/VHANDLER_4.H"

extern Node_func_8023CBC0_de D_80103F88;

void func_8023CB60_de(Field_void_4 *arg0, void *arg1) {
    void *temp_v0;

    *(void **)arg1 = 0;
    ((Field_void_4 *)(arg1))->value = arg0->value;
    temp_v0 = arg0->value;
    if (temp_v0 != 0) {
        *(void **)temp_v0 = arg1;
    }
    arg0->value = arg1;
    if (*(void **)arg0 == 0) {
        *(void **)arg0 = arg1;
    }
}

void func_8023CB90_de(Field_void_4 *arg0, Field_void_4 *arg1) {
    void *temp_v0;

    arg1->value = 0;
    *(void **)arg1 = *(void **)arg0;
    temp_v0 = *(void **)arg0;
    if (temp_v0 != 0) {
        ((Field_void_4 *)(temp_v0))->value = arg1;
    }
    *(void **)arg0 = arg1;
    if (arg0->value == 0) {
        arg0->value = arg1;
    }
}

Node_func_8023CBC0_de *func_8023CBC0_de(u32 arg0) {
    Node_func_8023CBC0_de *var_v1;
    u16 temp_a1;

    var_v1 = &D_80103F88;
    if (&D_80103F88 != 0) {
    loop_1:
        temp_a1 = var_v1->f4;
        if ((arg0 < temp_a1) || (arg0 >= (u32)(temp_a1 + var_v1->f6))) {
            var_v1 = var_v1->next;
            if (var_v1 != 0) {
                goto loop_1;
            }
        }
    }
    return var_v1;
}
