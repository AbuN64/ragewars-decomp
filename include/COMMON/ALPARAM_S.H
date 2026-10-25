#ifndef COMMON_ALPARAM_S_H
#define COMMON_ALPARAM_S_H
#include "TYPES.H"
struct ALParam_s;
typedef struct ALParam_s ALParam_s;

struct func_802BA4B0_S1;
struct func_802BA4B0_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    short unkC;
    char padC[0xE - 0xC - sizeof(short)];
    short unkE;
    char padE[0x10 - 0xE - sizeof(short)];
    int unk10;
};

extern float D_800C7708_de;

extern float D_800C75E0_de;

struct ALFilter_s;
typedef struct ALFilter_s ALFilter_s;

struct ALFilter_s;
struct ALFilter_s {
    struct ALFilter_s *source;
    void *handler;
    s32 (*setParam)(void *, s32, void *);
    s16 inp;
    s16 outp;
    s32 type;
};

/* Filter parameter / control-update types (libultra AL_FILTER_*). */
enum {
    AL_FILTER_FREE_VOICE,
    AL_FILTER_SET_SOURCE,
    AL_FILTER_ADD_SOURCE,
    AL_FILTER_ADD_UPDATE,
    AL_FILTER_RESET,
    AL_FILTER_SET_WAVETABLE,
    AL_FILTER_SET_DRAM,
    AL_FILTER_SET_PITCH,
    AL_FILTER_SET_UNITY_PITCH,
    AL_FILTER_START,
    AL_FILTER_SET_STATE,
    AL_FILTER_SET_VOLUME,
    AL_FILTER_SET_PAN,
    AL_FILTER_START_VOICE_ALT,
    AL_FILTER_START_VOICE,
    AL_FILTER_STOP_VOICE,
    AL_FILTER_SET_FXAMT
};
struct ALParam_s;
struct ALParam_s {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    union {
        s32 i;
        f32 f;
        void *p;
    } data;
    union {
        s32 i;
        f32 f;
        void *p;
    } moredata;
};
/* AL_FILTER_START_VOICE update: optional unity pitch, then the wavetable to start. */
struct ALStartParam;
typedef struct ALStartParam ALStartParam;
struct ALStartParam {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    void *wave;
};
/* AL_FILTER_FREE_VOICE update: the physical voice to return to the synth driver. */
struct PVoice_s;
struct ALFreeParam;
typedef struct ALFreeParam ALFreeParam;
struct ALFreeParam {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    struct PVoice_s *pvoice;
};

struct ALEnvMixer;
struct ALFilter_s;
struct ALParam_s;
struct ALEnvMixer {
    ALFilter_s filter;
    void *state;
    s16 pan;
    s16 volume;
    s16 cvolL;
    s16 cvolR;
    s16 dryamt;
    s16 wetamt;
    u16 lratl;
    s16 lratm;
    s16 ltgt;
    u16 rratl;
    s16 rratm;
    s16 rtgt;
    s32 delta;
    s32 segEnd;
    s32 first;
    struct ALParam_s *ctrlList;
    struct ALParam_s *ctrlTail;
    struct ALFilter_s **sources;
    s32 motion;
};

typedef signed short AudioPoleFilterState[4];

struct AudioLowPassFilter;
struct AudioLowPassFilter {
    s16 cutoff;
    s16 gain;
    union {
        s16 taps[16];
        s64 alignment;
    } coefficients;
    AudioPoleFilterState *state;
    s32 first;
};

struct AudioLowPassFilter;
typedef struct AudioLowPassFilter AudioLowPassFilter;


struct func_802B95DC_S1;
typedef struct func_802B95DC_S1 func_802B95DC_S1;

struct LogTab;
typedef struct LogTab LogTab;

struct LogTab;
struct LogTab {
    f64 v[8];
};

extern s16 func_802B4F68_de(f64 vol, f64 tgt, s32 count, u16 *ratel);

struct ALEnvMixer;
typedef struct ALEnvMixer ALEnvMixer;

extern f64 func_802B53B4_de(f64 arg0, s32 arg1);

extern f64 frexp(f64 arg0, s32 *arg2);

extern float D_800C770C_de;

struct func_802B95DC_S1;
struct func_802B95DC_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
};

struct func_802BA4B0_S1;
typedef struct func_802BA4B0_S1 func_802BA4B0_S1;

extern f32 Audio_GetEnvelopeVolume(f32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern void func_802B4A08_eu_x(void);
#endif
