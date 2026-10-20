#include "include_asm.h"
#include "COMMON/ENTRYRECAT6C.H"

/* Enters the selected menu state and resolves the default destination from the game mode. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/8042E080_15.H"


extern State_func_8043577C_de *D_800E54A4;


extern void func_802A2394_de(void);
void func_8043577C_de(s32 arg0) {
    s32 var_v0;

    func_802A2394_de();
    D_800E54A4->unk4C = 5;
    D_800E54A4->unk50 = 4;
    D_800E54A4->unk3470 = arg0;
    if (arg0 == -2) {
        switch(D_801462D5) {
        case 0:D_800E54A4->unk3470=7;break;
        case 2:D_800E54A4->unk3470=7;break;
        case 1:D_800E54A4->unk3470=9;break;
        case 3:D_800E54A4->unk3470=7;break;
        case 4:D_800E54A4->unk3470=10;break;
        }
    }
}

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCB9C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E972C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE56C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDEEC);
#endif
