#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/WORLD.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/STATEPAIR.H"
#include "RESMGR/TSMOS_SETIDLETIMER.H"
#include "COMMON/PLAYERPROFILES.H"

/* 80408AC4_16.CPP */
/* 80408AC4_16.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_804143FC_de_padding_17A3FC[4] = { 0x24, 0x65, 0x00, 0x18 };
#endif

/* 8043962C_11.CPP */
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
    Pools_ResetActorPools(object, 0);
    Player_InitializePlayerPool(&D_80145040, 0, 0);
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

/* 80408CB0_17.CPP */
/* 80408CB0_17.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_8041483C_eu_padding_18A83C[4] = { 0x0C, 0x0A, 0x86, 0x64 };
#endif

/* DATA_800E5CC8.CPP */
#if defined(VERSION_US_REV1)
char s_bigCheatActivatedText[20] = "big cheat activated";
#endif

/* DATA_800E5CDC.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E5CAC_unclaimed_E68DC */
unsigned int D_blob_0f60ffbc76c8bea817b7[1] = {
    0x800E5CC8,
};

char s_janesCheatActivatedText[24] = "janes cheat activated";
#endif

/* DATA_800E5CF8.CPP */
#if defined(VERSION_US_REV1)
extern char D_0043E1B0[];
extern char D_0043E1C0[];
extern char D_0043E21C[];
extern char D_0043E230[];
extern char D_0043E244[];
extern char rw_menu_paged_func_804402DC_de[];
extern char rw_menu_paged_func_804415F4_de[];
extern char rw_menu_paged_func_80442064_de[];
unsigned int D_auto_rodata_unresolved_800E5CAC_unclaimed_E68F8[84] = {
    0x800E5CE0, 0x00000000, 0x8014641C, 0x801464B2, 0x80146548, 0x801465DE, 0x800E5D00, 0x800E5D04,
    0x800E5D08, 0x800E5D0C, 0x00010000, 0x10000000, 0x00000000, 0x0000FF01, 0x00000385, (unsigned int)rw_menu_paged_func_804402DC_de,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x08000021, 0x00000008, 0x0000FF01, 0x800D76C4,
    (unsigned int)rw_menu_paged_func_80442064_de, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010041, 0x00000028, 0x0000FF01,
    0x800D7E14, (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)D_0043E21C, 0x00000000, 0x00000000, 0x00000000, 0x00010041, 0x0000000F,
    0x0000FF01, 0x800D7E14, (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)D_0043E230, 0x00000000, 0x00000000, 0x00000000, 0x00010041,
    0x00000023, 0x0000FF01, 0x800D76D0, (unsigned int)rw_menu_paged_func_80442064_de, 0x00000000, (unsigned int)D_0043E244, 0x00000000, 0x800E5D20,
    0x00050000, (unsigned int)D_0043E1B0, 0x00000000, (unsigned int)rw_menu_paged_func_804415F4_de, (unsigned int)D_0043E1C0, 0x00040000, 0x00000000, 0x00000000,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0xFFFFFFFF,
    0x00000001, 0x00000001, 0x00000001, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
