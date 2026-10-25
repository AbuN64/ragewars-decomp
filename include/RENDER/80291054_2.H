#ifndef RENDER_80291054_2_H
#define RENDER_80291054_2_H
#include "COMMON/SESSIONHANDLERROW.H"
extern float Render_BeginFrameDisplayList(void *world);
struct GameSession;
extern void Render_RunGameLoop(struct GameSession *session);
#endif
