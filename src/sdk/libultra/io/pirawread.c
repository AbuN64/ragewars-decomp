#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/ALFXPARAM.H"
#include "sdk/libultra/io/pirawread.H"
#include "AUDIO/AUDIO_ASSERT.H"



s32 osPiRawReadIo(s32 deviceOffset, s32 *outputWord) {
    u32 status;

    if (outputWord == 0) {
        Audio_Assert(&D_800C7970_de, &s_pirawreadText, 0x3D);
    }
    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *outputWord = *(s32 *)(D_80000308 | deviceOffset | 0xA0000000);
    return 0;
}

#if defined(VERSION_US)
char rodata_unresolved_802B9AE4[12] =
    "ModeInfo_t\004.";
#endif
