#include "span_1000/code_802B9BB4.h"
/** Report whether either low bit of the VI current register is set. */
int func_802B9D70_de(void) {
    return (*(volatile unsigned int *)0xA4800018 & 3) != 0;
}
