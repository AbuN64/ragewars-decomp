#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Reports a value through the second argument and returns a word: D_800E28C8 and zero when
   D_8015375C is set, otherwise the signed byte at offset 4 of the object at 0x20 of a record and
   the record's word at 0x1C. */




extern s32 D_8015375C;
extern s32 D_800E28C8;

s32 func_80409EF4_de(struct RecordRecAt20V2 *record, s32 *out) {
    s32 value;
    s32 result;

    if (D_8015375C != 0) {
        value = D_800E28C8;
        result = 0;
    } else {
        value = record->inner->unk4;
        result = record->result;
    }
    *out = value;
    return result;
}
