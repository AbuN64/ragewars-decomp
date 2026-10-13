#include "span_16E000/code_8040F1E0.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Draws the child at 0x8 of window arg0 with the arguments passed by value once func_8040E0D4_de resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_802A1BE0_de. */





extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);
extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);
extern void func_8040F488_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *);
extern void func_802A1870_de(u32, u32, u32, u32);
extern void func_8040E7FC_de(void *, Args);




void func_8041A7B4_de(void *arg0, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;
    Widget_func_8040F6DC_de *window = arg0;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((window->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
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
