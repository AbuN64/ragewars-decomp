#include "include_asm.h"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/EXTERNS_6.H"

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

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C259C_de, D_800C25A0_de, D_800C25A4_de, D_800C25A8_de, D_800C25AC_de, D_800C76A0;
extern f32 D_800C25B4_de, D_800C25B8_de, D_800C25BC_de, D_800C25C0_de;
extern char D_auto_rodata_unresolved_800CE410[], D_800C91C8_de[], D_auto_800CE420[], D_800C91D8_de[];
extern void *func_80268C1C_de(void *, void *);
extern void func_8024BC94_de(CVector3 *, void *, f32, f32, f32);
extern s32 func_802744D4_de(void);
/* Fills in one light record of a player: places it at the player's position (offset by the vector from
 * func_8024BC94_de) with the record's flag at 0x16 set, its position as shorts at 0x10..0x14 and its radius
 * (0xC) from the given constants. */
static void placePlayerLight(void *player, void *light, f32 offsetY, f32 heightScale, f32 radius) {
    CVector3 position;
    func_8024BC94_de(&position, player, 0.0f, 0.0f, offsetY);
    func_80271F34_de(&position, &position, (char *)player + 8);
    FIELD(s16, light, 0x16) = 1;
    FIELD(s16, light, 0x10) = (s16)position.x;
    FIELD(s16, light, 0x12) = (s16)(position.y + Particle_GetActorHeight(player) * heightScale);
    FIELD(f32, light, 0xC) = radius;
    FIELD(s16, light, 0x14) = (s16)position.z;
}
/* Keeps the three light records of a player's effect (0x67C, 0x680, 0x684) in step with its timer at 0x678:
 * allocates and places the two flickering lights while the timer runs, flickers their flag with a random
 * roll once the timer is low, releases them when it is zero, and handles the third light that follows the
 * 0x4000 game flag and toggles its table with button 0x20. */
void func_8021E5F8_de(void *player) {
    void *light;
    s32 flicker;
    s32 roll;
    if (FIELD(u32, &D_801462C8, 0) & 0x4000) {
        FIELD(f32, player, 0x678) = 0.0f;
    } else if (FIELD(void *, player, 0x684) != 0) {
        func_80268C7C_de(&D_8013B1A8, (s32)FIELD(void *, player, 0x684));
        FIELD(void *, player, 0x684) = 0;
    }
    if (FIELD(f32, player, 0x678) != 0.0f) {
        light = FIELD(void *, player, 0x67C);
        if (light == 0) {
            light = func_80268C1C_de(&D_8013B1A8, D_auto_rodata_unresolved_800CE410);
        }
        if (light != 0) {
            FIELD(void *, player, 0x67C) = light;
            placePlayerLight(player, light, D_800C259C_de, D_800C25A0_de, D_800C25A4_de);
        }
        light = FIELD(void *, player, 0x680);
        if (light == 0) {
            light = func_80268C1C_de(&D_8013B1A8, D_800C91C8_de);
        }
        if (light != 0) {
            FIELD(void *, player, 0x680) = light;
            placePlayerLight(player, light, D_800C25A8_de, D_800C25AC_de, D_800C76A0);
        }
        if (FIELD(f32, player, 0x678) < D_800C25B4_de) {
            flicker = 1;
            if (FIELD(f32, player, 0x678) < D_800C25B8_de) {
                roll = func_802744D4_de();
                flicker = ((roll % 100) < 50) ^ 1;
            } else {
                roll = func_802744D4_de();
                if ((roll % 100) < 15) {
                    flicker = 0;
                }
            }
            if (FIELD(void *, player, 0x67C) != 0) {
                FIELD(s16, FIELD(void *, player, 0x67C), 0x16) = flicker;
            }
            if (FIELD(void *, player, 0x680) != 0) {
                FIELD(s16, FIELD(void *, player, 0x680), 0x16) = flicker;
            }
        }
    } else {
        if (FIELD(void *, player, 0x67C) != 0) {
            func_80268C7C_de(&D_8013B1A8, (s32)FIELD(void *, player, 0x67C));
            FIELD(void *, player, 0x67C) = 0;
        }
        if (FIELD(void *, player, 0x680) != 0) {
            func_80268C7C_de(&D_8013B1A8, (s32)FIELD(void *, player, 0x680));
            FIELD(void *, player, 0x680) = 0;
        }
    }
    if (FIELD(u32, &D_801462C8, 0) & 0x4000) {
        light = FIELD(void *, player, 0x684);
        if (light == 0) {
            light = func_80268C1C_de(&D_8013B1A8, D_auto_800CE420);
            if (light != 0) {
                FIELD(void *, player, 0x684) = light;
            }
        }
        if (light != 0) {
            placePlayerLight(player, light, 0.0f, D_800C25BC_de, D_800C25C0_de);
        }
        if ((FIELD(u32, player, 0x6B0) & 0x20) && FIELD(void *, player, 0x684) != 0) {
            void *entry = FIELD(void *, player, 0x684);
            if (FIELD(void *, entry, 0x8) == D_auto_800CE420) {
                FIELD(void *, entry, 0x8) = D_800C91D8_de;
            } else {
                FIELD(void *, entry, 0x8) = D_auto_800CE420;
            }
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8021E5F8_de);
#endif
