#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/8043A0B0_11.H"
#include "FRONTEND/CODE_8043AED0.H"
#include "FRONTEND/8040B45C_32.H"
#include "COMMON/PLAYERPROFILES.H"

/* Moves player p's column cursor on the screen D_800E59E0: fades the shown item of the current
   column (D_800E5A1A[p][column]) to alpha 0x23, calls func_8040E8D8_de(0) on the item D_800E5A06[p][column]
   unless the column is 5, then steps the column back for direction 1 (0 wraps to 5, and in mode 1
   at 0x4D4 anything above 2 becomes 2) or forward otherwise (5 wraps to 0, and in mode 1 anything
   past 2 becomes 5), and redraws through func_8043BA5C_de. */











extern struct StateFlags D_800E5A06[][19];

extern void Frontend_SetWidgetFlag08(void *, s32);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern FourPlayerResultsScreen *D_800E59E0;


typedef struct EquipEntry {
    s32 item;
    s32 resource;
    s32 kind;
    s32 *label;
} EquipEntry;
extern EquipEntry D_800E5B44[];

extern HudStatusShared_Settings D_801462C8;


extern s32 func_8022F4DC_de(s32 record, s32 item);

/* Enters player p's loadout panel on the screen D_800E59E0: marks the entry open, hides the panel
   item D_800E59E6[p][0], then by the entry's mode at 0x4D4 either hides column item
   D_800E59EE[p][5] and fades label D_800E5A1A[p][5] to alpha 0x23 (mode 0), or for each of the
   3 (mode 1) or 6 (mode 2 and any other) columns hides D_800E59EE[p][c], fades D_800E5A1A[p][c]
   to 0x23 and redraws the column through Frontend_ShowEquipChoice with the entry's value; mode 1 then also
   hides column 5's item, fades its label and hides the entry's item. Finally it hides the five
   D_800E5A06[p] items at alpha 0x37 and shows the selected column's label at alpha 0x96 through
   func_8040E928_de. */











void func_8043ACF0_de(s32 player, s32 direction) {
    MenuWidget *item;
    s32 column;

    column = D_800E59E0->panels[player].selection;
    item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][column].value);
    Frontend_SetWidgetFlag40(item, 0);
    item->alpha = 0x23;
    if (column != 5) {
        Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E5A06[player][column].value), 0);
    }
    if (direction == 1) {
        if (column == 0) {
            column = 5;
        } else {
            column--;
            if (D_800E59E0->panels[player].mode == 1 && column >= 3) {
                column = 2;
            }
        }
    } else {
        if (column == 5) {
            column = 0;
        } else {
            column++;
            if (D_800E59E0->panels[player].mode == 1 && column >= 3) {
                column = 5;
            }
        }
    }
    func_8043BA5C_de(player, column);
}

/* Step an equipment choice, rejecting duplicates and the locked item 15. */
void func_8043AE5C_de(s32 player, s32 step) {
    s32 count;
    s32 low;
    s32 high;
    s32 category;
    s32 value;
    s32 valid;
    s32 i;

    if (D_800E59E0->panels[player].mode == 2) {
        count = 0;
        low = 0;
        high = 0;
        category = D_800E59E0->panels[player].selection;
        switch (category) {
        case 0:
        case 1:
            count = 4;
            low = 0;
            high = 1;
            break;
        case 2:
        case 3:
            count = 8;
            low = 2;
            high = 3;
            break;
        case 4:
            count = 3;
            low = 4;
            high = 4;
            break;
        case 5:
            return;
        }
        value = D_800E59E0->panels[player].values[category];
        value += step;
        do {
            if (value >= count) {
                value = 0;
            }
            if (value < 0) {
                value = count - 1;
            }
            valid = 1;
            for (i = low; i < high + 1; i++) {
                if (valid != 1) {
                    break;
                }
                if (D_800E59E0->panels[player].values[i] == value) {
                    value += step;
                    valid = 0;
                }
            }
            if (valid == 1 && (category == 2 || category == 3) &&
                D_800E5B44[value].kind == 15 &&
                !(D_801462C8.flags & 0x10000000) &&
                !func_8022F4DC_de((s32)&D_80102B00[player], 15)) {
                value += step;
                valid = 0;
            }
        } while (!valid);
        Frontend_ShowEquipChoice(player, category, value);
        D_800E59E0->panels[player].values[category] = value;
    }
}

