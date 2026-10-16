#include "span_1000/code_8023A284.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/motion_step.h"
#include "span_1000/code_8023D370.h"
#include "span_1000/code_80271B18.h"
#include "span_C76B0/data.h"
#include "types.h"

extern void func_80271FC8_de(Vec3 *,f32,void *,void *);

/* Resolve contact response, updating translation and rotation along the contact normal. */
s32 func_8023D380_de(ActorMotion *a) {
    Vec3 remaining;
    Vec3 slide;
    Vec3 bounce;
    Vec3 reflection;
    Vec3 projected;
    Vec3 gravity;
    Vec3 rotation;
    MotionSurface *settings;
    Vec3 *delta;
    f32 step, highest, d, scale, damping, fraction;
    s32 i, active, type, timer;
    settings=a->surface;
    if (a->collisionState!=0) {
    func_8027207C_de(&a->normal.x);
    step=D_800CB404_de*D_800C3634_de;
    a->position=a->end;
    a->projectedOrientation=a->orientation;
    if (step<=a->distance && a->mode!=7) {
        f32 adjusted=a->blend-step/a->distance;
        a->blend=adjusted;
        func_80271FC8_de(&a->interpolated,adjusted,&a->start,&a->end);
    }
    if(a->grounded!=0 && a->collisionState==3) {
        highest=a->contacts[0].y;
        i=1;
        while(i<a->contactCount) { f32 point=a->contacts[i].y; if(!(highest<=point)) point=highest; highest=point; i++; }
        d=highest-a->start.y;
        if(0.0f<d && d<=D_800C3638_de) {
            a->interpolated=a->start; a->position=a->end; a->projectedOrientation=a->orientation;
            a->blend=0.0f;
            d+=D_800C363C_de;
            a->interpolated.y+=d;
            a->position.y+=d;
            return 1;
        }
    }
    type=a->mode;
    if(type==6) { if(a->grounded==0)a->mode=3;else a->mode=2; }
    type=a->mode;
    if(type==3 && settings->response<D_800C3640_de && a->distance<D_800C3644_de) {
        s32 response=1;
        if(!(a->velocity.x*a->velocity.x+a->velocity.z*a->velocity.z<D_800C3648_de))response=2;
        a->mode=response;
    }
    type=a->collisionState;
    if(type>=3)goto planar;
    if(type<=0)goto planar;
    {
        timer=a->verticalTicks;
        if(timer!=0){a->verticalTicks=timer-1;goto vertical;}
        goto zero_vertical;
    }
planar:
    timer=a->horizontalTicks;
    if(timer!=0)a->horizontalTicks=timer-1;
vertical:
    if(a->verticalTicks==0){
zero_vertical:
        a->velocity.y=0.0f;
    }
if(a->horizontalTicks==0){a->velocity.x=a->velocity.z=0.0f;} timer=a->horizontalTicks; active=0; if(timer!=0 || a->verticalTicks!=0)active=1;
    switch(a->mode) {
    case 7:
        if(a->orientationActive!=0)a->projectedOrientation=a->orientation;
        if(active!=0)a->position=a->end;
        if(a->transitionActive!=0) {
            if(a->collisionState==5){a->flags^=0x1000;func_8023EC54_de(a,&a->collisionState);}
            if(a->collisionState==6){a->flags^=0x4000;func_8023EC54_de(a,&a->collisionState);}
        }
        return 1;
    case 1: case 8:
        if(a->orientationActive!=0){a->projectedOrientation.x=0.0f;a->projectedOrientation.y=0.0f;a->projectedOrientation.z=0.0f;}
        if(active!=0)a->position=a->interpolated;
        return 0;
    case 3: {
        f32 remainingFraction;
        if(a->orientationActive!=0) {
            func_80272180_de(&rotation,&a->orientation,&a->normal,settings->response);
            a->projectedOrientation=rotation;
            damping=a->damping;
            func_80271F9C_de(&a->projectedOrientation,&a->projectedOrientation,D_800C3670_de-damping);
        }
        if(active==0)return 1;
        remainingFraction=a->blend;
        scale=D_800C3674_de;
        remainingFraction=scale-remainingFraction;
        func_80271F9C_de(&remaining,&a->velocity,remainingFraction);
        delta=&slide;
        func_80272180_de(delta,&remaining,&a->normal,settings->response);
        func_80271F9C_de(delta,delta,scale-a->damping);
        func_80271F34_de(&a->position,&a->interpolated,delta);
        return 1;
    }
    case 2: {
        f32 remainingFraction;
        if(a->orientationActive!=0) {
            func_80272214_de(&rotation,&a->orientation,&a->normal);
            a->projectedOrientation=rotation;
            damping=a->damping;
            func_80271F9C_de(&a->projectedOrientation,&a->projectedOrientation,D_800C3678_de-damping);
        }
        if(active==0)return 1;
        remainingFraction=a->blend;
        scale=D_800C367C_de;
        remainingFraction=scale-remainingFraction;
        func_80271F9C_de(&remaining,&a->velocity,remainingFraction);
        func_80272214_de(&bounce,&remaining,&a->normal);
        func_80271F9C_de(&bounce,&bounce,scale-a->damping);
    func_80271F34_de(&a->position,&a->interpolated,&bounce);
    func_80271F9C_de(&gravity,&a->normal,D_800D0640[0]*D_800C368C_de);
    func_80271F34_de(&a->position,&a->position,&gravity);
    return 1;

    }
    case 4:
        if(a->orientationActive!=0) {rotation=func_802723FC_de(&a->orientation,&a->normal);a->projectedOrientation=rotation;}
        if(active==0)return 1;
        fraction=a->blend;
        func_80271F9C_de(&remaining,&a->velocity,D_800C3680_de-fraction);
        bounce=func_802723FC_de(&remaining,&a->normal);
        func_80271F34_de(&a->position,&a->interpolated,&bounce);
    func_80271F9C_de(&gravity,&a->normal,D_800D0640[0]*D_800C368C_de);
    func_80271F34_de(&a->position,&a->position,&gravity);
    return 1;

    case 5: {
        f32 remainingFraction;
        if(a->orientationActive!=0) {
            func_80272214_de(&reflection,&a->orientation,&a->normal);
            projected=func_802723FC_de(&a->orientation,&a->normal);
            func_80271FC8_de(&a->projectedOrientation,0.25f,&reflection,&projected);
            damping=a->damping;
            func_80271F9C_de(&a->projectedOrientation,&a->projectedOrientation,D_800C3684_de-damping);
        }
        if(active==0)return 1;
        remainingFraction=a->blend;
        scale=D_800C3688_de;
        remainingFraction=scale-remainingFraction;
        func_80271F9C_de(&remaining,&a->velocity,remainingFraction);
        func_80272214_de(&reflection,&remaining,&a->normal);
        projected=func_802723FC_de(&remaining,&a->normal);
        func_80271FC8_de(&bounce,0.25f,&reflection,&projected);
        func_80271F9C_de(&bounce,&bounce,scale-a->damping);
    func_80271F34_de(&a->position,&a->interpolated,&bounce);
    func_80271F9C_de(&gravity,&a->normal,D_800D0640[0]*D_800C368C_de);
    func_80271F34_de(&a->position,&a->position,&gravity);
    return 1;

    }
    case 6: default: return 0;
    }
    }
    return 0;
}

