#ifndef INSTHDR_INSTHDR_GETACTORSHADOWRADIUS_H
#define INSTHDR_INSTHDR_GETACTORSHADOWRADIUS_H
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/PROBE.H"
extern const unsigned int D_pad_func_8024E2C4_de[1];
extern f32 InstHdr_GetActorShadowRadius(Actor_u1 *actor);
extern f32 InstHdr_GetInactiveActorHeight(Actor_u1 *actor);
extern float func_8024E544_de(void *object);
extern void InstHdr_ProjectPositionToActorGround(void *actor, void *, void *);
extern int func_8024E610_de(void *actorStorage);
extern f32 InstHdr_GetActorTargetHeight(u8 *);
extern int InstHdr_GetActorMotionFlags(void *levelActor);
extern float func_8024E864_de(void);
extern f32 InstHdr_GetActorTriangleTopOffset(void *);
extern f32 InstHdr_GetActorTriangleBottomOffset(void *);
extern s32 func_8024E900_de(void *actorStorage);
extern int func_8024E140_de(void);
extern int func_8024E148_de(void);
extern int func_8024E150_de(void);
extern s32 InstHdr_CanActorCastShadow(void *);
extern s32 func_8024E208_de(char *actor);
extern int func_8024E2B0_de(LevelActor *actor);
extern int func_8024E2C4_de(LevelActor *source);
#endif
