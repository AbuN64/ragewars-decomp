#include "span_1000/code_802609CC.h"
unsigned int func_8026100C_de(unsigned int *arg0, unsigned int arg1) {
    unsigned int bitAddress;
    unsigned int shift;
    unsigned int *word;
    unsigned int value;
    unsigned int next;

    bitAddress = *arg0;
    word = (unsigned int *) ((bitAddress & 0xF0000000) |
                             ((bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (arg1 < 0x20U) {
        value &= (1 << arg1) - 1;
    }
    *arg0 = bitAddress + arg1;
    return value;
}
