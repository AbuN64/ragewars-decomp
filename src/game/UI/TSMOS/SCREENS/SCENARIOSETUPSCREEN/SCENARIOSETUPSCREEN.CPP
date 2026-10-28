#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SCREEN.H"
#include "FRONTEND/MENUTRANSITIONSIGNAL.H"
#include "COMMON/CONTROL.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/MENU_SCREEN_SETUP.H"
#include "FRONTEND/8040B45C_33.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "stddef.h"
#include "COMMON/LEVEL_GOAL.H"
#include "SCENE/802508E0_13.H"
#include "COMMON/PLAYERPROFILES.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "FRONTEND/RESULTS_SETUP_TEXT.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "FRONTEND/RESULTS_SCREEN_TEXT.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "DATA/OVLDAT9/800E5320.H"
#include "FRONTEND/PREVIEW_MODEL_IMAGE.H"
#include "SCENARIOSETUPSCREEN/SCENARIOSETUPSCREEN.H"

void ScenarioSetup_SetCupCategory(s32);

/* 80423280_11.CPP */
#if !defined(VERSION_DE)
/* Advances the menu transition state and updates its visual effects. */

/* The values ScenarioSetup_UpdateSetupTransition loads by address:
 * 0x800E1AF4 = 0.0033333334 (float, D_800EE144 in this cartridge's tables)
 * 0x800E1AF8 = 100.0 (float, D_800EE148 in this cartridge's tables)
 * 0x800E1AFC = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B00 = 2147483600.0 (float, D_800EE150 in this cartridge's tables)
 * 0x800E1B04 = 0.0033333334 (float, D_800EE154 in this cartridge's tables)
 * 0x800E1B08 = 100.0 (float, D_800EE158 in this cartridge's tables)
 * 0x800E1B0C = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B10 = 2147483600.0 (float, D_800EE160 in this cartridge's tables)
 */

void Tsmos_ActivateControllerState(void);



void SmpFlicker_StartFlicker(void *, int);

void SmXlate_SwitchScreen(s32);



/* Resource ids of this screen are numbered per version (relative to us): eu-x 4. */
static inline s32 setupRes(s32 id) {
#if defined(VERSION_EU_X)
    return id + 4;
#else
    return id;
#endif
}

