#ifndef UNBAKE_SPAN_1000_CODE_802B369C_H
#define UNBAKE_SPAN_1000_CODE_802B369C_H
#include "audio_callbacks.h"
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
struct ALAuxBus_s;
typedef struct ALAuxBus_s ALAuxBus_s;

struct ALLoadFilter;
typedef struct ALLoadFilter ALLoadFilter;

struct ALParam_s1C;
struct ALParam_s1C {
    struct ALParam_s1C *next;
    s32 delta;
    s16 type;
    s32 data;
    s32 moredata;
    s32 stillmoredata;
    s32 yetstillmoredata;
};

extern void alSynStopVoice(struct Shape_typemap_71 *arg0, void *arg1);

struct ALResampler;
typedef struct ALResampler ALResampler;

struct func_802B8CC8_S1;
struct func_802B8CC8_S1 {
    char pad0[0x2C];
    void * unk2C;
};

struct ALParam_s1C;
typedef struct ALParam_s1C ALParam_s1C;

struct ALLoadFilter;
struct ALLoadFilter {
    char pad[0x48];
};

struct ALFilter_sC;
struct ALFilter_sC {
    struct ALFilter_sC *source;
    ALCmdHandler handler;
    ALSetParam setParam;
};

struct ALFilter_sC;
typedef struct ALFilter_sC ALFilter_sC;

struct ALSynth4C;
struct ALSynth4C {
    ALPlayer_s14 *head;
    ListLink pFreeList;
    ListLink pAllocList;
    ListLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    void *dma;
    void *heap;
    void *paramList;
    void *mainBus;
    void *auxBus;
    ALFilter_sC *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};

typedef void ( *SharedRecV12)(void *, signed int, void *);

struct ALEnvMixer4C;
struct ALEnvMixer4C {
    char pad[0x4C];
};

struct ALSynth;
typedef struct ALSynth ALSynth;

struct ALAuxBus_s;
struct ALAuxBus_s {
    ALFilter_s14 filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter_s14 **sources;
    char fx[0x4C - 0x20];
};

struct ALResampler;
struct ALResampler {
    char pad[0x34];
};

struct func_802B8CC8_S1;
typedef struct func_802B8CC8_S1 func_802B8CC8_S1;

struct ALSynConfig;
typedef struct ALSynConfig ALSynConfig;

typedef void *( *ALDMANew)(void *);

struct ALSave;
typedef struct ALSave ALSave;

struct ALMainBus_s;
struct ALMainBus_s {
    ALFilter_s14 filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter_s14 **sources;
};

struct func_802B9474_S1;
struct func_802B9474_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x30 - 0x18 - sizeof(s32)];
    s32 unk30;
    char pad30[0x3C - 0x30 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
    char pad40[0x44 - 0x40 - sizeof(s32)];
    s32 unk44;
};

struct ALSynth4C;
typedef struct ALSynth4C ALSynth4C;

struct ALSynConfig;
struct ALSynConfig {
    s32 maxVVoices;
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    u8 fxType;
    s32 *params;
};

struct ALGlobals;
struct ALGlobals {
    ALSynth4C drvr;
};

struct PVoice_s;
typedef struct PVoice_s PVoice_s;

struct ALEnvMixer4C;
typedef struct ALEnvMixer4C ALEnvMixer4C;

struct Opaque_ALVoice_s;
struct PVoice_s;
struct PVoice_s {
    ListLink node;
    struct Opaque_ALVoice_s *vvoice;
    ALFilter_s14 *channelKnob;
    ALLoadFilter decoder;
    ALResampler resampler;
    ALEnvMixer4C envmixer;
    s32 offset;
};

struct ALMainBus_s;
typedef struct ALMainBus_s ALMainBus_s;

struct ObjectStateC_3;
typedef struct ObjectStateC_3 ObjectStateC_3;

struct func_802B9474_S1;
typedef struct func_802B9474_S1 func_802B9474_S1;

struct ObjectStateC_3;
struct ObjectStateC_3 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
};

struct ALGlobals;
typedef struct ALGlobals ALGlobals;

struct ALSynth;
struct ALSynth {
    void *head;
    ListLink pFreeList;
    ListLink pAllocList;
    ListLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    ALParam_s1C *paramList;
    ALMainBus_s *mainBus;
    ALAuxBus_s *auxBus;
    ALFilter_s14 *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};

struct ALSave;
struct ALSave {
    ALFilter_s14 filter;
    s32 dramout;
    s32 first;
};

extern s32 func_802B3D10_de(ALSynth4C *drvr, ALPlayer_s14 **client);
#endif
