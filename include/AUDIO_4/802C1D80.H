#ifndef AUDIO_4_802C1D80_H
#define AUDIO_4_802C1D80_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CTX.H"
/* Disk transfer state embedded at offset 0x14 in the PI device handle. */
typedef struct DiskTransferInfo {
    u16 command;
    u16 mode;
    u32 block;
    s32 sector;
    u32 deviceAddress;
    u32 bmControl;
} DiskTransferInfo;
extern void func_802BCC90_de();
extern void func_802BCD64_de();
#endif
