#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"

extern s32 alEvtqPostEvent(void *, s16 *, s32);




void alSndpPlay(ALSndPlayer *soundPlayer) {
    s32 base = (s32)soundPlayer->sndState;

    if (((ALSoundState *) (base + (soundPlayer->target * 0x30)))->state == 0) {
        ParamsRecAt8V1 p;
        p.f0 = 0;
        p.f4 = base + soundPlayer->target * 0x30;
        alEvtqPostEvent(&soundPlayer->evtq, (s16 *)&p, 0);
    }
}





void alSndpSetFXMix(ALSndPlayer *soundPlayer, s8 effectMix) {
    ParamsRecAt8V2 p;
    s32 acc;

    acc = (s32)soundPlayer->sndState;
    p.f0 = 8;
    acc += soundPlayer->target * 0x30;
    p.f8 = effectMix;
    p.f4 = acc;
    alEvtqPostEvent(&soundPlayer->evtq, (s16 *)&p, 0);
}
