#include "span_1000/code_8023EEF0.h"
#include "common/types_8a8189af7b05.h"
#include "math_helpers.h"
#include "span_1000/code_802412C0.h"
#include "types.h"

/* Computes the signed incline between two horizontal points projected onto a plane. */
extern f32 func_802B72B0_de(f32);

extern f32 D_800C8820;

extern f32 D_800C8828;

static inline f32 height(Plane *p,f32 x,f32 z) {
 Vec3 n=p->normal;
 if(n.y==0) return p->pos.y;
 else {Vec3 v=p->pos; return ((v.z-z)*n.z+(v.x-x)*n.x+v.y*n.y)/n.y;}
}

extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);

extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);

extern void func_8027207C_de(Vec3 *out);

/* Sets up one face of a box as a four-corner quad of kind 4, copying points 0, 1, 2 and 3 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through func_80271F68_de, their cross product through
   func_80272018_de and normalisation through func_8027207C_de. */




extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);

extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

extern void func_8027207C_de(Vec3 *);

/* The edge vectors belong to this helper; declared in the face function itself, GCC 2.8.1 keeps
   the second edge's frame address in a saved register and grows the frame. */
static inline void quad_normal(struct Quad *quad) {
    Vec3 first;
    Vec3 second;

    func_80271F68_de(&first, &quad->corner[1], &quad->corner[0]);
    func_80271F68_de(&second, &quad->corner[2], &quad->corner[1]);
    func_80272018_de(&quad->normal, &second, &first);
    func_8027207C_de(&quad->normal);
}

f32 func_80240A98_de(Plane *p,f32 x0,f32 z0,f32 x1,f32 z1) {
 f32 y0,y1,dx,dz,dy,h,v,r;
 if(!p)return 0;
 y0=height(p,x0,z0);y1=height(p,x1,z1);
 dx=x1-x0;dz=z1-z0;dy=y1-y0;
 h=dx*dx+dz*dz;v=h+dy*dy;
 r=0.0f;
 if(v!=0){r=func_802B72B0_de(h/v);r=func_802745D0_de(RW_MAX_GT(-1.0f,RW_MIN_LT(1.0f,r)));if(!(y0<y1))r=-r;}
 return r;
}

void func_80240C8C_de(void *arg0)
{
    ObjRecAtCC *arg0_record = arg0;
  int new_var;
  f32 new_var2;
  new_var2 = (f32) D_800C373C_de;
  arg0_record->unk0 = 0;
  arg0_record->unk54 = 0;
  new_var = -1;
  arg0_record->unk58 = new_var;
  arg0_record->unkCC = new_var2;
}

void func_80240CAC_de(void *arg0) {
    QueryE0 *object = arg0;
    Vec3 sp10;
    Vec3 sp20;
    Vec3 *temp_s1;
    Vec3 *temp_s0;

    temp_s1 = &object->vectors[1];
    func_80271F68_de(&sp10, temp_s1, &object->vectors[0]);
    func_80271F68_de(&sp20, &object->vectors[2], temp_s1);
    temp_s0 = &object->result;
    func_80272018_de(temp_s0, &sp20, &sp10);
    func_8027207C_de(temp_s0);
}

void func_80240D20_de(struct Quad *quad, Vec3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[0];
    quad->corner[2] = points[1];
    quad->corner[1] = points[2];
    quad->corner[0] = points[3];
    quad_normal(quad);
}
