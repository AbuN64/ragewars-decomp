#ifndef ENGINE_SETN64_H
#define ENGINE_SETN64_H
#include "COMMON/SESSIONHANDLERROW.H"
extern void SetN64_BeginFrameDisplayList(void *world);
struct GameSession;
extern void SetN64_RunGameLoop(struct GameSession *session);
#endif
