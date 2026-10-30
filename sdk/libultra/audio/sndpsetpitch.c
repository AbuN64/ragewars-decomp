#include "../../include/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern s32 alEvtqPostEvent(void *, s16 *, s32);




void alSndpSetPitch(struct SoundPlayerEventStateView *soundPlayer, s32 pitchBits) {
    SoundPlayerWordParameterEvent p;
    s32 acc;

    acc = soundPlayer->eventTime;
    p.f0 = 4;
    acc += soundPlayer->frameSampleCount * 0x30;
    p.f8 = pitchBits;
    p.f4 = acc;
    alEvtqPostEvent(&soundPlayer->events, (s16 *)&p, 0);
}
