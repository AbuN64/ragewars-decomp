#ifndef SDK_RDP_DMA_IO_H
#define SDK_RDP_DMA_IO_H
#include "TYPES.H"
#include "COMMON/HARDWARE_IO.H"

/* Uncached RDP DMA registers; every access retains the shared volatile word type. */
#define RDP_DMA_START_REG 0xA4100000U
#define RDP_DMA_END_REG 0xA4100004U
#define RDP_DMA_STATUS_REG 0xA410000CU
#define IO_WRITE_WORD(address, value) (IO_READ_WORD(address) = (u32)(value))
#endif
