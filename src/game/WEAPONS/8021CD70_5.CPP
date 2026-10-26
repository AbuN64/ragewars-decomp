#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/EXTERNS_6.H"

extern u8 D_80142233; /* MIXED func_8021E2A0_de */
void func_8021E2A0_de(SharedPlayer *player, void *view) {
    s32 icon;
    s32 show;
    f32 scale;

    player->views5E8.view7BC_102.timer += D_800D2988;
    if (player->views5E8.view788_94.icons == 0) {
        return;
    }
    if (player->views5D8.view5D8_9.profile->remote == 1 && D_801462C8.counters.m_bFragTagOn != 0) {
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
    OnScreen_SetupSpriteMode(0xFF);

    icon = player->views5E8.view7B8_100.target;
    show = 1;
    if (icon == 0x2DA && D_80145088.settings.local != 0) {
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
    if (icon == 0x2DA && D_80145088.settings.local != 0) {
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

#include "COMMON/AIPROFILE.H"
struct PlayerEffectLight {
    u8 pad0[8];
    void *pattern;
    f32 radius;
    s16 x, y, z;
    s16 active;
};
#if defined(VERSION_US)
#define PLAYER_SECOND_LIGHT_RADIUS D_auto_800C24E0
#else
#define PLAYER_SECOND_LIGHT_RADIUS D_800C76A0
#endif
extern f32 D_800C25A8_de, D_800C25AC_de, PLAYER_SECOND_LIGHT_RADIUS;
extern f32 D_800C25C0_de;
#if defined(VERSION_DE)
#define PLAYER_EFFECT_LIGHT_PATTERN D_auto_rodata_unresolved_800C91C0
#define PLAYER_MODE_LIGHT_PATTERN D_auto_800C91D0
#elif defined(VERSION_EU)
#define PLAYER_EFFECT_LIGHT_PATTERN D_auto_rodata_unresolved_800C9DB0
#define PLAYER_MODE_LIGHT_PATTERN D_auto_800C9DC0
#elif defined(VERSION_EU_X)
#define PLAYER_EFFECT_LIGHT_PATTERN D_auto_rodata_unresolved_800CA780
#define PLAYER_MODE_LIGHT_PATTERN D_auto_800CA790
#elif defined(VERSION_US)
#define PLAYER_EFFECT_LIGHT_PATTERN D_auto_rodata_unresolved_800C90E0
#define PLAYER_MODE_LIGHT_PATTERN D_auto_800C90F0
#elif defined(VERSION_US_REV1)
#define PLAYER_EFFECT_LIGHT_PATTERN D_auto_rodata_unresolved_800CE410
#define PLAYER_MODE_LIGHT_PATTERN D_auto_800CE420
#endif
extern char PLAYER_EFFECT_LIGHT_PATTERN[], D_800C91C8_de[], PLAYER_MODE_LIGHT_PATTERN[], D_800C91D8_de[];
extern void *DynLight_AllocateLightNode(void *, void *);
extern void func_8024BC94_de(CVector3 *, void *, CVector3);
extern s32 GraphU64_NextRandom(void);
extern f32 GameObject_GetActorHeight(void *);
/* Position one effect light, reading its scale and radius at their use sites. */
static inline void placePlayerLight(struct Player *player, struct PlayerEffectLight *light,
                                    f32 offsetZ, const f32 *heightScale, const f32 *radius) {
    CVector3 offset;
    CVector3 position;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = offsetZ;
    func_8024BC94_de(&position, player, offset);
    GraphU64_AddVec3(&position, &position, &player->pos);
    light->active = 1;
    light->x = (s16)position.x;
    light->y = (s16)(position.y + GameObject_GetActorHeight(player) * *heightScale);
    light->z = (s16)position.z;
    light->radius = *radius;
}
/* Keep the timer lights and the special-mode light in step with player state. */
void Player_UpdatePlayerEffectLights(struct Player *player) {
    struct PlayerEffectLight *light;
    s32 flicker;
    if (D_801462C8.flags & 0x4000) {
        player->rangeTimer = 0.0f;
    } else if (player->rangeNodes[2] != 0) {
        DynLight_ReleaseLight(&D_8013B1A8, (s32)player->rangeNodes[2]);
        player->rangeNodes[2] = 0;
    }
    if (player->rangeTimer != 0.0f) {
        light = (struct PlayerEffectLight *)player->rangeNodes[0];
        if (light == 0) {
            light = DynLight_AllocateLightNode(&D_8013B1A8, PLAYER_EFFECT_LIGHT_PATTERN);
        }
        if (light != 0) {
            player->rangeNodes[0] = (struct RangeNode *)light;
            placePlayerLight(player, light, D_800C259C_de, &D_800C25A0_de, &D_800C25A4_de);
        }
        light = (struct PlayerEffectLight *)player->rangeNodes[1];
        if (light == 0) {
            light = DynLight_AllocateLightNode(&D_8013B1A8, D_800C91C8_de);
        }
        if (light != 0) {
            player->rangeNodes[1] = (struct RangeNode *)light;
            placePlayerLight(player, light, D_800C25A8_de, &D_800C25AC_de, &PLAYER_SECOND_LIGHT_RADIUS);
        }
        if (player->rangeTimer < D_800C25B4_de) {
            flicker = 1;
            if (player->rangeTimer < D_800C25B8_de) {
                flicker ^= (GraphU64_NextRandom() % 100) < 50;
            } else {
                if ((GraphU64_NextRandom() % 100) < 15) {
                    flicker = 0;
                }
            }
            if (player->rangeNodes[0] != 0) {
                ((struct PlayerEffectLight *)player->rangeNodes[0])->active = flicker;
            }
            if (player->rangeNodes[1] != 0) {
                ((struct PlayerEffectLight *)player->rangeNodes[1])->active = flicker;
            }
        }
    } else {
        if (player->rangeNodes[0] != 0) {
            DynLight_ReleaseLight(&D_8013B1A8, (s32)player->rangeNodes[0]);
            player->rangeNodes[0] = 0;
        }
        if (player->rangeNodes[1] != 0) {
            DynLight_ReleaseLight(&D_8013B1A8, (s32)player->rangeNodes[1]);
            player->rangeNodes[1] = 0;
        }
    }
    if (D_801462C8.flags & 0x4000) {
        light = (struct PlayerEffectLight *)player->rangeNodes[2];
        if (light == 0) {
            light = DynLight_AllocateLightNode(&D_8013B1A8, PLAYER_MODE_LIGHT_PATTERN);
        }
        if (light != 0) {
            player->rangeNodes[2] = (struct RangeNode *)light;
            placePlayerLight(player, light, 0.0f, &D_800C25BC_de, &D_800C25C0_de);
        }
        if ((player->actionFlags & 0x20) && player->rangeNodes[2] != 0) {
            struct PlayerEffectLight *entry = (struct PlayerEffectLight *)player->rangeNodes[2];
            if (entry->pattern == PLAYER_MODE_LIGHT_PATTERN) {
                entry->pattern = D_800C91D8_de;
            } else {
                entry->pattern = PLAYER_MODE_LIGHT_PATTERN;
            }
        }
    }
}
