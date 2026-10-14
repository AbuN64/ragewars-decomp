#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Latches D_80146D60 and D_800E28CC to one the first time bit 12 of the word at offset 0xB0 of the
   object at 0x20 of a record is seen set, and returns D_80146D60. */




extern s32 D_80146D60;


s32 func_80409DCC_de(struct RecordRecAt20V1 *record) {
    if ((record->inner->unkB0 & 0x1000) && D_800E28CC == 0) {
        D_80146D60 = 1;
        D_800E28CC = 1;
    }
    return D_80146D60;
}
