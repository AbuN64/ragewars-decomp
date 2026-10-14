#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043962C.h"
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
