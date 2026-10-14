#include "span_1000/code_8025A3EC.h"
#include "types.h"

/* Returns whether any of the seventeen occupied slots of a record, other than the one its header marks as local, holds the given value at slot offset 0xA8. Adapted from func_8025BA4C_de with the slot count changed from 16 to 17. */







s32 func_8025C17C_de(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 17; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}
