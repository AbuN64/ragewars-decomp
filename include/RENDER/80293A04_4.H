#ifndef RENDER_80293A04_4_H
#define RENDER_80293A04_4_H
#include "COMMON/INTEGERSTATEB0.H"
struct GameSession;
extern void SetN64_DrawMode6(void);
extern void SetN64_AdvanceToModeEight(struct GameSession *arg0);
extern void SetN64_ResetMode11Items(s32 arg0);
extern void SetN64_ResetMode9Items(int arg0);
extern void SetN64_UpdateMode6(void);
struct GameSession;
extern void SetN64_DrawMode8Session(struct GameSession *session);
extern void SetN64_DrawMode9Session(void *session);
extern void SetN64_HandleMode7Transition(struct GameSession *arg0);
extern void SetN64_UpdateMode8(void);
extern void SetN64_ResetMode4Effects(void);
extern void SetN64_ResetMode5Items(s32 arg0);
extern void SetN64_SetMode7AudioState(void);
extern void SetN64_InitializeMode6(void);
extern void SetN64_DrawMode4Backdrop(void);
#endif
