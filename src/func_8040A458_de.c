#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Points offset 0x14 of a record at D_800D7794 when D_8015375C is set, and returns zero. */


extern s32 D_8015375C;
extern char D_800D7794[];

s32 func_8040A458_de(struct ObjRecAt14V1 *record) {
    if (D_8015375C != 0) {
        record->unk14 = D_800D7794;
    }
    return 0;
}
