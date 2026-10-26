#include "include_asm.h"
#include "COMMON/PLAYERPROFILES.H"

#if defined(VERSION_US)
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/WORLD.H"
extern void *Cache_AllocateMemory(s32);
extern void Player_InitializeProfile(Profile *);
extern Pulse *D_800E5950;
extern Shared_MenuData D_80145040;
extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(u32);
extern void Frontend_RequestScreenMode(s32);
extern void func_802A2394_de(void);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_802A2400_de(f32);

s32 func_804396C0_us(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    D_800E5950 = Cache_AllocateMemory(sizeof(*D_800E5950));
    object = &D_80145040.object;
    Items_ResetActorPools(object, 0);
    func_804499B0_de(&D_80145040, 0, 0);
    func_80286AA8_de(&g_world, 0, 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    Frontend_RequestScreenMode(0);
    i = 7;
    func_802A2394_de();
    record = &object->playerSettings[7];
    do {
        record->enabled = 0;
        i--;
        record--;
    } while (i >= 0);
    D_800E5950->widget = func_8040EC30_de(tree, 0x397);
    D_800E5950->phase = 0;
    settings = &D_801462C8;
    settings->laps = 10;
    settings->players = 10;
    for (i = 0; i < 4; i++) {
        Player_InitializeProfile(&D_80102B00[i]);
    }
    func_802A2400_de(0.0f);
    return 0;
}
#endif
