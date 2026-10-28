#ifndef COMMON_OBJRECAT4V6_H
#define COMMON_OBJRECAT4V6_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern f32 D_800C9068;

extern float D_800D0D10;

struct RecordCode8025A3EC;
typedef struct RecordCode8025A3EC RecordCode8025A3EC;

struct RecordCode8025A3EC;
struct RecordCode8025A3EC {
    s32 index;
    char pad04[4];
    s32 f08;
    s32 f0C;
    char pad10[4];
    s32 f14;
    char pad18[0x14];
    f32 f2C;
    char pad30[4];
    f32 f34;
    s16 f38;
    s16 f3A;
    char pad3C[4];
    s32 f40;
    CVector3 position; /* +0x44, Channel_InitializeVoiceMix */
    u8 reserved50[8];
    s32 f58;
    s32 f5C;
    u8 reserved60[0x14];
    s16 envelope[4]; /* +0x74 */
    u8 reserved7C[4];
    f32 envelopeValue, envelopeStep; /* +0x80, +0x84 */
    u8 reserved88[0x1C];
    s32 fA4;
    s32 soundId; /* +0xA8 */
    s32 fAC;
    struct ContextRecAt2BC0 *owner; /* probe 20261019T012703451174Z */
    s32 fB4;
    f32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    f32 fC8; /* per-slot volume scale, 0xC8 */
};

struct ObjRecAt4V6;


struct SlotRecAtB0;
typedef struct SlotRecAtB0 SlotRecAtB0;



struct SlotRecAtA8;
struct SlotRecAtA8 {
    char pad0[8];
    s32 used;
    char pad[0x9C];
    s32 value;
    char pad2[0x20];
};

struct HeaderRecAt102;
typedef struct HeaderRecAt102 HeaderRecAt102;

struct SlotRecAtA8;
typedef struct SlotRecAtA8 SlotRecAtA8;

struct HeaderRecAt102;
struct HeaderRecAt102 {
    char pad[0x102];
    s16 local;
};

struct RecordRecAt4V3;


struct ObjRecAt4V6;
typedef struct ObjRecAt4V6 ObjRecAt4V6;

struct OwnerCode8025A3EC8025B5F0;
typedef struct OwnerCode8025A3EC8025B5F0 OwnerCode8025A3EC8025B5F0;



struct OwnerCode8025A3EC8025B5F0;
struct OwnerCode8025A3EC8025B5F0 {
    char pad[0x84];
    char sound[0x58];
    s16 samples[20];
    char pad2[(0x104 - 0xDC) - 40];
    s32 key;
};

struct OwnerCode8025A3EC8025B5F0;
struct SlotRecAtB0;
struct SlotRecAtB0 {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 value;
    s32 active;
    struct OwnerCode8025A3EC8025B5F0 *owner;
    char pad3[0x18];
};

extern int D_800CBB00;

struct IntegerStateB4;

struct SlotRecAtB8;
struct SlotRecAtB8 {
    char pad0[0xA8];
    s32 flags;
    char padaC[8];
    char *owner;
    char end[0x14];
};

struct SlotRecAtB4V1;
typedef struct SlotRecAtB4V1 SlotRecAtB4V1;


struct SlotCode8025A3EC;
struct SlotCode8025A3EC {
    int id;
    char pad4[0x9C];
    int keyA;
    char padA4[8];
    int keyB;
    char padB0[0x1C];
};

struct SlotCode8025A3EC;
typedef struct SlotCode8025A3EC SlotCode8025A3EC;

struct ObjRecAtCV4;


extern float D_800C9044;

struct RecordRecAt4V3;
typedef struct RecordRecAt4V3 RecordRecAt4V3;




struct Slots;
struct Slots {
    char pad0[0x60];
    s16 ids[16];
};


struct SlotRecAtB4V1;
struct SlotRecAtB4V1 {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 other;
    s32 active;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 value;
    char pad3[0x14];
};

extern float D_800C3F68_de;

struct Slots;
typedef struct Slots Slots;

/* A voice waiting in the context queue; the queue head is a sentinel node inside the context. */
typedef struct VoiceQueueNode {
    struct VoiceQueueNode *prev;
    struct VoiceQueueNode *next;
    char pad8[0x38];
    s16 priority;
} VoiceQueueNode;

struct ContextCode8025A3EC;
struct ContextCode8025A3EC {
    char pad0[0x7C];
    Slots slots;
    char padFC[0x104 - 0xFC];
    s32 frame;
    char pad108[0x134 - 0x108];
    s32 track;
    char pad138[0x13C - 0x138];
    VoiceQueueNode queue; /* 0x13C: sentinel of the queue of voices waiting for a slot */
    char pad180[0x2B98 - 0x180];
    s32 result;
};

struct ContextCode8025A3EC;
struct ViewChannelUpdateVoicePlayback;



extern float D_800C3F80_de;

struct SlotRecAtB4V2;
struct SlotRecAtB4V2 {
    s32 index;
    s32 state;
    s32 used;
    s32 fieldC;
    s32 key;
    char pad14[0x24];
    s16 priority;
    s16 channel;
    char pad3C[0x14];
    s32 flag;
    char pad2[0x50];
    s32 mask;
    s32 value;
    s32 active;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 fieldB4;
    char padB8[0x14];
};

extern float D_800C3F88_de;


struct SlotRecAtB4V2;
typedef struct SlotRecAtB4V2 SlotRecAtB4V2;

struct RecordRecAt4V4;
struct RecordRecAt4V4 {
    HeaderRecAt102 *header;
    SlotRecAtB4V2 slots[17];
};


struct SlotRecAtB8;
typedef struct SlotRecAtB8 SlotRecAtB8;

extern void Audio_PlayVoiceSound(SlotRecAtB8 *base, s16 index);



extern s32 Audio_GetVoiceSoundState(SlotRecAtB8 *arg0, s16 arg1);




struct RecordRecAt4V5;
typedef struct RecordRecAt4V5 RecordRecAt4V5;


struct HeaderRecAt102;
struct RecordRecAt4V6;

struct RecordRecAt4V5;

extern float D_800C3F50_de;



struct RecordRecAt4V4;
typedef struct RecordRecAt4V4 RecordRecAt4V4;

extern float D_800CB8E8;


struct Emitter;

extern float D_800C3F84_de;


struct RecordRecAt4V6;
typedef struct RecordRecAt4V6 RecordRecAt4V6;


struct IntegerStateB4;
typedef struct IntegerStateB4 IntegerStateB4;

struct ContextCode8025A3EC;
typedef struct ContextCode8025A3EC ContextCode8025A3EC;

struct ViewChannelUpdateVoicePlayback;
typedef struct ViewChannelUpdateVoicePlayback ViewChannelUpdateVoicePlayback;

extern float D_800C9048;

struct Emitter;
typedef struct Emitter Emitter;


struct ObjRecAtCV4;
typedef struct ObjRecAtCV4 ObjRecAtCV4;

#endif
