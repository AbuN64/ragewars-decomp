#include "COMMON/FIELD_VEC_B0.H"
#include "WEAPONS/CBARREL_LOCKTRACKERTARGET.H"

void Cbarrel_LockTrackerTarget(void *unused0, void *trackerState, struct Actor_func_80214DD4_de *target, float lockDuration) {
    Tracker *tracker = trackerState;
    tracker->lockedTarget = target;
    tracker->targetTimer = lockDuration;
}
