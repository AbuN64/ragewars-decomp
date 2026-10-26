#ifndef RENDER_80293A04_2_H
#define RENDER_80293A04_2_H
#include "COMMON/INTEGERSTATEB0.H"
struct GameSession;
extern void func_80293E9C_de(struct GameSession *session);
extern void func_802940F8_de(struct GameSession *value);
extern void func_8029412C_de(void);
extern void func_80293DE8_de(s32 session);
extern void func_80294134_de(struct GameSession *arg0);
extern void func_80293FF0_de(void);
extern s32 SetN64_CheckTimedSessionTransition(struct GameSession *session, f32 limit, s32 arg2, s32 arg3);
extern void Scene_ResetTransitionViewport(void);
extern void SetN64_DrawSessionWithAttractTimeout(void *session);
#endif
