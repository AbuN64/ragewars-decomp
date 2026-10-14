#include "span_1000/code_8025E568.h"
/** Preserve the top nibble and shift the lower 28 bits right by three. */
unsigned int func_80260684_de(unsigned int value) {
    return (value & 0xF0000000) | ((value & 0x0FFFFFFF) >> 3);
}
