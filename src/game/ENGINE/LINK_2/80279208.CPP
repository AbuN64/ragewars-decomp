#include "COMMON/LISTHEADER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "SYSTEM_2/8025E280.H"

/* Updates a table of triggers against masks: for each trigger the world accepts (always in world mode 4, otherwise when Scene_TestTriggerStateBit refuses it), a trigger not yet entered whose mask meets the enter mask is marked entered and runs its enter action (the id's action through Scene_TestTriggerKindFlags and Scene_DispatchSecondaryTriggersOfKind, or Link_DispatchTriggerExit without an id); it then counts as active when its mask meets the require mask, meets the enter mask, passes the paired exclude masks, is not flagged 0x1000 without 0x100 and passes Link_CheckTriggerMessage, and an active trigger runs its fire action once (through Scene_SetTriggerStateBit, Scene_DecrementTriggerCounter, Scene_TestTriggerCounterZero and Scene_ActivateTriggersOfKind for an id, or Link_ActivateTrigger without one). */




extern s32 Scene_TestTriggerStateBit(Shared_World *world, Trigger *trigger);

extern s32 Scene_TestTriggerKindFlags(Shared_World *world, s32 id);

extern void Scene_DispatchSecondaryTriggersOfKind(Shared_World *world, s32 id);

extern void Link_DispatchTriggerExit(Trigger *trigger);

extern s32 Link_CheckTriggerMessage(Trigger *trigger, struct Player *arg);

extern void Scene_SetTriggerStateBit(Shared_World *world, Trigger *trigger, s32 arg);

extern void Scene_DecrementTriggerCounter(Shared_World *world, s32 id);

extern s32 Scene_TestTriggerCounterZero(Shared_World *world, s32 id);

extern void Scene_ActivateTriggersOfKind(Shared_World *world, s32 id);

extern void Link_ActivateTrigger(Trigger *trigger);

void Link_SetTriggerTrackCallback(int unused0, int unused1, void *arg2) {
    ObjRecAt6V1 *arg2_record = arg2;
    func_8025E260_de(arg2_record->unk6);
}

void Link_SetTriggerTrack(void *arg0) {
    func_8025E260_de((((struct ObjRecAt6V1 *) ((s8 *) arg0))->unk6));
}

void Link_ClearActorStateBit(struct Shared_Actor *actor) {
    actor->weaponFlags &= ~0x10000;
}

/** Set flag 0x10000 in the word at offset 0x100. */
void Link_SetActorStateBit(void *object) {
    Shared_Actor *actor = object;
    actor->weaponFlags |= 0x10000;
}

void Link_DispatchMatchingTriggers(Trigger *triggers, s32 count, s32 require, s32 enter, s32 exclude, s32 group, struct Player *arg) {
    s32 i;
    s32 active;
    s32 usable;
    Shared_World *world;
    Trigger *trigger;

    for (trigger = triggers, i = 0; i < count; trigger++, i++) {
        world = &g_world;
        usable = 1;
        if (world->mode != 4) {
            usable = Scene_TestTriggerStateBit(world, trigger) == 0;
        }
        if (!usable) {
            continue;
        }
        active = 1;
        if (!(trigger->flags.bytes.state & 0x20) && enter != 0 && (trigger->mask & enter)) {
            trigger->flags.bytes.state |= 0x40;
            if (trigger->flags.bytes.id != 0) {
                if (Scene_TestTriggerKindFlags(world, trigger->flags.bytes.id) != 0) {
                    Scene_DispatchSecondaryTriggersOfKind(world, trigger->flags.bytes.id);
                }
            } else {
                Link_DispatchTriggerExit(trigger);
            }
            active = 1;
        }
        if (require != 0) {
            active = 0;
            if (trigger->mask & require) {
                active = 1;
            }
        }
        if (enter != 0 && !(trigger->mask & enter)) {
            active = 0;
        }
        if ((trigger->mask & group) && !(trigger->mask & group & exclude)) {
            active = 0;
        }
        if ((trigger->flags.word & 0x1100) == 0x1000) {
            active = 0;
        }
        if (Link_CheckTriggerMessage(trigger, arg) == 0) {
            active = 0;
        }
        if (!active) {
            continue;
        }
        if (trigger->flags.bytes.id != 0) {
            if (!(trigger->flags.bytes.state & 0x80)) {
                Scene_SetTriggerStateBit(world, trigger, 1);
                trigger->flags.bytes.state |= 0x80;
                Scene_DecrementTriggerCounter(world, trigger->flags.bytes.id);
                if (Scene_TestTriggerCounterZero(world, trigger->flags.bytes.id) != 0) {
                    Scene_ActivateTriggersOfKind(world, trigger->flags.bytes.id);
                }
            }
        } else {
            Link_ActivateTrigger(trigger);
        }
    }
}
