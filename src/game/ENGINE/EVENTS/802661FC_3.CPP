#include "include_asm.h"
#include "COMMON/TARGET.H"
#include "SYSTEM_2/802661FC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "TYPES.H"

extern s32 Gsky_StartEmitter(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, Triple arg6);

extern f32 D_800C4450_de[2];

void Events_StartEnabledCameraEmitter(s32 unused0, s32 unused1, s32 unused2, Triple t, Vec4s v) {
    Gsky_StartEmitter(&D_80145088, (f32) v.x, (f32) v.y, (f32) v.z, (f32) v.w * D_800C4450_de[1], 1, t);
}

void Events_StartDisabledCameraEmitter(s32 unused0, s32 unused1, s32 unused2, Triple t, Vec4s v) {
    Gsky_StartEmitter(&D_80145088, (f32) v.x, (f32) v.y, (f32) v.z, (f32) v.w * D_800C4458_de, 0, t);
}

#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/CHANNEL.H"

void Events_PostGameplayMessage(void *owner, LevelActor *actor, s32 event, Triple position, ResourceManagerState params) {
    if (actor->kind == 1 && (actor->flags & 0x300000)) {
        Shared_ActorView *player = actor->controller;
        void *parent = player->message;
        if (parent != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            Camera_PostScreenMessage(&D_80145088, parent, D_800E45D4[params.active].sound[D_80145088.settings.language]);
#else
            Camera_PostScreenMessage(&D_80145088, parent, gameplaySoundValue(params.active));
#endif
        }
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Camera_PostScreenMessage(&D_80145088, &D_80145088.fallbackCamera, D_800E45D4[params.active].sound[D_80145088.settings.language]);
#else
        Camera_PostScreenMessage(&D_80145088, &D_80145088.fallbackCamera, gameplaySoundValue(params.active));
#endif
    }
    if (gameplaySoundHook(params.active) != 0) {
        func_8025E11C_de(gameplaySoundHook(params.active));
    }
}
