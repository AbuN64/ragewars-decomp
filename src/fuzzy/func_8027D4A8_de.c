#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
typedef struct ImpactParams { s32 a, b; } ImpactParams;
typedef struct ImpactEvents { ImpactParams params[14]; u16 models[14], particles[14], sounds[14]; } ImpactEvents;
typedef struct ImpactDef { u32 flags; char pad4[0x14]; ImpactEvents *events; } ImpactDef;
typedef struct ImpactOwner { u8 kind; char pad1[0xFF]; u32 flags; char pad104[0xD4]; void *state; } ImpactOwner;
typedef struct ImpactParticle {
    char pad0[4]; u16 type; char pad6[2]; Vec3 position;
    char pad14[8]; Vec3 facing;
    char pad28[0x34]; u32 flags; char pad60[0xB8]; ImpactDef *definition;
    char pad11C[0x10]; ImpactOwner *owner; char pad130[8]; void *sound;
    char pad13C[0x10]; s16 dead; char pad14E[0x6B]; s8 state, nextState;
    char pad1BB[0x15]; s8 modelOffset; char pad1D1[8]; u8 active;
} ImpactParticle;
typedef struct ImpactContext { Vec3 position; char padC[0xE8 - 0xC]; Vec3 normal; } ImpactContext;
typedef struct ImpactKind { u32 flags; s32 unused; } ImpactKind;
extern void *D_801041F0;
extern ImpactContext D_801001F8;
extern Vec3 D_801042C8;
extern Vec3 D_801002E0;
extern u32 D_801002F0;
extern u8 D_801462E5;
extern ImpactKind D_800CC134[];
extern char D_801379C0, D_8013B1A8, D_8011D8D0;
extern s32 func_80216108_de(void *);
extern void func_802A5BE4_de(void *, Vec3, Vec3, s32, s32);
extern void func_8022B064_de(void *, Vec3 *);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *);

extern void func_8027207C_de(f32 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80265E10_de(void *, void *, u16, s32, Vec3, ImpactParams);
extern void func_80279B40_de(void *, s32, s32, s32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_80284570_de(void *, void *);

void func_8027D4A8_de(ImpactParticle *particle) {
    ImpactDef *definition, *controlledDefinition;
    void *source, *eventSource;
    s32 kind, controlledKind, selection;
    s32 model, sound, effect, halfOffset, paramOffset;
    ImpactParams params;
    Vec3 normal;
    ImpactParams controlledParams;
    ImpactOwner *owner;
    ImpactContext *context;
    Vec3 *normalSource;

    source = D_801041F0;
    definition = particle->definition;
    kind = func_80216108_de(source);
    if (kind == 5) {
        kind = 4;
        particle->flags |= 2;
    }
    if (D_801462E5 && func_80284068_de(particle)) {
        controlledDefinition = particle->definition;
        if (func_80284068_de(particle)) controlledKind = 12;
        else controlledKind = 10;
        halfOffset = controlledKind * 2;
        kind = controlledDefinition->events->models[controlledKind];
        effect = controlledDefinition->events->particles[controlledKind];
        controlledParams = controlledDefinition->events->params[controlledKind];
        sound = controlledDefinition->events->sounds[controlledKind];
        if (effect != 0xFFFF) {
            func_80265E10_de(particle, particle, effect, -1, particle->position, controlledParams);
        }
        if (kind != 0xFFFF) {
            func_80279B40_de(particle, kind, particle->modelOffset, 1);
        }
        if (sound != 0xFFFF) {
            func_8025DE54_de((s16)sound, particle->position, 0, -1);
        }
    } else {
        switch (kind) {
        case 0:
        case 2:
        case 3:
            if (definition->flags & 0x800000) {
                context = &D_801001F8;
                func_802A5BE4_de(&D_801379C0, context->position, context->normal, kind, 0);
            }
            break;
        }
        if (particle->state == 8 || particle->nextState == 8) {
            if ((D_801002F0 & 0x1000000) && (owner = particle->owner) && owner->kind == 1 && (owner->flags & 0x300000)) {
                particle->flags |= 0x20000;
                particle->position = D_801001F8.position;
                particle->facing = D_801042C8;
                func_8022B064_de(particle->owner->state, &particle->position);
            } else particle->dead = 1;
        }
        if (particle->type == 0x56 || particle->type == 0x126 || particle->type == 0xCD || particle->type == 0xF) {
            particle->flags |= 0x20000;
            particle->position = D_801001F8.position;
            particle->facing = D_801042C8;
            if (particle->active) {
                func_80284178_de(particle);
                func_802A42F4_de(&D_801379C0, particle);
            }
            if (particle->sound) {
                func_80268C7C_de(&D_8013B1A8, (s32)particle->sound);
                particle->sound = 0;
            }
        }
        normalSource = &D_801002E0;
        normal = *normalSource;
        func_8027207C_de(&normal.x);
        func_80271F9C_de(&normal, &normal, 1.024f);
        func_80271F34_de(&particle->position, &particle->position, &normal);
        selection = kind;
        halfOffset = kind * 2;
        paramOffset = kind * 8;
        kind = definition->events->models[selection];
        effect = definition->events->particles[selection];
        params = definition->events->params[selection];
        sound = definition->events->sounds[selection];
        if (effect != 0xFFFF) {
            eventSource = source;
            if (D_800CC134[effect].flags & 2) eventSource = particle;
            func_80265E10_de(eventSource, particle, effect, -1, D_801001F8.position, params);
        }
        if (kind != 0xFFFF) func_80279B40_de(particle, kind, -8, 1);
        if (sound != 0xFFFF) func_8025DE54_de((s16)sound, D_801001F8.position, 0, (s32)particle);
        if (particle->flags & 0x30000) return;
        if (particle->state != 1) return;
    }
    func_80284570_de(&D_8011D8D0, particle);
    func_80284434_de(particle);
}
