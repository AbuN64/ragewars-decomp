#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Intersects a rectangle with another in place, widening it to at least one unit and returning whether it was non-empty. */



s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip) {
    s32 ok;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 v;

    x0 = rect->field_0;
    ok = 1;
    if (x0 < clip->field_0) {
        x0 = clip->field_0;
    }
    x1 = rect->field_4;
    rect->field_0 = x0;
    if (clip->field_4 < x1) {
        x1 = clip->field_4;
    }
    y0 = rect->field_8;
    rect->field_4 = x1;
    if (y0 < clip->field_8) {
        y0 = clip->field_8;
    }
    y1 = rect->field_C;
    rect->field_8 = y0;
    if (clip->field_C < y1) {
        y1 = clip->field_C;
    }
    rect->field_C = y1;
    v = rect->field_0 + 1;
    if (rect->field_4 < v) {
        rect->field_4 = v;
        ok = 0;
    }
    v = rect->field_8 + 1;
    if (rect->field_C < v) {
        rect->field_C = v;
        ok = 0;
    }
    return ok;
}
