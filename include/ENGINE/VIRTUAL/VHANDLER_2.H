#ifndef ENGINE_VIRTUAL_VHANDLER_2_H
#define ENGINE_VIRTUAL_VHANDLER_2_H
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "ENGINE/VIRTUAL/VHANDLER_5.H"
extern int Virtual_RecycleTlbSlot();
extern void Virtual_HandleResourcePageRequest(void);
extern void Virtual_MapResourcePage(s16 flags, ResourcePageMapping *item, s32 unused, u8 *out);
extern void Virtual_UnmapResourcePage(ResourcePageMapping *mapping);
extern void Virtual_AppendPageChainNode(Field_void_4*arg0, void*arg1);
extern void Virtual_PrependPageChainNode(Field_void_4 *, Field_void_4 *);
extern ResourcePageMapping *Virtual_AcquireRecycledPage(void);
extern void Virtual_ReleaseVirtualRegion(OwnerRecAt8V2 *);
extern void Virtual_AssignVirtualRegion(RegionDesc *desc);
#endif
