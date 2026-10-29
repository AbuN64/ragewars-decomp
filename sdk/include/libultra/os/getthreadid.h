#ifndef LIBULTRA_OS_GETTHREADID_H
#define LIBULTRA_OS_GETTHREADID_H
#include "TYPES.H"
struct ThreadIdentifierView {
    char pad0[0x14];
    unsigned int threadId;
};
extern unsigned int osGetThreadId(void *object);
extern int __osGetCurrFaultedThread(void);
#endif
