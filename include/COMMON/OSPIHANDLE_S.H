#ifndef COMMON_OSPIHANDLE_S_H
#define COMMON_OSPIHANDLE_S_H
#include "TYPES.H"
typedef struct PiDiskBlock {
    s32 error;
    u8 *dramAddress;
    u32 c2Address, sectorSize;
    u8 remaining[0x14];
} PiDiskBlock;

typedef struct PiDiskTransfer {
    u32 command;
    u16 mode, blockNumber;
    s32 sectorNumber;
    u32 deviceAddress, control, sequenceControl;
    PiDiskBlock blocks[2];
} PiDiskTransfer;
struct OSPiHandle_s;
typedef struct OSPiHandle_s OSPiHandle_s;
struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    union { u8 bytes[0x60]; PiDiskTransfer transfer; } transferInfo;
};









struct OSPiHandle_s;

extern OSPiHandle_s g_diskPiHandle;
#endif
