#include "include_asm.h"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/AUDIO/802C3EA4_2.H"

/* Builds the decoder's trigonometric tables: for 128 steps it stores the sine and cosine of
   (i * D_800CCF10 + D_800CCF14) * D_800CCF18 in D_801510C0 and D_801512C0 and clears D_801518C0,
   then for 128 steps of i * D_800CCF1C stores sine plus cosine in D_801514C0 and cosine minus sine in
   D_801516C0. */


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

void Audio_ComplexFft(f32 *data, s32 count, s32 sign, f32 *cosines, f32 *sines, s32 *reverse) {
    s32 i, j, k;
    s32 width, groups, n, m;
    f32 real, imag, co, si;
    for (i = 0; i < count; i++) {
        if (i < reverse[i]) {
            real = data[i * 2];
            data[i * 2] = data[reverse[i] * 2];
            data[reverse[i] * 2] = real;
            real = data[i * 2 + 1];
            data[i * 2 + 1] = data[reverse[i] * 2 + 1];
            data[reverse[i] * 2 + 1] = real;
        }
    }
    width = 2;
    groups = 1;
    n = count >> groups;
    count <<= groups;
    while (n > 0) {
        m = 0;
        for (j = 0; j < groups; j++) {
            co = cosines[m];
            si = sign * sines[m];
            for (k = j * 2; k < count; k += width * 2) {
                real = co * data[k + width] - si * data[k + width + 1];
                imag = co * data[k + width + 1] + si * data[k + width];
                data[k + width] = data[k] - real;
                data[k + width + 1] = data[k + 1] - imag;
                data[k] = data[k] + real;
                data[k + 1] = data[k + 1] + imag;
            }
            m += n;
        }
        n >>= 1;
        groups <<= 1;
        width <<= 1;
    }
}

#ifdef NON_MATCHING
/* 49/228 words; remaining: draft builds 254 words, loop shape and register allocation differ from the original */
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LLDIVRESULT.H"
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

/* Decode a 256-sample transform block, rotate around the FFT, then combine
 * it with the preceding block and round/saturate to signed PCM samples. */
void func_802BFAAC_de(s16 *out, s16 *input) {
    f32 data[256];
    f32 unpacked[256];
    f32 scale, real, imag, co, si, previous, value, rounded;
    s16 i;
    if ((s16)D_800D54C0_de == 0) {
        func_802BF514_de();
        D_8014B830 = func_802BF67C_de(128);
        D_800D54C0_de = 1;
    }
    scale = D_800C7CD8_de;
    func_802BF804_de(unpacked, input + 12);
    for (i = 0; i < 128; i++) {
        data[i * 2] = unpacked[i * 2];
        data[i * 2 + 1] = unpacked[255 - i * 2];
    }
    for (i = 0; i < 128; i++) {
        real = data[i * 2];
        imag = data[i * 2 + 1];
        co = D_801510C0[i];
        si = D_801512C0[i];
        data[i * 2] = real * co - imag * si;
        data[i * 2 + 1] = real * si + imag * co;
    }
    Audio_ComplexFft(data, D_8014B830->size, -1,
                      D_8014B830->sines, D_8014B830->cosines, D_8014B830->order);
    for (i = 0; i < 128; i++) {
        real = data[i * 2];
        imag = data[i * 2 + 1];
        co = D_801514C0[i];
        si = D_801516C0[i];
        data[i * 2] = real * co - imag * si;
        data[i * 2 + 1] = real * si + imag * co;
    }
    for (i = 0; i < 128; i++) {
        /* The shared history buffer is declared as raw 32-bit words. */
        func_802BD3A0_de(&previous, &D_801518C0[i], sizeof(previous));
        imag = data[i * 2 + 1];
        co = D_801510C0[i];
        si = D_801512C0[i];
        value = scale * (previous * co + imag * si);
        func_802BD3A0_de(&D_801518C0[i], &data[i * 2], sizeof(f32));
        if (value >= 0.0f) {
            rounded = value + D_800C7CDC_de;
            if (D_800C7CE0_de < rounded) rounded = D_800C7CE0_de;
        } else {
            rounded = value - D_800C7CDC_de;
            if (rounded < D_800C7CE4_de) rounded = D_800C7CE4_de;
        }
        out[i * 2] = (s16)(s32)rounded;
        value = scale * (previous * si - imag * co);
        if (value >= 0.0f) {
            rounded = value + D_800C7CDC_de;
            if (D_800C7CE0_de < rounded) rounded = D_800C7CE0_de;
        } else {
            rounded = value - D_800C7CDC_de;
            if (rounded < D_800C7CE4_de) rounded = D_800C7CE4_de;
        }
        out[255 - i * 2] = (s16)(s32)rounded;
    }
}
#else
INCLUDE_ASM("span_1000", func_802BFAAC_de);
#endif