s32 ScenarioSetup_UpdateSetupTransition(void *root, s32 arg1, s32 arg2) {
    ListScreenScreen *countdown;
    f32 var_f0;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 enabled;
    s32 var_v0;
    ListScreenItem *closeLeft;
    ListScreenItem *closeRight;
    ListScreenItem *openLeft;
    ListScreenItem *openRight;
    void *var_a0;
    ListScreenItem *var_a0_2;
    void *var_a0_3;

    if (D_80154020.ready == 1) {
        D_80154020.ready = 0;
        if (D_80154020.value != -1) {
            D_800E4F60->unk44C->alpha = 0x5A;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(D_80154020.value);
            return 0;
        }
        D_800E4F60->unk44C->alpha = 0xFF;
        D_800E4F60->unk3DC = 9;
        if (D_800E4F60->selection == 0) {
            Frontend_SetWidgetFlag08(D_800E4F60->unk440, 1);
            var_a0 = D_800E4F60->unk448;
        } else {
            var_a0 = D_800E4F60->unk444;
        }
        Frontend_SetWidgetFlag08(var_a0, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->label, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3F0, 1);
        goto block_7;
    }
block_7:
    temp_v0 = D_800E4F60->unk3DC;
    switch (temp_v0) {
    case 1:
        openLeft = D_800E4F60->left;
        openLeft->x = (u16) (openLeft->x + (u16)D_800E4F60->leftCount);
        openRight = D_800E4F60->right;
        openRight->x = (u16) (openRight->x - (u16)D_800E4F60->rightCount);
        temp_v0_2 = D_800E4F60->unk3E0 - 1;
        D_800E4F60->unk3E0 = temp_v0_2;
        if (temp_v0_2 <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 1);
            SmpFlicker_StartFlicker(D_800E4F60->text3E4, 4);
            D_800E4F60->unk3DC = 4;
            D_800E4F60->unk3E0 = 4;
        }
        break;
    case 2:
        closeLeft = D_800E4F60->left;
        closeLeft->x = (u16) (closeLeft->x - (u16)D_800E4F60->leftCount);
        closeRight = D_800E4F60->right;
        closeRight->x = (u16) (closeRight->x + (u16)D_800E4F60->rightCount);
        temp_v0_3 = D_800E4F60->unk3E0 - 1;
        D_800E4F60->unk3E0 = temp_v0_3;
        if (temp_v0_3 <= 0) {
            D_800E4F60->unk3DC = 3;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk460 == 0) {
            Tsmos_ActivateControllerState();
            enabled = 0;
            var_a0_3 = D_800E4F60->unk458;
            D_800E4F60->unk460 = 1;
            Frontend_SetWidgetFlag08(var_a0_3, enabled);
        }
        break;
    case 4:
        countdown = D_800E4F60;
        temp_v1 = countdown->unk_3E0;
        temp_v0_4 = temp_v1 - 1;
        if (temp_v0_4 >= 0) {
            var_v0 = temp_v1 - (temp_v1 >= temp_v0_4);
        } else {
            var_v0 = 0;
        }
        countdown->unk_3E0 = var_v0;

        if ((((ListScreenScreen *) D_800E4F60)->unk_3E0 <= 0) && (SmpFlicker_IsFlickerIdle(D_800E4F60->text3E4) != 0)) {
            SmpFlicker_RestoreFlickerValue(D_800E4F60->text3E4);
            ScenarioSetup_SetCatalogueAlpha(0xA);
            D_800E4F60->unk3DC = 9;
        }
        break;
    case 5:
        Frontend_SetWidgetFlag08(D_800E4F60->unk458, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 0);
        ScenarioSetup_ResetSelectionIndicators();
        ScenarioSetup_SetCatalogueAlpha(0);
        D_800E4F60->unk3DC = 2;
        D_800E4F60->unk3E0 = 4;
        Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
        SoundElement_PlayFlatSound(0xE78);
        break;
    case 8:
        temp_v0 = ((ListScreenItem *)Frontend_FindWidgetByResourceId(root, setupRes(0x316)))->alpha;
        temp_s0 = temp_v0 >> 1;
        ScenarioSetup_SetCatalogueAlpha(temp_s0);
        if (temp_s0 < 0xA) {
            D_800E4F60->unk3DC = 3;
            Random_SetMenuChoiceResult(0xB);
            return 0;
        }
        break;
    case 9:
        temp_s0 = ((ListScreenItem *)Frontend_FindWidgetByResourceId(root, setupRes(0x316)))->alpha;
        temp_s0 = (temp_s0 + 1) * 2;
        if (temp_s0 >= 0x42) {
            temp_s0 = 0x41;
            D_800E4F60->unk3DC = 3;
        }
        ScenarioSetup_SetCatalogueAlpha(temp_s0);
        enabled = 1;
        if (D_800E4F60->selection == 0) {
            var_a0_3 = D_800E4F60->unk448;
            Frontend_SetWidgetFlag08(var_a0_3, enabled);
        }
        break;
    default:
        break;
    }
    if (D_800E4F60->unk3DC == 3) {
            temp_a2 = D_800E4F60->unk45C + arg2;
            D_800E4F60->unk45C = temp_a2;
            if (D_80154020.value == -1) {
                if (D_800E4F60->selection == 0) {
                    var_f0 = (Math_Cosf((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->unk448;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                } else {
                    var_f0 = (Math_Cosf((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->item;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                }
            }
        }
        return 0;
}
#endif

#if defined(VERSION_US)
char rodata_unresolved_800DC794[12] =
    "\000\000\000\000\023RAX_INT";
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE164[3] = {
    0x00BA00C9, 0x00BB00C2, 0x00BC00BF,
};
#endif

/* 80408AC4_2.CPP */
#if defined(VERSION_DE)
s32 ScenarioSetup_UpdateSetupTransitionDe(void *root, s32 unused, s32 delta) {
    MenuWidget *item;
    f32 alpha;
    s32 fade;
    s32 count, previous, level;
    SetupScreen *countdown;
    if (D_80154020.ready == 1) {
        D_80154020.ready = 0;
        if (D_80154020.value != -1) {
            D_800E4F60->unk44C->alpha = 0x5A;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(D_80154020.value);
            return 0;
        }
        D_800E4F60->unk44C->alpha = 0xFF;
        D_800E4F60->unk3DC = 9;
        if (D_800E4F60->selection == 0) {
            Frontend_SetWidgetFlag08(D_800E4F60->unk440, 1);
            item = D_800E4F60->unk448;
        } else item = D_800E4F60->unk444;
        Frontend_SetWidgetFlag08(item, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->label, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3F0, 1);
    }
    switch (D_800E4F60->unk3DC) {
    case 1:
        D_800E4F60->left->x += (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x -= (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 1);
            SmpFlicker_StartFlicker(D_800E4F60->text3E4, 4);
            D_800E4F60->unk3DC = 4;
            D_800E4F60->unk3E0 = 4;
        }
        break;
    case 2:
        D_800E4F60->left->x -= (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x += (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            D_800E4F60->unk3DC = 3;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk460 == 0) {
            Tsmos_ActivateControllerState();
            D_800E4F60->unk460 = 1;
            Frontend_SetWidgetFlag08(D_800E4F60->unk458, 0);
        }
        break;
    case 4:
        countdown = D_800E4F60;
        previous = countdown->unk3E0;
        count = previous - 1;
        /* fakematch: preserve the target's comparison-based decrement,
         * which a normal saturating countdown would simplify to max(previous - 1, 0). */
        if (count >= 0) count = previous - (previous >= count);
        else count = 0;
        countdown->unk3E0 = count;
        if (D_800E4F60->unk3E0 <= 0 && SmpFlicker_IsFlickerIdle(D_800E4F60->text3E4)) {
            SmpFlicker_RestoreFlickerValue(D_800E4F60->text3E4);
            ScenarioSetup_SetCatalogueAlpha(10);
            D_800E4F60->unk3DC = 9;
        }
        break;
    case 5:
        Frontend_SetWidgetFlag08(D_800E4F60->unk458, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 0);
        ScenarioSetup_ResetSelectionIndicators();
        ScenarioSetup_SetCatalogueAlpha(0);
        D_800E4F60->unk3DC = 2;
        D_800E4F60->unk3E0 = 4;
        Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
        SoundElement_PlayFlatSound(0xE78);
        break;
    case 6: case 7: break;
    case 8:
        level = Frontend_FindWidgetByResourceId(root, 0x312)->alpha;
        fade = level >> 1;
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (fade < 10) {
            D_800E4F60->unk3DC = 3;
            Random_SetMenuChoiceResult(11);
            return 0;
        }
        break;
    case 9:
        fade = Frontend_FindWidgetByResourceId(root, 0x312)->alpha;
        fade = (fade + 1) * 2;
        if (fade > 65) { fade = 65; D_800E4F60->unk3DC = 3; }
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (D_800E4F60->selection == 0) Frontend_SetWidgetFlag08(D_800E4F60->unk448, 1);
        break;
    }
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk45C += delta;
        if (D_80154020.value == -1) {
            if (D_800E4F60->selection == 0) {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->unk448;
                item->alpha = (u32)alpha;
            } else {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->item;
                item->alpha = (u32)alpha;
            }
        }
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDAE4[3] = {
    0x25642525, 0x00000000, 0x3E99999A,
};
#endif

/* 80423280_50.CPP */
typedef struct ArenaCatalogueEntry {
    s32 key;
    s32 other;
    s32 reserved;
    s32 value;
} ArenaCatalogueEntry;
extern ArenaCatalogueEntry D_800E4F64[];

/* Sets the alpha of every catalogue icon on the screen D_800E4F60: for categories 0 to 3 (tables
   g_cupCategoryTwoArenaControls, g_cupCategoryThreeArenaControls, g_cupCategoryOneArenaControls and g_cupCategoryZeroArenaControls) it walks the count ScenarioSetup_GetCategoryEntryCount gives for the
   category's list ScenarioSetup_CategoryToList and, for the first of the forty 16-byte icon records D_800E4F64
   whose key matches the entry, sets the alpha of the item its key names (and of the item its second
   word names unless that is -1) and shows them through func_8040E8D8_de while the alpha is at least
   12. */

/* Refreshes the selection on the screen D_800E4F60: for category 0 to 3 at 0x434 it takes the item
   the selection at 0x438 names in the 4-byte table g_cupCategoryTwoArenaControls, g_cupCategoryThreeArenaControls, g_cupCategoryOneArenaControls or
   g_cupCategoryZeroArenaControls from the window into 0x43C, copies the selection's name into the text at 0x3F4 (the
   default label for selection 0, otherwise the resource name Scene_CopyLevelName reads from
   D_8011FE88 for the entry ScenarioSetup_ResolveArenaFromSelection finds in the category's list ScenarioSetup_CategoryToList), points the
   label at 0x3EC to that text and calls func_80245B28_de. */

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern void Scene_CopyLevelName(Shared_World *, s32, char *, s32);

extern char *XPlus_UppercaseString(char *);

extern char *XPlus_CopyString(char *, char *);

/* Resets the selection screen: maps the menu mode at 0x434 to a category (0 to 2, 1 to 3, 2 to 1,
   otherwise 0), builds the category list through ScenarioSetup_ResolveArenaFromSelection, hides the forty controls of the
   table D_800E4F64 (and each entry's optional second control), refreshes the list, hides five fixed
   widgets and restores the selection, starting from the first entry when nothing was selected. */

extern s32 ScenarioSetup_StartRandomCupStage(void);

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
            table = g_cupCategoryZeroArenaControls;
            list = 3;
            break;
        case 2:
            table = g_cupCategoryOneArenaControls;
            list = 2;
            break;
        case 0:
            table = g_cupCategoryTwoArenaControls;
            list = 0;
            break;
        case 1:
            table = g_cupCategoryThreeArenaControls;
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
        table = g_cupCategoryZeroArenaControls;
        break;
    case 2:
        table = g_cupCategoryOneArenaControls;
        break;
    case 1:
        table = g_cupCategoryThreeArenaControls;
        break;
    case 0:
        table = g_cupCategoryTwoArenaControls;
        break;
    default:
        return;
    }
    D_800E4F60->item = Frontend_FindWidgetByResourceId(D_800E4F60->window, (u16)table[D_800E4F60->selection]);
    if (D_800E4F60->selection == 0) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        XPlus_CopyString(D_800E4F60->text, g_matchOptionLabelSlots[0]);
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
    Random_SetSelectedStage(category, list);
    Random_SetMenuChoiceResult(0x15);
    Frontend_SetWidgetFlag08(((struct ScreenScenarioSetupRefreshSelectedArenaLabel *)D_800E4F60)->widgetC, 0);
    Frontend_SetWidgetFlag08(((struct ScreenScenarioSetupRefreshSelectedArenaLabel *)D_800E4F60)->widgetE, 0);
    Frontend_SetWidgetFlag08(((struct ScreenScenarioSetupRefreshSelectedArenaLabel *)D_800E4F60)->widgetD, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->label, 0);
    Frontend_SetWidgetFlag08(((struct ScreenScenarioSetupRefreshSelectedArenaLabel *)D_800E4F60)->widgetB, 0);
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

/* 80423280_51.CPP */
/* Starts the next stage of the current cup D_80154010 unless ScenarioSetup_IsCupComplete reports the cup over:
   draws random stage numbers below the cup's size (5, 7, 17 or 11 stages) until one not yet marked
   in the played set at D_80154018 turns up (giving up after 15000 draws), marks it, counts the stage in
   D_80154014, maps it through the cup's stage table to an arena id, finds that id among the 40
   arena entries at D_800E4F64 and starts the cup with the entry's value through Random_SetSelectedStage.
   Returns 1 when a stage was started, else 0. */


extern s32 Defs_TestBit(u8 *, s32);

extern void Defs_SetBitValue(void *, s32, s32);

static inline s32 cup_stages(s32 cup) {
    switch (cup) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 11;
    case 2:
        return 17;
    }
    return 0;
}

static inline s32 stage_arena(s32 cup, s32 stage) {
    s32 *table;
    s32 id;
    s32 value;
    s32 found;
    s32 i;

    value = 0;
    if (stage == 0) {
        stage = 1;
    }
    switch (cup) {
    case 0:
        table = g_cupCategoryZeroArenaControls;
        break;
    case 1:
        table = g_cupCategoryOneArenaControls;
        break;
    case 3:
        table = g_cupCategoryThreeArenaControls;
        break;
    case 2:
        table = g_cupCategoryTwoArenaControls;
        break;
    default:
        return 0;
    }
    id = table[stage];
    found = 0;
    i = 0;
    do {
        if (id == D_800E4F64[i].key) {
            found = 1;
            value = D_800E4F64[i].value;
        }
        i++;
    } while (i < 40 && !found);
    return value;
}

s32 ScenarioSetup_StartRandomCupStage(void) {
    s32 started;
    s32 found;
    s32 stage;
    s32 draws;
    s32 size;

    started = 0;
    if (ScenarioSetup_IsCupComplete() == 0) {
        started = 1;
        stage = 0;
        draws = 0;
        found = 0;
        size = cup_stages(D_80154010.index) - 1;
        while (!found) {
            stage = GraphU64_NextRandom() % size + 1;
            if (Defs_TestBit(D_80154010.played, stage) == 0) {
                found = 1;
                Defs_SetBitValue(D_80154010.played, stage, found);
            }
            draws++;
            if (draws >= 15001) {
                found = 1;
            }
        }
        D_80154010.stages++;
        Random_SetSelectedStage(D_80154010.index, stage_arena(D_80154010.index, stage));
    }
    return started;
}

/* Returns whether D_80154010 holds anything other than -1; ScenarioSetup_SetCupCategory stores it. */

s32 ScenarioSetup_IsCupSelected(void) {
    return D_80154010.index != -1;
}

s32 ScenarioSetup_IsCupComplete(void) {
    s32 complete = 1;
    if (D_80154010.index >= 0) {
        complete = cup_stages(D_80154010.index);
        complete = (D_80154010.stages + 1) == complete;
    }
    return complete;
}

/* 80423280_52.CPP */

/* Stores its argument in D_80154014. */


/* Refreshes the name label of screen D_800E4F60: with no entry at 0x438 it uses the default text
   g_matchOptionLabelSlots; otherwise it formats the entry's name from ScenarioSetup_ResolveArenaFromSelection on the list ScenarioSetup_CategoryToList
   returns for 0x434 into a 0x40-byte buffer through D_8011FE88 and takes the text XPlus_UppercaseString
   makes of it. Either text is copied into the screen's label at 0x3F4 through func_802A025C_de, and the
   widget at 0x3EC is pointed at that label. */


extern void Scene_CopyLevelName(Shared_World *, s32, char *, s32);

/* Calls ScenarioSetup_HideArenaCatalogueWidgets and then ScenarioSetup_SetCatalogueAlpha with 0. */

/* Hides each primary and optional secondary selection widget. */

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

    if (D_800E4F60->selection == 0) {
        XPlus_CopyString(D_800E4F60->text,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
g_matchOptionLabelSlots[D_801462C8.language]
#else
g_matchOptionLabelSlots[0]
#endif
);
    } else {
        Scene_CopyLevelName(&g_world, ScenarioSetup_ResolveArenaFromSelection(ScenarioSetup_CategoryToList(D_800E4F60->category), D_800E4F60->selection),
                      buffer, 0x3F);
        XPlus_CopyString(D_800E4F60->text, XPlus_UppercaseString(buffer));
    }
    D_800E4F60->label->text = D_800E4F60->text;
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
        Frontend_SetWidgetFlag08((void *)Frontend_FindWidgetByResourceId((void*)D_800E4F60->window, (u16)*(s32 *)(&D_800E0F16 - 2 + offset)), 0);
        if (*(s32 *)(&D_800E0F18 + offset) != -1) {
            Frontend_SetWidgetFlag08((void *)Frontend_FindWidgetByResourceId((void*)D_800E4F60->window, (u16)*(s32 *)(&D_800E0F1A - 2 + offset)), 0);
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

/* CODE_8042B398.CPP */
extern s32 D_800E0F20[];
s32 ScenarioSetup_ResolveArenaFromSelection(s32 arg0, s32 arg1) {
    s32 result = 0;
    s32 *table;
    s32 key;
    s32 found;
    s32 i;
    if (arg1 == 0) {
        arg1 = 1;
    }
    switch (arg0) {
    case 0:
        table = g_cupCategoryZeroArenaControls;
        break;
    case 1:
        table = g_cupCategoryOneArenaControls;
        break;
    case 3:
        table = g_cupCategoryThreeArenaControls;
        break;
    case 2:
        table = g_cupCategoryTwoArenaControls;
        break;
    default:
        return 0;
    }
    key = table[arg1];
    found = 0;
    i = 0;
    do {
        if (key == D_800E4F64[i].key) {
            found = 1;
            result = D_800E0F20[i * 4];
        }
        i++;
    } while ((i < 0x28) && (found == 0));
    return result;
}

s32 ScenarioSetup_CategoryToList(s32 category) {
    s32 list;
    switch (category) {
    default:
        list = 0;
        break;
    case 2:
        list = 1;
        break;
    case 1:
        list = 3;
        break;
    case 0:
        list = 2;
        break;
    }
    return list;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 ScenarioSetup_ReturnSetupEventZero(void) {
    return 0;
}

void ScenarioSetup_ResetSelectionIndicators(void) {
    D_800E4F60->unk454->alpha = 0xFF;
    D_800E4F60->unk450->alpha = 0xFF;
    Frontend_SetWidgetFlag08(D_800E4F60->unk450, 1);
    Frontend_SetWidgetFlag08(D_800E4F60->unk454, 1);
    D_800E4F60->unk46C = 0;
}

extern void Defs_SetBitValue(void *, s32, s32);

/* Clears the first 0x28 bits of the bit set D_80154018 (bit i set to 0 through Defs_SetBitValue). */
void ScenarioSetup_ClearFlagBits(void) {
    s32 i;

    for (i = 0; i < 0x28; i++) {
        Defs_SetBitValue(D_80154010.played, i, 0);
    }
}

/* Closes the setup screen D_800E4F60: releases it through Cache_FreeMemory, runs Tsmos_ActivateControllerState and
   Menu_ReleaseOptionsScene, then clears the pointer. Returns zero. */
s32 ScenarioSetup_CloseSetupScreen(void) {
    Cache_FreeMemory(D_800E4F60);
    Tsmos_ActivateControllerState();
    Menu_ReleaseOptionsScene();
    D_800E4F60 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 ScenarioSetup_ReturnSetupEventZeroAlt(void) {
    return 0;
}

/** Begin setup confirmation when the pending state and input event permit it. */
s32 ScenarioSetup_BeginSetupConfirmation(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 v = D_800E4F60->unk3DC;

    if (v != 3) {
        return 0;
    }
    if (D_80154020.value != -1) {
        return 0;
    }
    if ((u32)a2 >> 16 != v) {
        return 0;
    }
    if (a3 != 0) {
        return 0;
    }

    MarkMenuEventHandled();
    D_800E4F60->unk3DC = 8;
    ScenarioSetup_SetCatalogueAlpha(0x41);

    Frontend_SetWidgetFlag08(D_800E4F60->unk440, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk444, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->label, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk3F0, 0);

    D_800E4F60->unk44C->alpha = 0x5A;
    SoundElement_PlayFlatSound(0xE7C);

    return 0;
}

extern void Model_SetPreviewModel(void *, s32);
#define SCR4D4 ((struct ScreenScenarioSetupSelectPreviousCatalogueItem *)D_800E4F60)
s32 ScenarioSetup_SelectPreviousCatalogueItem(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 changed;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    if (SCR4D4->category != 0) {
        if (SCR4D4->selection > 0) {
            changed = 1;
            SCR4D4->selection = SCR4D4->selection - 1;
        }
    } else if (SCR4D4->selection >= 11) {
        s32 next = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(0));
        if (SCR4D4->selection + 1 < next) {
            changed = 1;
            SCR4D4->selection = SCR4D4->selection + 1;
        }
    } else if (SCR4D4->selection > 0) {
        SCR4D4->selection = SCR4D4->selection - 1;
        changed = 1;
    }
    if (changed != 1) {
        return 0;
    }
    SoundElement_PlayFlatSound(0xE7D);
    ScenarioSetup_ResetSelectionIndicators();
    SCR4D4->word45C = 0;
    SCR4D4->word464 = 0;
    SCR4D4->item->alpha = 0x41;
    ScenarioSetup_RefreshSelectedArenaLabel();
    if (SCR4D4->selection != 0) {
        return 0;
    }
    Frontend_SetWidgetFlag08(SCR4D4->left, 1);
    Frontend_SetWidgetFlag08(SCR4D4->marker, 1);
    SCR4D4->marker->x = SCR4D4->category * 34 + 0x7C;
    Frontend_SetWidgetFlag08(SCR4D4->right, 0);
    Model_SetPreviewModel(SCR4D4->view, SCR4D4->category + 0xEA6);
    return 0;
}
#undef SCR4D4

/** Select the next setup item, reversing the displayed order on the second page. */
s32 ScenarioSetup_SelectNextSetupItem(void *unused0, void *unused1, void *unused2, s32 event) {
    SetupScreen *screen;
    s32 changed;
    s32 count;
    s32 next;
    s32 limit;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    count = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(D_800E4F60->category));
    screen = D_800E4F60;
    if (screen->category != 0) {
        next = screen->selection + 1;
        if (next < count) {
            changed = 1;
            screen->selection = next;
        }
    } else {
        if (screen->selection >= 11) {
            next = screen->selection - 1;
            limit = 10;
        } else {
            limit = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(0));
            screen = D_800E4F60;
            next = screen->selection + 1;
            if (next == limit) {
                goto moved;
            }
            limit = 11;
        }
        if (next != limit) {
            changed = 1;
            screen->selection = next;
        }
    }
moved:
    if (changed != 1) {
        return 0;
    }
    SoundElement_PlayFlatSound(0xE7D);
    ScenarioSetup_ResetSelectionIndicators();
    D_800E4F60->unk45C = 0;
    D_800E4F60->unk464 = 0;
    D_800E4F60->item->alpha = 0x41;
    ScenarioSetup_RefreshSelectedArenaLabel();
    Frontend_SetWidgetFlag08(D_800E4F60->unk440, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk444, 1);
    Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
    return 0;
}

#define SCR78C ((struct ScreenScenarioSetupSelectPreviousCatalogueCategory *)D_800E4F60)
s32 ScenarioSetup_SelectPreviousCatalogueCategory(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 changed;
    s32 count;
    s32 mirror;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    if (SCR78C->category != 0) {
        changed = 1;
        SCR78C->category = SCR78C->category - 1;
    } else if ((u32)(SCR78C->selection - 5) < 6) {
        mirror = 21 - SCR78C->selection;
        if (mirror < ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(0))) {
            changed = 1;
            SCR78C->selection = mirror;
        }
    }
    if (changed != 1) {
        return 0;
    }
    SoundElement_PlayFlatSound(0xE7D);
    ScenarioSetup_ResetSelectionIndicators();
    SCR78C->word45C = 0;
    SCR78C->word464 = 0;
    SCR78C->item->alpha = 0x41;
    count = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(SCR78C->category));
    if (SCR78C->selection >= count) {
        SCR78C->selection = count - 1;
    }
    ScenarioSetup_RefreshSelectedArenaLabel();
    if (SCR78C->selection == 0) {
        Model_SetPreviewModel(SCR78C->view, SCR78C->category + 0xEA6);
        Frontend_SetWidgetFlag08(SCR78C->marker, 1);
        SCR78C->marker->x = SCR78C->category * 34 + 0x7C;
    }
    return 0;
}
#undef SCR78C

#define SCR904 ((struct ScreenScenarioSetupSelectPreviousCatalogueCategory *)D_800E4F60)
s32 ScenarioSetup_SelectNextCatalogueCategory(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 changed;
    s32 count;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    if (SCR904->category != 3) {
        changed = SCR904->category == 0;
        if (changed) {
            changed = 1;
            if (SCR904->selection >= 11) {
                SCR904->selection = 21 - SCR904->selection;
            } else {
                SCR904->category = changed;
            }
        } else {
            changed = 1;
            SCR904->category = SCR904->category + changed;
        }
    }
    if (changed != 1) {
        return 0;
    }
    SoundElement_PlayFlatSound(0xE7D);
    ScenarioSetup_ResetSelectionIndicators();
    SCR904->word45C = 0;
    SCR904->word464 = 0;
    SCR904->item->alpha = 0x41;
    count = ScenarioSetup_GetCategoryEntryCount(ScenarioSetup_CategoryToList(SCR904->category));
    if (SCR904->selection >= count) {
        SCR904->selection = count - 1;
    }
    ScenarioSetup_RefreshSelectedArenaLabel();
    if (SCR904->selection == 0) {
        Model_SetPreviewModel(SCR904->view, SCR904->category + 0xEA6);
        Frontend_SetWidgetFlag08(SCR904->marker, 1);
        SCR904->marker->x = SCR904->category * 34 + 0x7C;
    }
    return 0;
}
#undef SCR904

s32 ScenarioSetup_EndSetupInput(void) {
    MarkMenuEventHandled();
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk3DC = 5;
        D_800E4F60->unk3E0 = 4;
        return 0;
    }
    return 0;
}

/* Calls ScenarioSetup_StartSelectedScenario while the setup screen D_800E4F60 is in mode 3, and returns zero. */
s32 ScenarioSetup_RefreshSetupScreen(void) {
    if (D_800E4F60->unk3DC == 3) {
        ScenarioSetup_StartSelectedScenario();
        return 0;
    }
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5284, an actor kind at D_800E5288 and a handler at D_800E528C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8042BCB0)(void *, s32, s32, s32, s32);

extern Handler8042BCB0 D_800E528C;
s32 ScenarioSetup_DispatchCatalogueEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042BCB0 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E528C != 0) {
        wildcard = 0x7530;
        entry = &D_800E528C;
        index = 0;
        do {
            if (D_800E5284[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5288[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}

extern func_8042CE54_S1 *D_800E53C0;
extern s8 D_80102B0D[], D_800FEB0E[];
extern void Frontend_InitMenuImage(s32 *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(s32 *);
extern void Frontend_AccumulatePlayerStatistics(void);
extern void Match_UpdateMatchCounters(void *, s32);
extern void Achieve_MarkLevelPlayed(s32);

extern void Widget_SetWidgetFlag100(void *, s32);
extern s32 Widget_ListHasFlag100(void *);
extern void Scene_CopyLevelName(Shared_World *, s32, char *, s32);
extern char *XPlus_CopyString(char *, char *);

s32 ScenarioSetup_OpenResultsScreen(void *root) {
    char buffer[64];
    MenuWidget *item;
    func_8042CE54_S1 *screen;
    Shared_Game *game;
    Shared_Game *slot;
    Shared_PlayerSettingsRecord *config;
    s32 i, offset;

    D_800E53C0 = (void *)Cache_AllocateMemory(0x330);
    D_800E53C0->unkE0 = root;
    Frontend_SetWidgetFlag08(root, 0);
    Frontend_InitMenuImage(D_800E53C0->transition, 0x67, 0, 0, 0);
    Frontend_StartMenuImageTransition(D_800E53C0->transition);
    D_800E53C0->active = 1;
    Frontend_FindWidgetByResourceId(root, 0x234 + RESULTS_MENU_SHIFT)->alpha = 110;
    Frontend_FindWidgetByResourceId(root, 0x239 + RESULTS_MENU_SHIFT)->alpha = 20;
    Frontend_FindWidgetByResourceId(root, 0x236 + RESULTS_MENU_SHIFT)->alpha = 20;
    Frontend_AccumulatePlayerStatistics();
    screen = D_800E53C0;
    for (i = 0; i < 8; i++) {
        screen->icons[i][0] = -1;
        screen->icons[i][1] = -1;
    }
    D_800E53C0->selection = -1;
    ScenarioSetup_SortResultsPlayers();
    game = &D_801462C8;
    switch (game->controllerMode) {
    case 0:
        Match_UpdateMatchCounters(D_800E53C0->data, D_8015402C);
        Frontend_AwardResultAchievements();
        D_800E53C0->mode = 0;
        break;
    case 2:
        if (game->humanWon == 1) {
            D_800E53C0->mode = 0;
            Frontend_AwardResultMilestones();
            config = game->playerSettings;
            for (i = 0; i < 4; i++) {
                if (config[i].enabled == 1 && config[i].locked == 0) Achieve_MarkLevelPlayed(i);
            }
        } else D_800E53C0->mode = 1;
        break;
    }
    slot = &D_801462C8;
    switch (slot->controllerMode) {
    case 0:
        ScenarioSetup_FillResultRows();
        break;
    case 2:
        screen = D_800E53C0;
        if (screen->mode == 1) {
            screen->first = 0;
            screen->count = 0;
            ScenarioSetup_HideResultCatalogueWidgets();
            item = Frontend_FindWidgetByResourceId(root, 0x266 + RESULTS_MENU_SHIFT);
            Frontend_SetWidgetFlag08(item, 1);
            item->alpha = 115;
            item->text = resultsUnavailable(slot);
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(root, RESULTS_RIGHT_ITEM), 0);
        } else if (screen->selection != -1) {
            screen->first = 0;
            screen->count = 0;
            ScenarioSetup_HideResultCatalogueWidgets();
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(root, RESULTS_RIGHT_ITEM), 0);
            ScenarioSetup_InitResultModelPreview();
        } else {
            ScenarioSetup_FillResultRows();
        }
        break;
    }
    SmpButton_WrapButtonWidget(0x237 + RESULTS_MENU_SHIFT);
    SmpButton_WrapButtonWidget(0x238 + RESULTS_MENU_SHIFT);
    SmpButton_WrapButtonWidget(0x23C + RESULTS_MENU_SHIFT);
    Widget_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    i = 0;
    offset = 0;
    do {
        i++;
        if (D_80102B0D[offset] >= 0 && D_800FEB0E[offset] == 0) {
            Widget_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, 0x238 + RESULTS_MENU_SHIFT), 0);
            break;
        }
        offset += 400;
    } while (i < 4);
    if (Widget_ListHasFlag100(Frontend_FindWidgetByResourceId(root, 0x238 + RESULTS_MENU_SHIFT)) == 0 && ScenarioSetup_IsCupSelected() == 1 && ScenarioSetup_ReturnResultsGateTrue() == 0) {
        Widget_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    }
    item = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, RESULTS_HEADING1);
    if (D_8014DD98.kind == 0) item->text = resultsFirstHeading();
    else item->text = resultsSecondHeading();
    item = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, RESULTS_HEADING2);
    switch (D_8014DD98.kind) {
    case 3: item->text = resultsFirstHeading(); break;
    case 0: item->text = resultsFourthHeading(); break;
    case 1:
    default: item->text = resultsThirdHeading(); break;
    }
    item = Frontend_FindWidgetByResourceId(root, 0x235 + RESULTS_MENU_SHIFT);
    Scene_CopyLevelName(&g_world, D_8015402C, buffer, 63);
    XPlus_CopyString(D_800E53C0->name, XPlus_UppercaseString(buffer));
    item->text = D_800E53C0->name;
    D_800E53C0->buttonAddress = (s32)Frontend_FindWidgetByResourceId(root, 0x23D + RESULTS_MENU_SHIFT);
    D_800E53C0->dirty = 1;
    D_80145088.status[7] = 1;
    D_800E53C0->phase = 0;
    Tsmos_DeactivateControllerState();
    return 0;
}

