#include "span_1000/code_80275E44.h"
#include "types.h"
#include "math_helpers.h"
/* Blends a colour toward the grey of its brightest channel: with amount (0-100) zero it copies r, g, b to the outputs, otherwise each output is (channel * (100 - amount) + max(r, g, b) * amount) / 100. */
void func_80276968_de(u8 amount, u8 r, u8 g, u8 b, u8 *outR, u8 *outG, u8 *outB) {
    s32 rest;
    s32 top;
    if (amount != 0) {
        rest = 100 - amount;
        top = RW_MAX_GT(r, RW_MAX_GT(g, b));
        *outR = (r * rest + top * amount) * 0.01f;
        *outG = (g * rest + top * amount) * 0.01f;
        *outB = (b * rest + top * amount) * 0.01f;
    } else {
        *outR = r;
        *outG = g;
        *outB = b;
    }
}
/* Darkens a colour by a percentage: with a non-zero percentage each channel becomes the channel scaled by one hundredth of (100 minus the percentage), and with zero the channels are copied unchanged. */
void func_80276B44_de(unsigned char percent, unsigned char r, unsigned char g, unsigned char b,
                   unsigned char *outR, unsigned char *outG, unsigned char *outB) {
    int remaining;
    if (percent != 0) {
        remaining = 100 - percent;
        *outR = (unsigned int)(r * 0.01f * remaining);
        *outG = (unsigned int)(g * 0.01f * remaining);
        *outB = (unsigned int)(b * 0.01f * remaining);
    } else {
        *outR = r;
        *outG = g;
        *outB = b;
    }
}
