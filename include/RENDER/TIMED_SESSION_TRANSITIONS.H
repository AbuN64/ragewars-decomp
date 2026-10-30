#ifndef RENDER_TIMED_SESSION_TRANSITIONS_H
#define RENDER_TIMED_SESSION_TRANSITIONS_H
#include "COMMON/INTEGERSTATEB0.H"
struct GameSession;
extern void SetN64_DrawRoundTimeoutSession();
extern void SetN64_AdvanceToModeFour();
extern void SetN64_InitializeMode2(void);
extern void SetN64_OnMode5DrawComplete(s32 session);
extern void SetN64_AdvanceToModeFive();
extern void SetN64_DrawIntroBackdrop(void);
extern s32 SetN64_CheckTimedSessionTransition(struct GameSession *session, f32 limit, s32 eight, s32 transitionCode);
extern void Scene_ResetTransitionViewport(void);
extern void SetN64_DrawSessionWithAttractTimeout(void *session);
#endif
