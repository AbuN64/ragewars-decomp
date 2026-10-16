#include "shared/gameplay_sound_table.h"
#include "TYPES.H"
typedef struct Trigger { char pad0[4]; u16 actor; char pad6[2]; u16 action, owner; char padC[4]; u8 sound, table, entry; } Trigger;
typedef struct TriggerActor { char pad0[0x170]; char component[0x178]; } TriggerActor;
typedef void (*PrimaryCallback)(TriggerActor *, void *, Trigger *);
typedef void (*SecondaryCallback)(Trigger *);
typedef struct CallbackPair { PrimaryCallback primary; SecondaryCallback secondary; } CallbackPair;

extern CallbackPair *D_800CD668_de[];

extern void *D_800CD730;

#include "shared/menu_match_globals.h"
extern s32 D_8011FE88, D_801371D4;
extern TriggerActor *D_8011BF00;
extern void func_80239908_de(void *, void *, s32, void *, f32);
extern s32 func_804030E0_de(s32);
void func_80278C10_de(Trigger *trigger) {
    CallbackPair *table;
    void *fallback;
    u8 index;
    s32 callback;
    table = D_800CD668_de[trigger->table];
    if (table != 0) {
        fallback = &D_80145088.fallbackCamera;
        if (D_801462E5 == 0) {
            fallback = D_80145088.cameras;
            if (fallback == 0) fallback = &D_80145088.fallbackCamera;
        }
        if (D_8011FE88 == 4) {
            index = trigger->sound;
            if (index != 0) {
                func_80239908_de(&D_80145088, fallback, gameplaySoundValue(index), D_800CD730, triggerSoundWeight());
                callback = gameplaySoundHook(trigger->sound);
                if (callback != 0) func_8025E11C_de(callback);
            }
            if (trigger->action >= 2) func_804030E0_de(trigger->action);
        }
        table += trigger->entry;
        if (trigger->owner == D_801371D4) {
            PrimaryCallback fn;
            TriggerActor *actor;
            fn = table->primary;
            actor = &D_8011BF00[trigger->actor];
            if (fn != 0) fn(actor, actor->component, trigger);
        } else {
            SecondaryCallback fn;
            fn = table->secondary;
            if (fn != 0) fn(trigger);
        }
    }
}
