#ifndef COMMON_ALBANK_S_H
#define COMMON_ALBANK_S_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ALBank_s;
typedef struct ALBank_s ALBank_s;
/* Relocated bank-file header read by the sound context initializer. */
typedef struct ALBankFile {
    s16 revision;
    s16 bankCount;
    ALBank_s *bankArray[1];
} ALBankFile;

struct func_802B6BE4_S3;
struct func_802B6BE4_S3 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x1C - 0x14 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x48 - 0x1C - sizeof(s32)];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
};

struct ALKeyMap;
struct ALKeyMap {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
};

struct ALVoiceState;

struct func_802B6B90_S3;
struct func_802B6B90_S3 {
    u8 unk0;
    char pad0[0x1 - 0x0 - sizeof(u8)];
    u8 unk1;
    char pad1[0x2 - 0x1 - sizeof(u8)];
    u8 unk2;
    char pad2[0xC - 0x2 - sizeof(u8)];
    u16 unkC;
};

struct func_802B6B90_S1;
typedef struct func_802B6B90_S1 func_802B6B90_S1;

struct func_802B66A0_S2;
typedef struct func_802B66A0_S2 func_802B66A0_S2;

struct func_802B6BE4_S2;
struct func_802B6BE4_S2 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x30 - 0x24 - sizeof(s32)];
    u8 unk30;
    char pad30[0x33 - 0x30 - sizeof(u8)];
    u8 unk33;
    char pad33[0x34 - 0x33 - sizeof(u8)];
    u8 unk34;
};



struct func_802B6D04_S1;
typedef struct func_802B6D04_S1 func_802B6D04_S1;

struct ALInstrument;
typedef struct ALInstrument ALInstrument;

struct ALSound_s;
typedef struct ALSound_s ALSound_s;

struct ALKeyMap;
typedef struct ALKeyMap ALKeyMap;

struct ALEnvelope;
struct ALEnvelope {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
};

struct ALEnvelope;
typedef struct ALEnvelope ALEnvelope;

struct ALSound_s;
struct ALSound_s {
    ALEnvelope *envelope;
    ALKeyMap *keyMap;
    void *wavetable;
    u8 samplePan;
    u8 sampleVolume;
    u8 flags;
};

struct ALInstrument;
struct ALInstrument {
    u8 volume;
    u8 pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSound_s *soundArray[1];
};

struct ALChanState10;
struct ALChanState10 {
    ALInstrument *instrument;
    s16 bendRange;
    u8 fxId;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
};

struct func_802B6BE4_S4;
typedef struct func_802B6BE4_S4 func_802B6BE4_S4;

struct ALSeqPlayer;
typedef struct ALSeqPlayer ALSeqPlayer;

struct func_802B67B0_S3;
struct func_802B67B0_S3 {
    char pad0[0x4];
    u8 * unk4;
};

struct func_802B6BE4_S2;
typedef struct func_802B6BE4_S2 func_802B6BE4_S2;

struct TableSlot;
typedef struct TableSlot TableSlot;

struct ObjectLinks88;
typedef struct ObjectLinks88 ObjectLinks88;

struct ALSeqPlayer;

struct func_802B6BE4_S4;
struct func_802B6BE4_S4 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
    char padC[0x10 - 0xC - sizeof(s16)];
    void * unk10;
};

struct func_802B67B0_S1;
typedef struct func_802B67B0_S1 func_802B67B0_S1;

struct ALSeqPlayer;

struct ObjectStateD;
typedef struct ObjectStateD ObjectStateD;

struct ALBank_s;
struct ALBank_s {
    s16 instCount;
    u8 flags;
    u8 pad;
    s32 sampleRate;
    ALInstrument *percussion;
    ALInstrument *instArray[1];
};

struct ALVoiceState;
typedef struct ALVoiceState ALVoiceState;

struct ALChanState;
struct ALChanState {
    void *instrument;
    s16 bendRange;
    u8 fxId;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
};
struct ALChanState;
struct ALSeqPlayer;

