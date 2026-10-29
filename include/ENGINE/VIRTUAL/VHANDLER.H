#ifndef ENGINE_VIRTUAL_VHANDLER_H
#define ENGINE_VIRTUAL_VHANDLER_H
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "ENGINE/VIRTUAL/VIRTUAL_REGION_OWNER_STATE.H"
extern int Vhandler_RecycleTlbSlot(void);
extern void Vhandler_HandleResourcePageRequest(void);
extern void Vhandler_MapResourcePage(s16 flags, ResourcePageMapping *item, s32 unused, u8 *out);
extern void Vhandler_UnmapResourcePage(ResourcePageMapping *mapping);
extern void Virtual_AppendPageChainNode(Field_void_4*pageChain, void*pageNode);
extern void Virtual_PrependPageChainNode(Field_void_4 *, Field_void_4 *);
extern ResourcePageMapping *Virtual_AcquireRecycledPage(void);
extern void Virtual_ReleaseVirtualRegion(VirtualRegionOwnerState *);
extern void Virtual_AssignVirtualRegion(RegionDesc *desc);
#endif
