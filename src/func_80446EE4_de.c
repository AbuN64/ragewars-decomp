#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041C67C.h"
#include "types.h"

/* Decodes the six-byte short controller status reply found one byte per preceding channel into D_80154110 for the given channel, recording its error bits and, without error, its type and status.
   Adapted from func_80447A38_de with the per-channel loop over eight-byte replies changed to a single six-byte reply reached by skipping one byte per preceding channel. */





extern char D_80154110;

void func_80446EE4_de(s32 channel, EntryRecAt3 *data) {
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    s32 i;

    ptr = (u8 *)&D_80154110;
    for (i = 0; i < channel; i++) {
        ptr++;
    }
    requestformat = *(__OSContRequesFormatShort *)ptr;
    data->slot = (requestformat.rxsize & 0xC0) >> 4;
    if (data->slot == 0) {
        data->id = (requestformat.typel << 8) | requestformat.typeh;
        data->team = requestformat.status;
    }
}
