#include "span_16E000/code_80423280.h"
#include "common/unused.h"
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

extern struct ArenaChoiceState *D_800E4600;

extern s32 D_800E4680;


/* D_80146398 is the hub's func_8041F2A0_Config array: eight 0x96-byte records at Game+0xD0.
   This unit reaches them only as settings->playerSettings and declares nothing here. */
extern Profile D_80102B00[];

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
    #if defined(VERSION_EU_X)
    case 0x47:
#else
    case 0x45:
#endif
        D_800E4600->next = 0x1A;
        D_801462C8.controllerMode = 0;
        break;
    #if defined(VERSION_EU_X)
    case 0x4C:
#else
    case 0x49:
#endif
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
    #if defined(VERSION_EU_X)
    case 0x48:
#else
    case 0x46:
#endif
        status = D_801462C8.playerSettings;
        status->enabled = 1;
        status[0].slot = 0;
        func_8022EF30_de((char *)D_80102B00);
        func_80434FB4_de(7);
        D_800E4600->next = 0x13;
        D_801462C8.controllerMode = 1;
        break;
    #if defined(VERSION_EU_X)
    case 0x49:
#else
    case 0x4B:
#endif
        D_800E4600->next = 0x1B;
        break;
    #if defined(VERSION_EU_X)
    case 0x4B:
#else
    case 0x47:
#endif
        D_800E4600->next = 4;
        break;
    #if defined(VERSION_EU_X)
    case 0x4A:
#else
    case 0x4C:
#endif
        D_800E4600->next = 0x10;
        break;
    #if defined(VERSION_EU_X)
    case 0x4D:
#else
    case 0x48:
#endif
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
    #if defined(VERSION_EU_X)
    case 0x4E:
#else
    case 0x4A:
#endif
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
