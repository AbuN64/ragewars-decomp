#ifndef COMMON_OSPIHANDLE_S_H
#define COMMON_OSPIHANDLE_S_H
#include "TYPES.H"
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
    u8 transferInfo[0x60];
};









struct OSPiHandle_s;

extern OSPiHandle_s D_801486C0;
#endif
