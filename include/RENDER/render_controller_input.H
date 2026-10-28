#ifndef RENDER_RENDER_CONTROLLER_INPUT_H
#define RENDER_RENDER_CONTROLLER_INPUT_H

#include "TYPES.H"
struct ControllerProfile;
void Control_UpdateControllerInput(struct ControllerProfile *state, s8 x, s8 y, u32 buttons);

#endif
