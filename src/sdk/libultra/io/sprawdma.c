#include "COMMON/UNUSED.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/EXTERNS_2.H"
#include "TYPES.H"
#include "sdk/libultra/io/sprawdma.H"
#include "sdk/libgultra/sp.h"
#include "sdk/OSINT/802C0CB0.H"
#include "AUDIO_3/802BFD40.H"


s32 func_802B9FD0_de(s32 direction, s32 deviceAddress, s32 dramAddress, s32 size) {
    if (deviceAddress & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3A);
    }
    if (dramAddress & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3B);
    }
    if (size & 7) {
        func_802BAC50_de(&D_800C79B0_de, &D_800C79B4_de, 0x3C);
    }
    if (__osSpDeviceBusy() != 0) {
        return -1;
    }
    IO_READ_WORD(0xA4040000U) = deviceAddress;
    IO_READ_WORD(0xA4040004U) = func_802BBBC0_de(dramAddress);
    if (direction == 0) {
        IO_READ_WORD(0xA404000CU) = size - 1;
    } else {
        IO_READ_WORD(0xA4040008U) = size - 1;
    }
    return 0;
}
