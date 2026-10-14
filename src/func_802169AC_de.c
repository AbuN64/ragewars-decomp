#include "shared/route_chase_records.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"

extern s32 D_8013B290;










s32 func_802169AC_de(void *arg0, void *arg1, void *arg2) {
    void *temp_a2;

    if (((RouteChaseBot *)arg1)->node == 0) {
        return 6;
    }
    if (arg2 == 0) {
        if (((RouteChaseBot *)arg1)->routeReady != 0) {
            return 4;
        }
        return 3;
    }
    if (arg2 == ((RouteChaseBot *)arg1)->target) {
        return 2;
    }
    if (*((LevelActor *)arg2)->definition == 5) {
        return 5;
    }
    if (((LevelActor *)arg2)->type == 0x64F) {
        return 7;
    }
    if (D_8013B290 == 0) {
        if (((LevelActor *)arg2)->flags & 0x300000) {
            temp_a2 = ((LevelActor *)arg2)->controller;
            if ((((Shared_ActorView *)temp_a2)->controllerOwner == arg0) &&
                (((Shared_ActorView *)temp_a2)->controllerMode == 2)) {
                return 1;
            }
        }
        if (((LevelActor *)arg0)->renderFlags & 2) {
            if (((LevelActor *)arg0)->type != 0xCA) {
                return 1;
            }
        }
    }
    return 0;
}
