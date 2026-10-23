#ifndef AUDIO_8025A3EC_H
#define AUDIO_8025A3EC_H
#include "TYPES.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
struct ObjRecAtDC {
    char pad0[0xDC];
    s16 unkDC;
};
struct func_80245A10_S1 {
    char pad0[0x104];
    int unk104;
};
struct ObjRecAt4V6 {
    char pad0[0x4];
    RecordCode8025A3EC unk4;
};
struct RecordRecAt4V3 {
    HeaderRecAt102 *header;
    SlotRecAtA8 slots[17];
};
struct IntegerStateB4 {
    s32 unk_0;
    s32 unk_4;
    unsigned char padding_8[8];
    s32 unk_10;
    unsigned char padding_14[60];
    s32 unk_50;
    unsigned char padding_54[88];
    s32 unk_AC;
    s32 unk_B0;
};
struct ObjRecAtCV4 {
    HeaderRecAt102 *owner;
    char pad4[8];
    SlotCode8025A3EC slots[16];
};
typedef struct SoundEnvelope {
    u16 flags;
    u16 initial;
    u16 target;
    s16 frames;
    u32 reserved8;
} __attribute__((packed)) SoundEnvelope;
struct View_func_8025AE1C_de {
    s32 slot;
    s32 handle;
    s32 field8;
    s32 fieldC;
    s32 frame;
    char pad14[4];
    s32 finished;
    u8 pad1C[0xC];
    s16 priority; /* 0x28 */
    u8 pad2A[2];
    f32 time;
    char pad30[0x38 - 0x30];
    s16 field38;
    s16 field3A;
    char pad3C[0x44 - 0x3C];
    Triple position;
    Triple *tracked;
    u8 pad54[0x88 - 0x54];
    s32 sweeping; /* 0x88 */
    SoundEnvelope envelope; /* 0x8C */
    f32 value; /* 0x98 */
    f32 step; /* 0x9C */
    s32 hold;
    s32 flags;
    s32 trackId;
    s32 done;
    struct ContextCode8025A3EC *context;
    s32 fieldB4;
    char padB8[4];
    s32 followTrack;
    s32 fixed; /* 0xC0 */
};
struct RecordRecAt4V6 {
    struct HeaderRecAt102 *header;
    SlotRecAtB0 slots[17];
};
struct RecordRecAt4V5 {
    HeaderRecAt102 *header;
    SlotRecAtB4V1 slots[17];
};
struct Emitter {
    char pad0[0x34];
    f32 level;
    char pad38[0xC];
    f32 x;
    f32 y;
    f32 z;
    char pad50[8];
    f32 distance;
    f32 lastDistance;
    char pad60[0x48];
    s32 id;
    char padAC[4];
    void *scene;
    char padB4[0xC];
    s32 reset;
};
/* Position and attenuation curve of a spatial sound source. */
typedef struct SoundSpatialSource {
    u8 reserved0[0x34];
    CVector3 position;
    u8 reserved40[4];
    s8 curve;
} SoundSpatialSource;
struct View_func_8025AB94_de {
    s32 slot;
    char pad4[0xC];
    MotionRecAt24 motion;
    char pad38[0x60 - 0x38];
    AnglesRecAt8 angles;
    f32 pitch;
    f32 pitchStep;
    char pad74[0xA4 - 0x74];
    s32 flags;
    char padA8[0xB0 - 0xA8];
    struct ContextRecAt104 *context;
    char padB4[4];
    f32 scale;
};
struct Voice_func_8025A844_de {
    s32 index;
    char pad4[0xC];
    ParamsRecAt18 params;
    char position[0x44];
    s32 sweeping;
    char pad8C[4];
    u16 target;
    char pad92[2];
    s16 delay;
    char pad96[2];
    f32 value;
    f32 step;
    char padA0[4];
    s32 flags;
    char padA8[8];
    struct OwnerCode8025A3EC *owner;
    char padB4[0xC];
    s32 fixed;
};
#endif
