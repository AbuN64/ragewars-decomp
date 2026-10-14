#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B7488.h"
#include "types.h"





extern u8 D_8014D46C[];
extern char D_8014D470;

void func_802B7AD8_de(u8 *valid, EntryRecAt3 *data) {
    u8 *ptr;
    __OSContRequesFormat readformat;
    s32 i;
    u8 mask = 0;

    ptr = (u8 *)&D_8014D470;
    for (i = 0; i < D_8014D46C[0]; i++, ptr += sizeof(readformat), data++) {
        readformat = *(__OSContRequesFormat *)ptr;
        data->slot = (readformat.rxsize & 0xC0) >> 4;
        if (data->slot != 0) {
            continue;
        }
        data->id = (readformat.typel << 8) | readformat.typeh;
        data->team = readformat.status;
        mask |= 1 << i;
    }
    *valid = mask;
}