extern s32 Key_FindKeyIndex(s32);
extern char *XPlus_CopyString(char *,char *);
extern char *Match_UpdateRankText(s32);
extern s32 XStdio_FormatBuffer(void *,const char *,...);
extern void Frontend_ShowResultRankBadge(s32,s32,u16);
/* Fill the four visible player rows of the match results screen. */
void ScenarioSetup_FillResultRows(void) {
    s32 row, player, attempts, percent;
    func_8041F2A0_Config *record;
    MenuWidget *widget, *pending;
    char *name;

    ScenarioSetup_HideResultCatalogueWidgets();
    for (row = 0; row < 4; row++) {
        if (row >= D_800E53C0->count) return;
        player = D_800E53C0->players[D_800E53C0->first + row];
        record = &g_playerSettings[player];

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[0]);
        Frontend_SetWidgetFlag08(widget, 1);
        widget->alpha = 0x96;
        pending = widget;
        pending->value = D_800E3A58[Key_FindKeyIndex(record->kind)].portrait;

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[2]);
        Frontend_SetWidgetFlag08(widget, 1);
        widget->alpha = 0x19;

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[4]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        if (record->out == 0) {
            widget->text = D_80102B00[player].name;
        } else {
            name = record->name;
            XPlus_CopyString(name, XPlus_UppercaseString(name));
            widget->text = name;
        }

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[6]);
        widget->alpha = 0x73;
        Frontend_SetWidgetFlag08(widget, 1);
        if (record->out == 0) widget->text = Match_UpdateRankText(player);
        else widget->text = resultsRankText(record->rank);

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[8]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        XStdio_FormatBuffer(D_800E53C0->killText[row], resultsNumberFormat(), record->kills);
        widget->text = D_800E53C0->killText[row];

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[10]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        XStdio_FormatBuffer(D_800E53C0->scoreText[row], resultsNumberFormat(), record->score + record->total);
        *&widget->text = D_800E53C0->scoreText[row];

        if (D_8014DD98.kind == 0) {
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[12]), 0);
            Frontend_ShowResultRankBadge(player, row, RESULTS_RANK_GROUP);
        } else {
            widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[12]);
            widget->alpha = 0xAF;
            Frontend_SetWidgetFlag08(widget, 1);
            attempts = D_800FF140_de[player];
            percent = 0;
            if (attempts > 0) percent = D_800FEAE0[player] * 100 / attempts;
            XStdio_FormatBuffer(D_800E53C0->ratioText[row], resultsPercentFormat(), percent);
            widget->text = D_800E53C0->ratioText[row];
        }

        if (D_8014DD98.kind == 3) {
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[14]), 0);
            Frontend_ShowResultRankBadge(player, row, RESULTS_SECONDARY_GROUP);
        } else {
            widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[14]);
            widget->alpha = 0xAF;
            Frontend_SetWidgetFlag08(widget, 1);
            pending = widget;
            switch (D_8014DD98.kind) {
            case 0:
                XStdio_FormatBuffer(D_800E53C0->valueText[row], resultsNumberFormat(), record->other);
                break;
            case 1:
                XStdio_FormatBuffer(D_800E53C0->valueText[row], resultsNumberFormat(), record->selected);
                break;
            default:
                XStdio_FormatBuffer(D_800E53C0->valueText[row], resultsNumberFormat(), 0);
                break;
            }
            pending->text = D_800E53C0->valueText[row];
        }

        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[16]);
        Frontend_SetWidgetFlag08(widget, 0);
        widget->alpha = 0x96;
        widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[18]);
        Frontend_SetWidgetFlag08(widget, 0);
        widget->alpha = 0x96;
        if (record->out == 0) {
            if (D_800E53C0->icons[player][0] != -1) {
                widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[16]);
                Frontend_SetWidgetFlag08(widget, 1);
                widget->value = D_800E01B0_de[D_800E53C0->icons[player][0]];
            }
            if (D_800E53C0->icons[player][1] != -1) {
                widget = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[row].ids[18]);
                Frontend_SetWidgetFlag08(widget, 1);
                widget->value = D_800E01B0_de[D_800E53C0->icons[player][1]];
            }
        }
        pending = 0;
    }
}

