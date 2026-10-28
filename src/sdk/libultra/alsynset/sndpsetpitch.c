#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern s32 alEvtqPostEvent(void *, s16 *, s32);




void alSndpSetPitch(struct ObjRecAt40V2 *soundPlayer, s32 pitchBits) {
    ParamsRecAt8V3 p;
    s32 acc;

    acc = soundPlayer->field40;
    p.f0 = 4;
    acc += soundPlayer->field3C * 0x30;
    p.f8 = pitchBits;
    p.f4 = acc;
    alEvtqPostEvent(&soundPlayer->events, (s16 *)&p, 0);
}
