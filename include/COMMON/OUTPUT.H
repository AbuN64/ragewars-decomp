#ifndef COMMON_OUTPUT_H
#define COMMON_OUTPUT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Output;
typedef struct Output Output;

struct World;

struct Ray;
typedef struct Ray Ray;

struct Polygon_func_8023E178_de;
struct Polygon_func_8023E178_de {
    s32 type;
    s32 pad4;
    s32 kind;
    char padC[0x8];
    s32 flag;
    CVector3 point;
    char pad24[0x24];
    CVector3 normal;
    char pad54[0x78];
    f32 t;
    CVector3 hit;
};

struct Polygon;
typedef struct Polygon Polygon;

struct Ray;
struct Ray {
    char pad0[0x44];
    CVector3 start;
    CVector3 end;
    CVector3 dir;
    char pad68[0x114];
    f32 nearest;
};

extern float D_800C87C0;




struct Polygon;
struct Polygon {
    s32 type;
    f32 response; /* 0x04 */
    s32 kind;
    s32 category; /* 0x0C */
    u32 flags; /* 0x10 */
    s32 vertexCount; /* 0x14 */
    CVector3 vertices[4]; /* 0x18 */
    CVector3 normal; /* 0x48 */
    void *input; /* 0x54 */
    s32 index; /* 0x58 */
    char pad5C[0x70];
    f32 t; /* 0xCC */
    CVector3 hit;
};


struct ActorMotion;
struct MotionContactResult;


struct ObjRecAt18C;
struct ObjRecAt18C {
    char pad0[0x18C];
    Triple unk18C;
};


struct ObjRecAt18C;
typedef struct ObjRecAt18C ObjRecAt18C;

struct Polygon_func_8023E178_de;
typedef struct Polygon_func_8023E178_de Polygon_func_8023E178_de;

struct Ray_func_8023E178_de;
struct Ray_func_8023E178_de {
    char pad0[0x44];
    CVector3 start;
    CVector3 end;
    CVector3 dir;
    char pad68[0x18];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E178_de nearest;
};


struct Polygon;
typedef struct Polygon Polygon_func_8023E8D4_de;

struct CapsuleSweep;
struct MotionSurface;
struct CapsuleSweep {
    char pad0[0x08];
    f32 radius; /* 0x08 */
    f32 secondaryRadius; /* 0x0C */
    char pad10[0x0C];
    f32 height; /* 0x1C */
    char pad20[0x1C];
    u32 flags; /* 0x3C */
    struct MotionSurface *surface; /* 0x40 */
    CVector3 start;
    CVector3 end;
    char pad5C[0x24];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E8D4_de nearest;
};

struct Instance;
struct Instance {
    u8 pad0[0x14];
    s32 field14;
};
struct Input;
struct Instance;
struct Input {
    u8 pad0[0xB0];
    s32 type;
    u8 padB4[8];
    s32 fieldBC;
    s32 fieldC0;
    u8 padC4[0x34];
    Triple vecF8;
    struct Instance *instance104;
    s32 field108;
    Block70 block10C;
    s32 field17C;
    Triple vec180;
    CVector3 contactNormal; /* 0x18C */
};

struct CapsuleSweep;
typedef struct CapsuleSweep CapsuleSweep;


struct World;

extern float D_800D0648;

extern float D_800C36D8_de;


struct Polygon;


struct CapsuleSweep;


struct Range;
struct Range {
    char pad[8];
    f32 low;
    s32 count;
    f32 high;
    f32 extra;
    f32 limit;
};






struct Instance;
struct Output;
struct Output {
    struct Instance *instance0;
    s32 instanceValue4;
    Triple vec8;
    s32 field14;
    Block70 block18;
    struct Instance *instance88;
    s32 instanceValue8C;
    Triple vec90;
    u8 pad9C[0x28];
    s32 fieldC4;
    Triple vecC8;
    s32 fieldD4;
    u8 padD8[0xC];
    Triple vecE4;
    Triple vecF0;
    s32 typeFC;
    s32 field100;
};

struct Ray_func_8023E178_de;
typedef struct Ray_func_8023E178_de Ray_func_8023E178_de;


struct ObjRecAt48;
typedef struct ObjRecAt48 ObjRecAt48;

struct Reusable;
typedef struct Reusable Reusable;

struct ObjRecAt48;
struct ObjRecAt48 {
    char pad0[0x48];
    Triple unk48;
};

struct SegmentCode8023A284;
typedef struct SegmentCode8023A284 SegmentCode8023A284;


struct SegmentCode8023A284;
struct SegmentCode8023A284 {
    char pad0[0x40];
    Field_f32_10 *limits;
    f32 x0;
    char pad48[4];
    f32 y0;
    f32 x1;
    f32 height;
    f32 y1;
    char pad5C[0x74 - 0x5C];
    char node[1];
};

struct Input;
typedef struct Input Input;

extern float D_800C87B4;



struct Reusable;


struct CapsuleSweep;

extern f32 D_800C3670_de;
extern f32 D_800C3674_de;
extern f32 D_800C3678_de;
extern f32 D_800C367C_de;
extern f32 D_800C3680_de;
extern f32 D_800C3684_de;
extern f32 D_800C3688_de;
extern f32 D_800C368C_de;
extern CVector3 func_802723FC_de(CVector3 *,CVector3 *);
#endif
