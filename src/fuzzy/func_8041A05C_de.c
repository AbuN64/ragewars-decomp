#include "span_16E000/code_804196C0.h"
#include "span_C76B0/data.h"
extern f32 D_800E1454;
extern f32 D_800E1460;
extern f32 D_800E146C;

static inline f32 bound(f32 value, f32 low, f32 high) {
    if (value < low) value = low;
    else if (high < value) value = high;
    return value;
}

s32 func_8041A05C_de(Record_func_8041A280_de *object) {
    if (object->running == 1) {
        switch (object->phase) {
        case 3: break;
        case 1:
            if (object->frame->progressX != D_800DD420) {
                if (object->frame->progressX < D_800DD420)
                    { f32 value = object->frame->progressX + object->scaleX;
                    if (value < 0.0f) value = 0.0f;
                    else if (D_800DD420 < value) value = D_800DD420;
                    object->frame->progressX = value;
                }
                else object->frame->progressX -= D_800E1454;
            } else if (object->frame->field_24 != D_800DD420) {
                if (object->frame->field_24 < D_800DD420) {
                    object->frame->field_24 += object->scaleY;
                    if (D_800DD420 < object->frame->field_24) object->frame->field_24 = D_800DD428;
                } else {
                    object->frame->field_24 = D_800DD420;
                    object->phase = 3;
                }
            }
            break;
        case 2:
            if (object->frame->field_24 - D_800DD42C > D_800DD42C) {
                if (D_800DD42C < object->frame->field_24)
                    { f32 value = object->frame->field_24 - object->scaleY;
                    if (value < D_800DD42C) value = D_800DD42C;
                    else if (D_800E1460 < value) value = D_800E1460;
                    object->frame->field_24 = value;
                }
                else object->frame->field_24 += D_800DD434;
            } else if (object->frame->progressX != 0.0f) {
                if (0.0f < object->frame->progressX)
                    { f32 value = object->frame->progressX - object->scaleX;
                    if (value < 0.0f) value = 0.0f;
                    else if (D_800DD438 < value) value = D_800DD438;
                    object->frame->progressX = value;
                }
                else object->frame->progressX += D_800E146C;
            } else object->phase = 4;
            break;
        }
    }
    return 0;
}
