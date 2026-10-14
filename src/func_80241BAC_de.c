#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"
#include "common/unused.h"








extern f32 func_8024D398_de(Input_func_80241BAC_de *);
extern f32 func_8024E464_de(Input_func_80241BAC_de *);
extern f32 func_8024D284_de(Input_func_80241BAC_de *);
extern f32 func_8024E420_de(Input_func_80241BAC_de *);
extern void func_80240D20_de(Query_func_80241BAC_de *, Bounds *);
extern void func_80240E00_de(Query_func_80241BAC_de *, Bounds *);
extern void func_80240EE0_de(Query_func_80241BAC_de *, Bounds *);
extern void func_80240FC0_de(Query_func_80241BAC_de *, Bounds *);
extern void func_802410A0_de(Query_func_80241BAC_de *, Bounds *);
extern void func_80241180_de(Query_func_80241BAC_de *, Bounds *);
extern s32 func_8023E8D4_de(Actor_func_80241BAC_de *, Query_func_80241BAC_de *, s32);
extern f32 func_80241728_de(Query_func_80241BAC_de *, f32, f32);
extern s32 func_8024491C_de(Input_func_80241BAC_de *, Vec3, Vec3, void *, f32, f32, f32, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern void *D_80103FCC;
extern f32 D_800C3758_de[];




void func_80241BAC_de(Actor_func_80241BAC_de *actor, OwnerRecAt18 *owner, Bounds *bounds, Query_func_80241BAC_de *query, Input_func_80241BAC_de *input) {
    u8 collision[0x108];
    Vec3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;
    s32 hit;

    if (actor->movement.y > 0.0f) {
        query->word0 = 3;
        func_80240D20_de(query, bounds);
        if (func_8023E8D4_de(actor, query, 0)) {
            saved_collision = D_80103FCC;
            D_80103FCC = collision;
            hit_y = func_80241728_de(query, input->x, input->z);
            input->owner = owner;
            extent0 = func_8024E464_de(input);
            extent1 = func_8024D398_de(input);
            extent2 = func_8024D284_de(input);
            extent3 = func_8024E420_de(input);
            next.x = input->x;
            next.y = hit_y + D_800C3758_de[0];
            next.z = input->z;
            if (func_8024491C_de(input, *(Vec3 *)&input->x, next, &D_801000F0,
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
        func_80240E00_de(query, bounds);
        if (func_8023E8D4_de(actor, query, 1)) {
            actor->flags |= 8;
            input->flags38 |= 0x10;
        }
    }
    if (actor->movement.x != 0.0f || actor->movement.z != 0.0f) {
        query->word0 = 3;
        func_80240EE0_de(query, bounds);
        hit = func_8023E8D4_de(actor, query, 1);
        func_80240FC0_de(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        func_802410A0_de(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        func_80241180_de(query, bounds);
        hit |= func_8023E8D4_de(actor, query, 1);
        if (hit) {
            actor->flags |= 8;
            func_80271F34_de(&((Actor_func_8024A7A0_de *)input)->position1,
                          &((Actor_func_8024A7A0_de *)input)->position1,
                          &actor->movement);
        }
    }
}