/* Tests a ray against an axis-aligned box: a ray starting inside the box hits at parameter 0; otherwise
 * each axis whose start and end differ gives the parameter where the ray reaches the box face it
 * approaches, and the first such hit nearer than the ray's current nearest hit whose point lies within the
 * face's other two extents is written out. Returns whether the box was hit. */







s32 func_8023DAA0_de(Ray *ray, Box *box, f32 *out) {
    Vec3 hit;
    Vec3 *start;
    Vec3 *end;
    f32 t;

    start = &ray->start;
    end = &ray->end;
    if (box->max.x >= start->x && box->max.y >= start->y && box->max.z >= start->z && box->min.x <= start->x &&
        box->min.y <= start->y && box->min.z <= start->z) {
        *out = 0.0f;
        return 1;
    }
    if (start->x != end->x) {
        if (start->x < end->x) {
            t = (box->min.x - start->x) / (end->x - start->x);
        } else {
            t = (start->x - box->max.x) / (start->x - end->x);
        }
        if (t < ray->nearest) {
            hit.y = start->y + t * ray->dir.y;
            hit.z = start->z + t * ray->dir.z;
            if (box->min.y <= hit.y && hit.y <= box->max.y && box->min.z <= hit.z && hit.z <= box->max.z) {
                *out = t;
                return 1;
            }
        }
    }
    if (start->y != end->y) {
        if (start->y < end->y) {
            t = (box->min.y - start->y) / (end->y - start->y);
        } else {
            t = (start->y - box->max.y) / (start->y - end->y);
        }
        if (t < ray->nearest) {
            hit.x = start->x + t * ray->dir.x;
            hit.z = start->z + t * ray->dir.z;
            if (box->min.x <= hit.x && hit.x <= box->max.x && box->min.z <= hit.z && hit.z <= box->max.z) {
                *out = t;
                return 1;
            }
        }
    }
    if (start->z != end->z) {
        if (start->z < end->z) {
            t = (box->min.z - start->z) / (end->z - start->z);
        } else {
            t = (start->z - box->max.z) / (start->z - end->z);
        }
        if (t < ray->nearest) {
            hit.x = start->x + t * ray->dir.x;
            hit.y = start->y + t * ray->dir.y;
            if (box->min.x <= hit.x && hit.x <= box->max.x && box->min.y <= hit.y && hit.y <= box->max.y) {
                *out = t;
                return 1;
            }
        }
    }
    return 0;
}

