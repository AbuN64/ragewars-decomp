#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/WORLD.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/STATEPAIR.H"
#include "RESMGR/802A2230_8.H"
#include "COMMON/PLAYERPROFILES.H"

#if defined(VERSION_US_REV1)
extern void Player_InitializeProfile(void *);
extern Pulse *D_800E5950;

/* Initialize the pulse screen, its shared menu state, and player profiles. */
s32 Frontend_CreateProfileResetScreen(MenuWidget *tree) {
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
        func_8025476C_de(1);
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
    D_800E5950->widget = Frontend_FindWidgetByResourceId(tree, 0x397);
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
