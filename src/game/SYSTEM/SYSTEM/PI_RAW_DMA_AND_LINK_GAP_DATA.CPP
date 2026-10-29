#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "TYPES.H"
#include "COMMON/DEVICE_IO.H"
#include "sdk/OSINT/osyieldthread.H"

/* 802BE040_7.CPP */
#if defined(VERSION_DE)
unsigned char g_PiRawDmaAndLinkGapTrailingBytes[12] = { 0xAF, 0xB0, 0x00, 0x10, 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB2, 0x00, 0x18 };
#endif

/* 802BE040_57.CPP */
/* osEPiRawStartDma, drafted from ultralib src/io/epirawdma.c with the 2.0I EPI_SYNC of PRinternal/piint.h. */
extern OSPiHandle_s *g_peripheralDomainHandles[2];
s32 __osEPiRawStartDma(OSPiHandle_s *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    u32 stat;
    u32 domain;
    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3)
        stat = *(volatile u32 *)0xA4600010;
    domain = pihandle->domain;
    if (g_peripheralDomainHandles[domain] != pihandle) {
        OSPiHandle_s *cHandle = g_peripheralDomainHandles[domain];
        if (domain == 0) {
            if (cHandle->latency != pihandle->latency) IO_WRITE(0xA4600014, pihandle->latency);
            if (cHandle->pageSize != pihandle->pageSize) IO_WRITE(0xA460001C, pihandle->pageSize);
            if (cHandle->relDuration != pihandle->relDuration) IO_WRITE(0xA4600020, pihandle->relDuration);
            if (cHandle->pulse != pihandle->pulse) IO_WRITE(0xA4600018, pihandle->pulse);
        } else {
            if (cHandle->latency != pihandle->latency) IO_WRITE(0xA4600024, pihandle->latency);
            if (cHandle->pageSize != pihandle->pageSize) IO_WRITE(0xA460002C, pihandle->pageSize);
            if (cHandle->relDuration != pihandle->relDuration) IO_WRITE(0xA4600030, pihandle->relDuration);
            if (cHandle->pulse != pihandle->pulse) IO_WRITE(0xA4600028, pihandle->pulse);
        }
        g_peripheralDomainHandles[domain] = pihandle;
    }
    IO_WRITE(0xA4600000, osVirtualToPhysical(dramAddr));
    IO_WRITE(0xA4600004, (pihandle->baseAddress | devAddr) & 0x1FFFFFFF);
    switch (direction) {
        case 0:
            IO_WRITE(0xA460000C, size - 1);
            break;
        case 1:
            IO_WRITE(0xA4600008, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int k_PiRawDmaAndLinkGapEncodedWords[3] = {
    0x00080018, 0x001C0000, 0x0000000E,
};
#endif
