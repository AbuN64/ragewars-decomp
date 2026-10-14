#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BE0D0.h"
#include "types.h"
/* Builds the decoder's trigonometric tables: for 128 steps it stores the sine and cosine of
   (i * D_800CCF10 + D_800CCF14) * D_800CCF18 in D_801510C0 and D_801512C0 and clears D_801518C0,
   then for 128 steps of i * D_800CCF1C stores sine plus cosine in D_801514C0 and cosine minus sine in
   D_801516C0. */
extern s32 D_801518C0[];


void func_802BF514_de(void) {
    s16 i;
    f32 angle;
    f32 s;
    f32 c;
    f32 step;
    f32 offset;
    f32 scale;
    f32 *sines;
    f32 *cosines;
    s32 *zeros;
    f32 *sums;
    f32 *differences;
    step = D_800CCF10;
    offset = (*(&D_800CCF10 + 1));
    scale = D_800CCF18;
    i = 0;
    sines = D_801510C0;
    cosines = D_801512C0;
    zeros = D_801518C0;
    for (; i < 128; i++) {
        angle = (i * step + offset) * scale;
        sines[i] = func_802B6560_de(angle);
        cosines[i] = func_802B7130_de(angle);
        zeros[i] = 0;
    }
    i = 0;
    scale = (*(&D_800CCF18 + 1));
    sums = D_801514C0;
    differences = D_801516C0;
    for (; i < 128; i++) {
        angle = i * scale;
        s = func_802B6560_de(angle);
        c = func_802B7130_de(angle);
        sums[i] = s + c;
        differences[i] = c - s;
    }
}
/* Prepares the FFT tables in D_800D9370 for n points: fills the first n / 2 entries of the sine and
   negated cosine tables for angles i * D_800CCF20 / n, fills the order table with 0..n - 1 and
   bit-reverses it with the standard index-swapping walk, records n and returns the tables. */
extern FftTables D_800D9370;


FftTables *func_802BF67C_de(s32 n) {
    FftTables *tables;
    s32 half;
    s32 i;
    s32 k;
    s32 j;
    s32 m;
    s32 swap;
    s32 limit;
    s32 *order;
    f32 angle;
    f32 scale;
    f32 count;
    half = n >> 1;
    tables = &D_800D9370;
    i = 0;
    if (i < half) {
        scale = D_800CCF20;
        count = n;
        do {
            angle = i * scale / count;
            tables->sines[i] = func_802B6560_de(angle);
            tables->cosines[i] = -func_802B7130_de(angle);
            i++;
        } while (i < half);
    }
    order = tables->order;
    limit = n * 2;
    for (k = 0; k < n; k++) {
        order[k] = k;
    }
    j = 1;
    for (k = 1; k <= limit; k += 2) {
        if (k < j) {
            swap = order[(j - 1) / 2];
            order[(j - 1) / 2] = order[(k - 1) / 2];
            order[(k - 1) / 2] = swap;
        }
        m = n;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    tables->size = n;
    return tables;
}
/* Dequantises 256 coefficients: for each of the 16 bands, whose end indices are in D_800D93C8,
   every coefficient is the quantised value at offset 0xA0 of the input divided by the step
   D_800D93E8 selected by the band's scale index and multiplied by the gain D_800CCF24; the
   coefficients past the last band end (D_800D93E6) are cleared. Returns 1. */
extern u16 D_800D93C8[];
extern s16 D_800D93E6;
extern f32 D_800D93E8[];
s32 func_802BF804_de(f32 *out, s16 *in) {
    s16 *scale;
    s16 band;
    s16 i;
    s16 start;
    s16 *values;
    u16 *ends;
    f32 *steps;
    f32 gain;
    start = 0;
    values = in + 0x50;
    band = 0;
    ends = D_800D93C8;
    steps = D_800D93E8;
    gain = D_800CCF24;
    for (; band < 16; band++) {
        for (i = start; i < ends[band]; i++) {
            out[i] = (f32)values[i] / steps[*(scale = &in[band])] * gain;
        }
        start = ends[band];
    }
    for (band = D_800D93E6; band < 0x100; band++) {
        out[band] = 0.0f;
    }
    return 1;
}
