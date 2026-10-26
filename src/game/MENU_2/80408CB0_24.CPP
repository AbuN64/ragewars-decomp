#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/REQUESTRECAT10.H"
extern struct CourseOptionsScreen *D_800E39C0;
extern void *Cache_AllocateMemory(s32);
extern s32 SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(MenuWidget *, s32);
extern void Tsmos_ActivateControllerState(void);

s32 Menu_CreateEuJoinOptions(void *handle) {
    MenuWidget *widget;
    s32 i;
    D_800E39C0 = Cache_AllocateMemory(0x20);
    D_800E39C0->handle = handle;
    D_800E39C0->mode = SmpOverlay_CreateOverlayNode(handle, 4);
    SmpOverlay_ShowSlotById(handle, 0, 0x389);
    SmpOverlay_ShowSlotById(handle, 1, 0x389);
    SmpOverlay_ShowSlotById(handle, 2, 0x389);
    SmpOverlay_ShowSlotById(handle, 3, 0x389);
    widget = Frontend_FindWidgetByResourceId(handle, 0x38B);
    widget->alpha = 0x8C;
    if (Smos_GetPreviousScreenOwner(0) == 0x16) {
        Frontend_SetWidgetFlag08(widget, 0);
    }
    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    D_800E39C0->rows[0] = Frontend_FindWidgetByResourceId(handle, 0x38C);
    D_800E39C0->rows[1] = Frontend_FindWidgetByResourceId(handle, 0x395);
    D_800E39C0->rows[2] = Frontend_FindWidgetByResourceId(handle, 0x396);
    D_800E39C0->step = Frontend_CountUsedSlots();
    for (i = 0; i < 3; i++) {
        Frontend_UpdateJoinRequestDisplay(i);
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E39C0->rows[i], 0x392), 0);
    }
    Tsmos_ActivateControllerState();
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x392), 1);
    return 0;
}
#endif
