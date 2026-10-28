#ifndef SYSTEM_2_802661FC_2_H
#define SYSTEM_2_802661FC_2_H
#include "COMMON/TARGET.H"
#include "SYSTEM/802661FC.H"
extern void Events_RequestActorPosition(s32 source, void *target, s32 kind, CVector3 position, struct IntPair arg6);
extern void Events_ConsumeEventArgument(int arg0, int arg1, int arg2, int arg3);
extern void Events_PreserveEventArgument(int arg0, int arg1, int arg2, int arg3);
extern void Events_StartCameraFadeAtPoint(s32 arg0, s32 arg1, s32 arg2, Triple arg3, CEventValueFormat7a arg6);
#endif
