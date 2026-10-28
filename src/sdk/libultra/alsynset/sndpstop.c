#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern void alEvtqPostEvent(ALEventQueue *, void *, s32);




void alSndpStop(ObjRecAt40V2 *soundPlayer) {
    s32 new_var;
    Buf16 stopEvent;

    new_var = soundPlayer->field40;
    stopEvent.count = 1;
    stopEvent.value = new_var + (soundPlayer->field3C * 0x30);
    alEvtqPostEvent(&soundPlayer->events, &stopEvent, 0);
}

#if defined(VERSION_US)
char rodata_unresolved_802B2ED8[8] =
    "rientT\000\000";
#endif
