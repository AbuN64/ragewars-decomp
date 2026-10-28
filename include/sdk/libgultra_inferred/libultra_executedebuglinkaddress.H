#ifndef SDK_LIBGULTRA_INFERRED_LIBULTRA_EXECUTEDEBUGLINKADDRESS_H
#define SDK_LIBGULTRA_INFERRED_LIBULTRA_EXECUTEDEBUGLINKADDRESS_H
#include "sdk/OBJECTSTATE2.H"
extern s32 Libultra_WaitDebugLinkReceiveReady(u32 arg0);
extern s32 Libultra_WaitDebugLinkAcknowledgement(u32 arg0);
extern void Libultra_SetDebugLinkMode(s32 arg0);
extern void Libultra_SetDebugLinkByteRequest(s32 arg0);
extern void Libultra_SetDebugLinkReceiveEnable(s32 arg0);
extern void Libultra_WritePortByteValue(s16 *arg0, s32 arg1);
extern s32 Libultra_WaitDebugLinkTransmitReady(u32 arg0);
extern s32 Libultra_ReadDebugLinkMemoryByte(void);
extern void Libultra_SetDebugLinkHandshakeBit(s32 arg0);
extern s32 Libultra_WriteDebugLinkMemoryByte(void);
extern s32 Libultra_WaitDebugLinkRequestAcknowledgement(u32 arg0);
extern void Libultra_SetDebugLinkBlockTransfer(s32 arg0);
extern void Libultra_SetDebugLinkTransmitStrobe(s32 arg0);
extern s32 Libultra_WaitPortStatus(u8 *status, u8 mask, u32 arg2, s32 reload);
extern s32 Libultra_HandshakeDebugLink(void);
extern s32 Libultra_ExecuteDebugLinkAddress(void);
extern int func_802B2048_us_rev1(void);
extern s32 Libultra_GetDebugLinkRequestAcknowledgement(void);
extern u8 Libultra_ReadPortStatusByte(void *arg0);
extern void Libultra_SetDebugLinkHostRequest(s32 arg0);
extern s32 Libultra_CheckDebugLinkAcknowledgement(u32 arg0);
extern void Libultra_SetDebugLinkEnable(s32 arg0);
#endif
