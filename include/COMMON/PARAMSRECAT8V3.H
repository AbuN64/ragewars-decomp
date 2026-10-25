#ifndef COMMON_PARAMSRECAT8V3_H
#define COMMON_PARAMSRECAT8V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct ParamsRecAt8V3;
struct ParamsRecAt8V3 {
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




struct ParamsRecAt8V2;
typedef struct ParamsRecAt8V2 ParamsRecAt8V2;

struct ALSndPlayer;
typedef struct ALSndPlayer ALSndPlayer;


union ALSndpEvent;
typedef union ALSndpEvent ALSndpEvent;



struct ParamsRecAt8V2;
struct ParamsRecAt8V2 {
    s16 f0;
    s32 f4;
    s8 f8;
};

struct ParamsRecAt8V3;
typedef struct ParamsRecAt8V3 ParamsRecAt8V3;


extern const f32 D_800C7544;
#endif
