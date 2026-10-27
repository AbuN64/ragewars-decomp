#ifndef SDK_LIBGULTRA_H
#define SDK_LIBGULTRA_H

#include "TYPES.H"
extern int Libultra_SendDebugLinkIdentification(void);

extern s32 Libultra_ReceiveDebugLinkMemory(void);

extern s32 Libultra_SendDebugLinkMemory(void);

extern void Libultra_RunDebugLinkCommands();

extern u32 Libultra_ExchangeDebugLinkStrings(u8 *arg0, u8 *arg1);

extern int Libultra_SubmitDebugLinkBlock(void * arg0, int arg1, int arg2, int arg3);

extern u32 Libultra_ExchangeDebugLinkWords(u32 arg0, u32 arg1, u32 arg2);

extern u32 Libultra_ExchangeDebugLinkWord(u32 arg0);

extern s32 Libultra_SendDebugLinkString(u8 *arg0);

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
extern f32 alSeqTicksToSec(ObjRecAt18V1 *arg0, s32 arg1, s32 arg2);

extern u32 alSeqSecToTicks(ObjRecAt18V1 *seq, f32 sec, u32 tempo);

#include "COMMON/PARAMSRECAT8V3.H"
extern void func_802B2780_de(struct ALSndPlayer * arg0, union ALSndpEvent * arg1);

extern s32 func_802B2BBC_de(void *node);

extern s32 readVarLen(ALSeq_s *);
extern const float D_800CC740;
extern s32 readVarLen(struct ALSeq_s *arg0);

extern void func_802B31F0_de(s32 *arg0);

#include "COMMON/ALPARAM_S.H"
extern void func_802B468C_de(AudioLowPassFilter *lp);

extern int __osDpDeviceBusy();

#include "acmd.h"
extern void osViSetYScale(f32 arg0);

extern s32 D_800C7990_de;
extern s32 s_sirawdmaText;

#endif
