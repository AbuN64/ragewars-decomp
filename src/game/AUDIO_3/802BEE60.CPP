#include "TYPES.H"
#include "COMMON/ARG.H"
#include "AUDIO/802BEE60.H"

/** Report whether either low bit of the VI current register is set. */
int Audio_IsSerialInterfaceBusy(void) {
    return (*(volatile unsigned int *)0xA4800018 & 3) != 0;
}
