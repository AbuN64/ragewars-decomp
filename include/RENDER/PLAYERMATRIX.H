#ifndef RENDER_PLAYERMATRIX_H
#define RENDER_PLAYERMATRIX_H
#include "COMMON/REC.H"
#include "WORLD/INTEGERSTATE170.H"

extern void Device_BuildPlayerMatrix(void *object, void *state);
extern void func_80207A90_de(void *actor, s32 *stateFlags);

extern void func_80207EEC_de(void *event);
extern void func_80207F90_de(void *object);
extern void func_80207C68_de(void *actor, s32 *stateFlags);
extern void func_80207F60_de(void *event);
extern void func_80207FC4_de(char *object, unsigned int *flags);
extern void func_80207FA0_de(struct LevelActor *actor, struct ActorMotionState *motionState);
extern int func_80207FE4_de(void * player);
#endif
