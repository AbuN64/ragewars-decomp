#include "span_16E000/code_8043962C.h"
#include "shared/func_804235A8_eu_layout.h"
#include "shared/world.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_804220A8_de_closed.h"
#include "shared/func_804235A8_eu_closed.h"
#include "span_1000/code_80293A04.h"
#include "span_1000/code_802A208C.h"

extern void func_8022EF30_de(void *);
extern Profile D_80102B00[];
extern Pulse *D_800E5950;

/* Initialize the pulse screen, its shared menu state, and player profiles. */
s32 func_804396C0_us_rev1(MenuWidget *tree) {
    s32 i;
    Shared_Game *settings;
    Shared_PlayerSettingsRecord *record;
    Shared_MenuObject *object;

    D_800E5950 = func_8025305C_de(sizeof(*D_800E5950));
    object = &D_80145040.object;
    func_8044A370_de(object, 0);
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
