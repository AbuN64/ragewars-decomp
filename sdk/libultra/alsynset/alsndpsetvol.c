#include "include_asm.h"
#include "../../include/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"

void alSndpSetSound(ALSndPlayer *soundPlayer, s16 soundId) {
    soundPlayer->target = (s32) soundId;
}

extern s32 alEvtqPostEvent(void *, s16 *, s32);




void alSndpSetVol(ALSndPlayer *soundPlayer, s16 eventVolume) {
    ParamsRecAt8V1 p;
    s32 acc;

    acc = (s32)soundPlayer->sndState;
    p.f0 = 3;
    acc += soundPlayer->target * 0x30;
    p.f8 = eventVolume;
    p.f4 = acc;
    alEvtqPostEvent(&soundPlayer->evtq, (s16 *)&p, 0);
}

#if defined(VERSION_US)
unsigned int func_802B2F10_de_padding_B3A8C[1] = {
    0x00000000,
};
#endif
