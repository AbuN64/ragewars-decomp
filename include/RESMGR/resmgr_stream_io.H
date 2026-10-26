#ifndef RESMGR_802A0888_8_H
#define RESMGR_802A0888_8_H
#include "COMMON/INTEGERSTATE14_2.H"

/* An open callback consumes the name and mode byte strings and returns a stream handle. */
typedef s32 (*ResourceOpenCallback)(const void *name, const void *mode);
extern s32 XStdio_OpenStream(const void *name, const void *mode);
extern void XStdio_InitializeStreams();
extern void XStdio_ShutdownStreams();
extern s32 XStdio_ReadStream(void *arg0, s32 arg1, s32 arg2, s32 arg3);
typedef s32 (*ResourceReadCallback)(s32 handle, void *destination, s32 bytes);
#endif
