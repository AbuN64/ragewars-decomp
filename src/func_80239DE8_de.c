#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"
#include "types.h"

/* Configures a three-channel record: copies a by-value three-word block to offset 8 and a value to
   0x14, and gives each of the channels at 0x18, 0x2C and 0x40 the same mode word and a level scaled
   by the pooled constant D_800C8664. */








void func_80239DE8_de(struct RecordRecAt18 *record, f32 first, f32 second, f32 third, f32 value, s32 mode,
                   Triple triple) {
    record->triple = triple;
    record->value = value;
    record->channels[0].mode = mode;
    record->channels[1].mode = mode;
    record->channels[2].mode = mode;
    record->channels[0].level = first * D_800C8664;
    record->channels[1].level = second * D_800C8664;
    record->channels[2].level = third * D_800C8664;
}
