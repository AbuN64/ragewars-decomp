#include "types.h"

/* Formats a 64-bit value held as a (hi, lo) word pair at the head of a
   ValueRecord into digits written backwards into a 24-byte stack buffer, then
   memcpy's the resulting digit string to the record's chars pointer and stores
   its length. The base comes from the record's type char: 'o' -> 8, 'x'/'X' ->
   16, anything else -> 10; 'X' also selects the upper-case D_800D5314 digit
   table instead of D_800D5300. For 'd'/'i' a negative value is negated first,
   and a negative zero path emits one sign-related digit up front via
   func_802C1330_de. Up to 24 divisions by the base extract the digits, each
   remainder indexing the table; finally the record's unknown padding fields are
   reconciled against the requested minimum width. */

typedef struct {
    s32 hi;
    s32 lo;
} Pair;

typedef struct {
    Pair value;
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

extern Pair func_802C1330_de(s32 valueHi, s32 valueLo, s32 baseHi, s32 baseLo);
extern Pair func_802C0DA0_de(s32 valueHi, s32 valueLo, s32 baseHi, s32 baseLo);
extern Pair func_802C0230_de(s32 valueHi, s32 valueLo, s32 baseHi, s32 baseLo);
extern Pair func_802C0820_de(s32 valueHi, s32 valueLo, s32 baseHi, s32 baseLo);
extern void *func_802BD3A0_de(void *destination, const void *source, s32 count);

void func_802BDDE0_de(ValueRecord *record, u8 type) {
    u8 *table;
    Pair quotient;
    Pair remainder;
    s32 base;
    s32 slots;
    s32 valueHi;
    s32 valueLo;
    s32 combined;
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
    valueHi = record->value.hi;
    valueLo = record->value.lo;
    if ((type == 'd' || type == 'i') && record->value.hi < 0) {
        valueLo = -valueLo;
        valueHi = -valueHi - (valueLo != 0);
    }
    combined = valueHi | valueLo;
    if (combined != 0 || record->minDigits != 0) {
        slots--;
        buffer[slots] = table[func_802C1330_de(valueHi, valueLo, 0, base).lo];
    }
    record->value = func_802C0DA0_de(valueHi, valueLo, 0, base);
    while (record->value.hi > 0 || (record->value.hi == 0 && record->value.lo != 0)) {
        if (slots <= 0) {
            break;
        }
        quotient = func_802C0230_de(record->value.hi, record->value.lo, 0, base);
        remainder = func_802C0820_de(record->value.hi, record->value.lo, 0, base);
        record->value = quotient;
        slots--;
        buffer[slots] = table[remainder.lo];
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
