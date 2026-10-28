#ifndef RESMGR_X_PLUS_H
#define RESMGR_X_PLUS_H
#include "COMMON/MESSAGESEMAPHORE.H"
extern void XPlus_PartitionSortRange(char *base, char *max);
extern void XPlus_SortArray(char *base, s32 n, s32 size, s32 (*compare)(char *a, char *b));
extern void XPlus_SplitPath(u8 *path, u8 *drive, u8 *dir, u8 *name, u8 *ext);
extern void * XPlus_FillMemory(void *arg0, int arg1, u32 arg2);
#endif
