#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "include_asm.h"
#include "COMMON/PLAYERPROFILES.H"

#if defined(VERSION_US)
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/WORLD.H"
extern void *Cache_AllocateMemory(s32);
extern void Player_InitializeProfile(Profile *);
extern Pulse *D_800E5950;
extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void Cache_SetResourceActivityState(u32);
extern void Frontend_RequestScreenMode(s32);
extern void Tsmos_DeactivateControllerState(void);
extern void Tsmos_SetIdleTimer(f32);

s32 Frontend_CreateProfileResetScreenUs(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    D_800E5950 = Cache_AllocateMemory(sizeof(*D_800E5950));
    object = &D_80145040.object;
    Pools_ResetActorPools(object, 0);
    Player_InitializePlayerPool(&D_80145040, 0, 0);
    Scene_LoadLevelResources(&g_world, 0, 0);
    if (func_8025477C_de() == 0) {
        Cache_SetResourceActivityState(1);
    }
    Frontend_RequestScreenMode(0);
    i = 7;
    Tsmos_DeactivateControllerState();
    record = &object->playerSettings[7];
    do {
        record->enabled = 0;
        i--;
        record--;
    } while (i >= 0);
    D_800E5950->widget = Node_FindWidgetByResourceId(tree, 0x397);
    D_800E5950->phase = 0;
    settings = &D_801462C8;
    settings->laps = 10;
    settings->players = 10;
    for (i = 0; i < 4; i++) {
        Player_InitializeProfile(&D_80102B00[i]);
    }
    Tsmos_SetIdleTimer(0.0f);
    return 0;
}
#endif
