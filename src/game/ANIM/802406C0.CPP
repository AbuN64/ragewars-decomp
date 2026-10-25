#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "COMMON/BALLISTICPARAMS.H"

/* Computes the signed incline between two horizontal points projected onto a plane. */

static inline f32 height(Plane *p,f32 x,f32 z) {
 CVector3 n=p->normal;
 if(n.y==0) return p->pos.y;
 else {CVector3 v=p->pos; return ((v.z-z)*n.z+(v.x-x)*n.x+v.y*n.y)/n.y;}
}

f32 func_80240A98_de(Plane *p,f32 x0,f32 z0,f32 x1,f32 z1) {
 f32 y0,y1,dx,dz,dy,h,v,r;
 if(!p)return 0;
 y0=height(p,x0,z0);y1=height(p,x1,z1);
 dx=x1-x0;dz=z1-z0;dy=y1-y0;
 h=dx*dx+dz*dz;v=h+dy*dy;
 r=0.0f;
 if(v!=0){r=Math_Sqrtf(h/v);r=Nav_ArcCos(RW_MAX_GT(-1.0f,RW_MIN_LT(1.0f,r)));if(!(y0<y1))r=-r;}
 return r;
}
