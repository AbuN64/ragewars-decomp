#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern void alEvtqPostEvent(ALEventQueue *, void *, s32);




void alSndpStop(SoundPlayerEventStateView *soundPlayer) {
    s32 soundStateBase;
    Buf16 stopEvent;

    soundStateBase = soundPlayer->eventTime;
    stopEvent.count = 1;
    stopEvent.value = soundStateBase + (soundPlayer->frameSampleCount * 0x30);
    alEvtqPostEvent(&soundPlayer->events, &stopEvent, 0);
}

#if defined(VERSION_US)
char s_SndpstopRientTText[8] =
    "rientT\000\000";
#endif
