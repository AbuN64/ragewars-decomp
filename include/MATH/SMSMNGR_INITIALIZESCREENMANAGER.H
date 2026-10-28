#ifndef MATH_80297CD0_3_H
#define MATH_80297CD0_3_H
#include "COMMON/INTEGERSTATE530.H"
extern void SmSmngr_InitializeCurrentScreen();
extern void SmSmngr_InitializeScreenManager(s32 screenCount, s32 value);
extern void SmSmngr_RegisterElementHandlers(s32 id, MenuElementHandler event_handler, MenuDrawHandler draw_handler, s32 flags);
#endif
