#include "include_asm.h"
#include "WEAPONS/80213ED4.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/FUNCPTR.H"
#include "COMMON/SHARED_VOIDCALLBACK.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT30.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Applies a hit to a damageable object: when its descriptor at 0x18 takes the hit (flag 1 for hits
   without bit 0x200, flag 2 for hits with it) it lowers the health at 0x4 by the damage, not below
   zero, turns the remaining percentage into the damage stage with the lowest threshold above it to set
   the model and time at 0x124 and 0x128 and the stage byte, and runs func_80214178_de (kind 2 when the
   descriptor has flag 0x40, else 1) once the health reaches zero. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"







void func_802050C0_eu_x(Damageable *obj, Health *health, Hit *hit)
{
    s32 canHit = 0;
    s32 flags;
    s32 remaining;
    u8 percent;
    u8 best;
    s32 bestIndex;
    s32 i;
    s32 kind;
    Damage *damage;

    flags = obj->desc->damage.flags;
    damage = &obj->desc->damage;
    bestIndex = canHit;
    if (flags & 1) {
        canHit = ((hit->flags >> 9) ^ 1) & 1;
    }
    if ((flags & 2) && (hit->flags & 0x200)) {
        canHit = 1;
    }
    if (canHit) {
        remaining = health->health - hit->damage;
        if (remaining < 0) {
            remaining = 0;
        }
        best = 100;
        health->health = remaining;
        percent = ((f32)remaining / (f32)health->maxHealth) * 100.0f;
        for (i = 0; i < 4; i++) {
            if (damage->threshold[i] < best && damage->threshold[i] != 0 &&
                percent < damage->threshold[i]) {
                best = damage->threshold[i];
                bestIndex = i;
            }
        }
        health->model = damage->model[bestIndex];
        health->time = damage->time[bestIndex];
        obj->stage = damage->model[bestIndex];
        if (health->health == 0) {
            kind = 1;
            if (obj->desc->damage.flags & 0x40) {
                kind = 2;
            }
            Weapons_RequestActorState(obj, health, kind);
        }
    }
}
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1D78[2] = {
    0x43C00000, 0x3FC90FDC,
};
#endif

#if defined(VERSION_EU)
/* Applies a hit to a damageable object: when its descriptor at 0x18 takes the hit (flag 1 for hits
   without bit 0x200, flag 2 for hits with it) it lowers the health at 0x4 by the damage, not below
   zero, turns the remaining percentage into the damage stage with the lowest threshold above it to set
   the model and time at 0x124 and 0x128 and the stage byte, and runs func_80214178_de (kind 2 when the
   descriptor has flag 0x40, else 1) once the health reaches zero. */












void func_802050C0_eu(Damageable *obj, Health *health, Hit *hit)
{
    s32 canHit = 0;
    s32 flags;
    s32 remaining;
    u8 percent;
    u8 best;
    s32 bestIndex;
    s32 i;
    s32 kind;
    Damage *damage;

    flags = obj->desc->damage.flags;
    damage = &obj->desc->damage;
    bestIndex = canHit;
    if (flags & 1) {
        canHit = ((hit->flags >> 9) ^ 1) & 1;
    }
    if ((flags & 2) && (hit->flags & 0x200)) {
        canHit = 1;
    }
    if (canHit) {
        remaining = health->health - hit->damage;
        if (remaining < 0) {
            remaining = 0;
        }
        best = 100;
        health->health = remaining;
        percent = ((f32)remaining / (f32)health->maxHealth) * 100.0f;
        for (i = 0; i < 4; i++) {
            if (damage->threshold[i] < best && damage->threshold[i] != 0 &&
                percent < damage->threshold[i]) {
                best = damage->threshold[i];
                bestIndex = i;
            }
        }
        health->model = damage->model[bestIndex];
        health->time = damage->time[bestIndex];
        obj->stage = damage->model[bestIndex];
        if (health->health == 0) {
            kind = 1;
            if (obj->desc->damage.flags & 0x40) {
                kind = 2;
            }
            Weapons_RequestActorState(obj, health, kind);
        }
    }
}
#endif

