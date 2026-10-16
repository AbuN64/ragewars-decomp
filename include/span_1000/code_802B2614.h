#include "TYPES.H"
#ifndef UNBAKE_SPAN_1000_CODE_802B2614_H
#define UNBAKE_SPAN_1000_CODE_802B2614_H
#include "common/types_1dc8418c21db.h"
struct Slot_func_802B2ED0_de;
typedef struct Slot_func_802B2ED0_de Slot_func_802B2ED0_de;

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

struct func_802B7D18_S2;
struct func_802B7D18_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    s32 unk10;
};

struct func_802B7FA0_S1;
struct func_802B7FA0_S1 {
    char pad0[0x40];
    void * unk40;
};

struct func_802B7D18_S2;
typedef struct func_802B7D18_S2 func_802B7D18_S2;

struct ParamsRecAt8V2;
typedef struct ParamsRecAt8V2 ParamsRecAt8V2;

struct ALSndPlayer;
typedef struct ALSndPlayer ALSndPlayer;

struct func_802B7FA0_S1;
typedef struct func_802B7FA0_S1 func_802B7FA0_S1;

union ALSndpEvent;
typedef union ALSndpEvent ALSndpEvent;

struct Slot_func_802B2ED0_de;
struct Slot_func_802B2ED0_de {
    char pad0[0x20];
    short value;
    char pad22[0xE];
};


struct ParamsRecAt8V2;
struct ParamsRecAt8V2 {
    s16 f0;
    s32 f4;
    s8 f8;
};

struct ParamsRecAt8V3;
typedef struct ParamsRecAt8V3 ParamsRecAt8V3;

s32 func_802B2CF0_de(s32 val, f32 div);

extern const f32 D_800C7544;

#endif
