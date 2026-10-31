#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include <ultra64.h>
#include "TYPES.H"
#include "../../include/libgultra.h"
#include "../../include/libultra/io/si.h"
#include <PR/os_internal_reg.h>
#include <PR/os_internal_si.h>
#include "../../include/libultra/debug/assert.h"

extern void osWritebackDCache(void *addr, s32 size);
extern void osInvalDCache(void *addr, s32 size);


s32 __osSiRawStartDma(s32 direction, void *dramAddr) {
    if ((u32)dramAddr & 3) {
        __assert(&g_serialDmaAssertText, &s_sirawdmaText, 0x37);
    }
    if (__osSiDeviceBusy() != 0) {
        return -1;
    }
    if (direction == 1) {
        osWritebackDCache(dramAddr, 0x40);
    }
    IO_WRITE(0xA4800000U, osVirtualToPhysical(dramAddr));
    if (direction == 0) {
        IO_WRITE(0xA4800004U, 0x1FC007C0U);
    } else {
        IO_WRITE(0xA4800010U, 0x1FC007C0U);
    }
    if (direction == 0) {
        osInvalDCache(dramAddr, 0x40);
    }
    return 0;
}

