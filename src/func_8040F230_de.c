#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Draws a widget's variant image: when func_8040E0D4_de accepts the widget at the position, picks the
   pressed (flag 0x100), highlighted (flag 0x40) or normal image of the widget, and when present
   moves the position back by the image's offset scaled by the style's scale factors and draws it
   through func_8040DB04_de with the same flags and style. */











extern s32 func_8040E0D4_de(Shared_Quad *a, Shared_Quad *b, Widget_func_8040F230_de *widget, Triple *at);
extern void func_8040DB04_de(struct Pair14 *image, Triple at, Style style);

void func_8040F230_de(Widget_func_8040F230_de *widget, Triple at, Style style) {
    Shared_Quad box0;
    Shared_Quad box1;
    struct Pair14 *image;

    if (func_8040E0D4_de(&box0, &box1, widget, &at) != 0) {
        if (at.z & 0x100) {
            image = widget->pressed;
        } else if (at.z & 0x40) {
            image = widget->highlighted;
        } else {
            image = widget->normal;
        }
        if (image != 0) {
            at.x -= (s32)(image->first * style.scaleX);
            at.y -= (s32)(image->second * style.scaleY);
            func_8040DB04_de(image, at, style);
        }
    }
}
