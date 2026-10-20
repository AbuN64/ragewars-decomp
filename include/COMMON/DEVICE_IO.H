#ifndef COMMON_DEVICE_IO_H
#define COMMON_DEVICE_IO_H
#include "TYPES.H"

#define IO_WRITE(addr, value) (*(volatile u32 *)(addr) = (value))
#endif