/* The game settings record. */
static inline Shared_Game *resultsGame(void) { return &D_801462C8; }

static inline LevelGoal *levelGoal(void) { return &D_8014DD98; }
static inline CGameStatus *gameStatus(void) { return &resultsGame()->counters; }
static inline s32 resultsTeamTotal(s32 group) {
    if (levelGoal()->kind == 0) return gameStatus()->counts[group];
    return gameStatus()->scores[group];
}
static inline Shared_PlayerSettingsRecord *playerSettings(void) { return resultsGame()->playerSettings; }

/* Swap two sort entries through the caller's temp. */
#define RESULTS_SWAP(x, y) do { temp = x; x = y; y = temp; } while (0)
/* Swap the joined players at slots n and n + 1. */
#define RESULTS_SWAP_PLAYERS(n) do { RESULTS_SWAP(D_800E53C0->players[n], D_800E53C0->players[(n) + 1]); } while (0)
/* Order the joined players for the results screen: in team games (goal kinds 0 and 3) teams by
 * total, players by their team's total, then players within each team by the mode's score; otherwise
 * players by the mode's score. Ties fall back to the kill score. */
void ScenarioSetup_SortResultsPlayers(void) {
    s32 groups[5];
    s32 i, j, k, mode, temp, leftTotal, rightTotal, group, a, b, leftKills, rightKills, leftScore, rightScore, nextTotal;

    D_800E53C0->first = 0;
    D_800E53C0->count = 0;
    /* leftKills doubles as the empty-slot marker while the slots are cleared. */
    for (i = 0, leftKills = -1; i < 8; i++) {
        D_800E53C0->players[i] = leftKills;
        if (playerSettings()[i].enabled == 1) {
            D_800E53C0->players[D_800E53C0->count] = i;
            D_800E53C0->count++;
        }
    }
    mode = Frontend_GetMatchEndReason();
    if (mode == 0) {
        switch (D_8014DD98.kind) {
        case 2: mode = 1; break;
        case 1: mode = 2; break;
        case 0: mode = 3; break;
        default: mode = 1; break;
        }
    }
    if (D_8014DD98.kind == 3 || D_8014DD98.kind == 0) {
        for (i = 4; i >= 0; i--) groups[i] = i;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                a = groups[j];
                leftTotal = resultsTeamTotal(a);
                b = groups[j + 1];
                rightTotal = resultsTeamTotal(b);
                if (leftTotal < rightTotal) {
                    RESULTS_SWAP(groups[j], groups[j + 1]);
                }
            }
        }
        for (j = 0; j < D_800E53C0->count; j++) {
            for (k = 0; k < D_800E53C0->count - 1; k++) {
                a = D_800E53C0->players[k];
                leftTotal = resultsGame()->playerSettings[a].rank;
                if (leftTotal >= 5) leftTotal = -1;
                else leftTotal = resultsTeamTotal(leftTotal);
                b = D_800E53C0->players[k + 1];
                rightTotal = resultsGame()->playerSettings[b].rank;
                if (rightTotal >= 5) nextTotal = -1;
                else nextTotal = resultsTeamTotal(rightTotal);
                if (leftTotal < nextTotal) {
                    RESULTS_SWAP_PLAYERS(k);
                }
            }
        }
        for (i = 0; i < 5; i++) {
            group = groups[i];
            for (j = 0; j < D_800E53C0->count; j++) {
                for (k = 0; k < D_800E53C0->count - 1; k++) {
                    a = D_800E53C0->players[k];
                    b = D_800E53C0->players[k + 1];
                    leftKills = resultsGame()->playerSettings[a].score;
                    rightKills = resultsGame()->playerSettings[b].score;
                    if (resultsGame()->playerSettings[a].rank == group && resultsGame()->playerSettings[b].rank == group) {
                        switch (mode) {
                        case 1: leftScore = leftKills; rightScore = rightKills; break;
                        case 3: leftScore = resultsGame()->playerSettings[a].resultAlternate; rightScore = resultsGame()->playerSettings[b].resultAlternate; break;
                        default: leftScore = leftKills; rightScore = rightKills; break;
                        }
                        if (leftScore < rightScore || (leftScore == rightScore && leftKills < rightKills)) {
                            RESULTS_SWAP_PLAYERS(k);
                        }
                    }
                }
            }
        }
    } else {
        for (i = 0; i < D_800E53C0->count; i++) {
            for (j = 0; j < D_800E53C0->count - 1; j++) {
                a = D_800E53C0->players[j];
                b = D_800E53C0->players[j + 1];
                leftKills = resultsGame()->playerSettings[a].score;
                rightKills = resultsGame()->playerSettings[b].score;
                switch (mode) {
                case 3: leftScore = resultsGame()->playerSettings[a].resultAlternate; rightScore = resultsGame()->playerSettings[b].resultAlternate; break;
                case 2: leftScore = resultsGame()->playerSettings[a].resultScore; rightScore = resultsGame()->playerSettings[b].resultScore; break;
                case 1:
                default: leftScore = leftKills; rightScore = rightKills; break;
                }
                if (leftScore < rightScore || (leftScore == rightScore && leftKills < rightKills)) {
                    RESULTS_SWAP_PLAYERS(j);
                }
            }
        }
    }
}