#if defined(VERSION_DE)
void func_802050A0_de(Damageable *obj, Health *health, Hit *hit)
{
    s32 canHit = 0;
    s32 flags;
    s32 remaining;
    u8 percent;
    u8 best;
    s32 bestIndex;
    s32 i;
    s32 kind;
    Damage *damage;

    flags = obj->desc->damage.flags;
    damage = &obj->desc->damage;
    bestIndex = canHit;
    if (flags & 1) {
        canHit = ((hit->flags >> 9) ^ 1) & 1;
    }
    if ((flags & 2) && (hit->flags & 0x200)) {
        canHit = 1;
    }
    if (canHit) {
        remaining = health->health - hit->damage;
        if (remaining < 0) {
            remaining = 0;
        }
        best = 100;
        health->health = remaining;
        percent = ((f32)remaining / (f32)health->maxHealth) * 100.0f;
        for (i = 0; i < 4; i++) {
            if (damage->threshold[i] < best && damage->threshold[i] != 0 &&
                percent < damage->threshold[i]) {
                best = damage->threshold[i];
                bestIndex = i;
            }
        }
        health->model = damage->model[bestIndex];
        health->time = damage->time[bestIndex];
        obj->stage = damage->model[bestIndex];
        if (health->health == 0) {
            kind = 1;
            if (obj->desc->damage.flags & 0x40) {
                kind = 2;
            }
            Weapons_RequestActorState(obj, health, kind);
        }
    }
}
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1A98[2] = {
    0x00205940, 0x00205940,
};
#endif

extern s32 Rumble_TestActorStateBit(void *, void *);


typedef struct Owner Owner;

/** Initialize the dest record's vtable-like fields from source's flag byte. */
void func_8020520C_de(LevelActor *source, void *dest) {
    ((SpawnDispatchOwner *)dest)->callbacks = &D_800C8420_de;
    ((SpawnDispatchOwner *)dest)->update = &D_002052C4;
    ((SpawnDispatchOwner *)dest)->draw = &D_00205628;
    ((SpawnDispatchOwner *)dest)->hit = &D_002050A0;
    ((SpawnDispatchOwner *)dest)->spawn = 0;
    ((SpawnDispatchOwner *)dest)->remaining = source->field3;
}

void func_8020524C_de(LevelActor *actor, void *requestContext) {
    if (Rumble_TestActorStateBit(&g_world, actor) == 1) {
        Weapons_RequestActorState(actor, requestContext, 1);
    } else {
        Weapons_RequestActorState(actor, requestContext, 0);
        actor->flags |= 0x10000;
    }
}

void func_802052C4_de(void *callbackContext, Shared_CallbackOwner *callbackOwner) {
    void *obj = callbackOwner->hook;
    if (obj != 0) {
        FuncPtr fn = ((Shared_CallbackHook *)(obj))->callback;
        if (fn != 0) {
            ((void (*)(void *, Shared_CallbackOwner *))fn)(callbackContext, callbackOwner);
        }
    }
}

/** Return the nested record's field, or a fallback constant when zero. */
int func_802052F8_de(void *owner) {
    int temp = ((Hold5324 *)((Owner *)owner)->track)->r.sound;
    if (temp != 0) {
        return temp;
    }
    return 0x5334;
}

int func_80205314_de(void *actor) {
    return ((Obj5324 *)actor)->holder->r.unk18;
}

void func_80205324_de(Obj5324 *actor, s32 *activationContext) {
    s32 mode;
    Rec5324 *rec;
    Shared_World *pFlag;

    rec = &actor->holder->r;
    pFlag = &g_world;
    Rumble_SetActorStateBit(pFlag, actor, 1);
    func_80278D78_de(actor, 0x40000, actor);
    if (activationContext[1] == 0) {
        actor->flags = actor->flags & 0xFFFEFFFF;
    }
    if (rec->unk18 == 0) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
    mode = pFlag->mode;
    if (mode == 4) {
        if (rec->unk20.whole != -1) {
            SoundElement_PlaySoundAtPosition(rec->unk20.half.id, actor->pos.v, 0, -1);
        }
        if (rec->unk1C != -1) {
            Weapons_SpawnActorEffect(actor, rec->unk1C, actor->pos.t, 0);
        }
        Weapons_SpawnFlaggedEffects(actor, activationContext, 4, rec->unk24, rec->unk28);
        /* func_802A5D38_de unlinks the walker by the object's 32-bit identity;
         * the registry holds those identities as s32. */
        func_802A5D38_de(&D_801379C0, (s32)actor);
        if (pFlag->mode != mode) {
            goto block_10;
        }
    } else {
block_10:
        actor->flags = (actor->flags & ~0x100) | 0x08000000;
    }
}

/** Clear two flags when the controlling byte and nested flag are set. */
void func_80205494_de(BreakableHitContext *breakableHitContext, ObjectStateCC *hitState) {
    char *nested = breakableHitContext->unk_18;
    if (hitState->unk_CB != 0 &&
        (((struct Descriptor *)nested)->damage.flags & 0x4) != 0) {
        unsigned int flags = breakableHitContext->unk_100;
        flags &= ~0x2000;
        flags &= ~0x100;
        breakableHitContext->unk_100 = flags;
    }
}

/** Return the word at offset 0x40 through the pointer stored at offset 0x18. */
int func_802054D0_de(void *object) {
    return ((struct Access_s32_40 *) ((Owner *) object)->track)->field;
}
