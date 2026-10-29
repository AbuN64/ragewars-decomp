#ifndef SDK_LEO_H
#define SDK_LEO_H
#include "TYPES.H"

typedef struct __OSBlockInfo {
    u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} __OSBlockInfo;

typedef struct __OSTranxInfo {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_leo {
    struct OSPiHandle_leo *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle_leo;

extern OSPiHandle_leo *g_currentDiskPeripheralHandle;
extern s32 __OSGlobalIntMask;
extern s32 __osEPiRawStartDma(OSPiHandle_leo *handle, s32 direction, u32 cartAddr, void *dramAddr, u32 size);
extern void __osLeoResume(void);
extern void __osLeoAbnormalResume(void);
#endif
