#ifndef RESMGR_802A0888_9_H
#define RESMGR_802A0888_9_H
#include "COMMON/INTEGERSTATE14_2.H"

/* Stream seek callbacks preserve the handle, byte offset and origin, and return status. */
typedef s32 (*ResourceSeekCallback)(s32 handle, s32 offset, s32 origin);
extern s32 Resmgr_SeekStream(s32 handle, s32 offset, s32 origin);
extern void func_802A1188_de(void);
extern s32 func_802A0FCC_de(s32 arg0);
extern void func_802A1158_de(void *arg0, u8 *arg1);
extern void func_802A109C_de(void);
extern void func_802A1050_de(s32 arg0, s32 arg1, s32 (*arg2)(s32, u8 *, s32), s32 arg3, ResourceSeekCallback arg4, void (*arg5)(void), void (*arg6)(void));
extern void func_802A0F84_de(void);
extern void func_802A1114_de(void);
extern void func_802A0FA8_de(void);
#endif
