#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "TYPES.H"

/* Draws the child at 0x8 of a window with the arguments passed by value after clearing D_800E2AB8 once func_8040E0D4_de resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de, giving up when it fails, and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_8041BA00_de with D_800E2AB8 cleared before the rectangle is resolved, the resolved basis declared first, and a failed func_8040F488_de ending the function. */





extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);
extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);
extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void func_802A1870_de(u32, u32, u32, u32);
extern void func_8040E7FC_de(void *, Args);
extern s32 D_800E2AB8;




void func_8040F350_de(void *arg0, Args args) {
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    Quad_func_802A1BE0_de first;
    s32 changed;
    UiWidget *window = arg0;

    changed = 0;
    D_800E2AB8 = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((window->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            if (func_8040F488_de(&transformed, &basis) == 0) {
                return;
            }
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(window->children, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}
