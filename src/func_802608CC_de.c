#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025E568.h"
#include "types.h"



Func802608ECResult func_802608CC_de(f32 arg0, f32 arg1, f32 arg2) {
    Func802608ECResult result;
    f32 ratio;
    s32 truncated;
    s32 bits;
    u32 count;
    u32 highest;
    u32 bit;
    u32 value;

    result.start = arg0;
    result.delta = arg1 - arg0;
    ratio = result.delta / (arg2 + arg2);
    if (ratio <= 0.0f) {
        bits = (s32)ratio + 1;
    } else {
        truncated = (s32)ratio;
        bits = truncated + 1;
        if ((f32)truncated != ratio) {
            bits = truncated + 2;
        }
    }
    count = 0;
    highest = 0;
    bit = 0;
    do {
        if (bits & (u32)(1 << bit)) {
            count += 1;
            highest = bit;
        }
        bit += 1;
    } while (bit < 0x20U);
    value = highest;
    if (count >= 2U) {
        value += 1;
    }
    result.value = value;
    return result;
}
