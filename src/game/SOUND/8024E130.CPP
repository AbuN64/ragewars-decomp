#include "include_asm.h"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/REC.H"
#include "COMMON/OBJ.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SOUND/TRIPLERECAT8.H"
#include "TYPES.H"

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
    switch (((LevelActor *)arg0)->definition->kind) {
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

s32 func_8024E1B4_de(void *actor) {
    if (*(u8 *)actor != 1) {
        return 0;
    }
    if (!(((LevelActor *)actor)->flags & 0x2000)) {
        return 0;
    }
    actor = ((ActorMotionState *)((Player *)actor)->motion)->hooks;
    if (actor == 0) {
        goto ret1;
    }
    if (((ActorMotionHooks *)actor)->flags & 0x10000) {
        return 0;
    }
ret1:
    return 1;
}

/* Reports whether an actor's current state counts as active: states 1 and 5 always do, and state 11 does for a live mirrored actor whose controller flag at 0x80C is set or for which Camera_IsSequenceInWindow agrees. */

extern s32 Camera_IsSequenceInWindow(char *actor);




s32 func_8024E208_de(char *actor)
{
    switch (((LevelActor *)actor)->definition->kind) {
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
        if (((Player *)((Shared_Actor *)actor)->entity)->controllerEnabled != 0 || Camera_IsSequenceInWindow(actor) != 0) {
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
int func_8024E2B0_de(LevelActor *actor) {
    return actor->definition->kind == 1;
}

int func_8024E2C4_de(LevelActor *source) {
    switch (source->definition->kind) {
        case 0: case 2: case 3: case 5: case 6: case 7: case 8: case 0xA: case 0xC: case 0xD: case 0xE:
        default:
            return 1;
        case 1: case 4: case 9: case 0xB:
            return 0;
    }
}
