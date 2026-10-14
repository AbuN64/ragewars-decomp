#include "shared/gameplay_transition.h"
#include "span_1000/code_80225D10.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"




























/** Start the round-end sequence once no menu or transition is active and any player is flagged. */
extern int func_80245798_de(void);
extern int func_80245784_de(void);



extern MatchState D_801468A0;






int func_8022A68C_de(char *arg0) {
    Shared_ActorView *p;
    int count;
    MatchState *s;
    MatchState *t;

    if (func_80245798_de() != 0 || func_80245784_de() != 0 || D_801371DC != 0) {
        return 0;
    }
    t = &D_801468A0;
    if (t->active != 0 || t->armed == 0) {
        return 0;
    }
    count = 0;
    for (p = (Shared_ActorView *)((ForcePlayerList *)arg0)->head; p != 0; p = p->next) {
        if (p->controls->roundEnded == 1) {
            count++;
        }
    }
    if (count <= 0) {
        return 0;
    }
    s = &D_801468A0;
    s->active = 1;
    s->armed = 0;
    return 1;
}
