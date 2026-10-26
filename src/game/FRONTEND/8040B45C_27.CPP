#include "COMMON/WIDGETRECAT1A.H"
#include "FRONTEND/8040B45C_29.H"
#include "MATH/80299ECC.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_EU)
/* Slider widget message handler: clamps the current value into range, then dispatches on the
   message to get/set the value, range, step or user word, adjusts by one step, or posts the new
   value to the parent. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"



extern void MarkMenuEventHandled(void);

s32 Frontend_HandleSliderMessage(Slider *slider, s32 msg, s32 arg2, s32 arg3) {
    s32 result;
    Slider *widget = slider;

    if (widget->value < widget->min) {
        widget->value = widget->min;
    }
    if (widget->value > widget->max) {
        widget->value = widget->max;
    }

    switch (msg) {
        case 5:
        case 8:
            if (arg3 != 0) {
                s32 v = widget->value + widget->step;
                s32 hi = widget->max;
                widget->value = v;
                if (hi < v) {
                    widget->value = hi;
                }
            }
            goto post;

        case 6:
        case 7:
            if (arg3 != 0) {
                s32 v = widget->value - widget->step;
                s32 lo = widget->min;
                widget->value = v;
                if (v < lo) {
                    widget->value = lo;
                }
            }
            goto post;

        case 0x1000:
            result = widget->value;
            goto end;

        case 0x1002:
            result = widget->min;
            goto end;

        case 0x1003:
            result = widget->max;
            goto end;

        case 0x1006:
            result = widget->step;
            goto end;

        case 0x1008:
            result = widget->flags;
            goto end;

        case 0x1005:
            if (arg2 < widget->min) {
                goto post;
            }
            if (widget->max < arg2) {
                goto post;
            }
            widget->value = arg2;
            goto post;

        case 0x1004:
            if (widget->min < arg2) {
                widget->max = arg2;
            }
            if (arg3 < widget->max) {
                widget->min = arg3;
            }
            goto post;

        case 0x1007:
            if (arg2 < (widget->max - widget->min)) {
                widget->step = arg2;
            }
            goto post;

        case 0x1009:
            widget->flags = arg2;
            goto post;

        default:
            result = 0;
            goto end;
    }

post:
    Frontend_UpdateSliderGeometry((Slider *)widget);
    func_802995D4_de(GetMenuScreenOwner(), 0x100A, slider->parentId, widget->value, 0);
    MarkMenuEventHandled();
    result = 0;

end:
    return result;
}
#endif
