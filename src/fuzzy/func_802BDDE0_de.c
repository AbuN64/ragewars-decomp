#include "types.h"

typedef struct {
    s64 value;
    char *chars;
    s32 unkC;
    s32 unk10;
    s32 digitCount;
    s32 unk18;
    s32 pad1C[2];
    s32 minDigits;
    s32 unk28;
    u32 flags;
} ValueRecord;

extern u8 D_800D5300[];
extern u8 D_800D5314[];

extern s64 func_802C1330_de(s64 numerator, s64 denominator);
extern s64 func_802C0DA0_de(s64 numerator, s64 denominator);
extern s64 func_802C0230_de(s64 numerator, s64 denominator);
extern s64 func_802C0820_de(s64 numerator, s64 denominator);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

void func_802BDDE0_de(ValueRecord *record, u8 type) {
    u8 *table;
    s64 quotient;
    s64 remainder;
    s32 base;
    s32 slots;
    s64 value;
    s32 extra;
    char buffer[0x18];

    table = D_800D5300;
    if (type == 'X') {
        table = D_800D5314;
    }
    if (type == 'o') {
        base = 8;
    } else {
        base = 0x10;
        if (type != 'x' && type != 'X') {
            base = 10;
        }
    }
    slots = 0x18;
    value = record->value;
    if ((type == 'd' || type == 'i') && record->value < 0) {
        value = -value;
    }
    if (value != 0 || record->minDigits != 0) {
        slots--;
        buffer[slots] = table[func_802C1330_de(value, base)];
    }
    record->value = func_802C0DA0_de(value, base);
    while (record->value > 0) {
        if (slots <= 0) {
            break;
        }
        quotient = func_802C0230_de(record->value, base);
        remainder = func_802C0820_de(record->value, base);
        record->value = quotient;
        slots--;
        buffer[slots] = table[remainder];
    }
    record->digitCount = 0x18 - slots;
    func_802BD3A0_de(record->chars, &buffer[slots], record->digitCount);
    if (record->digitCount < record->minDigits) {
        record->unk10 = record->minDigits - record->digitCount;
    }
    if (record->minDigits < 0 && (record->flags & 0x14) == 0x10) {
        extra = (record->unk28 - record->unkC) - record->unk10 - record->digitCount;
        if (extra > 0) {
            record->unk10 = record->unk10 + extra;
        }
    }
}
