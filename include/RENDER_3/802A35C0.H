#ifndef RENDER_3_802A35C0_H
#define RENDER_3_802A35C0_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/SHAREDPLAYER.H"
struct AnimationFrameDefinition {
    u8 definition_prefix[0x1E];
    u8 mode;
};
struct AnimationFrameState {
    u8 node_prefix[0x2C];
    f32 endpoint;
    f32 frame;
    u8 state_between_frame_and_cache[4];
    s32 cached_frame;
};
struct ObjectState68 {
    unsigned char padding_0[40];
    UnitMtx unk_28;
};
struct Owner802A697C {
    u8 pad0[0x7528];
    struct State802A697C *head;
};
struct FloatState50 {
    unsigned char padding_0[76];
    f32 unk_4C;
};
struct Root752C {
    char pad[0x7528];
    Node44 *unk_7528;
};
struct FloatStateB0 {
    unsigned char padding_0[172];
    f32 unk_AC;
};
struct func_802A68A0_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x1C - 0x4 - sizeof(void*)];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    f32 unk24;
};
struct func_802A6A54_S3 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
};
struct RibbonActor {
    char pad0[4];
    struct RibbonActor *next; /* 0x4 */
    struct CROMSwoosh_t *track;
    struct Key *first;
    struct Key *second;
    s32 model;
    char pad18[0x24 - 0x18];
    f32 time;
    f32 phase;
    char pad2C[0x34 - 0x2C];
    s32 layer; /* 0x34: negative layers draw first, positive second */
    char pad38[0x3C - 0x38];
    u32 flags;
    ObjRecAt28V1 *tail;
    ObjRecAt28V1 *clock;
    s32 pointCount; /* 0x48: drawn once it has two points */
    f32 length;
};
struct Morph {
    s32 count;
    struct Blend *blends;
    struct Key *first;
    struct Key *second;
    union { f32 firstFrame; f32 scaleS; };
    union { f32 secondFrame; f32 scaleT; };
    f32 textureScaleS;
    f32 textureScaleT;
    f32 step;
};
struct func_802A6A54_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
};
/* Double-buffered vertex storage shared by the ribbon allocator and reset. */
struct RibbonVertexPool {
    s32 state;
    s32 reserved4;
    Vtx vertices[2][300]; /* 0x08, 4800 bytes per buffer */
    s32 remaining; /* 0x2588 */
    Vtx *next; /* 0x258C */
};
struct IntegerState6A94 {
    unsigned char padding_0[27280];
    s32 unk_6A90;
};
struct Animator {
    s32 unk0;
    s32 mode;
    f32 time;
    f32 *loop;
    f32 *script;
    f32 value;
    f32 valueFrom;
    f32 valueTo;
    f32 valueDuration;
    f32 alpha;
    f32 alphaFrom;
    f32 alphaTo;
    f32 colourDuration;
    f32 rgb[3];
    char pad40[4];
    f32 rgbFrom[3];
    char pad50[4];
    f32 rgbTo[3];
};
#endif
