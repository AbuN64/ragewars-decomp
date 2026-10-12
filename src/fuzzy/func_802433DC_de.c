#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "span_1000/code_802412C0.h"
extern f32 D_800C3774_de,D_800C3778;
extern void func_80272898_de(void*,void*,void*);
extern void func_80271F68_de(Vec3*,Vec3*,Vec3*);
extern void func_80272018_de(Vec3*,Vec3*,Vec3*);
extern void func_8027207C_de(f32*);
extern s32 func_8023E8D4_de(Ray_func_8023E8D4_de*,Polygon_func_8023E8D4_de*,s32);
extern s32 func_8023DF70_de(Ray_func_8023DF70_de*,Vec3*,f32,Polygon*,s32);
typedef struct CollisionSurface {
    u32 flags;
    char pad4;
    s8 slopeKind;
    s8 sideKind;
    char pad7[9];
    f32 friction;
    char pad14[4];
    f32 water;
} CollisionSurface;
typedef union CollisionRay {
    Ray_func_8023E8D4_de plane;
    Ray_func_8023DF70_de sphere;
    struct {
        char pad0[8];
        f32 radius;
        f32 radius2;
        char pad10[12];
        f32 height;
        char pad20[0x1C];
        u32 flags;
        CollisionSurface *surface;
    } body;
} CollisionRay;
typedef struct CollisionTransform { char reserved0[0x68]; Matrix matrix; } CollisionTransform;
typedef struct CollisionMesh {
    CollisionRay *ray;
    char pad4[0x4C];
    s32 layers;
    f32 layerStep;
    CollisionTransform *transform;
    s32 kind;
    u32 flags;
} CollisionMesh;
typedef struct CollisionVertex {
    f32 x,y;
    char pad8[0x14];
    s16 *position;
} CollisionVertex;
typedef union CollisionPolygon {
    QueryE0 query;
    Polygon_func_8023E8D4_de plane;
    Polygon sphere;
} CollisionPolygon;
void func_802433DC_de(CollisionMesh *mesh,CollisionVertex **points) {
    Vec3 vertex;
    Vec3 edgeA;
    Vec3 edgeB;
    CollisionPolygon polygon;
    Vec3 offset;
    CollisionSurface *surface;
    CollisionRay *ray;
    s32 i;
    s32 byteOffset;
    s32 faceType;
    s32 sideType;
    CollisionVertex **cursor;
    void *destination;
    CollisionPolygon *base;
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
    polygon.query.word14=3;
    do {
        s16 *position=(*cursor)->position;
        destination=&polygon.query.vectors[i];
        vertex.x=(f32)position[0];
        byteOffset+=12;
        vertex.y=(f32)position[1];
        vertex.z=(f32)position[2];
        i++;
        cursor++;
        func_80272898_de(&mesh->transform->matrix,&vertex,destination);
    } while(i<3);
    func_80271F68_de(&edgeA,&polygon.query.vectors[1],&polygon.query.vectors[0]);
    func_80271F68_de(&edgeB,&polygon.query.vectors[2],&polygon.query.vectors[1]);
    func_80272018_de(&polygon.query.result,&edgeB,&edgeA);
    func_8027207C_de(&polygon.query.result.x);
    surface=ray->body.surface;
    polygon.query.input=mesh->transform;
    polygon.query.index=-1;
    polygon.query.wordC=mesh->kind;
    polygon.query.word10=mesh->flags;
    switch(mesh->kind) {
    case 1: case 7: case 8: {
        if(!(surface->flags&8)) return;
        if(surface->flags&0x80000) return;
        polygon.query.word0=6;
        polygon.query.word4=surface->water;
        polygon.query.word8=7;
        func_8023E8D4_de(&ray->plane,&polygon.plane,1);
        polygon.query.word0=5;
        polygon.query.word8=(surface->flags&0x100000)?7:surface->sideKind;
        if(polygon.query.result.y!=0.0f) shift=ray->body.height;
        else shift=0.0f;
        i=0;
        do {
            polygon.query.vectors[i].y += shift;
            i++;
        } while(i<3);
        break;
    }
    default: {
        if(polygon.query.result.y<0.0f) {
            if(-polygon.query.result.y<D_800C3774_de) goto flatFace;
        } else if(polygon.query.result.y<D_800C3778) {
flatFace:
            faceType=3;
            if(!(ray->body.flags&0x1000)) {
                faceType=4;
                if(!(mesh->flags&0x10000000)) faceType=3;
            }
            polygon.query.word0=faceType;
            polygon.query.word4=0.0f;
            polygon.query.word8=surface->slopeKind;
            goto dispatch;
        }
        sideType=2;
        if(!(polygon.query.result.y<0.0f)) sideType=1;
        polygon.query.word0=sideType;
        polygon.query.word4=surface->friction;
        polygon.query.word8=surface->sideKind;
        break;
    }
    }
dispatch:
    if((u32)(polygon.query.word0-5)<2) {
        func_8023DF70_de(&ray->sphere,0,ray->body.radius,&polygon.sphere,1);
    } else if(ray->body.radius==0.0f && ray->body.radius2==0.0f) {
        func_8023E8D4_de(&ray->plane,&polygon.plane,1);
    } else {
        offset.x=0.0f;
        offset.y=ray->body.radius;
        offset.z=0.0f;
        i=mesh->layers;
        while(--i!=-1) {
            if(i==mesh->layers-1) {
                if(polygon.query.word0==2) goto skipSweep;
                goto sweep;
            } else if(i==0) {
                if(polygon.query.word0==1) goto skipSweep;
                goto sweep;
            } else if((u32)(polygon.query.word0-1)>=2) {
sweep:
                func_8023DF70_de(&ray->sphere,&offset,ray->body.radius,&polygon.sphere,1);
            }
skipSweep:
            offset.y+=mesh->layerStep;
        }
    }
}
