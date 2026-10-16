#include "span_16E000/code_804196C0.h"
#include "span_C76B0/data.h"

s32 func_8041A05C_de(Record_func_8041A280_de *object) {
    Record_func_8041A280_de *owner = object;
    f32 value, target, result;
    Record_func_8041A280_de *frame;
    if (object->running == 1) {
        switch (object->phase) {
        case 1:
            frame = object->frame;
            target = D_800DD420;
            value = frame->progressX;
            if (value != target) {
                if (value < target) {
                    result = value + object->scaleX;
                    if (result < 0.0f) result = 0.0f;
                    else if (target < result) result = target;
                    frame->progressX = result;
                } else frame->progressX = value - D_800E1454;
            } else {
                value = frame->field_24;
                if (value != target) {
                    if (value < target) {
                        frame->field_24 = value + object->scaleY;
                        object = object->frame;
                        if (target < object->field_24) object->field_24 = D_800DD428;
                    } else {
                        frame->field_24 = target;
                        object->phase = 3;
                    }
                }
            }
            break;
        case 2:
            frame = object->frame;
            target = D_800DD42C;
            value = frame->field_24;
            if (target < value - target) {
                if (target < value) {
                    result = value - object->scaleY;
                    if (result < target) result = target;
                    else if (D_800E1460 < result) result = D_800E1460;
                    frame->field_24 = result;
                } else frame->field_24 = value + D_800DD434;
            } else {
                value = frame->progressX;
                if (value != 0.0f) {
                    if (0.0f < value) {
                        result = value - object->scaleX;
                        if (result < 0.0f) result = 0.0f;
                        else if (D_800DD438 < result) result = D_800DD438;
                        frame->progressX = result;
                    } else frame->progressX = value + D_800E146C;
                } else owner->phase = 4;
            }
            break;
        case 3: break;
        }
    }
    return 0;
}
