#include "COMMON/FUNCPTR.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/UNUSED.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/80213ED4_22.H"

/** Read the next u16 from the cursor stream, wrapping back to base on the -1 sentinel. */
s16 Barrel_ReadLoopingSequenceValue(Cursor802171C8 *arg0) {
    u16 *cur;
    u16 value;

    cur = arg0->cur;
    value = *cur;
    cur += 1;
    arg0->cur = cur;
    if (*(s16 *) cur == -1) {
        arg0->cur = arg0->base;
    }
    return (s16) value;
}

/* Runs the hook with the arguments this function was called with: its callers pass the actor, its hook state
 * and the damage record, and the hook reads them from the same argument registers. */
void Barrel_RunDamageHook(void *actor, struct CallbackState114 *callbackState, void *damage) {
    FuncPtr fn = callbackState->callback;
    if (fn != 0) {
        ((void (*)(void *, void *, void *))fn)(actor, callbackState, damage);
    }
}

extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);




/** Subtract obj->y from arg2 in-place via GraphU64_SubtractVectors, then return the squared length of (arg1, arg2', arg3). */
f32 Barrel_GetEyeDistanceSquared(void *candidate, CVector3 v) {
    f32 eyeDeltaY;

    GraphU64_SubtractVectors(&v, &v, &((ActorBarrelIsTargetInViewCone *)(candidate))->position);
    eyeDeltaY = v.y - ((ActorBarrelIsTargetInViewCone *)(candidate))->eye;
    v.y = eyeDeltaY;
    return (v.x * v.x) + (eyeDeltaY * eyeDeltaY) + (v.z * v.z);
}

/* Squared XZ distance to a point using the existing by-value vector ABI. */
f32 Barrel_GetFlatDistanceSquared(LevelActor *actor, CVector3 point)
{
    f32 dx = point.x - actor->position0.x;
    f32 dz = point.z - actor->position0.z;
    return dx * dx + dz * dz;
}

void func_802172C4_de(void *unused0, void *unused1, Func802172C4Value unused2) {
}

extern void *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);








void Barrel_SetLoopingSound(void *actor, void *stateController, s32 sixth) {
    CLoopingSoundData *node;
    void *fallback;
    s32 kind;

    node = ((Dest *)stateController)->sound;
    fallback = (void *)-1;
    if (node != 0) {
        if (node->state == sixth) {
            return;
        }
        func_8025CA24_de(func_8025CC6C_de(), ((Dest *)stateController)->sound);
    }

    kind = *(u8 *)actor;
    if (kind != 0) {
        if (kind >= 0) {
            if (kind < 3) {
                fallback = actor;
            }
        }
    } else {
        fallback = (void *)((LevelActor *)actor)->resourceFlags;
    }

    ((Dest *)stateController)->sound =
        func_8025C95C_de(func_8025CC6C_de(), sixth, &((LevelActor *)actor)->position0,
                      &((LevelActor *)actor)->position0, (s32)fallback);
}
