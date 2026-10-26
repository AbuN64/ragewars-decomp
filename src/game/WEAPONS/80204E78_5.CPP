#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT30.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "WEAPONS/80213ED4.H"

extern void Geometry_QueueModelInstance(void **, void *, s32, void *, void *, s32);




extern void Scene_SetLevelActorStateBit(void *a, unsigned short b, unsigned short c, int d);

void func_802054E0_de(Obj54E0 *actor, void *responseContext) {
    Rec54E0 *rec;

    rec = &actor->holder->r;
    actor->flags = actor->flags & 0xFFFEFFFF;
    Link_DispatchActorLinks(actor, 0x40000, actor);
    if (rec->unk2C == 0) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
    if (g_world.mode == 4) {
        if (rec->unk34.whole != -1) {
            SoundElement_PlaySoundAtPosition(rec->unk34.half.id, actor->pos.v, 0, -1);
        }
        if (rec->unk30 != -1) {
            Barrel_SpawnActorEffect(actor, rec->unk30, actor->pos.t, 0);
        }
        Barrel_SpawnFlaggedEffects(actor, responseContext, 8, rec->unk38, rec->unk3C);
    }
}

/** Clear two flags when the controlling byte and nested flag are set. */
void func_802055EC_de(void *levelActor, void *hitState) {
    LevelActor *object = levelActor;
    BreakableDefinition *nested = (void *)object->definition;
    ObjectStateCC *state = hitState;
    if (state->unk_CB != 0 &&
        (nested->flags & 0x20) != 0) {
        unsigned int flags = object->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        object->flags = flags;
    }
}

/* Draw callback installed by func_8020520C_de; the animation lookup is
 * the same third callback argument consumed by func_8024A1D0_de. */
void func_80205628_de(void *levelActor, void *spawnDispatchOwner, void *modelLookup) {
    LevelActor *actor = levelActor;
    SpawnDispatchOwner *owner = spawnDispatchOwner;
    Lookup *lookup = modelLookup;

    actor->mask = 1 << owner->spawn;
    if (lookup->unk0 != 0) {
        Geometry_QueueModelInstance(lookup->value, actor->fieldB4, 1,
                        &actor->lighting[D_800D297C], 0, owner->remaining);
    }
}

void func_80205694_de(void *actor, void *requestContext) {
    Nav_RequestActorState(actor, requestContext, 1);
    Rumble_SetActorStateBit(&g_world, actor, 1);
}

void func_802056D0_de(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 1);
}

/** Return the object's 0x200 status bit. */
unsigned int func_80205700_de(void *object) {
    struct Hit *hit = object;
    return hit->flags & 0x200;
}

int func_8020570C_de(Hit *hitRecord) {
    return ((hitRecord->flags >> 9) ^ 1) & 1;
}
