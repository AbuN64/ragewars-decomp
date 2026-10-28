#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/UNUSED.H"
#include "COMMON/DEVICE_IO.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "AUDIO/SIRAW.H"
#include "sdk/os.h"
#include "sdk/OSINT/osyieldthread.H"
#include "AUDIO/802BFD40.H"

extern void func_802BD280_de(void *addr, s32 size);
extern void func_802BCF70_de(void *addr, s32 size);


s32 __osSiRawStartDma(s32 direction, void *dramAddr) {
    if ((u32)dramAddr & 3) {
        Audio_Assert(&D_800C7990_de, &s_sirawdmaText, 0x37);
    }
    if (Audio_IsSerialInterfaceBusy() != 0) {
        return -1;
    }
    if (direction == 1) {
        func_802BD280_de(dramAddr, 0x40);
    }
    IO_WRITE(0xA4800000U, osVirtualToPhysical(dramAddr));
    if (direction == 0) {
        IO_WRITE(0xA4800004U, 0x1FC007C0U);
    } else {
        IO_WRITE(0xA4800010U, 0x1FC007C0U);
    }
    if (direction == 0) {
        func_802BCF70_de(dramAddr, 0x40);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B9C98[2] = {
    0x6D655200, 0x00580600,
};
#endif
