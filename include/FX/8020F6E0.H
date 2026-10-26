#ifndef FX_8020F6E0_H
#define FX_8020F6E0_H
#include "TYPES.H"

struct AiController;

s32 Fx_UpdateTargetSelection(void *object);
s32 Fx_IsPreferredTargetAccepted(struct AiController *controller);
s32 Fx_CountAcceptedTargets(struct AiController *controller);
s32 Fx_FindNearestFlaggedTarget(struct AiController *controller);

#endif
