#ifndef SDK_LIBULTRA_PFS_PFS_H
#define SDK_LIBULTRA_PFS_PFS_H
#include "COMMON/OBJECTSTATE96.H"
#include "TYPES.H"
extern s32 __osCheckPackId(OSPfs*pfs, __OSPackId*temp);
extern s32 __osRepairPackId(OSPfs*pfs, __OSPackId*badid, __OSPackId*newid);
#endif
