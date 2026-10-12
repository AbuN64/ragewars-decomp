#include "span_1000/code_8022A274.h"
#include "types.h"

extern void *D_800D052C[];
extern s16 D_800CB348_de[];






s32 func_8022AB9C_de(void *arg0) {
    s16 *var_v0;
    s32 temp_v1;
    void *temp_v0;

    temp_v0 = D_800D052C[((func_8022AB8C_S1 *)(arg0))->unk62E];
    if (((func_8022AB8C_S1 *)(arg0))->unk594 == 1) {
        var_v0 = ((func_8022AAC4_S2 *)(temp_v0))->unk20;
    } else {
        var_v0 = ((func_8022AAC4_S2 *)(temp_v0))->unk24;
    }
    if (var_v0 != 0) {
        temp_v1 = *var_v0;
    } else {
        temp_v1 = -1;
    }
    if (temp_v1 != -1) {
        return D_800CB348_de[temp_v1];
    }
    return -1;
}
