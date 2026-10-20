#ifndef FRONTEND_80423280_59_H
#define FRONTEND_80423280_59_H
#include "COMMON/SETTINGSRECAT24.H"
/* The one object D_800E5430 points to; the settings screens each read their own fields of it. */
typedef struct SettingsScreenState {
    struct State_func_8042DAF8_de head; /* 0x0: menu, list, delay, target */
    char text[0xC]; /* 0x14 */
    s32 count; /* 0x20, also the counter value */
} SettingsScreenState;
extern s32 func_8042DE10_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
