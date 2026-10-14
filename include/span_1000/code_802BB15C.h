#ifndef UNBAKE_SPAN_1000_CODE_802BB15C_H
#define UNBAKE_SPAN_1000_CODE_802BB15C_H
#include "types.h"
#include "span_1000/code_802BAC58.h"
#include "span_1000/code_802B7B80.h"

extern char D_800CCC30[];
extern int D_8000030C;

extern void func_802BAE40_de();

extern int func_802BB060_de(unsigned int devAddr, unsigned int * data);


struct OSMesgQueue;

extern s32 func_802BB2A0_de(OSMesgQueue *queue, void **message, s32 block);

extern int func_802BB0F0_de(unsigned int devAddr, unsigned int data);



extern void func_802BB850_eu(s32 arg0);


extern void func_802BB3D0_de(s32 arg0);


#endif
