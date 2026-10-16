#ifndef RAGEWARS_DEVICE_IO_H
#define RAGEWARS_DEVICE_IO_H
#include "TYPES.H"

#define IO_WRITE(addr, value) (*(volatile u32 *)(addr) = (value))

#endif
