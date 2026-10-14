#include "span_1000/code_80200400.h"
#include "hardware_io.h"

s32 func_802005A0_de(s32 arg0) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    return IO_READ_WORD(arg0);
}
