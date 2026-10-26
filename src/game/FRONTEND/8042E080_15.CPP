#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ENTRYRECAT6C.H"

/* Enters the selected menu state and resolves the default destination from the game mode. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/8042E080_15.H"




extern void Tsmos_DeactivateControllerState(void);
void func_8043577C_de(s32 focusEntry) {
    s32 var_v0;

    Tsmos_DeactivateControllerState();
    D_800E54A4->ready = 5;
    D_800E54A4->timer = 4;
    D_800E54A4->focus = focusEntry;
    if (focusEntry == -2) {
        switch(D_801462C8.controllerMode) {
        case 0:D_800E54A4->focus=7;break;
        case 2:D_800E54A4->focus=7;break;
        case 1:D_800E54A4->focus=9;break;
        case 3:D_800E54A4->focus=7;break;
        case 4:D_800E54A4->focus=10;break;
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DCB9C[1] = {
    0x5F444541,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E972C[1] = {
    0x0000003E,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE56C[1] = {
    0x8C180FE8,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDEEC[1] = {
    0x004360AC,
};
#endif
