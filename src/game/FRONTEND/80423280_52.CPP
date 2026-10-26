#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "COMMON/CONTROL.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/80423280_50.H"
#include "FRONTEND/80423280_52.H"
#include "FRONTEND/80423280_53.H"
#include "FRONTEND/8040B45C_33.H"
extern struct ScreenScenarioSetupLoadSetupArenaLabel *D_800E4F60;

/* Stores its argument in D_80154014. */

extern struct MenuSettings D_801462C8;

/* Refreshes the name label of screen D_800E4F60: with no entry at 0x438 it uses the default text
   D_800D34D4_de; otherwise it formats the entry's name from ScenarioSetup_ResolveArenaFromSelection on the list ScenarioSetup_CategoryToList
   returns for 0x434 into a 0x40-byte buffer through D_8011FE88 and takes the text XPlus_UppercaseString
   makes of it. Either text is copied into the screen's label at 0x3F4 through func_802A025C_de, and the
   widget at 0x3EC is pointed at that label. */








extern char *ScenarioSetup_ResolveArenaFromSelection(s32, s32);

extern void Scene_CopyLevelName(Shared_World *, char *, char *, s32);

extern char *XPlus_UppercaseString(char *);

extern void XPlus_CopyString(char *, char *);

/* Calls ScenarioSetup_HideArenaCatalogueWidgets and then ScenarioSetup_SetCatalogueAlpha with 0. */


/* Hides each primary and optional secondary selection widget. */
extern void Frontend_SetWidgetFlag08(void *, s32);

 /* extern */

 /* extern */





/* Returns one; ScenarioSetup_OpenResultsScreen calls it. */
s32 ScenarioSetup_ReturnResultsGateTrue(void) {
    return 1;
}

/* Stores its argument in D_80154010. */

void ScenarioSetup_SetCupCategory(s32 value) {
    D_80154010.index = value;
}

void ScenarioSetup_SetCupStageCount(s32 value) {
    D_80154010.stages = value;
}

void ScenarioSetup_LoadSetupArenaLabel(void) {
    char buffer[0x40];

    if (D_800E4F60->entry == 0) {
        XPlus_CopyString(D_800E4F60->label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800D34D4_de[D_801462C8.language]
#else
D_800D34D4_de[0]
#endif
);
    } else {
        Scene_CopyLevelName(&g_world, ScenarioSetup_ResolveArenaFromSelection(ScenarioSetup_CategoryToList(D_800E4F60->list), D_800E4F60->entry),
                      buffer, 0x3F);
        XPlus_CopyString(D_800E4F60->label, XPlus_UppercaseString(buffer));
    }
    D_800E4F60->widget->text = D_800E4F60->label;
}

void ScenarioSetup_HideSetupCatalogue(void) {
    ScenarioSetup_HideArenaCatalogueWidgets();
    ScenarioSetup_SetCatalogueAlpha(0);
}

/* The catalogue stores word-valued widget identifiers; only the low 16 bits name a widget. */
void ScenarioSetup_HideArenaCatalogueWidgets(void) {
    s32 offset;
    s32 index;
    index = 0;
    do {
        offset = index * 0x10;
        Frontend_SetWidgetFlag08((void *)Frontend_FindWidgetByResourceId((void*)D_800E4F60->field0, (u16)*(s32 *)(&D_800E0F16 - 2 + offset)), 0);
        if (*(s32 *)(&D_800E0F18 + offset) != -1) {
            Frontend_SetWidgetFlag08((void *)Frontend_FindWidgetByResourceId((void*)D_800E4F60->field0, (u16)*(s32 *)(&D_800E0F1A - 2 + offset)), 0);
        }
            index += 1;
    } while (index < 0x28);
}

/* Maps a selection index to its code: 0 gives 5, 1 gives 7, 2 gives 17, 3 gives 11 and anything else
   0. */
int ScenarioSetup_GetCategoryEntryCount(int index) {
    int r;

    switch (index) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 11;
    case 2:
        return 17;
    default:
        r = 0;
        break;
    }
    return r;
}
