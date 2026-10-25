#ifndef ANIM_RAY180_H
#define ANIM_RAY180_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/FIELD_VEC_B0.H"
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
    CVector3 start;
    CVector3 end;
    char pad5C[0x24];
    f32 scale;
    Box box;
    CQuatern rect;
    char padAC[0xD0];
    f32 nearest;
};

struct EntryC;
typedef struct EntryC EntryC;

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
    CQuatern *rect;
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
    CVector3 center;
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

struct ModelF0;
typedef struct ModelF0 ModelF0;

struct Footprint;
struct Footprint {
    char pad0[0x18];
    CVector3 corner[4];
    f32 pad48;
    f32 winding;
};


struct ActorB0;
struct ActorB0 {
    u8 pad0[0x1C];
    f32 height; /* 0x1C */
    u8 pad20[0x20];
    s32 *flags;
    u8 pad44[0x68];
    u8 *data;
};


struct FloatState68_2;
struct FloatState68_2 {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[76];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct QueryRecAt58;
typedef struct QueryRecAt58 QueryRecAt58;

struct IntPair;

struct FloatState68;
struct FloatState68 {
    unsigned char padding_0[92];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct Bounds;
struct Bounds {
    CVector3 corners[8];
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

struct SurfaceHit;
struct SurfaceHit {
    s32 word0;
    s32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    s32 valid; /* 0x14 */
    CVector3 point; /* 0x18 */
    u8 pad24[0x24];
    CVector3 normal; /* 0x48 */
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


struct ContextB0;
struct ContextB0 {
    void *ray; /* Ray shared by collision traversal callbacks. */
    CVector3 *start;
    CVector3 *end;
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
    CVector3 vectors[4];
    CVector3 result;
    void *input;
    s32 index;
    u8 pad5C[0x84];
};

struct Actor_func_80241BAC_de;
struct Actor_func_80241BAC_de {
    u8 pad00[0x3C];
    s32 flags;
    u8 pad40[0x1C];
    CVector3 movement; /* 0x5C */
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

struct FloatState20;
typedef struct FloatState20 FloatState20;

struct Actor_func_80241BAC_de;
typedef struct Actor_func_80241BAC_de Actor_func_80241BAC_de;


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

typedef struct CollisionVertex {
    f32 x, y, z;
    char padC[0xC];
    u32 clipFlags; /* 0x18 */
    s16 *position; /* 0x1C */
} CollisionVertex;


extern void Anim_TraceMeshDisplayList(ContextB0 *context, void *resource);

extern void D_00243814();
extern void D_00243850();
extern void func_8026F368_de(MatrixF *, CVector3 *, CVector3 *, CVector3 *);
#endif
