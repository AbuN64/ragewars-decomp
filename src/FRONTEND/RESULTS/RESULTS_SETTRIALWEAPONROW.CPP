#include "include_asm.h"
#include "COMMON/MENU_OPTIONS_AND_RESULTS.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "FRONTEND/RESULTS_GETWEAPONICONVALUE.H"

/* Finds a menu item identifier in three selection tables, falling back to the first item of the second table. */
extern int g_loadoutWeaponItems[];

extern int g_loadoutColumnOneItems[];

extern int g_loadoutColumnFourItems[];

void Results_SetTrialWeaponRow(u32 row, s32 weaponId, s32 amount) {
    s32 id;
    MenuWidget *element;
    MenuWidget *field;
    s32 value;

    switch (row) {
    case 0:
        id = 0x1DF + ID_SHIFT;
        if (amount == 0) {
            id = 0x149 + OPTION_SHIFT;
        }
        break;
    case 1:
        id = 0x1E0 + ID_SHIFT;
        if (amount == 0) {
            id = 0x14C + OPTION_SHIFT;
        }
        break;
    case 2:
        id = 0x1E1 + ID_SHIFT;
        if (amount == 0) {
            id = 0x14D + OPTION_SHIFT;
        }
        break;
    case 3:
        id = 0x1E2 + ID_SHIFT;
        if (amount == 0) {
            id = 0x14E + OPTION_SHIFT;
        }
        break;
    case 4:
        id = 0x1E3 + ID_SHIFT;
        if (amount == 0) {
            id = 0x14F + OPTION_SHIFT;
        }
        break;
    default:
        id = 0x149 + OPTION_SHIFT;
        break;
    }
    /* the hub's Item view shares the MenuWidget prefix; this unit reads alpha and value through it */
    element = (MenuWidget *) Node_FindWidgetByResourceId(g_trialCatalogueScreen->root, id);
    Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(element, 0x14B + OPTION_SHIFT), 0);
    value = Results_GetWeaponIconValue(weaponId);
    field = (MenuWidget *) Node_FindWidgetByResourceId(element, 0x14A + OPTION_SHIFT);
    field->alpha = 0x64;
    field->value = value;
}

int Results_GetWeaponIconValue(int id) {
 int i;
 for(i=0;i<8;i++) if(g_loadoutWeaponIds[i*4]==id) return g_loadoutWeaponItems[i*4];
 for(i=0;i<4;i++) if(g_trialBonusWeaponIds[i*4]==id) return g_loadoutColumnOneItems[i*4];
 for(i=0;i<3;i++) if(g_trialSpecialWeaponIds[i*4]==id) return g_loadoutColumnFourItems[i*4];
 return g_loadoutColumnOneItems[0];
}
