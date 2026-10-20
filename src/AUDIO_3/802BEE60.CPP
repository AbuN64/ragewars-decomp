#include "TYPES.H"
#include "COMMON/ARG.H"
#include "AUDIO_3/802BEE60.H"

/** Report whether either low bit of the VI current register is set. */
int func_802B9D70_de(void) {
    return (*(volatile unsigned int *)0xA4800018 & 3) != 0;
}
