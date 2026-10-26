#ifndef MATH_MATH_CONTROLLER_EVENTS_H
#define MATH_MATH_CONTROLLER_EVENTS_H
#include "COMMON/CALLBACK.H"
#include "MATH/8029AE80.H"

extern void DispatchControllerAxisEvents(ControllerEvent *event);
extern void Smos_DispatchControllerEvent(ControllerEvent *event);
extern void DispatchControllerButtonEvent(ControllerEvent *event);
extern void Smos_SendControllerButtonEvent(s16 port, s16 control, s32 pressed);
extern void Smos_SendControllerStickEvent(s16 port, s32 stick_x, s32 stick_y);

extern void Smos_SetControllerEventFilter(s32 (*arg0)(void));

extern void Smos_AllocateControllerContext();
extern void Smos_FreeControllerContext();
#endif