#ifdef NON_MATCHING
/* Looks up entry arg1 of the table chosen by arg0 and returns field 0xC of the first of the forty records at D_800E4F64 whose first word equals it, or zero. */

/* Sets the byte at offset 0x10 of the two objects at offsets 0x454 and 0x450 of the structure D_800E4F60
   points to to 0xFF, shows both through func_8040E8D8_de and clears the word at 0x46C. */

/* Calls Defs_SetBitValue on D_80154018 for each index from 0 to 0x27 with zero. */

/* Releases the object D_800E4F60 holds through Cache_FreeMemory, calls Tsmos_ActivateControllerState and
   Menu_ReleaseOptionsScene, clears D_800E4F60 and returns zero. */

#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
#else
#endif

/* When the global session is mode 3 with no pending state and the caller's high word and empty flag agree, resets the mode, restarts five subsystems and queues one status message. */

/* Moves the selection of the screen D_800E4F60 back on event 1: calls MarkMenuEventHandled and steps the
   selection at 0x438 back while it is above 0; in category 0 the second page (11 and up) instead
   steps forward while below the count ScenarioSetup_GetCategoryEntryCount gives for list 0. When it moved it plays sound
   0xE7D, calls ScenarioSetup_ResetSelectionIndicators, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha
   0x41 and refreshes through ScenarioSetup_RefreshSelectedArenaLabel, and when the selection is then 0 it shows the items at
   0x440 and 0x448, moves the marker at 0x448 to x 0x7C plus 34 per category, hides the item at
   0x444 and shows model 0xEA6 plus the category in the view at 0x308. Returns zero. Adapted from
   ScenarioSetup_SelectNextSetupItem with the step direction, page handling and final item updates changed. */

