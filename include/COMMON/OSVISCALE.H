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

extern float g_videoScaleSignedConversionLimit;

struct ViModeContextView;
typedef struct ViModeContextView ViModeContextView;

struct OSMesgQueue;

struct VideoDeviceManager;
struct OSMesgQueue;
struct OSThread;
struct VideoDeviceManager {
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

struct VideoContextEventView;
typedef struct VideoContextEventView VideoContextEventView;

extern double g_videoScaleUnsignedBias;


struct OSViFieldRegs;
typedef struct OSViFieldRegs OSViFieldRegs;

struct VideoContextEventView;

struct ViVerticalScaleView;
struct ViVerticalScaleView {
    u16 state;
    unsigned char padding_2[34];
    f32 yScaleFactor;
};

struct OSViMode;
struct OSViMode {
    u8 type;
    Awords comRegs;
};

struct OSViMode;
struct ViModeContextView;
struct ViModeContextView {
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

struct ViVerticalScaleView;
typedef struct ViVerticalScaleView ViVerticalScaleView;


struct Modep;
typedef struct Modep Modep;

struct OSViMode;
typedef struct OSViMode OSViMode;

struct __OSViScale;
typedef struct __OSViScale __OSViScale;

struct Modep;
struct ViSwapContextView;
struct ViSwapContextView {
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

struct VideoDeviceManager;
typedef struct VideoDeviceManager VideoDeviceManager;

struct ViSwapContextView;
typedef struct ViSwapContextView ViSwapContextView;
#endif
