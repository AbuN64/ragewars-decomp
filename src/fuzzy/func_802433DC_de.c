#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/motion_step.h"
#include "span_1000/code_802412C0.h"
extern f32 D_800C3774_de,D_800C3778;
extern void func_80272898_de(void*,void*,void*);
extern void func_80271F68_de(Vec3*,Vec3*,Vec3*);
extern void func_80272018_de(Vec3*,Vec3*,Vec3*);
extern void func_8027207C_de(f32*);
extern s32 func_8023E8D4_de(Ray180*,QueryE0*,s32);
extern s32 func_8023DF70_de(Ray180*,Vec3*,f32,QueryE0*,s32);
void func_802433DC_de(ContextB0 *mesh,CollisionVertex **points) {
    Vec3 vertex;
    Vec3 edgeA;
    Vec3 edgeB;
    QueryE0 polygon;
    Vec3 offset;
    MotionSurface *surface;
    Ray180 *ray;
    s32 i;
    s32 byteOffset;
    s32 faceType;
    s32 sideType;
    CollisionVertex **cursor;
    void *destination;
    QueryE0 *base;
    f32 shift;
    f32 px=points[1]->x;
    f32 p0x=points[0]->x;
    f32 py=points[1]->y;
    if (0.0f <= (px-p0x)*(points[2]->y-py) - (py-points[0]->y)*(points[2]->x-px)) return;
    i=0;
    base=&polygon;
    byteOffset=0x18;
    cursor=points;
    ray=mesh->ray;
    polygon.word14=3;
    do {
        s16 *position=(*cursor)->position;
        destination=(char *)base+byteOffset;
        cursor++;
        vertex.x=(f32)position[0];
        byteOffset+=12;
        vertex.y=(f32)position[1];
        vertex.z=(f32)position[2];
        func_80272898_de(&mesh->element->transform,&vertex,destination);
        i++;
    } while(i<3);
    func_80271F68_de(&edgeA,&polygon.vectors[1],&polygon.vectors[0]);
    func_80271F68_de(&edgeB,&polygon.vectors[2],&polygon.vectors[1]);
    func_80272018_de(&polygon.result,&edgeB,&edgeA);
    func_8027207C_de(&polygon.result.x);
    surface=ray->surface;
    polygon.input=mesh->element;
    polygon.index=-1;
    polygon.wordC=mesh->kind;
    polygon.word10=mesh->flags;
    switch(mesh->kind) {
    case 1: case 7: case 8: {
        if(!(surface->flags&8)) return;
        if(surface->flags&0x80000) return;
        polygon.word0=6;
        polygon.word4=surface->materialResponse;
        polygon.word8=7;
        func_8023E8D4_de(ray,&polygon,1);
        polygon.word0=5;
        polygon.word8=(surface->flags&0x100000)?7:surface->materialKind;
        if(polygon.result.y!=0.0f) shift=ray->height;
        else shift=0.0f;
        i=0;
        do {
            polygon.vectors[i].y += shift;
            i++;
        } while(i<3);
        break;
    }
    default: {
        if(polygon.result.y<0.0f) {
            if(-polygon.result.y<D_800C3774_de) goto flatFace;
        } else if(polygon.result.y<D_800C3778) {
flatFace:
            polygon.word0=((ray->flags&0x1000) || !(mesh->flags&0x10000000)) ? 3 : 4;
            polygon.word4=0.0f;
            polygon.word8=surface->slopeKind;
            goto dispatch;
        }
        sideType=2;
        if(!(polygon.result.y<0.0f)) sideType=1;
        polygon.word0=sideType;
        polygon.word4=surface->friction;
        polygon.word8=surface->materialKind;
        break;
    }
    }
dispatch:
    if((u32)(polygon.word0-5)<2) {
        func_8023DF70_de(ray,0,ray->spacing,&polygon,1);
    } else if(ray->spacing==0.0f && ray->secondaryRadius==0.0f) {
        func_8023E8D4_de(ray,&polygon,1);
    } else {
        offset.x=0.0f;
        offset.y=ray->spacing;
        offset.z=0.0f;
        i=mesh->segments;
        while(--i!=-1) {
            if(i==mesh->segments-1) {
                if(polygon.word0==2) goto skipSweep;
                goto sweep;
            } else if(i==0) {
                if(polygon.word0==1) goto skipSweep;
                goto sweep;
            } else if((u32)(polygon.word0-1)>=2) {
sweep:
                func_8023DF70_de(ray,&offset,ray->spacing,&polygon,1);
            }
skipSweep:
            offset.y+=mesh->step;
        }
    }
}
