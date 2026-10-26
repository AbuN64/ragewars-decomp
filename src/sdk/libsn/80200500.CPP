#include "COMMON/HARDWARE_IO.H"
#include "IO/EXTERNS.H"
#include "COMMON/OBJ.H"
#include "TYPES.H"
#include "include_asm.h"

s32 Libsn_ReadPortWord(s32 portAddress) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    return IO_READ_WORD(portAddress);
}

extern volatile s32 D_800F1C80_de;

void Libsn_SpinDelay(s32 iterationCount) {
    for (D_800F1C80_de = 0; D_800F1C80_de < iterationCount; D_800F1C80_de++) {
    }
}
