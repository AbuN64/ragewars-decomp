#ifndef UNBAKE_SPAN_1000_CODE_802BA23C_H
#define UNBAKE_SPAN_1000_CODE_802BA23C_H
#include "acmd.h"
#include "types.h"
extern void func_802BA210_de(void);

struct __OSViScale;
struct __OSViScale {
    f32 factor;
    u16 offset;
    u32 scale;
};

extern float D_800C79D8_de;

struct __OSViContext_func_802BA6B0_de;
typedef struct __OSViContext_func_802BA6B0_de __OSViContext_func_802BA6B0_de;

struct OSIoMesgHdr_func_802BA350_de;
struct OSMesgQueue;
struct OSIoMesgHdr_func_802BA350_de {
    u16 type;
    u8 pri;
    u8 status;
    struct OSMesgQueue *retQueue;
};

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

struct OSIoMesgCode802BA23C;
typedef struct OSIoMesgCode802BA23C OSIoMesgCode802BA23C;

extern void func_802BA700_de(s32 arg0);

extern void *func_802BA310_de();

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

struct OSIoMesgHdr_func_802BA350_de;
typedef struct OSIoMesgHdr_func_802BA350_de OSIoMesgHdr_func_802BA350_de;

struct OSViFieldRegs;
typedef struct OSViFieldRegs OSViFieldRegs;

struct RecCode802BA23C;
struct RecCode802BA23C {
    char pad0[2];
    s16 f2;
    char pad4[0xC];
    s32 f10;
    s32 f14;
};

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

struct OSIoMesgCode802BA23C;
struct OSIoMesgCode802BA23C {
    OSIoMesgHdr_func_802BA350_de hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
};

extern void func_802BA910_de();

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

extern void osViSetYScale(f32 arg0);

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

struct State_func_802BA700_de;
typedef struct State_func_802BA700_de State_func_802BA700_de;

struct State_func_802BA700_de;
struct State_func_802BA700_de {
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

extern void func_802BA350_de(s32 pri);

#endif
