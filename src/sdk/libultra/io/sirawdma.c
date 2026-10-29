#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/DEVICE_IO.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "AUDIO/SIRAW.H"
#include "sdk/os.h"
#include "sdk/OSINT/osyieldthread.H"
#include "AUDIO/AUDIO_ASSERT.H"

extern void osWritebackDCache(void *addr, s32 size);
extern void osInvalDCache(void *addr, s32 size);


s32 __osSiRawStartDma(s32 direction, void *dramAddr) {
    if ((u32)dramAddr & 3) {
        Audio_Assert(&g_serialDmaAssertText, &s_sirawdmaText, 0x37);
    }
    if (Audio_IsSerialInterfaceBusy() != 0) {
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

#if defined(VERSION_US)
unsigned int k_SirawdmaEncodedWords[2] = {
    0x6D655200, 0x00580600,
};
#endif