extern s32 ScenarioSetup_GetCategoryEntryCount(s32);

/* Moves the selection of the screen D_800E4F60 on event 1: calls MarkMenuEventHandled and steps the
   selection at 0x438 forward while it stays below the count ScenarioSetup_GetCategoryEntryCount gives for the category's
   list; in category 0 the first page (below 11) steps forward unless it would reach the count of
   list 0 or 11, and the second page steps back unless it would reach 10. When it moved it plays
   sound 0xE7D, calls ScenarioSetup_ResetSelectionIndicators, clears the words at 0x45C and 0x464, dims the item at 0x43C to
   alpha 0x41, refreshes through ScenarioSetup_RefreshSelectedArenaLabel, hides the items at 0x440 and 0x448 and shows the
   one at 0x444. Returns zero. */

/* Moves the screen D_800E4F60 to its previous category on event 1: calls MarkMenuEventHandled and steps
   the category at 0x434 back unless it is 0; in category 0 a selection at 0x438 from 5 to 10 is
   mirrored to 21 minus it when that stays below the count ScenarioSetup_GetCategoryEntryCount gives for list 0. When
   anything changed it plays sound 0xE7D, calls ScenarioSetup_ResetSelectionIndicators, clears the words at 0x45C and 0x464,
   dims the item at 0x43C to alpha 0x41, clamps the selection below the count for the category's
   list, refreshes through ScenarioSetup_RefreshSelectedArenaLabel and, when the selection is 0, shows model 0xEA6 plus the
   category in the view at 0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category.
   Returns zero. Adapted from ScenarioSetup_SelectNextCatalogueCategory with the step direction and the mirror test changed. */

