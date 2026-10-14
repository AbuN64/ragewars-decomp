#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
#include "types.h"

/* Sets bit 24 of the flag word at offset 0x120 of the object at offset 0xC of a record when
   D_801468F4 is set, and clears it otherwise. */




extern s32 D_801468F4;

void func_80443BD4_de(struct RecordRecAtCV3 *record) {
    if (D_801468F4 != 0) {
        record->target->flags |= 0x01000000;
    } else {
        record->target->flags &= ~0x01000000;
    }
}
