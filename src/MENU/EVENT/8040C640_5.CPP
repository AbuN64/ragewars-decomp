#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER_2/8025DE50_5.H"
extern struct CourseOptionsScreen *D_800E39C0;

s32 func_8041DFC0_us(void *arg0) {
    MenuWidget *item;
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

#if defined(VERSION_US)
#include "COMMON/ITEMRECAT20V1.H"
extern struct TextEntry D_800E381C[][17];
extern struct RequestRecAt10 D_80153F80[];
extern void func_8029973C_de(void);
extern s32 func_802999A0_de(s32);
extern s32 func_8041EC44_de(s32, s32);
extern void func_802A025C_de(char *, char *);
extern void func_8041E408_de(s32);

s32 func_8041E170_us(void *sender, void *context, void *argument, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) return 0;
    func_8029973C_de();
    if (func_802999A0_de(0) == 0x16) return 0;
    variant = D_80153F80[D_800E39C0->selection].variant;
    model = func_8041EC44_de(variant, D_80153F80[D_800E39C0->selection].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) model = 16;
        }
        id = D_800E381C[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->selection].variant = variant;
    D_80153F80[D_800E39C0->selection].id = id;
    func_802A025C_de(D_80153F80[D_800E39C0->selection].name,
                    *D_800E381C[variant][id].text);
    D_80153F80[D_800E39C0->selection].variantC = variant;
    func_8041E408_de(D_800E39C0->selection);
    func_8025DF34_de(0xE81);
    return 0;
}
#endif

#if defined(VERSION_US)
INCLUDE_ASM("ovl_80400000", func_8041E2F0_us);
#endif
