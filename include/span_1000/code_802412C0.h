#ifndef UNBAKE_SPAN_1000_CODE_802412C0_H
#define UNBAKE_SPAN_1000_CODE_802412C0_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
#include "span_1000/code_80213ED4.h"
struct Ray180;
struct MotionSurface;
struct Ray180 {
    char pad0[0x8];
    f32 spacing;
    f32 secondaryRadius;
    f32 length;
    char pad14[0x4];
    f32 radius;
    f32 height; /* 0x1C */
    char pad20[0x1C];
    u32 flags; /* 0x3C */
    struct MotionSurface *surface; /* 0x40 */
    Vec3 start;
    Vec3 end;
    char pad5C[0x24];
    f32 scale;
    Box box;
    Vector4f rect;
    char padAC[0xD0];
    f32 nearest;
};

struct EntryC;
typedef struct EntryC EntryC;

struct func_80243864_S2;
struct func_80243864_S2 {
    char pad0[0x68];
    char unk68;
    char pad68[0xB4 - 0x68 - sizeof(char)];
    void ** unkB4;
};

struct func_80241940_S1;
typedef struct func_80241940_S1 func_80241940_S1;

struct ElementE8;
struct ElementE8 {
    char pad0[0x68];
    MatrixF transform; /* 0x68 */
    u8 padA8[0xC];
    void **resource; /* 0xB4 */
    Box box;
    char padD0[0x8];
    u16 flags;
    char padDA[0xE];
};

struct ElementE8;
typedef struct ElementE8 ElementE8;

struct Hit8;
struct Hit8 {
    ElementE8 *element;
    f32 t;
};

struct ObjectState7;
typedef struct ObjectState7 ObjectState7;

extern float D_800C3744_de;

struct EntryBlock;
typedef struct EntryBlock EntryBlock;

struct ActorRecAtB0;
typedef struct ActorRecAtB0 ActorRecAtB0;

struct OwnerRecAt18;
typedef struct OwnerRecAt18 OwnerRecAt18;

struct OwnerRecAt18;
struct OwnerRecAt18 {
    u8 pad0[0x18];
    u8 *entries;
};

struct Actor_func_80242288_de;
struct Actor_func_80242288_de {
    OwnerRecAt18 *owner;
    u8 pad04[8];
    f32 fieldC;
    u8 pad10[0x30];
    void *field40;
    u8 pad44[0x18];
    f32 field5C;
    f32 field60;
    f32 field64;
};

struct Input_func_802426CC_de;
typedef struct Input_func_802426CC_de Input_func_802426CC_de;

struct ContextB0;
typedef struct ContextB0 ContextB0;

struct FloatState68;
typedef struct FloatState68 FloatState68;


struct Ray180;
typedef struct Ray180 Ray180;

struct SurfaceHit;
typedef struct SurfaceHit SurfaceHit;

struct EntryC;
struct EntryC {
    void **resource;
    Vector4f *rect;
    s32 unk_8;
};

struct ShapeRecAt18V1;
struct ShapeRecAt18V1 {
    s32 flags;
    u16 kind;
    f32 radius;
    f32 halfWidth;
    f32 height;
    f32 halfDepth;
    Vec3 center;
};

struct QueryRecAt58;
struct QueryRecAt58 {
    s32 word0;
    s32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    u8 pad14[0x40];
    OwnerRecAt18 *owner;
    s32 index;
    u8 pad5C[0x84];
};

struct Actor_func_80242288_de;
typedef struct Actor_func_80242288_de Actor_func_80242288_de;

struct Footprint;
typedef struct Footprint Footprint;

extern float D_800C3740_de;

struct FloatState20;
struct FloatState20 {
    unsigned char padding_0[28];
    f32 unk_1C;
};

struct func_802414E4_S1;
typedef struct func_802414E4_S1 func_802414E4_S1;

struct ModelF0;
typedef struct ModelF0 ModelF0;

