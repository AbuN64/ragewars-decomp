#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "TYPES.H"
#include "COMMON/ALFXPARAM.H"
#include "../../include/libultra/io/pirawread.H"
#include "AUDIO/AUDIO_ASSERT.H"



s32 osPiRawReadIo(s32 deviceOffset, s32 *outputWord) {
    u32 status;

    if (outputWord == 0) {
        Audio_Assert(&g_peripheralReadAssertText, &s_pirawreadText, 0x3D);
    }
    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *outputWord = *(s32 *)(g_cartridgeRomBaseAddress | deviceOffset | 0xA0000000);
    return 0;
}

#if defined(VERSION_US)
char s_PirawreadModeInfoTText[12] =
    "ModeInfo_t\004.";
#endif
