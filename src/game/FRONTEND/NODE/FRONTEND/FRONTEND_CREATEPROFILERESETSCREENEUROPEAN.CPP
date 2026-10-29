#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/FRONTEND_RESOURCE_LOAD_STATE.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "COMMON/PLAYERPROFILES.H"

/* 8040B45C_17.CPP */
#if defined(VERSION_DE)
unsigned char g_FrontendCreateprofileresetscreeneuropeanTrailingBytes[4] = { 0x8C, 0x48, 0x00, 0x08 };
#endif

/* 8040B45C_8.CPP */
#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Points a field's text at the label for the state word g_frontendResourceLoadStage: one of 3 strings through the jump table
   jtbl_800E1098 for states 0 to 4, and s_nodeDefaultFieldText for any other state. Returns zero. */

s32 Frontend_SelectPakActionLabel(struct PakActionLabelView *field) {
    u32 state = g_frontendResourceLoadStage;

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
    field->text = s_nodeDefaultFieldText;
    goto done;
case_1:
    field->text = s_nodeDefaultFieldText;
    goto done;
case_2:
    field->text = s_nodeDefaultFieldText;
    goto done;
case_3:
    field->text = s_nodeAlternateFieldText;
done:
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned int k_FrontendCreateprofileresetscreeneuropeanEncodedWordsBlock1[1] = {
    0x00009608,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_FrontendCreateprofileresetscreeneuropeanEncodedWords[1] = {
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
extern Pulse *g_profileResetScreen;
extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 Cache_GetResourceActivityState(void);
extern void Cache_SetResourceActivityState(u32);
extern void Frontend_RequestScreenMode(s32);
extern void Tsmos_DeactivateControllerState(void);
extern void Tsmos_SetIdleTimer(f32);

s32 Frontend_CreateProfileResetScreenEuropean(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    g_profileResetScreen = Cache_AllocateMemory(sizeof(*g_profileResetScreen));
    object = &g_playerViewRenderContext.object;
    Pools_ResetActorPools(object, 0);
    Player_InitializePlayerPool(&g_playerViewRenderContext, 0, 0);
    Scene_LoadLevelResources(&g_world, 0, 0);
    if (Cache_GetResourceActivityState() == 0) {
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
    g_profileResetScreen->widget = Node_FindWidgetByResourceId(tree, 0x397);
    g_profileResetScreen->phase = 0;
    settings = &g_gameSettings;
    settings->laps = 10;
    settings->players = 10;
    for (i = 0; i < 4; i++) {
        Player_InitializeProfile(&g_localPlayerProfiles[i]);
    }
    Tsmos_SetIdleTimer(0.0f);
    return 0;
}
#endif
