#ifndef RESMGR_802A0888_4_H
#define RESMGR_802A0888_4_H
#include "COMMON/MESSAGESEMAPHORE.H"
extern s32 func_802A03F4_de(u8 *arg0, u8 *arg1);
extern u8 *func_802A0294_de(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_802A01D8_de(int arg0);
extern int func_802A05B8_de(int arg0);
extern u8 *func_802A07DC_de(u8 *arg0, s32 arg1, s32 arg2);
extern void func_802A0960_de(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern u32 func_802A08B8_de(u8 *arg0, u32 arg1, u32 arg2);
extern u8 *func_802A0324_de(u8 *destination, u8 *source, s32 count);
extern void func_802A066C_de(s32 n, char *s);
extern u8 *func_802A0444_de(u8 *s, int c);
extern s32 func_802A0814_de(u8 *arg0, u8 *arg1, s32 arg2);
extern void *func_802A0748_de(void *arg0, int arg1, u32 arg2);
extern void *Resmgr_CopyBytes(void *destination, const void *source, s32 bytes);
#endif
