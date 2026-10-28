#ifndef RESMGR_RESMGR_STREAM_CALLBACKS_H
#define RESMGR_RESMGR_STREAM_CALLBACKS_H
#include "COMMON/INTEGERSTATE14_2.H"
#include "RESMGR/resmgr_stream_io.H"

/* Stream seek callbacks preserve the handle, byte offset and origin, and return status. */
typedef s32 (*ResourceSeekCallback)(s32 handle, s32 offset, s32 origin);
extern s32 XStdio_SeekStream(s32 handle, s32 offset, s32 origin);
extern void XStdio_CloseMemoryStream(void);
extern s32 XStdio_ReadCharacter(s32 arg0);
extern s32 XStdio_OpenMemoryStream(const void *name, const void *mode);
extern void XStdio_LoadMemoryStream(void);
extern void XStdio_SetStreamCallbacks(ResourceOpenCallback arg0, s32 arg1, ResourceReadCallback arg2, s32 arg3, ResourceSeekCallback arg4, void (*arg5)(void), void (*arg6)(void));
extern void XStdio_QueryStreamPosition(void);
extern void XStdio_FreeMemoryStream(void);
extern void XStdio_QueryStreamEnd(void);
#endif
