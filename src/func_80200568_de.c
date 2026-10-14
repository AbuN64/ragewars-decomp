#include "hardware_io.h"

void func_80200568_de(s32 address, s32 value) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    *(s32 *)address = value;
}
