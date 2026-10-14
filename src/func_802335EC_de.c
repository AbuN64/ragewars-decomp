#include "span_1000/code_8023330C.h"
#include "types.h"
#include "common/draft_fields_func_802335EC_de.h"





extern f32 D_800C3068_de[];


extern s32 D_800CA2D8_de;
extern void func_80274870_de(f32 *, f32, f32);


void func_802335EC_de(void *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    void *temp_s1;
    void *temp_v0;

    temp_s1 = ((struct MeasuredRecAt1D8V3 *)(arg0))->value;
    if (((struct MeasuredRecAt34 *)(arg1))->value == 5) {
        func_80274870_de(arg1 + 0x128, (f32) D_800CA2D8_de * D_800C3058_de, 0.4f);
    } else {
        func_80274870_de(arg1 + 0x128, 0.0f, 0.4f);
    }
    temp_f1 = ((struct MeasuredRecAt128 *)(arg1))->value;
    temp_v0 = ((struct MeasuredRecAt698V1 *)(temp_s1))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3060_de < (-temp_f1 * D_800C305C_de)
              : D_800C3068_de[0] < (temp_f1 * D_800C3064_de))) {
        temp_f2 = ((struct MeasuredRecAt128 *)(arg1))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3068_de[1]);
            return;
        }
        ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3070_de);
        return;
    }
    ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) D_800C3074_de;
}
