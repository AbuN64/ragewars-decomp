#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "TYPES.H"
typedef struct EuxDrawScreen { void *window; s32 unk4; void *roots[3]; s32 unk14; s32 unk18; s32 count; } EuxDrawScreen;
typedef struct { u8 pad0[0x10]; u8 alpha; } EuxDrawItem;
extern EuxDrawScreen *D_800E39C0;
extern void *Cache_AllocateMemory(s32);
extern s32 SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern void *Node_FindWidgetByResourceId(void *, s32);
extern void Widget_SetWidgetFlag08(void *, s32);
extern s32 Menu_GetPreviousScreenOwner(s32);
extern s32 Join_CountUsedSlots(void);
extern void Join_UpdateJoinRequestDisplay(s32);
extern void Tsmos_ActivateControllerState(void);
/* Builds the pak-draw selection screen: allocates its 0x20-byte state, creates the four rows, hides the pointer item
   when the pad answer is 0x16, collects the three root items and hides their cursors, then shows the cursor of the
   current root. Returns 0. */
s32 Menu_CreateEuxJoinOptions(void *window) {
    EuxDrawScreen *screen;
    EuxDrawItem *item;
    s32 i;

    screen = Cache_AllocateMemory(0x20);
    D_800E39C0 = screen;
    screen->window = window;
    D_800E39C0->unk4 = SmpOverlay_CreateOverlayNode(window, 4);
    SmpOverlay_ShowSlotById(window, 0, 0x38D);
    SmpOverlay_ShowSlotById(window, 1, 0x38D);
    SmpOverlay_ShowSlotById(window, 2, 0x38D);
    SmpOverlay_ShowSlotById(window, 3, 0x38D);
    item = Node_FindWidgetByResourceId(window, 0x38F);
    item->alpha = 0x8C;
    if (Menu_GetPreviousScreenOwner(0) == 0x16) {
        Widget_SetWidgetFlag08(item, 0);
    }
    D_800E39C0->unk18 = 0;
    D_800E39C0->unk14 = 0;
    D_800E39C0->roots[0] = Node_FindWidgetByResourceId(window, 0x390);
    D_800E39C0->roots[1] = Node_FindWidgetByResourceId(window, 0x399);
    D_800E39C0->roots[2] = Node_FindWidgetByResourceId(window, 0x39A);
    D_800E39C0->count = Join_CountUsedSlots();
    for (i = 0; i < 3; i++) {
        Join_UpdateJoinRequestDisplay(i);
        Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(D_800E39C0->roots[i], 0x396), 0);
    }
    Tsmos_ActivateControllerState();
    Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(D_800E39C0->roots[D_800E39C0->unk14], 0x396), 1);
    return 0;
}
#endif
