#ifndef FRONTEND_FRONTEND_DISPATCHPLAYERCOUNTEVENT_H
#define FRONTEND_FRONTEND_DISPATCHPLAYERCOUNTEVENT_H
#include "COMMON/SETTINGSRECAT24.H"
/* The one object D_800E5430 points to; the settings screens each read their own fields of it. */
typedef struct SettingsScreenState {
    struct StateFrontendUpdatePlayerCountScreen head; /* 0x0: menu, list, delay, target */
    char text[0xC]; /* 0x14 */
    s32 count; /* 0x20, also the counter value */
} SettingsScreenState;
extern s32 Frontend_DispatchPlayerCountEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
