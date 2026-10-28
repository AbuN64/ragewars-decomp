#ifndef COMMON_ALFXPARAM_H
#define COMMON_ALFXPARAM_H
#include "TYPES.H"

#include "COMMON/OSTHREAD_S.H"

#if defined(VERSION_US_REV1)
extern const unsigned char D_800C7784_de[];
#else
extern const char D_800C7784_de[];
#endif

extern int alFxParam(int *filter, int paramId, int param);

extern s32 s_sirawreadText;
extern s32 D_800C7A00_de;
extern s32 D_800C7A04_de;

extern s32 D_800C7970_de;
extern s32 s_pirawreadText;


extern s32 D_800C79B0_de;
extern s32 s_sprawdmaText;
#endif
