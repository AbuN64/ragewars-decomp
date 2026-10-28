#include "COMMON/OSPIHANDLE_S.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/OSINT/802C0CB0.H"

/* osPiRawStartDma, drafted from ultralib src/io/pirawdma.c (2.0I, where __osPiRawStartDma is osPiRawStartDma). */


s32 Gamecore_StartRawPeripheralDma(s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    register u32 stat;

    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3)
        stat = *(volatile u32 *)0xA4600010;

    *(volatile u32 *)0xA4600000 = osVirtualToPhysical(dramAddr);
    *(volatile u32 *)0xA4600004 = (D_80000308 | devAddr) & 0x1FFFFFFF;

    switch (direction) {
        case 0:
            *(volatile u32 *)0xA460000C = size - 1;
            break;
        case 1:
            *(volatile u32 *)0xA4600008 = size - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
