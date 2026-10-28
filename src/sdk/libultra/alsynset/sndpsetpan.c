#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern s32 alEvtqPostEvent(void *, s16 *, s32);




void alSndpSetPan(struct ObjRecAt40V2 *soundPlayer, u8 pan) {
    ParamsRecAt8V2 p;
    s32 acc;

    acc = soundPlayer->field40;
    p.f0 = 2;
    p.f8 = pan;
    acc += soundPlayer->field3C * 0x30;
    p.f4 = acc;
    alEvtqPostEvent(&soundPlayer->events, (s16 *)&p, 0);
}
