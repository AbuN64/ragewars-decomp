#include "COMMON/RUNTIME_DECLARATIONS.H"
#include <ultra64.h>
#include "COMMON/ALFXPARAM.H"
#include "TYPES.H"
#include <PR/os_internal_rsp.h>
#include "../../include/libgultra/sp.h"
#include "../../include/libultra/debug/assert.h"


s32 __osSpRawStartDma(s32 direction, u32 deviceAddress, void *dramAddress, u32 size) {
    if (deviceAddress & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3A);
    }
    if ((u32)dramAddress & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3B);
    }
    if (size & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3C);
    }
    if (__osSpDeviceBusy() != 0) {
        return -1;
    }
    IO_WRITE(0xA4040000U, deviceAddress);
    IO_WRITE(0xA4040004U, osVirtualToPhysical(dramAddress));
    if (direction == 0) {
        IO_WRITE(0xA404000CU, size - 1);
    } else {
        IO_WRITE(0xA4040008U, size - 1);
    }
    return 0;
}
