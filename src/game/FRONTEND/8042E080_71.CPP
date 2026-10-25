#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "stddef.h"
#include "FRONTEND/8040B45C_33.H"

/* Allocates menu state, selects the language-dependent title and enables the appropriate menu item. */
extern s32 *D_800E5550;
extern s32 D_80146894;
extern s32 *Scene_AllocateMemory(s32);
extern void func_802648C8_de(void); extern void func_802A2360_de(void); extern void func_8040E950_de(s32, s32);
extern s32 func_8040C474_de(void),func_8042AF28_de(void);
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
enum { MENU_80435D14_62 = 62 };
#elif defined(VERSION_EU_X)
enum { MENU_80435D14_62 = 64 };
#endif
s32 func_80435B34_de(MenuWidget *arg0) {
    s32 *temp_v0;
    temp_v0 = Scene_AllocateMemory(0x14);
    D_800E5550 = temp_v0;
    *temp_v0 = 0;
    func_8025E214_de(-1);
    func_802648C8_de();
    if (func_8040C474_de() == 1) {
        arg0->x = 0x62;
        arg0->y = 0x45;
    } else if (func_8040C474_de() == 2) {
        arg0->x = 0x69;
    }
    func_802A2360_de();
    if ((D_801462C8.controllerMode != 0) || (func_8042AF28_de() == 0)) {
        func_8040E950_de((s32)func_8040EC30_de(arg0, MENU_80435D14_62), 1);
    }
    D_80146894 = 1;
    return 0;
}
