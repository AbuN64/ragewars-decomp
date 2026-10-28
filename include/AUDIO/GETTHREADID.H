#ifndef AUDIO_GETTHREADID_H
#define AUDIO_GETTHREADID_H
#include "TYPES.H"
struct func_80205494_S3 {
    char pad0[0x14];
    unsigned int unk14;
};
extern unsigned int Audio_GetThreadIdentifier(void *object);
extern int Audio_GetInterruptMask(void);
#endif
