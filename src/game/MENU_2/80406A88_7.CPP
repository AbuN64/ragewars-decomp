#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define func_804235A8_eu func_804235E0_eu_x
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_5.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER_2/8025DE50_5.H"
s32 func_804235A8_eu(void) {
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 pages;
    s32 var_v0;
    MenuWidget *temp_a0;
    MenuWidget *temp_a0_2;
    MenuWidget *temp_a0_3;
    MenuWidget *temp_a0_4;
    Shared_OptionsScreen *timer;
    Shared_OptionsScreen *finish;
    s32 *ready;

    if (D_800E28E0 <= 0) {
        if ((func_8043C308_de(D_800E4518) != 1) && ((((Shared_OptionsScreen *)(D_800E4518))->state) == 0)) {
            (((Shared_OptionsScreen *)(D_800E4518))->state) = 1;
            func_802A2360_de();
            return 0;
        }
        temp_s0 = D_800E2830->state3C;
        if ((temp_s0 == 1) && (func_80245798_de() == temp_s0)) {
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->prompt), 0);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->footer), 0);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->rumbleIcon), 0);
            D_800E2830->state3C = 0;
        }
        ready = &D_80154020.ready;
        if (*ready == 1) {
            *ready = 0;
            if (D_80154020.value != -1) {
                func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 0);
                func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->header), 0);
                MarkMenuEventHandled();
                func_80298368_de(D_80154020.value);
                return 0;
            }
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 1);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->header), 1);
            func_802991D4_de(0x37D);
            goto block_11;
        }
block_11:
        temp_v0 = (((Shared_OptionsScreen *)(D_800E4518))->page);
        switch (temp_v0) {
        case 1:
            temp_a0 = (((Shared_OptionsScreen *)(D_800E4518))->leftTab);
            temp_a0->x = (u16) (temp_a0->x + (u16)(((Shared_OptionsScreen *)(D_800E4518))->leftStep));
            temp_a0_2 = (((Shared_OptionsScreen *)(D_800E4518))->rightTab);
            temp_a0_2->x = (u16) (temp_a0_2->x - (u16)(((Shared_OptionsScreen *)(D_800E4518))->rightStep));
            temp_v0_2 = (((Shared_OptionsScreen *)(D_800E4518))->pages) - 1;
            (((Shared_OptionsScreen *)(D_800E4518))->pages) = temp_v0_2;
            if (temp_v0_2 <= 0) {
                func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->marker), 1);
                func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 1);
                func_80419F58_de((((Shared_OptionsScreen *)(D_800E4518))->title), 4);
                finish = (Shared_OptionsScreen *)D_800E4518;
                finish->page = 4;
                finish->pages = 4;
            }
        case 3:
        default:
            break;
        case 2:
            temp_a0_3 = (((Shared_OptionsScreen *)(D_800E4518))->leftTab);
            temp_a0_3->x = (u16) (temp_a0_3->x - (u16)(((Shared_OptionsScreen *)(D_800E4518))->leftStep));
            temp_a0_4 = (((Shared_OptionsScreen *)(D_800E4518))->rightTab);
            temp_a0_4->x = (u16) (temp_a0_4->x + (u16)(((Shared_OptionsScreen *)(D_800E4518))->rightStep));
            temp_v0_3 = (((Shared_OptionsScreen *)(D_800E4518))->pages) - 1;
            (((Shared_OptionsScreen *)(D_800E4518))->pages) = temp_v0_3;
            if (temp_v0_3 <= 0) {
                D_80145040.pause = 0;
                (((Shared_OptionsScreen *)(D_800E4518))->page) = 3;
                Items_ResetActorPools(&D_80145040.object, 0);
                func_804499B0_de(&D_80145040, 0, 0);
                func_80286AA8_de(&D_8011FE88, 0, 0);
                if (func_8025477C_de() == 0) {
                    func_8025476C_de(1U);
                }
                D_80145040.stage = 8;
                MarkMenuEventHandled();
                func_80298368_de((((Shared_OptionsScreen *)(D_800E4518))->selection));
                return 0;
            }
            break;
        case 4:
            timer = (Shared_OptionsScreen *)D_800E4518;
            pages = timer->pages;
            temp_v0_4 = pages - 1;
            if (temp_v0_4 >= 0) {
                var_v0 = pages - (pages >= temp_v0_4);
            } else {
                var_v0 = 0;
            }
            timer->pages = var_v0;
            if (((((Shared_OptionsScreen *)(D_800E4518))->pages) <= 0) && (func_80419F38_de((((Shared_OptionsScreen *)(D_800E4518))->title)) != 0)) {
                func_80419F24_de((((Shared_OptionsScreen *)(D_800E4518))->title));
                (((Shared_OptionsScreen *)(D_800E4518))->page) = 3;
            }
            break;
        case 5:
            func_8025DF34_de(0xE78);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->marker), 0);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 0);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->footer), 1);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->rumbleIcon), 1);
            func_8040E8D8_de((((Shared_OptionsScreen *)(D_800E4518))->prompt), 1);
            finish = (Shared_OptionsScreen *)D_800E4518;
            finish->page = 2;
            finish->pages = 4;
            break;
        }
        if ((((Shared_OptionsScreen *)(D_800E4518))->page) != 3) {
            return 0;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804235E0_eu_x);
#endif
#endif
