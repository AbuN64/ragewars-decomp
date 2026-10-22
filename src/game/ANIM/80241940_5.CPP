#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/WORLD.H"
#include "COMMON/OUTPUT.H"
#include "ANIM/RAY180.H"
#include "COMMON/OBJB.H"
#include "COMMON/TRIPLE.H"
#include "ANIM/8023DF60.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

extern void func_80272018_de(CVector3*,CVector3*,CVector3*);

void func_802433DC_de(ContextB0 *mesh,CollisionVertex **points) {
    extern s32 func_8023E8D4_de(CapsuleSweep*,Polygon_func_8023E8D4_de*,s32);
    CVector3 vertex;
    CVector3 edgeA;
    CVector3 edgeB;
    Polygon polygon;
    CVector3 offset;
    MotionSurface *surface;
    CapsuleSweep *ray;
    s32 i;
    s32 byteOffset;
    s32 sideType;
    CollisionVertex **cursor;
    Polygon *base;
    f32 shift;
    f32 px=points[1]->x;
    f32 p0x=points[0]->x;
    f32 py=points[1]->y;
    if (0.0f <= (px-p0x)*(points[2]->y-py) - (py-points[0]->y)*(points[2]->x-px)) return;
    i=0;
    base=&polygon;
    /* Vertex storage starts at 0x18 in the shared collision query. */
    byteOffset=0x18;
    cursor=points;
    ray=mesh->ray;
    polygon.vertexCount=3;
    do {
        s16 *position=(*cursor)->position;
        vertex.x=(f32)position[0];
        vertex.y=(f32)position[1];
        vertex.z=(f32)position[2];
        func_80272898_de(&mesh->element->transform,&vertex,(char *)base+byteOffset);
        byteOffset+=(s32)sizeof(polygon.vertices[0]);
        cursor++;
        i++;
    } while(i<3);
    func_80271F68_de(&edgeA,&polygon.vertices[1],&polygon.vertices[0]);
    func_80271F68_de(&edgeB,&polygon.vertices[2],&polygon.vertices[1]);
    func_80272018_de(&polygon.normal,&edgeB,&edgeA);
    func_8027207C_de(&polygon.normal);
    surface=ray->surface;
    polygon.input=mesh->element;
    polygon.index=-1;
    polygon.category=mesh->kind;
    polygon.flags=mesh->flags;
    switch(mesh->kind) {
    case 1: case 7: case 8: {
        if(!(surface->flags&8)) return;
        if(surface->flags&0x80000) return;
        polygon.type=6;
        polygon.response=surface->materialResponse;
        polygon.kind=7;
        func_8023E8D4_de(ray,&polygon,1);
        polygon.type=5;
        polygon.kind=(surface->flags&0x100000)?7:surface->materialKind;
        if(polygon.normal.y!=0.0f) shift=ray->height;
        else shift=0.0f;
        i=0;
        do {
            polygon.vertices[i].y += shift;
            i++;
        } while(i<3);
        break;
    }
    default: {
        if(polygon.normal.y<0.0f) {
            if(-polygon.normal.y<D_800C3774_de) goto flatFace;
        } else if(polygon.normal.y<D_800C3778) {
flatFace:
            polygon.type=((ray->flags&0x1000) || !(mesh->flags&0x10000000)) ? 3 : 4;
            polygon.response=0.0f;
            polygon.kind=surface->slopeKind;
            goto dispatch;
        }
        sideType=2;
        if(!(polygon.normal.y<0.0f)) sideType=1;
        polygon.type=sideType;
        polygon.response=surface->friction;
        polygon.kind=surface->materialKind;
        break;
    }
    }
dispatch:
    if((u32)(polygon.type-5)<2) {
        func_8023DF70_de(ray,0,ray->radius,&polygon,1);
    } else if(ray->radius==0.0f && ray->secondaryRadius==0.0f) {
        func_8023E8D4_de(ray,&polygon,1);
    } else {
        offset.x=0.0f;
        offset.y=ray->radius;
        offset.z=0.0f;
        i=mesh->segments;
        while(--i!=-1) {
            if(i==mesh->segments-1) {
                if(polygon.type==2) goto skipSweep;
                goto sweep;
            } else if(i==0) {
                if(polygon.type==1) goto skipSweep;
                goto sweep;
            } else if((u32)(polygon.type-1)>=2) {
sweep:
                func_8023DF70_de(ray,&offset,ray->radius,&polygon,1);
            }
skipSweep:
            offset.y+=mesh->step;
        }
    }
}
