#include "FRONTEND/8040B45C_33.H"
#include "COMMON/RECRECAT4.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "COMMON/CONTROL.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/MENULISTSCREEN.H"
#include "FRONTEND/80423280_50.H"
#include "FRONTEND/80423280_52.H"
#include "FRONTEND/80423280_53.H"
extern struct ScreenScenarioSetupRefreshSelectedArenaLabel *D_800E4F60;
extern struct Icon D_800E4F64[];
extern void Frontend_SetWidgetFlag08(void *, s32);
extern s32 ScenarioSetup_ResolveArenaFromSelection(s32, s32);

/* Sets the alpha of every catalogue icon on the screen D_800E4F60: for categories 0 to 3 (tables
   D_800E5240, D_800E5214, D_800E51F8 and D_800E51E4) it walks the count ScenarioSetup_GetCategoryEntryCount gives for the
   category's list ScenarioSetup_CategoryToList and, for the first of the forty 16-byte icon records D_800E4F64
   whose key matches the entry, sets the alpha of the item its key names (and of the item its second
   word names unless that is -1) and shows them through func_8040E8D8_de while the alpha is at least
   12. */










extern s32 ScenarioSetup_GetCategoryEntryCount(s32 index);

/* Refreshes the selection on the screen D_800E4F60: for category 0 to 3 at 0x434 it takes the item
   the selection at 0x438 names in the 4-byte table D_800E5240, D_800E5214, D_800E51F8 or
   D_800E51E4 from the window into 0x43C, copies the selection's name into the text at 0x3F4 (the
   default label for selection 0, otherwise the resource name Scene_CopyLevelName reads from
   D_8011FE88 for the entry ScenarioSetup_ResolveArenaFromSelection finds in the category's list ScenarioSetup_CategoryToList), points the
   label at 0x3EC to that text and calls func_80245B28_de. */


#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern void Scene_CopyLevelName(Shared_World *, s32, char *, s32);

extern char *XPlus_UppercaseString(char *);

extern void XPlus_CopyString(char *, char *);


/* Resets the selection screen: maps the menu mode at 0x434 to a category (0 to 2, 1 to 3, 2 to 1,
   otherwise 0), builds the category list through ScenarioSetup_ResolveArenaFromSelection, hides the forty controls of the
   table D_800E4F64 (and each entry's optional second control), refreshes the list, hides five fixed
   widgets and restores the selection, starting from the first entry when nothing was selected. */






extern void Frontend_SetSelectedStage(int, int);




extern void ScenarioSetup_StartRandomCupStage(void);

static inline int map_category(int mode) {
    int category;

    switch (mode) {
        case 3:
            category = 0;
            break;
        case 2:
            category = 1;
            break;
        case 1:
            category = 3;
            break;
        case 0:
            category = 2;
            break;
        default:
            return 0;
    }
    return category;
}

void ScenarioSetup_SetCatalogueAlpha(s32 alpha) {
    MenuWidget *item;
    s32 *table;
    s32 visible;
    s32 category;
    s32 count;
    s32 list;
    s32 found;
    s32 i;
    s32 j;

    visible = alpha >= 12;
    for (category = 0; category < 4; category++) {
        switch (category) {
        case 3:
            table = D_800E51E4;
            list = 3;
            break;
        case 2:
            table = D_800E51F8;
            list = 2;
            break;
        case 0:
            table = D_800E5240;
            list = 0;
            break;
        case 1:
            table = D_800E5214;
            list = 1;
            break;
        default:
            return;
        }
        do {
            count = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(list));
            for (i = 0; i < count; i++) {
                found = 0;
                j = 0;
            scan:
                if (table[i] == D_800E4F64[j].key) {
                    item = Frontend_FindWidgetByResourceId(D_800E4F60->window, (u16)D_800E4F64[j].key);
                    Frontend_SetWidgetFlag08(item, visible);
                    item->alpha = alpha;
                    if (D_800E4F64[j].other != -1) {
                        item = Frontend_FindWidgetByResourceId(D_800E4F60->window, (u16)D_800E4F64[j].other);
                        Frontend_SetWidgetFlag08(item, visible);
                        item->alpha = alpha;
                    }
                    found = 1;
                }
                j++;
                if (j < 40 && found == 0) {
                    goto scan;
                }
            }
        } while (0);
    }
}

void ScenarioSetup_RefreshSelectedArenaLabel(void) {
    s32 *table;
    char buffer[0x40];
    switch (D_800E4F60->category) {
    case 3:
        table = D_800E51E4;
        break;
    case 2:
        table = D_800E51F8;
        break;
    case 1:
        table = D_800E5214;
        break;
    case 0:
        table = D_800E5240;
        break;
    default:
        return;
    }
    D_800E4F60->item = Frontend_FindWidgetByResourceId(D_800E4F60->window, (u16)table[D_800E4F60->selection]);
    if (D_800E4F60->selection == 0) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        XPlus_CopyString(D_800E4F60->text, D_800D34D4_de[0]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        XPlus_CopyString(D_800E4F60->text, D_800E1DA4[g_languageIndex]);
#endif
    } else {
        Scene_CopyLevelName(&g_world,
                      ScenarioSetup_ResolveArenaFromSelection(ScenarioSetup_CategoryToList(D_800E4F60->category), D_800E4F60->selection),
                      buffer, 0x3F);
        XPlus_CopyString(D_800E4F60->text, XPlus_UppercaseString(buffer));
    }
    D_800E4F60->label->text = D_800E4F60->text;
    Cinema_ReleaseSequenceContext();
}

void ScenarioSetup_StartSelectedScenario(void) {
    int category;
    int list;
    int i;

    category = map_category(D_800E4F60->category);
    list = ScenarioSetup_ResolveArenaFromSelection(category, D_800E4F60->selection);
    for (i = 0; i < 40; i++) {
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4F60->window, (u16)D_800E4F64[i].key), 0);
        if (D_800E4F64[i].other != -1) {
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4F60->window, (unsigned short)D_800E4F64[i].other), 0);
        }
    }
    Frontend_SetSelectedStage(category, list);
    Frontend_SetMenuChoiceResult(0x15);
    Frontend_SetWidgetFlag08(D_800E4F60->widgetC, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->widgetE, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->widgetD, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->label, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->widgetB, 0);
    ScenarioSetup_ClearFlagBits();
    if (D_800E4F60->selection == 0) {
        ScenarioSetup_SetCupCategory(category);
        ScenarioSetup_SetCupStageCount(0);
        ScenarioSetup_StartRandomCupStage();
    } else {
        ScenarioSetup_SetCupCategory(-1);
        ScenarioSetup_SetCupStageCount(D_800E4F60->selection);
    }
}
