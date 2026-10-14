#ifndef UNBAKE_SPAN_1000_CODE_802B7488_H
#define UNBAKE_SPAN_1000_CODE_802B7488_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct ContReadFormat;
typedef struct ContReadFormat ContReadFormat;

struct ALSynth_func_802B2650_de;
struct ALSynth_func_802B2650_de {
    ALPlayer_s14 *head;
};

struct ALSndPlayer_func_802B2650_de;
struct ALSynth_func_802B2650_de;
struct ALSndPlayer_func_802B2650_de {
    ALPlayer_s14 node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    struct ALSynth_func_802B2650_de *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    s32 frameTime;
    s32 nextDelta;
    s32 curTime;
};

struct ALGlobals_func_802B2650_de;
typedef struct ALGlobals_func_802B2650_de ALGlobals_func_802B2650_de;

extern int D_800D4340;

struct ALSndpConfig;
struct ALSndpConfig {
    s32 maxSounds;
    s32 maxEvents;
    ALHeap *heap;
};

struct ALSoundState;
typedef struct ALSoundState ALSoundState;

struct ALSndPlayer_func_802B2650_de;
typedef struct ALSndPlayer_func_802B2650_de ALSndPlayer_func_802B2650_de;

struct ALSndpConfig;
typedef struct ALSndpConfig ALSndpConfig;

struct ALSynth_func_802B2650_de;
typedef struct ALSynth_func_802B2650_de ALSynth_func_802B2650_de;

struct ALGlobals_func_802B2650_de;
struct ALGlobals_func_802B2650_de {
    ALSynth_func_802B2650_de drvr;
};

struct ContReadFormat;
struct ContReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    s8 stick_x;
    s8 stick_y;
};

struct ContPad;
struct ContPad {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 error;
};

extern int func_802B7C30_de();

struct ALSoundState;
struct ALSoundState {
    ALVoice_s voice;
    void *sound;
    s16 priority;
    f32 pitch;
    s32 state;
    s16 vol;
    u8 pan;
    u8 fxMix;
};

extern void func_802B784C_de();

struct ContPad;
typedef struct ContPad ContPad;

extern void func_802B75F4_de(ContPad *data);

extern void func_802B768C_de();

#endif
