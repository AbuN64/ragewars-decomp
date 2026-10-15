#include "span_1000/code_80254CE4.h"
#include "types.h"
#include "common/draft_fields_func_80255630_de.h"
#include "stddef.h"
s32 func_80255630_de(s8 *arg0, void *arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_v0_3;
    u32 temp_a2_2;
    u32 temp_a2_4;
    u32 temp_v1_2;
    u32 var_v0;
    void *temp_a0;
    void *temp_a2_3;
    void *temp_t0;
    void *temp_t1;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_3;
    void *var_a3;
    temp_a2 = (arg2 + 0x2F) & ~0xF;
    temp_v1 = ((struct MeasuredRecAt8V2 *)(arg0))->value;
    if (temp_v1 != NULL) {
        var_a3 = temp_v1;
        while (((struct MeasuredRecAt4V4 *)(var_a3))->value != 0) {
            temp_v1_2 = ((struct MeasuredRecAt4V4 *)(var_a3))->value;
            if (temp_v1_2 >= (u32) arg1) {
                break;
            }
            var_a3 = (void *) temp_v1_2;
        }
        temp_v0 = var_a3 + ((struct MeasuredRecAt10V3 *)(var_a3))->value;
        temp_t1 = temp_v0 + ((struct MeasuredRecAt14V3 *)(var_a3))->value;
        temp_v1_3 = arg1 - 0x20;
        temp_t0 = temp_v1_3 + temp_a2;
        if ((u32) temp_v1_3 >= (u32) temp_v0) {
            if ((u32) temp_t1 >= (u32) temp_t0) {
                s32 temp_v0_2 = temp_t1 - temp_t0;
                ((struct MeasuredRecAt10V3 *)(temp_v1_3))->value = temp_a2;
                ((struct MeasuredRecAt14V3 *)(temp_v1_3))->value = temp_v0_2;
                if (temp_v0_2 != 0) {
                    ((struct MeasuredRecAt4V3 *)(arg1))[-1].value = var_a3;
                    temp_a2_2 = ((struct MeasuredRecAt4V4 *)(var_a3))->value;
                    ((struct MeasuredRecAt4V4 *)(temp_v1_3))->value = temp_a2_2;
                    if (((struct MeasuredRecAt4V4 *)(var_a3))->value != 0) {
                        *(void **) temp_a2_2 = temp_v1_3;
                    }
                    ((struct MeasuredRecAt4V4 *)(var_a3))->value = (u32) temp_v1_3;
                    if (((struct MeasuredRecAtCV2 *)(arg0))->value == var_a3) {
                        ((struct MeasuredRecAtCV2 *)(arg0))->value = temp_v1_3;
                    }
                } else {
                    ((struct MeasuredRecAt4V3 *)(arg1))[-1].value = NULL;
                    ((struct MeasuredRecAt4V4 *)(temp_v1_3))->value = 0U;
                }
                temp_v0_3 = temp_v1_3 - (var_a3 + ((struct MeasuredRecAt10V3 *)(var_a3))->value);
                ((struct MeasuredRecAt14V3 *)(var_a3))->value = temp_v0_3;
                if (temp_v0_3 == 0) {
                    temp_a2_3 = ((struct MeasuredRecAt0V2 *)(var_a3))->value;
                    if (temp_a2_3 != NULL) {
                        ((struct MeasuredRecAt4V4 *)(temp_a2_3))->value = ((struct MeasuredRecAt4V4 *)(var_a3))->value;
                    }
                    temp_a2_4 = ((struct MeasuredRecAt4V4 *)(var_a3))->value;
                    if (temp_a2_4 != 0) {
                        *(void **) temp_a2_4 = ((struct MeasuredRecAt0V2 *)(var_a3))->value;
                    }
                    if (((struct MeasuredRecAt8V2 *)(arg0))->value == var_a3) {
                        ((struct MeasuredRecAt8V2 *)(arg0))->value = ((struct MeasuredRecAt4V2 *)(var_a3))->value;
                    }
                    if (((struct MeasuredRecAtCV2 *)(arg0))->value == var_a3) {
                        var_v0 = ((struct MeasuredRecAt4V4 *)(var_a3))->value;
                        if (var_v0 == 0) {
                            var_v0 = (u32) ((struct MeasuredRecAt0V2 *)(var_a3))->value;
                        }
                        ((struct MeasuredRecAtCV2 *)(arg0))->value = (void *) var_v0;
                    }
                    ((struct MeasuredRecAt0V2 *)(var_a3))->value = NULL;
                    ((struct MeasuredRecAt4V4 *)(var_a3))->value = 0U;
                }
                ((struct MeasuredRecAt8V2 *)(temp_v1_3))->value = var_a3;
                temp_a0 = ((struct MeasuredRecAtCV2 *)(var_a3))->value;
                ((struct MeasuredRecAtCV2 *)(temp_v1_3))->value = temp_a0;
                if (((struct MeasuredRecAtCV2 *)(var_a3))->value != NULL) {
                    ((struct MeasuredRecAt8V2 *)(temp_a0))->value = temp_v1_3;
                }
                ((struct MeasuredRecAtCV2 *)(var_a3))->value = temp_v1_3;
                return (s32) arg1;
            }
        }
    }
    return 0;
}
