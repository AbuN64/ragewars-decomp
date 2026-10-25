#include "include_asm.h"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/EXTERNS_16.H"
#include "sdk/MATH/802BC3B0.H"

 /* 0.5, followed by 2^31 */



s32 func_802B72E0_de(u32 frequency)
{
    register unsigned int dacRate;
    register unsigned char bitRate;
    register float f;
    f64 wide;
    float clock;

    wide = (s32)frequency;
    clock = D_800D5250;
    if ((s32)frequency < 0) {
        wide += D_800C7920_de;
    }
    f = clock / (float)wide + D_800C7928_de;
    if (f >= D_800C792C_de) {
        goto large;
    }
    dacRate = (s32)f;
    goto converted;
large:
    dacRate = (s32)(f - D_800C792C_de);
    dacRate |= 0x80000000;
converted:

    if (dacRate < 132) {
        return -1;
    }

    bitRate = dacRate / 66;
    if (bitRate > 16) {
        bitRate = 16;
    }

    IO_READ_WORD(0xA4500010U) = dacRate - 1;
    IO_READ_WORD(0xA4500014U) = bitRate - 1;
    IO_READ_WORD(0xA4500008U) = 1;
    return D_800D5250 / (s32)dacRate;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B7328[2] = {
    0x00B80000, 0x00080006,
};
#endif
