#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "WEAPONS/80213ED4_19.H"

extern f32 Weapons_FindClearAimAngle(void *arg0, f32 arg1, f32 arg2, f32 arg3,
                        void *arg4, f32 arg5);


void func_802168B8_de(void *actor, s32 arg1, CTeamSelectTeam *arg2, f32 arg3) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    if (arg2 != 0) {
        f1 = Weapons_FindClearAimAngle(actor, arg2->x, arg2->y, arg2->z,
                           arg2, D_800C21C8_de);
        f3 = f1;
        if (arg3 < f1) {
            f1 = arg3;
        } else {
            f0 = -arg3;
            if (f1 < f0) {
                f1 = f0;
            }
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
        func_80217074_de(actor, f1);
    }
}
