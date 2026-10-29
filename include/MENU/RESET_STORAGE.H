#ifndef MENU_RESET_STORAGE_H
#define MENU_RESET_STORAGE_H
#include "TYPES.H"
typedef struct {
    u8 padding_0[4];
    f32 closeDelay;
    u8 padding_8[884];
    s32 unk37C;
} ResetTimerStorage;
typedef struct {
    u8 padding_0[1688];
    void * controller;
} ResetOwnerStorage;
typedef struct {
    u8 padding_0[176];
    s32 buttons;
} ResetFlagsStorage;
#endif