struct Footprint;
struct Footprint {
    char pad0[0x18];
    Vec3 corner[4];
    f32 pad48;
    f32 winding;
};

struct func_80241940_S2;
typedef struct func_80241940_S2 func_80241940_S2;

struct func_80241940_S2;
struct func_80241940_S2 {
    char pad0[0x134];
    s32 unk134;
};

struct func_80243864_S2;
typedef struct func_80243864_S2 func_80243864_S2;


struct ActorB0;
struct ActorB0 {
    u8 pad0[0x1C];
    f32 height; /* 0x1C */
    u8 pad20[0x20];
    s32 *flags;
    u8 pad44[0x68];
    u8 *data;
};

extern f32 func_802417C4_de(f32 *arg0);

struct FloatState68_2;
struct FloatState68_2 {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[76];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct func_80241940_S1;
struct func_80241940_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x18 - 0x10 - sizeof(s32)];
    char * unk18;
    char pad18[0x5C - 0x18 - sizeof(char*)];
    Vector4f unk5C;
    char pad5C[0x6C - 0x5C - sizeof(Vector4f)];
    f32 unk6C;
};

struct QueryRecAt58;
typedef struct QueryRecAt58 QueryRecAt58;

struct IntPair;
extern void func_80243814_de(struct Hit8 *arg0, struct Hit8 *arg1);

struct FloatState68;
struct FloatState68 {
    unsigned char padding_0[92];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct Bounds;
struct Bounds {
    Vec3 corners[8];
};

struct EntryRecAt8V5;
struct EntryRecAt8V5 {
    u8 pad0[4];
    u16 kind;
    u8 pad6[2];
    f32 value;
};

struct EntryRecAt8V5;
typedef struct EntryRecAt8V5 EntryRecAt8V5;

struct EntryBlock;
struct EntryBlock {
    u8 pad[0x14];
    EntryRecAt8V5 entry;
};

struct func_80241718_S1;
struct func_80241718_S1 {
    char pad0[0x1C];
    f32 unk1C;
    char pad1C[0x48 - 0x1C - sizeof(f32)];
    Vec3 unk48;
};

struct SurfaceHit;
struct SurfaceHit {
    s32 word0;
    s32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    s32 valid; /* 0x14 */
    Vec3 point; /* 0x18 */
    u8 pad24[0x24];
    Vec3 normal; /* 0x48 */
    void *input;
    s32 index;
    u8 pad5C[0x80];
};

struct ActorRecAtB0;
struct ActorRecAtB0 {
    u8 pad00[0x3C];
    s32 flags;
    u8 pad40[0x70];
    SurfaceHit saved_query;
};

struct ObjRecAt34;
typedef struct ObjRecAt34 ObjRecAt34;

struct EntryRecAt4V3;
struct EntryRecAt4V3 {
    u8 pad0[4];
    u16 kind;
};

struct QueryE0;
typedef struct QueryE0 QueryE0;

struct ActorB0;
typedef struct ActorB0 ActorB0;

extern void func_802428D0_de(void *first, void *second);

struct ContextB0;
struct ContextB0 {
    void *ray; /* Ray shared by collision traversal callbacks. */
    Vec3 *start;
    Vec3 *end;
    MatrixF matrix;
    f32 reach;
    s32 segments;
    f32 step;
    ElementE8 *element;
    s32 kind;
    u32 flags; /* 0x60 */
    MatrixF transform; /* 0x64 */
    void *vertices; /* 0xA4 */
    s32 isKind9;
    char padAC[0x4];
};

struct FloatState68_2;
typedef struct FloatState68_2 FloatState68_2;

struct func_802414E4_S1;
struct func_802414E4_S1 {
    char pad0[0x18];
    char unk18;
    char pad18[0x48 - 0x18 - sizeof(char)];
    char unk48;
};

extern void func_802428EC_de(void *arg0, void *arg1);

struct CollisionProbe;
struct OwnerRecAt18;
struct CollisionProbe {
    u8 kind;
    u8 pad01[7];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0xC];
    f32 floor;
    u8 pad24[0x10];
    struct OwnerRecAt18 *owner;
    s32 flags38;
    u8 pad3C[0xC4];
    s32 flags100;
};