struct List802B663C;
typedef struct List802B663C List802B663C;

extern void alHeapInit(void *arg0, u8 *base, s32 arg2);

typedef signed int ( *Lane_ALOscUpdate)(void *, float *);

struct func_802B65EC_S2;
struct func_802B65EC_S2 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x31 - 0x14 - sizeof(void*)];
    s8 unk31;
    char pad31[0x32 - 0x31 - sizeof(s8)];
    s8 unk32;
    char pad32[0x33 - 0x32 - sizeof(s8)];
    s8 unk33;
};

struct List802B663C;
struct List802B663C {
    char pad[0x64];
    Node_func_80239AF4_de *head;
    Node_func_80239AF4_de *tail;
    Node_func_80239AF4_de *free;
};


struct EntryTable;
typedef struct EntryTable EntryTable;

extern float D_800C74D0_de;

struct ALVoice_s;

struct func_802B6B90_S1;
struct func_802B6B90_S1 {
    char pad0[0x60];
    s32 unk60;
};

struct func_802B65EC_S1;
struct func_802B65EC_S1 {
    char pad0[0x64];
    void * unk64;
    char pad64[0x68 - 0x64 - sizeof(void*)];
    void * unk68;
    char pad68[0x6C - 0x68 - sizeof(void*)];
    void * unk6C;
};

struct func_802B6A60_S1;
struct func_802B6A60_S1 {
    char pad0[0x34];
    u8 unk34;
    char pad34[0x60 - 0x34 - sizeof(u8)];
    func_802626BC_S1_U10 unk60;
};

struct ALVoiceState;
struct ALVoiceState {
    struct ALVoiceState *next;
    ALVoice_s voice;
    ALSound_s *sound;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
};

struct ALOscEvent;
struct ALVoiceState;

struct func_802B6A60_S1;
typedef struct func_802B6A60_S1 func_802B6A60_S1;

struct func_802B69B4_S2;
struct func_802B69B4_S2 {
    char pad0[0x34];
    u8 unk34;
};

struct Entry802B6BE4;
struct Entry802B6BE4 {
    s16 type;
    s16 pad;
    void *object;
    s32 unused;
};

struct func_802B66A0_S1;
struct func_802B66A0_S1 {
    char pad0[0x48];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
};

struct ALVoiceState;

struct func_802B65EC_S2;
typedef struct func_802B65EC_S2 func_802B65EC_S2;

struct func_802B6D04_S1;
struct func_802B6D04_S1 {
    char pad0[0x48];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
    char pad50[0x78 - 0x50 - sizeof(char*)];
    void * unk78;
};

struct ALVoiceState;

typedef signed int ( *Lane_ALOscInit)(void * *, float *, unsigned char, unsigned char, unsigned char, unsigned char);

struct func_802B6B90_S3;
typedef struct func_802B6B90_S3 func_802B6B90_S3;

struct func_802B6D04_S2;
typedef struct func_802B6D04_S2 func_802B6D04_S2;

struct Entry802B6BE4;
typedef struct Entry802B6BE4 Entry802B6BE4;

struct func_802B6B90_S2;
struct func_802B6B90_S2 {
    void *unk0;
    u16 unk4;
    char pad4[0x7 - 0x4 - sizeof(u16)];
    u8 unk7;
    char pad7[0x8 - 0x7 - sizeof(u8)];
    u8 unk8;
    char pad8[0x9 - 0x8 - sizeof(u8)];
    u8 unk9;
};

typedef void ( *Lane_ALOscStop)(void *);

struct func_802B69B4_S1;
struct func_802B69B4_S1 {
    char pad0[0x4];
    char unk4;
    char pad4[0xC - 0x4 - sizeof(char)];
    void * unkC;
};

struct TableSlot;
struct TableSlot {
    void *entry;
    char rest[0xC];
};

struct func_802B66A0_S1;
typedef struct func_802B66A0_S1 func_802B66A0_S1;

