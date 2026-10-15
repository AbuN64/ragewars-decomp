#include "types.h"
#include "span_1000/code_80200610.h"



int func_80200800_de(int arg0) {
    u32 shift = (~arg0 & 3) << 3;
    u32 word = func_802005A0_de(arg0 & ~3);

    return (word >> shift) & 0xFF;
}

/* Signature follows the published cartridge word reader implementation. */


int func_80200840_de(int arg0) {
    int shift = (~arg0 & 3) << 3;
    return ((u32)func_802005A0_de(arg0 & -4) >> shift) & 0xFF;
}



void func_80200880_de(s32 source, u8 *destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        *destination++ = func_80200800_de(source++);
        count--;
    }
    while (count >= 4) {
        u32 word = func_802005A0_de(source);
        *destination++ = word >> 24;
        *destination++ = word >> 16;
        *destination++ = word >> 8;
        *destination++ = word;
        source += 4;
        count -= 4;
    }
    while (count != 0) {
        *destination++ = func_80200800_de(source++);
        count--;
    }
}
