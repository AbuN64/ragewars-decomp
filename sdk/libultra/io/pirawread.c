#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "TYPES.H"
#include "COMMON/ALFXPARAM.H"
#include "../../include/libultra/io/pirawread.H"
#include "../../include/libultra/debug/assert.h"



s32 osPiRawReadIo(s32 deviceOffset, s32 *outputWord) {
    u32 status;

    if (outputWord == 0) {
        __assert(&g_peripheralReadAssertText, &s_pirawreadText, 0x3D);
    }
    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *outputWord = *(s32 *)(g_cartridgeRomBaseAddress | deviceOffset | 0xA0000000);
    return 0;
}

