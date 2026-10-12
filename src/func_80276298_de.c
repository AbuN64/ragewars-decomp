#include "span_1000/code_80275E44.h"
#include "types.h"




void func_80276298_de(struct ModelTreeNode *arg0, u16 arg1) {
    u16 temp_s0;
    u16 temp_v1;
    void *temp_a0;

    temp_s0 = arg0->modelId;
    if (temp_s0 == arg1) {
        temp_v1 = arg0->flags;
        if (temp_v1 & 4) {
            temp_a0 = arg0->branches[0];
            arg0->flags = temp_v1 & 0xFFFB;
            if (temp_a0 != 0) {
                func_80276298_de(temp_a0, temp_s0);
            }
            temp_a0 = arg0->branches[1];
            if (temp_a0 != 0) {
                func_80276298_de(temp_a0, temp_s0);
            }
            temp_a0 = arg0->branches[2];
            if (temp_a0 != 0) {
                func_80276298_de(temp_a0, temp_s0);
            }
        }
    }
}
