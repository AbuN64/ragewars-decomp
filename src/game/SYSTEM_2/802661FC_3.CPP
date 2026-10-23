#include "include_asm.h"
#include "COMMON/TARGET.H"
#include "SYSTEM_2/802661FC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "TYPES.H"

extern s32 func_802394BC_de(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, Triple arg6);

extern f32 D_800C4450_de[2];

void func_80267DB4_de(s32 arg0, s32 arg1, s32 arg2, Triple t, Vec4s v) {
    func_802394BC_de(&D_80145088, (f32) v.x, (f32) v.y, (f32) v.z, (f32) v.w * D_800C4450_de[1], 1, t);
}

void func_80267E48_de(s32 arg0, s32 arg1, s32 arg2, Triple t, Vec4s v) {
    func_802394BC_de(&D_80145088, (f32) v.x, (f32) v.y, (f32) v.z, (f32) v.w * D_800C4458_de, 0, t);
}

#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/CHANNEL.H"
extern void func_8025E11C_de(s32);

void func_80267ED8_de(void *owner, LevelActor *actor, s32 event, Triple position, ResourceManagerState params) {
    if (actor->kind == 1 && (actor->flags & 0x300000)) {
        Shared_ActorView *player = actor->controller;
        void *parent = player->message;
        if (parent != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            func_80237E80_de(&D_80145088, parent, D_800E45D4[params.active].sound[D_80145088.settings.language]);
#else
            func_80237E80_de(&D_80145088, parent, gameplaySoundValue(params.active));
#endif
        }
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        func_80237E80_de(&D_80145088, &D_80145088.fallbackCamera, D_800E45D4[params.active].sound[D_80145088.settings.language]);
#else
        func_80237E80_de(&D_80145088, &D_80145088.fallbackCamera, gameplaySoundValue(params.active));
#endif
    }
    if (gameplaySoundHook(params.active) != 0) {
        func_8025E11C_de(gameplaySoundHook(params.active));
    }
}
