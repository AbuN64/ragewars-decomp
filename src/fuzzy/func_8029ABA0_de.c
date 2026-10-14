#include "types.h"
#include "span_1000/code_8029BBA0.h"
#include "span_1000/code_8029EB74.h"

extern const f64 D_800C56C0_de;
extern const f64 D_800C56C8_de;
extern const f64 D_800C56D0_de;

f64 func_8029ABA0_de(f64 value, s32 shift) {
    DoubleBits_8029ECB0 *bits = (DoubleBits_8029ECB0 *)&value;
    u32 high = bits->w.hi;
    s32 exponent = (high >> 20) & 0x7FF;
    u32 sign;
    if (exponent != 0) {
        if ((u32)exponent < 0x7FF) {
            exponent = (s32)((u32)exponent + (u32)shift);
            if (exponent != 0) {
                if ((u32)exponent < 0x7FF) {
                    bits->w.hi = (high & 0x800FFFFF) | ((exponent & 0x7FF) << 20);
                    return value;
                }
                if (shift >= 0) {
                    high = bits->w.hi;
                    sign = high >> 31;
                    value = D_800C56C0_de;
                    bits->w.hi = (high & 0x7FFFFFFF) | (sign << 31);
                    return value;
                }
                if ((u32)exponent < (u32)-53) {
                    sign = high >> 31;
                    value = 0.0;
                    bits->w.hi = (bits->w.hi & 0x7FFFFFFF) | (sign << 31);
                    return value;
                }
            }
            bits->w.hi = (bits->w.hi & 0x800FFFFF) | 0x100000;
            value *= func_8029ABA0_de(D_800C56C8_de, exponent - 1);
            return value;
        }
        if ((high & 0xFFFFF) != 0 || bits->w.lo != 0) {
            return value;
        }
        if (shift >= 0) {
            high = bits->w.hi;
            sign = high >> 31;
            value = D_800C56C0_de;
            bits->w.hi = (high & 0x7FFFFFFF) | (sign << 31);
        } else {
            bits->w.hi = (high & 0x7FFFFFFF) | ((high >> 31) << 31);
        }
        return value;
    }
    if ((high & 0xFFFFF) == 0 && bits->w.lo == 0) {
        return value;
    }
    return func_8029ABA0_de(value * func_8029ABA0_de(D_800C56D0_de, 53), shift - 53);
}
