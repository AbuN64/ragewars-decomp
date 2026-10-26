#ifndef UI_TSMOS_SMP_SMP_FLICKER_H
#define UI_TSMOS_SMP_SMP_FLICKER_H
#include "COMMON/ANIMATION.H"

extern void SmpFlicker_RegisterFlickerClass();

extern s32 SmpFlicker_DispatchEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void SmpFlicker_IgnoreEvent(s32 arg0, struct Triple arg1);
#endif
