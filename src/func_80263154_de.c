#include "span_1000/code_802624A0.h"
#include "types.h"



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
