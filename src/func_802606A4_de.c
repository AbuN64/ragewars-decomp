#include "span_1000/code_8025E568.h"
/** Repack the low address bits while retaining the high nibble. */
unsigned int func_802606A4_de(unsigned int arg0) {
    return (arg0 & 0xF0000000) | ((arg0 & 0x0FFFFFE0) >> 3);
}
