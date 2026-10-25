#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/WORLD.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "WEAPONS/80213ED4_13.H"

s32 func_802169AC_de(LevelActor *actor, RouteChaseBot *routeChaseBot, LevelActor *arg2) {
    void *controller;

    if (routeChaseBot->node == 0) {
        return 6;
    }
    if (arg2 == 0) {
        if (routeChaseBot->routeReady != 0) {
            return 4;
        }
        return 3;
    }
    if (arg2 == routeChaseBot->target) {
        return 2;
    }
    if (arg2->definition->kind == 5) {
        return 5;
    }
    if (arg2->type == 0x64F) {
        return 7;
    }
    if (D_8011FE88.visibilityEnabled == 0) {
        if (arg2->flags & 0x300000) {
            controller = arg2->controller;
            if ((((Shared_ActorView *)controller)->controllerOwner == actor) &&
                (((Shared_ActorView *)controller)->controllerMode == 2)) {
                return 1;
            }
        }
        if (actor->renderFlags & 2) {
            if (actor->type != 0xCA) {
                return 1;
            }
        }
    }
    return 0;
}
