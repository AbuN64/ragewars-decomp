#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Blends two values by a weight: from times the pooled constant D_800E0CB0[1] less the weight,
   plus to times the weight, which is linear interpolation when that constant is one. The
   constant lives in a shared literal pool outside this object, so it is read by name. */
extern f32 D_800E0CB0[];

f32 func_80403C98_de(f32 from, f32 to, f32 weight) {
    return from * (D_800E0CB0[1] - weight) + to * weight;
}
