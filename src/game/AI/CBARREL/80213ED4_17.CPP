#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"

extern void Cbarrel_ResolveTrackGoal(void *, void *, s32, void *);
extern void Barrel_FillAnchorTargetInfo(void *, void *, s32, void *);






void Barrel_UpdateTrackGoals(Input80216D3C *actor, void *trackerState, Output80216D3C *targetInfos, s32 updateTrackedTarget, s32 updateAnchorTarget) {
    Tracker *tracker = trackerState;
    Triple first;
    Triple second;
    f32 lockTimeLeft;
    f32 targetTimer;

    targetTimer = tracker->targetTimer;
    if (targetTimer > 0.0f) {
        lockTimeLeft = targetTimer - D_800D2988;
        tracker->targetTimer = lockTimeLeft;
        if (lockTimeLeft <= 0.0f) {
            tracker->lockedTarget = 0;
            tracker->targetTimer = 0.0f;
        }
    }
    if (updateTrackedTarget != 0) {
        Cbarrel_ResolveTrackGoal(actor, tracker, (s32)tracker->target, &targetInfos[1]);
    } else {
        Output80216D3C *out = &targetInfos[1];
        first = actor->vec;
        second.x = 0;
        second.y = 0;
        second.z = 0;
        out->type = 3;
        out->unk4 = 0;
        out->unk8 = 0;
        out->first = first;
        out->second = second;
        out->unk24 = 0;
        second.y = 0;
        first.y = 0;
        out->third = first;
        out->fourth = second;
        out->unk40 = 0;
    }
    if (updateAnchorTarget != 0) {
        Barrel_FillAnchorTargetInfo(actor, tracker, (s32)tracker->anchor, targetInfos);
        return;
    }
    first = actor->vec;
    second.x = 0;
    second.y = 0;
    second.z = 0;
    targetInfos->type = 3;
    targetInfos->unk4 = 0;
    targetInfos->unk8 = 0;
    targetInfos->first = first;
    targetInfos->second = second;
    targetInfos->unk24 = 0;
    second.y = 0;
    first.y = 0;
    targetInfos->third = first;
    targetInfos->fourth = second;
    targetInfos->unk40 = 0;
}
