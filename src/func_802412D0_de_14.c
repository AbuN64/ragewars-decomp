#include "span_1000/code_802412C0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/gameplay_movement.h"
#include "shared/motion_step.h"
#include "shared/world.h"
#include "span_1000/code_8023D370.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_C76B0/data.h"
#include "types.h"

extern void func_80272018_de(Vec3*,Vec3*,Vec3*);

extern void func_8026F620_de(void *, void *, void *);

extern char *func_8028FDB4_de(s32 *, s32);


extern void *func_8028B2F8_de(void *, u16 *);

extern void func_80240CAC_de(QueryE0 *arg0);

void func_802433DC_de(ContextB0 *mesh,CollisionVertex **points) {
    extern s32 func_8023E8D4_de(CapsuleSweep*,Polygon_func_8023E8D4_de*,s32);
    Vec3 vertex;
    Vec3 edgeA;
    Vec3 edgeB;
    Polygon polygon;
    Vec3 offset;
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

/** Swap two pairs of words. */
void func_80243814_de(Hit8 *arg0, Hit8 *arg1) {
    Hit8 temporary = *arg0;
    *arg0 = *arg1;
    *arg1 = temporary;
}

s32 func_80243850_de(void *arg0, void *arg1) {
    s32 var_v0;
    var_v0 = 1;
    if ((((Hit8 *)arg0)->t) < (((Hit8 *)arg1)->t)) {
        var_v0 = -1;
    }
    return var_v0;
}

void func_80243874_de(void *arg0) {
    void *temp_a1;
    void **temp_s0;
    void *temp_s0_2;
    s32 *temp_v0;
    s32 temp_s1;
    s32 var_s0;

    temp_a1 = ((ContextB0 *)arg0)->element;
    temp_s0 = ((ElementE8 *)temp_a1)->resource;
    if (temp_s0 != 0) {
        func_8026F620_de(&((ContextB0 *)arg0)->transform, &((ElementE8 *)temp_a1)->transform, (char *) arg0 + 0xC);
        temp_s0_2 = *temp_s0;
        ((ContextB0 *)arg0)->vertices = func_8028FDB4_de(temp_s0_2, 0);
        temp_v0 = func_8028FDB4_de(temp_s0_2, 2);
        temp_s1 = *temp_v0;
        var_s0 = 0;
        if (temp_s1 > 0) {
            do {
                func_80242FE8_de(arg0, func_8028FDB4_de((void *) temp_v0, var_s0));
                var_s0 += 1;
            } while (var_s0 < temp_s1);
        }
    }
}

void func_80243920_de(ActorB0 *actor) {
    extern s32 func_8023E8D4_de(ActorB0 *, QueryE0 *, s32);
    QueryE0 query;
    u8 *data;
    s32 *flags;
    void *resource;
    s32 i;
    f32 height;

    data = actor->data;
    flags = actor->flags;
    if (data != 0) {
        resource = func_8028B2F8_de(&D_8011FE88, (u16 *)data);
        if (resource != 0) {
          if ((*flags & 8) != 0) {
           if ((*flags & 0x100000) == 0) {
            query.word14 = 3;
            for (i = 0; i < 3; i++) {
                query.vectors[2 - i].x = ((CollisionBuildTriangle *)data)->fields.v[i]->x;
                query.vectors[2 - i].y = ((CollisionBuildTriangle *)data)->fields.v[i]->ceiling +
                                         actor->height;
                query.vectors[2 - i].z = ((CollisionBuildTriangle *)data)->fields.v[i]->z;
            }
            func_80240CAC_de(&query);
            height = query.result.y;
            if ((0.10000000149011612f) < height) {
                query.word0 = 5;
                query.word4 = ((MotionSurface *)flags)->materialResponse;
                query.word8 = ((MotionSurface *)flags)->materialKind;
                query.input = 0;
                query.index = -1;
                query.word10 = 0;
                if ((((Shared_Surface *)resource)->flags & 0x400000) != 0) {
                    query.wordC = 7;
                } else if ((((Shared_Surface *)resource)->flags52 & 0x80) != 0) {
                    query.wordC = 8;
                } else {
                    query.wordC = 1;
                }
                func_8023E8D4_de(actor, &query, 1);
            }
           }
          }
        }
    }
}
