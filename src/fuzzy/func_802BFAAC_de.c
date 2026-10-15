#include "span_1000/code_802BE0D0.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
extern void func_802BF928_de(f32 *, s32, s32, f32 *, f32 *, s32 *);
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
    func_802BF928_de(data, D_8014B830->size, -1,
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
