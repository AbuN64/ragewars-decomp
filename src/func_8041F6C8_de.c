#include "span_16E000/code_8041F1FC.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

/* Returns the index of the first of the seventeen 0x70-byte slots of D_800E3A50 whose leading word equals the argument, or zero when none does. Adapted from func_8041F140_de with the slot word D_800E3A50 changed. */





/* Returns the second word of the first of the seventeen 0x70-byte slots of D_800E3A50 whose leading word equals the argument, or zero when none does.
   Adapted from func_8041F18C_de with the returned index changed to the slot's second word D_800E3A54. */





s32 func_8041F18C_de(s32 key) {
    extern struct SlotRecAt0V1 D_800E3A50[];
    s32 index = 0;
    s32 found = 0;
    s32 i;

    for (i = 0; i < 17 && !found; i++) {
        if (D_800E3A50[i].key == key) {
            found = 1;
            index = i;
        }
    }
    return index;
}

s32 func_8041F1D8_de(s32 key) {
    extern struct SlotRecAt4 D_800E3A50[];
    s32 value = 0;
    s32 found = 0;
    s32 i;

    for (i = 0; i < 17 && !found; i++) {
        if (D_800E3A50[i].key == key) {
            found = 1;
            value = D_800E3A50[i].value;
        }
    }
    return value;
}
