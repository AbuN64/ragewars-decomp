#include "TYPES.H"
#include "COMMON/EXTERNS_15.H"
#include "IO/80200800.H"
#include "IO/80200800_2.H"

void func_80200B14_de(s32 source, s32 destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        func_80200AD8_de(destination++, (u8)func_80200800_de(source++));
        count--;
    }
    while (count >= 4) {
        u32 word = Libsn_ReadPortWord(source);
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
