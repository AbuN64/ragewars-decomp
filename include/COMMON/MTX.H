#ifndef COMMON_MTX_H
#define COMMON_MTX_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"

struct Mtx;
struct Mtx {
    CVector3 right;
    f32 m03;
    CVector3 up;
    f32 m13;
    CVector3 forward;
    f32 m23;
    f32 m30;
    f32 m31;
    f32 m32;
    f32 m33;
};

extern float D_800C48E0_de;

extern float D_800C4920_de;

extern float D_800C4930_de;




extern float D_800C48EC_de;



extern float D_800C4910_de;





extern float D_800C48F0_de;




struct Mtx;
typedef struct Mtx Mtx;

extern float D_800C4914_de;
#endif
