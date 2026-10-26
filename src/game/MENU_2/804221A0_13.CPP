#include "COMMON/S1_5.H"
#include "MENU_2/804221A0_13.H"

/* Calls Tsmos_DeactivateControllerState and then func_80298368_de with 0x16. */
extern void Tsmos_DeactivateControllerState();
extern void func_80298368_de(int);

void Menu_RequestOptionsScreen22(void) {
    Tsmos_DeactivateControllerState();
    func_80298368_de(0x16);
}
