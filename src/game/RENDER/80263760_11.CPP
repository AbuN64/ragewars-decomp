#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/TRIPLE.H"

extern u32 D_8010C070;
extern u32 D_8010C07C;

/* Drops width bits from the sample bit stream and refills it a byte at a time. */
static inline void advance_bits(s32 width) {
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
        D_8010C07C = shifted | (next << remaining);
    }
}
/* Takes the next 6-bit predictor descriptor (2-bit coefficient index, 4-bit shift) from the control stream. */
static inline u32 predictor_bits(void) {
    u32 previous = D_8010C070;
    u32 bits = previous & 63;
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
        D_8010C070 = shifted | (next << remaining);
    }
    return bits;
}

/* Takes a signed width-bit delta from the sample stream and scales it by 1 << shift. */
static inline s32 scaled_sample(s32 width, u8 shift) {
    u32 mask = (1U << width) - 1;
    u16 encoded = (u16)D_8010C07C;
    s32 value = encoded & mask;
    advance_bits(width);
    if (encoded & ((mask + 1) >> 1)) {
        return (s16)(value | ~mask) * (1 << shift);
    }
    return value * (1 << shift);
}


/* Decodes count samples: each group of 4 takes a predictor descriptor, each sample a 3-bit delta.
 * The delta plus the two-tap prediction is integrated into a running sample clamped to 16 bits.
 * 7 of 148 words differ: the ROM keeps an extra andi 0xFF on the descriptor shift (one more
 * insn in the group block), and previous/older initialise in the other order. */
void Render_DecodeThreeBitSamples(s16 *out, s32 count) {
    s32 older = 0;
    s32 previous = 0;
    s32 sample;
    u8 head = (u8)D_8010C07C;
    s32 group = 0;
    u8 shift;
    s32 first, second;
    s32 delta, predicted, clamped, total;
    u32 descriptor;
    advance_bits(8);
    sample = (s8)head * 256;
    while (count-- > 0) {
        if (group-- == 0) {
            group = 3;
            descriptor = predictor_bits();
            shift = descriptor & 15;
            first = D_800CBC30[descriptor >> 4];
            second = D_800CBC40[descriptor >> 4];
        }
        delta = scaled_sample(3, shift);
        predicted = previous * first + older * second;
        older = previous;
        delta += predicted >> 16;
        previous = delta;
        total = sample + delta;
        sample = total;
        if (total <= 32767) clamped = total; else clamped = 32767;
        total = clamped;
        clamped = -32768;
        if (total >= -32768) clamped = total;
        *out++ = clamped;
    }
}
#else
INCLUDE_ASM("span_1000", Render_DecodeThreeBitSamples);
#endif

#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ACTORRECAT5E0.H"

extern u32 D_8010C070;
extern u32 D_8010C07C;
extern void Render_DecodeThreeBitSamples(s16 *out, s32 count);

/* Initializes the packed control and sample bit streams, then decodes each output channel. */
s32 func_802651B0_de(s32 destinations, void *encoded, s32 channel_count) {
    s32 *channels = (s32 *)destinations;
    u8 *packed = (u8 *)encoded;
    s32 sample_count;
    s32 control_bits;
    s32 shift;
    u8 *sample_bytes;
    u8 *cursor;
    s32 i;
    u32 last_byte;

    sample_count = *packed++ << 8;
    sample_count |= *packed++;
    control_bits = ((sample_count + 3) / 4) * 6;
    sample_bytes = packed + control_bits / 8;
    D_8010C07C = sample_bytes[0];
    D_8010C07C |= sample_bytes[1] << 8;
    D_8010C07C |= sample_bytes[2] << 16;
    shift = control_bits & 7;
    last_byte = sample_bytes[3];
    last_byte <<= 24;
    D_8010C080_de = 32 - shift;
    D_8010C084 = sample_bytes + 4;
    D_8010C07C = (D_8010C07C | last_byte) >> shift;

    for (i = 0; i < channel_count; i++) {
        u32 tail;
        cursor = packed;
        D_8010C070 = *cursor++;
        D_8010C070 |= *cursor++ << 8;
        D_8010C070 |= *cursor++ << 16;
        tail = *cursor++;
        D_8010C074 = 32;
        D_8010C078 = cursor;
        tail <<= 24;
        D_8010C070 |= tail;
        Render_DecodeThreeBitSamples((s16 *)channels[i], sample_count);
    }
    return sample_count;
}

#if defined(VERSION_US)
char rodata_unresolved_802652E4[12] =
    "Pair_t\014m_YDi";
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_80265344_de_padding_65F44[12] = { 0x34, 0x63, 0xFF, 0xFF, 0x3C, 0x04, 0x80, 0x00, 0x8C, 0x84, 0x03, 0x18 };
#endif