/* Moves the screen D_800E4F60 to its next category on event 1: calls MarkMenuEventHandled and, unless the
   category at 0x434 is already 3, advances it (from category 0 only while the selection at 0x438
   is below 11, otherwise mirroring the selection to 21 minus it), then plays sound 0xE7D, calls
   ScenarioSetup_ResetSelectionIndicators, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha 0x41, clamps
   the selection below the count ScenarioSetup_GetCategoryEntryCount gives for the category's list, refreshes through
   ScenarioSetup_RefreshSelectedArenaLabel and, when the selection is 0, shows model 0xEA6 plus the category in the view at
   0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category. Returns zero. */

/* Calls MarkMenuEventHandled; when the mode word at offset 0x3DC of the object D_800E4F60 points to is 3,
   sets it to 5 and the word at 0x3E0 to 4. Returns zero. */

#endif

/* 80423280_55.CPP */

/** Load four banks of ten resources, then activate the two resources used by the set. */
void ScenarioSetup_HideResultCatalogueWidgets(void)
{
    s32 bank;
    s32 offset;
    void *resource;

    bank = 0;
    offset = 0;
    do {
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[0]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[2]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[4]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[6]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[8]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[10]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[12]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[14]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[16]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, D_800E12D2[bank].ids[18]);
        Frontend_SetWidgetFlag08(resource, 0);
        offset += 0x28;
        bank++;
    } while (bank < 4);

