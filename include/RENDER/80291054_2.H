#ifndef RENDER_80291054_2_H
#define RENDER_80291054_2_H
#include "COMMON/SESSIONHANDLERROW.H"
extern void SetN64_BeginFrameDisplayList(void *world);
struct GameSession;
extern void SetN64_RunGameLoop(struct GameSession *session);
#endif
