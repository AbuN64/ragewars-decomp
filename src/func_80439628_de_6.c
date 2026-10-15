#include "span_16E000/code_8043962C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/world.h"
#include "types.h"

/* Stores a count in a record and, when it is positive, the handle func_8028B21C_de returns for
   D_8011FE88 and that count at offset 0x34; otherwise the handle is -1. Returns the handle. */



extern s32 func_8028B21C_de(void *, s32);

s32 func_80439C80_de(struct Record_func_80439C80_de *record, s32 count) {
    record->count = count;
    record->handle = -1;
    if (count > 0) {
        record->handle = func_8028B21C_de(&D_8011FE88, count);
    }
    return record->handle;
}

/* Returns the word at offset 0x0 of a record. */
s32 func_80439CC8_de(s32 *record) {
    return record[0x0 / 4];
}

/* Stores a value into the word at offset 0xB8 of an object. */


void func_80439CD4_de(struct ObjectB8 *object, s32 value) {
    object->value = value;
}

/* Returns by value the three-word vector at offset 0x10 of an object. */




struct Triple func_80439CDC_de(struct ObjectRecAt10 *object) {
    return object->vector;
}

/* Stores a three-word vector passed by value into offset 0x10 of an object. */




void func_80439D00_de(struct ObjectRecAt10 *object, struct Triple vector) {
    object->vector = vector;
}
