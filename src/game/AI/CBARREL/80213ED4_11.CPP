#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "WEAPONS/80213ED4_19.H"

void Barrel_ApplyClampedTurn(void *actor, s32 unused1, f32 turnLimit, f32 desiredTurn) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    f0 = turnLimit;
    f1 = desiredTurn;
    f3 = f1;
    if (f0 < f1 || (f0 = -f0, f1 < f0)) {
        f1 = f0;
    }
    f1 = f1 * D_800D2988;
    f2 = f1;
    if (f1 < 0.0f) {
        f2 = -f1;
    }
    if (f3 < 0.0f) {
        if (-f3 < f2) {
            goto clamp;
        }
    } else if (f3 < f2) {
clamp:
        f1 = f3;
    }
    Barrel_AddActorYaw(actor, f1);
}
