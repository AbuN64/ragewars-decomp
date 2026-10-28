#ifndef SYSTEM_EVENTS_COMPUTEDAMAGESCALE_H
#define SYSTEM_EVENTS_COMPUTEDAMAGESCALE_H
#include "COMMON/TARGET.H"
#include "SYSTEM/802661FC.H"
extern void Events_RequestActorPosition(s32 source, void *target, s32 kind, CVector3 position, struct IntPair arg6);
extern void Events_ConsumeEventArgument(int unused0, int unused1, int unused2, int arg3);
extern void Events_PreserveEventArgument(int unused0, int unused1, int unused2, int arg3);
extern void Events_StartCameraFadeAtPoint(s32 unused0, s32 unused1, s32 unused2, Triple testPoint, CEventValueFormat7a arg6);
#endif
