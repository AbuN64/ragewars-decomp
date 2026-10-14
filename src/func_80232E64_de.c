#include "span_1000/code_80231F5C.h"
#include "types.h"
#include "common/draft_fields_func_80232E64_de.h"




extern f32 D_800C3030_de[];


extern f32 D_800D2988;

extern s32 func_802301F4_de(void *, void *);



void func_80232E64_de(void *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    void *temp_s1;
    void *temp_v0;

    temp_s1 = ((struct MeasuredRecAt1D8V2 *)(arg0))->value;
    ((struct MeasuredRecAt124 *)(arg1))->value += (((struct Measured_func_80232E64_de_1121ff480e8c *)(arg1))->value * D_800D2988) * 2.0f;
    temp_f1 = ((struct Measured_func_80232E64_de_1121ff480e8c *)(arg1))->value;
    temp_v0 = ((struct MeasuredRecAt698V2 *)(temp_s1))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3028_de < (-temp_f1 * *(&D_800C3020_de + 1))
              : D_800C3030_de[0] < (temp_f1 * D_800C302C_de))) {
        temp_f2 = ((struct Measured_func_80232E64_de_1121ff480e8c *)(arg1))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3030_de[1]);
        } else {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3038_de);
        }
    } else {
        ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) D_800C303C_de;
    }

    if (((struct MeasuredRecAtCB *)(arg1))->value != 0) {
        ((struct MeasuredRecAt13CV1 *)(arg1))->value = 2;
        if (func_802301F4_de(arg0, arg1) != 0) {
            ((struct MeasuredRecAt13CV1 *)(arg1))->value = 1;
            func_8022B00C_de(temp_s1);
        }
    }
}
