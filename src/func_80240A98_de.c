#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023EEF0.h"
#include "types.h"
#include "math_helpers.h"
/* Computes the signed incline between two horizontal points projected onto a plane. */
extern f32 func_802B72B0_de(f32);
extern f32 D_800C8820;
extern f32 D_800C8828;
static inline f32 height(Plane *p,f32 x,f32 z) {
 Vec3 n=p->normal;
 if(n.y==0) return p->pos.y;
 else {Vec3 v=p->pos; return ((v.z-z)*n.z+(v.x-x)*n.x+v.y*n.y)/n.y;}
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
