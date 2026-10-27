#ifndef CONTPAD_CONTPAD_H
#define CONTPAD_CONTPAD_H
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT5F14.H"
#include "FX/CONTROLLER_INPUT.H"
extern void ContPad_BuildControllerState(ControllerInput *input, Player *player);
extern void ContPad_InitControllerInput(void *input, s32 attributes);
extern s32 ContPad_SwapButtonPairs(s32);
#endif
