#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "FRONTEND/OPTIONS.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/MENULISTSCREEN.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
#include "FRONTEND/MATCH_MENU_MESSAGE_IDS.H"
#include "TYPES.H"

/* Handles the menu message func_80299A08_de reports after MarkMenuEventHandled. 0x1D9: when
   func_802999A0_de(0) reports 0x16 it stops the menu object and the menu data D_80145040, releases
   D_8011FE88, restarts func_8025476C_de when func_8025477C_de reports it idle, sets the menu stage to 8
   and sends func_8042E988_de 20, 10, 15 or 10 by the controller mode (3 for any other mode); otherwise
   it sends 3. 0x1DA sends 11 when func_802999A0_de(0) reports 11 and -1 otherwise. Either then calls
   func_802998A8_de. Returns zero. */
#include "MENU/PAK_LOAD.H"

extern void MarkMenuEventHandled(void);
extern s32 func_80299A08_de(void);
extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_802998A8_de(void);




s32 Frontend_HandleMatchMenuMessage(void) {
    MarkMenuEventHandled();
    switch (func_80299A08_de()) {
    default:
        return 0;
    case MENU_804291A8_473:
        if (func_802999A0_de(0) == 0x16) {
            Items_ResetActorPools(&D_80145040.object, 0);
            func_804499B0_de(&D_80145040, 0, 0);
            Scene_LoadLevelResources(&g_world, 0, 0);
            if (func_8025477C_de() == 0) {
                func_8025476C_de(1);
            }
            D_80145040.stage = 8;
            switch (D_80145040.game.controllerMode) {
            case 0:
                func_8042E988_de(20);
                break;
            case 1:
                func_8042E988_de(10);
                break;
            case 2:
                func_8042E988_de(15);
                break;
            case 3:
            case 4:
                func_8042E988_de(10);
                break;
            default:
                func_8042E988_de(3);
                break;
            }
        } else {
            func_8042E988_de(3);
        }
        break;
    case MENU_804291A8_474:
        if (func_802999A0_de(0) == 11) {
            func_8042E988_de(11);
        } else {
            func_8042E988_de(-1);
        }
        break;
    }
    func_802998A8_de();
    return 0;
}
#endif

/* Calls MarkMenuEventHandled, then passes 0xB to func_8042E988_de when func_802999A0_de reports 0xB for zero
   and -1 otherwise, then calls func_802998A8_de. Returns zero. */
extern void MarkMenuEventHandled();

s32 func_804290F4_de(void) {
    MarkMenuEventHandled();
    func_8042E988_de(func_802999A0_de(0) == 0xB ? 0xB : -1);
    func_802998A8_de();
    return 0;
}
