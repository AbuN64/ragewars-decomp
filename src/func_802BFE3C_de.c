#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802BE0D0.h"
#include "types.h"
#include "common/unused.h"

s16 func_802BF388_de();
u32 func_802BFE3C_de(void) {
    return (u32) ~func_802BF388_de() >> 0x1F;
}

/* Fills the first N words of an index table with 0..N-1, then applies the bit-reversal
   permutation of an FFT of length N to it, swapping entries in place. */
void func_802BFE68_de(s32 *arg0, s32 arg1) {
    s32 *ptr;
    s32 i;
    s32 j;
    s32 k;
    s32 tmp;
    s32 n2;

    i = 0;
    n2 = arg1 * 2;
    if (arg1 > 0) {
        ptr = arg0;
        do {
            *ptr = i;
            i++;
            ptr++;
        } while (i < arg1);
    }

    j = 1;
    i = 1;
    if (n2 > 0) {
        do {
            if (j > i) {
                tmp = arg0[(j - 1) / 2];
                arg0[(j - 1) / 2] = arg0[(i - 1) / 2];
                arg0[(i - 1) / 2] = tmp;
            }
            k = arg1;
            while (k >= 2 && j > k) {
                j -= k;
                k >>= 1;
            }
            i += 2;
            j += k;
        } while (n2 >= i);
    }
}

/** Interleave the first and mirrored halves of 128 float pairs. */
void func_802BFF30_de(float *arg0, float *arg1) {
    short i = 0;
    do {
        arg0[i * 2] = arg1[i * 2];
        arg0[i * 2 + 1] = arg1[(255 - i * 2)];
        i++;
    } while (i < 128);
}

/** Complex-multiply 128 (re,im) pairs in-place by per-element (a,b) factors. */
void func_802BFF90_de(float *arg0, float *arg1, float *arg2) {
    short i = 0;
    do {
        float re = arg0[i * 2];
        float im = arg0[i * 2 + 1];
        float a = arg1[i];
        float b = arg2[i];

        arg0[i * 2] = re * a - im * b;
        arg0[i * 2 + 1] = re * b + im * a;
        i++;
    } while (i < 0x80);
}

extern void func_802BF928_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_802C000C_de(s32 unused0, struct Shape_typemap_165 *arg1, s32 unused2) {
    func_802BF928_de(unused0, arg1->field_C, unused2, arg1->field_0, arg1->field_4, arg1->field_8);
}

s16 func_802C0044_de(f32 arg0) {
    f32 f0;
    f32 f12;

    if (arg0 >= 0.0f) {
        f12 = arg0 + D_800C7CE8_de;
        f0 = D_800C7CEC_de;
        if (f0 < f12) {
            f12 = f0;
        }
    } else {
        f12 = arg0 - D_800C7CF0_de;
        f0 = D_800C7CF4_de;
        if (f12 < f0) {
            f12 = f0;
        }
    }
    return (s16)(s32)f12;
}

/** Initialize the global decoder state and return its scaled period. */
u32 func_802C00B0_de(s32 *source, u32 divisor, s32 *first)
{
    DecodeState *state = &D_8014BA38_de;
    state->source = source;
    state->cursor = source;
    state->first = *(s32 *)state->cursor;
    state->cursor = (s32 *)state->cursor + 1;
    state->count = *(s32 *)state->cursor;
    state->second = *(s32 *)state->cursor;
    state->cursor = (s32 *)state->cursor + 1;
    state->third = *(s32 *)state->cursor;
    state->cursor = (s32 *)state->cursor + 1;
    D_800D54BE = 0;
    D_800D54C0_de = 0;
    D_800D54B8 = 0;
    D_800D54BA = 0;
    D_800D54BC = 0;
    *first = state->first;
    return (u64)((s64)state->count * 0xF424000) / divisor;
}
