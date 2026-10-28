#ifndef COMMON_OSVISCALE_H
#define COMMON_OSVISCALE_H
#include "acmd.h"
#include "TYPES.H"

struct OSThread_s;
struct OSPiHandle_s;

typedef struct OSDevMgr OSDevMgr;
struct OSDevMgr {
    s32 active;
    struct OSThread_s *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(struct OSPiHandle_s *, s32, u32, void *, u32);
};


struct __OSViScale;
struct __OSViScale {
    f32 factor;
    u16 offset;
    u32 scale;
};

extern float D_800C79D8_de;

struct __OSViContext_func_802BA6B0_de;
typedef struct __OSViContext_func_802BA6B0_de __OSViContext_func_802BA6B0_de;

struct OSMesgQueue;

struct OSDevMgr_func_802BA350_de;
struct OSMesgQueue;
struct OSThread;
struct OSDevMgr_func_802BA350_de {
    u32 active;
    struct OSThread *thread;
    struct OSMesgQueue *cmdQueue;
    struct OSMesgQueue *evtQueue;
    struct OSMesgQueue *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(void *, s32, u32, void *, u32);
};




struct OSViCommonRegs;
struct OSViCommonRegs {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
};

struct RecCode802BA23C;
typedef struct RecCode802BA23C RecCode802BA23C;

extern double D_800C79D0_de;


struct OSViFieldRegs;
typedef struct OSViFieldRegs OSViFieldRegs;

struct RecCode802BA23C;

struct ObjectState28;
struct ObjectState28 {
    u16 unk_0;
    unsigned char padding_2[34];
    f32 unk_24;
};

struct OSViMode;
struct OSViMode {
    u8 type;
    Awords comRegs;
};

struct OSViMode;
struct __OSViContext_func_802BA6B0_de;
struct __OSViContext_func_802BA6B0_de {
    u16 state;
    u16 retraceCount;
    void *framep;
    struct OSViMode *modep;
    u32 control;
};



struct OSViCommonRegs;
typedef struct OSViCommonRegs OSViCommonRegs;

struct OSViFieldRegs;
struct OSViFieldRegs {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
};

struct Modep;
struct Modep {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
};

struct ObjectState28;
typedef struct ObjectState28 ObjectState28;


struct Modep;
typedef struct Modep Modep;

struct OSViMode;
typedef struct OSViMode OSViMode;

struct __OSViScale;
typedef struct __OSViScale __OSViScale;

struct Modep;
struct __OSViContext_func_802BA910_de;
struct __OSViContext_func_802BA910_de {
    u16 state;
    u16 retraceCount;
    void *framep;
    struct Modep *modep;
    u32 control;
    void *msgq;
    void *msg;
    __OSViScale x;
    __OSViScale y;
};

struct StateosViSetSpecialFeatures;
typedef struct StateosViSetSpecialFeatures StateosViSetSpecialFeatures;

struct StateosViSetSpecialFeatures;
struct StateosViSetSpecialFeatures {
    u16 status;
    u16 pad2;
    u32 word4;
    Awords *inner;
    u32 flags;
};

struct OSDevMgr_func_802BA350_de;
typedef struct OSDevMgr_func_802BA350_de OSDevMgr_func_802BA350_de;

struct __OSViContext_func_802BA910_de;
typedef struct __OSViContext_func_802BA910_de __OSViContext_func_802BA910_de;
#endif
