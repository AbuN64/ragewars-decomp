#ifndef SDK_LIBGULTRA_H
#define SDK_LIBGULTRA_H

#include "TYPES.H"
extern int func_802AEF84_us_rev1(void);

extern s32 func_802AF544_us_rev1(void);

extern s32 func_802AF6A0_us_rev1(void);

extern void func_802AF990_us_rev1();

extern u32 func_802AFCE4_us_rev1(u8 *arg0, u8 *arg1);

extern int func_802B05C8_us_rev1(void * arg0, int arg1, int arg2, int arg3);

extern u32 func_802B091C_us_rev1(u32 arg0, u32 arg1, u32 arg2);

extern u32 func_802B0D3C_us_rev1(u32 arg0);

extern s32 func_802B1820_us_rev1(u8 *arg0);

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
extern f32 func_802B20D4_de(ObjRecAt18V1 *arg0, s32 arg1, s32 arg2);

extern u32 func_802B2120_de(ObjRecAt18V1 *seq, f32 sec, u32 tempo);

#include "COMMON/PARAMSRECAT8V3.H"
extern void func_802B2780_de(struct ALSndPlayer * arg0, union ALSndpEvent * arg1);

extern s32 func_802B2BBC_de(void *node);

extern s32 func_802B235C_de(ALSeq_s *);
extern const float D_800CC740;
extern s32 func_802B235C_de(struct ALSeq_s *arg0);

extern void func_802B31F0_de(s32 *arg0);

#include "COMMON/ALPARAM_S.H"
extern void func_802B468C_de(AudioLowPassFilter *lp);

extern int __osDpDeviceBusy();

#include "acmd.h"
extern void osViSetYScale(f32 arg0);

extern s32 D_800C7990_de;
extern s32 s_sirawdmaText;

#endif
