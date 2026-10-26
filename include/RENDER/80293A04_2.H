#ifndef RENDER_80293A04_2_H
#define RENDER_80293A04_2_H
#include "COMMON/INTEGERSTATEB0.H"
struct GameSession;
extern void SetN64_DrawRoundTimeoutSession(struct GameSession *session);
extern void SetN64_AdvanceToModeFour(struct GameSession *value);
extern void SetN64_InitializeMode2(void);
extern void SetN64_OnMode5DrawComplete(s32 session);
extern void SetN64_AdvanceToModeFive(struct GameSession *arg0);
extern void SetN64_DrawIntroBackdrop(void);
extern s32 SetN64_CheckTimedSessionTransition(struct GameSession *session, f32 limit, s32 arg2, s32 arg3);
extern void Scene_ResetTransitionViewport(void);
extern void SetN64_DrawSessionWithAttractTimeout(void *session);
#endif
