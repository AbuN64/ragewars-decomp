#ifndef SDK_AUDIO_SPRINTF_H
#define SDK_AUDIO_SPRINTF_H
#include "TYPES.H"
/* sprintf: formats into buffer and returns the length written. */
extern s32 Libc_FormatString(char *buffer, const char *format, ...);
#endif
