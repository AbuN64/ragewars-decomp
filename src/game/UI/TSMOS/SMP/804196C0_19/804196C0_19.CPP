#include "COMMON/ANIMATION.H"
#include "COMMON/TRIPLE.H"
#include "include_asm.h"

s32 Smp_UpdateFadeProgress(MenuFadeWidget *object) {
    MenuFadeWidget *owner = object;
    f32 value, target, result;
    MenuFadeWidget *frame;
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

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8041A05C_E2050_us_rev1[8] = {
    0x3F800000, 0x3C23D70A, 0x3F99999A, 0x3D4CCCCD, 0x3F800000, 0x3C23D70A, 0x3F800000, 0x3C23D70A,
};
#endif
