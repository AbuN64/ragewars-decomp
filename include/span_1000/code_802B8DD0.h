#ifndef UNBAKE_SPAN_1000_CODE_802B8DD0_H
#define UNBAKE_SPAN_1000_CODE_802B8DD0_H
#include "types.h"
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


extern void func_802B9A10_de(void);


extern void func_802B9950_de();




extern void func_802B99A4_de(void);

struct OSPiHandle_s;
extern s32 func_802B9590_de(struct OSPiHandle_s *handle, u32 address, u32 *value);
extern s32 func_802B9B20_de(s32 arg0, s32 *arg1);

extern OSPiHandle_s D_801486C0;

#endif
