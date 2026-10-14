#include "span_1000/code_802B8DD0.h"
#include "types.h"
#include "device_io.h"
/* osEPiRawStartDma, drafted from ultralib src/io/epirawdma.c with the 2.0I EPI_SYNC of PRinternal/piint.h. */
extern OSPiHandle_s_func_802B93B0_de *D_800D4380[2];
extern u32 func_802BBBC0_de(void *addr);
s32 func_802B93B0_de(OSPiHandle_s_func_802B93B0_de *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    u32 stat;
    u32 domain;
    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3)
        stat = *(volatile u32 *)0xA4600010;
    domain = pihandle->domain;
    if (D_800D4380[domain] != pihandle) {
        OSPiHandle_s_func_802B93B0_de *cHandle = D_800D4380[domain];
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
        D_800D4380[domain] = pihandle;
    }
    IO_WRITE(0xA4600000, func_802BBBC0_de(dramAddr));
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
