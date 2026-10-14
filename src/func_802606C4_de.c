#include "span_1000/code_8025E568.h"
/* Reads a width-bit field starting at a packed bit address, returning it right-aligned. Adapted from func_80260DA8_de, with the bit address and width passed directly instead of computed from a base/width record. */

int func_802606C4_de(int bitAddress, unsigned int width) {
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;

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
