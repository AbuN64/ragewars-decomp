#include "TYPES.H"
#include "n64sdk.h"

typedef struct DraftChoiceEntry {
    s32 index;
    void *resource;
    s32 enabled;
    f32 angle, value, scale;
} DraftChoiceEntry;
typedef struct DraftChoiceMenu {
    u8 pad0[0x1C];
    DraftChoiceEntry choices[8];
    u8 padDC[0x37C-0xDC];
    s32 selected, ready;
    void *context;
    s32 filter, active;
} DraftChoiceMenu;
typedef struct DraftChoiceMap { u8 unused; s8 slot; } DraftChoiceMap;
typedef struct DraftChoicePlayer {
    u8 pad0[0x602];
    DraftChoiceMap map[22];
    s16 selected;
} DraftChoicePlayer;
extern void *D_800D052C[];
extern f32 D_800C2248_de, D_800C913C_de;
extern s32 func_8022EB0C_de(void *);

void func_802181FC_de(DraftChoiceMenu *menu, void *context, DraftChoicePlayer *player) {
    DraftChoiceEntry *entry = menu->choices;
    s32 i = 0;
    s32 j;
    s32 filter;
    s32 accept;
    menu->active = 0;
    menu->context = context;
    menu->selected = -1;
    do {
        for (j = 0; j < 22; j++) {
            if (i == player->map[j].slot) break;
        }
        if (j < 22) {
            filter = menu->filter;
            if (filter == -1) accept = 1;
            else if (filter == 3 || filter == 7) accept = i == filter;
            else if (filter == 4) accept = i == 4;
            else {
                accept = 0;
                if (i == filter || i == filter + 1) accept = 1;
            }
            if (!accept) {
                entry->index = -1;
                entry->enabled = 0;
            } else {
                entry->index = j;
                if (player->selected == j) menu->selected = i;
                entry->resource = D_800D052C[j];
                if (func_8022EB0C_de(player) == 0) entry->enabled = 0;
                else entry->enabled = 1;
                entry->value = 0.0f;
                entry->scale = D_800C913C_de;
                entry->angle = (f32)i * D_800C2248_de;
            }
        } else {
            entry->index = -1;
            entry->enabled = 0;
        }
        i++;
        entry++;
    } while (i < 8);
    menu->ready = 1;
}
