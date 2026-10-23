#include "include_asm.h"
#include "RENDER_3/RANGENODE.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "RENDER_3/80268160.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"

/* Spawns an effect of the given kind for an object through func_802627A0_de at the object's position with its velocity (none when the object is inactive) and a uniform scale; kind 0x40C instead starts at the camera with no velocity and, once spawned, follows the camera's target through func_802833D0_de, and kinds 0x474 to 0x477 attach to the host's partner effect for active flagged hosts, otherwise the effect is started through func_80262C88_de. */

extern Camera_func_8026851C_de *D_80103FCC;

extern s32 func_802833D0_de(void *host);

extern s32 func_80262C88_de(void *effect);

/* Forwards a position read from an object to func_8028FFD0_de on the global D_80131600 with a zero offset and a zero trailing weight, returning its result. Adapted from func_8028BFD8_de with the base argument, the source vector, the trailing arguments passed as a by-value struct and the return value changed. */









extern s32 func_8028FFD0_de(s32, s32, s32, Triple, Triple, s32, f32);

void func_8026851C_de(SourceRecAt1C *source, Shared_ParticleOwner *host, s32 unused, Spawn spawn) {
    Vec3f scale;
    Vec3f velocity;
    Effect_func_8026851C_de *effect;
    void *storage;
    Effect_func_8026851C_de *partner;

#if defined(VERSION_DE)
    if (spawn.kind == 0x321) {
        return;
    }
#endif
    if (source->active == 0) {
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
    } else {
        velocity = source->velocity;
    }
    spawn.position = source->position;
    scale.x = spawn.size;
    scale.y = spawn.size;
    scale.z = spawn.size;
    if (spawn.kind == 0x40C) {
        spawn.position = D_80103FCC->position;
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
    }
    storage = func_802627A0_de(&D_80131150, spawn.kind, source->id, spawn.position, 0.0f, velocity, scale, 0);
    effect = storage;
    if (effect == 0) {
        return;
    }
    if (spawn.kind == 0x40C) {
        effect->target = func_802833D0_de(host);
        effect->offset.x = D_80103FCC->offset.x;
        effect->offset.y = D_80103FCC->offset.y;
        effect->offset.z = D_80103FCC->offset.z;
    } else if ((unsigned)(spawn.kind - 0x474) < 4) {
        if (host->kind == 1 && (host->flags & 0x300000)) {
            partner = host->state;
            if (partner != 0) {
                partner->child = effect;
                effect->scale = partner->scale;
            }
        } else {
            func_80262C88_de(effect);
        }
    }
}

s32 func_802686EC_de(s32 arg0, Input80216D3C *arg1, s32 arg2, Triple arg3, Extra arg6) {
    CVector3 scale;
    Triple zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    scale.x = arg6.scale;
    scale.y = arg6.scale;
    scale.z = arg6.scale;
    return func_8028FFD0_de((s32)&D_80131600, 0, arg6.id, zero, arg1->vec, 0, 0.0f);
}

typedef struct SoundDefinition { s32 kind; } SoundDefinition;
typedef struct SoundActor {
    char pad0[0x18];
    SoundDefinition *definition;
} SoundActor;
typedef struct SoundSource {
    u8 kind;
    char pad1[0xCF];
    s32 owner;
} SoundSource;
extern f32 D_800C4478_de;
extern f32 D_800C447C;
extern s32 func_8024E968_de(void *);
extern s32 func_8025DEC0_de(s32, CVector3, s32, s32, f32);

void Render_PlayTeamEffect(SoundActor *actor, SoundSource *source, s32 unused,
                     CVector3 position, ParamsRecAt4 params) {
    f32 gain = D_800C4478_de;
    s32 owner = -1;
    u8 kind;
    if (D_80145088.status[7] == 0 && func_8024E968_de(actor) == params.team) {
        kind = source->kind;
        switch (kind) {
        case 0:
            owner = source->owner;
            break;
        case 1:
            if (actor->definition->kind == kind) {
                if (D_80145088.settings.flags & 0x40) {
                    gain = D_800C447C;
                }
                if (D_80145088.settings.flags & 0x20) {
                    gain = D_800C9570[0];
                }
            }
            break;
        }
        func_8025DEC0_de(params.value, position, 0, owner, gain);
    }
}
