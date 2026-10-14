#include "span_1000/code_802022E0.h"
/* Returns whether a player may act on a target: never on its own linked object or an inactive
   target, always when the team rule D_801468C4 is off, otherwise only across different teams. */




extern int D_801468C4;
int func_80203EB0_de(Actor *self, int unused, Actor *target) {
    Actor *linked = self->linked;
    if (linked == target || target->active == 0) {
        return 0;
    }
    if (D_801468C4 != 0) { if (linked->info->team == target->info->team) { return 0; } } return 1;
}
