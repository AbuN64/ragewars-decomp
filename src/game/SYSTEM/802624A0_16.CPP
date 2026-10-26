#include "COMMON/OBJRECAT5F14.H"
#include "TYPES.H"

/* Two-word value setter; live func_802171BC_de uses the same word-array representation. */
void AnimPool_InitializeBitReader(s32 *value, s32 word) {
    value[0] = word;
    value[1] = 0;
}

s32 func_80263154_de(BitReader *arg0, s32 arg1);

s32 AnimPool_ReadSignedBits(BitReader *arg0, s32 arg1) {
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

/** Reads arg1 bits (LSB first) from the bitstream at arg0, advancing its bit position. */
s32 func_80263154_de(BitReader *arg0, s32 arg1) {
    s32 bitPos;
    s32 i;
    s32 result;

    i = 0;
    result = 0;
    if (arg1 > 0) {
        do {
            bitPos = arg0->bitPos;
            result |= (((s32) *(arg0->data + (bitPos >> 3)) >> (bitPos & 7)) & 1) << i;
            i += 1;
            arg0->bitPos = (s32) (bitPos + 1);
        } while (i < arg1);
    }
    return result;
}
