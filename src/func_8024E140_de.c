#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_802022E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"
#include "types.h"

/** Return the zero status used by callers at VRAM 0x8024E130. */
int func_8024E140_de(void) {
    return 0;
}

/** Return zero. */
int func_8024E148_de(void) {
    return 0;
}

/** Return the empty result used by callers at VRAM 0x8024E140. */
int func_8024E150_de(void) {
    return 0;
}

/** Return whether this object is active for its current behavior class. */
s32 func_8024E158_de(void *arg0) {
    if (*(u8 *)arg0 == 1) {
        if ((((LevelActor *)arg0)->flags & 0x300000) != 0) {
            return 1;
        }
    }
    switch (*((LevelActor *)arg0)->definition) {
    case 1:
    case 2:
    case 5:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}

s32 func_8024E1B4_de(void *arg0) {
    if (*(u8 *)arg0 != 1) {
        return 0;
    }
    if (!(((LevelActor *)arg0)->flags & 0x2000)) {
        return 0;
    }
    arg0 = ((ActorMotionState *)((Player *)arg0)->motion)->hooks;
    if (arg0 == 0) {
        goto ret1;
    }
    if (((ActorMotionHooks *)arg0)->flags & 0x10000) {
        return 0;
    }
ret1:
    return 1;
}

/* Reports whether an actor's current state counts as active: states 1 and 5 always do, and state 11 does for a live mirrored actor whose controller flag at 0x80C is set or for which func_80245798_de agrees. */

extern s32 func_80245798_de(char *actor);




s32 func_8024E208_de(char *actor)
{
    switch (*((LevelActor *)actor)->definition) {
    case 1:
    case 5:
        return 1;
    case 11:
        if (*(u8 *)actor != 1) {
            return 0;
        }
        if (!(((LevelActor *)actor)->flags & 0x300000)) {
            return 0;
        }
        if (((Player *)((Shared_Actor *)actor)->entity)->controllerEnabled != 0 || func_80245798_de(actor) != 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}

typedef struct Owner Owner;



/** Return bit two of the nested state word. */
unsigned int func_8024E29C_de(char *object) {
    return (((struct NavigationTrack *)((LevelActor *)object)->definition)->flags >> 2) & 1;
}

/** Report whether the object pointed to at offset 0x18 equals one. */
int func_8024E2B0_de(LevelActor *arg0) {
    return *(int *)(arg0->definition) == 1;
}
