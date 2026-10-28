#ifndef RENDER_TRIGGERED_UPDATETRIGGEREDMOTION_H
#define RENDER_TRIGGERED_UPDATETRIGGEREDMOTION_H
#include "COMMON/REC.H"

extern void func_80206930_de(struct LevelActor *actor, int arg1, struct Trigger *triggerRecord);
extern void Triggered_DisableTriggeredActorState(struct Trigger *trigger);
extern void Triggered_EnableTriggeredActorState(struct Trigger *trigger);

extern void func_802077F4_de(void *object, void *state);
s32 func_80207738_de(void *context, struct InputRecAt37 *option);
#endif
