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

extern volatile s32 g_libsnDelayIteration;

void Libsn_SpinDelay(s32 iterationCount) {
    for (g_libsnDelayIteration = 0; g_libsnDelayIteration < iterationCount; g_libsnDelayIteration++) {
    }
}
