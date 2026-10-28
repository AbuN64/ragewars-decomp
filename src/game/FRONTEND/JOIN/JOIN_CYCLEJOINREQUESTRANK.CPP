#include "FRONTEND/JOIN_RANDOMIZEJOINREQUESTENTRIES.H"
#include "COMMON/MENULISTSCREEN.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Resets the three 28-byte entries of D_80153F80: -1 in the first word and zero in the next
   three. */

/* Counts the four player records whose byte 0x78 is one and returns 3, 2 or 1 for one, two or three such players, otherwise zero. */

extern PlayerFrontendCountOpenPlayerSlots g_playerSettings[];

/* Counts how many of the three 28-byte entries of D_80153F80 hold a non-negative first word. */

/* Returns entry column - 1 of row r in the five-word table g_rewardScoreBudgets, or zero when the column is
   not positive. */

/* Returns the score of the three entries: 5, 10 or 20 points by kind for each active one, repeating the previous award for other kinds. */

/* Returns the column of the first of the seventeen eight-byte entries in row r of g_rewardItemTiers whose
   identifier matches, or zero when none does. */

/* Releases the object D_800E39C0 holds through Cache_FreeMemory, clears D_800E39C0 and returns zero. */

/* Advances the join screen's pulse timer by delta and sets byte 0x10 of node 0x392 under the edited request's root to 150 plus 100 times the sine of the timer over 300; returns zero. */

/* Calls MarkMenuEventHandled, then passes -1 to Random_SetMenuChoiceResult when Menu_GetPreviousScreenOwner reports 0x16 for zero
   and 0x15 otherwise, then calls Menu_ReturnToPreviousScreen. Returns zero. */
extern void MarkMenuEventHandled();

extern void Menu_ReturnToPreviousScreen();

/* Steps the selected menu item backwards and updates its display state. */

extern void MarkMenuEventHandled(void),Widget_SetWidgetFlag08(MenuWidget *,int);

#if defined(VERSION_DE)
enum { MENU_RESOURCE = 0x38c };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 0x392 };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 0x396 };
#elif defined(VERSION_US)
enum { MENU_RESOURCE = 0x392 };
#elif defined(VERSION_US_REV1)
enum { MENU_RESOURCE = 0x392 };
#endif

/* Advances the selected menu item and updates its display state. */

/* Cycles a menu selection and updates the associated character setting. */

extern s32 D_8014DCF8[];

extern unsigned char D_8014DCFB[];

extern void MarkMenuEventHandled(void);
extern struct CourseOptionsScreen *D_800E39C0;
extern MenuWidget *Node_FindWidgetByResourceId(void *, s32);

void Join_ResetJoinRequestEntries(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        D_80153F80[i].id = -1;
        D_80153F80[i].variant = 0;
        D_80153F80[i].word8 = 0;
        D_80153F80[i].variantC = 0;
    }
}

s32 Join_CountOpenPlayerSlots(void) {
    s32 count;
    s32 i;
    s32 result;
    PlayerFrontendCountOpenPlayerSlots *player;

    count = 0;
    player = g_playerSettings;
    for (i = 0; i < 4; i++) {
        if (player[i].active == 1) {
            count++;
        }
    }
    result = 0;
    switch (count) {
    case 1:
        result = 3;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 1;
        break;
    }
    return result;
}

s32 Join_CountUsedSlots(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].id >= 0) {
            count++;
        }
    }
    return count;
}

s32 Join_GetJoinRankThreshold(s32 column, s32 row) {
    s32 previous = column - 1;

    if (column <= 0) {
        return 0;
    }
    return g_rewardScoreBudgets[row * 5 + previous];
}

s32 Join_ScoreJoinRequestEntries(void) {
    s32 score;
    s32 points;
    s32 i;

    score = 0;
    points = 0;
    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].id >= 0) {
            switch (D_80153F80[i].variant) {
            case 0:
                points = 5;
                break;
            case 1:
                points = 10;
                break;
            case 2:
                points = 20;
                break;
            }
            score += points;
        }
    }
    return score;
}

s32 Join_FindJoinModelIndex(s32 row, s32 id) {
    s32 i;

    for (i = 0; i < 0x11; i++) {
        if (g_rewardItemTiers[row][i].field_0 == id) {
            return i;
        }
    }
    return 0;
}

s32 Join_DestroyJoinOptionsMenu(void) {
    Cache_FreeMemory(D_800E39C0);
    D_800E39C0 = 0;
    return 0;
}

s32 Join_PulseJoinSelectionHighlight(void *unused0, void *unused1, s32 delta) {
    MenuWidget *node;
    D_800E39C0->timer += delta;
#if defined(VERSION_DE)
    node = Node_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    node = Node_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x392);
