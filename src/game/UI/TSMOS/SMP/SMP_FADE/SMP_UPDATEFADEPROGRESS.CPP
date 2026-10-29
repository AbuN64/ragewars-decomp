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
            target = g_fadeProgressTarget;
            value = frame->progressX;
            if (value != target) {
                if (value < target) {
                    result = value + object->scaleX;
                    if (result < 0.0f) result = 0.0f;
                    else if (target < result) result = target;
                    frame->progressX = result;
                } else frame->progressX = value - g_fadeProgressRetreatStep;
            } else {
                value = frame->field_24;
                if (value != target) {
                    if (value < target) {
                        frame->field_24 = value + object->scaleY;
                        object = object->frame;
                        if (target < object->field_24) object->field_24 = g_fadeProgressMinimum;
                    } else {
                        frame->field_24 = target;
                        object->phase = 3;
                    }
                }
            }
            break;
        case 2:
            frame = object->frame;
            target = g_fadeProgressAlternateTarget;
            value = frame->field_24;
            if (target < value - target) {
                if (target < value) {
                    result = value - object->scaleY;
                    if (result < target) result = target;
                    else if (g_fadeProgressHorizontalMaximum < result) result = g_fadeProgressHorizontalMaximum;
                    frame->field_24 = result;
                } else frame->field_24 = value + g_fadeProgressAdvanceStep;
            } else {
                value = frame->progressX;
                if (value != 0.0f) {
                    if (0.0f < value) {
                        result = value - object->scaleX;
                        if (result < 0.0f) result = 0.0f;
                        else if (g_fadeProgressMaximum < result) result = g_fadeProgressMaximum;
                        frame->progressX = result;
                    } else frame->progressX = value + g_fadeProgressHorizontalAdvanceStep;
                } else owner->phase = 4;
            }
            break;
        case 3: break;
        }
    }
    return 0;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
const unsigned int g_fadeProgressConstants[8] = {
    0x3F800000, 0x3C23D70A, 0x3F99999A, 0x3D4CCCCD, 0x3F800000, 0x3C23D70A, 0x3F800000, 0x3C23D70A,
};
#endif
