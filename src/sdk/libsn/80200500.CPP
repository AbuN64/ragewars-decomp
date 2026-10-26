#include "COMMON/HARDWARE_IO.H"
#include "IO/EXTERNS.H"
#include "COMMON/OBJ.H"
#include "TYPES.H"

s32 Libsn_ReadPortWord(s32 portAddress) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    return IO_READ_WORD(portAddress);
}
