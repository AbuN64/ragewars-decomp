#include "include_asm.h"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/PROBE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "SOUND/TRIPLERECAT8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"













/** Return the vertical offset selected by the actor's current state. */
f32 InstHdr_GetActorShadowRadius(Actor_u1 *actor) {
    Resource_u1 *state;

    {
        s32 state_value = actor->resource->kind;
        s32 sw_state_value = state_value - 1;
        if ((unsigned int)sw_state_value > 10) {
            goto sw_state_default;
        }
        switch (sw_state_value) {
        case 0: goto sw_state_1;
        case 1: goto sw_state_2;
        case 2: goto sw_state_default;
        case 3: goto sw_state_default;
        case 4: goto sw_state_5;
        case 5: goto sw_state_default;
        case 6: goto sw_state_default;
        case 7: goto sw_state_8;
        case 8: goto sw_state_default;
        case 9: goto sw_state_default;
        case 10: goto sw_state_11;
        }
    }
    do {
    sw_state_11:
        return actor->resource->valueEC;
    sw_state_1:
        return actor->resource->value2C;
    sw_state_2:
        state = actor->resource;
        if (((CollisionShapeResource *)state)->mode == 0) {
            return D_800C3D6C_de;
        }
        return ((CollisionShapeResource *)state)->height;
    sw_state_5:
        return actor->resource->radius;
    sw_state_8:
        state = actor->resource;
        if ((state->flags14 & 1) != 0) {
            return D_800C3D70_de;
        }
        return state->radius;
    sw_state_default:
        return D_800C3D74_de;
    
    } while (0);
}

f32 InstHdr_GetInactiveActorHeight(Actor_u1 *actor) {
    Resource_u1 *resource = actor->resource;
    s32 kind = resource->kind;

    switch (kind) {
    case 11:
        return resource->valueF8;
    case 4:
    case 1:
        return resource->value34;
    default:
        return 0.0f;
    }
}

f32 InstHdr_GetActorBaseOffset(void *actorStorage) {
    Resource_u1 *nested;
    if (*(u8 *)actorStorage == 1) {
        return ((LevelActor *)actorStorage)->eyeHeight;
    }
    nested = ((Actor_u1 *)actorStorage)->resource;
    if (nested->kind == 0) {
        return nested->value20;
    }
    return 0.0f;
}

#include "TYPES.H"
#include "COMMON.H"

typedef struct MeasureObject MeasureObject;
typedef struct MeasureDefinition {
    s32 kind;
    char pad4[0x14];
    f32 value18;
    char pad1C[0x10];
    f32 value2C;
    char pad30[0xC0];
    f32 valueF0;
} MeasureDefinition;
typedef struct MeasureResource {
    char pad0[0x14];
    u16 packedValue;
} MeasureResource;
typedef struct MeasureModel {
    char pad0[0x30];
    MeasureResource *resource;
} MeasureModel;
typedef struct MeasureOwner {
    char pad0[0x80C];
    MeasureObject *redirect;
} MeasureOwner;
struct MeasureObject {
    u8 kind;
    char pad1[0x17];
    MeasureDefinition *definition;
    char pad1C[0xE4];
    u32 flags;
    char pad104[0x14];
    MeasureModel *model;
    char pad11C[0xBC];
    MeasureOwner *owner;
};

f32 InstHdr_GetActorReach(MeasureObject *object) {
    MeasureDefinition *definition;
top:
    definition = object->definition;
    switch (definition->kind) {
    case 11:
        if (object->kind == 1 && (object->flags & 0x300000) != 0 &&
            object->owner->redirect != 0) {
            object = object->owner->redirect;
            goto top;
        }
        return object->definition->valueF0;
    case 4:
    case 1:
        return definition->value2C;
    case 5:
        return definition->value18;
    default:
        if (object->kind == 2) {
            return Menu_ExpandFloatHighWord(object->model->resource->packedValue);
        }
        return 0.0f;
    }
}
