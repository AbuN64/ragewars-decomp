#ifndef SDK_LIBGULTRA_INFERRED_802AE260_8_H
#define SDK_LIBGULTRA_INFERRED_802AE260_8_H
#include "COMMON/RESPONSE.H"
extern s32 Libultra_SendDebugLinkWord(u32 arg0);
extern s32 Libultra_ReceiveDebugLinkWord(s32 *arg0);
extern void func_802B1554_us_rev1(void);
extern s32 Libultra_SendDebugLinkHalfword(u32 arg0);
extern s32 Libultra_ReceiveDebugLinkString(u8 *arg0, s32 arg1);
extern s32 Libultra_ReceiveDebugLinkHalfword(u16 *arg0);
extern void Libultra_SetDebugLinkCallback(int arg0);
#endif
