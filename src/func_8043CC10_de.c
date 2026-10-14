#include "common/types_1dc8418c21db.h"
#include "span_166000/code_80426310.h"
#include "types.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
#include "types.h"
/* Shifts the input history, appends the current byte, and advances the history counters. */





extern s32 D_80154030;
extern InputHistory D_800E5CA0;

s32 func_8043CC10_de(ObjRecAt14V2 *arg0) {
    s32 index;
    s32 count;

    D_80154030 = -1;
    D_800E5CA0.timer = 0;
    if (D_800E5CA0.count == 0x16) {
        return 0;
    }
    index = 0x16;
    if (D_800E5CA0.value < 0x16) {
        do {
            D_800E5CA0.text[index] = D_800E5CA0.text[index - 1];
            index--;
        } while (D_800E5CA0.value < index);
    }
    D_800E5CA0.text[D_800E5CA0.value] =
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        *arg0->unk14[D_80152789];
#else
        **arg0->unk14;
#endif
    count = D_800E5CA0.count + 1;
    D_800E5CA0.value++;
    D_800E5CA0.count = count;
    D_800E5CA0.text[count] = 0;
    return 0;
}
