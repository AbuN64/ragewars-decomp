#include "COMMON/FIELD_VEC_B0.H"
#include "WEAPONS/80213ED4_16.H"

void Barrel_LockTrackerTarget(void *unused0, void *arg1, struct Actor_func_80214DD4_de *target, float arg3) {
    Tracker *tracker = arg1;
    tracker->lockedTarget = target;
    tracker->targetTimer = arg3;
}
