#ifndef MENU_2_80420E90_3_H
#define MENU_2_80420E90_3_H
#include "COMMON/NUMBERPADSCREEN.H"
extern s32 Menu_GetFadeMeterDone(s32 *record);
extern s32 Menu_AdvanceFadeMeter(struct Meter *meter, s32 step);
extern s32 Menu_DispatchSixChoiceEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void Menu_SetFadeMeterDirection(struct Triple *timer, s32 mode);
extern void Menu_InitializeFadeMeter(struct RecGobjinstSampleBoneTranslation *record, s32 value);
#endif
