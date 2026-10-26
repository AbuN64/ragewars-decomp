#ifndef MATH_8029AE80_H
#define MATH_8029AE80_H
#include "COMMON/CALLBACK.H"
#include "MATH/8029AE80.H"
extern void DispatchControllerAxisEvents(ControllerEvent *event);
extern void Smos_DispatchControllerEvent(ControllerEvent *event);
extern void DispatchControllerButtonEvent(ControllerEvent *event);
extern void Smos_SendControllerButtonEvent(s16 port, s16 control, s32 pressed);
extern void Smos_SendControllerStickEvent(s16 port, s32 stick_x, s32 stick_y);
#endif
