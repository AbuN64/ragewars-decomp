#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4_19.H"
#include "COMMON/PROBE.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "particle/8024D018_4.H"
#include "WEAPONS/80213ED4_23.H"
#include "WEAPONS/80213ED4_21.H"
#include "COMMON/FUNCPTR.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/80213ED4_22.H"
#include "include_asm.h"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "MENU/TEAMMENU.H"
#include "MENU/TEAM/80217388.H"
#include "FX/80271B18.H"

/* 80213ED4_19.CPP */
void Barrel_AddActorYaw(void *arg0, f32 arg1) {
    (((struct func_80203908_S4 *) ((s8 *) arg0))->unk6C) = (f32) ((((struct func_80203908_S4 *) ((s8 *) arg0))->unk6C) + arg1);
    ((s32 (*)(void *))Graphu64_WrapPeriodicValue)(arg0 + 0x6C);
}

/* 80213ED4_20.CPP */
void Barrel_SpawnFlaggedEffects(Player *actor, s32 *emittedFlags, s32 emissionFlag, s32 primaryEffectMask, s32 secondaryEffectMask) {
    s32 *entry;

    if ((emittedFlags[0] & emissionFlag) != 0) {
        return;
    }

    emittedFlags[0] |= emissionFlag;
    entry = D_800C8FF0_de;
    if (entry[0] != 0) {
        do {
            if ((primaryEffectMask & entry[0]) != 0) {
                Insthdr_PlayActorGraphSound(actor,
                              actor->pos,
                              entry[1],
                              Graphu64_RandomBetween(g_barrelFlaggedEffectRandomRanges, D_800C21DC_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }

    entry = D_800C90F8_de;
    if (entry[0] != 0) {
        do {
            if ((secondaryEffectMask & entry[0]) != 0) {
                Insthdr_PlayActorGraphSound(actor,
                              actor->pos,
                              entry[1],
                              Graphu64_RandomBetween(D_800C21E0_de, D_800C21E4_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }
}

/* 80213ED4_21.CPP */
/** Store one word into both elements of a two-word value. */
void Barrel_FillWordPair(int *value, int word) {
    value[0] = word;
    value[1] = word;
}

/* 80213ED4_22.CPP */
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

extern void Graphu64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

/** Subtract obj->y from arg2 in-place via Graphu64_SubtractVectors, then return the squared length of (arg1, arg2', arg3). */
f32 Barrel_GetEyeDistanceSquared(void *candidate, CVector3 v) {
    f32 eyeDeltaY;

    Graphu64_SubtractVectors(&v, &v, &((ActorBarrelIsTargetInViewCone *)(candidate))->position);
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

/* 80217388.CPP */
void Barrel_StopActorLoopingSound(void *arg0, void *arg1) {
    void *owner = 0;
    u8 type = *(u8 *)arg0;

    switch (type) {
    case 1:
    case 2:
        owner = arg0;
        break;
    case 0:
        owner = (void *)((LevelActor *)arg0)->resourceFlags;
        break;
    }

    if (((Dest *)arg1)->sound != 0) {
        func_8025E1C4_de(owner);
        if (((Dest *)arg1)->sound != 0) {
            func_8025CA24_de(func_8025CC6C_de(), ((Dest *)arg1)->sound);
            ((Dest *)arg1)->sound = 0;
        }
    }
}

extern f32 Gobjinst_GetActorRadius(void *arg0);
extern void Graphu64_ScaleVector(void *result, void *vector, f32 scale);
extern void Graphu64_AddVec3(CVector3 *result, CVector3 *left, CVector3 *right);
extern void InstHdr_CopyActorPositionAndModel(void *arg0, CVector3 value, void *arg4, s32 *arg5,
                          s32 arg6, s32 arg7);

void Barrel_FindOffsetApproachPosition(void *arg0, s32 unused, void *arg2, Player *arg3,
                   void *arg4, s32 *arg5) {
    CVector3 offset;
    CVector3 position;
    f32 distance;

    if (arg3 != 0) {
        Graphu64_SubtractVectors(&offset, &((Player *)(arg2))->pos,
                       &arg3->pos);
        offset.y = 0.0f;
        Graphu64_NormalizeVec3(&offset.x);
    } else {
        offset.x = 0.0f;
        offset.y = 0.0f;
        offset.z = 0.0f;
    }

    distance = Gobjinst_GetActorRadius(arg2) + Gobjinst_GetActorRadius(arg0) + D_800C21E8_de;
    Graphu64_ScaleVector(&offset, &offset, distance);
    Graphu64_AddVec3(&position, &((Player *)(arg2))->pos, &offset);
    InstHdr_CopyActorPositionAndModel(arg2, position, arg4, arg5, 0, 0);
}

void Barrel_ClearTargetInfo(Shared_ActorView *arg0, void *unused1, Output80216D3C *arg2) {
    Triple local1;
    Triple local2;

    local1 = arg0->position.words;
    local2.x = 0;
    local2.y = 0;
    local2.z = 0;
    arg2->type = 3;
    arg2->unk4 = 0;
    arg2->unk8 = 0;
    arg2->first = local1;
    arg2->second = local2;
    arg2->unk24 = 0;
    local2.y = 0;
    local1.y = 0;
    arg2->third = local1;
    arg2->fourth = local2;
    arg2->unk40 = 0;
}

void Barrel_SpawnEffectsFromMask(Player *arg0, s32 unused1, s32 arg2, s32 *entry) {
    if (entry[0] != 0) {
        do {
            if ((arg2 & entry[0]) != 0) {
                Insthdr_PlayActorGraphSound(arg0,
                              arg0->pos,
                              entry[1],
                              Graphu64_RandomBetween(D_800C21EC_de, D_800C21F0_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8021762C[1] = {
    0x43524541,
};
#endif