struct EntryTable;
struct EntryTable {
    char header[0x10];
    void *entries[1];
};

struct ALSeqPlayer;
struct ALVoiceState;

struct func_802B67B0_S3;
typedef struct func_802B67B0_S3 func_802B67B0_S3;

struct ALSound;
struct ALSound {
    void *envelope;
    void *keyMap;
    void *wavetable;
    u8 samplePan;
    u8 sampleVolume;
    u8 flags;
};
struct ALSound;
struct ALVoiceState;

struct func_802B67B0_S1;
struct func_802B67B0_S1 {
    char pad0[0x60];
    void * unk60;
};

struct ObjectLinks88;
struct ObjectLinks88 {
    char pad0[0x18];
    void * unk_18;
    char pad18[0x24 - 0x18 - sizeof(void*)];
    s32 unk_24;
    char pad24[0x2C - 0x24 - sizeof(s32)];
    s32 unk_2C;
    char pad2C[0x48 - 0x2C - sizeof(s32)];
    char unk_48;
    char pad48[0x7C - 0x48 - sizeof(char)];
    void * unk_7C;
    char pad7C[0x80 - 0x7C - sizeof(void*)];
    char * unk_80;
    char pad80[0x84 - 0x80 - sizeof(char*)];
    s32 unk_84;
};

struct ObjectLinks34;
typedef struct ObjectLinks34 ObjectLinks34;

typedef int ALMicroTime;

struct ALChanState10;
typedef struct ALChanState10 ALChanState10;

struct ALNoteEvent;

struct ALOscEvent;

struct ALVolumeEvent;

struct ALNoteEvent;
struct ALVoice_s;


struct ALEvent;

struct ALSeqPlayer;
struct ALSeqPlayer {
    ALPlayer_s node;
    void *drvr;
    void *target;
    ALMicroTime curTime;
    ALBank_s *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState10 *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    Lane_ALOscInit initOsc;
    Lane_ALOscUpdate updateOsc;
    Lane_ALOscStop stopOsc;
};

struct func_802B65EC_S1;
typedef struct func_802B65EC_S1 func_802B65EC_S1;

struct func_802B66A0_S2;
struct func_802B66A0_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
    char padC[0x10 - 0xC - sizeof(s16)];
    s32 unk10;
};

struct func_802B6D04_S2;
struct func_802B6D04_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    u16 unkC;
    char padC[0x10 - 0xC - sizeof(u16)];
    void * unk10;
    char pad10[0x14 - 0x10 - sizeof(void*)];
    void * unk14;
};

struct func_802B6BE4_S3;
typedef struct func_802B6BE4_S3 func_802B6BE4_S3;

struct func_802B6BE4_S1;
typedef struct func_802B6BE4_S1 func_802B6BE4_S1;

struct ObjectLinks34;
struct ObjectLinks34 {
    char pad0[0x20];
    void * unk_20;
    char pad20[0x31 - 0x20 - sizeof(void*)];
    u8 unk_31;
};


struct func_802B6B90_S2;
typedef struct func_802B6B90_S2 func_802B6B90_S2;

struct func_802B69B4_S2;
typedef struct func_802B69B4_S2 func_802B69B4_S2;



struct func_802B6D04_S4;
struct func_802B6D04_S4 {
    char pad0[0x37];
    u8 unk37;
};

struct ObjectStateD;
struct ObjectStateD {
    unsigned char padding_0[12];
    u8 unk_C;
};

struct func_802B6D04_S4;
typedef struct func_802B6D04_S4 func_802B6D04_S4;

struct func_802B69B4_S1;
typedef struct func_802B69B4_S1 func_802B69B4_S1;

extern float D_800C74CC_de;

struct func_802B6BE4_S1;
struct func_802B6BE4_S1 {
    char pad0[0x10];
    char * unk10;
};

extern int func_802B0630_eu(void * arg0, int arg1, int arg2);
#endif
