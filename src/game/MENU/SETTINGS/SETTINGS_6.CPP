#include "COMMON/S1_5.H"
#include "MENU/804221A0_13.H"

/* Calls Tsmos_DeactivateControllerState and then SmXlate_SwitchScreen with 0x16. */
extern void Tsmos_DeactivateControllerState();
extern void SmXlate_SwitchScreen(int);

void Menu_RequestOptionsScreen22(void) {
    Tsmos_DeactivateControllerState();
    SmXlate_SwitchScreen(0x16);
}
