#ifndef COMMON_PARAMSRECAT8V3_H
#define COMMON_PARAMSRECAT8V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct SoundPlayerWordParameterEvent;
struct SoundPlayerWordParameterEvent {
    s16 f0;
    s32 f4;
    s32 f8;
};

union ALSndpEvent;
union ALSndpEvent {
    ALEvent msg;
    struct {
        s16 type;
        void *state;
    } common;
};

struct ALSndPlayer;
struct ALSndPlayer {
    ALPlayer_s node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    void *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    s32 frameTime;
    s32 nextDelta;
    s32 curTime;
};

struct ALSndPlayer;
union ALSndpEvent;




struct SoundPlayerByteParameterEvent;
typedef struct SoundPlayerByteParameterEvent SoundPlayerByteParameterEvent;

struct ALSndPlayer;
typedef struct ALSndPlayer ALSndPlayer;


union ALSndpEvent;
typedef union ALSndpEvent ALSndpEvent;



struct SoundPlayerByteParameterEvent;
struct SoundPlayerByteParameterEvent {
    s16 f0;
    s32 f4;
    s8 f8;
};

struct SoundPlayerWordParameterEvent;
typedef struct SoundPlayerWordParameterEvent SoundPlayerWordParameterEvent;


extern const f32 D_800C7544;
#endif
