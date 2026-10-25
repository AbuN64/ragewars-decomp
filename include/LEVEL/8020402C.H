#ifndef LEVEL_8020402C_H
#define LEVEL_8020402C_H
#include "COMMON/OBJRECAT30.H"
#include "COMMON/VECTOR4F.H"
struct ObjRecAt30 {
    char pad0[0x30];
    Hook * unk30;
};
extern void Level_SetDrawHandler(void *arg0, void *arg1);
extern void Level_CopyTrackBytes(char *arg0, char *arg1);
extern void Level_DisableTrigger(struct Trigger *arg0);
extern void Level_InitBreakableMotion(struct LevelActor *arg0, struct ActorMotionState *arg1);
extern s32 Level_UpdateHealthFlag(struct LevelActor *arg0);
extern void Level_ClearMotionFlags(struct LevelActor *object);
extern void Level_EnableTrigger(struct Trigger *arg0);
extern s32 Level_UpdateTriggerFlag(struct LevelActor *actor);
void Level_DrawFadedActor(struct Actor_func_8024A1D0_de *actor, struct InputRecAt40 *input, struct Lookup *lookup);
#endif
