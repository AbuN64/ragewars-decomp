#include "COMMON/FIELD_VEC_B0.H"
#include "WEAPONS/CBARREL_LOCKTRACKERTARGET.H"

void Cbarrel_LockTrackerTarget(void *unused0, void *trackerState, struct BarrelAnchorActorView *target, float lockDuration) {
    Tracker *tracker = trackerState;
    tracker->lockedTarget = target;
    tracker->targetTimer = lockDuration;
}
