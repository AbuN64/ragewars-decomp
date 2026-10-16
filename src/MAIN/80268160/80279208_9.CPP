#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80279208.h"
#include "TYPES.H"

typedef struct Owner Owner;

extern void *func_802833D0_de(void *arg0);
extern s32 func_8022B178_de(void *arg0);
extern void func_80229554_de(void *arg0, s32 arg1, s32 arg2);
extern void func_802227F4_de(void *, void *, s32);











void func_80279A00_de(void *arg0) {
    char *actor = arg0;
    char *state;
    char *owner;
    char *resource;

    if (((ObjectLinks1BC *)(actor))->unk_4 != 0x414) {
        if (((ObjectLinks1BC *)(actor))->unk_4 == 0x42D) {
            state = func_802833D0_de(actor);
            if (((IntegerState5AC *)(state))->unk_5A8 != 0 && func_8022B178_de(state) == 0) {
                func_80229554_de(state, ((IntegerState5AC *)(state))->unk_5A4,
                               ((IntegerState5AC *)(state))->unk_5A8);
            }
            goto reset_state;
        }
    } else {
reset_state:
        state = func_802833D0_de(actor);
        ((IntegerState5AC *)(state))->unk_5A8 = 0;
        if (func_8022B178_de(state) == 0) {
            ((IntegerState5AC *)(state))->unk_59C = 1;
        }
    }

    if (((ObjectLinks1BC *)(actor))->unk_1B9 == 8 ||
        ((ObjectLinks1BC *)(actor))->unk_1BA == 8 ||
        ((ObjectLinks1BC *)(actor))->unk_1B8 == 8) {
        resource = ((ObjectLinks1BC *)(actor))->unk_12C;
        if (resource != 0 && *(u8 *)resource == 1 &&
            (((Shared_Actor *)(resource))->weaponFlags & 0x300000) != 0) {
            func_802227F4_de(((Shared_Actor *)(resource))->entity, resource, 2);
        }
    }

    func_80284434_de(actor);
    owner = ((ObjectLinks1BC *)(actor))->unk_118;
    if (((struct ObjectStateC4 *) ((Owner *) owner)->track)->unk_BE != 0xFFFF) {
        func_8025E1C4_de((s32)actor);
    }
    if (((struct ObjectStateC4 *) ((Owner *) owner)->track)->unk_C2 != 0xFFFF) {
        func_8025E1C4_de((s32)actor);
    }
}

/* Spawns an effect for an actor through func_802800C0_de: the rotation comes from the fixed direction D_801042C8 or the actor's own facing, and the spawn point is the actor's position, or when the actor carries a horizontal offset the negated offset turned by the actor's angle, carried through its parent transform when it has one, and added to the position; the flags passed are the given flags with the actor's bits 0x200006. Adapted from func_8027C274_de with the offset reads as static inline getters and a stack state briefly made current in D_80103FCC. */









extern char D_8011D8D0;
extern void *D_80103FCC;
extern char D_801041F0;
extern void func_80271818_de(Vector4f *, Vec3 *);
extern void func_80273760_de(f32 *matrix, s32 angle);
extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);
extern void *func_8027D97C_de(Actor_func_80279B40_de *actor, s32 index);
extern void func_80271F34_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern s32 func_802800C0_de(void *, Actor_func_80279B40_de *, void *, s32, s32, s32, Vec3, Vector4f, Vec3, s32, s32, s32);

static inline f32 offset_x(Actor_func_80279B40_de *actor) {
    if (actor->def->unk14 != 0) {
        return 0.0f;
    }
    return actor->offsetX;
}

static inline f32 offset_y(Actor_func_80279B40_de *actor) {
    if (actor->def->unk14 != 0) {
        return 0.0f;
    }
    return actor->offsetY;
}

void func_80279B40_de(Actor_func_80279B40_de *actor, s32 model, s32 arg2, s32 flags) {
    Vector4f rotation;
    Vec3 direction;
    Vec3 offset;
    Vec3 turned;
    Vec3 carried;
    Vec3 point;
    Vec3 moved;
    f32 matrix[16];
    char scratch[0x108];
    void *parent;

    if (actor->def->unk0 & 0x10) {
        direction = D_801042C8;
    } else {
        direction = actor->facing;
    }
    func_80271818_de(&rotation, &direction);
    if (offset_x(actor) == 0.0f && offset_y(actor) == 0.0f) {
        point = actor->position;
    } else {
        offset.x = -offset_x(actor);
        offset.y = -offset_y(actor);
        offset.z = 0.0f;
        func_80273760_de(matrix, actor->angle);
        func_80272898_de(matrix, &offset, &turned);
        parent = func_8027D97C_de(actor, 0);
        if (parent != 0) {
            func_80272898_de(parent, &turned, &carried);
        } else {
            carried = turned;
        }
        func_80271F34_de(&moved, &carried, &actor->position);
        D_80103FCC = scratch;
        point = moved;
        D_80103FCC = &D_801041F0;
    }
    func_802800C0_de(&D_8011D8D0, actor, actor->owner, actor->unk130, actor->unk134, model,
                  direction, rotation, point, 0, arg2, flags | (actor->flags & 0x200006));
}
