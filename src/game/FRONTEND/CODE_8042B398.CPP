#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
#include "COMMON/MENU_SCREEN_SETUP.H"
#include "FRONTEND/80423280_50.H"
#include "COMMON/SCREEN.H"
#include "COMMON/PLAYERPROFILES.H"

#include "COMMON/CONTROL.H"
extern RecordRecAtCV2 D_800E4F64[];
extern s32 D_800E51E4[];
extern s32 D_800E51F8[];
extern s32 D_800E5214[];
extern s32 D_800E5240[];
extern s32 D_800E0F20[];
s32 func_8042B1B8_de(s32 arg0, s32 arg1) {
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
        table = D_800E51E4;
        break;
    case 1:
        table = D_800E51F8;
        break;
    case 3:
        table = D_800E5214;
        break;
    case 2:
        table = D_800E5240;
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

s32 Frontend_CategoryToList(s32 category) {
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
s32 func_8042B2DC_de(void) {
    return 0;
}

#include "COMMON/CONTROL.H"
#include "COMMON/SELECTIONSCREENSTATE.H"

void func_8042B2E4_de(void) {
    D_800E4F60->unk454->alpha = 0xFF;
    D_800E4F60->unk450->alpha = 0xFF;
    Frontend_SetWidgetFlag08(D_800E4F60->unk450, 1);
    Frontend_SetWidgetFlag08(D_800E4F60->unk454, 1);
    D_800E4F60->unk46C = 0;
}

extern void func_80265688_de(void *, s32, s32);

/* Clears the first 0x28 bits of the bit set D_80154018 (bit i set to 0 through func_80265688_de). */
void Frontend_ClearFlagBits(void) {
    s32 i;

    for (i = 0; i < 0x28; i++) {
        func_80265688_de(D_80154010.played, i, 0);
    }
}

extern void func_80422020_de(void);

/* Closes the setup screen D_800E4F60: releases it through Scene_FreeMemory, runs func_802A2360_de and
   func_80422020_de, then clears the pointer. Returns zero. */
s32 Frontend_CloseSetupScreen(void) {
    Scene_FreeMemory(D_800E4F60);
    func_802A2360_de();
    func_80422020_de();
    D_800E4F60 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8042B3D4_de(void) {
    return 0;
}

extern void func_8042A7B4_de(s32);

/** Begin setup confirmation when the pending state and input event permit it. */
s32 Frontend_BeginSetupConfirmation(s32 a0, s32 a1, s32 a2, s32 a3)
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
    func_8042A7B4_de(0x41);

    Frontend_SetWidgetFlag08(D_800E4F60->unk440, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk444, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->label, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk3F0, 0);

    D_800E4F60->unk44C->alpha = 0x5A;
    Render_PlayFlatSound(0xE7C);

    return 0;
}


extern void MarkMenuEventHandled();
extern void func_80439C80_de(void *, s32);
#define SCR4D4 ((struct Screen_func_8042B4D4_de *)D_800E4F60)
s32 func_8042B4D4_de(void *unused0, void *unused1, void *unused2, s32 event) {
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
        s32 next = func_8042B154_de(Frontend_CategoryToList(0));
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
    Render_PlayFlatSound(0xE7D);
    func_8042B2E4_de();
    SCR4D4->word45C = 0;
    SCR4D4->word464 = 0;
    SCR4D4->item->alpha = 0x41;
    func_8042A990_de();
    if (SCR4D4->selection != 0) {
        return 0;
    }
    Frontend_SetWidgetFlag08(SCR4D4->left, 1);
    Frontend_SetWidgetFlag08(SCR4D4->marker, 1);
    SCR4D4->marker->x = SCR4D4->category * 34 + 0x7C;
    Frontend_SetWidgetFlag08(SCR4D4->right, 0);
    func_80439C80_de(SCR4D4->view, SCR4D4->category + 0xEA6);
    return 0;
}
#undef SCR4D4

extern s32 func_8042B154_de(s32 index);
extern void func_8042B2E4_de(void);

/** Select the next setup item, reversing the displayed order on the second page. */
s32 Frontend_SelectNextSetupItem(void *unused0, void *unused1, void *unused2, s32 event) {
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
    count = func_8042B154_de(Frontend_CategoryToList(D_800E4F60->category));
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
            limit = func_8042B154_de(Frontend_CategoryToList(0));
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
    Render_PlayFlatSound(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->unk45C = 0;
    D_800E4F60->unk464 = 0;
    D_800E4F60->item->alpha = 0x41;
    func_8042A990_de();
    Frontend_SetWidgetFlag08(D_800E4F60->unk440, 0);
    Frontend_SetWidgetFlag08(D_800E4F60->unk444, 1);
    Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
    return 0;
}


#define SCR78C ((struct Screen_func_8042B78C_de *)D_800E4F60)
s32 func_8042B78C_de(void *unused0, void *unused1, void *unused2, s32 event) {
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
        if (mirror < func_8042B154_de(Frontend_CategoryToList(0))) {
            changed = 1;
            SCR78C->selection = mirror;
        }
    }
    if (changed != 1) {
        return 0;
    }
    Render_PlayFlatSound(0xE7D);
    func_8042B2E4_de();
    SCR78C->word45C = 0;
    SCR78C->word464 = 0;
    SCR78C->item->alpha = 0x41;
    count = func_8042B154_de(Frontend_CategoryToList(SCR78C->category));
    if (SCR78C->selection >= count) {
        SCR78C->selection = count - 1;
    }
    func_8042A990_de();
    if (SCR78C->selection == 0) {
        func_80439C80_de(SCR78C->view, SCR78C->category + 0xEA6);
        Frontend_SetWidgetFlag08(SCR78C->marker, 1);
        SCR78C->marker->x = SCR78C->category * 34 + 0x7C;
    }
    return 0;
}
#undef SCR78C

#define SCR904 ((struct Screen_func_8042B78C_de *)D_800E4F60)
s32 func_8042B904_de(void *unused0, void *unused1, void *unused2, s32 event) {
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
    Render_PlayFlatSound(0xE7D);
    func_8042B2E4_de();
    SCR904->word45C = 0;
    SCR904->word464 = 0;
    SCR904->item->alpha = 0x41;
    count = func_8042B154_de(Frontend_CategoryToList(SCR904->category));
    if (SCR904->selection >= count) {
        SCR904->selection = count - 1;
    }
    func_8042A990_de();
    if (SCR904->selection == 0) {
        func_80439C80_de(SCR904->view, SCR904->category + 0xEA6);
        Frontend_SetWidgetFlag08(SCR904->marker, 1);
        SCR904->marker->x = SCR904->category * 34 + 0x7C;
    }
    return 0;
}
#undef SCR904

s32 Frontend_EndSetupInput(void) {
    MarkMenuEventHandled();
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk3DC = 5;
        D_800E4F60->unk3E0 = 4;
        return 0;
    }
    return 0;
}

/* Calls func_8042AAD0_de while the setup screen D_800E4F60 is in mode 3, and returns zero. */
s32 Frontend_RefreshSetupScreen(void) {
    if (D_800E4F60->unk3DC == 3) {
        func_8042AAD0_de();
        return 0;
    }
    return 0;
}

#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5284, an actor kind at D_800E5288 and a handler at D_800E528C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042BCB0)(void *, s32, s32, s32, s32);



extern Handler8042BCB0 D_800E528C;
s32 func_8042BAD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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

#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/WORLD.H"
#include "FRONTEND/RESULTS_SETUP_TEXT.H"
#include "COMMON/SETTINGSRECAT24.H"
extern func_8042CE54_S1 *D_800E53C0;
extern s32 D_8015402C;
extern s8 D_80102B0D[], D_800FEB0E[];
extern void func_8043C210_de(s32 *, s32, s32, s32, s32);
extern void func_8043C278_de(s32 *);
extern void func_80424B90_de(void);
extern void Frontend_SortResultsPlayers(void);
extern void Achieve_UpdateMatchCounters(void *, s32);
extern void func_80425D14_de(s32);
extern void Frontend_FillResultRows(void);
extern void func_8042CE74_de(void);

extern void Frontend_SetWidgetFlag100(void *, s32);
extern s32 Frontend_ListHasFlag100(void *);
extern s32 Frontend_IsCupSelected(void);
extern s32 func_8042AFB8_de(void);
extern void func_8028D380_de(Shared_World *, s32, void *, s32);
extern char *func_802A0494_de(char *);
extern char *Resmgr_CopyString(char *, char *);

s32 Frontend_OpenResultsScreen(void *root) {
    char buffer[64];
    MenuWidget *item;
    func_8042CE54_S1 *screen;
    Shared_Game *game;
    Shared_Game *slot;
    Shared_PlayerSettingsRecord *config;
    s32 i, offset;

    D_800E53C0 = (void *)Scene_AllocateMemory(0x330);
    D_800E53C0->unkE0 = root;
    Frontend_SetWidgetFlag08(root, 0);
    func_8043C210_de(D_800E53C0->transition, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E53C0->transition);
    D_800E53C0->active = 1;
    func_8040EC30_de(root, 0x234 + RESULTS_MENU_SHIFT)->alpha = 110;
    func_8040EC30_de(root, 0x239 + RESULTS_MENU_SHIFT)->alpha = 20;
    func_8040EC30_de(root, 0x236 + RESULTS_MENU_SHIFT)->alpha = 20;
    func_80424B90_de();
    screen = D_800E53C0;
    for (i = 0; i < 8; i++) {
        screen->icons[i][0] = -1;
        screen->icons[i][1] = -1;
    }
    D_800E53C0->selection = -1;
    Frontend_SortResultsPlayers();
    game = &D_801462C8;
    switch (game->controllerMode) {
    case 0:
        Achieve_UpdateMatchCounters(D_800E53C0->data, D_8015402C);
        func_8042D118_de();
        D_800E53C0->mode = 0;
        break;
    case 2:
        if (game->humanWon == 1) {
            D_800E53C0->mode = 0;
            func_8042D1C8_de();
            config = game->playerSettings;
            for (i = 0; i < 4; i++) {
                if (config[i].enabled == 1 && config[i].locked == 0) func_80425D14_de(i);
            }
        } else D_800E53C0->mode = 1;
        break;
    }
    slot = &D_801462C8;
    switch (slot->controllerMode) {
    case 0:
        Frontend_FillResultRows();
        break;
    case 2:
        screen = D_800E53C0;
        if (screen->mode == 1) {
            screen->first = 0;
            screen->count = 0;
            func_8042CC74_de();
            item = func_8040EC30_de(root, 0x266 + RESULTS_MENU_SHIFT);
            Frontend_SetWidgetFlag08(item, 1);
            item->alpha = 115;
            item->text = resultsUnavailable(slot);
            Frontend_SetWidgetFlag08(func_8040EC30_de(root, RESULTS_RIGHT_ITEM), 0);
        } else if (screen->selection != -1) {
            screen->first = 0;
            screen->count = 0;
            func_8042CC74_de();
            Frontend_SetWidgetFlag08(func_8040EC30_de(root, RESULTS_RIGHT_ITEM), 0);
            func_8042CE74_de();
        } else {
            Frontend_FillResultRows();
        }
        break;
    }
    func_8041B110_de(0x237 + RESULTS_MENU_SHIFT);
    func_8041B110_de(0x238 + RESULTS_MENU_SHIFT);
    func_8041B110_de(0x23C + RESULTS_MENU_SHIFT);
    Frontend_SetWidgetFlag100(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    i = 0;
    offset = 0;
    do {
        i++;
        if (D_80102B0D[offset] >= 0 && D_800FEB0E[offset] == 0) {
            Frontend_SetWidgetFlag100(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 0);
            break;
        }
        offset += 400;
    } while (i < 4);
    if (Frontend_ListHasFlag100(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT)) == 0 && Frontend_IsCupSelected() == 1 && func_8042AFB8_de() == 0) {
        Frontend_SetWidgetFlag100(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    }
    item = func_8040EC30_de(D_800E53C0->unkE0, RESULTS_HEADING1);
    if (D_8014DD98.kind == 0) item->text = resultsFirstHeading();
    else item->text = resultsSecondHeading();
    item = func_8040EC30_de(D_800E53C0->unkE0, RESULTS_HEADING2);
    switch (D_8014DD98.kind) {
    case 3: item->text = resultsFirstHeading(); break;
    case 0: item->text = resultsFourthHeading(); break;
    case 1:
    default: item->text = resultsThirdHeading(); break;
    }
    item = func_8040EC30_de(root, 0x235 + RESULTS_MENU_SHIFT);
    func_8028D380_de(&D_8011FE88, D_8015402C, buffer, 63);
    Resmgr_CopyString(D_800E53C0->name, func_802A0494_de(buffer));
    item->text = D_800E53C0->name;
    D_800E53C0->buttonAddress = (s32)func_8040EC30_de(root, 0x23D + RESULTS_MENU_SHIFT);
    D_800E53C0->dirty = 1;
    D_80145088.status[7] = 1;
    D_800E53C0->phase = 0;
    func_802A2394_de();
    return 0;
}

#include "COMMON/SETTINGSRECAT24.H"
#include "FRONTEND/RESULTS_SCREEN_TEXT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
extern func_8042CE54_S1 *D_800E53C0;
extern ResourceBank D_800E12D2[];
extern struct RowRecAt54 D_800E3A58[];
extern s32 D_800E01B0_de[],D_800FF140_de[],D_800FEAE0[];
extern s32 Frontend_FindKeyIndex(s32);
extern char *func_802A0494_de(char *);
extern char *Resmgr_CopyString(char *,char *);
extern char *func_80424DE8_de(s32);
extern s32 func_802A0C08_de(void *,const char *,...);
extern void func_8042D304_de(s32,s32,u16);
/* Fill the four visible player rows of the match results screen. */
void Frontend_FillResultRows(void) {
    s32 row, player, attempts, percent;
    func_8041F2A0_Config *record;
    MenuWidget *widget, *pending;
    char *name;

    func_8042CC74_de();
    for (row = 0; row < 4; row++) {
        if (row >= D_800E53C0->count) return;
        player = D_800E53C0->players[D_800E53C0->first + row];
        record = &D_80146398[player];

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[0]);
        Frontend_SetWidgetFlag08(widget, 1);
        widget->alpha = 0x96;
        pending = widget;
        pending->value = D_800E3A58[Frontend_FindKeyIndex(record->kind)].portrait;

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[2]);
        Frontend_SetWidgetFlag08(widget, 1);
        widget->alpha = 0x19;

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[4]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        if (record->out == 0) {
            widget->text = D_80102B00[player].name;
        } else {
            name = record->name;
            Resmgr_CopyString(name, func_802A0494_de(name));
            widget->text = name;
        }

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[6]);
        widget->alpha = 0x73;
        Frontend_SetWidgetFlag08(widget, 1);
        if (record->out == 0) widget->text = func_80424DE8_de(player);
        else widget->text = resultsRankText(record->rank);

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[8]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        func_802A0C08_de(D_800E53C0->killText[row], resultsNumberFormat(), record->kills);
        widget->text = D_800E53C0->killText[row];

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[10]);
        widget->alpha = 0xAF;
        Frontend_SetWidgetFlag08(widget, 1);
        func_802A0C08_de(D_800E53C0->scoreText[row], resultsNumberFormat(), record->score + record->total);
        *&widget->text = D_800E53C0->scoreText[row];

        if (D_8014DD98.kind == 0) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[12]), 0);
            func_8042D304_de(player, row, RESULTS_RANK_GROUP);
        } else {
            widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[12]);
            widget->alpha = 0xAF;
            Frontend_SetWidgetFlag08(widget, 1);
            attempts = D_800FF140_de[player];
            percent = 0;
            if (attempts > 0) percent = D_800FEAE0[player] * 100 / attempts;
            func_802A0C08_de(D_800E53C0->ratioText[row], resultsPercentFormat(), percent);
            widget->text = D_800E53C0->ratioText[row];
        }

        if (D_8014DD98.kind == 3) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[14]), 0);
            func_8042D304_de(player, row, RESULTS_SECONDARY_GROUP);
        } else {
            widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[14]);
            widget->alpha = 0xAF;
            Frontend_SetWidgetFlag08(widget, 1);
            pending = widget;
            switch (D_8014DD98.kind) {
            case 0:
                func_802A0C08_de(D_800E53C0->valueText[row], resultsNumberFormat(), record->other);
                break;
            case 1:
                func_802A0C08_de(D_800E53C0->valueText[row], resultsNumberFormat(), record->selected);
                break;
            default:
                func_802A0C08_de(D_800E53C0->valueText[row], resultsNumberFormat(), 0);
                break;
            }
            pending->text = D_800E53C0->valueText[row];
        }

        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[16]);
        Frontend_SetWidgetFlag08(widget, 0);
        widget->alpha = 0x96;
        widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[18]);
        Frontend_SetWidgetFlag08(widget, 0);
        widget->alpha = 0x96;
        if (record->out == 0) {
            if (D_800E53C0->icons[player][0] != -1) {
                widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[16]);
                Frontend_SetWidgetFlag08(widget, 1);
                widget->value = D_800E01B0_de[D_800E53C0->icons[player][0]];
            }
            if (D_800E53C0->icons[player][1] != -1) {
                widget = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[row].ids[18]);
                Frontend_SetWidgetFlag08(widget, 1);
                widget->value = D_800E01B0_de[D_800E53C0->icons[player][1]];
            }
        }
        pending = 0;
    }
}

