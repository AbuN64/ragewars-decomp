#include "span_1000/code_8026AC38.h"
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"



extern s32 D_8011064C;
extern s32 D_8010C564;
extern s32 D_80110640;
extern s32 D_80111310;
extern s32 D_80111318[];
extern char D_801157D8;
extern void *func_8028FDB4_de(void *, s32);

extern void func_80253670_de(s32, s32);

void func_8026DC24_de(void **a, s32 b, s32 c, void *d, s32 e, s32 f) {
    s32 temp_v1;
    s32 temp_v0;
    s32 var_s0;
    char *temp_v1_2;
    void *temp_a0;
    s32 *countp;
    s32 count;
    s32 *queue_countp;

    temp_a0 = *a;
    var_s0 = e;
    if (var_s0 == 0) {
        var_s0 = (s32)func_8028FDB4_de(temp_a0, 0);
    }
    if ((D_8011064C != (s32)a) || (D_8010C564 != f) || (D_80110640 == 0x20)) {
        func_8026BC60_de();
        if (D_80111310 != 0x100) {
            func_80253670_de(0, (s32)a);
            countp = &D_80111310;
            count = *countp;
            D_80111318[count] = (s32)a;
            *countp = count + 1;
            goto block_7;
        }
    } else {
block_7:
        D_8011064C = (s32)a;
        D_8010C564 = f;
        queue_countp = &D_80110640;
        temp_v0 = *queue_countp;
        temp_v1 = temp_v0 * 0x10;
        temp_v0 += 1;
        *queue_countp = temp_v0;
        temp_v1_2 = temp_v1 + &D_801157D8;
        ((struct MeasuredRecAt0V1 *)(temp_v1_2))->value = b;
        ((struct MeasuredRecAtCV1 *)(temp_v1_2))->value = c;
        ((struct MeasuredRecAt4V1 *)(temp_v1_2))->value = d;
        ((struct MeasuredRecAt8V1 *)(temp_v1_2))->value = var_s0;
    }
}
