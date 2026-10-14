#include "shared/world.h"
#include "span_1000/code_80279208.h"
#include "types.h"

/* Updates a table of triggers against masks: for each trigger the world accepts (always in world mode 4, otherwise when func_8028BC0C_de refuses it), a trigger not yet entered whose mask meets the enter mask is marked entered and runs its enter action (the id's action through func_8028C424_de and func_8028C4B4_de, or func_80278F00_de without an id); it then counts as active when its mask meets the require mask, meets the enter mask, passes the paired exclude masks, is not flagged 0x1000 without 0x100 and passes func_80279420_de, and an active trigger runs its fire action once (through func_8028BB1C_de, func_8028BD4C_de, func_8028BDAC_de and func_8028C370_de for an id, or func_80278E7C_de without one). */




extern s32 func_8028BC0C_de(Shared_World *world, Trigger *trigger);
extern s32 func_8028C424_de(Shared_World *world, s32 id);
extern void func_8028C4B4_de(Shared_World *world, s32 id);
extern void func_80278F00_de(Trigger *trigger);
extern s32 func_80279420_de(Trigger *trigger, s32 arg);
extern void func_8028BB1C_de(Shared_World *world, Trigger *trigger, s32 arg);
extern void func_8028BD4C_de(Shared_World *world, s32 id);
extern s32 func_8028BDAC_de(Shared_World *world, s32 id);
extern void func_8028C370_de(Shared_World *world, s32 id);
extern void func_80278E7C_de(Trigger *trigger);

void func_80279204_de(Trigger *triggers, s32 count, s32 require, s32 enter, s32 exclude, s32 group, s32 arg) {
    s32 i;
    s32 active;
    s32 usable;
    Shared_World *world;
    Trigger *trigger;

    for (trigger = triggers, i = 0; i < count; trigger++, i++) {
        world = &D_8011FE88;
        usable = 1;
        if (world->mode != 4) {
            usable = func_8028BC0C_de(world, trigger) == 0;
        }
        if (!usable) {
            continue;
        }
        active = 1;
        if (!(trigger->flags.bytes.state & 0x20) && enter != 0 && (trigger->mask & enter)) {
            trigger->flags.bytes.state |= 0x40;
            if (trigger->flags.bytes.id != 0) {
                if (func_8028C424_de(world, trigger->flags.bytes.id) != 0) {
                    func_8028C4B4_de(world, trigger->flags.bytes.id);
                }
            } else {
                func_80278F00_de(trigger);
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
        if (func_80279420_de(trigger, arg) == 0) {
            active = 0;
        }
        if (!active) {
            continue;
        }
        if (trigger->flags.bytes.id != 0) {
            if (!(trigger->flags.bytes.state & 0x80)) {
                func_8028BB1C_de(world, trigger, 1);
                trigger->flags.bytes.state |= 0x80;
                func_8028BD4C_de(world, trigger->flags.bytes.id);
                if (func_8028BDAC_de(world, trigger->flags.bytes.id) != 0) {
                    func_8028C370_de(world, trigger->flags.bytes.id);
                }
            }
        } else {
            func_80278E7C_de(trigger);
        }
    }
}
