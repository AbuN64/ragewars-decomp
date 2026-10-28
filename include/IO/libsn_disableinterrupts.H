#ifndef IO_80200568_H
#define IO_80200568_H
#include "TYPES.H"
extern void Libsn_RestoreInterruptEnable(s32 saved);
extern int Libsn_DisableInterrupts();
extern void Libsn_WritePortWord(s32 address, s32 value);
#endif
