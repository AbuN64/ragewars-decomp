#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Blends two values with cubic weights: with u the pooled constant D_800E0CB0[0] less t, from is
   weighted by u cubed less u and to by t cubed less t. The constant lives in a shared literal
   pool outside this object, so it is read by name. */
extern f32 D_800E0CB0[];

f32 func_80403C58_de(f32 from, f32 to, f32 t) {
    f32 u = D_800E0CB0[0] - t;

    return from * (u * u * u - u) + to * (t * t * t - t);
}
