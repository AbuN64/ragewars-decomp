#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025E568.h"
#include "types.h"





extern s32 D_8010AC78;

extern f32 D_8010AC80;


extern u32 func_802607B8_de(u32 *, u32);

extern f32 func_80260650_de(f32 value, f32 lower, f32 upper);
extern f32 func_80260B80_de(u32 *stream, s32 bits, f32 base, f32 range);

void func_8025EF34_de(u32 *stream, Output8025EF54 *out, s32 count) {
    Decode8025EF54 decode;
    f32 first;
    f32 second;
    s32 i;
    f64 converted;

    decode.stream = *stream;
    if (D_8010AC78 != 0) {
        decode.first_bits = func_802607B8_de(&decode.stream, 0x20);
        decode.second_bits = func_802607B8_de(&decode.stream, 0x20);
        first = *(f32 *)&decode.first_bits;
        second = *(f32 *)&decode.second_bits;
    } else {
        decode.first_bits = func_802607B8_de(&decode.stream, 6);
        decode.second_bits = func_802607B8_de(&decode.stream, 6);
        converted = (f64)decode.first_bits;
        if (decode.first_bits < 0) {
            converted += D_800C40F8_de;
        }
        first = func_80260634_de((f32)converted, 6);
        converted = (f64)decode.second_bits;
        if (decode.second_bits < 0) {
            converted += D_800C4100_de;
        }
        second = func_80260634_de((f32)converted, 6);
        first = func_80260650_de(first, D_8010AC7C, D_8010AC80);
        second = func_80260650_de(second, D_8010AC7C, D_8010AC80);
    }
    decode.base = first;
    decode.range = second - first;
    decode.bits = func_802607B8_de(&decode.stream, 6);
    i = 0;
    if (count > 0) {
        do {
            out->value = func_80260B80_de(&decode.stream, decode.bits,
                                       decode.base, decode.range);
            i++;
            out++;
        } while (i < count);
    }
    *stream = decode.stream;
}
