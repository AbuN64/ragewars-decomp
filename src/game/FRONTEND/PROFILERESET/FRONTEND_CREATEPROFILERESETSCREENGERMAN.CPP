#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "include_asm.h"
#include "COMMON/PLAYERPROFILES.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "FRONTEND/FRONTEND_DISPATCHPROFILERESETEVENT.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* 80408AC4_37.CPP */
#if defined(VERSION_DE)
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

s32 Frontend_CreateProfileResetScreenGerman(MenuWidget *tree) {
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
    D_800E5950->widget = Node_FindWidgetByResourceId(tree, 0x391);
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

/* 8043962C_2.CPP */
/* Releases the object D_800E5950 holds through Cache_FreeMemory, clears D_800E5950 and returns zero. */

extern void Tsmos_ActivateControllerState(void);

/* On event 3 with value 0xD, calls MarkMenuEventHandled and SmXlate_SwitchScreen with 3. Returns zero. */
extern void MarkMenuEventHandled();

extern void SmXlate_SwitchScreen(s32);

s32 Frontend_FreeProfileResetScreen(void) {
    extern Pulse *D_800E5950;
    Cache_FreeMemory(D_800E5950);
    D_800E5950 = 0;
    return 0;
}

/* Advances a sine-driven pulse phase and writes the resulting display intensity byte. */
s32 Frontend_PulseProfileResetWidget(s32 unused0, s32 unused1, s32 arg2) {
    extern Pulse *D_800E5950;
    if (D_800E28E0 >= 2) {
        return 0;
    }
    Tsmos_ActivateControllerState();
    D_800E5950->phase += arg2;
    D_800E5950->light->field_10 = (u32)(Math_Cosf(D_800E5950->phase * 0.005f) * 100.0f + 150.0f);
    return 0;
}

s32 Frontend_HandleProfileResetConfirm(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3) {
        if (value != 0xD) {
            return 0;
        }
        MarkMenuEventHandled();
        SmXlate_SwitchScreen(3);
    }
    return 0;
}

s32 Frontend_AcknowledgeProfileResetEvent(void) {
    MarkMenuEventHandled();
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80439750_de(void) {
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5954, an actor kind at D_800E5958 and a handler at D_800E595C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

s32 Frontend_DispatchProfileResetEvent(Shared_Body *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E595C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E595C;
        index = 0;
        do {
#if defined(VERSION_EU)
            if (D_800F1F74[index].value == arg1) {
#else
            if (D_800E5954[index].value == arg1) {
#endif
                actor_kind = arg0->kind;
                table_kind = D_800E5958[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(MenuEventHandler *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            index++;
        } while (*(MenuEventHandler *)entry != 0);
    }
    return 0;
}
