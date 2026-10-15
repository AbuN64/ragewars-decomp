#include "types.h"
#include "span_1000/code_80200610.h"



void func_80200B14_de(s32 source, s32 destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        func_80200AD8_de(destination++, (u8)func_80200800_de(source++));
        count--;
    }
    while (count >= 4) {
        u32 word = func_802005A0_de(source);
        func_80200AD8_de(destination++, word >> 24);
        func_80200AD8_de(destination++, (word >> 16) & 0xFF);
        func_80200AD8_de(destination++, (word >> 8) & 0xFF);
        func_80200AD8_de(destination++, word & 0xFF);
        source += 4;
        count -= 4;
    }
    while (count != 0) {
        func_80200AD8_de(destination++, (u8)func_80200800_de(source++));
        count--;
    }
}