struct func_80241940_S3;
struct func_80241940_S3 {
    char pad0[0x10];
    f32 unk10;
    char pad10[0x54 - 0x10 - sizeof(f32)];
    f32 unk54;
};

struct func_80243864_S1;
typedef struct func_80243864_S1 func_80243864_S1;

struct ObjectState7;
struct ObjectState7 {
    char pad0[0x6];
    s8 unk_6;
};

struct EntryRecAt4V3;
typedef struct EntryRecAt4V3 EntryRecAt4V3;

extern float D_800C3760_de;

struct QueryE0;
struct QueryE0 {
    s32 word0;
    f32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    s32 word14;
    Vec3 vectors[4];
    Vec3 result;
    void *input;
    s32 index;
    u8 pad5C[0x84];
};

struct Actor_func_80241BAC_de;
struct Actor_func_80241BAC_de {
    u8 pad00[0x3C];
    s32 flags;
    u8 pad40[0x1C];
    Vec3 movement; /* 0x5C */
    u8 pad68[0x48];
    SurfaceHit saved_query;
};

struct ObjRecAt34;
struct ObjRecAt34 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x34 - 0x4 - sizeof(s32)];
    f32 unk34;
};

struct Actor_func_80242550_de;
struct Actor_func_80242550_de {
    OwnerRecAt18 *owner;
    u8 pad04[0x3C];
    s32 *flags;
    Triple previous;
    Triple position;
    Triple delta;
};

struct Actor_func_80242550_de;
typedef struct Actor_func_80242550_de Actor_func_80242550_de;

struct CollisionProbe;
typedef struct CollisionProbe CollisionProbe;

struct Input_func_802426CC_de;
struct Input_func_802426CC_de {
    u8 kind;
    u8 pad01[7];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0xC];
    f32 floor;
    u8 pad24[0x10];
    void *owner;
    s32 flags38;
    u8 pad3C[0xC4];
    s32 flags100;
};

struct func_80241940_S3;
typedef struct func_80241940_S3 func_80241940_S3;

struct FloatState20;
typedef struct FloatState20 FloatState20;

struct Actor_func_80241BAC_de;
typedef struct Actor_func_80241BAC_de Actor_func_80241BAC_de;

struct func_80243864_S1;
struct func_80243864_S1 {
    char pad0[0x58];
    void * unk58;
    char pad58[0x64 - 0x58 - sizeof(void*)];
    char unk64;
    char pad64[0xA4 - 0x64 - sizeof(char)];
    void * unkA4;
};

extern s32 func_80243850_de(void *arg0, void *arg1);

struct Bounds;
typedef struct Bounds Bounds;

struct ShapeRecAt18V1;
typedef struct ShapeRecAt18V1 ShapeRecAt18V1;

struct ModelF0;
struct ModelF0 {
    s32 unk_0;
    s32 count;
    ElementE8 elements[1];
};

struct Hit8;
typedef struct Hit8 Hit8;

struct func_80241718_S1;
typedef struct func_80241718_S1 func_80241718_S1;

struct func_802428DC_S2;
typedef struct func_802428DC_S2 func_802428DC_S2;

struct func_802428DC_S2;
struct func_802428DC_S2 {
    char pad0[0x3C];
    int unk3C;
    char pad3C[0x5C - 0x3C - sizeof(int)];
    Vec3 unk5C;
};

typedef struct CollisionVertex {
    f32 x, y;
    char pad8[0x14];
    s16 *position; /* 0x1C */
} CollisionVertex;

extern s32 func_8023DF70_de(CapsuleSweep*,Vec3*,f32,Polygon*,s32);

#endif
