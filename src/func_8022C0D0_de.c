#include "span_1000/code_8022BA90.h"
#include "types.h"





extern f32 D_800D2988;
void func_8022C0D0_de(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = (((struct FloatState67C *) ((s8 *) arg0))->unk_678);
    if (temp_f1 > 0.0f) {
        temp_f0 = temp_f1 - D_800D2988;
        (((struct FloatState67C *) ((s8 *) arg0))->unk_678) = temp_f0;
        if (temp_f0 < 0.0f) {
            (((struct FloatState67C *) ((s8 *) arg0))->unk_678) = 0.0f;
        }
    }
}
