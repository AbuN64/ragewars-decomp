#include "TYPES.H"

typedef struct EffectPair { s32 first, second; } EffectPair;
typedef struct EffectTable {
    EffectPair pairs[14];
    u16 animations[14], effects[14], sounds[14];
} EffectTable;
typedef struct ActorDefinition {
    u32 flags;
    char pad04[0x14];
    EffectTable *effects;
} ActorDefinition;
typedef struct Actor {
    char pad00[4]; u16 kind; char pad06[2];
    s32 x, y, z;
    char pad14[0x48]; u32 flags;
    char pad60[0xB8]; ActorDefinition *definition;
    char pad11C[0x14]; s32 *counter; void *owner; s32 handle;
    char pad13C[0x94]; s8 channel; char pad1D1[8]; u8 linked;
    char pad1DA[0xA]; void *list;
    char pad1E8[4]; struct Actor *next;
} Actor;
typedef struct ActorWorld {
    char pad00[0xFC00]; IntrusiveList active, secondary;
    char padFC28[0x14]; Actor *head;
} ActorWorld;
extern char D_801379C0, D_8013B1A8;
extern void func_80265E10_de(void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_80279B40_de(void *, s32, s32, s32);
extern void func_8025DE54_de(s32, s32, s32, s32, s32, s32);
extern void func_80279A00_de(void *);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *);
extern void func_80255ED8_de(void *, void *);
extern void func_80255CB8_de(void *, void *);

void func_80282A44_de(ActorWorld *world, void *owner) {
    Actor *actor, *next;
    ActorDefinition *definition;
    s32 index;
    u16 animation, effect, sound;
    EffectPair pair;
    for (actor = world->head; actor != 0; actor = next) {
        next = actor->next;
        if ((actor->kind == 0x41E || actor->kind == 0x3EF) &&
            (actor->flags & 0x100) && actor->owner == owner) {
            definition = actor->definition;
            index = func_80284068_de(actor) ? 12 : 10;
            animation = definition->effects->animations[index];
            effect = definition->effects->effects[index];
            pair = definition->effects->pairs[index];
            sound = definition->effects->sounds[index];
            if (effect != 0xFFFF)
                func_80265E10_de(actor, actor, effect, -1, actor->x, actor->y, actor->z, pair.first, pair.second);
            if (animation != 0xFFFF)
                func_80279B40_de(actor, animation, actor->channel, 1);
            if (sound != 0xFFFF)
                func_8025DE54_de((s16)sound, actor->x, actor->y, actor->z, 0, -1);
            if ((actor->flags & 0x100) && !(actor->flags & 0x800)) {
                func_80279A00_de(actor);
                if (actor->linked) {
                    func_80284178_de(actor);
                    func_802A42F4_de(&D_801379C0, actor);
                }
                if (actor->handle) {
                    func_80268C7C_de(&D_8013B1A8, actor->handle);
                    actor->handle = 0;
                }
                if (actor->counter) --*actor->counter;
                actor->flags &= 0xFDFFFEFF;
                func_80255ED8_de(actor->list, actor);
                actor->list = 0;
                func_80255CB8_de(&world->active, actor);
                if (actor->flags & 0x1000000)
                    func_80255ED8_de(&world->secondary, actor);
            }
        }
    }
}
