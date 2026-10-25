#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/WIDGETRECAT1A.H"
#include "FRONTEND/8040B45C_29.H"
#include "MATH/80299ECC.H"
extern s32 GetMenuScreenOwner(void);
extern void MarkMenuEventHandled(void);

/* Clamp the slider and handle range, value, step and parent notifications. */
s32 func_8040C780_us(Slider *slider, s32 msg, s32 arg2, s32 arg3) {
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
    func_8040C950_de(widget);
    func_802995D4_de(GetMenuScreenOwner(), 0x100A, slider->parentId, widget->value, 0);
    MarkMenuEventHandled();
    result = 0;

end:
    return result;
}
#endif

#if defined(VERSION_US)
unsigned char D_auto_func_8040C780_us_padding_1709C8[8] = { 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
#endif
