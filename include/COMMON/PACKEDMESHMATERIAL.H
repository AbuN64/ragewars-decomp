#ifndef COMMON_PACKEDMESHMATERIAL_H
#define COMMON_PACKEDMESHMATERIAL_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
/* Section zero of packed and expanded mesh resources. */
typedef struct PackedMeshMaterial {
    s32 textureId;
    s32 flags;
    u16 renderMode;
    u8 mode;
    u8 reservedB;
    u8 primaryColor[4];
    u8 secondaryColor[4];
    u16 width;
    u16 height;
} PackedMeshMaterial;
typedef struct MeshMaterial {
    s32 flags;
    s16 renderMode;
    u8 mode;
    u8 reserved7;
    s32 texture;
    u8 reservedC[4];
    u8 primaryColor[4];
    u8 secondaryColor[4];
    u16 width;
    u16 height;
} MeshMaterial;

struct Obj_func_80284DC4_de;


struct ParticleEffect;


struct ObjRecAt12;
typedef struct ObjRecAt12 ObjRecAt12;







struct ObjRecAt4V2;
typedef struct ObjRecAt4V2 ObjRecAt4V2;


struct Arg1;
typedef struct Arg1 Arg1;

struct Obj_func_80284DC4_de;

extern float D_800C4EB8_de;








extern float D_800C4EA0_de;




struct ObjRecAt4V2;




struct ObjRecAt12;

struct Arg1;




struct Obj_func_80284DC4_de;
typedef struct Obj_func_80284DC4_de Obj_func_80284DC4_de;



extern float D_800C4E90_de;





extern double D_800C4EB0_de;





#endif
