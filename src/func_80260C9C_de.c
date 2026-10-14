#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802609CC.h"
#include "types.h"
/* Decodes element arg1 of a packed bit-field float array into a float scaled into its range. Adapted from func_802609AC_de, inlined as a helper (with the width held in a local) called with a base plus width-times-index bit address and the record's range. */







static inline f32 decode(s32 bitAddress, Func802608ECResult range) {
    s32 shift;
    u32 *word;
    u32 value;
    u32 next;
    f64 converted;
    f32 result;
    u32 width;

    width = range.value;
    word = (u32 *) ((bitAddress & 0xF0000000) |
                    ((u32) (bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (width < 0x20U) {
        value &= (1 << width) - 1;
    }
    converted = (s32) value;
    if ((s32) value < 0) {
        converted += D_800C4188_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << width) - 1);
    result *= range.delta;
    result += range.start;
    return result;
}

f32 func_80260C9C_de(DecodeArray *arg0, s32 arg1) {
    return decode(arg0->base + (arg0->range.value * arg1), arg0->range);
}
