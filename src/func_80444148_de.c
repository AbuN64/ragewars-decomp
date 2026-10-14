#include "types.h"
#include "span_16E000/code_80444030.h"
#include "common/draft_fields_func_80444148_de.h"
#include "common/draft_fields_func_8044417C_de.h"

/* Measured global: loaded pointer followed by indexed byte reads. */
extern u8 *D_800D3C48;

s32 func_80444148_de(s32 arg0) {
    u8 *object = (u8 *)arg0;
    s32 temp_v0;
    s32 var_a1;
    u8 temp_v0_2;
    void *temp_v1;

    var_a1 = 0;
    do {
        temp_v1 = object + var_a1;
        temp_v0_2 = *(D_800D3C48 + var_a1);
        var_a1 += 1;
        ((struct MeasuredRecAt84V1 *)(temp_v1))->value = temp_v0_2;
        temp_v0 = var_a1 < 8;
    } while (temp_v0 != 0);
    return temp_v0;
}

extern int D_800D3C4C;

s32 func_8044417C_de(s32 arg0) {
    s32 temp_v0;
    s32 var_a1;
    u8 temp_v0_2;
    u8 *temp_v1;

    var_a1 = 0;
    do {
        temp_v1 = (u8 *)(u32)arg0 + var_a1;
        temp_v0_2 = *((u8 *)(u32)D_800D3C4C + var_a1);
        var_a1 += 1;
        ((struct MeasuredRecAt84V2 *)(temp_v1))->value = temp_v0_2;
        temp_v0 = var_a1 < 8;
    } while (temp_v0 != 0);
    return temp_v0;
}

extern int D_800D3C50;

s32 func_804441B0_de(s32 arg0) {
    s32 temp_v0;
    s32 var_a1;
    u8 temp_v0_2;
    u8 *temp_v1;

    var_a1 = 0;
    do {
        temp_v1 = (u8 *)(u32)arg0 + var_a1;
        temp_v0_2 = *((u8 *)(u32)D_800D3C50 + var_a1);
        var_a1 += 1;
        ((struct MeasuredRecAt84V1 *)temp_v1)->value = temp_v0_2;
        temp_v0 = var_a1 < 8;
    } while (temp_v0 != 0);
    return temp_v0;
}
