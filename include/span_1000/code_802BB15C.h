#ifndef UNBAKE_SPAN_1000_CODE_802BB15C_H
#define UNBAKE_SPAN_1000_CODE_802BB15C_H
#include "types.h"

extern char D_800CCC30[];
extern int D_8000030C;

extern void func_802BAE40_de();

extern int func_802BB060_de(unsigned int devAddr, unsigned int * data);

struct Thread;
struct Thread {
    char pad0[0x10];
    u16 state;
};

struct Queue_func_802BB2A0_de;
typedef struct Queue_func_802BB2A0_de Queue_func_802BB2A0_de;

extern int func_802BB0F0_de(unsigned int devAddr, unsigned int data);

struct OSThread_s_func_802BB5F0_de;
typedef struct OSThread_s_func_802BB5F0_de OSThread_s_func_802BB5F0_de;

struct OSThread_s_func_802BB5F0_de;
struct OSThread_s_func_802BB5F0_de {
    struct OSThread_s_func_802BB5F0_de *next;
    s32 priority;
    struct OSThread_s_func_802BB5F0_de **queue;
    struct OSThread_s_func_802BB5F0_de *tlnext;
    u16 state;
};

extern void func_802BB850_eu(s32 arg0);

struct Thread;
typedef struct Thread Thread;

extern void func_802BB3D0_de(s32 arg0);

struct Queue_func_802BB2A0_de;
struct Queue_func_802BB2A0_de {
    void *mtqueue;
    void *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
};

#endif
