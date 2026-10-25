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
/* Cached path-node plane normals (func_80272018_de edge cross products). */
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
/* Cached path-node plane normal (func_80272018_de edge cross product). */
extern CVector3 D_80111D30;

extern void func_80275AA4_de(CGameRegion *dst, Packed *src, char *base, int unused, char *extra);

extern float D_800C4980_de;

extern void func_802744B4_de(void);

extern float D_800C9AD8;

extern void func_802744AC_de(void);

struct func_80274BEC_S2;
typedef struct func_80274BEC_S2 func_80274BEC_S2;

struct func_80274DFC_S1;
struct func_80274DFC_S1 {
    f32 unk0;
    char pad0[0x8 - 0x0 - sizeof(f32)];
    f32 unk8;
    char pad8[0x30 - 0x8 - sizeof(f32)];
    CVector3 unk30;
};

struct func_80274BEC_S2;
struct func_80274BEC_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x30 - 0x20 - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    f32 unk38;
};

extern void func_80275A58_de(void *arg0);

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

struct func_80274DFC_S1;
typedef struct func_80274DFC_S1 func_80274DFC_S1;

struct Triangle;
typedef struct Triangle Triangle;

extern void func_80274C7C_de(void *arg0);

struct func_80274BEC_S1;
typedef struct func_80274BEC_S1 func_80274BEC_S1;

struct ObjRecAt2CV1;
typedef struct ObjRecAt2CV1 ObjRecAt2CV1;

extern void func_80274BF4_de(void *arg0);

extern float D_800C49C8_de;

extern float D_800C4998_de;

struct func_80274BEC_S1;
struct func_80274BEC_S1 {
    func_8022E280_S1_U744 unk0;
    char pad0[0x4 - 0x0 - sizeof(func_8022E280_S1_U744)];
    func_8022E280_S1_U744 unk4;
    char pad4[0x8 - 0x4 - sizeof(func_8022E280_S1_U744)];
    func_8022E280_S1_U744 unk8;
};

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
