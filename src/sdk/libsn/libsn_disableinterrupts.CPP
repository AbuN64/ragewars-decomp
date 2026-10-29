#include "IO/EXTERNS.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OBJ.H"
#include "TYPES.H"
#include "IO/libsn_disableinterrupts.H"

/* Libgultra_TrwGetSr: types.declaration: solved callee prototype */

/* Libgultra_TrwSetSr: types.declaration: solved callee prototype */

                                                  /* size = 0x18 */

s32 Libsn_DisableInterrupts(void) {
    s32 savedStatus;

    savedStatus = Libgultra_TrwGetSr();
    Libgultra_TrwSetSr(savedStatus & ~1);
    return savedStatus & 1;
}

                                                  /* size = 0x18 */

void Libsn_RestoreInterruptEnable(s32 savedInterruptEnable) {
    Libgultra_TrwSetSr(Libgultra_TrwGetSr() | savedInterruptEnable);
}

void Libsn_WritePortWord(s32 address, s32 value) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    *(s32 *)address = value;
}
