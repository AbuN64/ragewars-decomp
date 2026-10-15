#include "span_1000/code_8025A3EC.h"
#include "span_16E000/code_8043962C.h"
#include "common/unused.h"
#include "shared/func_80286080_de_closed.h"
#include "shared/gameplay_movement.h"
#include "common/data.h"
#include "span_1000/code_8021CD70.h"
#include "shared/func_8021E2A0_de_closed.h"

void func_8021E2A0_de(SharedPlayer *player, void *view) {
    s32 icon;
    s32 show;
    f32 scale;

    player->views5E8.view7BC_102.timer += D_800D2988;
    if (player->views5E8.view788_94.icons == 0) {
        return;
    }
    if (player->views5D8.view5D8_9.profile->remote == 1 && D_801468F4 != 0) {
        return;
    }
    if (player->views5E8.view650_17.action == 0x27) {
        return;
    }
    if (player->views1C.view594_40.mode == 2 && player->views5E8.view62E_14.weapon == 3) {
        return;
    }
    if (func_802A23B4_de() != 0) {
        return;
    }
    if (player->views5E8.view798_96.carried == 0x2DA) {
        if (player->views1C.view594_40.mode == 1) {
            if (player->views1C.viewE4_7.kind != D_800CE474[0] && player->views1C.viewE4_7.kind != D_800CE474[1]) {
                player->views5E8.view798_96.carried = 0x2EF;
                if ((u8) player->views1C.view48C_35.state - 2U < 2) {
                    player->views5E8.view7BC_102.timer = 0.0f;
                } else if (player->views1C.view523_37.busy != 0) {
                    player->views5E8.view7BC_102.timer = 0.0f;
                } else {
                    player->views5E8.view7BC_102.timer = 1.0f;
                }
            }
        } else if (player->views1C.viewE4_7.kind != D_800CE474[0] && player->views1C.viewE4_7.kind != D_800CE474[1]) {
            player->views5E8.view798_96.carried = 0x2F1;
            if (player->views5E8.view62E_14.weapon == 9 && player->views1C.view5A0_42.charge > 0.0f) {
                player->views5E8.view7BC_102.timer = 1.0f;
            } else if (player->views1C.view48C_35.state == 0xB || player->views1C.view48C_35.state == 3 || player->views1C.view48C_35.state == 2) {
                player->views5E8.view7BC_102.timer = 0.0f;
            } else if (player->views1C.view523_37.busy != 0) {
                player->views5E8.view7BC_102.timer = 0.0f;
            } else {
                player->views5E8.view7BC_102.timer = 1.0f;
            }
        } else {
            player->views5E8.view798_96.carried = 0x302;
            player->views5E8.view7BC_102.timer = 0.0f;
        }
    }
    func_802A9234_de(0xFF);

    icon = player->views5E8.view7B8_100.target;
    show = 1;
    if (icon == 0x2DA && D_801462E5 != 0) {
        show = D_80142233;
    }
    if (icon != -1) {
        switch (icon) {
        case 0x2DA:
        case 0x2EF:
        case 0x2F0:
            scale = 8.0f;
            break;
        case 0x2BC:
        case 0x2E4:
        case 0x2F1:
        case 0x2F2:
        case 0x302:
        case 0x320:
        case 0x32A:
        case 0x32B:
        case 0x35C:
        case 0x35D:
            scale = 32.0f;
            break;
        default:
            scale = 16.0f;
            break;
        }
        if (show) {
            func_8021E08C_de(view, &player->views5E8.view7C0_104.targetPosition, icon, player->views5E8.view7BC_102.timer, scale, 1.0f);
        }
    }

    icon = player->views5E8.view798_96.carried;
    show = 1;
    if (icon == 0x2DA && D_801462E5 != 0) {
        show = D_80142233;
    }
    if (icon != -1) {
        switch (icon) {
        case 0x2DA:
        case 0x2EF:
        case 0x2F0:
            scale = 8.0f;
            break;
        case 0x2BC:
        case 0x2E4:
        case 0x2F1:
        case 0x2F2:
        case 0x302:
        case 0x320:
            scale = 32.0f;
            break;
        case 0x2F3:
        case 0x2F4:
        default:
            scale = 16.0f;
            break;
        }
        if (show) {
            func_8021E08C_de(view, &player->views5E8.view79C_98.carriedPosition, icon, player->views5E8.view7BC_102.timer, scale, 1.0f);
        }
    }
}
