#ifndef FRONTEND_FRONTEND_ACTIVATEMATCHOPTIONACTION_H
#define FRONTEND_FRONTEND_ACTIVATEMATCHOPTIONACTION_H
#include "COMMON/RECRECAT4.H"
#include "FRONTEND/OPTIONS.H"
extern void Frontend_SyncMatchJoinSlots(s32);
extern void Frontend_LoadMatchOptionWidgets(void);
extern void Frontend_StoreMatchOptionWidgets(void);
extern s32 Frontend_DispatchMatchOptionsEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
