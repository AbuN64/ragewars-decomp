#include "span_1000/code_80271B18.h"
#include "types.h"

/* Transforms a count of points by the affine part of a 4x4 matrix, writing each transformed point to an output array. Adapted from func_8029F1A0_de with the input and output arguments swapped and the indexed loop replaced by a loop counting down an unsigned count while advancing an input and an output pointer. */
void func_80272944_de(f32 *m, f32 *in, f32 *out, u32 count) {
    f32 vx, vy, vz;

    while (count-- != 0) {
        vx = in[0];
        vy = in[1];
        vz = in[2];
        out[0] = (m[0] * vx) + (m[4] * vy) + (m[8] * vz) + m[12];
        out[1] = (m[1] * vx) + (m[5] * vy) + (m[9] * vz) + m[13];
        out[2] = (m[2] * vx) + (m[6] * vy) + (m[10] * vz) + m[14];
        in += 3;
        out += 3;
    }
}
