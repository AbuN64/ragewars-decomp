#ifndef COMMON_PACKED_H
#define COMMON_PACKED_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Packed;
struct Packed {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short first[3];
    unsigned short second[3];
    int unk10;
};

struct Packed;
typedef struct Packed Packed;
/* Cached path-node plane normals (Particle_CrossVectors edge cross products). */
extern CVector3 D_80115E10;
extern CVector3 D_80115E20;

struct CGameRegion_t;
struct CGameRegion_t {
    short unk0;
    short unk2;
    void *first[3];
    void *second[3];
    int unk1C;
};

struct CGameRegion_t;
typedef struct CGameRegion_t CGameRegion;
/* Cached path-node plane normal (Particle_CrossVectors edge cross product). */
extern CVector3 D_80111D30;

extern void Nav_DecodePackedRegion(CGameRegion *dst, Packed *src, char *base, int unused, char *extra);

extern float D_800C4980_de;

extern void func_802744B4_de(void);

extern float D_800C9AD8;

extern void func_802744AC_de(void);




extern void Nav_ScaleWordsToFloats(void *arg0);

extern float D_800C4978_de;

extern s32 func_8027451C_de();

extern float D_800C49C0_de;

struct ObjRecAt2CV1;
struct ObjRecAt2CV1 {
    char pad0[0x18];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
};

extern float D_800C9A38;

extern float D_800C49EC_de;

extern void func_80274DFC_de(float mf[4][4], float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);

extern float D_800C49C4_de;

extern f32 func_802749B4_de(f32 arg0, f32 arg1);

struct Triangle;
struct Triangle {
    char pad0[2];
    u16 flags;
    CVector3 *vertices[3];
};

extern s32 func_80274D8C_de(void *arg0, void *arg1);


struct Triangle;
typedef struct Triangle Triangle;

extern void func_80274C7C_de(void *arg0);


struct ObjRecAt2CV1;
typedef struct ObjRecAt2CV1 ObjRecAt2CV1;

extern void func_80274BF4_de(void *arg0);

extern float D_800C49C8_de;

extern float D_800C4998_de;


extern double D_800C4940_de;

extern void func_80274B7C_de(void *arg0, void *arg1, void *arg2);

extern s32 func_802748F4_de(s32 arg0, s32 arg1, s32 arg2);

extern float D_800C499C_de;

extern float D_800C4990_de;

extern float D_800C49E0_de;

extern f32 func_80274944_de(f32 arg0);

extern float D_800C4988_de;

extern s32 func_80274D10_de(f32 *arg0, f32 *arg1, f32 *arg2);

/* Edge endpoints and the direction/normal derived by the edge helpers. */
typedef struct GeometryEdge {
    CVector3 start;
    CVector3 end;
    CVector3 direction;
    CVector3 unitDirection;
    CVector3 normal;
} GeometryEdge;
#endif