void func_8043B0CC_de(s32 player) {
    MenuWidget *item;
    s32 i;

    D_800E59E0->panels[player].state = 1;
    Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E59E6[player][0].value), 0);
    switch (D_800E59E0->panels[player].mode) {
    case 0:
        Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][5].value), 0);
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][5].value);
        Frontend_SetWidgetFlag08(item, 1);
        item->alpha = 0x23;
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][i].value), 0);
            item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][i].value);
            Frontend_SetWidgetFlag08(item, 1);
            item->alpha = 0x23;
            Frontend_ShowEquipChoice(player, i, D_800E59E0->panels[player].values[i]);
        }
        Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][5].value), 0);
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][5].value);
        Frontend_SetWidgetFlag08(item, 1);
        item->alpha = 0x23;
        Frontend_SetWidgetFlag08(D_800E59E0->panels[player].item, 0);
        break;
    case 2:
    default:
        for (i = 0; i < 6; i++) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][i].value), 0);
            item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][i].value);
            Frontend_SetWidgetFlag08(item, 1);
            item->alpha = 0x23;
            Frontend_ShowEquipChoice(player, i, D_800E59E0->panels[player].values[i]);
        }
        break;
    }
    for (i = 0; i < 5; i++) {
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A06[player][i].value);
        Frontend_SetWidgetFlag08(item, 0);
        item->alpha = 0x37;
    }
    item = func_8040EC30_de(D_800E59E0->window,
                         D_800E5A1A[player][D_800E59E0->panels[player].selection].value);
    Frontend_SetWidgetFlag40(item, 1);
    item->alpha = 0x96;
}

/* Redraws player p's equipment row for the chosen column: shows the panel item, picks the column's
   table (mode 1: columns 0/1/2 -> D_800E5BC4/D_800E5B44/D_800E5B14; otherwise 0-1, 2-3, 4), writes
   the choice's item into the column widget's kind-3 child, sets the badge and the panel label (per
   language on EU); column 5 or out of range clears the badge and hides the item. */
extern EquipEntry D_800E5BC4[];
extern EquipEntry D_800E5B14[];
extern void func_80439C80_de(void *, s32);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
void Frontend_ShowEquipChoice(s32 player, s32 category, s32 choice)
{
    EquipEntry *table;
    MenuWidget *node;
    s32 found;

    if (D_800E59E0->panels[player].mode == 0) {
        return;
    }
    Frontend_SetWidgetFlag08(D_800E59E0->panels[player].item, 1);
    if (D_800E59E0->panels[player].mode == 1) {
        switch (category) {
        case 0:
            table = D_800E5BC4;
            break;
        case 1:
            table = D_800E5B44;
            break;
        case 2:
            table = D_800E5B14;
            break;
        default:
            func_80439C80_de(D_800E59E0->badges[player], 0);
            Frontend_SetWidgetFlag08(D_800E59E0->panels[player].item, 0);
            return;
        }
    } else {
        switch (category) {
        case 0:
        case 1:
            table = D_800E5BC4;
            break;
        case 2:
        case 3:
            table = D_800E5B44;
            break;
        case 4:
            table = D_800E5B14;
            break;
        case 5:
        default:
            func_80439C80_de(D_800E59E0->badges[player], 0);
            Frontend_SetWidgetFlag08(D_800E59E0->panels[player].item, 0);
            return;
        }
    }
    if (table) {
        node = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][category].value)->child;
        found = 0;
        do {
            if (node->kind == 3) {
                node->value = table[choice].item;
                found = 1;
            } else {
                node = node->sibling;
            }
        } while (!found);
        func_80439C80_de(D_800E59E0->badges[player], table[choice].resource);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        D_800E59E0->panels[player].item->word38 = table[choice].label[g_languageIndex];
#else
        D_800E59E0->panels[player].item->word38 = *table[choice].label;
#endif
    }
}
