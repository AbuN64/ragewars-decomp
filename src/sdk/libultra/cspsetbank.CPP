#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"

extern s32 func_802B00D4_de(void *, s16 *, s32);

void alCSPSetBank(s32 player, s32 bank) {
    Buf16 bankEvent;

    bankEvent.value = bank;
    bankEvent.count = 0xE;
    func_802B00D4_de(player + 0x48, &bankEvent, 0);
}


void alCSPSetChlFXMix(s32 player, s32 channel, s8 effectMix) {
    Buf16c controlEvent;

    controlEvent.count = 2;
    controlEvent.f8 = (s8)(channel | 0xB0);
    controlEvent.fA = effectMix;
    controlEvent.zero = 0;
    controlEvent.f9 = 0x5B;
    func_802B00D4_de(player + 0x48, &controlEvent, 0);
}

#if defined(VERSION_US)
char rodata_unresolved_802AFE54[12] =
    "FPair_t\010m_XP";
#endif
