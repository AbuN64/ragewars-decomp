#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Records the last column and row of a width by height area: stores width - 1 and height - 1 in
   D_800DEA60 and D_800E2AB4_de, and fills the rectangle D_8014D580 with zero to width - 1 and zero
   to height - 1. */


extern s32 D_800DEA60;
extern s32 D_800E2AB4_de;
extern struct Shape_typemap_165 D_8014D580;

void func_8040F534_de(s32 width, s32 height) {
    struct Shape_typemap_165 *rect = &D_8014D580;

    width--;
    height--;
    D_800DEA60 = width;
    D_800E2AB4_de = height;
    rect->field_8 = 0;
    rect->field_0 = 0;
    rect->field_4 = width;
    rect->field_C = height;
}
