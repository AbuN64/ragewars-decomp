#ifndef LEVEL_ACTION_UPDATEBREAKABLEPROXIMITY_H
#define LEVEL_ACTION_UPDATEBREAKABLEPROXIMITY_H
#include "COMMON/OBJRECAT30.H"
#include "COMMON/VECTOR4F.H"
struct ObjRecAt30 {
    char pad0[0x30];
    Hook * unk30;
};
extern void Actionai_SetDrawHandler(void *unused0, void *motionState);
extern void Actionai_CopyTrackBytes(char *ownerRecord, char *eventRecord);
extern void Actionai_DisableTrigger(struct Trigger *trigger);
extern void Actionai_InitBreakableMotion(struct LevelActor *actor, struct ActorMotionState *motionState);
extern s32 Actionai_UpdateHealthFlag(struct LevelActor *actor);
extern void Actionai_ClearMotionFlags(struct LevelActor *object);
extern void Actionai_EnableTrigger(struct Trigger *trigger);
extern s32 Actionai_UpdateTriggerFlag(struct LevelActor *actor);
void Actionai_DrawFadedActor(struct Actor_func_8024A1D0_de *actor, struct InputRecAt40 *input, struct Lookup *lookup);
#endif
