#ifndef SDK_EXTERNS_H
#define SDK_EXTERNS_H
#include "TYPES.H"
extern s32 Libc_FormatToCallback(void *(*)(void *, const char *, s32), void *, const char *, char *);
#endif
