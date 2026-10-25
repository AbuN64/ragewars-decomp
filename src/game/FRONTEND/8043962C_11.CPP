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
extern void func_8022EF30_de(void *);
extern Pulse *D_800E5950;

/* Initialize the pulse screen, its shared menu state, and player profiles. */
s32 func_804396C0_us_rev1(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    D_800E5950 = Scene_AllocateMemory(sizeof(*D_800E5950));
    object = &D_80145040.object;
    Items_ResetActorPools(object, 0);
    func_804499B0_de(&D_80145040, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0, 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    func_8040C428_de(0);
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
        func_8022EF30_de(&D_80102B00[i]);
    }
    func_802A2400_de(0.0f);
    return 0;
}
#endif
