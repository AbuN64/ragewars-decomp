#include "include_asm.h"
#include "COMMON/TRIPLE.H"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/AUDIO/audio_decodetransformblock.H"

/* Builds the decoder's trigonometric tables: for 128 steps it stores the sine and cosine of
   (i * D_800CCF10 + D_800CCF14) * D_800CCF18 in D_801510C0 and D_801512C0 and clears D_801518C0,
   then for 128 steps of i * D_800CCF1C stores sine plus cosine in D_801514C0 and cosine minus sine in
   D_801516C0. */


void Audio_InitTransformTables(void) {
    s16 i;
    f32 angle;
    f32 s;
    f32 c;
    f32 step;
    f32 offset;
    f32 scale;
    f32 *sines;
    f32 *cosines;
    f32 *zeros;
    f32 *sums;
    f32 *differences;
    step = D_800CCF10;
    offset = D_800CCF14;
    scale = D_800CCF18;
    i = 0;
    sines = D_801510C0;
    cosines = D_801512C0;
    zeros = D_801518C0;
    for (; i < 128; i++) {
        angle = (i * step + offset) * scale;
        sines[i] = Math_Cosf(angle);
        cosines[i] = Gu_Sinf(angle);
        zeros[i] = 0.0f;
    }
    i = 0;
    scale = D_800CCF1C;
    sums = D_801514C0;
    differences = D_801516C0;
    for (; i < 128; i++) {
        angle = i * scale;
        s = Math_Cosf(angle);
        c = Gu_Sinf(angle);
        sums[i] = s + c;
        differences[i] = c - s;
    }
}
/* Prepares the FFT tables in D_800D9370 for n points: fills the first n / 2 entries of the sine and
   negated cosine tables for angles i * D_800CCF20 / n, fills the order table with 0..n - 1 and
   bit-reverses it with the standard index-swapping walk, records n and returns the tables. */


FftTables *Audio_InitFftTables(s32 n) {
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
            tables->sines[i] = Math_Cosf(angle);
            tables->cosines[i] = -Gu_Sinf(angle);
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
s32 Audio_DequantizeTransformCoefficients(f32 *out, s16 *in) {
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

/* Decoder stage helpers. Their out-of-line copies are Audio_ReorderTransformSamples, Audio_RotateComplexSamples,
   Audio_TransformFft and Audio_QuantizeSampleS16 in the next unit (each with its own literal pool). */
static inline void interleaveMirrored(f32 *dst, f32 *src) {
    s16 i = 0;
    do {
        dst[i * 2] = src[i * 2];
        dst[i * 2 + 1] = src[255 - i * 2];
        i++;
    } while (i < 128);
}
static inline void rotatePairs(f32 *data, f32 *a, f32 *b) {
    s16 i = 0;
    do {
        f32 re = data[i * 2];
        f32 im = data[i * 2 + 1];
        f32 ca = a[i];
        f32 cb = b[i];
        data[i * 2] = re * ca - im * cb;
        data[i * 2 + 1] = re * cb + im * ca;
        i++;
    } while (i < 128);
}
static inline void transformFft(f32 *data, FftTables *tables, s32 sign) {
    Audio_ComplexFft(data, tables->size, sign, tables->sines, tables->cosines, tables->order);
}
static inline s16 roundToSample(f32 value) {
    f32 rounded;
    if (value >= 0.0f) {
        rounded = value + 0.5f;
        if (32767.0f < rounded) {
            rounded = 32767.0f;
        }
    } else {
        rounded = value - 0.5f;
        if (rounded < -32768.0f) {
            rounded = -32768.0f;
        }
    }
    return (s16)(s32)rounded;
}
/* Decode a 256-sample transform block: unpack it, pre-rotate, inverse FFT, post-rotate, then
   overlap it with the previous block's history (D_801518C0) and round/saturate to PCM. */
void Audio_DecodeTransformBlock(s16 *out, s16 *input) {
    f32 data[256];
    f32 unpacked[256];
    f32 scale;
    s16 i;
    s16 *initialized = &D_800D54C0_de;
    if (*initialized == 0) {
        Audio_InitTransformTables();
        D_8014B830 = Audio_InitFftTables(128);
        *initialized = 1;
    }
    scale = 23170.474609375f; /* 32768 / sqrt(2) */
    Audio_DequantizeTransformCoefficients(unpacked, input + 12);
    interleaveMirrored(data, unpacked);
    rotatePairs(data, D_801510C0, D_801512C0);
    transformFft(data, D_8014B830, -1);
    rotatePairs(data, D_801514C0, D_801516C0);
    i = 0;
    do {
        f32 *history = D_801518C0;
        f32 *sines = D_801510C0;
        f32 previous = history[i];
        f32 s = sines[i];
        f32 im = data[i * 2 | 1];
        f32 *cosines = D_801512C0;
        f32 c = cosines[i];
        f32 first = previous * s + im * c;
        f32 second = previous * c - im * s;
        history[i] = data[i * 2];
        out[i * 2] = roundToSample(scale * first);
        out[255 - i * 2] = roundToSample(scale * second);
        i++;
    } while (i < 128);
}
