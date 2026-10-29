#ifndef SYSTEM_EVENTS_COMPUTEDAMAGESCALE_H
#define SYSTEM_EVENTS_COMPUTEDAMAGESCALE_H
#include "COMMON/TARGET.H"
#include "SYSTEM/EVENT_DAMAGE_AND_IMPACT_VIEWS.H"
extern void Events_RequestActorPosition(s32 source, void *target, s32 kind, CVector3 position, struct IntPair positionParams);
extern void Events_ConsumeEventArgument(int unused0, int unused1, int unused2, int eventArgument);
extern void Events_PreserveEventArgument(int unused0, int unused1, int unused2, int eventArgument);
extern void Events_StartCameraFadeAtPoint(s32 unused0, s32 unused1, s32 unused2, Triple testPoint, CEventValueFormat7a fadeParams);
#endif
