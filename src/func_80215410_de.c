#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "stddef.h"
/* Picks an actor's target (the tracked enemy when the aim point is chosen, else the nearest permitted target from func_802149C0_de), classifies it into one of eight kinds, and fills the target record with the kind, target, height difference, position, direction and distance, both in full and flattened to the horizontal plane. */
extern s32 D_8011CD20,D_8013B290;
extern void *func_802149C0_de(void *,void *,s32,s32), *func_80219408_de(void *);
extern f32 func_80216F44_de(void *,f32,f32,f32),func_802B72B0_de(f32);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
static inline s32 func_80215410_kind(Actor_func_80214DD4_de *self, Tracker *ctx, Actor_func_80214DD4_de *target) {
    if (ctx->active == 0) {
        return 6;
    }
    if (target == NULL) {
        if (ctx->slot != 0) {
            return 4;
        }
        return 3;
    }
    if (target == ctx->self) {
        return 2;
    }
    if (*target->kind == 5) {
        return 5;
    }
    if (target->id == 0x64F) {
        return 7;
    }
    if (D_8013B290 == 0) {
        if ((target->flags100 & 0x300000) && target->controller->owner == self
            && target->controller->state == 2) {
            return 1;
        }
        if ((self->flags2E0 & 2) && self->id != 0xCA) {
            return 1;
        }
    }
    return 0;
}
void func_80215410_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, s32 unused, TrackResult *arg3) {
    Vec3 pos;
    Vec3 delta;
    f32 height;
    s32 kind;
    Actor_func_80214DD4_de *target;
    Location *point;
    if ((arg1->team == D_8011CD20) && !(arg0->kind[1] & 0x400) && (!(arg1->flags & 0x80000) || (arg1->unk78 != 0))) {
        arg1->anchor = func_802149C0_de(arg0, arg1, 1, 0);
    }
    if ((*arg0->kind == 1) && (arg1->mode == 0xB)
        && func_80215410_kind(arg0, arg1, arg1->target) == 4) {
        target = arg1->target;
        kind = 4;
    } else {
        target = arg1->anchor;
        kind = func_80215410_kind(arg0, arg1, target);
    }
    if (target != NULL) {
        pos = target->pos;
        height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
    } else {
        switch (kind) {
            case 4:
                point = func_80219408_de(&arg1->slot);
                pos = point->pos;
                if (point->flags & 1) {
                    height = point->heading * 0.0174532942f - arg0->heading;
                } else {
                    height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
                }
                break;
            case 3:
                pos = arg1->homePos;
                height = arg1->homeYaw - arg0->heading;
                break;
            case 6:
                pos = arg0->pos;
                height = 0.0f;
                break;
        }
    }
    func_80274020_de(&height);
    func_80271F68_de(&delta, &pos, &arg0->pos);
    arg3->range = height;
    arg3->kind = kind;
    arg3->target = target;
    arg3->pos = pos;
    arg3->delta = delta;
    arg3->dist = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
    delta.y = 0.0f;
    pos.y = 0;
    arg3->flatPos = pos;
    arg3->flatDelta = delta;
    arg3->flatDist = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}
