#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/EXTERNS_16.H"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra/ai.h"
#include "sdk/OSINT/802C0CB0.H"

/* Queues an audio buffer for the AI DMA, backing the address up 0x2000 bytes after a buffer that ended on an 8 KiB boundary, returning -1 when __osAiDeviceBusy reports the interface busy and zero after writing the physical address from func_802BBBC0_de and the length to the AI registers (libultra osAiSetNextBuffer). Adapted from func_802BB060_de with the argument checks replaced by the boundary flag byte D_800D8360 read through its array declaration, the busy test by __osAiDeviceBusy, and the uncached read by two AI register writes. */


s32 func_802B7400_de(void *bufPtr, u32 size) {
    char *bptr = bufPtr;

    if (D_800D8360[0] != 0) {
        bptr -= 0x2000;
    }
    if ((((u32)bufPtr + size) & 0x1FFF) == 0) {
        D_800D8360[0] = 1;
    } else {
        D_800D8360[0] = 0;
    }
    if (__osAiDeviceBusy() != 0) {
        return -1;
    }
    *(volatile u32 *)0xA4500000 = func_802BBBC0_de(bptr);
    *(volatile u32 *)0xA4500004 = size;
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B73BC[1] = {
    0x72616374,
};
#endif

#if defined(VERSION_EU)
unsigned char D_auto_func_802B772C_eu_padding_B832C[4] = { 0x8C, 0xA2, 0x00, 0x00 };
#endif

#if defined(VERSION_DE)
void func_802B748C_de(void) {}
#endif
