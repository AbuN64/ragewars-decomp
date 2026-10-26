#ifndef IO_IO_HOSTMEMORY_H
#define IO_IO_HOSTMEMORY_H
#include "TYPES.H"
extern void Libsn_FillPortBytes(s32 address, s32 value, u32 count);
extern void Libsn_CopyPortBytes(s32 address, s32 port, s32 count);
extern void Libsn_TransferHostMemoryRanges(u32 mode);
extern void Libsn_CopyHostBlockToCart(void);
#endif
