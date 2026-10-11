/* Main menu choice handler: after func_8029973C_de it acts on the entry func_80299A08_de reports
   (0x45 to 0x4C), setting the next state of screen D_800E4600, the player count D_801462D5 and the
   player status records in D_80146398 (joining players and resetting unsaved records through
   func_8022F204_de), then closes the menu through func_8041A430_de. Returns zero. */
#include "types.h"
#include "types.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/gameplay_transition.h"

#include "types.h"
struct CompactOptionsScreen {
    s32 slider;
    s32 first_list;
    s32 second_list;
    s32 state;
};
struct ArenaChoiceState {
    void *menu;
    u32 unknown4[5];
    s32 next;
};

#include "common/unused.h"

extern struct ArenaChoiceState *D_800E4600;
extern s32 D_800E4680;
extern Shared_Game D_801462C8;
/* D_80146398 is the hub's func_8041F2A0_Config array: eight 0x96-byte records at Game+0xD0.
   This unit reaches them only as settings->playerSettings and declares nothing here. */
extern Record_func_80433914_de D_80102B00[];

extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);

extern void func_8022EF30_de(char *);
extern void func_80434FB4_de(s32);
extern void func_8022F5A4_de(char *, s32);
extern void func_8041A430_de(void *, s32);

s32 func_80423F48_de(void) {
    Shared_PlayerSettingsRecord *status;
    Shared_Game *settings;

    s32 i;

    func_8029973C_de();
    switch (func_80299A08_de()) {
    case 0x45:
        D_800E4600->next = 0x1A;
        D_801462C8.controllerMode = 0;
        break;
    case 0x49:
        settings = &D_801462C8;
        status = settings->playerSettings;
        D_800E4600->next = 7;
        settings->controllerMode = 2;
        for (i = 0; i < 2; i++) {
            status[i].enabled = 1;
            status[i].slot = i;
            if (D_80102B00[i].player < 0) {
                func_8022F204_de(i);
            }
        }
        break;
    case 0x46:
        status = D_801462C8.playerSettings;
        status->enabled = 1;
        status[0].slot = 0;
        func_8022EF30_de((char *)D_80102B00);
        func_80434FB4_de(7);
        D_800E4600->next = 0x13;
        D_801462C8.controllerMode = 1;
        break;
    case 0x4B:
        D_800E4600->next = 0x1B;
        break;
    case 0x47:
        D_800E4600->next = 4;
        break;
    case 0x4C:
        D_800E4600->next = 0x10;
        break;
    case 0x48:
        status = D_801462C8.playerSettings;
        D_800E4600->next = 7;
        status->enabled = 1;
        status[0].slot = 0;
        if (D_80102B00[0].player < 0) {
            func_8022F204_de(0);
            for (i = 0; i < 20; i++) {
                func_8022F5A4_de((char *)D_80102B00, i);
            }
        }
        D_801462C8.controllerMode = 3;
        break;
    case 0x4A:
        status = D_801462C8.playerSettings;
        D_800E4600->next = 0xA;
        status->enabled = 1;
        status[0].slot = 0;
        if (D_80102B00[0].player < 0) {
            func_8022F204_de(0);
        }
        D_801462C8.controllerMode = 4;
        D_800E4680 = 0;
        break;
    default:
        return 0;
    }
    func_8041A430_de(D_800E4600->menu, 2);
    return 0;
}
