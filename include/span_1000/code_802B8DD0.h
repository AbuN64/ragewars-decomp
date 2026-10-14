#ifndef UNBAKE_SPAN_1000_CODE_802B8DD0_H
#define UNBAKE_SPAN_1000_CODE_802B8DD0_H
#include "types.h"
#include "types.h"
struct DeviceState;
struct DeviceState {
    struct DeviceState *previous;
    u8 type;
    u8 latency;
    u8 page_size;
    u8 release;
    u8 pulse;
    u8 domain;
    u8 pad_A[2];
    u32 address;
    u32 queue;
};

struct DeviceState;
typedef struct DeviceState DeviceState;

extern void func_802B9A10_de(void);

struct PiTransfer802BE820;
typedef struct PiTransfer802BE820 PiTransfer802BE820;

extern void func_802B9950_de();

struct PiTransfer802BE820;
struct PiTransfer802BE820 {
    u8 pad0[5];
    u8 field5;
    u8 field6;
    u8 field7;
    u8 field8;
    u8 index;
    u8 padA[2];
    u32 address;
};

struct OSPiHandle_s_func_802B93B0_de;
typedef struct OSPiHandle_s_func_802B93B0_de OSPiHandle_s_func_802B93B0_de;

struct OSPiHandle_s_func_802B93B0_de;
struct OSPiHandle_s_func_802B93B0_de {
    struct OSPiHandle_s_func_802B93B0_de *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
};

extern void func_802B99A4_de(void);

struct OSPiHandle_s;
extern s32 func_802B9590_de(struct OSPiHandle_s *handle, u32 address, u32 *value);
extern s32 func_802B9B20_de(s32 arg0, s32 *arg1);

typedef struct PiDevice {
    DeviceState state;
    u8 transfer[0x60];
} PiDevice;
extern PiDevice D_801486C0;

#endif
