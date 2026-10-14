#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Resets a five-word record: clears the first three words, stores a value in the fourth and one
   in the fifth, then calls func_802A2394_de. */


extern void func_802A2394_de();

void func_80421FEC_de(struct Rec_func_8024C92C_de *record, s32 value) {
    record->y = 0;
    record->x = 0;
    record->z = 0;
    record->pad0 = value;
    record->pad1 = 1;
    func_802A2394_de();
}
