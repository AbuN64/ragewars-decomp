#ifndef MATH_8029AE80_H
#define MATH_8029AE80_H
#include "COMMON/CALLBACK.H"
#include "MATH/8029AE80.H"
extern void DispatchControllerAxisEvents(ControllerEvent *event);
extern void func_8029A558_de(ControllerEvent *event);
extern void func_80299E80_de(ControllerEvent *event);
extern void func_8029AAD8_de(s16 port, s16 control, s32 pressed);
extern void func_8029AB24_de(s16 port, s32 stick_x, s32 stick_y);
#endif
