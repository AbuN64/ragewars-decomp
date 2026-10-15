#include "types.h"
#include "common/data.h"
#include "span_1000/code_802646F4.h"
#include "span_C76B0/data.h"

extern u32 D_8010C070;
extern u32 D_8010C07C;

static inline u32 sample_bits(s32 width) {
    u32 previous = D_8010C07C;
    s32 available = D_8010C080_de;
    s32 remaining = available - width;
    u32 shifted = previous >> width;
    D_8010C07C = shifted;
    D_8010C080_de = remaining;
    if (remaining < 25) {
        u8 *cursor = (u8 *)D_8010C084;
        u32 next = *cursor++;
        D_8010C084 = cursor;
        D_8010C080_de = remaining + 8;
        D_8010C07C = shifted | (next << (remaining & 31));
    }
    return previous & ((1U << width) - 1);
}

static inline u32 predictor_bits(void) {
    u32 previous = D_8010C070;
    s32 available = D_8010C074;
    s32 remaining = available - 6;
    u32 shifted = previous >> 6;
    D_8010C070 = shifted;
    D_8010C074 = remaining;
    if (remaining < 25) {
        u8 *cursor = (u8 *)D_8010C078;
        u32 next = *cursor++;
        D_8010C078 = cursor;
        D_8010C074 = remaining + 8;
        D_8010C070 = shifted | (next << (remaining & 31));
    }
    return previous & 63;
}

void func_80264F60_de(s32 destination, s32 count) {
    s16 *out = (s16 *)destination;
    s32 previous = 0;
    s32 older = 0;
    s32 sample = (s8)D_8010C07F * 256;
    s32 group = 0;
    s32 shift, first, second;
    s32 delta, predicted, clamped;
    u32 raw, descriptor;
    sample_bits(8);
    while (count > 0) {
        count--;
        if (group-- == 0) {
            group = 3;
            descriptor = predictor_bits();
            shift = descriptor & 15;
            first = D_800CBC30[descriptor >> 4];
            second = D_800CBC40[descriptor >> 4];
        }
        raw = sample_bits(3);
        delta = raw & 4 ? (s16)(raw | ~7U) : raw;
        delta *= 1 << shift;
        predicted = (s32)((u32)previous * (u32)first + (u32)older * (u32)second);
        older = previous;
        previous = (s32)((u32)delta + (u32)(predicted >> 16));
        sample = (s32)((u32)sample + (u32)previous);
        clamped = sample;
        if (32767 < clamped) clamped = 32767;
        if (clamped < -32768) clamped = -32768;
        *out++ = clamped;
    }
}
