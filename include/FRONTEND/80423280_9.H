#ifndef FRONTEND_80423280_9_H
#define FRONTEND_80423280_9_H
#include "COMMON/RECRECAT4.H"
#include "FRONTEND/OPTIONS.H"
extern void Frontend_SyncMatchJoinSlots(s32);
extern void Frontend_LoadMatchOptionWidgets();
extern void Frontend_StoreMatchOptionWidgets();
extern s32 Frontend_DispatchMatchOptionsEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