/* Tests a ray's horizontal segment against a rectangle (min x/z at 0 and 4, max x/z at 8 and 12): a start
 * point inside gives parameter 0; otherwise the crossing of the x edge facing the start is tried first and
 * then the z edge, each accepted when nearer than the ray's current nearest hit at 0x17C and landing within
 * the other axis's extent (using the ray's direction at 0x5C/0x64); the accepted parameter is stored and 1
 * is returned, 0 when the segment misses. */







s32 func_8023DDC4_de(Ray *ray, Vector4f *rect, f32 *t) {
    Vec3 *start;
    Vec3 *end;
    f32 a;
    f32 b;
    f32 param;
    Vec3 hit;

    start = &ray->start;
    end = &ray->end;
    if (rect->z >= start->x && rect->w >= start->z && rect->x <= start->x && rect->y <= start->z) {
        *t = 0.0f;
        return 1;
    }
    a = start->x;
    b = end->x;
    if (a != b) {
        if (a < b) {
            param = (rect->x - a) / (b - a);
        } else {
            param = (a - rect->z) / (a - b);
        }
        if (param < ray->nearest) {
            hit.z = start->z + param * ray->dir.z;
            if (rect->y <= hit.z && hit.z <= rect->w) {
                *t = param;
                return 1;
            }
        }
    }
    a = start->z;
    b = end->z;
    if (a == b) {
        return 0;
    }
    if (a < b) {
        param = (rect->y - a) / (b - a);
    } else {
        param = (a - rect->w) / (a - b);
    }
    if (!(param < ray->nearest)) {
        return 0;
    }
    hit.x = start->x + param * ray->dir.x;
    if (rect->x <= hit.x && hit.x <= rect->z) {
        *t = param;
        return 1;
    }
    return 0;
}
