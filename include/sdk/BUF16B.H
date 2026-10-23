#ifndef SDK_BUF16B_H
#define SDK_BUF16B_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/AUDIO_INITIALIZE.H"
struct func_802B510C_S2;
struct func_802B510C_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    char unkC;
};

struct func_802B5410_S1;
struct func_802B5410_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    u32 unk4;
    char pad4[0x8 - 0x4 - sizeof(u32)];
    s32 unk8;
};

struct Buf16b;
struct Buf16b {
    s16 count;
    s16 _pad2;
    s16 value;
    s16 _pad6;
    s32 _pad8;
    s32 _padC;
};

struct Buf16c;
typedef struct Buf16c Buf16c;



struct func_802B52B0_S1;
typedef struct func_802B52B0_S1 func_802B52B0_S1;

struct Buf16c;
struct Buf16c {
    s16 count;
    s16 _pad2;
    s32 zero;
    s8 f8;
    s8 f9;
    s8 fA;
    s8 _padB;
    s32 _padC;
};

struct func_802B5328_S2;
typedef struct func_802B5328_S2 func_802B5328_S2;

struct func_802B5328_S2;
struct func_802B5328_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
};

struct Buf16b;
typedef struct Buf16b Buf16b;

struct func_802B5410_S1;
typedef struct func_802B5410_S1 func_802B5410_S1;

struct func_802B510C_S2;
typedef struct func_802B510C_S2 func_802B510C_S2;

struct func_802B52B0_S1;
struct func_802B52B0_S1 {
    char pad0[0x8];
    Node_func_80239AF4_de * unk8;
};

typedef struct SeqFreeVoice { struct SeqFreeVoice *next; char pad[0x34]; } SeqFreeVoice;
typedef struct ALSeqpConfig {
    s32 voices, events;
    u8 channels, debug;
    u8 pad[2];
    void *heap;
    void *initOsc, *updateOsc, *stopOsc;
} ALSeqpConfig;
typedef struct SeqInitPlayer {
    void *next;
    struct SeqInitPlayer *self;
    void *callback;
    char padC[8];
    void *driver;
    void *target;
    s32 time;
    void *bank;
    s32 uspt, delta, state;
    u16 mask;
    s16 volume;
    u8 channels, debug;
    u8 pad36[2];
    s16 eventType;
    char pad3A[0xE];
    char queue[0x14];
    s32 frameTime;
    void *channelState;
    SeqFreeVoice *allocHead, *allocTail, *freeList;
    void *initOsc, *updateOsc, *stopOsc;
    void *loopStart, *loopEnd;
    s32 loopCount;
} SeqInitPlayer;
extern char D_002B0554;
#endif
