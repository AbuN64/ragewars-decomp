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

extern void Render_QueueModelInstance(void **, void *, s32, void *, void *, s32);




extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_802054E0_de(Obj54E0 *arg0, void *arg1) {
    Rec54E0 *rec;

    rec = &arg0->holder->r;
    arg0->flags = arg0->flags & 0xFFFEFFFF;
    func_80278D78_de(arg0, 0x40000, arg0);
    if (rec->unk2C == 0) {
        arg0->flags &= ~0x2000;
        arg0->flags &= ~0x100;
    }
    if (D_8011FE88.mode == 4) {
        if (rec->unk34.whole != -1) {
            Render_PlaySoundAtPosition(rec->unk34.half.id, arg0->pos.v, 0, -1);
        }
        if (rec->unk30 != -1) {
            Weapons_SpawnActorEffect(arg0, rec->unk30, arg0->pos.t, 0);
        }
        Weapons_SpawnFlaggedEffects(arg0, arg1, 8, rec->unk38, rec->unk3C);
    }
}

/** Clear two flags when the controlling byte and nested flag are set. */
void func_802055EC_de(void *levelActor, void *arg1) {
    LevelActor *object = levelActor;
    BreakableDefinition *nested = (void *)object->definition;
    ObjectStateCC *state = arg1;
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
void func_80205628_de(void *levelActor, void *spawnDispatchOwner, void *arg2) {
    LevelActor *actor = levelActor;
    SpawnDispatchOwner *owner = spawnDispatchOwner;
    Lookup *lookup = arg2;

    actor->mask = 1 << owner->spawn;
    if (lookup->unk0 != 0) {
        Render_QueueModelInstance(lookup->value, actor->fieldB4, 1,
                        &actor->lighting[D_800D297C], 0, owner->remaining);
    }
}

void func_80205694_de(void *arg0, void *arg1) {
    Weapons_RequestActorState(arg0, arg1, 1);
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}

void func_802056D0_de(Trigger *trigger) {
    func_8028B670_de(&D_8011FE88, trigger->owner, trigger->actor, 1);
}

/** Return the object's 0x200 status bit. */
unsigned int func_80205700_de(void *object) {
    struct Hit *hit = object;
    return hit->flags & 0x200;
}

int func_8020570C_de(Hit *arg0) {
    return ((arg0->flags >> 9) ^ 1) & 1;
}
