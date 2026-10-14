#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"
/* Draws a visible widget (flag 8): when func_8040E0D4_de places it, and its draw flags ask for
   clipping (0x200), it narrows the current scissor from func_802A1898_de to the widget's box through
   func_8040F488_de (skipping the draw when nothing is left) and applies it with func_802A1870_de; it then
   draws the widget through func_8040DB04_de and restores the saved scissor if it was narrowed. */







extern s32 func_8040E0D4_de(struct Shape_typemap_165 *a, struct Shape_typemap_165 *box, Widget_func_8040E67C_de *widget, DrawArgs_func_8040E67C_de *args);
extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);
extern s32 func_8040F488_de(struct Shape_typemap_165 *clip, struct Shape_typemap_165 *box);
extern void func_802A1870_de(s32 left, s32 right, s32 top, s32 bottom);
extern void func_8040DB04_de(Widget_func_8040E67C_de *widget, DrawArgs_func_8040E67C_de args);

void func_8040E67C_de(Widget_func_8040E67C_de *widget, DrawArgs_func_8040E67C_de args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    DrawArgs_func_8040E67C_de local;
    s32 clipped;

    clipped = 0;
    if (widget->flags & 8) {
        local = args;
        if (func_8040E0D4_de(&area, &box, widget, &local) != 0) {
            if (local.flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (func_8040F488_de(&clip, &box) == 0) {
                    return;
                }
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            func_8040DB04_de(widget, args);
            if (clipped) {
                func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
            }
        }
    }
}
