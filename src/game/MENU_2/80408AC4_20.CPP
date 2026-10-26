#include "include_asm.h"

#if defined(VERSION_DE)
typedef struct { s32 owner; void *list; void *w8[3]; void *w14; s32 sel; s32 unk1C; } Func_8041DF50_State;
extern Func_8041DF50_State *D_800E39C0;
extern void *Cache_AllocateMemory(s32);
extern void *SmpOverlay_CreateOverlayNode(s32, s32);
extern void SmpOverlay_ShowSlotById(s32, s32, s32);
extern u8 *Frontend_FindWidgetByResourceId(s32, s32);
extern s32 func_802999A0_de(s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void *Frontend_CountUsedSlots(void);
extern void Tsmos_ActivateControllerState(void);
extern void Frontend_UpdateJoinRequestDisplay(s32);
/* Opens the 0x20-byte screen state D_800E39C0 for owner arg0: a four-row list, the widgets 0x385, 0x386, 0x38F, 0x390 and three 0x38C rows (shown one by one through Frontend_UpdateJoinRequestDisplay); returns zero. */
s32 Menu_CreateGermanCourseOptions(s32 owner) {
    u8 *widget;
    s32 i;
    D_800E39C0 = (Func_8041DF50_State *)Cache_AllocateMemory(0x20);
    D_800E39C0->owner = owner;
    D_800E39C0->list = SmpOverlay_CreateOverlayNode(owner, 4);
    SmpOverlay_ShowSlotById(owner, 0, 0x383);
    SmpOverlay_ShowSlotById(owner, 1, 0x383);
    SmpOverlay_ShowSlotById(owner, 2, 0x383);
    SmpOverlay_ShowSlotById(owner, 3, 0x383);
    widget = Frontend_FindWidgetByResourceId(owner, 0x385);
    widget[0x10] = 0x8C;
    if (func_802999A0_de(0) == 0x16) {
        Frontend_SetWidgetFlag08(widget, 0);
    }
    D_800E39C0->sel = 0;
    D_800E39C0->w14 = 0;
    D_800E39C0->w8[0] = Frontend_FindWidgetByResourceId(owner, 0x386);
    D_800E39C0->w8[1] = Frontend_FindWidgetByResourceId(owner, 0x38F);
    D_800E39C0->w8[2] = Frontend_FindWidgetByResourceId(owner, 0x390);
    D_800E39C0->unk1C = (s32)Frontend_CountUsedSlots();
    for (i = 0; i < 3; ) {
        Frontend_UpdateJoinRequestDisplay(i);
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId((s32)D_800E39C0->w8[i], 0x38C), 0);
        i++;
    }
    Tsmos_ActivateControllerState();
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId((s32)D_800E39C0->w8[(s32)D_800E39C0->w14], 0x38C), 1);
    return 0;
}
#endif
