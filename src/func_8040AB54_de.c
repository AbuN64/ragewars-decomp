#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040A83C.h"
#include "types.h"

/* Clears bit 26 and sets bit 3 of the flag word at offset 0x120 of the object at offset 0xC of a
   record, stores 8 in the state word D_80153788 between the two, and calls func_802649FC_de. */




extern s32 D_80153788;
extern void func_802649FC_de();

void func_8040AB54_de(struct RecordRecAtCV3 *record) {
    record->target->flags &= ~0x04000000;
    D_80153788 = 8;
    record->target->flags |= 8;
    func_802649FC_de();
}
