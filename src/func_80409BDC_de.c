#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Returns D_800E28C8 when D_8015375C is set, otherwise the signed byte at offset 4 of the object
   at offset 0x20 of a record. */




extern s32 D_8015375C;
extern s32 D_800E28C8;

s32 func_80409BDC_de(struct Record_func_80409BDC_de *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->inner->unk4;
}
