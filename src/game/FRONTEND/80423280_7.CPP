#include "include_asm.h"
#include "COMMON/RECRECAT4.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "FRONTEND/80423280_7.H"

/* Finds a menu item identifier in three selection tables, falling back to the first item of the second table. */
extern int D_800E5B44[];

extern int D_800E5BC4[];

extern int D_800E5B14[];

void func_8042854C_de(u32 arg0, s32 arg1, s32 arg2) {
    s32 id;
    MenuWidget *element;
    MenuWidget *field;
    s32 value;

    switch (arg0) {
    case 0:
        id = 0x1DF + ID_SHIFT;
        if (arg2 == 0) {
            id = 0x149 + OPTION_SHIFT;
        }
        break;
    case 1:
        id = 0x1E0 + ID_SHIFT;
        if (arg2 == 0) {
            id = 0x14C + OPTION_SHIFT;
        }
        break;
    case 2:
        id = 0x1E1 + ID_SHIFT;
        if (arg2 == 0) {
            id = 0x14D + OPTION_SHIFT;
        }
        break;
    case 3:
        id = 0x1E2 + ID_SHIFT;
        if (arg2 == 0) {
            id = 0x14E + OPTION_SHIFT;
        }
        break;
    case 4:
        id = 0x1E3 + ID_SHIFT;
        if (arg2 == 0) {
            id = 0x14F + OPTION_SHIFT;
        }
        break;
    default:
        id = 0x149 + OPTION_SHIFT;
        break;
    }
    /* the hub's Item view shares the MenuWidget prefix; this unit reads alpha and value through it */
    element = (MenuWidget *) func_8040EC30_de(D_800E4690->root, id);
    Frontend_SetWidgetFlag08(func_8040EC30_de(element, 0x14B + OPTION_SHIFT), 0);
    value = func_8042863C_de(arg1);
    field = (MenuWidget *) func_8040EC30_de(element, 0x14A + OPTION_SHIFT);
    field->alpha = 0x64;
    field->value = value;
}

int func_8042863C_de(int id) {
 int i;
 for(i=0;i<8;i++) if(D_800E1AFC_de[i*4]==id) return D_800E5B44[i*4];
 for(i=0;i<4;i++) if(D_800E1B7C[i*4]==id) return D_800E5BC4[i*4];
 for(i=0;i<3;i++) if(D_800E1ACC_de[i*4]==id) return D_800E5B14[i*4];
 return D_800E5BC4[0];
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC69C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E922C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE06C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD9EC[1] = {
    0x00000000,
};
#endif
