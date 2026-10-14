#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"

/* Decodes the controller status replies in D_80154110 for each of D_8014D46C[0] channels, recording the error bits from each reply's receive size and, for a channel without error, its type and status, and stores the mask of answering channels through arg0. Adapted from func_802B7AD8_de. */





extern u8 D_8014D46C[];
extern char D_80154110;

void func_80447A38_de(u8 *valid, EntryRecAt3 *data) {
    u8 *ptr;
    __OSContRequesFormat readformat;
    s32 i;
    u8 mask = 0;

    ptr = (u8 *)&D_80154110;
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
