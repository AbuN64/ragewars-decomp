#include "span_1000/code_802624A0.h"
#include "types.h"

/* Two-word value setter; live func_802171BC_de uses the same word-array representation. */
void func_802630E0_de(s32 *value, s32 word) {
    value[0] = word;
    value[1] = 0;
}

extern s32 func_80263154_de(BitReader *, s32);

s32 func_802630EC_de(BitReader *arg0, s32 arg1) {
    s32 val;
    s32 i;
    s32 mask;

    val = func_80263154_de(arg0, arg1);
    mask = 1 << (arg1 - 1);
    if (val & mask) {
        i = arg1;
        if (arg1 < 0x20) {
            do {
                val |= 1 << i;
                i += 1;
            } while (i < 0x20);
        }
    }
    return val;
}
