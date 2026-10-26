#include "TYPES.H"
#include "COMMON/EXTERNS_15.H"
#include "IO/80200800.H"

int Libsn_ReadPortByte(int arg0) {
    u32 shift = (~arg0 & 3) << 3;
    u32 word = Libsn_ReadPortWord(arg0 & ~3);

    return (word >> shift) & 0xFF;
}

/* Signature follows the published cartridge word reader implementation. */


int Libsn_ReadTransferPortByte(int arg0) {
    int shift = (~arg0 & 3) << 3;
    return ((u32)Libsn_ReadPortWord(arg0 & -4) >> shift) & 0xFF;
}



void Libsn_ReadPortBuffer(s32 source, u8 *destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        *destination++ = Libsn_ReadPortByte(source++);
        count--;
    }
    while (count >= 4) {
        u32 word = Libsn_ReadPortWord(source);
        *destination++ = word >> 24;
        *destination++ = word >> 16;
        *destination++ = word >> 8;
        *destination++ = word;
        source += 4;
        count -= 4;
    }
    while (count != 0) {
        *destination++ = Libsn_ReadPortByte(source++);
        count--;
    }
}
