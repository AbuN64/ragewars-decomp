#include "types.h"
#include "span_16E000/code_804143D8.h"


/* Spins forever unless arg0 is 5, calling func_802BA1B0_de with bit 20 of a running counter each pass. */
void func_80415C1C_de(s32 arg0) {
    s32 i = 0;

    while (arg0 != 5) {
        s32 bit = i & 0x100000;

        i++;
        func_802BA1B0_de(bit != 0);
    }
}
