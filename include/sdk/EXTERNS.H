#ifndef SDK_EXTERNS_H
#define SDK_EXTERNS_H
#include "TYPES.H"
extern s32 Libc_FormatToCallback(void *(*)(void *, const char *, s32), void *, const char *, char *);
#include "COMMON/ALSEQUENCEPLAYER.H"
/* Divides an integer by a float and truncates toward zero, asserting first if the divisor is
   zero; clamps the result to 0x7FFFFFFF when the quotient would overflow a signed 32-bit int. */

extern char g_soundPlayerAssertText[];
extern char s_audioSndplayerText[];
#endif
