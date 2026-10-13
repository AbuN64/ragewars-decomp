#include "shared/motion_step.h"
#include "span_1000/code_80271B18.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "shared/func_80214624_de_closed.h"
#include "span_1000/code_8023D370.h"
#include "span_C76B0/data.h"
#include "types.h"
extern void func_80271FC8_de(void *,f32,void *,void *);
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
