#ifndef CINEMA_CINEMA_H
#define CINEMA_CINEMA_H
#include "COMMON/GROUP.H"
extern void Cinema_EndSequence(void);
extern void func_8024570C_de(void);
extern int func_80245764_de(void);
extern int func_8024576C_de(void);
extern s32 func_802457E0_de(void);
extern void Cinema_UpdateSequenceTrack(void *camera);
extern unsigned int func_802458E8_de(void);
extern void func_802458F8_de(void);
extern int func_80245908_de(void);
extern int func_80245940_de(void);
extern int func_80245968_de(void);
extern void func_80245990_de(void *letterboxEnabled);
extern void Cinema_SetResponse(float responseValue);
extern void Cinema_ClearResponse(void);
extern void func_80245A20_de(int loopMode);
extern void func_80245A30_de(void);
extern void func_80245A5C_de(int viewportWidth, int viewportHeight, int viewportLeft, int viewportTop);
extern void Cinema_ClearMessageCount(void);
extern float func_80245AD8_de(void);
extern void func_80245B74_de(s32 unused);
extern void func_80245BC0_de(void);
extern void func_80245C38_de(void);
extern int func_80245D14_de(void);
#endif
