#include "common/unused.h"
#include "span_1000/code_8027A0F4.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028469C.h"
#include "types.h"

extern func_80284AF4_G2 D_80145060;

extern f32 func_8024D284_de(void *arg0);
extern f32 func_802726BC_de(f32 *arg0, f32 *arg1);
extern void func_80282E98_de(void *arg0, void *arg1);








void func_80284B20_de(void *arg0) {
    Vec3 point;
    void *node;
    void *point_ptr;
    int actor_id;
    s16 amount;
    int stop;
    f32 radius_sq;
    f32 height_scale;

    amount = ((Shared_Particle *)arg0)->desc->unk10;
    radius_sq = (f32)amount;
    if (radius_sq <= 0.0f) {
        return;
    }
    radius_sq *= D_800C4E90_de;
    node = D_80145060.unk0;
    radius_sq *= radius_sq;
    if (node == 0) {
        return;
    }

    point_ptr = &point;
    actor_id = 0x40F;
    height_scale = (&D_800C4E90_de)[1];
    do {
        point = ((Shared_ActorView *)node)->position.vector;
        stop = 0;
        if (((Shared_Particle *)arg0)->inst.type != actor_id) {
            point.y += func_8024D284_de(node) * height_scale;
        }
        if (func_802726BC_de(&((Shared_Particle *)arg0)->inst.pos.x, point_ptr) < radius_sq) {
            func_80282E98_de(arg0, node);
            if (((Shared_Particle *)arg0)->inst.type == actor_id) {
                stop = 1;
            }
        }
        if (stop != 0) {
            node = 0;
        } else {
            node = ((Shared_ActorView *)node)->next;
        }
    } while (node != 0);
}

typedef struct CollisionInfo CollisionInfo;









extern CollisionInfo D_80100030;
extern Instance8020CD74 *func_802392EC_de(Arg1 *arg0);
extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, CollisionInfo *);

s32 func_80284C48_de(Instance8020CD74 *arg0, Arg1 *arg1) {
    Instance8020CD74 saved;
    Instance8020CD74 *instance;
    s32 collisions;

    instance = func_802392EC_de(arg1);
    if (instance != 0 && arg1->field24 == 0) {
        saved = *instance;
        instance->position = arg1->position128;
        collisions = func_80243A90_de(instance, arg0->position, &D_80100030);
        *instance = saved;
    } else {
        saved = *arg0;
        saved.position = arg1->position128;
        collisions = func_80243A90_de(&saved, arg0->position, &D_80100030);
    }
    return collisions == 0;
}

/* Marks nearby objects other than type 87 as active. */

extern void func_80271F68_de(f32 *, f32 *, f32 *);
void func_80284DC4_de(s32 unused, Obj_func_80284DC4_de *center, Obj_func_80284DC4_de **objects, s32 count) {
 f32 d[3]; s32 i; Obj_func_80284DC4_de *o;
 for(i=0;i<count;i++) {
  o=objects[i];
  if(o->unk4 != 0x57) {
   func_80271F68_de(d,o->pos,center->pos);
   if(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]<=65536.0f) o->unk14C=1;
  }
 }
}

/* Checks object proximity through type-specific handlers and marks nearby objects active. */

extern void func_80271F68_de(f32 *, f32 *, f32 *);
static inline void nearby(s32 unused, Obj_func_80284DC4_de *center, Obj_func_80284DC4_de **objects, s32 count) {
 f32 d[3]; s32 i; Obj_func_80284DC4_de *o;
 for(i=0;i<count;i++) {
  o=objects[i];
  if(o->unk4 != 0x57) {
   func_80271F68_de(d,o->pos,center->pos);
   if(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]<=65536.0f) o->unk14C=1;
  }
 }
}
extern void func_80281A9C_de(int,Obj_func_80284DC4_de *,Obj_func_80284DC4_de **,int);
void func_80284E9C_de(int context,Obj_func_80284DC4_de **objects,int count) {
 int i; Obj_func_80284DC4_de *obj;
 for(i=0;i<count;i++) {
  obj=objects[i];
  switch(obj->unk4) {
   case 0xC: break;
   case 0x22: func_80281A9C_de(context,obj,objects,count); break;
   case 0x57: nearby(context,obj,objects,count); break;
  }
 }
}

void func_80284FF4_de(void *arg0, s32 arg1, void *arg2) {
    f32 temp_f2;
    s32 count;
    u16 v;
    s8 *record;

    ((Vec3 *)arg2)->x = 0.0f;
    ((Vec3 *)arg2)->y = 0.0f;
    ((Vec3 *)arg2)->z = 0.0f;
    record = ((EffectSystem *)arg0)->lists[1].head;
    count = 0;
    if (record != 0) {
        do {
            v = ((Effect_func_802800C0_de *)record)->kind;
            if (((v == 0x41E) || (v == 0x3EF)) &&
                (((Effect_func_802800C0_de *)record)->owner == arg1) &&
                (((Effect_func_802800C0_de *)record)->flags & 0x100)) {
                ((Vec3 *)arg2)->x += ((Effect_func_802800C0_de *)record)->pos.x;
                ((Vec3 *)arg2)->y += ((Effect_func_802800C0_de *)record)->pos.y;
                count += 1;
                ((Vec3 *)arg2)->z += ((Effect_func_802800C0_de *)record)->pos.z;
            }
            record = ((Effect_func_802800C0_de *)record)->next;
        } while (record != 0);
    }
    if (count != 0) {
        temp_f2 = (f32)count;
        ((Vec3 *)arg2)->x = (f32)(((Vec3 *)arg2)->x / temp_f2);
        ((Vec3 *)arg2)->y = (f32)(((Vec3 *)arg2)->y / temp_f2);
        ((Vec3 *)arg2)->z = (f32)(((Vec3 *)arg2)->z / temp_f2);
    }
}

extern f32 func_802726BC_de(f32 *a, f32 *b);









void func_802850C8_de(void *arg0, void *arg1, f32 *arg2) {
    f32 temp;
    void *node;

    *arg2 = D_800C4EA0_de;
    node = ((EffectSystem *)arg0)->groups.head;
    if (node != 0) {
        do {
            if (((Effect_func_802800C0_de *)node)->owner != arg1 && (((Effect_func_802800C0_de *)node)->flags & 0x100)) {
                temp = func_802726BC_de(&((Effect_func_802800C0_de *)node)->pos.x, &((Actor_func_8024A7A0_de *)arg1)->position0.x);
                if (temp < *arg2) {
                    *arg2 = temp;
                }
            }
            node = ((Effect_func_802800C0_de *)node)->groupNext;
        } while (node != 0);
    }
}
