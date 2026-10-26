#include "TYPES.H"
#include "COMMON/EXTERNS_15.H"
#include "IO/80200800.H"
#include "IO/80200800_2.H"

void Libsn_CopyPortToWordMemory(s32 source, s32 destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        Libsn_WriteMemoryByte(destination++, (u8)Libsn_ReadPortByte(source++));
        count--;
    }
    while (count >= 4) {
        u32 word = Libsn_ReadPortWord(source);
        Libsn_WriteMemoryByte(destination++, word >> 24);
        Libsn_WriteMemoryByte(destination++, (word >> 16) & 0xFF);
        Libsn_WriteMemoryByte(destination++, (word >> 8) & 0xFF);
        Libsn_WriteMemoryByte(destination++, word & 0xFF);
        source += 4;
        count -= 4;
    }
    while (count != 0) {
        Libsn_WriteMemoryByte(destination++, (u8)Libsn_ReadPortByte(source++));
        count--;
    }
}
