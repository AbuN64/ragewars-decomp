#ifndef LIBULTRA_OS_INITIALIZE_H
#define LIBULTRA_OS_INITIALIZE_H
#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"

extern void osInitialize(void);
extern int __osSiRawReadIo(unsigned int devAddr, unsigned int * data);
extern int __osSiRawWriteIo(unsigned int devAddr, unsigned int data);
#endif
