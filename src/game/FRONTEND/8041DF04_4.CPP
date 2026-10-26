
#if defined(VERSION_US_REV1)
/* Creates the three-row request screen and shows its selected row. */
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"


extern struct CourseOptionsScreen *D_800E39C0;

s32 Frontend_CreateCourseOptionsMenu(void *root) {
    func_8041F2A0_Item *item;
    s32 row;

    { void *memory = Cache_AllocateMemory(0x20); D_800E39C0 = memory; }
    D_800E39C0->handle = root;
    D_800E39C0->mode = SmpOverlay_CreateOverlayNode((s32) root, 4);
    SmpOverlay_ShowSlotById((s32) root, 0, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 1, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 2, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 3, 0x389);

    item = func_8040EC30_de(root, 0x38B);
    item->alpha = 0x8C;
    if (func_802999A0_de(0) == 22) {
        Frontend_SetWidgetFlag08(item, 0);
    }

    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    item = func_8040EC30_de(root, 0x38C);
    D_800E39C0->rows[0] = item;
    item = func_8040EC30_de(root, 0x395);
    D_800E39C0->rows[1] = item;
    item = func_8040EC30_de(root, 0x396);
    D_800E39C0->rows[2] = item;
    D_800E39C0->step = Frontend_CountUsedSlots();

    for (row = 0; row < 3; row++) {
        func_8041E408_de(row);
        item = func_8040EC30_de(D_800E39C0->rows[row], 0x392);
        Frontend_SetWidgetFlag08(item, 0);
    }

    func_802A2360_de();

    item = func_8040EC30_de(D_800E39C0->rows[D_800E39C0->selection], 0x392);
    Frontend_SetWidgetFlag08(item, 1);
    return 0;
}
#endif
