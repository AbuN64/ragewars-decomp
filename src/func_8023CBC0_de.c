#include "span_1000/code_8023B9A0.h"
#include "types.h"



extern Node_func_8023CBC0_de D_80103F88;

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
