#include "ANIM/RAY180.H"
#include "COMMON/LONE/D_80103FCC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

extern f32 GameObject_GetActorRadius(CollisionProbe *);

extern f32 InstHdr_GetActorReach(CollisionProbe *);

extern f32 GameObject_GetActorHeight(CollisionProbe *);

extern f32 InstHdr_GetActorBaseOffset(CollisionProbe *);

extern f32 func_80241728_de(SurfaceHit *, f32, f32);

struct CCollisionInfo2_t;
extern s32 Unicol_SweepActorMotion(CollisionProbe *, CVector3, CVector3, struct CCollisionInfo2_t *, f32, f32, f32, f32);

extern void GraphU64_AddVec3(CVector3 *, CVector3 *, CVector3 *);



extern char D_80100338;

extern void func_80241950_de(OwnerRecAt18 *, RayCornerBounds *, Actor_func_80242288_de *, OwnerRecAt18 *);

extern void Plane_BuildBoxFace5(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace4(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace3(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace2(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace1(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace0(void *, RayCornerBounds *);
extern s32 func_8023EA44_de(void *, void *, void *, f32, s32);
extern s32 func_8023E8D4_de(void *, void *, s32);
extern s32 func_8023E178_de(void *, void *, f32, f32, f32, s32, void *, s32);
void func_80241BAC_de(Actor_func_80241BAC_de *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;
    s32 hit;

    if (actor->movement.y > 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace0(query, bounds);
        if (func_8023E8D4_de(actor, query, 0)) {
            saved_collision = D_80103FCC;
            D_80103FCC = collision;
            hit_y = func_80241728_de(query, input->x, input->z);
            input->owner = owner;
            extent0 = InstHdr_GetActorReach(input);
            extent1 = GameObject_GetActorRadius(input);
            extent2 = GameObject_GetActorHeight(input);
            extent3 = InstHdr_GetActorBaseOffset(input);
            next.x = input->x;
            next.y = hit_y + D_800C3758_de[0];
            next.z = input->z;
            if (Unicol_SweepActorMotion(input, *(CVector3 *)&input->x, next, &D_801000F0,
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
    }
    if (actor->movement.y < 0.0f) {
        query->word0 = 2;
        Plane_BuildBoxFace1(query, bounds);
        if (func_8023E8D4_de(actor, query, 1)) {
            actor->flags |= 8;
            input->flags38 |= 0x10;
        }
    }
    if (actor->movement.x != 0.0f || actor->movement.z != 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace2(query, bounds);
        hit = func_8023E8D4_de(actor, query, 1);
        Plane_BuildBoxFace3(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        Plane_BuildBoxFace4(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        Plane_BuildBoxFace5(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        if (hit) {
            actor->flags |= 8;
            GraphU64_AddVec3(&((LevelActor *)input)->position1,
                          &((LevelActor *)input)->position1,
                          &actor->movement);
        }
    }
}

void func_80241F24_de(Actor_func_80241BAC_de *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    f32 height;
    void *saved_collision;
    void *entry;
    void *owner_data;

    owner_data = &((LevelActor *)owner)->position0;
    entry = owner->entries + 0x14;
    height = ((ShapeRecAt18V1 *)entry)->radius + GameObject_GetActorRadius(input);
    if (actor->movement.y > 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace0(query, bounds);
        if (func_8023EA44_de(actor, query, owner_data, height, 0)) {
            saved_collision = D_80103FCC;
            D_80103FCC = collision;
            hit_y = func_80241728_de(query, input->x, input->z);
            input->owner = owner;
            extent0 = InstHdr_GetActorReach(input);
            extent1 = GameObject_GetActorRadius(input);
            extent2 = GameObject_GetActorHeight(input);
            extent3 = InstHdr_GetActorBaseOffset(input);
            next.x = input->x;
            next.y = hit_y + D_800C3758_de[1];
            next.z = input->z;
            if (Unicol_SweepActorMotion(input, *(CVector3 *)&input->x, next, &D_801000F0,
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
    }
    if (actor->movement.y < 0.0f) {
        query->word0 = 2;
        Plane_BuildBoxFace1(query, bounds);
        if (func_8023EA44_de(actor, query, owner_data, height, 1)) {
            actor->flags |= 8;
            input->flags38 |= 0x10;
        }
    }
    if (actor->movement.x != 0.0f || actor->movement.z != 0.0f) {
        query->word0 = 3;
        if (func_8023E178_de(actor, owner_data, height,
                          bounds->corners[0].y, bounds->corners[4].y,
                          1, query, 1)) {
            actor->flags |= 8;
            GraphU64_AddVec3(&((LevelActor *)input)->position1,
                          &((LevelActor *)input)->position1,
                          &actor->movement);
        }
    }
}

void func_80242288_de(Actor_func_80242288_de *actor, OwnerRecAt18 *owner) {
    QueryRecAt58 query;
    RayCornerBounds bounds;
    EntryRecAt8V5 *entry;

    entry = &((RayEntryBlock *)owner->entries)->entry;
    if ((actor->field40 != &D_80100338) && (((Shape *)actor->field40)->enabled != 0)) {
        f32 value;
        s32 *word;
        void *owner_data;

        func_80241950_de(owner, &bounds, actor, actor->owner);
        query.word4 = 0;
        query.word8 = 2;
        query.wordC = 0;
        query.word10 = 0;
        query.owner = owner;
        query.index = -1;
        switch (entry->kind) {
        case 1:
            word = &query.word0;
            owner_data = &((LevelActor *)owner)->position0;
            value = ((RayEntryBlock *)owner->entries)->entry.value + actor->fieldC;
            if ((actor->field5C != *(f32 *)&query.word4) ||
                (actor->field64 != *(f32 *)&query.word4)) {
                *word = 3;
                func_8023E178_de(actor, owner_data, value, bounds.corners[0].y,
                              bounds.corners[4].y, 1, word, 1);
            }
            if (actor->field60 > 0.0f) {
                *word = 2;
                Plane_BuildBoxFace1(word, &bounds);
                func_8023EA44_de(actor, word, owner_data, value, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                Plane_BuildBoxFace0(word, &bounds);
                func_8023EA44_de(actor, word, owner_data, value, 1);
                return;
            }
            break;
        case 2:
        {
            f32 movement;
            f32 zero;

            word = &query.word0;
            movement = actor->field60;
            zero = *(f32 *)&query.word4;
            if (zero < movement) {
                *word = 2;
                Plane_BuildBoxFace1(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            if ((actor->field5C != zero) || (actor->field64 != zero)) {
                *word = 3;
                Plane_BuildBoxFace2(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                Plane_BuildBoxFace3(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                Plane_BuildBoxFace4(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                Plane_BuildBoxFace5(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                Plane_BuildBoxFace0(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            break;
        }
        }
    }
}
