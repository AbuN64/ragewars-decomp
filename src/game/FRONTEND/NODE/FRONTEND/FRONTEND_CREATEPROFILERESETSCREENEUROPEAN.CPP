#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_20.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_33.H"
#include "COMMON/PLAYERPROFILES.H"

/* 8040B45C_17.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_80412CDC_de_padding_178CDC[4] = { 0x8C, 0x48, 0x00, 0x08 };
#endif

/* 8040B45C_8.CPP */
#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Points a field's text at the label for the state word D_80153778: one of 3 strings through the jump table
   jtbl_800E1098 for states 0 to 4, and D_800D7A0C for any other state. Returns zero. */

s32 Frontend_SelectPakActionLabel(struct FieldRecAt14 *field) {
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_3;
        case 2: goto case_3;
        case 3: goto case_1;
        case 4: goto case_2;
        }
state_other:
    field->text = D_800D7A0C;
    goto done;
case_1:
    field->text = D_800D7A0C;
    goto done;
case_2:
    field->text = D_800D7A0C;
    goto done;
case_3:
    field->text = D_800DE7BC;
done:
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_8040BC2C[1] = {
    0x00009608,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E88BC[1] = {
    0x0043D414,
};
#endif

/* 8042FBEC_9.CPP */
#if defined(VERSION_EU)
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/WORLD.H"
extern void *Cache_AllocateMemory(s32);
extern void Player_InitializeProfile(Profile *);
extern Pulse *D_800E5950;
extern void Items_ResetActorPools(void *, s32);
extern void Ovlgame_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void Cache_SetResourceActivityState(u32);
extern void Frontend_RequestScreenMode(s32);
extern void Tsmos_DeactivateControllerState(void);
extern void Tsmos_SetIdleTimer(f32);

s32 Frontend_CreateProfileResetScreenEuropean(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    D_800E5950 = Cache_AllocateMemory(sizeof(*D_800E5950));
    object = &D_80145040.object;
    Items_ResetActorPools(object, 0);
    Ovlgame_InitializePlayerPool(&D_80145040, 0, 0);
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
