#ifndef AUDIO_SIRAWWRITE_H
#define AUDIO_SIRAWWRITE_H
#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/EXTERNS_18.H"

extern void Audio_InitializeOperatingSystem(void);
extern int Audio_ReadSerialInterfaceWord(unsigned int devAddr, unsigned int * data);
extern int Audio_WriteSerialInterfaceWord(unsigned int devAddr, unsigned int data);
#endif
