#ifndef MENU_2_804196C0_21_H
#define MENU_2_804196C0_21_H
#include "MENU/SCROLL.H"
extern void SmpSlider_IgnoreFormattedMessage(void *target, const char *format, ...);
extern s32 SmpSlider_DispatchSliderEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void SmpSlider_RegisterSliderClass();
extern s32 SmpSlider_DispatchTransitionEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
