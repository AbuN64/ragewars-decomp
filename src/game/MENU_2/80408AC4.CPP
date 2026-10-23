#include "include_asm.h"

#if defined(VERSION_DE)
unsigned int data_unresolved_800DDA24[3] = {
    0x004297A8, 0x00429754, 0x004297A8,
};
#endif

#if defined(VERSION_DE)
#include "COMMON/OWNERRECAT8V1.H"

s32 func_80428FA0_de(void) {
    func_8041B110_de(0x1D5);
    func_8041B110_de(0x1D6);
    return 0;
}
#endif

#if defined(VERSION_DE)
#include "FRONTEND/MATCH_MENU_MESSAGE_IDS.H"
#include "MENU/PAK_LOAD.H"
#include "COMMON/GAME_SESSION.H"

/* Handles the menu message func_80299A08_de reports after func_8029973C_de. 0x1D5: when
   func_802999A0_de(0) reports 0x16 it stops the menu object and the menu data D_80145040, releases
   D_8011FE88, restarts func_8025476C_de when func_8025477C_de reports it idle, sets the menu stage to 8
   and sends func_8042E988_de 20, 10, 15 or 10 by the controller mode (3 for any other mode); otherwise
   it sends 3. 0x1D6 sends 11 when func_802999A0_de(0) reports 11 and -1 otherwise. Either then calls
   func_802998A8_de. Returns zero. */
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern s32 func_802999A0_de(s32);
extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de(void);

s32 Menu_HandleMatchMessage(void) {
    func_8029973C_de();
    switch (func_80299A08_de()) {
    default:
        return 0;
    case MENU_804291A8_473:
        if (func_802999A0_de(0) == 0x16) {
            Items_ResetActorPools(&D_80145040.object, 0);
            func_804499B0_de(&D_80145040, 0, 0);
            func_80286AA8_de(&D_8011FE88, 0, 0);
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