#elif defined(VERSION_EU_X)
    node = Node_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x396);
#endif
    node->alpha = (u32)(Math_Cosf(D_800E39C0->timer * 0.0033333334f) * 100.0f + 150.0f);
    return 0;
}

s32 Join_RequestJoinOptionsExit(void) {
    MarkMenuEventHandled();
    Random_SetMenuChoiceResult(Menu_GetPreviousScreenOwner(0) == 0x16 ? -1 : 0x15);
    Menu_ReturnToPreviousScreen();
    return 0;
}

s32 Join_RequestJoinOptionsExitAlternate(void) {
    MarkMenuEventHandled();
    Random_SetMenuChoiceResult(Menu_GetPreviousScreenOwner(0) == 0x16 ? -1 : 0x15);
    Menu_ReturnToPreviousScreen();
    return 0;
}

s32 Join_SelectPreviousJoinRow(s32 unused0, s32 unused1, s32 unused2, s32 arg3) {
    s32 prevSelection;
    s32 idx;
    MenuWidget *oldItem;
    MenuWidget *newItem;
    if (arg3 == 1) {
        MarkMenuEventHandled();
        idx = D_800E39C0->selection;
#if defined(VERSION_DE)
        oldItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        oldItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x392);
#elif defined(VERSION_EU_X)
        oldItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x396);
#endif
        oldItem->alpha = 0xFF;
        Widget_SetWidgetFlag08(oldItem, 0);
        prevSelection = D_800E39C0->selection - 1;
        D_800E39C0->selection = prevSelection;
        if (prevSelection < 0) {
            D_800E39C0->selection = D_800E39C0->step - 1;
        }
        idx = D_800E39C0->selection;
#if defined(VERSION_DE)
        newItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        newItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x392);
#elif defined(VERSION_EU_X)
        newItem = Node_FindWidgetByResourceId(D_800E39C0->rows[idx], 0x396);
#endif
        newItem->alpha = 0xFF;
        Widget_SetWidgetFlag08(newItem, 1);
        D_800E39C0->timer = 0;
        SoundElement_PlayFlatSound(0xE80);
        return 0;
    }
    return 0;
}

s32 Join_SelectNextJoinRow(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 nextSelection;
    s32 temp_v0_2;
    s32 rowCount;
    MenuWidget *oldItem;
    MenuWidget *newItem;

    if (arg3 == 1) {
        MarkMenuEventHandled();
        oldItem = Node_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], MENU_RESOURCE);
        oldItem->alpha = 0xFF;
        Widget_SetWidgetFlag08(oldItem, 0);
        rowCount = D_800E39C0->step;
        temp_v0_2 = D_800E39C0->selection + 1;
        nextSelection = temp_v0_2 % rowCount;
        D_800E39C0->selection = nextSelection;
        newItem = Node_FindWidgetByResourceId(D_800E39C0->rows[nextSelection], MENU_RESOURCE);
        newItem->alpha = 0xFF;
        Widget_SetWidgetFlag08(newItem, 1);
        D_800E39C0->timer = 0;
        SoundElement_PlayFlatSound(0xE80);
        return 0;
    }
    return 0;
}

s32 Join_CycleJoinRequestRank(s32 unused0, s32 unused1, u32 arg2, s32 arg3) {
    s32 temp_a1;
    s32 selectedRow;
    u32 temp_a2;

    temp_a2 = arg2 >> 0x10;
    if ((temp_a2 == 3) && (arg3 == 0)) {
        MarkMenuEventHandled();
        temp_a1 = D_800E39C0->selection * 0x1C;
        *(s32 *)((char *)D_8014DCF8 + temp_a1) = (*(s32 *)((char *)D_8014DCF8 + temp_a1) + 1) % 5;
        Join_UpdateJoinRequestDisplay(D_800E39C0->selection);
        if (Menu_GetPreviousScreenOwner(0) == 0x16) {
            selectedRow = D_800E39C0->selection;
            D_801462C8.playerSettings[7 - selectedRow].rank = *(D_8014DCFB + (selectedRow * 0x1C));
        }
    }
    return 0;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int rodata_func_8041F298_us_800DC1F0[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern ResidentEventHandlerEntry D_800EB1A4[];

s32 Join_DispatchJoinOptionsEvent(MenuWidget *object, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 i = 0;
    while (D_800EB1A4[i].handler != 0) {
        if (D_800EB1A4[i].event == event &&
            (D_800EB1A4[i].actorKind == object->resource || D_800EB1A4[i].actorKind == 30000)) {
            return D_800EB1A4[i].handler(object, event, arg2, arg3, arg4);
        }
        i++;
    }
    return 0;
}
#endif
