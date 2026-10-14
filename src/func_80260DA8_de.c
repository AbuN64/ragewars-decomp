#include "span_1000/code_802609CC.h"


int func_80260DA8_de(BitFieldSource *arg0, int arg1) {
    int bitAddress;
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;
    unsigned int width;

    width = arg0->width;
    bitAddress = arg0->base + (width * arg1);
    word = (int *) ((bitAddress & 0xF0000000) |
                    ((unsigned int) (bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (width < 0x20U) {
        value &= (1 << width) - 1;
    }
    return value;
}
