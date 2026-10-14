#include "span_1000/code_8025A3EC.h"
/* Initialises an object: sets the words at 0x8, 0xC, 0x40 and 0xB4 and the halfword at 0x3A to -1,
   stores the two arguments at 0xB0 and 0x0, clears the halfword at 0x38 and the words at 0x14, 0x58,
   0x5C, 0xA4, 0xAC, 0xBC and 0xC0, sets the word at 0xC4 to 1 and writes D_800C9068 into the floats
   at 0x2C, 0x34 and 0xB8. */



void func_8025B6F8_de(void *arg0, int arg1, int arg2) {
    Record_func_8025B758_de *slot = arg0;
    float k = D_800C9068;

    slot->f0C = -1;
    slot->f08 = -1;
    slot->f3A = -1;
    slot->f40 = -1;
    slot->fB4 = -1;
    slot->owner = arg1;
    slot->index = arg2;
    slot->f38 = 0;
    slot->f14 = 0;
    slot->f58 = 0;
    slot->f5C = 0;
    slot->fA4 = 0;
    slot->fAC = 0;
    slot->fBC = 0;
    slot->fC0 = 0;
    slot->fC4 = 1;
    slot->f2C = k;
    slot->f34 = k;
    slot->fB8 = k;
}
