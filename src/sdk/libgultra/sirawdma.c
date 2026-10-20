#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/UNUSED.H"
#include "COMMON/DEVICE_IO.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "AUDIO_3/802BEE60.H"
#include "sdk/os.h"
#include "SDK/OSINT/802C0CB0.H"

extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);
extern int func_802B9D70_de(void);
extern void func_802BD280_de(void *addr, s32 size);
extern void func_802BCF70_de(void *addr, s32 size);


s32 __osSiRawStartDma(s32 direction, void *dramAddr) {
    if ((u32)dramAddr & 3) {
        func_802BAC50_de(&D_800C7990_de, &D_800C7994_de, 0x37);
    }
    if (func_802B9D70_de() != 0) {
        return -1;
    }
    if (direction == 1) {
        func_802BD280_de(dramAddr, 0x40);
    }
    IO_WRITE(0xA4800000U, func_802BBBC0_de(dramAddr));
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
INCLUDE_DATA("span_1000", rodata_unresolved_802B9C98);
#endif
