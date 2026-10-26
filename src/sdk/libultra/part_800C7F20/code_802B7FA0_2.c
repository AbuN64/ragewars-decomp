#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"

void func_802B2F00_de(ALSndPlayer *soundPlayer, s16 soundId) {
    soundPlayer->target = (s32) soundId;
}

extern s32 func_802B00D4_de(void *, s16 *, s32);




void func_802B2F10_de(ALSndPlayer *soundPlayer, s16 eventVolume) {
    ParamsRecAt8V1 p;
    s32 acc;

    acc = (s32)soundPlayer->sndState;
    p.f0 = 3;
    acc += soundPlayer->target * 0x30;
    p.f8 = eventVolume;
    p.f4 = acc;
    func_802B00D4_de(&soundPlayer->evtq, (s16 *)&p, 0);
}

#if defined(VERSION_US)
unsigned int func_802B2F10_de_padding_B3A8C[1] = {
    0x00000000,
};
#endif
