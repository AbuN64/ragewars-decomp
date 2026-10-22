
#if defined(VERSION_US_REV1)
/* Creates the three-row request screen and shows its selected row. */
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"


extern struct CourseOptionsScreen *D_800E39C0;

s32 func_8041DFC0_us_rev1(void *arg0) {
    func_8041F2A0_Item *item;
    s32 row;

    { void *memory = func_8025305C_de(0x20); D_800E39C0 = memory; }
    D_800E39C0->handle = arg0;
    D_800E39C0->mode = func_8041B610_de((s32) arg0, 4);
    func_8041B6E8_de((s32) arg0, 0, 0x389);
    func_8041B6E8_de((s32) arg0, 1, 0x389);
    func_8041B6E8_de((s32) arg0, 2, 0x389);
    func_8041B6E8_de((s32) arg0, 3, 0x389);

    item = func_8040EC30_de(arg0, 0x38B);
    item->alpha = 0x8C;
    if (func_802999A0_de(0) == 22) {
        func_8040E8D8_de(item, 0);
    }

    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    item = func_8040EC30_de(arg0, 0x38C);
    D_800E39C0->rows[0] = item;
    item = func_8040EC30_de(arg0, 0x395);
    D_800E39C0->rows[1] = item;
    item = func_8040EC30_de(arg0, 0x396);
    D_800E39C0->rows[2] = item;
    D_800E39C0->step = func_8041EB50_de();

    for (row = 0; row < 3; row++) {
        func_8041E408_de(row);
        item = func_8040EC30_de(D_800E39C0->rows[row], 0x392);
        func_8040E8D8_de(item, 0);
    }

    func_802A2360_de();

    item = func_8040EC30_de(D_800E39C0->rows[D_800E39C0->selection], 0x392);
    func_8040E8D8_de(item, 1);
    return 0;
}
#endif
