#ifndef IO_IO_HOSTMEMORY_H
#define IO_IO_HOSTMEMORY_H
#include "TYPES.H"
extern void func_80200F98_de(s32 address, s32 value, u32 count);
extern void func_80201064_de(s32 address, s32 port, s32 count);
extern void func_802010D8_de(u32 mode);
extern void Io_CopyHostBlockToCart(void);
#endif
