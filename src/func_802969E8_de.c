#include "span_1000/code_80296014.h"
#include "types.h"

/* Returns whether a point lies on the inner side of all six planes of a frustum, each stored as a normal and a distance. Adapted from func_80296B74_de with the per-axis box minimum replaced by the point's dot product with each plane normal, tested directly in the loop. */
s32 func_802969E8_de(f32 (*planes)[4], f32 *point) {
    s32 i;
    f32 *plane;

    for (i = 0; i < 6; i++) {
        plane = planes[i];
        if (!(plane[0] * point[0] + plane[1] * point[1] + plane[2] * point[2] <= plane[3])) {
            return 0;
        }
    }
    return 1;
}
