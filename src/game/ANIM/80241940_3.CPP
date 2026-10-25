#include "TYPES.H"
#include "COMMON/LONE/D_80103FCC.H"
#include "COMMON/SHAREDPLAYER.H"
#include "ANIM/RAY180.H"

extern void Particle_SubtractVectors(Triple *, Triple *, Triple *);

extern void func_80241950_de(OwnerRecAt18 *, Bounds *, Actor_func_80242550_de *, Source_func_802164A8_de *);

extern void func_80241BAC_de(Actor_func_80242550_de *, OwnerRecAt18 *, Bounds *, SurfaceHit *, Source_func_802164A8_de *);

extern void func_80241F24_de(Actor_func_80242550_de *, OwnerRecAt18 *, Bounds *, SurfaceHit *, Source_func_802164A8_de *);

extern f32 func_8024D398_de(void *);

extern f32 Sound_GetActorReach(Input_func_802426CC_de *);

extern f32 Particle_GetActorHeight(Input_func_802426CC_de *);

extern f32 Sound_GetActorBaseOffset(void *);

extern f32 func_80241728_de(SurfaceHit *, f32, f32);

extern s32 func_8024491C_de(Input_func_802426CC_de *, CVector3, CVector3, struct MotionSurface *, f32, f32, f32, f32);


extern char D_801000F0;

void func_80242550_de(Actor_func_80242550_de *actor, Source_func_802164A8_de *input) {
    Triple saved_previous;
    Triple saved_position;
    SurfaceHit query;
    Bounds bounds;
    OwnerRecAt18 *owner;
    EntryRecAt4V3 *entry;

    owner = actor->owner;
    entry = (EntryRecAt4V3 *)(owner->entries + 0x14);
    if (*actor->flags & 0x40000) {
        saved_previous = actor->previous;
        saved_position = actor->position;
        actor->previous = input->position;
        Particle_SubtractVectors(&actor->position, &input->position, &actor->delta);
        query.word4 = 0;
        query.word8 = 1;
        query.wordC = 0;
        query.word10 = 0;
        query.input = input;
        query.index = -1;
        func_80241950_de(owner, &bounds, actor, input);
        switch (entry->kind) {
        case 1:
            func_80241F24_de(actor, owner, &bounds, &query, input);
            break;
        case 2:
            func_80241BAC_de(actor, owner, &bounds, &query, input);
            break;
        }
        actor->previous = saved_previous;
        actor->position = saved_position;
    }
}

struct MotionSurface;

void func_802426CC_de(ActorRecAtB0 *actor, void *owner, Input_func_802426CC_de *input, SurfaceHit *query) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;

    saved_collision = D_80103FCC;
    D_80103FCC = collision;
    hit_y = func_80241728_de(query, input->x, input->z);
    input->owner = owner;
    extent0 = Sound_GetActorReach(input);
    extent1 = func_8024D398_de(input);
    extent2 = Particle_GetActorHeight(input);
    extent3 = Sound_GetActorBaseOffset(input);
    next.x = input->x;
    next.y = hit_y + D_800C3760_de;
    next.z = input->z;
    if (func_8024491C_de(input, *(CVector3 *)&input->x, next, &D_801000F0,
                      extent0, extent1, extent2, extent3)) {
        actor->saved_query = *query;
        actor->flags |= 8;
        input->flags38 |= 0x10;
    } else {
        input->y = next.y;
        if (input->floor < 0.0f) input->floor = 0.0f;
        {
            s32 flags = actor->flags;
            actor->flags = flags | 0x20;
            if (input->kind == 1 && (input->flags100 & 0x300000))
                actor->flags = flags | 0x60;
        }
        input->flags38 = (input->flags38 & ~3) | 2;
    }
    D_80103FCC = saved_collision;
}
