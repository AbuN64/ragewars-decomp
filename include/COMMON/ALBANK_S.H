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

struct ALChanState;
struct ALChanState {
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


struct ALSeqPlayer;
typedef struct ALSeqPlayer ALSeqPlayer;




struct ObjectLinks88;
typedef struct ObjectLinks88 ObjectLinks88;

struct ALSeqPlayer;



struct ALSeqPlayer;


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

struct ALSeqPlayer;

struct List802B663C;
typedef struct List802B663C List802B663C;

extern void alHeapInit(void *arg0, u8 *base, s32 arg2);

typedef signed int ( *Lane_ALOscUpdate)(void *, float *);


struct List802B663C;
struct List802B663C {
    char pad[0x64];
    Node_func_80239AF4_de *head;
    Node_func_80239AF4_de *tail;
    Node_func_80239AF4_de *free;
};



extern float D_800C74D0_de;

struct ALVoice_s;




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



struct Entry802B6BE4;
struct Entry802B6BE4 {
    s16 type;
    s16 pad;
    void *object;
    s32 unused;
};


struct ALVoiceState;



struct ALVoiceState;

typedef signed int ( *Lane_ALOscInit)(void * *, float *, unsigned char, unsigned char, unsigned char, unsigned char);



struct Entry802B6BE4;
typedef struct Entry802B6BE4 Entry802B6BE4;


typedef void ( *Lane_ALOscStop)(void *);





struct ALSeqPlayer;
struct ALVoiceState;


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


typedef int ALMicroTime;

struct ALChanState;
typedef struct ALChanState ALChanState;

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
    struct ALCSeq_s *target;
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
    ALChanState *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    Lane_ALOscInit initOsc;
    Lane_ALOscUpdate updateOsc;
    Lane_ALOscStop stopOsc;
};
















extern float D_800C74CC_de;


#endif