#if defined(VERSION_DE)
    Frontend_HideResultBadgeGroup(0x264);
    Frontend_HideResultBadgeGroup(0x269);
#elif defined(VERSION_EU_X)
    Frontend_HideResultBadgeGroup(0x26D);
    Frontend_HideResultBadgeGroup(0x272);
#else
    Frontend_HideResultBadgeGroup(0x269);
    Frontend_HideResultBadgeGroup(0x26E);
#endif
}

/* Shows the model preview of the screen D_800E53C0 when its model id at 0x32C is set: shows the
   version-specific preview item of the screen window with alpha 0xAF and the preview image, then sets up the
   view at 0x20 of the screen through Frontend_InitModelPreviewTransform with mode 0, a uniform D_800DDAFC_de scale and the
   offset (0, D_800DDB04, D_800DDB08_de), through Frontend_SetPreviewRotation with a zero vector, through
   Frontend_SetPreviewRotationSpeed with (0, D_800DDB00, 0), and loads the model through Model_SetPreviewModel. */
typedef struct PreviewScreen {
    char pad0[0x20];
    char view[0xE0 - 0x20];
    void *window;
    char padE4[0x32C - 0xE4];
    s32 model;
} PreviewScreen;
#define PREVIEW_SCREEN ((PreviewScreen *)D_800E53C0)
extern f32 D_800DDAFC_de;
extern f32 D_800DDB00, D_800DDB04, D_800DDB08_de;
void ScenarioSetup_InitResultModelPreview(void) {
    struct MenuWidget *item;
    CVector3 scale;
    CVector3 offset;
    CVector3 angle;
    CVector3 position;
    if (PREVIEW_SCREEN->model != -1) {
#if defined(VERSION_DE)
        item = Frontend_FindWidgetByResourceId(PREVIEW_SCREEN->window, 0x263);
#elif defined(VERSION_EU_X)
        item = Frontend_FindWidgetByResourceId(PREVIEW_SCREEN->window, 0x26C);
#else
        item = Frontend_FindWidgetByResourceId(PREVIEW_SCREEN->window, 0x268);
#endif
        Frontend_SetWidgetFlag08(item, 1);
        item->alpha = 0xAF;
        item->image = previewModelImage();
        scale.x = D_800DDAFC_de;
        scale.y = D_800DDAFC_de;
        scale.z = D_800DDAFC_de;
        angle.x = 0;
        angle.y = 0;
        angle.z = 0;
        position.x = 0;
        position.y = D_800DDB00;
        position.z = 0;
        offset.x = 0;
        offset.y = D_800DDB04;
        offset.z = D_800DDB08_de;
        ((void (*)(void *, s32, CVector3, CVector3))Frontend_InitModelPreviewTransform)(PREVIEW_SCREEN->view, 0, scale, offset);
        ((void (*)(void *, CVector3))Frontend_SetPreviewRotation)(PREVIEW_SCREEN->view, angle);
        ((void (*)(void *, CVector3))Frontend_SetPreviewRotationSpeed)(PREVIEW_SCREEN->view, position);
        Model_SetPreviewModel(PREVIEW_SCREEN->view, PREVIEW_SCREEN->model);
    }
}
