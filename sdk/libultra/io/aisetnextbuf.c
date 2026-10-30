#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/GUMTXL2F.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "../../include/libgultra/ai.h"
#include "../../include/OSINT/osyieldthread.H"

/* Queues an audio buffer for the AI DMA, backing the address up 0x2000 bytes after a buffer that ended on an 8 KiB boundary, returning -1 when __osAiDeviceBusy reports the interface busy and zero after writing the physical address from osVirtualToPhysical and the length to the AI registers (libultra osAiSetNextBuffer). Adapted from __osSiRawReadIo with the argument checks replaced by the boundary flag byte g_audioDmaBoundaryWorkaroundFlag read through its array declaration, the busy test by __osAiDeviceBusy, and the uncached read by two AI register writes. */


s32 osAiSetNextBuffer(void *bufPtr, u32 size) {
    char *bptr = bufPtr;

    if (g_audioDmaBoundaryWorkaroundFlag[0] != 0) {
        bptr -= 0x2000;
    }
    if ((((u32)bufPtr + size) & 0x1FFF) == 0) {
        g_audioDmaBoundaryWorkaroundFlag[0] = 1;
    } else {
        g_audioDmaBoundaryWorkaroundFlag[0] = 0;
    }
    if (__osAiDeviceBusy() != 0) {
        return -1;
    }
    *(volatile u32 *)0xA4500000 = osVirtualToPhysical(bptr);
    *(volatile u32 *)0xA4500004 = size;
    return 0;
}

#if defined(VERSION_US)
unsigned int k_AisetnextbufEncodedWords[1] = {
    0x72616374,
};
#endif

#if defined(VERSION_EU)
unsigned char g_AisetnextbufTrailingBytes[4] = { 0x8C, 0xA2, 0x00, 0x00 };
#endif

#if defined(VERSION_DE)
unsigned char g_AisetnextbufTrailingBytes[4] = { 0x03, 0xE0, 0x00, 0x08 };
#endif