#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"

extern s32 Frontend_GetMatchEndReason(void);

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
void Frontend_SortResultsPlayers(void) {
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




extern RecordRecAtCV2 D_800E4F64[];

extern s32 D_800E51E4[];

extern s32 D_800E51F8[];

extern s32 D_800E5214[];

extern s32 D_800E5240[];

/* Sets the byte at offset 0x10 of the two objects at offsets 0x454 and 0x450 of the structure D_800E4F60
   points to to 0xFF, shows both through func_8040E8D8_de and clears the word at 0x46C. */







/* Calls func_80265688_de on D_80154018 for each index from 0 to 0x27 with zero. */

extern void func_80265688_de(void *, s32, s32);

/* Releases the object D_800E4F60 holds through Scene_FreeMemory, calls func_802A2360_de and
   func_80422020_de, clears D_800E4F60 and returns zero. */



extern void func_802A2360_de();

#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_80422020_de();
#else
#endif


/* When the global session is mode 3 with no pending state and the caller's high word and empty flag agree, resets the mode, restarts five subsystems and queues one status message. */









extern void func_8042A7B4_de(s32 a0);


/* Moves the selection of the screen D_800E4F60 back on event 1: calls MarkMenuEventHandled and steps the
   selection at 0x438 back while it is above 0; in category 0 the second page (11 and up) instead
   steps forward while below the count func_8042B154_de gives for list 0. When it moved it plays sound
   0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha
   0x41 and refreshes through func_8042A990_de, and when the selection is then 0 it shows the items at
   0x440 and 0x448, moves the marker at 0x448 to x 0x7C plus 34 per category, hides the item at
   0x444 and shows model 0xEA6 plus the category in the view at 0x308. Returns zero. Adapted from
   Frontend_SelectNextSetupItem with the step direction, page handling and final item updates changed. */







extern void MarkMenuEventHandled();



extern s32 func_8042B154_de(s32);

extern void func_80439C80_de(void *, s32);

/* Moves the selection of the screen D_800E4F60 on event 1: calls MarkMenuEventHandled and steps the
   selection at 0x438 forward while it stays below the count func_8042B154_de gives for the category's
   list; in category 0 the first page (below 11) steps forward unless it would reach the count of
   list 0 or 11, and the second page steps back unless it would reach 10. When it moved it plays
   sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to
   alpha 0x41, refreshes through func_8042A990_de, hides the items at 0x440 and 0x448 and shows the
   one at 0x444. Returns zero. */







/* Moves the screen D_800E4F60 to its previous category on event 1: calls MarkMenuEventHandled and steps
   the category at 0x434 back unless it is 0; in category 0 a selection at 0x438 from 5 to 10 is
   mirrored to 21 minus it when that stays below the count func_8042B154_de gives for list 0. When
   anything changed it plays sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464,
   dims the item at 0x43C to alpha 0x41, clamps the selection below the count for the category's
   list, refreshes through func_8042A990_de and, when the selection is 0, shows model 0xEA6 plus the
   category in the view at 0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category.
   Returns zero. Adapted from func_8042B904_de with the step direction and the mirror test changed. */







/* Moves the screen D_800E4F60 to its next category on event 1: calls MarkMenuEventHandled and, unless the
   category at 0x434 is already 3, advances it (from category 0 only while the selection at 0x438
   is below 11, otherwise mirroring the selection to 21 minus it), then plays sound 0xE7D, calls
   func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha 0x41, clamps
   the selection below the count func_8042B154_de gives for the category's list, refreshes through
   func_8042A990_de and, when the selection is 0, shows model 0xEA6 plus the category in the view at
   0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category. Returns zero. */












/* Calls MarkMenuEventHandled; when the mode word at offset 0x3DC of the object D_800E4F60 points to is 3,
   sets it to 5 and the word at 0x3E0 to 4. Returns zero. */


#endif
