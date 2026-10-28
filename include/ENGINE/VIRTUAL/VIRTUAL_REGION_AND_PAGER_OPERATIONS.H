#ifndef ENGINE_VIRTUAL_VIRTUAL_REGION_AND_PAGER_OPERATIONS_H
#define ENGINE_VIRTUAL_VIRTUAL_REGION_AND_PAGER_OPERATIONS_H
#include "COMMON/OWNERRECAT8V2.H"
extern void Vhandler_FreeVirtualRegion(s32 arg0);
extern void Vhandler_GetPagerCounters(struct PagerCounters *arg0);
extern void Vhandler_UpdatePagerStatistics(void);
extern void Vhandler_MapBootstrapAddressRange(void);
#endif
