#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/ALFXPARAM.H"
#include "TYPES.H"
#include "../../include/libultra/io/sprawdma.H"
#include "../../include/libgultra/sp.h"
#include "../../include/OSINT/osyieldthread.H"
#include "../../include/libultra/debug/assert.h"


s32 __osSpRawStartDma(s32 direction, s32 deviceAddress, s32 dramAddress, s32 size) {
    if (deviceAddress & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3A);
    }
    if (dramAddress & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3B);
    }
    if (size & 7) {
        __assert(&g_signalProcessorDmaAssertText, &s_sprawdmaText, 0x3C);
    }
    if (__osSpDeviceBusy() != 0) {
        return -1;
    }
    IO_READ_WORD(0xA4040000U) = deviceAddress;
    IO_READ_WORD(0xA4040004U) = osVirtualToPhysical(dramAddress);
    if (direction == 0) {
        IO_READ_WORD(0xA404000CU) = size - 1;
    } else {
        IO_READ_WORD(0xA4040008U) = size - 1;
    }
    return 0;
}
