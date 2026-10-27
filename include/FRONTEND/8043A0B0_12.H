#ifndef FRONTEND_8043A0B0_12_H
#define FRONTEND_8043A0B0_12_H
#include "FRONTEND/ENTRYRECAT4D4.H"
extern s32 Frontend_GetMenuImageFrame(s32 *record);
extern s32 Frontend_IsMenuImageTransitionComplete(s32 *record);
extern void Frontend_SetMenuImageResource(s32 *, s32);
extern void Frontend_SetMenuImageColor(s32 *, s32, s32, s32);
extern void Frontend_AdvanceMenuImageTransition(s32*record);
#endif
