#ifndef AUDIO_4_802BFE60_H
#define AUDIO_4_802BFE60_H
#include "TYPES.H"
struct func_80205494_S3 {
    char pad0[0x14];
    unsigned int unk14;
};
extern unsigned int Audio_GetThreadIdentifier(void *object);
extern int Audio_GetInterruptMask(void);
#endif
