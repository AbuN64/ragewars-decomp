#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "WEAPONS/80213ED4_13.H"

s32 func_802169AC_de(LevelActor *arg0, RouteChaseBot *arg1, LevelActor *arg2) {
    void *temp_a2;

    if (arg1->node == 0) {
        return 6;
    }
    if (arg2 == 0) {
        if (arg1->routeReady != 0) {
            return 4;
        }
        return 3;
    }
    if (arg2 == arg1->target) {
        return 2;
    }
    if (arg2->definition->kind == 5) {
        return 5;
    }
    if (arg2->type == 0x64F) {
        return 7;
    }
    if (D_8013B290 == 0) {
        if (arg2->flags & 0x300000) {
            temp_a2 = arg2->controller;
            if ((((Shared_ActorView *)temp_a2)->controllerOwner == arg0) &&
                (((Shared_ActorView *)temp_a2)->controllerMode == 2)) {
                return 1;
            }
        }
        if (arg0->renderFlags & 2) {
            if (arg0->type != 0xCA) {
                return 1;
            }
        }
    }
    return 0;
}
