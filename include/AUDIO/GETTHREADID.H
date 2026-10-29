#ifndef AUDIO_GETTHREADID_H
#define AUDIO_GETTHREADID_H
#include "TYPES.H"
struct ThreadIdentifierView {
    char pad0[0x14];
    unsigned int threadId;
};
extern unsigned int Audio_GetThreadIdentifier(void *object);
extern int Audio_GetInterruptMask(void);
#endif
