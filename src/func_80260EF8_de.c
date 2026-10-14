#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802609CC.h"
#include "types.h"
/* Decodes the next packed bit-field float from a stream record into its range and advances the record's bit address by the field width. Adapted from func_80260B80_de, inlined as a helper called with the record and a copy of the record's own range. */









static inline f32 decode(u32 *stream, Func802608ECResult range) {
    u32 bitAddress;
    u32 *streamPtr;
    s32 shift;
    u32 *word;
    u32 value;
    u32 next;
    u32 width;
    f64 converted;
    f32 result;
    LocalDecodeRange local;

    streamPtr = stream;
    bitAddress = *streamPtr;
    local.range = range;
    width = local.range.value;
    word = (u32 *) ((bitAddress & 0xF0000000) |
                    ((bitAddress & 0x0FFFFFE0) >> 3));
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
        converted += D_800C4190_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << width) - 1);
    result *= local.range.delta;
    result += local.range.start;
    *streamPtr += range.value;
    return result;
}

f32 func_80260EF8_de(LocalDecodeRange *arg0) {
    return decode(&arg0->unused, arg0->range);
}
